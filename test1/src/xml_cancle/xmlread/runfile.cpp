#include "runfile.h"
#include "usr_motion_api.h"
#include "opXmlErrorType.h"
RunFile::RunFile(QString fileName)
{
	//初始化状态
    this->fileName = fileName;
    exe[COMMAND_MOVJ_TYPE]=&RunFile::exeMovj;
    exe[COMMAND_MOVL_TYPE]=&RunFile::exeMovl;
    exe[COMMAND_MOVC_TYPE]=&RunFile::exeMovc;
    exe[CMOMAND_SPEED_TYPE]=&RunFile::exeSpeed;
    exe[COMMAND_DOUT_TYPE]=&RunFile::exeDout;
    exe[COMMAND_DIN_TYPE]=&RunFile::exeDin;
    exe[COMMAND_JUMP_TYPE]=&RunFile::exeJump;
    exe[COMMAND_LABEL_TYPE]=&RunFile::exeLabel;
    exe[COMMAND_CALL_TYPE]=&RunFile::exeCall;
    exe[COMMAND_PAUSE_TYPE]=&RunFile::exePause;
    exe[COMMAND_TIMER_TYPE]=&RunFile::exeTimer;
    exe[COMMAND_RET_TYPE]=&RunFile::exeRet;
    exe[COMMAND_NOP_TYPE]=&RunFile::exeNop;
    exe[COMMAND_END_TYPE]=&RunFile::exeEnd;
    movcCount = 0;
    pause = 0;
    currentFileLine = 0;
    op = new OperateProgramXml();
    state = 0;
    inverse = 0;
    runFilePause = 0;
    line.commandType = COMMAND_NONE_TYPE;
}
bool RunFile::init()
{
    int ret = 0;
    // open file ,
    ret = op->init(fileName);
    //currentFileLine = 0;
    if(ret)
    {
        if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_ERROR)
        {
            qDebug()<<"failed to open file  " << fileName << " errocode is " << ret;
        }
        return ret;
    }
    start();
    return true;
}
bool RunFile::init(int lineNumber, int mode)
{
    currentFileLine = lineNumber;
    inverse = mode;
    init();
}
void RunFile::run()
{
    int ret = 0;
	//执行整个文件之前扫描一遍整个文件的label。
	scanLabel();
	//初始化保存读取文件信息的命令类型为未读取
    line.commandType = COMMAND_NONE_TYPE;
    
	//正向运行时，一直执行到遇到END，
	//逆向运行时，一直执行到遇到NOP。
    while(((line.commandType!=COMMAND_END_TYPE)&&(!state)&&(!inverse))
          ||
          ((line.commandType!=COMMAND_NOP_TYPE)&&(!state)&&(inverse)))
    {
  	  //判断运行是否暂停
      if(!runFilePause)
      {
        //判断是否为逆向运行
        if(!inverse)
        {
          	//正向
            ret = exeLine(currentFileLine);
            if(ret)
            {
            	if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_ERROR)
        		{
            		qDebug()<<"failed to forward exe line =   " << currentFileLine<< ", errocode is " << ret;
        		}
                break;
            }
            currentFileLine++;
        }
        else
        {
        	//逆向
            ret = exeInverseLine(currentFileLine);
            if(ret)
            {
              	if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_ERROR)
        		{
            		qDebug()<<"failed to inverse exe line =   " << currentFileLine<< ", errocode is " << ret;
        		}
                break;
            }
            currentFileLine--;
        }

      }
        msleep(100);
    }
	if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_INFOR)
    {
    	qDebug() << "exiting this thread";
    }    
}
void RunFile::stop()
{	
	if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_INFOR)
    {
    	qDebug() << "Runfile : stopping the thread";
    } 
    state = 1;
}
int RunFile::exeLine(int lineNumber)
{
    int ret =0;
	//从文件中读取某一行，放入到line中
    ret = op->readLine(lineNumber);
    line = op->getLine();
	if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_INFOR)
    {
	    qDebug("RunFile: exeLine commandType = %d",line.commandType);
    } 
    
    if(ret)
    {
        if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_ERROR)
        {
            qDebug()<<"read line error  lineNumber = " << lineNumber << " errocode is " << ret;
        }
        return ret;
    }
	//如果命令类型不是运动指令，那需要等待运动执行完成。
    if(line.commandType > COMMAND_MOVC_TYPE)
    {
        waitForMotion();
    }
	//如果读取的命令类型不是MOVC，那就将从新记录MOVC的计数。
    if(line.commandType!=COMMAND_MOVC_TYPE)
    {
      movcCount = 0;
    }
    ExeLine run = exe[line.commandType];
    ret = (this->*run)(lineNumber);
    return ret;
}


