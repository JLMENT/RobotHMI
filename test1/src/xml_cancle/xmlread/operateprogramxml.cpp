#include "operateprogramxml.h"



OperateProgramXml::OperateProgramXml()
{
    qDebug()<<"start operateprogramXml";
    readParamFun[COMMAND_MOVJ_TYPE]=&OperateProgramXml::readMovj;
    readParamFun[COMMAND_MOVL_TYPE]=&OperateProgramXml::readMovl;
    readParamFun[COMMAND_MOVC_TYPE]=&OperateProgramXml::readMovc;
    readParamFun[CMOMAND_SPEED_TYPE]=&OperateProgramXml::readSpeed;
    readParamFun[COMMAND_DOUT_TYPE]=&OperateProgramXml::readDout;
    readParamFun[COMMAND_DIN_TYPE]=&OperateProgramXml::readDin;
    readParamFun[COMMAND_JUMP_TYPE]=&OperateProgramXml::readJump;
    readParamFun[COMMAND_LABEL_TYPE]=&OperateProgramXml::readLabel;
    readParamFun[COMMAND_CALL_TYPE]=&OperateProgramXml::readCall;
    readParamFun[COMMAND_PAUSE_TYPE]=&OperateProgramXml::readPause;
    readParamFun[COMMAND_TIMER_TYPE]=&OperateProgramXml::readTimer;
    readParamFun[COMMAND_RET_TYPE]=&OperateProgramXml::readRet;
    readParamFun[COMMAND_NOP_TYPE]=&OperateProgramXml::readNOP;
    readParamFun[COMMAND_END_TYPE]=&OperateProgramXml::readEND;
}



/*
    function: init the whole class object,
    parameter:fileName is the name of the program file that you want to operate
              it shouldn't contain the suffix,
              but could contain the abolute or relative path
    return value: 0 means open the file correctly,
                  otherwise chech the opXmlErrorType.h for what happend.
*/
int OperateProgramXml::init(QString fileName)
{
    //read program xml file
    QFile programFile(fileName+".xml");
    if(!programFile.open(QFile::ReadOnly))
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class  function init : can not open program file" << fileName;
        }
        return CANNOT_OPEN_PROGRAM_FILE;
    }
    QDomDocument doc(fileName);
    if(!doc.setContent(&programFile))
    {
        programFile.close();
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class  function init : can not map program file to Dom";
        }
        return CANNOT_MAP_PROGRAM_FILE_TO_DOM;
    }
    programFile.close();

    programRoot=doc.documentElement();


    //read position xml file
    QFile positionFile(fileName+"_position.xml");
    if(!positionFile.open(QFile::ReadOnly))
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class  function init : can not open position file";

        }
        return CANNOT_OPEN_POSITION_FILE;
    }


    if(!positionDoc.setContent(&positionFile))
    {
        positionFile.close();
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class  function init : can not map position file to dom";
        }
        return CANNOT_MAP_POSITION_FILE_TO_DOM;
    }
    positionFile.close();

    // read usr file
    QFile usrFile("usr.xml");
    if(!usrFile.open(QFile::ReadOnly))
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class  function init : can not open usr file";

        }
        return FAILD_TO_READ_USR_FILE;
    }


    if(!usrDoc.setContent(&usrFile))
    {
        usrFile.close();
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class  function init : can not map usr file to dom";
        }
        return CANNOT_MAP_USR_FILE_TO_DOM;
    }
    usrFile.close();

    //read tool file

    QFile toolFile("tool.xml");
    if(!toolFile.open(QFile::ReadOnly))
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class  function init : can not open tool file";

        }
        return FAILD_TO_READ_TOOL_FILE;
    }


    if(!toolDoc.setContent(&toolFile))
    {
        toolFile.close();
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class  function init : can not map tool file to dom";
        }
        return CANNOT_MAP_TOOL_FILE_TO_DOM;
    }
    toolFile.close();


    initLine();
    if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
    {
        qDebug() << "operate xml class  function init : correctly open the program and position file" <<fileName;
    }

    return 0;
}
/*
    function: read one line of the xml file
    parameter: lineNumber indicates which line to read.
    return value: 0 means open the file correctly,
                  otherwise chech the opXmlErrorType.h for what happend.
*/

int OperateProgramXml::readLine(int lineNumber)
{
    int ret;
    CommandType cmd;
    //init the line first
    initLine();
    //first read the command type of the line

    if(programRoot.isNull())
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readLine : the root child is null" ;
        }
        return READ_LINE_FIRST_CHILD_NULL;

    }
    if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
    {
        qDebug() << "operate xml class readLine : root.tagName=" << programRoot.tagName();
    }
    QDomNodeList list = programRoot.childNodes();
    QDomNode node =list.at(lineNumber);

    //QDomNode n = node.firstChild();
    QDomElement cmdType= node.toElement();
    if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
    {
        qDebug() << "operate xml class readLine : cmdType.tagName=" << cmdType.tagName();
    }

    cmd=readCmdType(cmdType);
    //now we already find the command type
    //we have to find the command information according to the command type
    OperateProgramXml param;
    if(COMMAND_NONE_TYPE == cmd)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readLine : faild to abstract a valid command type";
        }
        return READ_LINE_CANNOT_FIND_CMD_TYPE;
    }
    line.commandType=cmd;
    ret=(this->*readParamFun[cmd])(node.firstChild(),&line);
    if(!ret)
    {
        return ret;
    }
    return 0;
}

