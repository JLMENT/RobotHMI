#include "axiajonintwidget.h"
#include <QStringList>
#include <QMessageBox>


AxiaJonintWidget::AxiaJonintWidget(QWidget *parent)
    : QWidget(parent)
{
    page_status=0;
    axis_status =0;
    saveok = false;
    pagestatus = AXIS1_PAGE1;

    systemparameterxml = new SystemParameterXml("axis_joint");

    //this->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->setMinimumSize(100,100);
    axis_title = new QLineEdit(tr("轴关节空间参数设置"),this);
    axis_title->setEnabled(false);
    //axis_title->setStyleSheet("background-color:blue");
    axis_title->setStyleSheet("background-color:rgb(0,238,238)");
    axis_title->setAlignment(Qt::AlignCenter);

    //设置文本颜色
    //使用调色板-1
//    QBrush myBrush;
//    QPalette palette;
//    myBrush = QBrush(Qt::red,Qt::DiagCrossPattern);
//    palette.setBrush(QPalette::Text,myBrush);
//    axis_title->setPalette(palette);

    //使用调色板-2
    QPalette palette;
    palette.setColor(QPalette::Text,Qt::white);
    axis_title->setPalette(palette);

    //设置字体大小
    axis_title->setFont(QFont("Timers",28,QFont::Bold));

    //设置自由拉伸
    //axis_title->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    axis_title->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);


    list1<<"Axis(1~8)"<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8";
    list2<<"关节运动下线"<<"关节运动下限偏置"<<"关节运上限"<<"关节运动上限偏置"
        <<"关节运动速度上限（JOG）"<<"关节运动加减速度（JOG）"<<"关节运动速度上限(MOVJ)"
       <<"关节运动加速度（MOVJ）"<<"page2"<<"1"<<"1"<<"1"<<"1"<<"1"<<"1"<<"1"
         <<"1"<<"1"<<"1"<<"1"<<"1"<<"1"<<"1"<<"page3";
    list3<<"0.1"<<"0.0"<<"0.0"<<"0.0"<<"0.0"<<"0.0"<<"0.0"<<"0.0"
           <<"0.2"<<"0.0"<<"0.0"<<"0.0"<<"0.0"<<"0.0"<<"0.0"<<"0.0"
             <<"0.3"<<"0.0"<<"0.0"<<"0.0"<<"0.0"<<"0.0"<<"0.0"<<"0.0";
    list4<<"Save"<<""<<"PageUp"<<"PageDown";
    int i;
    vb1 = new QVBoxLayout(this);
    hb1 = new QHBoxLayout(this);
    hb2 = new QHBoxLayout(this);
    gb1 = new QGridLayout(this);
    for(i=0;i<9;++i)
    {
        axis_button[i] = new QPushButton(list1.at(i),this);
        //axis_button[i]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
        axis_button[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        //axis_button[i]->setStyle();

        hb1->addWidget(axis_button[i]);
    }
    axis_button[0]->setEnabled(false);

    //设置按键颜色

    QPalette pal = axis_button[1]->palette();
    pal.setColor(QPalette::ButtonText,QColor(255,0,0));
    axis_button[1]->setPalette(pal);

    //字体颜色设置
    //axis_button[1]->setStyleSheet("color:red");

    axis_button[1]->setStyleSheet("background-color:rgb(0,238,118)");


    hb1->setMargin(0);
    hb1->setSpacing(0);
    hb1->setStretch(0,2);
    for(i=1;i<9;++i)
    {
        hb1->setStretch(i,1);
    }
    hb1->setStretchFactor(axis_button[0],2);
    for(i=1;i<9;++i)
    {
        hb1->setStretch(i,1);
    }


    for(i=0;i<8;++i)
    {
        variate[i] = new QLineEdit(list2.at(i),this);
        //variate[i]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
        variate[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        variate[i]->setEnabled(false);
        variate[i]->setAlignment(Qt::AlignCenter);
        //variate_value[i] = new QLineEdit(list3.at(i),this);
        variate_value[i] = new DigetEdit;
        //variate_value[i]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
        variate_value[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        variate_value[i]->setAlignment(Qt::AlignCenter);
        gb1->addWidget(variate[i],i,0);
        gb1->addWidget(variate_value[i],i,1);
    }
    gb1->setMargin(0);
    gb1->setSpacing(0);

    label = new QLabel("(1/3)",this);
    label->setAlignment(Qt::AlignCenter);
    for(i=0;i<4;++i)
    {
        operate[i]=new QPushButton(list4.at(i),this);
        //operate[i]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
        operate[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        hb2->addWidget(operate[i]);
    }
    operate[1]->setEnabled(false);
    hb2->setMargin(0);
    hb2->setSpacing(0);

    vb1->addWidget(axis_title);
    vb1->addLayout(hb1);
    vb1->addLayout(gb1);
    vb1->addWidget(label);
    vb1->addLayout(hb2);

    vb1->setStretch(0,3);
    vb1->setStretch(1,1);
    vb1->setStretch(2,8);
    vb1->setStretch(3,3);
    vb1->setStretch(4,1);


    this->setLayout(vb1);

    connect(axis_button[1],SIGNAL(clicked()),this,SLOT(axis1_parameter_slot()));
    connect(axis_button[2],SIGNAL(clicked()),this,SLOT(axis2_parameter_slot()));
    connect(axis_button[3],SIGNAL(clicked()),this,SLOT(axis3_parameter_slot()));
    connect(axis_button[4],SIGNAL(clicked()),this,SLOT(axis4_parameter_slot()));
    connect(axis_button[5],SIGNAL(clicked()),this,SLOT(axis5_parameter_slot()));
    connect(axis_button[6],SIGNAL(clicked()),this,SLOT(axis6_parameter_slot()));
    connect(axis_button[7],SIGNAL(clicked()),this,SLOT(axis7_parameter_slot()));
    connect(axis_button[8],SIGNAL(clicked()),this,SLOT(axis8_parameter_slot()));
    connect(operate[0],SIGNAL(clicked()),this,SLOT(save_slot()));
    connect(operate[2],SIGNAL(clicked()),this,SLOT(pageup_slot()));
    connect(operate[3],SIGNAL(clicked()),this,SLOT(pagedown_slot()));

    //数据初始化
    dataInit();

    robot_data_init();//add_robot_param 20180321(robot param init)


}

AxiaJonintWidget::~AxiaJonintWidget()
{
    systemparameterxml->closexml();
}

void AxiaJonintWidget::axis1_parameter_slot()
{
    //判断保存状态
    //页面状态改变，检测当前显示值和文件值是否相同。
    //判断当前状态，并且判断当前的值是否改变（界面值和文件值校验操作），改变则提示是否保存当前值。

    //读取轴一第一页的参数

    //设置当前状态
    axis_save_response();
    axis_cancle_select_status();

    axis_status = 0;
    page_status = 0;
    pagestatus = AXIS1_PAGE1;
    axis_change_response();


}

void AxiaJonintWidget::axis2_parameter_slot()
{
    axis_save_response();
    axis_cancle_select_status();

    axis_status = 1;
    page_status = 0;
    pagestatus = AXIS2_PAGE1;
    axis_change_response();
}

void AxiaJonintWidget::axis3_parameter_slot()
{
    axis_save_response();
    axis_cancle_select_status();

    axis_status = 2;
    page_status = 0;
    pagestatus = AXIS3_PAGE1;
    axis_change_response();
}

void AxiaJonintWidget::axis4_parameter_slot()
{
    axis_save_response();
    axis_cancle_select_status();

    axis_status = 3;
    page_status = 0;
    pagestatus = AXIS4_PAGE1;
    axis_change_response();
}

void AxiaJonintWidget::axis5_parameter_slot()
{
    axis_save_response();
    axis_cancle_select_status();

    axis_status = 4;
    page_status = 0;
    pagestatus = AXIS5_PAGE1;
    axis_change_response();
}

void AxiaJonintWidget::axis6_parameter_slot()
{
    axis_save_response();
    axis_cancle_select_status();

    axis_status = 5;
    page_status = 0;
    pagestatus = AXIS6_PAGE1;
    axis_change_response();
}

void AxiaJonintWidget::axis7_parameter_slot()
{
    axis_save_response();
    axis_cancle_select_status();

    axis_status = 6;
    page_status = 0;
    pagestatus = AXIS7_PAGE1;
    axis_change_response();
}

void AxiaJonintWidget::axis8_parameter_slot()
{
    axis_save_response();
    axis_cancle_select_status();

    axis_status = 7;
    page_status = 0;
    pagestatus = AXIS8_PAGE1;
    axis_change_response();
}

void AxiaJonintWidget::save_slot()
{
    //根据当前页的状态保存当前页的值
    //保存成功后，进入下一页，不进行数据检查
    save_response();
    QMessageBox::information(NULL,"title","save success!",QMessageBox::Ok);
}

void AxiaJonintWidget::pageup_slot()
{
    //根据当前状态对当前页面进行“检查”“保存”操作
    //根据当前页进行翻页

    //根据状态加载数据
    //page_response();
    int i;
    switch(pagestatus)
    {
    case AXIS1_PAGE1:
        //跳转页面
        //获取保存值，将值显示

        break;
    case AXIS1_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        pagestatus=AXIS1_PAGE1;
        //提取指定的值---提取轴1页1的值
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,1,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");

        break;
    case AXIS1_PAGE3:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS1_PAGE2;
        //提取指定的值--提取轴1页2的值
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,1,i+8);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("2/3");
        break;
    case AXIS2_PAGE1:
        //跳转页面
        //获取保存值，将值显示

        break;
    case AXIS2_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        pagestatus=AXIS2_PAGE1;
        //提取指定的值---提取轴1页1的值
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,2,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");

        break;
    case AXIS2_PAGE3:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS2_PAGE2;
        //提取指定的值--提取轴1页2的值
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,2,i+8);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("2/3");
        break;
    case AXIS3_PAGE1:
        //跳转页面
        //获取保存值，将值显示

        break;
    case AXIS3_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        pagestatus=AXIS3_PAGE1;
        //提取指定的值---提取轴1页1的值
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,3,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");

        break;
    case AXIS3_PAGE3:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS3_PAGE2;
        //提取指定的值--提取轴1页2的值
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,3,i+8);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("2/3");
        break;
    case AXIS4_PAGE1:
        //跳转页面
        //获取保存值，将值显示

        break;
    case AXIS4_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        pagestatus=AXIS4_PAGE1;
        //提取指定的值---提取轴1页1的值
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,4,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");

        break;
    case AXIS4_PAGE3:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS4_PAGE2;
        //提取指定的值--提取轴1页2的值
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,4,i+8);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("2/3");
        break;
    case AXIS5_PAGE1:
        //跳转页面
        //获取保存值，将值显示

        break;
    case AXIS5_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        pagestatus=AXIS5_PAGE1;
        //提取指定的值---提取轴1页1的值
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,5,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");

        break;
    case AXIS5_PAGE3:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS5_PAGE2;
        //提取指定的值--提取轴1页2的值
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,5,i+8);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("2/3");
        break;
    case AXIS6_PAGE1:
        //跳转页面
        //获取保存值，将值显示

        break;
    case AXIS6_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        pagestatus=AXIS6_PAGE1;
        //提取指定的值---提取轴1页1的值
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,6,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");

        break;
    case AXIS6_PAGE3:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS6_PAGE2;
        //提取指定的值--提取轴1页2的值
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,6,i+8);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("2/3");
        break;
    case AXIS7_PAGE1:
        //跳转页面
        //获取保存值，将值显示

        break;
    case AXIS7_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        pagestatus=AXIS7_PAGE1;
        //提取指定的值---提取轴1页1的值
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,7,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");

        break;
    case AXIS7_PAGE3:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS7_PAGE2;
        //提取指定的值--提取轴1页2的值
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,7,i+8);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("2/3");
        break;
    case AXIS8_PAGE1:
        //跳转页面
        //获取保存值，将值显示

        break;
    case AXIS8_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        pagestatus=AXIS8_PAGE1;
        //提取指定的值---提取轴1页1的值
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,8,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");

        break;
    case AXIS8_PAGE3:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS8_PAGE2;
        //提取指定的值--提取轴1页2的值
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,8,i+8);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("2/3");
        break;
    default:return;
    }

}

