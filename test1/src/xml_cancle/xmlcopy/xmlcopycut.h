#ifndef XMLCOPYCUT_H
#define XMLCOPYCUT_H

#include <QObject>
#include <QString>
#include <QPlainTextEdit>
#include <QtXml>
#include <QList>
#include <xml_cancle/xmlread/operateprogramxml.h>

//class RunFile;
//typedef int (RunFile::*ExeLine)(int lineNumber);
class XmlCopyCut : public QObject
{
    Q_OBJECT
public:
    explicit XmlCopyCut(QObject *parent = 0);

    void ensure_head_line(QString,int);
    void ensure_end_line(QString,int);
    QString* program_copy();
    QString* program_cut();
    void program_paste(int);

private:
    //void operate_check();
    QString *operate_check();
    void copy_paste(int);
    void cut_paste(int);
    //void acquire_command_string(int linenumber);
    void save_select_program();
    //void acquire_save_node();
    void clear_save_program();//require to release internal storage;
    void delete_select_xmlprogram();


    ///////////////////////////////////
    //will command changet to string

//    void stringMovj();
//    void stringMovl();
//    void stringMovc();
//    void stringSpeed();
//    void stringDin();
//    void stringDout();
//    void stringPause();
//    void stringTimer();
//    void stringLabel();
//    void stringJump();
//    void stringCall();
//    void stringRet();
//    void stringNop();
//    void stringEnd();

    //////////////////////////////////

//    OperateProgramXml *operateprogramxml = new OperateProgramXml;
//    ProgramXmlLine line;
//    ExeLine exe[COMMAND_END_TYPE+1];

protected:
    QString start_filename;
    int start_linenumber;
    QString end_filename;
    int end_linenumber;
    bool copystatus;
    bool cutstatus;
    QList<QDomNode> nodelist;
    QString *stringcommand = new QString;

    
signals:
    //void cut_paste_display(QString *);
    //void cut_program_sig(int,int);
    //void command_insert_display(QString *);
    void refresh_reload_program(QString);
    
public slots:
    
};

#endif // XMLCOPYCUT_H
