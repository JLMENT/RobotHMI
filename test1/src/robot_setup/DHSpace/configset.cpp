#include "configset.h"

QSettings ConfigSet::settrings("config.ini",QSettings::IniFormat);

ConfigSet::ConfigSet()
{

}

void ConfigSet::createIni(QString str, int num)
{
    if(settrings.value(str+"/num0").toString()!="yes")
    {
    settrings.beginGroup(str);
    settrings.setValue("num0","yes");
    for(int i=1;i<=num;++i)
    {
        settrings.setValue("num"+QString::number(i,10),0);
    }
    settrings.endGroup();
    }
}
