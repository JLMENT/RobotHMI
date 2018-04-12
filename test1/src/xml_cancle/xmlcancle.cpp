#include "xmlcancle.h"

XmlCancle::XmlCancle(QObject *parent) : QObject(parent)
{

}
//创建XML程序文件
void XmlCancle::create_xml_file(QString filename)
{
    QFile file(filename+".xml");
    //if(!file.open(QFile::WriteOnly|QFile::Truncate))
    if(!file.open(QFile::WriteOnly))
        return;
    QDomDocument doc;
    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);

    QDomElement root = doc.createElement("commendlist");
    doc.appendChild(root);

    QDomElement nop = doc.createElement("NOP");
    QDomText text;
    text = doc.createTextNode("NOP");
    root.appendChild(nop);
    nop.appendChild(text);

    QDomElement end = doc.createElement("END");
    text = doc.createTextNode("END");
    root.appendChild(end);
    end.appendChild(text);

    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

//create xml_subfile()
void XmlCancle::create_xml_subfile(QString filename)
{
    QFile file(filename+".xml");
    //if(!file.open(QFile::WriteOnly|QFile::Truncate))
    if(!file.open(QFile::WriteOnly))
        return;
    QDomDocument doc;
    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);

    QDomElement root = doc.createElement("commendlist");
    doc.appendChild(root);

    QDomElement nop = doc.createElement("NOP");
    QDomText text;
    text = doc.createTextNode("NOP");
    root.appendChild(nop);
    nop.appendChild(text);

    QDomElement end = doc.createElement("RET");
    text = doc.createTextNode("RET");
    root.appendChild(end);
    end.appendChild(text);

    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

//创建XML程序文件对应的位置文件
void XmlCancle::create_xml_position_file(QString filename)
{
    QString position_xml_file_name = filename+"_position.xml";
    QFile file(position_xml_file_name);
    //if(!file.open(QFile::WriteOnly|QFile::Truncate))
    if(!file.open(QFile::WriteOnly))
        return;
    QDomDocument doc;
    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);

    QDomElement root = doc.createElement("position");
    doc.appendChild(root);

    /*QDomElement nop = doc.createElement("NOP");
    QDomText text;
    text = doc.createTextNode("NOP");
    root.appendChild(nop);
    nop.appendChild(text);

    QDomElement end = doc.createElement("END");
    text = doc.createTextNode("END");
    root.appendChild(end);
    end.appendChild(text);*/

    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}


