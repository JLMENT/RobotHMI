#include "numerictypexml.h"

NumericTypeXml::NumericTypeXml()
{

}

void NumericTypeXml::readxml(QString commandstr, int sequence)
{
    qDebug()<<"readxml";
    QFile file("/home/a/pengcheng/test1/src/numeric_type_module/numeric_type.xml");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"file open failure!";
        return;
    }
    int i=0,j;
    QXmlStreamReader xmlReader;//(&file);
    xmlReader.setDevice(&file);
    for(j=0;j<6;++j)
    {
        xmlReader.readNext();
    }
    while(!xmlReader.atEnd())
    {
        xmlReader.readNext();
        if(xmlReader.name()=="name")
        {
            qDebug()<<xmlReader.readElementText();
        }
        if(xmlReader.name()=="content")
        {
            qDebug()<<xmlReader.readElementText();
        }
    }
    //xmlReader.readNext();
    /*if(commandstr=="interger")
    {
        xmlReader.readNext();
        qDebug()<<11;
        qDebug()<<xmlReader.readElementText();
        qDebug()<<xmlReader.name();
        for(int i=0;i<=sequence;++i)
        {
            xmlReader.readNextStartElement();
            for(int j=0;j<2;++j)
            {
                xmlReader.readNextStartElement();
                qDebug()<<xmlReader.name()<<xmlReader.text();
            }
        }
        xmlReader.readNextStartElement();
        name=xmlReader.readElementText();
        xmlReader.readNextStartElement();
        content=xmlReader.readElementText();
        qDebug()<<xmlReader.name();
        qDebug()<<22;
    }
    else if(commandstr=="realnumber")
    {
        xmlReader.readNext();
        xmlReader.readNext();
        for(int i=0;i<sequence;++i)
        {
            xmlReader.readNextStartElement();
            for(int j=0;j<2;++j)
            {
                xmlReader.readNextStartElement();
            }
        }
        xmlReader.readNextStartElement();
        name=xmlReader.readElementText();
        xmlReader.readNextStartElement();
        content=xmlReader.readElementText();
    }
    else if(commandstr=="byte")
    {
        xmlReader.readNext();
        xmlReader.readNext();
        xmlReader.readNext();
        for(int i=0;i<sequence;++i)
        {
            xmlReader.readNextStartElement();
            for(int j=0;j<2;++j)
            {
                xmlReader.readNextStartElement();
            }
        }
        xmlReader.readNextStartElement();
        name=xmlReader.readElementText();
        xmlReader.readNextStartElement();
        content=xmlReader.readElementText();
    }
    else
    {
        return;
    }
    if(xmlReader.hasError())
    {
        qDebug()<<"error";
    }
    */
    file.close();
}

