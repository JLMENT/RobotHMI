#ifndef XMLCANCLE_H
#define XMLCANCLE_H

#include <QObject>
#include <QPlainTextEdit>
#include <QXmlStreamReader>
#include <QtXml>
#include <include.h>
#include <QStringList>
#include <QDebug>

class XmlCancle : public QObject
{
    Q_OBJECT
public:
    explicit XmlCancle(QObject *parent = 0);

    /*struct MovjCommand
    {
        QString buf[12];
    };
    MovjCommand movjc1;
    struct MovlCommand
    {
        QString buf[18];
    };
    MovlCommand movlc1;

    struct MovcCommand
    {
        QString buf[18];
    };
    MovcCommand movcc1;
    struct SpeedCommand
    {
        QString buf[3];
    };
    SpeedCommand speedc1;*/

    void create_xml_file(QString);
    void create_xml_position_file(QString);
    void create_xml_subfile(QString);
    //可以将所有命令的输入写成一个接口函数，接口中加入一个参数（命令类型），根据命令类型调用相应的方法
    //Vj/PL/NUTIL/DIN/VALUE1/=/VALUE2/01/ACC/VALUE/DEC/VALUE/N_WAIT/POSITION
    //正常输入命令
    void input_MOVJ_command(MovjCommand,QString);
    void input_MOVL_command(MovlCommand,QString);
    void input_MOVC_command(MovcCommand,QString);
    void input_speed_command(SpeedCommand,QString);


    //(i/o)command
    void input_DOUT_command(DoutCommand,QString);
    void input_DIN_command(DinCommand,QString);

    void input_PAUSE_command(PauseCommand,QString);
    void input_TIMER_command(QString,QString);
    void input_JUMP_command(JumpCommand,QString);
    void input_LABEL_command(QString,QString);
    void input_CALL_command(CallCommand,QString);
    void input_RET_command(RetCommand,QString);




    //插入命令
    void insert_MOVJ_command(MovjCommand,QString,int);
    void insert_MOVL_command(MovlCommand,QString,int);
    void insert_MOVC_command(MovcCommand,QString,int);
    void insert_speed_command(SpeedCommand,QString,int);

    void insert_DOUT_command(DoutCommand,QString,int);
    void insert_DIN_command(DinCommand,QString,int);

    void insert_PAUSE_command(PauseCommand,QString,int);
    void insert_TIMER_command(QString,QString,int);
    void insert_JUMP_command(JumpCommand,QString,int);
    void insert_LABEL_command(QString,QString,int);
    void insert_CALL_command(CallCommand,QString,int);
    void insert_RET_command(RetCommand,QString,int);

    //删除命令(接口参数为光标位置行的值)（要加判断不能是首行和末行的值）
    void delete_command(QString,int);

    //修改命令-得到该元素是什么命令
    void get_command_style(QString,int);
    //修改-获取信息-调用相应的命令显示窗口(获的的命令保存到相应的命令结构中)
    void get_MOVJ(MovjCommand,QString,int);
    void get_MOVL(MovlCommand,QString,int);
    void get_MOVC(MovcCommand,QString,int);
    void get_speed(SpeedCommand,QString,int);
    void get_DOUT(DoutCommand,QString,int);
    void get_DIN(DinCommand,QString,int);

    void get_PAUSE_command(PauseCommand,QString,int);
    void get_TIMER_command(QString,QString,int);
    void get_JUMP_command(JumpCommand,QString,int);
    void get_LABEL_command(QString,QString,int);
    void get_CALL_command(CallCommand,QString,int);
    void get_RET_command(RetCommand,QString,int);

    //修改命令信息
    //using method of delete and add,this port havent used;
    void modify_MOVJ(MovjCommand,QString,int);
    void modify_MOVL(MovlCommand,QString,int);
    void modify_MOVC(MovcCommand,QString,int);
    void modify_speed(SpeedCommand,QString,int);
    void modify_DOUT(DoutCommand,QString,int);
    void modify_DIN(DinCommand,QString,int);

    //读取xml中的元素并显示出来
    void read_xml_file(QPlainTextEdit *textedit,QString filename);//读取完以后返回一个字符串

    /**********************位置点xml文件操作****************************/
    //输入位置命令
    void input_position_data(PositionData,QString);//给QString文件名添加PositionData位置信息
    void delete_position_data(QString,QString);//删除编号为QString P001的位置信息。
    void require_position_variable();//获取位置变量
    void require_position_data(QString);//获取指定变量的数据信息

signals:

public slots:

private:
    QXmlStreamReader xmlReader;

    QString constructorText;
    QString untill;
    QString usr;
    QString tool;

    //movj元素值
    QString movj_position;
    QString movj_vj;
    QString movj_pl;
    QString movj_untill;
    QString movj_ioselect;
    QString movj_ionumber;
    QString movj_ioprepare;
    QString movj_iovalue;
    QString movj_ioio;
    QString movj_acc;
    QString movj_dec;
    QString movj_nwait;

    QString movj_buf[12];

    //movl元素
    QString movl_position;
    QString movl_vl;
    QString movl_vr;
    QString movl_pl;
    QString movl_untill;
    QString movl_ioselect;
    QString movl_ionumber;
    QString movl_ioprepare;
    QString movl_iovalue;
    QString movl_ioio;
    QString movl_acc;
    QString movl_dec;
    QString movl_cr;
    QString movl_usr;
    QString movl_usrvalue;
    QString movl_tool;
    QString movl_toolvalue;
    QString movl_nwait;

    QString movl_buf[18];

    //movc元素
    QString movc_buf[18];
    //speed元素
    QString speed_buf[3];
    //dout value of element
    QString dout_buf[2];
    QString din_buf[2];
    QString pause_buf[5];
    QString time_buf;
    QString jump_buf[6];
    QString label_buf;
    QString call_buf[6];
    QString ret_buf[5];


    //NOP/END
    QString nop_command;
    QString end_command;

};

class ProgFileAnnotation
{
public:
    ProgFileAnnotation()
    {

    }
    void write_comments(QString filename,QString str)
    {
        QFile file("annotation.xml");
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
        QDomElement note = doc.createElement(filename);
        QDomText text = doc.createTextNode(str);
        note.appendChild(text);
        root.appendChild(note);

        if(!file.open(QFile::WriteOnly|QFile::Truncate))
            return;
        QTextStream out_stream(&file);
        doc.save(out_stream,4);
        file.close();
    }

    void read_comments(QString filename)
    {
        QFile file("annotation.xml");
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
            //qDebug()<<"COMMENTS";
            QDomNode n = list.at(i);
           // qDebug()<<n.nodeName();
            //qDebug()<<filename;
            if(n.nodeName()==filename)
            {
                //comments=n.nodeValue();
                comments=n.toElement().text();
                //qDebug()<<"finded comments";
                //qDebug()<<comments;
            }
        }

    }

    QString comments;
};

#endif // XMLCANCLE_H