void AxiaJonintWidget::pagedown_slot()
{
    int i;
    switch(pagestatus)
    {
    case AXIS1_PAGE1:
        //跳转页面
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS1_PAGE2;
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,1,i+8);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("2/3");

        //获取保存值，将值显示

        break;
    case AXIS1_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+16));
        }
        pagestatus=AXIS1_PAGE3;
        //提取指定的值
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,1,i+16);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("3/3");

        break;
    case AXIS1_PAGE3:
        break;
    case AXIS2_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS2_PAGE2;
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,2,i+8);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("2/3");
        break;
    case AXIS2_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+16));
        }
        pagestatus=AXIS2_PAGE3;
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,2,i+16);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("3/3");
        break;
    case AXIS2_PAGE3:

        break;
    case AXIS3_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS3_PAGE2;
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,3,i+8);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("2/3");
        break;
    case AXIS3_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+16));
        }
        pagestatus=AXIS3_PAGE3;
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,3,i+16);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("3/3");
        break;
    case AXIS3_PAGE3:

        break;
    case AXIS4_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS4_PAGE2;
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,4,i+8);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("2/3");
        break;
    case AXIS4_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+16));
        }
        pagestatus=AXIS4_PAGE3;
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,4,i+16);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("3/3");
        break;
    case AXIS4_PAGE3:

        break;
    case AXIS5_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS5_PAGE2;
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,5,i+8);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("2/3");
        break;
    case AXIS5_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+16));
        }
        pagestatus=AXIS5_PAGE3;
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,5,i+16);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("2/3");
        break;
    case AXIS5_PAGE3:

        break;
    case AXIS6_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS6_PAGE2;
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,6,i+8);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("2/3");
        break;
    case AXIS6_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS6_PAGE3;
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,6,i+16);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("2/3");
        break;
    case AXIS6_PAGE3:

        break;
    case AXIS7_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS7_PAGE2;
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,7,i+8);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("2/3");
        break;
    case AXIS7_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+16));
        }
        pagestatus=AXIS7_PAGE3;
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,7,i+16);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("3/3");
        break;
    case AXIS7_PAGE3:

        break;
    case AXIS8_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS8_PAGE2;
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,8,i+8);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("2/3");
        break;
    case AXIS8_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+16));
        }
        pagestatus=AXIS8_PAGE3;
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,8,i+16);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("3/3");
        break;
    case AXIS8_PAGE3:

        break;
    default:
        return;
    }
}