/*
    function: open program  xml file
    parameter: fileName indicates which file to read.
              it shouldn't contain the suffix,
              but could contain the abolute or relative path
    return value: 0 means open the file correctly,
                  otherwise chech the opXmlErrorType.h for what happend.

*/

int OperateProgramXml::openFile(QString fileName)
{

}
/*
    function: open program position xml file
    parameter: fileName indicates which file to read.
              it shouldn't contain the suffix,
              but could contain the abolute or relative path
    return value: 0 means open the file correctly,
                  otherwise chech the opXmlErrorType.h for what happend.

*/

int OperateProgramXml::openPositionFile(QString fileName)
{

}
/*
    function: init the private ProgramXmlLine structure
    parameter: none
    return value: none
*/
void OperateProgramXml::initLine(void)
{
    line.commandType=COMMAND_NONE_TYPE;
    line.vel.vj=-1.0;
    line.vel.vl=-1.0;
    line.vel.vr=-1.0;
    line.acc=-1.0;
    line.dec=-1.0;
    line.lablel=-1;
    line.fileName="";
    line.time=-1.0;
    line.p.coord=NONE;
    line.pl=-1;
    line.condition.type=VAR_TYPE_NONE;
    line.condition.varAddress=-1;
    line.nwait=-1;
    line.usr.x=0;
    line.usr.y=0;
    line.usr.z=0;
    line.usr.a=0;
    line.usr.b=0;
    line.usr.c=0;
    line.tool.x=0;
    line.tool.y=0;
    line.tool.z=0;
    line.tool.a=0;
    line.tool.b=0;
    line.tool.c=0;
    line.IoPort=-1;
    line.byteAddress=-1;
}


/*
    function: read the command type of one xml line
    parameter: cmdType contains one node of a gui programmed line
    return value: one of the enum CommandType value
                  or -1 means faild to read a valid command type
*/

CommandType OperateProgramXml::readCmdType(QDomElement cmdType)
{
    //read the cmdType
    QString cmdString;
    CommandType ret;
    cmdString = cmdType.tagName();
    if(cmdString == XML_TAG_NAME_MOVJ)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
        {
            qDebug() << "operate xml class readCmdType : find a movj";
        }
        ret = COMMAND_MOVJ_TYPE;
    }
    else if(cmdString == XML_TAG_NAME_MOVL)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
        {
            qDebug() << "operate xml class readCmdType : find a movl";
        }
        ret = COMMAND_MOVL_TYPE;
    }
    else if(cmdString == XML_TAG_NAME_MOVC)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
        {
            qDebug() << "operate xml class readCmdType : find a movc";
        }
        ret = COMMAND_MOVC_TYPE;
    }
    else if(cmdString == XML_TAG_NAME_SPEED)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
        {
            qDebug() << "operate xml class readCmdType : find a speed";
        }
        ret = CMOMAND_SPEED_TYPE;
    }
    else if(cmdString == XML_TAG_NAME_DOUT)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
        {
            qDebug() << "operate xml class readCmdType : find a DOUT";
        }
        ret = COMMAND_DOUT_TYPE;
    }
    else if(cmdString == XML_TAG_NAME_DIN)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
        {
            qDebug() << "operate xml class readCmdType : find a DIN";
        }
        ret = COMMAND_DIN_TYPE;
    }
    else if(cmdString == XML_TAG_NAME_JUMP)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
        {
            qDebug() << "operate xml class readCmdType : find a JUMP";
        }
        ret = COMMAND_JUMP_TYPE;
    }
    else if(cmdString == XML_TAG_NAME_LABEL)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
        {
            qDebug() << "operate xml class readCmdType : find a LABEL";
        }
        ret = COMMAND_LABEL_TYPE;
    }
    else if(cmdString == XML_TAG_NAME_CALL)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
        {
            qDebug() << "operate xml class readCmdType : find a CALL";
        }
        ret = COMMAND_CALL_TYPE;
    }
    else if(cmdString == XML_TAG_NAME_PAUSE)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
        {
            qDebug() << "operate xml class readCmdType : find a PAUSE";
        }
        ret = COMMAND_PAUSE_TYPE;
    }
    else if(cmdString == XML_TAG_NAME_TIMER)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
        {
            qDebug() << "operate xml class readCmdType : find a TIMER";
        }
        ret = COMMAND_TIMER_TYPE;
    }
    else if(cmdString == XML_TAG_NAME_RET)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
        {
            qDebug() << "operate xml class readCmdType : find a RET";
        }
        ret = COMMAND_RET_TYPE;
    }
    else if(cmdString == XML_TAG_NAME_NOP)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
        {
            qDebug() << "operate xml class readCmdType : find a NOP";
        }
        ret = COMMAND_NOP_TYPE;
    }
    else if(cmdString == XML_TAG_NAME_END)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
        {
            qDebug() << "operate xml class readCmdType : find a END";
        }
        ret = COMMAND_END_TYPE;
    }
    else
    {
        ret = COMMAND_NONE_TYPE;
    }
    return ret;
}