int RunFile::exeMovj(int lineNumber)
{

    if(movcCount >0&&movcCount != 3)
    {
        if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_ERROR)
        {
            qDebug()<<"can not exe movj before end of movc  count = " << movcCount ;
        }
        return CAN_NOT_DO_MOVJ_BEFORE_END_OF_MOVC;
    }
    //movcCount = 0;
    JointMoveInformation mj;
    if(line.p.coord == JOINT)
    {
        mj.endPoint.j1 = line.p.p[0];
        mj.endPoint.j2 = line.p.p[1];
        mj.endPoint.j3 = line.p.p[2];
        mj.endPoint.j4 = line.p.p[3];
        mj.endPoint.j5 = line.p.p[4];
        mj.endPoint.j6 = line.p.p[5];
    }
    else
    {
        if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_ERROR)
        {
            qDebug()<<"can not exe movj with a non joint pos = " << line.p.coord;
        }
        return ADD_MOVJ_WITH_NON_JOINT_POS;
    }
    if(line.vel.vj < 0)
    {
        mj.vJ = default_vj;
    }
    else
    {
        mj.vJ = line.vel.vj;
    }

    if(line.acc < 0)
    {
        mj.acc = default_acc;
        mj.dec = default_acc;
    }
    else
    {
        mj.acc = line.acc;
        mj.dec = line.acc;
    }
    if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_INFOR)
    {
        qDebug()<<"exe movj p = " << mj.endPoint.j1 << mj.endPoint.j2 << mj.endPoint.j3 << mj.endPoint.j4 << mj.endPoint.j5 << mj.endPoint.j6
               <<"vj = " << mj.vJ << "acc = " << mj.acc << "dec = " << mj.dec ;
    }
    CTRL_AddJointMove(&mj,lineNumber,0);
    return 0;
}
int RunFile::exeMovl(int lineNumber)
{
    if(movcCount >0&&movcCount != 3)
    {
        if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_ERROR)
        {
            qDebug()<<"can not exe movl before end of movc  count = " << movcCount ;
        }
        return CAN_NOT_DO_MOVL_BEFORE_END_OF_MOVC;
    }
    //movcCount = 0;
	//判断输入位置的坐标系类型，选择对应的motion接口。
    if(line.p.coord == JOINT)
    {
        LinearMoveInformation ml;
        ml.acc = line.acc;
        ml.dec = line.acc;
        ml.vL = line.vel.vl;
        ml.vR = line.vel.vr;

        if(line.vel.vl < 0)
        {
            ml.vL = default_vl;
        }
        if(line.vel.vr < 0)
        {
            ml.vR = default_vr;
        }
        if(line.acc < 0)
        {
            ml.acc = default_acc;
            ml.dec = default_acc;
        }

        ml.endPoint.j1 = line.p.p[0];
        ml.endPoint.j2 = line.p.p[1];
        ml.endPoint.j3 = line.p.p[2];
        ml.endPoint.j4 = line.p.p[3];
        ml.endPoint.j5 = line.p.p[4];
        ml.endPoint.j6 = line.p.p[5];
        if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_INFOR)
        {
            qDebug()<<"exe movl p = " << ml.endPoint.j1 << ml.endPoint.j2 << ml.endPoint.j3 << ml.endPoint.j4 << ml.endPoint.j5 << ml.endPoint.j6
                   <<"vl = " << ml.vL << "acc = " << ml.acc << "dec = " << ml.dec <<"vr = " << ml.vR ;
        }
        CTRL_AddLinearMove(&ml,lineNumber,0);
    }
    else if(line.p.coord == WORLD)
    {
        LinearDescartesMoveInformation dml;
        dml.acc = line.acc;
        dml.dec = line.acc;
        dml.vL = line.vel.vl;
        dml.vR = line.vel.vr;

        if(line.vel.vl < 0)
        {
            dml.vL = default_vl;
        }
        if(line.vel.vr < 0)
        {
            dml.vR = default_vr;
        }
        if(line.acc < 0)
        {
            dml.acc = default_acc;
            dml.dec = default_acc;
        }


        dml.endPoint.x = line.p.p[0];
        dml.endPoint.y = line.p.p[1];
        dml.endPoint.z = line.p.p[2];
        dml.zyx.a = line.p.p[3];
        dml.zyx.b = line.p.p[4];
        dml.zyx.c = line.p.p[5];

        dml.user.x = 0.0;
        dml.user.y = 0.0;
        dml.user.z = 0.0;
        dml.user.a = 0.0;
        dml.user.b = 0.0;
        dml.user.c = 0.0;

        dml.tool.x = 0.0;
        dml.tool.y = 0.0;
        dml.tool.z = 0.0;
        dml.tool.rx = 0.0;
        dml.tool.ry = 0.0;
        dml.tool.rz = 0.0;
        if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_INFOR)
        {
            qDebug()<<"exe movdl p = " << dml.endPoint.x << dml.endPoint.y << dml.endPoint.z << dml.zyx.a << dml.zyx.b << dml.zyx.c
                   <<"vl = " << dml.vL << "acc = " << dml.acc << "dec = " << dml.dec <<"vr = " << dml.vR ;
        }
        CTRL_AddDescartesLinearMove(&dml,lineNumber,0);
    }
    else if(line.p.coord == USR || line.p.coord == TOOL)
    {
        LinearDescartesMoveInformation dml;
        dml.acc = line.acc;
        dml.dec = line.acc;
        dml.vL = line.vel.vl;
        dml.vR = line.vel.vr;

        if(line.vel.vl < 0)
        {
            dml.vL = default_vl;
        }
        if(line.vel.vr < 0)
        {
            dml.vR = default_vr;
        }
        if(line.acc < 0)
        {
            dml.acc = default_acc;
            dml.dec = default_acc;
        }

        dml.endPoint.x = line.p.p[0];
        dml.endPoint.y = line.p.p[1];
        dml.endPoint.z = line.p.p[2];
        dml.zyx.a = line.p.p[3];
        dml.zyx.b = line.p.p[4];
        dml.zyx.c = line.p.p[5];

        dml.user.x = line.usr.x;
        dml.user.y = line.usr.y;
        dml.user.z = line.usr.z;
        dml.user.a = line.usr.a;
        dml.user.b = line.usr.b;
        dml.user.c = line.usr.c;

        dml.tool.x = line.tool.x;
        dml.tool.y = line.tool.y;
        dml.tool.z = line.tool.z;
        dml.tool.rx = line.tool.a;
        dml.tool.ry = line.tool.b;
        dml.tool.rz = line.tool.c;
        if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_INFOR)
        {
            qDebug()<<"exe movdl p = " << dml.endPoint.x << dml.endPoint.y << dml.endPoint.z << dml.zyx.a << dml.zyx.b << dml.zyx.c
                   <<"vl = " << dml.vL << "acc = " << dml.acc << "dec = " << dml.dec <<"vr = " << dml.vR ;
        }
        CTRL_AddDescartesLinearMove(&dml,lineNumber,0);
    }
    else
    {
        return UNKNONW_COORDINATE_TYPE;
    }

    return 0;
}
int RunFile::exeMovc(int lineNumber)
{
    CircularMoveInformation mc;
    CircularDescartesMoveInformation dmc;
    static JointPoint position[3];
	//连续3条movc才可以下发一条运动指令。
	//其中3条movc的输入位置参数类型必须是一致的。
    if(movcCount == 0 )
    {
        jointType = line.p.coord;
    }
    else if(jointType!=line.p.coord)
    {
        return MOVC_POSTION_TYPE_CONFLIC;
    }
	//当连续输入5条movc时，可以将第3条movc的指令当作第二段圆弧中的第一条
    else if(movcCount == 3)
    {
        position[0] = position[2];
        movcCount = 1;
    }
    movcCount ++;
    position[movcCount-1].j1 = line.p.p[0];
    position[movcCount-1].j2 = line.p.p[1];
    position[movcCount-1].j3 = line.p.p[2];
    position[movcCount-1].j4 = line.p.p[3];
    position[movcCount-1].j5 = line.p.p[4];
    position[movcCount-1].j6 = line.p.p[5];
	//记录movc中的位置信息，在最后一条movc中才会真正执行运动指令。

    if(movcCount == 3)
    {
        if(line.p.coord == JOINT)
        {
            mc.acc = line.acc;
            mc.dec = line.acc;
            mc.vL = line.vel.vl;
            mc.vR = line.vel.vr;

            if(line.vel.vl < 0)
            {
                mc.vL = default_vl;
            }
            if(line.vel.vr < 0)
            {
                mc.vR = default_vr;
            }
            if(line.acc < 0)
            {
                mc.acc = default_acc;
                mc.dec = default_acc;
            }

            for(int i=0; i < 3;i++)
            {
                mc.endPoint[i] = position[i];
            }
            if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_INFOR)
            {
                qDebug()<<"exe movc p1 = " <<mc.endPoint[0].j1 << mc.endPoint[0].j2 << mc.endPoint[0].j3 << mc.endPoint[0].j4 << mc.endPoint[0].j5 << mc.endPoint[0].j6
                        <<"p2 = " <<mc.endPoint[1].j1 << mc.endPoint[1].j2 << mc.endPoint[1].j3 << mc.endPoint[1].j4 << mc.endPoint[1].j5 << mc.endPoint[1].j6
                       <<"p3 = " <<mc.endPoint[2].j1 << mc.endPoint[2].j2 << mc.endPoint[2].j3 << mc.endPoint[2].j4 << mc.endPoint[2].j5 << mc.endPoint[2].j6
                       <<"vl = " << mc.vL << "acc = " << mc.acc << "dec = " << mc.dec <<"vr = " << mc.vR ;
            }
            CTRL_AddCircularMove(&mc,lineNumber,0);
        }
        else if(line.p.coord == WORLD)
        {
            dmc.acc = line.acc;
            dmc.dec = line.dec;
            dmc.vL = line.vel.vl;
            dmc.vR = line.vel.vr;
            if(line.vel.vl < 0)
            {
                dmc.vL = default_vl;
            }
            if(line.vel.vr < 0)
            {
                dmc.vR = default_vr;
            }
            if(line.acc < 0)
            {
                dmc.acc = default_acc;
                dmc.dec = default_acc;
            }


            dmc.free = 0;
            for(int i =0;i<3;i++)
            {
                dmc.endPoint[i].x = position[i].j1;
                dmc.endPoint[i].y = position[i].j2;
                dmc.endPoint[i].z = position[i].j3;
                dmc.zyx[i].a = position[i].j4;
                dmc.zyx[i].b = position[i].j5;
                dmc.zyx[i].c = position[i].j6;
            }
            dmc.user.x = 0.0;
            dmc.user.y = 0.0;
            dmc.user.z = 0.0;
            dmc.user.a = 0.0;
            dmc.user.b = 0.0;
            dmc.user.c = 0.0;

            dmc.tool.x = 0.0;
            dmc.tool.y = 0.0;
            dmc.tool.z = 0.0;
            dmc.tool.rx = 0.0;
            dmc.tool.ry = 0.0;
            dmc.tool.rz = 0.0;

            CTRL_AddDescartesCircularMove(&dmc,lineNumber,0);
        }
        else if(line.p.coord == USR || line.p.coord == TOOL)
        {

            dmc.acc = line.acc;
            dmc.free = 0;

            dmc.acc = line.acc;
            dmc.dec = line.dec;
            dmc.vL = line.vel.vl;
            dmc.vR = line.vel.vr;
            if(line.vel.vl < 0)
            {
                dmc.vL = default_vl;
            }
            if(line.vel.vr < 0)
            {
                dmc.vR = default_vr;
            }
            if(line.acc < 0)
            {
                dmc.acc = default_acc;
                dmc.dec = default_acc;
            }


            for(int i =0;i<3;i++)
            {
                dmc.endPoint[i].x = position[i].j1;
                dmc.endPoint[i].y = position[i].j2;
                dmc.endPoint[i].z = position[i].j3;
                dmc.zyx[i].a = position[i].j4;
                dmc.zyx[i].b = position[i].j5;
                dmc.zyx[i].c = position[i].j6;
            }
            dmc.user.x = line.usr.x;
            dmc.user.y = line.usr.y;
            dmc.user.z = line.usr.z;
            dmc.user.a = line.usr.a;
            dmc.user.b = line.usr.b;
            dmc.user.c = line.usr.c;

            dmc.tool.x = line.tool.x;
            dmc.tool.y = line.tool.y;
            dmc.tool.z = line.tool.z;
            dmc.tool.rx = line.tool.a;
            dmc.tool.ry = line.tool.b;
            dmc.tool.rz = line.tool.c;

            CTRL_AddDescartesCircularMove(&dmc,lineNumber,0);
        }
        else
        {
            return UNKNONW_COORDINATE_TYPE;
        }

    }
    return 0;

}
int RunFile::exeSpeed(int lineNumber)
{
    default_vj = line.vel.vj;
    default_vl = line.vel.vl;
    default_vr = line.vel.vr;
    default_acc = line.acc;
    return 0;
}

