#ifndef CONFIGSET_H
#define CONFIGSET_H
#include <QSettings>



class ConfigSet
{
public:
    ConfigSet();
    createIni(QString,int);//参数群名，参数个数
    readIni();
    static QSettings settrings;
};

#endif // CONFIGSET_H
