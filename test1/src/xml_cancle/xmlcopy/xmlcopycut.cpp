#include "xmlcopycut.h"

XmlCopyCut::XmlCopyCut(QObject *parent) :
    QObject(parent)
{
    start_filename = "null";
    start_linenumber = 0;
    end_filename = "null";
    end_linenumber = 0;
    copystatus = false;
    cutstatus = false;

//    exe[COMMAND_MOVJ_TYPE] = &RunFile::stringMovj;
//    exe[COMMAND_MOVL_TYPE] = &RunFile::stringMovl;
//    exe[COMMAND_MOVC_TYPE] = &RunFile::stringMovc;
//    exe[CMOMAND_SPEED_TYPE] = &RunFile::stringSpeed;
//    exe[COMMAND_DOUT_TYPE] = &RunFile::stringDout;
//    exe[COMMAND_DIN_TYPE] = &RunFile::stringDin;
//    exe[COMMAND_JUMP_TYPE] = &RunFile::stringJump;
//    exe[COMMAND_LABEL_TYPE] = &RunFile::stringLabel;
//    exe[COMMAND_CALL_TYPE] = &RunFile::stringCall;
//    exe[COMMAND_PAUSE_TYPE] = &RunFile::stringPause;
//    exe[COMMAND_TIMER_TYPE] = &RunFile::stringTimer;
//    exe[COMMAND_RET_TYPE] = &RunFile::stringRet;
//    exe[COMMAND_NOP_TYPE] = &RunFile::stringNop;
//    exe[COMMAND_END_TYPE] = &RunFile::stringEnd;
}

void XmlCopyCut::ensure_head_line(QString filename, int number)
{
    start_filename = filename;
    start_linenumber = number;
}

void XmlCopyCut::ensure_end_line(QString filename, int number)
{
    end_filename = filename;
    end_linenumber = number;
}

QString* XmlCopyCut::program_copy()
{
    QString *string  = new QString;

    string = operate_check();

    if(*string=="correct")
    {
        copystatus = true;
        cutstatus = false;
    }
    else
    {
        return string;
    }
    clear_save_program();
    save_select_program();
}

/*
  function:
  paremeter:
  return value:
  1.clear program display
  2.require a command ,delete a commmand
  */

QString* XmlCopyCut::program_cut()
{
    QString *string = new QString;
    string = operate_check();
    if(*string=="correct")
    {
        cutstatus = true;
        copystatus = false;
    }
    else
    {
        return string;
    }
    //display clear
    //program display interface remove cut program.

    //emit cut_program_sig(start_linenumber,end_linenumber);


    //xml cut operate
    //cut_paste(linenumber);
    clear_save_program();
    save_select_program();
    delete_select_xmlprogram();

}

void XmlCopyCut::program_paste(int linenumber)
{
//    if(copystatus==true&&cutstatus==false)
//    {
//        copy_paste(linenumber);
//    }
//    else if(copystatus==false&&cutstatus==true)
//    {
//        cut_paste(linenumber);
//    }
//    else
//    {
//        return;
//    }
    //QString *command_string = new QString;
    if(copystatus==true||cutstatus==true)
    {
        QFile file(end_filename+".xml");
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
        QDomNode n1;
        QDomNode n2;

        //check out data of QList
        for(int i=0;i<nodelist.count();i++)
        {
            n1 = nodelist.at(i);
            n2 = list.at(linenumber+i);
            root.insertBefore(n1,n2);
            //acquire_command_string();
            //emit command_insert_display(stringcommand);

        }
        //emit refresh_reload_program(end_filename);

        if(!file.open(QFile::WriteOnly|QFile::Truncate))
            return;
        QTextStream out_stream(&file);
        doc.save(out_stream,4);
        file.close();
        emit refresh_reload_program(end_filename);
    }

}

QString* XmlCopyCut::operate_check()
{
    QString *string  = new QString;
    if(start_filename=="null")
    {
        *string = "not assign start filename";
        return string;
    }
    else if(start_linenumber==0)
    {
        *string = "start line number error";
        return string;
    }
    else if(end_filename=="null")
    {
        *string = "not assign end filename";
        return string;
    }
    else if(end_linenumber==0)
    {
        *string = "end line number error";
        return string;
    }
    else if(start_filename!=end_filename)
    {
        *string = "start_filename is different with end_filename";
        return string;
    }
    if(start_linenumber>end_linenumber)
    {
        int temp;
        temp = start_linenumber;
        start_linenumber=end_linenumber;
        end_linenumber=temp;
    }
    *string = "correct";
    return  string;
}