/*
    function: read velocity information of one xml line
    parameter: vel is the xml information,
               out is the digital information
    return value: one of the enum CommandType value
                  or -1 means faild to read a valid command type
*/

int OperateProgramXml::readVelocity(QDomNode vel,Velocity *out)
{
    //vel = vel.firstChild();
    int vstyle;
    while(!vel.toElement().isNull())
    {
        //read vj
        if(vel.toElement().tagName() == XML_TAG_NAME_VJ)
        {
            out->vj = vel.toElement().text().toDouble();
            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
            {
                qDebug()<<"read Velocity: find vj = " << out->vj;
            }
        }
        else if(vel.toElement().tagName() == XML_TAG_NAME_VL)
        {
            out->vl = vel.toElement().text().toDouble();
            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
            {
                qDebug()<<"read Velocity: find vl = " << out->vl;
            }
        }
        else if(vel.toElement().tagName() == XML_TAG_NAME_VR)
        {
            out->vr = vel.toElement().text().toDouble();
            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
            {
                qDebug()<<"read Velocity: find vr = " << out->vr;
            }

        }
        else if(vel.toElement().tagName() == XML_TAG_NAME_VSTYLE)
        {
            if(vel.toElement().text() == XML_TAG_NAME_SPEED_VJ)
            {
                vel = vel.nextSibling();
                if(vel.toElement().tagName() == XML_TAG_NAME_VALUE)
                    out->vj = vel.toElement().text().toDouble();
                if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
                {
                    qDebug()<<"read Velocity: find vj = " << out->vj;
                }
            }
            else if(vel.toElement().text() == XML_TAG_NAME_SPEED_VL)
            {
                vel = vel.nextSibling();
                if(vel.toElement().tagName() == XML_TAG_NAME_VALUE)
                    out->vl = vel.toElement().text().toDouble();
                if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
                {
                    qDebug()<<"read Velocity: find vl = " << out->vl;
                }
            }
            else if(vel.toElement().text() == XML_TAG_NAME_SPEED_VR)
            {
                vel = vel.nextSibling();
                if(vel.toElement().tagName() == XML_TAG_NAME_VALUE)
                    out->vr = vel.toElement().text().toDouble();
                if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
                {
                    qDebug()<<"read Velocity: find vr = " << out->vr;
                }
            }
            else
            {
                return UNKNOWN_VELOCITY_TYPE;
            }
        }
        vel = vel.nextSibling();
    }
    if((out->vj<0)&&(out->vl<0)&&(out->vr<0))
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug()<<"read Velocity: faild to read velocity ";
        }
        //return  FAILD_TO_READ_VELOCITY;
    }
    return 0;
}
/*
    function: read acc information of one xml line
    parameter: acc is the xml information,
               out is the digital information
    return value: one of the enum CommandType value
                  or -1 means faild to read a valid command type
*/
int OperateProgramXml::readAcc(QDomNode acc,double *out)
{
    while(!acc.toElement().isNull())
    {
        if(acc.toElement().tagName() == XML_TAG_NAME_ACC)
        {
            *out = acc.toElement().text().toDouble();

            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
            {
                qDebug()<<"read Acc: read acc = " << *out;
            }
            return 0;
        }
        acc = acc.nextSibling();
    }
    if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
    {
        qDebug()<<"read Acc: failed to acc" << *out;
    }
    return FAILD_TO_READ_ACC;

}

