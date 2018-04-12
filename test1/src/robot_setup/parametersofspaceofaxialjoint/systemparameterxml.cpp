#include "systemparameterxml.h"
#include <QDebug>

SystemParameterXml::SystemParameterXml(QString filename)
{
    file = new QFile(filename+".xml");
    if(!file->open(QFile::ReadOnly|QFile::WriteOnly))
        return;
    doc = new QDomDocument;
    if(!doc->setContent(file))
    {
        file->close();
        return;
    }
    file->close();
//    root = doc->documentElement();
//    node = root.firstChild();
}

void SystemParameterXml::closexml()
{
    file->close();
}

void SystemParameterXml::readxml(int paremeterstyle, int axisnum, int index)
{
    root = doc->documentElement();
    node = root.firstChild();
    for(int i=0;i<paremeterstyle;++i) //(0,1,2,3,4,5--axisjoint/descartes/cp/dh/axiscontrol/other)
    {
        node = node.nextSibling();
    }
    list = node.childNodes();
    node1 = list.at(axisnum-1);
    list11 = node1.childNodes();
    node11 = list11.at(index);
    paremeter_value = node11.nodeValue();
    e = node11.toElement();
    paremeter_value = e.text();

}

void SystemParameterXml::writexml(int paremeterstyle, int axisnum, int index,QString str)
{
    root = doc->documentElement();
    node = root.firstChild();
    for(int i=0;i<paremeterstyle;++i) //(0,1,2,3,4,5--axisjoint/descartes/cp/dh/axiscontrol/other)
    {
        node = node.nextSibling();
    }
    e = node.toElement();

    list = e.childNodes();
    node1 = list.at(axisnum-1);

    e1 = node1.toElement();

    list11 = e1.childNodes();
//    e = node1.toElement();
//    list11 = e.childNodes();
    node11 = list11.at(index);
    oldnode = node11.firstChild();

    node11.firstChild().setNodeValue(str);
    newnode = node11.firstChild();

    node11.replaceChild(newnode,oldnode);
    if(!file->open(QFile::WriteOnly|QFile::Truncate))
        return;
    out_stream = new QTextStream(file);
    doc->save(*out_stream,4);
    file->close();


}
