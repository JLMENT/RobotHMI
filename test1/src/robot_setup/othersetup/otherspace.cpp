#include "otherspace.h"

OtherSetup::OtherSetup()
{
//    this->axis_title->setText("CP参数设置");
//    int i;
//    for(i=0;i<6;++i)
//    {
//        delete axis_button[i+1];
//    }
//    axis_button[0]->setText("CP");
//    this->hb1->addSpacing(700);
//    QStringList variate_list;
//    variate_list<<"CP运动速度上限"<<"CP运动加速度"<<"CP运动减速度"<<"CP运动速度上限（姿态）"
//               <<"CP运动加速度（姿态）"<<"CP运动减速度（姿态）"<<"CP运动过渡段速度比"<<"CP运动紧急停止减速度";
//    for(i=0;i<8;++i)
//    {
//        variate[i]->setText(variate_list.at(i));
//    }

    this->axis_title->setText("其他参数设置");
    int i;
    for(i=0;i<6;++i)
    {
        delete axis_button[i+1];
    }
    axis_button[0]->setText("Other");
    this->hb1->addSpacing(700);
    QStringList variate_list;
    variate_list<<"服务器IP"<<"服务器端口"<<"设备号"<<"电机速度比（报警）"
               <<"电机速度比（紧急停止）"<<"心跳包周期"<<"数据包发送周期"<<"心跳包正常周期";
    for(i=0;i<8;++i)
    {
        variate[i]->setText(variate_list.at(i));
    }

}