void AxiaJonintWidget::dataInit()
{
    axis_response();
}

void AxiaJonintWidget::axis_response()
{
    int i;
    switch(pagestatus)
    {
    case AXIS1_PAGE1:
        //跳转页面
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[1]->setStyleSheet("background-color:rgb(0,238,118)");
        //加载轴1页1的数据
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,1,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        //获取保存值，将值显示

        break;
    case AXIS1_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[1]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,1,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS1_PAGE3:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[1]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,1,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        axis_button[1]->setStyleSheet("background-color:rgb(0,238,118)");
        label->setText("1/3");
        break;
    case AXIS2_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[2]->setStyleSheet("background-color:rgb(0,238,118)");
        //加载轴2页1的数据
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,2,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS2_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[2]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,2,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS2_PAGE3:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[2]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,2,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS3_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[3]->setStyleSheet("background-color:rgb(0,238,118)");
        //加载轴3页1的数据
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,3,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS3_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[3]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,3,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS3_PAGE3:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[3]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,3,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS4_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[4]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,4,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS4_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[4]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,4,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS4_PAGE3:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[4]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,4,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS5_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[5]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,5,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS5_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[5]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,5,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS5_PAGE3:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[5]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,5,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS6_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[6]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,6,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS6_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[6]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,6,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS6_PAGE3:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[6]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,6,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS7_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[7]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,7,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS7_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[7]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,7,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS7_PAGE3:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[7]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,7,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS8_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[8]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,8,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS8_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[8]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,8,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    case AXIS8_PAGE3:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        axis_button[8]->setStyleSheet("background-color:rgb(0,238,118)");
        for(i=0;i<8;++i)
        {
            systemparameterxml->readxml(0,8,i);
            variate_value[i]->setText(systemparameterxml->paremeter_value);
        }
        label->setText("1/3");
        break;
    default:
        return;
    }
}