int RunFile::exeDin(int lineNumber)
{
    //call interface

    //int value = din(line.IoPort);
    //setByte(line.byteAddress,value);
    return 0;
}
int RunFile::exeDout(int lineNumber)
{
    //call interface

    //dout(line.IoPort,line.dOutValue);
    return 0;
}
int RunFile::exePause(int lineNumber)
{
    int condition = 0;

    condition = exeCondition();
	//进入到这个函数当中，整个线程不会执行其它东西。会一直阻塞在这里。一直到pause被置为1。
    while(condition&&(!state))
    {
        msleep(100);
        if(pause)
        {
            condition = 0;
            pause = 0;
        }
    }
    return 0;
}
int RunFile::exeTimer(int lineNumber)
{
   // movcCount = 0;
    double mtime = line.time*1000;
    QTime start = QTime::currentTime();
    QTime end = QTime::currentTime();
	//进入到执行计时器函数中，开始计时，一直到时间达到预定才会推出去。或者state就是执行状态表示整个线程表示停止也会推出。
    while((start.msecsTo(end) < mtime)&&(!state))
    {
        //qDebug() << "timer start = " <<start <<"end = " <<end <<"mtime = " << mtime;
        //qDebug() << "time lasting is " <<start.msecsTo(end);
        msleep(100);
        end = QTime::currentTime();
    }
    return 0;
}
int RunFile::exeLabel(int lineNumber)
{
    return 0;
}
int RunFile::exeJump(int lineNumber)
{
    int condition = 0;
    condition = exeCondition();
	//从标签容器中找到匹配的标签，将当前行指向标签的当前行。
	//这里未考虑在执行子程序调用对标签容器的影响。应该会有一个bug。
    if(condition)
    {
        int fileLine;
        fileLine = labelMap[QString(line.lablel)];
        if(fileLine>0)
        {
            currentFileLine = fileLine;
        }
        //currentFileLine = line.lablel;
    }
    return 0;
}
int RunFile::exeCall(int lineNumber)
{
    int condition = 0;
    int ret =0 ;
    condition = exeCondition();
    if(condition)
    {
        SubFile sub;
		//将当前的程序文件的信息记录，并压入到链表当中
        sub.fileLine = currentFileLine;
        sub.fileName = this->fileName;
        subList.prepend(sub);
		qDebug() << "call sub file = " << line.fileName;
		//打开子程序
		ret = op->init(line.fileName);
        this->fileName = line.fileName;
        currentFileLine = 0;
		//扫描子程序标签。
		scanLabel();
        if(ret)
        {
            return false;
        }
    }
  // Q_EMIT FileNameChanged(this->fileName);
    return 0;
}
int RunFile::exeRet(int lineNumber)
{
    int condition = 0;
    int ret =0 ;
    condition = exeCondition();
	//执行返回
    if(condition)
    {
    	//从文件链表中读取最后一个，回复其信息，并且将它的信息从链表中移除
        SubFile sub;
        sub = subList.first();
        subList.removeFirst();
        this->fileName = sub.fileName;
        this->currentFileLine = sub.fileLine;
        qDebug() << "return to file " << this->fileName <<"at line " << this->currentFileLine;
        ret = op->init(fileName);
		//重新扫描标签。
		scanLabel();
        if(ret)
        {
            qDebug() << "open file error " <<ret;
            return false;
        }
    }
    //Q_EMIT FileNameChanged(this->fileName);
    return 0;
}
int RunFile::exeNop(int lineNumber)
{
    qDebug("RunFile: exeNope");
    return 0;
}
int RunFile::exeEnd(int lineNumber)
{
   // Q_EMIT FileClosed();
    return 0;
}