/*
    function: read position information of one xml line
    parameter: position is the xml information,
               out is the digital information
    return value: one of the enum CommandType value
                  or -1 means faild to read a valid command type
*/
int OperateProgramXml::readPosition(QDomNode position,Position *out)
{
    //position = position.firstChild();

    while(!position.toElement().isNull())
    {
        if(position.toElement().tagName() == XML_TAG_NAME_POSITION )
        {
            QString     pName = position.toElement().text();
            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
            {
                qDebug()<<"read Position: find tag named position" << pName;
            }
            //read position value from the position file
            QDomNodeList list = positionDoc.elementsByTagName(pName);
            if(list.count()>0)
            {

                QDomNode n = list.at(0);
                if(!n.firstChild().isNull())
                {
                    if(n.firstChild().hasChildNodes())
                    {
                       QDomNodeList info =  n.childNodes();
                       //qDebug()<< info.count();
                       if(info.count() == 7)
                       {
                           QDomNode coord = info.at(0);
                           if(coord.toElement().text() == XML_TAG_NAME_JOINT)
                           {
                                out->coord=JOINT;
                           }
                           else if(coord.toElement().text() == XML_TAG_NAME_WORLD)
                           {
                                out->coord=WORLD;
                           }
                           else if(coord.toElement().text() == XML_TAG_NAME_FRAME_USR)
                           {
                                out->coord=USR;
                           }
                           else if(coord.toElement().text() == XML_TAG_NAME_FRAME_TOOL)
                           {
                                out->coord=TOOL;
                           }
                           else
                           {
                               out->coord=NONE;
                               //error
                               if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
                               {
                                   qDebug()<<"read Position: failed to read coord" << coord.toElement().text();
                               }
                               return READ_POSITION_INFORMATION_FAILED;
                           }
                           if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
                           {
                               qDebug() <<"read Position: position type is " << out->coord;
                           }

                           for(int i=1 ; i< 7 ; i++)
                           {
                               //read position value to out
                               QDomNode value = info.at(i);
                               out->p[i-1] = value.toElement().text().toFloat();
                               if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
                               {
                                   qDebug() << "read Position: position" << i << "value is " << out->p[i-1];
                               }
                           }
                       }
                       else
                       {
                           if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
                           {
                               qDebug()<<"read Position: wrong tag number " << info.count();
                           }
                           return READ_POSITION_INFORMATION_FAILED;
                       }
                    }
                    else
                    {
                        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
                        {
                            qDebug()<<"read Position: no position information";
                        }
                        return READ_POSITION_INFORMATION_FAILED;
                    }

                }
                else
                {
                    if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
                    {
                        qDebug()<<"read Position: no position information";
                    }
                    return READ_POSITION_INFORMATION_FAILED;
                }
            }
            else
            {
                if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
                {
                    qDebug()<<"read Position: there is no tag named" << pName << "in the position file";
                }
                return READ_POSITION_NO_POSITION_NAME;
            }

            return 0;
        }
        position = position.nextSibling();
    }
    if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
    {
        qDebug()<<"read Position: there is no tag named position";
    }
    return READ_POSITION_NO_POSITION_TAG;
}

/*
    function: read position level information of one xml line
    parameter: pl is the xml information,
               out is the digital information
    return value: one of the enum CommandType value
                  or -1 means faild to read a valid command type
*/
int OperateProgramXml::readPL(QDomNode pl,int *out)
{
    while(!pl.toElement().isNull())
    {
        if(pl.toElement().tagName() == XML_TAG_NAME_PL)
        {
            *out = pl.toElement().text().toInt();

            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
            {
                qDebug()<<"read PL: read pl = " << *out;
            }
            return 0;
        }
        pl = pl.nextSibling();
    }
    if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
    {
        qDebug()<<"read Acc: PL to pl" << *out;
    }
    return FAILD_TO_READ_PL;
}
/*
    function: read condition information of one xml line
    parameter: condition is the xml information,
               out is the digital information
    return value: one of the enum CommandType value
                  or -1 means faild to read a valid command type
*/
int OperateProgramXml::readCondition(QDomNode condition,Condition *out)
{
    while(!condition.toElement().isNull())
    {
        //read condition information
        if(condition.toElement().tagName() == XML_TAG_NAME_IF ||
           condition.toElement().tagName() == XML_TAG_NAME_UNTILL)
        {
            //qDebug() << condition.toElement().tagName();
            if(1 == condition.toElement().text().toInt())
            {

            }
            else if(0 == condition.toElement().text().toInt())
            {

                return 0;
            }
            else
            {
                if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
                {
                    qDebug()<<"read condition: known if tag value " << condition.toElement().text().toInt();
                }
                return FAILD_TO_READ_IF_TAG;
            }
        }
        else if(condition.toElement().tagName() == XML_TAG_NAME_IOSELECT ||
                condition.toElement().tagName() == XML_TAG_NAME_VARTYPE)
        {
            if(condition.toElement().text() == XML_TAG_NAME_IO_TYPE_B)
            {
                out->type = BYTE;
            }
            else if(condition.toElement().text() == XML_TAG_NAME_IO_TYPE_INT)
            {
                out->type = INT;
            }
            else if(condition.toElement().text() == XML_TAG_NAME_DIN)
            {
                out->type = DIN;
            }
            else if(condition.toElement().text() == XML_TAG_NAME_DOUT)
            {
                out->type = DOUT;
            }
            else
            {
                out->type = VAR_TYPE_NONE;
                return FAILD_TO_READ_IO_TYPE;
            }

        }
        else if(condition.toElement().tagName() == XML_TAG_NAME_IONUMBER ||
                condition.toElement().tagName() == XML_TAG_NAME_VARADDRESS)
        {
            out->varAddress = condition.toElement().text().toInt();
        }
        else if(condition.toElement().tagName() == XML_TAG_NAME_COMPARESIGN ||
                condition.toElement().tagName() == XML_TAG_NAME_IOPREPARE)
        {
            if(condition.toElement().text() == ">")
            {
                out->sign = GT;
            }
            else if(condition.toElement().text() == "=")
            {
                out->sign = EQ;
            }
            else if(condition.toElement().text() == "<")
            {
                out->sign = LT;
            }
            else if(condition.toElement().text() == ">=")
            {
                out->sign = GE;
            }
            else if(condition.toElement().text() == "<=")
            {
                out->sign = LE;
            }
            else
            {
                out->sign = CMP_TYPE_NONE;
            }
        }
        else if(condition.toElement().tagName() == XML_TAG_NAME_IOIO ||
                condition.toElement().tagName() == XML_TAG_NAME_COMPAREVALUE)
        {
            switch(out->type)
            {
            case DIN:
            case DOUT:
                if(condition.toElement().text() == XML_TAG_NAME_IO_VALUE_ON)
                {
                    out->value.dio = ON;
                }
                else if(condition.toElement().text() == XML_TAG_NAME_IO_VALUE_OFF)
                {
                    out->value.dio = OFF;
                }
                else
                {
                    out->value.dio = IO_NONE;
                }
                 break;
            case BYTE:
            case INT:
                out->value.integerValue = condition.toElement().text().toInt();
                break;
            default:
                break;
            }
        }
        condition = condition.nextSibling();
    }
    if(out->sign == CMP_TYPE_NONE || out->type == VAR_TYPE_NONE ||
       out->value.dio == IO_NONE || out->value.integerValue <0||
       out->varAddress <0)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug()<<"read condition: read condition error sign = "<< out->sign <<"type = " << out->type <<"varAddress =" << out->varAddress <<
                      "value.dio =" << out->value.dio <<
                      "value.integerValue = " << out->value.integerValue;
        }
        return READ_CONDITION_INFORMATION_ERROR;
    }
    if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
    {
        qDebug()<<"read condition: read condition info sign = "<< out->sign <<"type = " << out->type <<"varAddress =" << out->varAddress <<
                  "value.dio =" << out->value.dio <<
                  "value.integerValue = " << out->value.integerValue;
    }
    return 0;
}
/*
    function: read nwait information of one xml line
    parameter: nwait is the xml information,
               out is the digital information
    return value: one of the enum CommandType value
                  or -1 means faild to read a valid command type
*/