void AxiaJonintWidget::axis_save_response()
{

}

void AxiaJonintWidget::axis_change_response()
{
    axis_response();
}

void AxiaJonintWidget::axis_cancle_select_status()
{
    switch(pagestatus)
    {
    case AXIS1_PAGE1:
        axis_button[1]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS1_PAGE2:
        axis_button[1]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS1_PAGE3:
        axis_button[1]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS2_PAGE1:
        axis_button[2]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS2_PAGE2:
        axis_button[2]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS2_PAGE3:
        axis_button[2]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS3_PAGE1:
        axis_button[3]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS3_PAGE2:
        axis_button[3]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS3_PAGE3:
        axis_button[3]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS4_PAGE1:
        axis_button[4]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS4_PAGE2:
        axis_button[4]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS4_PAGE3:
        axis_button[4]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS5_PAGE1:
        axis_button[5]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS5_PAGE2:
        axis_button[5]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS5_PAGE3:
        axis_button[5]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS6_PAGE1:
        axis_button[6]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS6_PAGE2:
        axis_button[6]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS6_PAGE3:
        axis_button[6]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS7_PAGE1:
        axis_button[7]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS7_PAGE2:
        axis_button[7]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS7_PAGE3:
        axis_button[7]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS8_PAGE1:
        axis_button[8]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS8_PAGE2:
        axis_button[8]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS8_PAGE3:
        axis_button[8]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    default:
        return;
    }
}

