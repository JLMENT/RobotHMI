#ifndef CONFIGSET_H
#define CONFIGSET_H
#include <QSettings>
#include "file_path_macro.h"



class ConfigSet
{
public:
    ConfigSet();
    void createIni(QString,int);//参数群名，参数个数
    void readIni();
    static QSettings settrings;
};

#endif // CONFIGSET_H