int OperateProgramXml::readNwait(QDomNode nwait,int *out)
{
    while(!nwait.toElement().isNull())
    {
        if(nwait.toElement().tagName() == XML_TAG_NAME_NWAIT)
        {
            *out = nwait.toElement().text().toInt();

            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
            {
                qDebug()<<"read nwait: read nwait = " << *out;
            }
            return 0;
        }
        nwait = nwait.nextSibling();
    }
    if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
    {
        qDebug()<<"read nwait: nwait " << *out;
    }
    return FAILD_TO_READ_NWAIT;
}

/*
    function: read usr information of one xml line
    parameter: usr is the xml information,
               out is the digital information
    return value: one of the enum CommandType value
                  or -1 means faild to read a valid command type
*/
int OperateProgramXml::readUsrInformation(QDomNode usr, UsrInformation *out)
{
    //first find out which usr to use
    while(!usr.toElement().isNull())
    {
        if(usr.toElement().tagName() == XML_TAG_NAME_USR )
        {
            QString usrName = usr.toElement().text();
            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
            {
                qDebug()<<"read usr: find tag named usr" << usrName;
            }
            QDomNodeList list = usrDoc.elementsByTagName(usrName);
            if(list.count()>0)
            {
                QDomNode n = list.at(0);
                if(!n.firstChild().isNull())
                {
                    if(n.firstChild().hasChildNodes())
                    {
                        QDomNodeList info =  n.childNodes();
                        //qDebug()<< info.count();
                        if(info.count() == 6)
                        {
                            out->x = info.at(0).toElement().text().toFloat();
                            out->y = info.at(1).toElement().text().toFloat();
                            out->z = info.at(2).toElement().text().toFloat();
                            out->a = info.at(3).toElement().text().toFloat();
                            out->b = info.at(4).toElement().text().toFloat();
                            out->c = info.at(5).toElement().text().toFloat();
                            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
                            {
                                qDebug() << "read usr: x = " << out->x << "y = " << out->y << "z = " <<out->z
                                         << "a = " << out->a <<"b = " << out->b  << "c = " << out->c;
                            }
                        }
                        else
                        {
                            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
                            {
                                qDebug()<<"read usr: wrong tag number " << info.count();
                            }
                            return READ_USR_INFORMATION_FAILED;
                        }
                    }

                }
            }
            else
            {
                if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
                {
                    qDebug()<<"read Usr: there is no tag named" << usrName << "in the usr file";
                }
                return READ_USR_NO_USR_NAME;
            }
            return 0;
        }
        usr = usr.nextSibling();
    }
    return 0;
}
/*
    function: read tool information of one xml line
    parameter: tool is the xml information,
               out is the digital information
    return value: one of the enum CommandType value
                  or -1 means faild to read a valid command type
*/
int OperateProgramXml::readToolInformation(QDomNode tool, ToolInformation *out)
{
    while(!tool.toElement().isNull())
    {
        if(tool.toElement().tagName() == XML_TAG_NAME_TOOL )
        {
            QString toolName = tool.toElement().text();
            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
            {
                qDebug()<<"read tool: find tag named tool" << toolName;
            }
            QDomNodeList list = toolDoc.elementsByTagName(toolName);
            if(list.count()>0)
            {
                QDomNode n = list.at(0);
                if(!n.firstChild().isNull())
                {
                    if(n.firstChild().hasChildNodes())
                    {
                        QDomNodeList info =  n.childNodes();
                        //qDebug()<< info.count();
                        if(info.count() == 6)
                        {
                            out->x = info.at(0).toElement().text().toFloat();
                            out->y = info.at(1).toElement().text().toFloat();
                            out->z = info.at(2).toElement().text().toFloat();
                            out->a = info.at(3).toElement().text().toFloat();
                            out->b = info.at(4).toElement().text().toFloat();
                            out->c = info.at(5).toElement().text().toFloat();
                            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
                            {
                                qDebug() << "read tool: x = " << out->x << "y = " << out->y << "z = " <<out->z
                                         << "a = " << out->a <<"b = " << out->b  << "c = " << out->c;
                            }
                        }
                        else
                        {
                            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
                            {
                                qDebug()<<"read tool: wrong tag number " << info.count();
                            }
                            return READ_TOOL_INFORMATION_FAILED;
                        }
                    }

                }
            }
            else
            {
                if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
                {
                    qDebug()<<"read Tool: there is no tag named" << toolName << "in the tool file";
                }
                return READ_TOOL_NO_TOOL_NAME;
            }
            return 0;
        }
        tool = tool.nextSibling();
    }
    return 0;
}
/*
    function: read port information of one xml line
    parameter: port is the xml information,
               out is the digital information
    return value: one of the enum CommandType value
                  or -1 means faild to read a valid command type
*/
int OperateProgramXml::readIOPort(QDomNode port,int *out)
{
    while(!port.toElement().isNull())
    {
        if(port.toElement().tagName() == XML_TAG_NAME_INPUTADDRESS
         ||port.toElement().tagName() == XML_TAG_NAME_DOADDRESS)
        {
            *out = port.toElement().text().toInt();

            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
            {
                qDebug()<<"read IO Port: read address = " << *out;
            }
            return 0;
        }
        port = port.nextSibling();
    }
    if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
    {
        qDebug()<<"read io port: port =  " << *out;
    }
    return FAILD_TO_READ_IO_PORT;
}
/*
    function: read output information of one xml line
    parameter: output is the xml information,
               out is the digital information
    return value: one of the enum CommandType value
                  or -1 means faild to read a valid command type
*/