void AxiaJonintWidget::page_response()
{

}

void AxiaJonintWidget::page_save_response()
{

}

void AxiaJonintWidget::page_change_response()
{

}

void AxiaJonintWidget::save_response()
{
    qlonglong s1[][4] = {0};
    qlonglong (*s)[4];
    s=s1;
    double buf1[][8] = {0.0};
    double (*buf)[8];
    buf=buf1;

    int i;
    switch(pagestatus)
    {
    case AXIS1_PAGE1:  //保存轴1页1的值--获取轴1页1的值，将值写入文件
        //require_page_value();
        //add_robot_param 20180321
        CTRL_SetJointPositiveLimit(variate_value[0]->text().toDouble(),1);
        CTRL_SetJointNegativeLimit(variate_value[1]->text().toDouble(),1);
        CTRL_SetJointMaxVelocity(variate_value[2]->text().toDouble(),1);
        CTRL_SetJointMaxAcc(variate_value[3]->text().toDouble(),1);
        CTRL_SetReductionRate(variate_value[4]->text().toLongLong(),variate_value[5]->text().toLongLong(),1);

        CTRL_GetJointPositiveLimit(buf[0],1);
        CTRL_GetJointNegativeLimit(buf[1],1);
        CTRL_GetJointMaxVelocity(buf[2],1);
        CTRL_GetJointMaxAcc(buf[3],1);
        CTRL_GetReductionRate(s[0],s[1],1);

        qDebug()<<variate_value[0]->text().toDouble();
        qDebug()<<*buf[0];
        qDebug()<<variate_value[1]->text().toDouble();
        qDebug()<<*buf[1];
        qDebug()<<variate_value[2]->text().toDouble();
        qDebug()<<*buf[2];
        qDebug()<<variate_value[3]->text().toDouble();
        qDebug()<<*buf[3];
        qDebug()<<variate_value[4]->text().toDouble();
        qDebug()<<*s[0];
        qDebug()<<variate_value[5]->text().toDouble();
        qDebug()<<*s[1];


//        if(*buf[0]==variate_value[0]->text().toDouble()&&
//                *buf[1]==variate_value[1]->text().toDouble()&&
//                *buf[2]==variate_value[2]->text().toDouble()&&
//                *buf[3]==variate_value[3]->text().toDouble()&&
//                *s[0]==variate_value[4]->text().toLongLong()&&
//                *s[1]==variate_value[5]->text().toLongLong())
//        {
            for(i=0;i<8;++i)
            {
                //write_page_value();
                systemparameterxml->writexml(0,1,i,variate_value[i]->text());
            }
//        }
//        else
//        {
//            //QMessageBox::warning(this,"warning","save failed!",QMessageBox::Ok,QMessageBox::Ok);
//        }
        break;
    case AXIS1_PAGE2:
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,1,i+8,variate_value[i]->text());
        }
        break;
    case AXIS1_PAGE3:
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,1,i+16,variate_value[i]->text());
        }
        break;
    case AXIS2_PAGE1:
        i=2;
        CTRL_SetJointPositiveLimit(variate_value[0]->text().toDouble(),i);
        CTRL_SetJointNegativeLimit(variate_value[1]->text().toDouble(),i);
        CTRL_SetJointMaxVelocity(variate_value[2]->text().toDouble(),i);
        CTRL_SetJointMaxAcc(variate_value[3]->text().toDouble(),i);
        CTRL_SetReductionRate(variate_value[4]->text().toLongLong(),variate_value[5]->text().toLongLong(),i);

        CTRL_GetJointPositiveLimit(buf[0],i);
        CTRL_GetJointNegativeLimit(buf[1],i);
        CTRL_GetJointMaxVelocity(buf[2],i);
        CTRL_GetJointMaxAcc(buf[3],i);
        CTRL_GetReductionRate(s[0],s[1],i);

        qDebug()<<variate_value[0]->text().toDouble();
        qDebug()<<*buf[0];
        qDebug()<<variate_value[1]->text().toDouble();
        qDebug()<<*buf[1];
        qDebug()<<variate_value[2]->text().toDouble();
        qDebug()<<*buf[2];
        qDebug()<<variate_value[3]->text().toDouble();
        qDebug()<<*buf[3];
        qDebug()<<variate_value[4]->text().toDouble();
        qDebug()<<*s[0];
        qDebug()<<variate_value[5]->text().toDouble();
        qDebug()<<*s[1];

        for(i=0;i<8;++i)
        {
            systemparameterxml->writexml(0,2,i,variate_value[i]->text());
        }
        break;
    case AXIS2_PAGE2:
        for(i=0;i<8;++i)
        {
            systemparameterxml->writexml(0,2,i+8,variate_value[i]->text());
        }
        break;
    case AXIS2_PAGE3:
        for(i=0;i<8;++i)
        {
            systemparameterxml->writexml(0,2,i+16,variate_value[i]->text());
        }
        break;
    case AXIS3_PAGE1:  //保存轴1页1的值--获取轴1页1的值，将值写入文件
        //require_page_value();
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,3,i,variate_value[i]->text());
        }
        break;
    case AXIS3_PAGE2:
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,3,i+8,variate_value[i]->text());
        }
        break;
    case AXIS3_PAGE3:
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,3,i+16,variate_value[i]->text());
        }
        break;
    case AXIS4_PAGE1:  //保存轴1页1的值--获取轴1页1的值，将值写入文件
        //require_page_value();
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,4,i,variate_value[i]->text());
        }
        break;
    case AXIS4_PAGE2:
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,4,i+8,variate_value[i]->text());
        }
        break;
    case AXIS4_PAGE3:
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,4,i+16,variate_value[i]->text());
        }
        break;
    case AXIS5_PAGE1:  //保存轴1页1的值--获取轴1页1的值，将值写入文件
        //require_page_value();
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,5,i,variate_value[i]->text());
        }
        break;
    case AXIS5_PAGE2:
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,5,i+8,variate_value[i]->text());
        }
        break;
    case AXIS5_PAGE3:
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,5,i+16,variate_value[i]->text());
        }
        break;
    case AXIS6_PAGE1:  //保存轴1页1的值--获取轴1页1的值，将值写入文件
        //require_page_value();
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,6,i,variate_value[i]->text());
        }
        break;
    case AXIS6_PAGE2:
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,6,i+8,variate_value[i]->text());
        }
        break;
    case AXIS6_PAGE3:
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,6,i+16,variate_value[i]->text());
        }
        break;
    case AXIS7_PAGE1:  //保存轴1页1的值--获取轴1页1的值，将值写入文件
        //require_page_value();
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,7,i,variate_value[i]->text());
        }
        break;
    case AXIS7_PAGE2:
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,7,i+8,variate_value[i]->text());
        }
        break;
    case AXIS7_PAGE3:
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,7,i+16,variate_value[i]->text());
        }
        break;
    case AXIS8_PAGE1:  //保存轴1页1的值--获取轴1页1的值，将值写入文件
        //require_page_value();
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,8,i,variate_value[i]->text());
        }
        break;
    case AXIS8_PAGE2:
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,8,i+8,variate_value[i]->text());
        }
        break;
    case AXIS8_PAGE3:
        for(i=0;i<8;++i)
        {
            //write_page_value();
            systemparameterxml->writexml(0,8,i+16,variate_value[i]->text());
        }
        break;
    default:return;
    }

}