void NumericTypeXml::writexml(QString valuetype, QString sequence, QString name, QString content)
{
    QFile file("numeric_type.xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomNode node,n1,n11;
    QDomNodeList list1,list11;


    QDomElement root = doc.documentElement();
    QDomElement element = doc.createElement("int"+sequence);
    QDomElement childelement1 = doc.createElement("name");
    QDomText text1;
    text1 = doc.createTextNode(name);
    childelement1.appendChild(text1);
    element.appendChild(childelement1);

    QDomElement childelement2 = doc.createElement("content");
    QDomText text2;
    text2 = doc.createTextNode(content);
    childelement2.appendChild(text2);
    element.appendChild(childelement2);
    //QDomNode n22 = element.

    qDebug()<<element.tagName()<<element.text();


    node = root.firstChild();
    int i = sequence.toInt()-1;
    qDebug()<<i;

    if(valuetype=="interger")
    {
        node = root.firstChild();
        node = node.firstChild();

//        list1 = node.childNodes();
//        n1 = list1.at(i);

//        //list11 = n1.childNodes();
//        //n11 = list11.at(i);
//        qDebug()<<n1.toElement().tagName()<<n1.toElement().text();
//        qDebug()<<n1.nodeName()<<n1.nodeValue();
        for(int j=0;j<i;++j)
        {
            node = node.nextSibling();
            qDebug()<<node.nodeName();
            qDebug()<<12345;
        }
    }
    else if(valuetype=="realnumber")
    {
        //node = root.firstChild();
        list1 = node.childNodes();
        n1 = list1.at(1);
        list11 = n1.childNodes();
        n11 = list11.at(i);
    }
    else if(valuetype=="byte")
    {
        node = root.firstChild();
        list1 = node.childNodes();
        n1 = list1.at(2);
        list11 = n1.childNodes();
        n11 = list11.at(i);
    }
    else
    {
        return;
    }



     //root.insertBefore(element,n1);
    //root.removeChild(n1);
    //root.replaceChild(element,node);
//    QDomNode n33 = root.lastChild();
//    root.insertAfter(element,n33);
    root.insertAfter(element,node);

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();


}
//数值类型，序号，名称，内容
void NumericTypeXml::writexml1(QString valuetype, int sequence, QString name, QString content)
{

    QFile file("numeric_type.xml");
    if(!file.open(QFile::ReadOnly))
        return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QString str[2]={name,content};
    QDomNode node;

    QDomElement root = doc.documentElement();
    node = root.firstChild();
    if(valuetype=="interger")
    {

    }
    else if(valuetype=="realnumber")
    {

        node = node.nextSibling();
    }
    else if(valuetype=="byte")
    {

        node = node.nextSibling();
        node = node.nextSibling();
    }
    node = node.firstChild();
    for(int j=0;j<sequence;++j)
    {
        node = node.nextSibling();
    }
    QDomElement e = node.toElement();
    QDomNodeList list = e.childNodes();
    for(int i=0;i<list.count();i++)
    {
        QDomNode n = list.at(i);
        QDomNode oldnode;
        QDomNode newnode;

        oldnode = n.firstChild();
        n.firstChild().setNodeValue(str[i]);
        newnode = n.firstChild();
        n.replaceChild(newnode,oldnode);
    }

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    QTextStream out_stream(&file);
    doc.save(out_stream,4);
    file.close();

}

//void NumericTypeXml::findvalue(QString valuestyle, QString variate)
//{
//    QFile file("numeric_type.xml");
//    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
//        qDebug()<<"file open failure!";
//        return;
//    }
//    int i=0,j;
//    QXmlStreamReader xmlReader;//(&file);
//    xmlReader.setDevice(&file);
//    while(!xmlReader.atEnd())
//    {
//        xmlReader.readNext();
//        if(xmlReader.name()=="name")
//        {
//            if(xmlReader.readElementText()==variate)
//            {

//                xmlReader.readNextStartElement();
//                variate = xmlReader.readElementText();
//            }
//        }
//    }
//}

void NumericTypeXml::findvalue1(QString valuestyle, QString variate)
{
    QFile file("numeric_type.xml");
    if(!file.open(QFile::ReadOnly))
        return;

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomNode n1,n11;
    QDomNodeList list1,list11,list2;
    QDomElement root = doc.documentElement();
    QDomNode node = root.firstChild();

    if(valuestyle=="interger")
    {

    }
    else if(valuestyle=="realnumber")
    {
        node = node.nextSibling();
    }
    else if(valuestyle=="byte")
    {
        node = node.nextSibling();
        node = node.nextSibling();
    }
    list1 = node.childNodes();
    for(int i=0;i<24;++i)
    {
        n1 = list1.at(i);
        list11 = n1.childNodes();
        if(list11.at(0).toElement().text()==variate)
        {
            //variatevalue = list11.at(0).toElement().text();
            content = list11.at(1).toElement().text();
        }
    }

    file.close();
}

void NumericTypeXml::domreadxml(QString valuestyle, QString sequence)
{
    //qDebug()<<"ddd";
    QFile file("numeric_type.xml");
    //QFile file("/home/a/pengcheng/test1/src/numeric_type_module/numeric_type.xml");
    if(!file.open(QFile::ReadOnly))
    {
        qDebug()<<"file readxml failure!";
        return;
    }
    qDebug()<<"next";

    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    qDebug()<<"next_1";
    file.close();

    QDomNode n1,n11;
    QDomNodeList list1,list11,list2;
    int i = sequence.toInt();
    qDebug()<<i;

    QDomElement root = doc.documentElement();
    QDomNode node = root.firstChild();
    qDebug()<<node.nodeName();
    if(valuestyle=="interger")
    {
        list1 = node.childNodes();
        n1 = list1.at(i);
        list11 = n1.childNodes();
    }
    else if(valuestyle=="realnumber")
    {
        node = node.nextSibling();
        list1 = node.childNodes();
        n1 = list1.at(i);
        list11 = n1.childNodes();
    }
    else if(valuestyle=="byte")
    {
        node = node.nextSibling().nextSibling();
        list1 = node.childNodes();
        n1 = list1.at(i);
        list11 = n1.childNodes();
    }
    else
    {
        return;
    }


    name = list11.at(0).toElement().text();
    content = list11.at(1).toElement().text();
    qDebug()<<name<<content;

    file.close();


//    list2 = n11.childNodes();
//    name = list2.at(1).toElement().text();
//    content = list2.at(2).toElement().text();
}



