int OperateProgramXml::readOutputValue(QDomNode output,DigitalValue *out)
{
    while(!output.toElement().isNull())
    {
        if(output.toElement().tagName() == XML_TAG_NAME_DOVALUE)
        {
            QString value = output.toElement().text();
            if(value == XML_TAG_NAME_IO_VALUE_ON)
            {
                *out = ON;
            }
            else if(value == XML_TAG_NAME_IO_VALUE_OFF)
            {
                *out = OFF;
            }
            else
            {
                *out = IO_NONE;
            }
            //*out = output.toElement().text().toInt();

            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
            {
                qDebug()<<"read byte number: read number = " << *out;
            }
            return 0;
        }
        output = output.nextSibling();
    }
    if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
    {
        qDebug()<<"read byte address: " << *out;
    }
    return FAILD_TO_READ_BYTE_ADDRESS;
}

/*
    function: read input information of one xml line
    parameter: input is the xml information,
               out is the digital information
    return value: one of the enum CommandType value
                  or -1 means faild to read a valid command type
*/
int OperateProgramXml::readByteNumber(QDomNode number,int *out)
{
    while(!number.toElement().isNull())
    {
        if(number.toElement().tagName() == XML_TAG_NAME_BYTENUMBER)
        {
            *out = number.toElement().text().toInt();

            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
            {
                qDebug()<<"read byte number: read number = " << *out;
            }
            return 0;
        }
        number = number.nextSibling();
    }
    if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
    {
        qDebug()<<"read byte address: " << *out;
    }
    return FAILD_TO_READ_BYTE_ADDRESS;
}
/*
    function: read file name from one xml line
    parameter: input is the xml information,
               out is the file name
    return value: one of the enum CommandType value
                  or -1 means faild to read a valid file name
*/
int OperateProgramXml::readFileName(QDomNode file,QString *out)
{
    while(!file.toElement().isNull())
    {
        if(file.toElement().tagName() == XML_TAG_NAME_FILENAME)
        {
            *out = file.toElement().text();

            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
            {
                qDebug()<<"read file name : read name = " << *out;
            }
            return 0;
        }
        file = file.nextSibling();
    }
    if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
    {
        qDebug()<<"read file name: " << *out;
    }
    return FAILD_TO_READ_FILE_NAME;
}