//循环启动按键接口
void RunFile::setPause()
{
    pause = 1;
    runFilePause = 0;
}
void RunFile::scanLabel()
{
    int i =0;
    int ret;
	//扫描整个文件中的label到指定容器中，
	//这里未考虑到子程序文件，在主程序中，扫描到END，在子程序中扫描到RET。
    for(;line.commandType!= COMMAND_END_TYPE&&line.commandType!= COMMAND_RET_TYPE;)
    {
        ret = op->readLine(i);
        if(ret)
        {
            if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_ERROR)
            {
                qDebug()<<"read line error , errorCode is  " << ret;
            }
            break;
        }
        line = op->getLine();
        if(line.commandType == COMMAND_LABEL_TYPE)
        {
            labelMap.insert(QString(line.lablel),i);
        }
        i++;
    }
    op->readLine(0);
    line = op->getLine();
}
int RunFile::exeCondition()
{
    int condition = 0;
    if(line.condition.type == VAR_TYPE_NONE)
    {
        condition = 1;
    }
    else
    {
        int valueLeft;
        int valueRight;
        switch(line.condition.type)
        {
            case DIN:
                //call interface
                valueRight = line.condition.value.dio;
                //valueLeft = din(line.condition.varAddress)
                break;
            case DOUT:
               // valueLeft = readDout(line.condition.varAddress)
                valueRight = line.condition.value.dio;
                break;
            case BYTE:
              //valueLeft = getByte(line.condition.varAddress)
                valueRight = line.condition.value.integerValue;
                break;
            case INT:
              //valueLeft = getInt(line.condition.varAddress)
                valueRight = line.condition.value.integerValue;
                break;
        default:
            condition = 0;
            break;
        }
        switch(line.condition.sign)
        {
        case EQ:
            if(valueLeft == valueRight)
                condition = 1;
            else
                condition = 0;
            break;
        case GT:
            if(valueLeft > valueRight)
                condition = 1;
            else
                condition = 0;
            break;
        case LT:
            if(valueLeft < valueRight)
                condition = 1;
            else
                condition = 0;
            break;
        case GE:
            if(valueLeft >= valueRight)
                condition = 1;
            else
                condition = 0;
            break;
        case LE:
            if(valueLeft <= valueRight)
                condition = 1;
            else
                condition = 0;
            break;
        default:
            condition = 0;
            break;
        }
    }
    return condition;

}
int RunFile::exeInverseLine(int lineNumber)
{

    int ret =0;
	int i=lineNumber - 1;
    ret = op->readLine(lineNumber);
    qDebug("read lineNumber = %d",lineNumber);
    line = op->getLine();
    if(ret)
    {
        return ret;
    }
	//逆向执行。首先逆向运行的思路是不能执行跳转，子程序调用。其他命令都可以执行。
	//在逆向运行的过程中，movc就正常按读取到的指令执行。movj和movl需要执行上一个运动位置的终点位置。
	//

	
    if(line.commandType > COMMAND_MOVC_TYPE)
    {
    	if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_INVERSE)
        {
        	qDebug()<<"inverse : exe %d " << line.commandType;
        }
        waitForMotion();
    }
    if((line.commandType == COMMAND_LABEL_TYPE)||
       (line.commandType == COMMAND_JUMP_TYPE)||
       (line.commandType == COMMAND_CALL_TYPE)||
       (line.commandType == COMMAND_RET_TYPE))
    {
      return 0;
    }
    if(
       line.commandType == COMMAND_MOVL_TYPE||
       line.commandType == COMMAND_MOVJ_TYPE
       )
    {
       	if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_INVERSE)
        {
        	qDebug()<<"inverse : exe %d " << line.commandType;
        }
		//在逆向执行时，当下面一行(行号大1的行)为movc时，有可能会造成正向和逆向运动结果不一样。
		//所以这里，在这种情况下在movj或者时movl中添加一行直线命令进行过渡
        if(nextLine.commandType == COMMAND_MOVC_TYPE)
        {
            if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_INVERSE)
        	{
        		qDebug()<<"inverse : exe %d"<< line.commandType<<"and the nextline is MOVC" ;
        	}
          ExeLine run = exe[line.commandType];
          ret = (this->*run)(lineNumber);
        }
        ProgramXmlLine lastLine;	//当前行的上面一行，如果行号未5，则lastLine为4.
        lastLine.commandType = COMMAND_NONE_TYPE;
		//movj 与 movl需要读取上一条运动指令的终点位置值。
        while((lastLine.commandType != COMMAND_MOVJ_TYPE)&&
              (lastLine.commandType != COMMAND_MOVL_TYPE)&&
              (lastLine.commandType != COMMAND_MOVC_TYPE)&&(!state))
        {
            ret = op->readLine(i);
			if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_INVERSE)
        	{
        		qDebug()<<"inverse : reading from last line.number = " << i;
        	}
            if(ret)
            {
                if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_INVERSE)
        		{
        			qDebug()<<"inverse : failed to read lastline ret = " << ret;
        		}
                return ret;
            }
            lastLine = op->getLine();
			//如果上一行是运动指令，将位置信息记录在当前行的位置信息上。
            if(lastLine.commandType == COMMAND_MOVJ_TYPE||
               lastLine.commandType == COMMAND_MOVL_TYPE||
               lastLine.commandType == COMMAND_MOVC_TYPE)
            {
            	if(RF_PROGRAM_DEBUG&RF_PROGRAM_DEBUG_INVERSE)
        		{
        			qDebug()<<"inverse : read move command type = " << lastLine.commandType;
        		}
                line.p = lastLine.p ;
            }
			//如果读到了NOP，表示已经读取到了文件的第一行，那就不能在继续了。
			if(lastLine.commandType == COMMAND_NOP_TYPE)
			{
				return 0;
			}
			//否则继续向前读取。
            i--;
        }
    }
    if(line.commandType == COMMAND_MOVJ_TYPE||
       line.commandType == COMMAND_MOVL_TYPE||
       line.commandType == COMMAND_MOVC_TYPE)
    {
      nextLine = line;
    }
    if(line.commandType!=COMMAND_MOVC_TYPE)
    {
      movcCount = 0;
    }
    ExeLine run = exe[line.commandType];
    ret = (this->*run)(lineNumber);
    return ret;

}
void RunFile::waitForMotion()
{
    MotionFeedback fb;
    CTRL_GetMotionStatus(&fb);
    while(fb.motionState!=COMMAND_DONE&&(!state))
    {
        //qDebug() << "fb.motionState = " << fb.motionState << "state = " << state;
        CTRL_GetMotionStatus(&fb);
        msleep(100);
    }
    return;
}
int RunFile::getCurrentNumber()
{
  return currentFileLine;
}
void RunFile::interpPause()
{
  runFilePause = 1;
}