/*void XmlCopyCut::copy_paste(int linenumber)
{
    int total_paste_line,i;
    QString *commmand_string = new QString;
    total_paste_line=end_linenumber-start_linenumber+1;

    QFile file(end_filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.document();
    QDomNodeList list = root.childNodes();
    QDomNode n1;
    QDomNode n2;

    if(linenumber<=start_linenumber)
    {
        for(i=0;i<total_paste_line;i++)
        {
            n1 = list.at(start_linenumber+i+i);
            n2 = list.at(linenumber+i);
            root.insertBefore(n1,n2);

            acquire_command_string();
            emit command_insert_display(stringcommand);
        }
    }
    else if(linenumber>end_linenumber)
    {
        for(i=0;i<total_paste_line;i++)
        {
            n1 = list.at(start_linenumber+i);
            n2 = list.at(linenumber+i);
            root.insertBefore(n1,n2);

            commmand_string = acquire_command_string();
            emit command_insert_display(command_string);
        }
    }
    else
    {
        int up = linenumber-start_linenumber;
        int down = end_linenumber-linenumber+1;
        for(i=0;i<up;i++)
        {
            n1 = list.at(start_linenumber+i);
            n2 = list.at(linenumber+i);
            root.insertBefore(n1,n2);

            commmand_string = acquire_command_string();
            emit command_insert_display(command_string);
        }
        for(i=0;i<down;i++)
        {
            n1 = list.at(linenumber+up+i+i);
            n2 = list.at(linenumber+up+i);
            root.insertBefore(n1,n2);

            commmand_string = acquire_command_string();
            emit command_insert_display(command_string);
        }
    }

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCopyCut::cut_paste(int linenumber)
{
    int total_paste_line,i;
    total_paste_line=end_linenumber-start_linenumber+1;

    QFile file(end_filename+".xml");
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.document();
    QDomNodeList list = root.childNodes();
    QDomNode n1;
    QDomNode n2;

    if(linenumber>end_linenumber)
    {
        for(i=0;i<total_paste_line;i++)
        {
            n1 = list.at(start_linenumber);
            n2 = list.at(linenumber-i);
            root.insertBefore(n1,n2);
            //root.removeChild(list.at(start_linenumber));
            //read one command

            QString *commmand_string = new QString;
            commmand_string = acquire_command_string();

            emit command_insert_display(command_string);

            root.removeChild(n1);
        }
    }
    else if(linenumber<=start_linenumber)
    {
        for(i=0;i<total_paste_line;i++)
        {
            n1 = list.at(start_linenumber);
            n2 = list.at(linenumber+i);
            root.insertBefore(n1,n2);

            QString *commmand_string = new QString;
            commmand_string = acquire_command_string();

            emit command_insert_display(command_string);

            root.removeChild(n1);
        }
    }
    else
    {

    }

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCopyCut::acquire_command_string(int linenumber)
{
    //acquire command style
    //analysis command
    operateprogramxml->readLine(linenumber);

    if(line.commandType>COMMAND_MOVC_TYPE)
    {
        //command error
        return;
    }


    ExeLine run = exe[line.commandType];
    stringcommand = (this->*run)(lineNumber);


}*/

void XmlCopyCut::save_select_program()
{
    QFile file(end_filename+".xml");
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

    for(int i=start_linenumber;i<=end_linenumber;i++)
    {
        //nodelist = list.at(i);
        nodelist.append(list.at(i));
    }

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
}

void XmlCopyCut::clear_save_program()
{
    nodelist.clear();
}

void XmlCopyCut::delete_select_xmlprogram()
{
    QFile file(end_filename+".xml");
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
    QDomNode n;

    for(int i=0;i<end_linenumber-start_linenumber+1;i++)
    {
        n=list.at(start_linenumber);
        root.removeChild(n);
    }

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();
    emit refresh_reload_program(end_filename);

}

/*void XmlCopyCut::stringMovj()
{
    QString *string = new QString;
    QString vj = QString::number(line.vel.vj,10);
    QString pl = QString::number(line.pl,10);

    QString type;
    QString varaddress;
    QString sig;
    QString dio;
    QString intergervalue;
    QString conditionstr;
    if(line.condition.type==0&&line.condition.type==1)
    {
        if(line.condition.type==0)
        {
            type="DIN";
        }
        else
        {
            type="DOUT";
        }
        varaddress = QString::number(line.condition.varAddress,10);
        if(line.condition.sign==0)
        {
            sig="=";
        }else if(line.condition.sign==1)
        {
            sig=">";
        }else if(line.condition.sign==2)
        {
            sig="<";
        }else if(line.condition.sign==3)
        {
            sig=">=";
        }else if(line.condition.sign==4)
        {
            sig="<=";
        }
        if(line.condition.value.dio==0)
        {
            dio="OFF";
        }
        else
        {
            dio="ON";
        }
        conditionstr=type+varaddress+sig+dio;
    }
    else
    {
        if(line.condition.type=="2")
        {
            type="B";
        }
        else
        {
            type="INT";
        }

        varaddress=QString::number(line.condition.varAddress,10);

        if(line.condition.sign==0)
        {
            sig="=";
        }else if(line.condition.sign==1)
        {
            sig=">";
        }else if(line.condition.sign==2)
        {
            sig="<";
        }else if(line.condition.sign==3)
        {
            sig=">=";
        }else if(line.condition.sign==4)
        {
            sig="<=";
        }
        intergervalue = QString::number(line.condition.value.integerValue,10);
        conditionstr = type+varaddress+sig+intergervalue;

    }



    QString acc = QString::number(line.acc,10);
    QString dec = QString::number(line.dec,10);
    QString nwait = QString::number(line.nwait,10);


    line.p;
    line.vel.vj;
    line.pl;

    line.condition.type;

    line.condition.sign;
    line.condition.value.dio;
    line.condition.value.integerValue;
    line.condition.varAddress;

    line.IoPort;
    line.acc;
    line.dec;
    line.nwait;
    line.positionstring;
    *string = "MOVJ VJ="+vj+" "+"PL="+pl+" "+conditionstr+" "+"ACC="+acc
            +" "+"DEC="+dec+" "+"N_WAIT="+nwait+" "+line.positionstring+"\n";
    return string;
}

void XmlCopyCut::stringMovl()
{

}*/