/*
    function: read label number from one xml line
    parameter: input is the xml information,
               out is the label number
    return value: one of the enum CommandType value
                  or -1 means faild to read a valid file name
*/
int OperateProgramXml::readLabelNumber(QDomNode label,int *out)
{
    while(!label.toElement().isNull())
    {
        if(label.toElement().tagName() == XML_TAG_NAME_NUMBER
         ||label.toElement().tagName() == XML_TAG_NAME_LABELNUMBER)
        {
            *out = label.toElement().text().toInt();

            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
            {
                qDebug()<<"read label number: read number = " << *out;
            }
            return 0;
        }
        label = label.nextSibling();
    }
    if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
    {
        qDebug()<<"read label address: " << *out;
    }
    return FAILD_TO_READ_LABEL_NUMBER;
}
int OperateProgramXml::readTime(QDomNode time,double *out)
{
    while(!time.toElement().isNull())
    {
        if(time.toElement().tagName() == XML_TAG_NAME_T)
        {
            *out = time.toElement().text().toDouble();

            if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_INFOR)
            {
                qDebug()<<"read time: read time = " << *out;
            }
            return 0;
        }
        time = time.nextSibling();
    }
    if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
    {
        qDebug()<<"read time : " << *out;
    }
    return FAILD_TO_READ_LABEL_NUMBER;
}



/*
    function: read the movj information from the xml line to ProgramXmlLine structure
    parameter: node: one line of xml
               line: out put
    return value: 0 means open the file correctly,
                  otherwise chech the opXmlErrorType.h for what happend.
*/

int OperateProgramXml::readMovj(QDomNode node,ProgramXmlLine *line)
{
    int ret=0;
    //node = node.firstChild();
    ret = readPosition(node,&line->p);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovj : faild to read Position ";
        }
        return ret;
    }
    ret = readVelocity(node,&line->vel);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovj : faild to read velocity ";
        }
        return ret;
    }

    ret = readAcc(node,&line->acc);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovj : faild to read acc ";
        }
        return ret;
    }
    ret = readPL(node,&line->pl);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovj : faild to read pl";
        }
        return ret;
    }
    ret = readNwait(node,&line->nwait);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovj : faild to read nwait";
        }
        return ret;
    }
    ret = readCondition(node,&line->condition);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovj : faild to read condition";
        }
        return ret;
    }
    return 0;
}

/*
    function: read the movl information from the xml line to ProgramXmlLine structure
    parameter: node: one line of xml
               line: out put
    return value: 0 means open the file correctly,
                  otherwise chech the opXmlErrorType.h for what happend.
*/

int OperateProgramXml::readMovl(QDomNode node,ProgramXmlLine *line)
{
    int ret=0;
    ret = readPosition(node,&line->p);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovL : faild to read Position ";
        }
        return ret;
    }
    ret = readVelocity(node,&line->vel);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovL : faild to read velocity ";
        }
        return ret;
    }

    ret = readAcc(node,&line->acc);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovL : faild to read acc ";
        }
        return ret;
    }
    ret = readPL(node,&line->pl);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovL : faild to read pl";
        }
        return ret;
    }
    ret = readNwait(node,&line->nwait);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovL : faild to read nwait";
        }
        return ret;
    }
    ret = readCondition(node,&line->condition);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovL : faild to read condition";
        }
        return ret;
    }
    ret = readUsrInformation(node,&line->usr);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovL : faild to read usr information";
        }
        return ret;
    }
    ret = readToolInformation(node,&line->tool);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovL : faild to read tool information";
        }
        return ret;
    }
    return 0;
}
/*
    function: read the movc information from the xml line to ProgramXmlLine structure
    parameter: node: one line of xml
               line: out put
    return value: 0 means open the file correctly,
                  otherwise chech the opXmlErrorType.h for what happend.
*/
int OperateProgramXml::readMovc(QDomNode node,ProgramXmlLine *line)
{
    int ret=0;
    ret = readPosition(node,&line->p);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovC : faild to read Position ";
        }
        return ret;
    }
    ret = readVelocity(node,&line->vel);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovC : faild to read velocity ";
        }
        return ret;
    }

    ret = readAcc(node,&line->acc);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovC : faild to read acc ";
        }
        return ret;
    }
    ret = readPL(node,&line->pl);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovC : faild to read pl";
        }
        return ret;
    }
    ret = readNwait(node,&line->nwait);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovC : faild to read nwait";
        }
        return ret;
    }
    ret = readCondition(node,&line->condition);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovC : faild to read condition";
        }
        return ret;
    }
    ret = readUsrInformation(node,&line->usr);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovC : faild to read usr information";
        }
        return ret;
    }
    ret = readToolInformation(node,&line->tool);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readMovC : faild to read tool information";
        }
        return ret;
    }
    return 0;

}
/*
    function: read the speed information from the xml line to ProgramXmlLine structure
    parameter: node: one line of xml
               line: out put
    return value: 0 means open the file correctly,
                  otherwise chech the opXmlErrorType.h for what happend.
*/
int OperateProgramXml::readSpeed(QDomNode node,ProgramXmlLine *line)
{
    int ret=0;
    ret = readVelocity(node,&line->vel);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readSpeed : faild to read velocity ";
        }
        return ret;
    }
    ret = readAcc(node,&line->acc);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class readSpeed : faild to read acc ";
        }
        return ret;
    }
    return 0;
}
/*
    function: read the dout information from the xml line to ProgramXmlLine structure
    parameter: node: one line of xml
               line: out put
    return value: 0 means open the file correctly,
                  otherwise chech the opXmlErrorType.h for what happend.
*/