//正常输入命令
void XmlCancle::input_MOVJ_command(MovjCommand movjc, QString filename)
{
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    qDebug()<<"open success";
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QString vjvalue;
    QString plvalue;
   // bool until;
    QString untistring;
    QString iocombo;
    QString iolineedit;
    QString preparevalue;
    QString valueedit;
    QString digitcombo;
    QString accvalue;
    QString decvalue;
   // bool nwaitcheck;
    QString nwaitstring;
    QString posvalue;

    vjvalue = movjc.buf[1];
    plvalue = movjc.buf[2];


    untistring = movjc.buf[3];
    iocombo = movjc.buf[4];
    iolineedit = movjc.buf[5];
    preparevalue = movjc.buf[6];
    valueedit = movjc.buf[7];
    digitcombo = movjc.buf[8];
    accvalue = movjc.buf[9];
    decvalue = movjc.buf[10];

    //nwaitcheck = movjc.buf[12];
    nwaitstring = movjc.buf[11];

    posvalue = movjc.buf[0];

    QDomElement root = doc.documentElement();
    QDomElement movj = doc.createElement("movj");
    QDomElement position = doc.createElement("positon");
    QDomText text;
    text = doc.createTextNode(posvalue);
    position.appendChild(text);
    movj.appendChild(position);

    QDomElement vj = doc.createElement("vj");
    text = doc.createTextNode(vjvalue);
    vj.appendChild(text);
    movj.appendChild(vj);

    QDomElement pl = doc.createElement("pl");
    text = doc.createTextNode(plvalue);
    pl.appendChild(text);
    movj.appendChild(pl);

    QDomElement untill = doc.createElement("untill");
    text = doc.createTextNode(untistring);
    untill.appendChild(text);
    movj.appendChild(untill);

    QDomElement ioselect = doc.createElement("ioselect");
    text = doc.createTextNode(iocombo);
    ioselect.appendChild(text);
    movj.appendChild(ioselect);

    QDomElement ionumber = doc.createElement("ionumber");
    text = doc.createTextNode(iolineedit);
    ionumber.appendChild(text);
    movj.appendChild(ionumber);

    QDomElement ioprepare = doc.createElement("ioprepare");
    text = doc.createTextNode(preparevalue);
    ioprepare.appendChild(text);
    movj.appendChild(ioprepare);

    QDomElement iovalue = doc.createElement("iovalue");
    text = doc.createTextNode(valueedit);
    iovalue.appendChild(text);
    movj.appendChild(iovalue);

    QDomElement ioio = doc.createElement("ioio");
    text = doc.createTextNode(digitcombo);
    ioio.appendChild(text);
    movj.appendChild(ioio);

    QDomElement acc = doc.createElement("acc");
    text = doc.createTextNode(accvalue);
    acc.appendChild(text);
    movj.appendChild(acc);

    QDomElement dec = doc.createElement("dec");
    text = doc.createTextNode(decvalue);
    dec.appendChild(text);
    movj.appendChild(dec);

    QDomElement nwait = doc.createElement("nwait");
    text = doc.createTextNode(nwaitstring);
    nwait.appendChild(text);
    movj.appendChild(nwait);

    //root.appendChild(movj);


    //QDomElement root = doc.documentElement();
    QDomNode node = root.firstChild();
    //QString linestring = ui->addlineEdit->text();
    //int linenumber = linestring.toInt();
    //for(int j=0;j<linenumber;j++)
    while(!node.isNull())
    {
        node = node.nextSibling();
        if(node.toElement().tagName() == "END"||node.toElement().tagName() == "RET")
        {
            break;
        }

    }

    //root.removeChild(node);
    root.insertBefore(movj,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();

}

void XmlCancle::input_MOVL_command(MovlCommand movlc, QString filename)
{
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    QDomElement movl = doc.createElement("movl");
    QDomElement position = doc.createElement("positon");
    QDomText text;
    text = doc.createTextNode(movlc.buf[0]);
    position.appendChild(text);
    movl.appendChild(position);

    QDomElement vl = doc.createElement("vl");
    text = doc.createTextNode(movlc.buf[1]);
    vl.appendChild(text);
    movl.appendChild(vl);

    QDomElement vr = doc.createElement("vr");
    text = doc.createTextNode(movlc.buf[2]);
    vr.appendChild(text);
    movl.appendChild(vr);

    QDomElement pl = doc.createElement("pl");
    text = doc.createTextNode(movlc.buf[3]);
    pl.appendChild(text);
    movl.appendChild(pl);

    QDomElement untill = doc.createElement("untill");
    text = doc.createTextNode(movlc.buf[4]);
    untill.appendChild(text);
    movl.appendChild(untill);

    QDomElement ioselect = doc.createElement("ioselect");
    text = doc.createTextNode(movlc.buf[5]);
    ioselect.appendChild(text);
    movl.appendChild(ioselect);

    QDomElement ionumber = doc.createElement("ionumber");
    text = doc.createTextNode(movlc.buf[6]);
    ionumber.appendChild(text);
    movl.appendChild(ionumber);

    QDomElement ioprepare = doc.createElement("ioprepare");
    text = doc.createTextNode(movlc.buf[7]);
    ioprepare.appendChild(text);
    movl.appendChild(ioprepare);

    QDomElement iovalue = doc.createElement("iovalue");
    text = doc.createTextNode(movlc.buf[8]);
    iovalue.appendChild(text);
    movl.appendChild(iovalue);

    QDomElement ioio = doc.createElement("ioio");
    text = doc.createTextNode(movlc.buf[9]);
    ioio.appendChild(text);
    movl.appendChild(ioio);

    QDomElement acc = doc.createElement("acc");
    text = doc.createTextNode(movlc.buf[10]);
    acc.appendChild(text);
    movl.appendChild(acc);

    QDomElement dec = doc.createElement("dec");
    text = doc.createTextNode(movlc.buf[11]);
    dec.appendChild(text);
    movl.appendChild(dec);

    QDomElement cr = doc.createElement("cr");
    text = doc.createTextNode(movlc.buf[12]);
    cr.appendChild(text);
    movl.appendChild(cr);

    QDomElement nwait = doc.createElement("nwait");
    text = doc.createTextNode(movlc.buf[13]);
    nwait.appendChild(text);
    movl.appendChild(nwait);

    QDomElement usr = doc.createElement("usr");
    text = doc.createTextNode(movlc.buf[14]);
    usr.appendChild(text);
    movl.appendChild(usr);

    QDomElement usrvalue = doc.createElement("usrvalue");
    text = doc.createTextNode(movlc.buf[15]);
    usrvalue.appendChild(text);
    movl.appendChild(usrvalue);

    QDomElement tool = doc.createElement("tool");
    text = doc.createTextNode(movlc.buf[16]);
    tool.appendChild(text);
    movl.appendChild(tool);

    QDomElement toolvalue = doc.createElement("toolvalue");
    text = doc.createTextNode(movlc.buf[17]);
    toolvalue.appendChild(text);
    movl.appendChild(toolvalue);

    QDomNode node = root.lastChild();
    root.insertBefore(movl,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCancle::input_MOVC_command(MovcCommand movcc,QString filename)
{
    QString string_movc_buf[18]={"positon","vl","vr","pl","untill","ioselect","ionumber","ioprepare","iovalue","ioio","acc","dec","cr","nwait","usr","usrvalue","tool","toolvalue"};

    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement movc = doc.createElement("movc");
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<18;i++)
    {
        element_string = doc.createElement(string_movc_buf[i]);
        text = doc.createTextNode(movcc.buf[i]);
        element_string.appendChild(text);
        movc.appendChild(element_string);
    }

    QDomNode node = root.lastChild();
    root.insertBefore(movc,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();

}

void XmlCancle::input_speed_command(SpeedCommand speedc,QString filename)
{
    QString string_speed_buf[3]={"vstyle","value","acc"};
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement speed = doc.createElement("speed");
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<3;i++)
    {
        element_string = doc.createElement(string_speed_buf[i]);
        text = doc.createTextNode(speedc.buf[i]);
        element_string.appendChild(text);
        speed.appendChild(element_string);
    }

    QDomNode node = root.lastChild();
    root.insertBefore(speed,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

//input dout
void XmlCancle::input_DOUT_command(DoutCommand doutc,QString filename)
{
    QString string_dout[2] = {"doAddress","doValue"};
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement dout = doc.createElement("DOUT");
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<2;i++)
    {
        element_string = doc.createElement(string_dout[i]);
        text = doc.createTextNode(doutc.buf[i]);
        element_string.appendChild(text);
        dout.appendChild(element_string);
    }

    QDomNode node = root.lastChild();
    root.insertBefore(dout,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();

}
//input din command
void XmlCancle::input_DIN_command(DinCommand dinc,QString filename)
{
    QString string_din[2] = {"byteNumber","inputAddress"};
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement din = doc.createElement("DIN");
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<2;i++)
    {
        element_string = doc.createElement(string_din[i]);
        text = doc.createTextNode(dinc.buf[i]);
        element_string.appendChild(text);
        din.appendChild(element_string);
    }

    QDomNode node = root.lastChild();
    root.insertBefore(din,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCancle::input_PAUSE_command(PauseCommand pausec, QString filename)
{
    QString string_pause[5] = {"IF","varType","varAddress","compareSign","compareValue"};
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement pause = doc.createElement("PAUSE");
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<5;i++)
    {
        element_string = doc.createElement(string_pause[i]);
        text = doc.createTextNode(pausec.buf[i]);
        element_string.appendChild(text);
        pause.appendChild(element_string);
    }

    QDomNode node = root.lastChild();
    root.insertBefore(pause,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCancle::input_TIMER_command(QString timec, QString filename)
{
    QString string_time = "T";
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement time = doc.createElement("TIMER");
    QDomText text;
    QDomElement element_string;

        element_string = doc.createElement(string_time);
        text = doc.createTextNode(timec);
        element_string.appendChild(text);
        time.appendChild(element_string);

    QDomNode node = root.lastChild();
    root.insertBefore(time,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();

}

void XmlCancle::input_JUMP_command(JumpCommand jumpc, QString filename)
{
    QString string_jump[6] = {"LabelNumber","IF","varType","varAddress","compareSign","compareValue"};
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement jump = doc.createElement("JUMP");
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<6;i++)
    {
        element_string = doc.createElement(string_jump[i]);
        text = doc.createTextNode(jumpc.buf[i]);
        element_string.appendChild(text);
        jump.appendChild(element_string);
    }

    QDomNode node = root.lastChild();
    root.insertBefore(jump,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCancle::input_LABEL_command(QString labelc, QString filename)
{
    QString string_label = "number";
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement label = doc.createElement("LABEL");
    QDomText text;
    QDomElement element_string;

        element_string = doc.createElement(string_label);
        text = doc.createTextNode(labelc);
        element_string.appendChild(text);
        label.appendChild(element_string);

    QDomNode node = root.lastChild();
    root.insertBefore(label,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCancle::input_CALL_command(CallCommand callc, QString filename)
{
    QString string_call[6] = {"fileName","IF","varType","varAddress","compareSign","compareValue"};
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement call = doc.createElement("CALL");
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<6;i++)
    {
        element_string = doc.createElement(string_call[i]);
        text = doc.createTextNode(callc1.buf[i]);
        element_string.appendChild(text);
        call.appendChild(element_string);
    }

    QDomNode node = root.lastChild();
    root.insertBefore(call,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCancle::input_RET_command(RetCommand retc, QString filename)
{
    QString string_ret[5] = {"IF","varType","varAddress","compareSign","compareValue"};
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement ret = doc.createElement("RET");
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<5;i++)
    {
        element_string = doc.createElement(string_ret[i]);
        text = doc.createTextNode(retc.buf[i]);
        element_string.appendChild(text);
        ret.appendChild(element_string);
    }

    QDomNode node = root.lastChild();
    root.insertBefore(ret,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}


//插入命令
void XmlCancle::insert_MOVJ_command(MovjCommand movjc,QString filename,int index)
{
    QString string_movl_buf[12]={"postion","vj","pl","untill","ioselect","ionumber","ioprepare","iovalue","ioio","acc","dec","nwait"};
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    QDomElement movj = doc.createElement("movj");
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<12;i++)
    {
        element_string = doc.createElement(string_movl_buf[i]);
        text = doc.createTextNode(movjc.buf[i]);
        element_string.appendChild(text);
        movj.appendChild(element_string);
    }

    QDomNode node = root.firstChild();

    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }

    //root.removeChild(node);
    root.insertBefore(movj,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}
//插入movl命令
void XmlCancle::insert_MOVL_command(MovlCommand movlc,QString filename,int index)
{
    QString string_movl_buf[18]={"postion","vl","vr","pl","untill","ioselect","ionumber","ioprepare","iovalue","ioio","acc","dec","cr","nwait","usr","usrvalue","tool","toolvalue"};

    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement movl = doc.createElement("movl");
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<18;i++)
    {
        element_string = doc.createElement(string_movl_buf[i]);
        text = doc.createTextNode(movlc.buf[i]);
        element_string.appendChild(text);
        movl.appendChild(element_string);
    }

    QDomNode node = root.firstChild();
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    root.insertBefore(movl,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}
//moc插入命令
void XmlCancle::insert_MOVC_command(MovcCommand movcc,QString filename,int index)
{
    QString string_movc_buf[18]={"postion","vl","vr","pl","untill","ioselect","ionumber","ioprepare","iovalue","ioio","acc","dec","cr","nwait","usr","usrvalue","tool","toolvalue"};

    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement movc = doc.createElement("movc");
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<18;i++)
    {
        element_string = doc.createElement(string_movc_buf[i]);
        text = doc.createTextNode(movcc.buf[i]);
        element_string.appendChild(text);
        movc.appendChild(element_string);
    }

    QDomNode node = root.firstChild();
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    root.insertBefore(movc,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}
//插入speed命令
void XmlCancle::insert_speed_command(SpeedCommand speedc,QString filename,int index)
{
    QString string_speed_buf[3]={"vstyle","value","acc"};
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement speed = doc.createElement("speed");
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<3;i++)
    {
        element_string = doc.createElement(string_speed_buf[i]);
        text = doc.createTextNode(speedc.buf[i]);
        element_string.appendChild(text);
        speed.appendChild(element_string);
    }

    QDomNode node = root.firstChild();
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    root.insertBefore(speed,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

//insert DOUT command
void XmlCancle::insert_DOUT_command(DoutCommand doutc, QString filename, int index)
{
    QString string_dout[2] = {"doAddress","doValue"};
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement dout = doc.createElement("DOUT");
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<2;i++)
    {
        element_string = doc.createElement(string_dout[i]);
        text = doc.createTextNode(doutc.buf[i]);
        element_string.appendChild(text);
        dout.appendChild(element_string);
    }

    QDomNode node = root.firstChild();
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    root.insertBefore(dout,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}
//insert DIN command
void XmlCancle::insert_DIN_command(DinCommand dinc, QString filename, int index)
{
    QString string_din[2] = {"byteNumber","inputAddress"};
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement din = doc.createElement("DIN");
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<2;i++)
    {
        element_string = doc.createElement(string_din[i]);
        text = doc.createTextNode(dinc.buf[i]);
        element_string.appendChild(text);
        din.appendChild(element_string);
    }

    QDomNode node = root.firstChild();
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    root.insertBefore(din,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCancle::insert_PAUSE_command(PauseCommand pausec,QString filename,int index)
{
    QString string_pause[5] = {"IF","varType","varAddress","compareSign","compareValue"};
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement pause = doc.createElement("PAUSE");
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<5;i++)
    {
        element_string = doc.createElement(string_pause[i]);
        text = doc.createTextNode(pausec.buf[i]);
        element_string.appendChild(text);
        pause.appendChild(element_string);
    }
    QDomNode node = root.firstChild();
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    root.insertBefore(pause,node);
    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCancle::insert_TIMER_command(QString timec, QString filename,int index)
{
    QString string_time = "T";
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement time = doc.createElement("TIMER");
    QDomText text;
    QDomElement element_string;

        element_string = doc.createElement(string_time);
        text = doc.createTextNode(timec);
        element_string.appendChild(text);
        time.appendChild(element_string);

        QDomNode node = root.firstChild();
        for(int j=0;j<index;j++)
        {
            node = node.nextSibling();
        }
        root.insertBefore(time,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();

}

void XmlCancle::insert_JUMP_command(JumpCommand jumpc, QString filename,int index)
{
    QString string_jump[6] = {"LabelNumber","IF","varType","varAddress","compareSign","compareValue"};
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement jump = doc.createElement("PAUSE");
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<6;i++)
    {
        element_string = doc.createElement(string_jump[i]);
        text = doc.createTextNode(jumpc.buf[i]);
        element_string.appendChild(text);
        jump.appendChild(element_string);
    }

    QDomNode node = root.firstChild();
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    root.insertBefore(jump,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCancle::insert_LABEL_command(QString labelc, QString filename,int index)
{
    QString string_label = "number";
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement label = doc.createElement("LABEL");
    QDomText text;
    QDomElement element_string;

        element_string = doc.createElement(string_label);
        text = doc.createTextNode(labelc);
        element_string.appendChild(text);
        label.appendChild(element_string);

        QDomNode node = root.firstChild();
        for(int j=0;j<index;j++)
        {
            node = node.nextSibling();
        }
        root.insertBefore(label,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCancle::insert_CALL_command(CallCommand callc, QString filename,int index)
{
    QString string_call[6] = {"fileName","IF","varType","varAddress","compareSign","compareValue"};
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement call = doc.createElement("CALL");
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<6;i++)
    {
        element_string = doc.createElement(string_call[i]);
        text = doc.createTextNode(callc1.buf[i]);
        element_string.appendChild(text);
        call.appendChild(element_string);
    }

    QDomNode node = root.firstChild();
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    root.insertBefore(call,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCancle::insert_RET_command(RetCommand retc, QString filename,int index)
{
    QString string_ret[5] = {"IF","varType","varAddress","compareSign","compareValue"};
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomElement ret = doc.createElement("RET");
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<5;i++)
    {
        element_string = doc.createElement(string_ret[i]);
        text = doc.createTextNode(retc.buf[i]);
        element_string.appendChild(text);
        ret.appendChild(element_string);
    }

    QDomNode node = root.firstChild();
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    root.insertBefore(ret,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}


//删除命令(接口参数为光标位置行的值)（要加判断不能是首行和末行的值）
void XmlCancle::delete_command(QString filename,int index)
{
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();

    QDomNode node = root.firstChild();
    qDebug()<<node.nodeName()<<":"<<node.toElement().text();


    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
        qDebug()<<node.nodeName()<<":"<<node.toElement().text();
    }

    root.removeChild(node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
    /*QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))//完成xml文档的设置
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    QDomNode node = root.firstChild();
    int node_total_number;

    while(!node.isNull())
    {
        node = node.nextSibling();
        ++node_total_number;

    }
    qDebug()<<node_total_number;
    qDebug("delete success");
    if(index==node_total_number)
    {
        qDebug()<<"endnode delete failure!";
    }else{



            for(int j=0;j<index;j++)
            {
                node = node.nextSibling();

            }

            root.removeChild(node);

            if(!file.open(QFile::WriteOnly|QFile::Truncate))
                return;
            QTextStream out_stream(&file);
            doc.save(out_stream,4);
            file.close();
         }*/
}

//修改查看是什么命令
void XmlCancle::get_command_style(QString filename,int index)
{
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    qDebug()<<root.nodeName();
    QDomNode node = root.firstChild();
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    QDomElement e = node.toElement();
    select_input_command = e.tagName();
    qDebug()<<"select command style is"<<select_input_command;


}

//修改-获取信息-调用相应的命令显示窗口(获的的命令保存到相应的命令结构中)
void XmlCancle::get_MOVJ(MovjCommand movjc,QString filename,int index)
{

    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    //qDebug()<<root.nodeName();
    QDomNode node = root.firstChild();
    /*if(node = "movj")
        显示movj界面调用movj填值函数
        其它界面相同*/

    //while(!node.isNull())
    //{
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    //指定第几个元素，接下来对指定的元素下的子元素值进行提取
        if(node.isElement()&(!node.isNull()))
        {
            QDomElement e = node.toElement();
            //qDebug()<<e.tagName()<<" "<<e.attribute("id")<<" "<<e.attribute("time");
            QDomNodeList list = e.childNodes(); //The QDomNodeList class is a list of QDomNode objects
            //将Node下的子元素转化为节点列表。
            for(int i=0;i<list.count();i++)
            {
                QDomNode n = list.at(i);
                if(node.isElement())
                {
                    movjc.buf[i]=n.toElement().text();
                    //qDebug()<<movjc.buf[i];
                    movjc2.buf[i]=movjc.buf[i];

                }
            }
        }
}
//获取光标位置处的命令信息MOVL
void XmlCancle::get_MOVL(MovlCommand movlc,QString filename,int index)
{
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    qDebug()<<root.nodeName();
    QDomNode node = root.firstChild();
    /*if(node = "movj")
        显示movj界面调用movj填值函数
        其它界面相同*/

    //while(!node.isNull())
    //{

    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    //指定第几个元素，接下来对指定的元素下的子元素值进行提取
        if(node.isElement()&(!node.isNull()))
        {
            QDomElement e = node.toElement();
            //qDebug()<<e.tagName()<<" "<<e.attribute("id")<<" "<<e.attribute("time");
            QDomNodeList list = e.childNodes(); //The QDomNodeList class is a list of QDomNode objects
            //将Node下的子元素转化为节点列表。
            for(int i=0;i<list.count();i++)
            {
                QDomNode n = list.at(i);
                if(node.isElement())
                {
                    //movlc.buf[i]=n.toElement().text();
                    movlc2.buf[i] = n.toElement().text();
                }
            }
        }
}
//获取光标位置处的命令信息MOVC
void XmlCancle::get_MOVC(MovcCommand movcc,QString filename,int index)
{
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    qDebug()<<root.nodeName();
    QDomNode node = root.firstChild();
    /*if(node = "movj")
        显示movj界面调用movj填值函数
        其它界面相同*/

    //while(!node.isNull())
    //

    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    //指定第几个元素，接下来对指定的元素下的子元素值进行提取
        if(node.isElement()&(!node.isNull()))
        {
            QDomElement e = node.toElement();
            //qDebug()<<e.tagName()<<" "<<e.attribute("id")<<" "<<e.attribute("time");
            QDomNodeList list = e.childNodes(); //The QDomNodeList class is a list of QDomNode objects
            //将Node下的子元素转化为节点列表。
            for(int i=0;i<list.count();i++)
            {
                QDomNode n = list.at(i);
                if(node.isElement())
                {
                    //movcc.buf[i]=n.toElement().text();
                    movcc2.buf[i] = n.toElement().text();

                }
            }
        }
}
//获取光标位置处的命令信息speed
void XmlCancle::get_speed(SpeedCommand speed,QString filename,int index)
{
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    qDebug()<<root.nodeName();
    QDomNode node = root.firstChild();
    /*if(node = "movj")
        显示movj界面调用movj填值函数
        其它界面相同*/

    //while(!node.isNull())
    //

    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    //指定第几个元素，接下来对指定的元素下的子元素值进行提取
        if(node.isElement()&(!node.isNull()))
        {
            QDomElement e = node.toElement();
            //qDebug()<<e.tagName()<<" "<<e.attribute("id")<<" "<<e.attribute("time");
            QDomNodeList list = e.childNodes(); //The QDomNodeList class is a list of QDomNode objects
            //将Node下的子元素转化为节点列表。
            for(int i=0;i<list.count();i++)
            {
                QDomNode n = list.at(i);
                if(node.isElement())
                {
                    //speed.buf[i]=n.toElement().text();
                    speedc2.buf[i] = n.toElement().text();

                }
            }
         }
}

//require DOUT information
void XmlCancle::get_DOUT(DoutCommand dout, QString filename, int index)
{
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    qDebug()<<root.nodeName();
    QDomNode node = root.firstChild();
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    if(node.isElement()&(!node.isNull()))
    {
        QDomElement e = node.toElement();
        QDomNodeList list = e.childNodes();
        for(int i=0;i<list.count();i++)
        {
            QDomNode n = list.at(i);
            if(node.isElement())
            {
                doutc2.buf[i] = n.toElement().text();

            }
        }
     }
}
//get DIN COMMAND
void XmlCancle::get_DIN(DinCommand dinc,QString filename,int index)
{
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    qDebug()<<root.nodeName();
    QDomNode node = root.firstChild();
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    if(node.isElement()&(!node.isNull()))
    {
        QDomElement e = node.toElement();
        QDomNodeList list = e.childNodes();
        for(int i=0;i<list.count();i++)
        {
            QDomNode n = list.at(i);
            if(node.isElement())
            {
                dinc2.buf[i] = n.toElement().text();
            }
        }
     }
}

void XmlCancle::get_PAUSE_command(PauseCommand pausec,QString filename,int index)
{
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    qDebug()<<root.nodeName();
    QDomNode node = root.firstChild();
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    if(node.isElement()&(!node.isNull()))
    {
        QDomElement e = node.toElement();
        QDomNodeList list = e.childNodes();
        for(int i=0;i<list.count();i++)
        {
            QDomNode n = list.at(i);
            if(node.isElement())
            {
                pausec2.buf[i] = n.toElement().text();
            }
        }
     }
}

void XmlCancle::get_TIMER_command(QString timec,QString filename,int index)
{
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    qDebug()<<root.nodeName();
    QDomNode node = root.firstChild();
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    if(node.isElement()&(!node.isNull()))
    {
        QDomElement e = node.toElement();
        QDomNodeList list = e.childNodes();
        for(int i=0;i<list.count();i++)
        {
            QDomNode n = list.at(i);
            if(node.isElement())
            {
                timec2 = n.toElement().text();
            }
        }
     }
}

void XmlCancle::get_JUMP_command(JumpCommand jumpc,QString filename,int index)
{
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    qDebug()<<root.nodeName();
    QDomNode node = root.firstChild();
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    if(node.isElement()&(!node.isNull()))
    {
        QDomElement e = node.toElement();
        QDomNodeList list = e.childNodes();
        for(int i=0;i<list.count();i++)
        {
            QDomNode n = list.at(i);
            if(node.isElement())
            {
                jumpc2.buf[i] = n.toElement().text();
            }
        }
     }
}

void XmlCancle::get_LABEL_command(QString labelc,QString filename,int index)
{
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    qDebug()<<root.nodeName();
    QDomNode node = root.firstChild();
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    if(node.isElement()&(!node.isNull()))
    {
        QDomElement e = node.toElement();
        QDomNodeList list = e.childNodes();
        for(int i=0;i<list.count();i++)
        {
            QDomNode n = list.at(i);
            if(node.isElement())
            {
                LabelCommand2 = n.toElement().text();
            }
        }
     }
}

void XmlCancle::get_CALL_command(CallCommand callc,QString filename,int index)
{
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    qDebug()<<root.nodeName();
    QDomNode node = root.firstChild();
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    if(node.isElement()&(!node.isNull()))
    {
        QDomElement e = node.toElement();
        QDomNodeList list = e.childNodes();
        for(int i=0;i<list.count();i++)
        {
            QDomNode n = list.at(i);
            if(node.isElement())
            {
                callc2.buf[i] = n.toElement().text();
            }
        }
     }
}

void XmlCancle::get_RET_command(RetCommand retc,QString filename,int index)
{
    QFile file(filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    qDebug()<<root.nodeName();
    QDomNode node = root.firstChild();
    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    if(node.isElement()&(!node.isNull()))
    {
        QDomElement e = node.toElement();
        QDomNodeList list = e.childNodes();
        for(int i=0;i<list.count();i++)
        {
            QDomNode n = list.at(i);
            if(node.isElement())
            {
                retc2.buf[i] = n.toElement().text();
            }
        }
     }
}

//将修改好的数据填到对应的xml文件中
void XmlCancle::modify_MOVJ(MovjCommand movjc,QString filename,int index)
{
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomNode node = root.firstChild();
    /*if(node = "movj")
        显示movj界面调用movj填值函数
        其它界面相同*/

    //while(!node.isNull())
    //{

    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    if(node.isElement()&(!node.isNull()))
    {
        QDomElement e = node.toElement();
        QDomNodeList list = e.childNodes();
        for(int i=0;i<list.count();i++)
        {
            QDomNode n = list.at(i);

            QDomNode oldnode;
           QDomNode newnode;

            if(node.isElement())
            {

                oldnode = n.firstChild();

                n.firstChild().setNodeValue(movjc.buf[i]);

                newnode = n.firstChild();

                n.replaceChild(newnode,oldnode);

                /*
                if(i==0)
                {
                    //posvalue
                    //QDomNode
                    oldnode = n.firstChild();
                    qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                    n.firstChild().setNodeValue(posvalue);
                    qDebug()<<posvalue;
                    //QDomNode
                    qDebug("replace1");
                    newnode = n.firstChild();
                    qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                    n.replaceChild(newnode,oldnode);
                }
                else if(i==1)
                {
                    qDebug("replace2");
                    oldnode = n.firstChild();
                    qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                    n.firstChild().setNodeValue(vjvalue);
                    qDebug()<<vjvalue;
                    //QDomNode
                    qDebug("replace3");
                    newnode = n.firstChild();
                    qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                    n.replaceChild(newnode,oldnode);
                }
                else if(i==2)
                {
                    qDebug("replace2");
                    oldnode = n.firstChild();
                    qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                    n.firstChild().setNodeValue(plvalue);
                    qDebug()<<plvalue;
                    //QDomNode
                    qDebug("replace3");
                    newnode = n.firstChild();
                    qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                    n.replaceChild(newnode,oldnode);
                }
                else if(i==3)
                {
                    qDebug("replace2");
                    oldnode = n.firstChild();
                    qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                    n.firstChild().setNodeValue(untistring);
                    qDebug()<<untistring;
                    //QDomNode
                    qDebug("replace3");
                    newnode = n.firstChild();
                    qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                    n.replaceChild(newnode,oldnode);
                }
                else if(i==4)
                {
                    qDebug("replace2");
                    oldnode = n.firstChild();
                    qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                    n.firstChild().setNodeValue(iocombo);
                    qDebug()<<iocombo;
                    //QDomNode
                    qDebug("replace3");
                    newnode = n.firstChild();
                    qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                    n.replaceChild(newnode,oldnode);
                }
                else if(i==5)
                {
                    qDebug("replace2");
                    oldnode = n.firstChild();
                    qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                    n.firstChild().setNodeValue(iolineedit);
                    qDebug()<<untistring;
                    //QDomNode
                    qDebug("replace3");
                    newnode = n.firstChild();
                    qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                    n.replaceChild(newnode,oldnode);
                }
                 else if(i==6)
                 {
                     qDebug("replace2");
                     oldnode = n.firstChild();
                     n.firstChild().setNodeValue(preparevalue);
                     newnode = n.firstChild();
                     n.replaceChild(newnode,oldnode);
                 }
                 else if(i==7)
                 {
                     qDebug("replace2");
                     oldnode = n.firstChild();
                     qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                     n.firstChild().setNodeValue(valueedit);
                     qDebug()<<untistring;
                     //QDomNode
                     qDebug("replace3");
                     newnode = n.firstChild();
                     qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                     n.replaceChild(newnode,oldnode);
                 }
                 else if(i==8)
                 {
                     qDebug("replace2");
                     oldnode = n.firstChild();
                     qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                     n.firstChild().setNodeValue(digitcombo);
                    qDebug("replace3");
                    newnode = n.firstChild();
                    qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                    n.replaceChild(newnode,oldnode);
                }
                 else if(i==9)
                 {
                     qDebug("replace2");
                     oldnode = n.firstChild();
                     qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                     n.firstChild().setNodeValue(accvalue);
                     qDebug()<<iocombo;
                     //QDomNode
                     qDebug("replace3");
                     newnode = n.firstChild();
                     qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                     n.replaceChild(newnode,oldnode);
                 }
                 else if(i==10)
                 {
                     qDebug("replace2");
                     oldnode = n.firstChild();
                     qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                     n.firstChild().setNodeValue(decvalue);
                     qDebug()<<untistring;
                     //QDomNode
                     qDebug("replace3");
                     newnode = n.firstChild();
                     qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                     n.replaceChild(newnode,oldnode);
                 }
                 else if(i==11)
                 {
                     qDebug("replace2");
                     oldnode = n.firstChild();
                     qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                     n.firstChild().setNodeValue(nwaitstring);
                    qDebug("replace3");
                    newnode = n.firstChild();
                    qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                    n.replaceChild(newnode,oldnode);
                }*/
            }
        }
    }
    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCancle::modify_MOVL(MovlCommand movlc,QString filename,int index)
{
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomNode node = root.firstChild();
    /*if(node = "movj")
        显示movj界面调用movj填值函数
        其它界面相同*/

    //while(!node.isNull())
    //{

    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    //可以直接用list.at(index)直接定位到需要修改的运动命令
    if(node.isElement()&(!node.isNull()))
    {
        QDomElement e = node.toElement();
        QDomNodeList list = e.childNodes();
        for(int i=0;i<list.count();i++)
        {
            QDomNode n = list.at(i);

            QDomNode oldnode;
           QDomNode newnode;

            if(node.isElement())
            {

                oldnode = n.firstChild();

                n.firstChild().setNodeValue(movlc.buf[i]);

                newnode = n.firstChild();

                n.replaceChild(newnode,oldnode);
            }
        }
    }
    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCancle::modify_MOVC(MovcCommand movcc,QString filename,int index)
{
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomNode node = root.firstChild();
    /*if(node = "movj")
        显示movj界面调用movj填值函数
        其它界面相同*/

    //while(!node.isNull())
    //{

    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    //可以直接用list.at(index)直接定位到需要修改的运动命令
    if(node.isElement()&(!node.isNull()))
    {
        QDomElement e = node.toElement();
        QDomNodeList list = e.childNodes();
        for(int i=0;i<list.count();i++)
        {
            QDomNode n = list.at(i);

            QDomNode oldnode;
           QDomNode newnode;

            if(node.isElement())
            {

                oldnode = n.firstChild();

                n.firstChild().setNodeValue(movcc.buf[i]);

                newnode = n.firstChild();

                n.replaceChild(newnode,oldnode);
            }
        }
    }
    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCancle::modify_speed(SpeedCommand speed,QString filename,int index)
{
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();
    QDomElement root = doc.documentElement();
    QDomNode node = root.firstChild();
    /*if(node = "movj")
        显示movj界面调用movj填值函数
        其它界面相同*/

    //while(!node.isNull())
    //{

    for(int j=0;j<index;j++)
    {
        node = node.nextSibling();
    }
    //可以直接用list.at(index)直接定位到需要修改的运动命令
    if(node.isElement()&(!node.isNull()))
    {
        QDomElement e = node.toElement();
        QDomNodeList list = e.childNodes();
        for(int i=0;i<list.count();i++)
        {
            QDomNode n = list.at(i);

            QDomNode oldnode;
           QDomNode newnode;

            if(node.isElement())
            {

                oldnode = n.firstChild();

                n.firstChild().setNodeValue(speed.buf[i]);

                newnode = n.firstChild();

                n.replaceChild(newnode,oldnode);
            }
        }
    }
    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}


void XmlCancle::read_xml_file(QPlainTextEdit *textedit,QString filename)
{
    QTextCursor cursor;
    textedit->clear();
    cursor = textedit->textCursor();

    //QIODevice *device;
    QFile file(filename+".xml");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"file open failure!";
        return;
    }
    xmlReader.setDevice(&file);
    while(!xmlReader.atEnd())
    {
        xmlReader.readNext();
        if(xmlReader.isStartElement()){
            if(xmlReader.name()=="movj")
            {
                //qDebug("read movj");
                /*while(!xmlReader.atEnd())
                {
                    //xmlReader.readNext();
                    xmlReader.readNextStartElement();
                    if(xmlReader.isStartElement())
                    {
                        if(xmlReader.name()=="positon")
                        {
                            movj_position = xmlReader.readElementText();

                            qDebug()<<"movj_position="
                                    <<movj_position;
                        }
                        else if(xmlReader.name()=="vj")
                        {
                            movj_vj = xmlReader.readElementText();
                            qDebug()<<"movj_vj="
                                    <<movj_vj;
                        }
                        else if(xmlReader.name()=="pl")
                        {
                            movj_pl = xmlReader.readElementText();
                            qDebug()<<"movj_pl="
                                    <<movj_pl;
                        }
                        else if(xmlReader.name()=="untill")
                        {
                            movj_untill = xmlReader.readElementText();
                            qDebug()<<"movj_untill="
                                    <<movj_untill;
                        }
                        else if(xmlReader.name()=="ioselect")
                        {
                            movj_ioselect = xmlReader.readElementText();
                            qDebug()<<"movj_ioselect="
                                    <<movj_ioselect;
                        }
                        else if(xmlReader.name()=="ionumber")
                        {
                            movj_ionumber = xmlReader.readElementText();
                            qDebug()<<"movj_ionumber="
                                    <<movj_ionumber;
                        }
                        else if(xmlReader.name()=="ioprepare")
                        {
                            movj_ioprepare = xmlReader.readElementText();
                            qDebug()<<"movj_ioprepare="
                                    <<movj_ioprepare;
                        }
                        else if(xmlReader.name()=="iovalue")
                        {
                            movj_iovalue = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="ioio")
                        {
                            movj_ioio = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="acc")
                        {
                            movj_acc = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="dec")
                        {
                            movj_dec = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="nwait")
                        {
                            movj_nwait = xmlReader.readElementText();
                            qDebug()<<"movj_nwait="
                                    <<movj_nwait;
                        }
                    }
                    if(xmlReader.isEndElement())
                    {
                        break;
                    }
                }*/

                for(int j=0;j<12;j++)
                {
                    //xmlReader.readNext();
                    xmlReader.readNextStartElement();
                    if(xmlReader.isStartElement())
                    {
                        movj_buf[j]=xmlReader.readElementText();
                        //qDebug()<<movj_buf[j];
                    }
                }

                untill = (movj_buf[3]=="0")?(""):(movj_buf[4]+movj_buf[5]+movj_buf[6]+movj_buf[7]+movj_buf[8]);
                constructorText ="MOVJ VJ="+movj_buf[1]+" "+"PL="+movj_buf[2]+" "+untill+" "+"ACC="+movj_buf[9]+" "+"DEC="+movj_buf[10]+" "+"N_WAIT="+movj_buf[11]+" "+movj_buf[0]+"\n";
                cursor.insertText(constructorText);
                //qDebug()<<constructorText;
            }
            else if(xmlReader.name()=="movl")
            {
                //qDebug("read movl");
                /*while(!xmlReader.atEnd())
                {
                    //xmlReader.readNext();
                    xmlReader.readNextStartElement();
                    if(xmlReader.isStartElement())
                    {
                        if(xmlReader.name()=="position")
                        {
                            movl_position = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="vl")
                        {
                            movl_vl = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="vr")
                        {
                            movl_vr = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="pl")
                        {
                            movl_pl = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="untill")
                        {
                            movl_untill = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="ioselect")
                        {
                            movl_ioselect = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="ionumber")
                        {
                            movl_ionumber = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="ioprepare")
                        {
                            movl_ioprepare = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="iovalue")
                        {
                            movl_iovalue = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="ioio")
                        {
                            movl_ioio = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="acc")
                        {
                            movl_acc = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="dec")
                        {
                            movl_dec = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="cr")
                        {
                            movl_cr = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="nwait")
                        {
                            movl_nwait = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="usr")
                        {
                            movl_usr = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="usrvalue")
                        {
                            movl_usrvalue = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="tool")
                        {
                            movl_tool = xmlReader.readElementText();
                        }
                        else if(xmlReader.name()=="toolvalue")
                        {
                            movl_toolvalue = xmlReader.readElementText();
                        }
                    }
                    if(xmlReader.EndElement)
                    {
                        break;
                    }
                }*/

                for(int k=0;k<18;k++)
                {
                    //xmlReader.readNext();
                    xmlReader.readNextStartElement();
                    if(xmlReader.isStartElement())
                    {
                        movl_buf[k]=xmlReader.readElementText();
                        //qDebug()<<movl_buf[k];
                    }
                }

                untill = (movl_buf[4]=="0")?(""):(movl_buf[5]+movl_buf[6]+movl_buf[7]+movl_buf[8]+movl_buf[9]);
                usr = (movl_buf[14]=="0")?(""):(movl_buf[15]);
                tool = (movl_buf[16]=="0")?(""):(movl_buf[17]);
                constructorText ="MOVL VL="+movl_buf[1]+" "+"VR="+movl_buf[2]+" "+"PL="+movl_buf[3]+" "+untill+" "+"ACC="+movl_buf[10]+" "+"DEC="+movl_buf[11]+" "+"CR="+movl_buf[12]+" "+"N_WAIT="+movl_buf[13]+" "+usr+" "+tool+" "+movl_buf[0]+"\n";
                cursor.insertText(constructorText);
            }
            else if(xmlReader.name()=="movc")
            {
                //qDebug("read movc");
                for(int i=0;i<18;i++)
                {
                    //xmlReader.readNext();
                    xmlReader.readNextStartElement();
                    if(xmlReader.isStartElement())
                    {
                        movc_buf[i]=xmlReader.readElementText();
                        //qDebug()<<movc_buf[i];
                    }
                }
                untill = (movc_buf[4]=="0")?(""):(movc_buf[5]+movc_buf[6]+movc_buf[7]+movc_buf[9]);
                usr = (movc_buf[14]=="0")?(""):(movc_buf[15]);
                tool = (movc_buf[16]=="0")?(""):(movc_buf[17]);
                constructorText ="MOVC VL="+movc_buf[1]+" "+"VR="+movc_buf[2]+" "+"PL="+movc_buf[3]+" "+untill+" "+"ACC="+movc_buf[10]+" "+"DEC="+movc_buf[11]+" "+"CR="+movc_buf[12]+" "+"N_WAIT="+movc_buf[13]+" "+usr+" "+tool+" "+movc_buf[0]+"\n";
                cursor.insertText(constructorText);
            }
            else if(xmlReader.name()=="speed")
            {
                //qDebug("read speed");
                for(int a=0;a<3;a++)
                {
                    //xmlReader.readNext();
                    xmlReader.readNextStartElement();
                    if(xmlReader.isStartElement())
                    {
                        speed_buf[a]=xmlReader.readElementText();
                        //qDebug()<<speed_buf[a];
                    }
                }
                constructorText = "SPEED "+speed_buf[0]+"="+speed_buf[1]+" "+"ACC="+speed_buf[2]+"\n";
                cursor.insertText(constructorText);
            }
            else if(xmlReader.name()=="DOUT")
            {
                for(int a=0;a<2;a++)
                {
                    //xmlReader.readNext();
                    xmlReader.readNextStartElement();
                    if(xmlReader.isStartElement())
                    {
                        dout_buf[a]=xmlReader.readElementText();

                    }
                }
                constructorText = "DOUT OUT"+dout_buf[0]+"="+dout_buf[1]+"\n";
                cursor.insertText(constructorText);
            }
            else if(xmlReader.name()=="DIN")
            {
                for(int a=0;a<2;a++)
                {
                    xmlReader.readNextStartElement();
                    if(xmlReader.isStartElement())
                    {
                        din_buf[a]=xmlReader.readElementText();

                    }
                }
                constructorText = "DIN B"+din_buf[0]+" IN"+din_buf[1]+"\n";
                cursor.insertText(constructorText);
            }
            else if(xmlReader.name()=="PAUSE")
            {
                for(int a=0;a<5;a++)
                {
                    xmlReader.readNextStartElement();
                    if(xmlReader.isStartElement())
                    {
                        pause_buf[a]=xmlReader.readElementText();

                    }
                }
                if(pause_buf[0]=="1")
                {
                    constructorText = "PAUSE IF "+pause_buf[1]+pause_buf[2]+pause_buf[3]+pause_buf[4]+"\n";
                }
                else
                {
                    constructorText="PAUSE\n";
                }
                cursor.insertText(constructorText);
            }
            else if(xmlReader.name()=="TIMER")
            {
                    xmlReader.readNextStartElement();
                    if(xmlReader.isStartElement())
                    {
                        time_buf=xmlReader.readElementText();

                    }
                constructorText = "TIMER T="+time_buf+"\n";
                cursor.insertText(constructorText);
            }
            else if(xmlReader.name()=="LABEL")
            {
                    xmlReader.readNextStartElement();
                    if(xmlReader.isStartElement())
                    {
                        label_buf=xmlReader.readElementText();

                    }
                constructorText = "LABEL "+label_buf+"\n";
                cursor.insertText(constructorText);
            }
            else if(xmlReader.name()=="JUMP")
            {
                for(int a=0;a<6;a++)
                {
                    xmlReader.readNextStartElement();
                    if(xmlReader.isStartElement())
                    {
                        jump_buf[a]=xmlReader.readElementText();
                    }
                }
                if(jump_buf[1]=="1")
                {
                    constructorText = "JUMP IF"+jump_buf[2]+jump_buf[3]+jump_buf[4]+jump_buf[5]+" LABEL="+jump_buf[0]+"\n";
                }
                else
                {
                    constructorText = "JUMP LABEL="+jump_buf[0]+"\n";
                }
                cursor.insertText(constructorText);
            }
            else if(xmlReader.name()=="CALL")
            {
                for(int a=0;a<6;a++)
                {
                    xmlReader.readNextStartElement();
                    if(xmlReader.isStartElement())
                    {
                        call_buf[a]=xmlReader.readElementText();
                    }
                }
                if(call_buf[1]=="1")
                {
                    constructorText = "CALL FILE="+call_buf[0]+"IF "+call_buf[2]+call_buf[3]+call_buf[4]+call_buf[5]+"\n";
                }
                else
                {
                    constructorText = "CALL FILE="+call_buf[0]+"\n";
                }
                cursor.insertText(constructorText);
            }
        else if(xmlReader.name()=="RET")
        {
            for(int a=0;a<5;a++)
            {
                xmlReader.readNextStartElement();
                if(xmlReader.isStartElement())
                {
                    ret_buf[a]=xmlReader.readElementText();
                }
            }
            if(ret_buf[0]=="1")
            {
                constructorText = "RET IF "+ret_buf[1]+ret_buf[2]+ret_buf[3]+ret_buf[4]+"\n";
            }
            else
            {
                //constructorText = "RET\n";
                constructorText = "RET";
            }
            cursor.insertText(constructorText);
        }


            else if(xmlReader.name()=="NOP")
            {
                //qDebug()<<"read NOP";
                if(xmlReader.isStartElement())
                {
                    nop_command = xmlReader.readElementText();
                }
                constructorText = nop_command+"\n";
                cursor.insertText(constructorText);
            }
            else if(xmlReader.name()=="END")
            {
                //qDebug()<<"read END";
                if(xmlReader.isStartElement())
                {
                    end_command = xmlReader.readElementText();
                }
                constructorText = end_command;
                cursor.insertText(constructorText);
            }

        }
    }
    file.close();

}


void XmlCancle::input_position_data(PositionData posi, QString filename)
{
    QString string_position_buf[7]={"frametyle","p1","p2","p3","p4","p5","p6"};

    QFile file(filename+"_position.xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    qDebug()<<"write position 111111111";

    QDomElement root = doc.documentElement();
    QDomElement pos = doc.createElement(posi.buf[0]);
    QDomText text;
    QDomElement element_string;
    for(int i=0;i<7;i++)
    {
        element_string = doc.createElement(string_position_buf[i]);
        text = doc.createTextNode(posi.buf[i+1]);
        element_string.appendChild(text);
        pos.appendChild(element_string);
    }

   // QDomNode node = root.lastChild();
    root.appendChild(pos);
    //root.insertBefore(pos,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCancle::delete_position_data(QString filename,QString posi_variable)
{
    QFile file(filename+"_position.xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    QDomNodeList list = root.childNodes();
    for(int i=0;i<list.count();i++)
    {
        QDomNode n = list.at(i);
        if(n.nodeName()==posi_variable)
        {
            root.removeChild(n);
        }
    }

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

//require position.xml file all variable of position ,use to  position variable comboBox;
void XmlCancle::require_position_variable()
{
    QFile file(program_filename+"_position.xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();
    QDomNodeList list = root.childNodes();
   // QString
    for(int i=0;i<list.count();i++)
    {
        QDomNode n = list.at(i);

        posi_vari_point.append(n.nodeName());

    }

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCancle::require_position_data(QString variable)
{
    QFile file(program_filename+"_position.xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomNodeList list = doc.elementsByTagName(variable);
    QDomElement e = list.at(0).toElement();
    QDomNodeList list_1 = e.childNodes();
    for(int i=0;i<7;i++)
    {
        QDomNode node = list_1.at(i);
        positiondata2.buf[i]=node.toElement().text();
        qDebug()<<positiondata2.buf[i];
    }

    /*QDomElement root = doc.documentElement();
    QDomNodeList list = root.childNodes();

    for(int i=0;i<list.count();i++)
    {
        QDomNode n = list.at(i);

        posi_vari_point.append(n.nodeName());

    }*/

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}
