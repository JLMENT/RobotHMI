#ifndef NUMERICTYPEXML_H
#define NUMERICTYPEXML_H
#include <QtXml>
#include <QObject>
#include <QFile>

class NumericTypeXml
{
    //Q_OBJECT
public:
    explicit NumericTypeXml();
    void readxml(QString,int);//数值类型，序号
    void domreadxml(QString,QString);
    void writexml(QString, QString, QString, QString);//数值类型，序号，名称，内容
    void writexml1(QString,int,QString,QString);
//    void findvalue(QString,QString);//类型，变量名
    void findvalue1(QString,QString);

    QString name;
    QString content;
    QString variatevalue;

private:
    //QXmlStreamReader xmlReader;
    //QDomDocument doc;

};

#endif // NUMERICTYPEXML_H