int OperateProgramXml::readDout(QDomNode node,ProgramXmlLine *line)
{
    int ret=0;
    ret = readIOPort(node,&line->IoPort);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class Dout : faild to read IoPort ";
        }
        return ret;
    }
    ret = readOutputValue(node,&line->dOutValue);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class Dout : faild to read output value ";
        }
        return ret;
    }
    return 0;
}

/*
    function: read the din information from the xml line to ProgramXmlLine structure
    parameter: node: one line of xml
               line: out put
    return value: 0 means open the file correctly,
                  otherwise chech the opXmlErrorType.h for what happend.
*/

int OperateProgramXml::readDin(QDomNode node,ProgramXmlLine *line)
{
    int ret=0;
    ret = readIOPort(node,&line->IoPort);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class Din : faild to read IoPort ";
        }
        return ret;
    }
    ret = readByteNumber(node,&line->byteAddress);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class Din : faild to read address ";
        }
        return ret;
    }

    return 0;
}
/*
    function: read the Jump information from the xml line to ProgramXmlLine structure
    parameter: node: one line of xml
               line: out put
    return value: 0 means open the file correctly,
                  otherwise chech the opXmlErrorType.h for what happend.
*/

int OperateProgramXml::readJump(QDomNode node,ProgramXmlLine *line)
{
    int ret=0;
    ret = readLabelNumber(node,&line->lablel);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class Jump : faild to read label ";
        }
        return ret;
    }
    ret = readCondition(node,&line->condition);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class Jump : faild to read condition ";
        }
        return ret;
    }
    return 0;
}
/*
    function: read the label information from the xml line to ProgramXmlLine structure
    parameter: node: one line of xml
               line: out put
    return value: 0 means open the file correctly,
                  otherwise chech the opXmlErrorType.h for what happend.
*/

int OperateProgramXml::readLabel(QDomNode node,ProgramXmlLine *line)
{
    int ret=0;
    ret = readLabelNumber(node,&line->lablel);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class Label : faild to read label ";
        }
        return ret;
    }
    return 0;
}

/*
    function: read the pause information from the xml line to ProgramXmlLine structure
    parameter: node: one line of xml
               line: out put
    return value: 0 means open the file correctly,
                  otherwise chech the opXmlErrorType.h for what happend.
*/
int OperateProgramXml::readPause(QDomNode node,ProgramXmlLine *line)
{
    int ret=0;
    ret = readCondition(node,&line->condition);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class Pause : faild to read condition ";
        }
        return ret;
    }
    return 0;
}

/*
    function: read the timer information from the xml line to ProgramXmlLine structure
    parameter: node: one line of xml
               line: out put
    return value: 0 means open the file correctly,
                  otherwise chech the opXmlErrorType.h for what happend.
*/
int OperateProgramXml::readTimer(QDomNode node,ProgramXmlLine *line)
{
    int ret =0 ;
    ret = readTime(node,&line->time);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class Timer : faild to read time ";
        }
        return ret;
    }
    return 0;
}

/*
    function: read the call subfile information from the xml line to ProgramXmlLine structure
    parameter: node: one line of xml
               line: out put
    return value: 0 means open the file correctly,
                  otherwise chech the opXmlErrorType.h for what happend.
*/
int OperateProgramXml::readCall(QDomNode node,ProgramXmlLine *line)
{
    int ret =0;
    ret = readFileName(node,&line->fileName);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class Call : faild to fileName ";
        }
        return ret;
    }
    ret = readCondition(node,&line->condition);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class Call : faild to condition ";
        }
        return ret;
    }
    return 0;
}


/*
    function: read the return information from the xml line to ProgramXmlLine structure
    parameter: node: one line of xml
               line: out put
    return value: 0 means open the file correctly,
                  otherwise chech the opXmlErrorType.h for what happend.
*/
int OperateProgramXml::readRet(QDomNode node,ProgramXmlLine *line)
{
    int ret =0;
    ret = readCondition(node,&line->condition);
    if(ret)
    {
        if(OP_PROGRAM_DEBUG&OP_PROGRAM_DEBUG_ERROR)
        {
            qDebug() << "operate xml class Ret : faild to condition ";
        }
        return 0;
    }
    return 0;
}

int OperateProgramXml::readNOP(QDomNode node,ProgramXmlLine *line)
{
    return 0;
}
int OperateProgramXml::readEND(QDomNode node,ProgramXmlLine *line)
{
    return 0;
}

ProgramXmlLine OperateProgramXml::getLine()
{
    return line;
}
