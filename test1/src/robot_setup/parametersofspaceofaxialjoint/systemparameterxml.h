#ifndef SYSTEMPARAMETERXML_H
#define SYSTEMPARAMETERXML_H
#include <QtXml>
#include <QString>
#include "file_path_macro.h"


class SystemParameterXml
{
public:
    SystemParameterXml(QString filename);
    void closexml();


    void readxml(int,int,int);//系统参数类型(axisjoint/descartes/cp/dh/axiscontrol/other)，轴号，参数
    void writexml(int, int, int, QString);//系统参数类型、轴号、参数号、参数值

    QString paremeter_value;
private:
    QDomDocument *doc;
    QFile *file;
    QDomElement root;
    QDomElement e,e1;
    QDomNodeList list,list1,list11;
    QDomNode node,n,n1,oldnode,newnode,node1,node11;
    QTextStream *out_stream;
};

#endif // SYSTEMPARAMETERXML_H