void AxiaJonintWidget::robot_data_init()
{
    QString str1,str2;
    signed long long s1[][4]={0};//{0.0};
    signed long long (*s)[4];
    s=s1;

    int i;
//    double buf1[8]={0};
//    double *buf[8]={0};
    //*buf = buf1;
    double buf1[][8] = {0.0};
    double (*buf)[8];
    buf=buf1;

    for(i=1;i<7;++i)
    {
        systemparameterxml->readxml(0,i,0);
        qDebug()<<systemparameterxml->paremeter_value<<"sss";
        CTRL_SetJointPositiveLimit(systemparameterxml->paremeter_value.toDouble(),i);
        systemparameterxml->readxml(0,i,1);
        CTRL_SetJointNegativeLimit(systemparameterxml->paremeter_value.toDouble(),i);
        systemparameterxml->readxml(0,i,2);
        qDebug()<<systemparameterxml->paremeter_value;
        CTRL_SetJointMaxVelocity(systemparameterxml->paremeter_value.toDouble(),i);
        systemparameterxml->readxml(0,i,3);
        CTRL_SetJointMaxAcc(systemparameterxml->paremeter_value.toDouble(),i);
        systemparameterxml->readxml(0,i,4);
        str1=systemparameterxml->paremeter_value;
        systemparameterxml->readxml(0,i,5);
        str2=systemparameterxml->paremeter_value;
        CTRL_SetReductionRate(str1.toLongLong(),str2.toLongLong(),i);
        qDebug()<<str1<<str2
               <<str1.toLongLong()<<str1.toLongLong()<<"aa";
    }

    //qDebug()<<"longlogn";
    CTRL_GetJointPositiveLimit(buf[0],1);
    CTRL_GetJointNegativeLimit(buf[1],1);
    CTRL_GetJointMaxVelocity(buf[2],1);
    CTRL_GetJointMaxAcc(buf[3],1);
    //qDebug()<<"ddddd";
    CTRL_GetReductionRate(s[0],s[1],1);

    for(i=0;i<4;++i)
    {
        variate_value[i]->setText(QString::number(*buf[i],10,4));
        qDebug()<<*buf[i];
    }

    variate_value[4]->setText(QString::number(*s[0],10));
    variate_value[5]->setText(QString::number(*s[1],10));
}














