#include "cpspace.h"

CpSpace::CpSpace()
{
    this->axis_title->setText("CP参数设置");
    int i;
    for(i=0;i<6;++i)
    {
        delete axis_button[i+1];
    }
    axis_button[0]->setText("CP");
    this->hb1->addSpacing(700);
    QStringList variate_list;
    variate_list<<"CP运动速度上限"<<"CP运动加速度"<<"CP运动减速度"<<"CP运动速度上限（姿态）"
               <<"CP运动加速度（姿态）"<<"CP运动减速度（姿态）"<<"CP运动过渡段速度比"<<"CP运动紧急停止减速度";
    for(i=0;i<8;++i)
    {
        variate[i]->setText(variate_list.at(i));
    }

}
