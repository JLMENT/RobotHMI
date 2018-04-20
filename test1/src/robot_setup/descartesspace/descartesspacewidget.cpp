#include "descartesspacewidget.h"
#include <QDebug>

QSettings settings("config.ini",QSettings::IniFormat);


DescartesSpaceWidget::DescartesSpaceWidget(QWidget *parent)
    : QWidget(parent)
{
    pagestatus = AXIS1_PAGE1;

    createIni();

    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->setMinimumSize(100,100);
    axis_title = new QLineEdit(tr("笛卡尔空间参数设置"),this);
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


    //list1<<"Axis(1~8)"<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8";
    list1<<"Axis(1~6)"<<"X"<<"Y"<<"Z"<<"A"<<"B"<<"C"<<"7"<<"8";
    list2<<"笛卡尔运动下线"<<"笛卡尔运动下限偏置"<<"笛卡尔运动上限"<<"笛卡尔运动上限偏置"
        <<"笛卡尔运动速度上限(JOG)"<<"笛卡尔运动加减速度(JOG)"<<"笛卡尔运动速度上限(MOVP)"<<"笛卡尔运动加速度(MOVP)"
       <<"page2"<<"1"<<"1"<<"1"<<"1"<<"1"<<"1"<<"1"
        <<"1"<<"1"<<"1"<<"1"<<"1"<<"1"<<"1"<<"page3";
//    list2<<"关节运动下线"<<"关节运动下限偏置"<<"关节运上限"<<"关节运动上限偏置"
//        <<"关节运动速度上限（JOG）"<<"关节运动加减速度（JOG）"<<"关节运动速度上限(MOVJ)"
//       <<"关节运动加速度（MOVJ）"<<"page2"<<"1"<<"1"<<"1"<<"1"<<"1"<<"1"<<"1"
//         <<"1"<<"1"<<"1"<<"1"<<"1"<<"1"<<"1"<<"page3";
    list3<<"0.1"<<"0.0"<<"0.0"<<"0.0"<<"0.0"<<"0.0"<<"0.0"<<"0.0"
           <<"0.2"<<"0.0"<<"0.0"<<"0.0"<<"0.0"<<"0.0"<<"0.0"<<"0.0"
             <<"0.3"<<"0.0"<<"0.0"<<"0.0"<<"0.0"<<"0.0"<<"0.0"<<"0.0";
    list4<<"Save"<<""<<"PageUp"<<"PageDown"<<"load"<<"remove";
    int i;
    vb1 = new QVBoxLayout(this);
    hb1 = new QHBoxLayout(this);
    hb2 = new QHBoxLayout(this);
    gb1 = new QGridLayout(this);
    for(i=0;i<7;++i)
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
    for(i=1;i<7;++i)
    {
        hb1->setStretch(i,1);
    }
    hb1->setStretchFactor(axis_button[0],2);
    for(i=1;i<7;++i)
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

    variate_value[0]->setText(settings.value("descartesspace1/笛卡尔运动下限",0).toString());
    variate_value[1]->setText(settings.value("descartesspace1/descartesminoffset",0).toString());
    variate_value[2]->setText(settings.value("descartesspace1/descartesmax",0).toString());
    variate_value[3]->setText(settings.value("descartesspace1/descartesmaxoffset",0).toString());
    variate_value[4]->setText(settings.value("descartesspace1/velocitymax",0).toString());
    variate_value[5]->setText(settings.value("descartesspace1/addsubtractvelocity",0).toString());
    variate_value[6]->setText(settings.value("descartesspace1/velocitymaxmovp",0).toString());
    variate_value[7]->setText(settings.value("descartesspace1/addsubtractvelocitymovp",0).toString());

    gb1->setMargin(0);
    gb1->setSpacing(0);

    label = new QLabel("(1/3)",this);
    label->setAlignment(Qt::AlignCenter);
    for(i=0;i<6;++i)
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
    connect(operate[0],SIGNAL(clicked()),this,SLOT(save_slot()));
    connect(operate[2],SIGNAL(clicked()),this,SLOT(pageup_slot()));
    connect(operate[3],SIGNAL(clicked()),this,SLOT(pagedown_slot()));
    connect(operate[4],SIGNAL(clicked()),this,SLOT(load_slot()));
    connect(operate[5],SIGNAL(clicked()),this,SLOT(remove_slot()));

    descartes_data_init();
}

DescartesSpaceWidget::~DescartesSpaceWidget()
{

}

void DescartesSpaceWidget::axis1_parameter_slot()
{
    axis_cancle_select_status();
    pagestatus = AXIS1_PAGE1;
    axis_change_response();
}

void DescartesSpaceWidget::axis2_parameter_slot()
{
    axis_cancle_select_status();
    pagestatus = AXIS2_PAGE1;
    axis_change_response();
}

void DescartesSpaceWidget::axis3_parameter_slot()
{
    axis_cancle_select_status();
    pagestatus = AXIS3_PAGE1;
    axis_change_response();
}

void DescartesSpaceWidget::axis4_parameter_slot()
{
    axis_cancle_select_status();
    pagestatus = AXIS4_PAGE1;
    axis_change_response();
}

void DescartesSpaceWidget::axis5_parameter_slot()
{
    axis_cancle_select_status();
    pagestatus = AXIS5_PAGE1;
    axis_change_response();
}

void DescartesSpaceWidget::axis6_parameter_slot()
{
    axis_cancle_select_status();
    pagestatus = AXIS6_PAGE1;
    axis_change_response();
}

void DescartesSpaceWidget::save_slot()
{
    switch(pagestatus)
    {
    case AXIS1_PAGE1:


        CTRL_SetLinearMaxVelocity(variate_value[0]->text().toDouble());
        CTRL_SetLinearMoveAcc(variate_value[1]->text().toDouble());
        CTRL_SetRotateMoveVelocity(variate_value[2]->text().toDouble());
        CTRL_SetRotateMoveAcc(variate_value[3]->text().toDouble());
        CTRL_SetLinearPositiveLimit(variate_value[4]->text().toDouble(),1);
        CTRL_SetLinearNegativeLimit(variate_value[5]->text().toDouble(),1);


        settings.setValue("descartesspace1/笛卡尔运动下限",variate_value[0]->text());
        settings.setValue("descartesspace1/descartesminoffset",variate_value[1]->text());
        settings.setValue("descartesspace1/descartesmax",variate_value[2]->text());
        settings.setValue("descartesspace1/descartesmaxoffset",variate_value[3]->text());
        settings.setValue("descartesspace1/velocitymax",variate_value[4]->text());
        settings.setValue("descartesspace1/addsubtractvelocity",variate_value[5]->text());
        settings.setValue("descartesspace1/velocitymaxmovp",variate_value[6]->text());
        settings.setValue("descartesspace1/addsubtractvelocitymovp",variate_value[7]->text());
        break;
    case AXIS1_PAGE2:
        settings.setValue("descartesspace1/add1",variate_value[0]->text());
        settings.setValue("descartesspace1/add2",variate_value[1]->text());
        settings.setValue("descartesspace1/add3",variate_value[2]->text());
        settings.setValue("descartesspace1/add4",variate_value[3]->text());
        settings.setValue("descartesspace1/add5",variate_value[4]->text());
        settings.setValue("descartesspace1/add6",variate_value[5]->text());
        settings.setValue("descartesspace1/add7",variate_value[6]->text());
        settings.setValue("descartesspace1/add8",variate_value[7]->text());
        break;
    case AXIS2_PAGE1:
        settings.setValue("descartesspace2/笛卡尔运动下限",variate_value[0]->text());
        settings.setValue("descartesspace2/descartesminoffset",variate_value[1]->text());
        settings.setValue("descartesspace2/descartesmax",variate_value[2]->text());
        settings.setValue("descartesspace2/descartesmaxoffset",variate_value[3]->text());
        settings.setValue("descartesspace2/velocitymax",variate_value[4]->text());
        settings.setValue("descartesspace2/addsubtractvelocity",variate_value[5]->text());
        settings.setValue("descartesspace2/velocitymaxmovp",variate_value[6]->text());
        settings.setValue("descartesspace2/addsubtractvelocitymovp",variate_value[7]->text());
        break;
    case AXIS2_PAGE2:
        settings.setValue("descartesspace2/add1",variate_value[0]->text());
        settings.setValue("descartesspace2/add2",variate_value[1]->text());
        settings.setValue("descartesspace2/add3",variate_value[2]->text());
        settings.setValue("descartesspace2/add4",variate_value[3]->text());
        settings.setValue("descartesspace2/add5",variate_value[4]->text());
        settings.setValue("descartesspace2/add6",variate_value[5]->text());
        settings.setValue("descartesspace2/add7",variate_value[6]->text());
        settings.setValue("descartesspace2/add8",variate_value[7]->text());
        break;
    case AXIS3_PAGE1:
        settings.setValue("descartesspace3/笛卡尔运动下限",variate_value[0]->text());
        settings.setValue("descartesspace3/descartesminoffset",variate_value[1]->text());
        settings.setValue("descartesspace3/descartesmax",variate_value[2]->text());
        settings.setValue("descartesspace3/descartesmaxoffset",variate_value[3]->text());
        settings.setValue("descartesspace3/velocitymax",variate_value[4]->text());
        settings.setValue("descartesspace3/addsubtractvelocity",variate_value[5]->text());
        settings.setValue("descartesspace3/velocitymaxmovp",variate_value[6]->text());
        settings.setValue("descartesspace3/addsubtractvelocitymovp",variate_value[7]->text());
        break;
    case AXIS3_PAGE2:
        for(int i=0;i<8;++i)
        {
            settings.setValue("descartesspace3/add"+QString::number(i+1,10),variate_value[i]->text());
        }
        break;
    case AXIS4_PAGE1:
        settings.setValue("descartesspace4/笛卡尔运动下限",variate_value[0]->text());
        settings.setValue("descartesspace4/descartesminoffset",variate_value[1]->text());
        settings.setValue("descartesspace4/descartesmax",variate_value[2]->text());
        settings.setValue("descartesspace4/descartesmaxoffset",variate_value[3]->text());
        settings.setValue("descartesspace4/velocitymax",variate_value[4]->text());
        settings.setValue("descartesspace4/addsubtractvelocity",variate_value[5]->text());
        settings.setValue("descartesspace4/velocitymaxmovp",variate_value[6]->text());
        settings.setValue("descartesspace4/addsubtractvelocitymovp",variate_value[7]->text());
        break;
    case AXIS4_PAGE2:
        for(int i=0;i<8;++i)
        {
            settings.setValue("descartesspace4/add"+QString::number(i+1,10),variate_value[i]->text());
        }
        break;
    case AXIS5_PAGE1:
        settings.setValue("descartesspace5/笛卡尔运动下限",variate_value[0]->text());
        settings.setValue("descartesspace5/descartesminoffset",variate_value[1]->text());
        settings.setValue("descartesspace5/descartesmax",variate_value[2]->text());
        settings.setValue("descartesspace5/descartesmaxoffset",variate_value[3]->text());
        settings.setValue("descartesspace5/velocitymax",variate_value[4]->text());
        settings.setValue("descartesspace5/addsubtractvelocity",variate_value[5]->text());
        settings.setValue("descartesspace5/velocitymaxmovp",variate_value[6]->text());
        settings.setValue("descartesspace5/addsubtractvelocitymovp",variate_value[7]->text());
        break;
    case AXIS5_PAGE2:
        for(int i=0;i<8;++i)
        {
            settings.setValue("descartesspace5/add"+QString::number(i+1,10),variate_value[i]->text());
        }
        break;
    case AXIS6_PAGE1:
        settings.setValue("descartesspace6/笛卡尔运动下限",variate_value[0]->text());
        settings.setValue("descartesspace6/descartesminoffset",variate_value[1]->text());
        settings.setValue("descartesspace6/descartesmax",variate_value[2]->text());
        settings.setValue("descartesspace6/descartesmaxoffset",variate_value[3]->text());
        settings.setValue("descartesspace6/velocitymax",variate_value[4]->text());
        settings.setValue("descartesspace6/addsubtractvelocity",variate_value[5]->text());
        settings.setValue("descartesspace6/velocitymaxmovp",variate_value[6]->text());
        settings.setValue("descartesspace6/addsubtractvelocitymovp",variate_value[7]->text());
        break;
    case AXIS6_PAGE2:
        for(int i=0;i<8;++i)
        {
            settings.setValue("descartesspace6/add"+QString::number(i+1,10),variate_value[i]->text());
        }
        break;
    default:
        return;
    }
}

void DescartesSpaceWidget::pageup_slot()
{
    int i;
    switch(pagestatus)
    {
    case AXIS1_PAGE1:
        break;
    case AXIS1_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        pagestatus=AXIS1_PAGE1;
//        for(i=0;i<8;++i)
//        {
////            systemparameterxml->readxml(0,1,i);
////            variate_value[i]->setText(systemparameterxml->paremeter_value);
//        }

        variate_value[0]->setText(settings.value("descartesspace1/笛卡尔运动下限",0).toString());
        variate_value[1]->setText(settings.value("descartesspace1/descartesminoffset",0).toString());
        variate_value[2]->setText(settings.value("descartesspace1/descartesmax",0).toString());
        variate_value[3]->setText(settings.value("descartesspace1/descartesmaxoffset",0).toString());
        variate_value[4]->setText(settings.value("descartesspace1/velocitymax",0).toString());
        variate_value[5]->setText(settings.value("descartesspace1/addsubtractvelocity",0).toString());
        variate_value[6]->setText(settings.value("descartesspace1/velocitymaxmovp",0).toString());
        variate_value[7]->setText(settings.value("descartesspace1/addsubtractvelocitymovp",0).toString());


        label->setText("1/2");

        break;
    case AXIS2_PAGE1:
        break;
    case AXIS2_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        pagestatus=AXIS2_PAGE1;
//        for(i=0;i<8;++i)
//        {
////            systemparameterxml->readxml(0,2,i);
////            variate_value[i]->setText(systemparameterxml->paremeter_value);
//        }
        variate_value[0]->setText(settings.value("descartesspace2/笛卡尔运动下限",0).toString());
        variate_value[1]->setText(settings.value("descartesspace2/descartesminoffset",0).toString());
        variate_value[2]->setText(settings.value("descartesspace2/descartesmax",0).toString());
        variate_value[3]->setText(settings.value("descartesspace2/descartesmaxoffset",0).toString());
        variate_value[4]->setText(settings.value("descartesspace2/velocitymax",0).toString());
        variate_value[5]->setText(settings.value("descartesspace2/addsubtractvelocity",0).toString());
        variate_value[6]->setText(settings.value("descartesspace2/velocitymaxmovp",0).toString());
        variate_value[7]->setText(settings.value("descartesspace2/addsubtractvelocitymovp",0).toString());
        label->setText("1/2");

        break;
    case AXIS3_PAGE1:
        break;
    case AXIS3_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        pagestatus=AXIS3_PAGE1;
//        for(i=0;i<8;++i)
//        {
////            systemparameterxml->readxml(0,3,i);
////            variate_value[i]->setText(systemparameterxml->paremeter_value);
//        }

        variate_value[0]->setText(settings.value("descartesspace3/笛卡尔运动下限",0).toString());
        variate_value[1]->setText(settings.value("descartesspace3/descartesminoffset",0).toString());
        variate_value[2]->setText(settings.value("descartesspace3/descartesmax",0).toString());
        variate_value[3]->setText(settings.value("descartesspace3/descartesmaxoffset",0).toString());
        variate_value[4]->setText(settings.value("descartesspace3/velocitymax",0).toString());
        variate_value[5]->setText(settings.value("descartesspace3/addsubtractvelocity",0).toString());
        variate_value[6]->setText(settings.value("descartesspace3/velocitymaxmovp",0).toString());
        variate_value[7]->setText(settings.value("descartesspace3/addsubtractvelocitymovp",0).toString());

        label->setText("1/2");

        break;
    case AXIS4_PAGE1:
        break;
    case AXIS4_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        pagestatus=AXIS4_PAGE1;
//        for(i=0;i<8;++i)
//        {
////            systemparameterxml->readxml(0,4,i);
////            variate_value[i]->setText(systemparameterxml->paremeter_value);
//        }

        variate_value[0]->setText(settings.value("descartesspace4/笛卡尔运动下限",0).toString());
        variate_value[1]->setText(settings.value("descartesspace4/descartesminoffset",0).toString());
        variate_value[2]->setText(settings.value("descartesspace4/descartesmax",0).toString());
        variate_value[3]->setText(settings.value("descartesspace4/descartesmaxoffset",0).toString());
        variate_value[4]->setText(settings.value("descartesspace4/velocitymax",0).toString());
        variate_value[5]->setText(settings.value("descartesspace4/addsubtractvelocity",0).toString());
        variate_value[6]->setText(settings.value("descartesspace4/velocitymaxmovp",0).toString());
        variate_value[7]->setText(settings.value("descartesspace4/addsubtractvelocitymovp",0).toString());

        label->setText("1/2");
        break;
    case AXIS5_PAGE1:
        break;
    case AXIS5_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        pagestatus=AXIS5_PAGE1;
//        for(i=0;i<8;++i)
//        {
////            systemparameterxml->readxml(0,5,i);
////            variate_value[i]->setText(systemparameterxml->paremeter_value);
//        }

        variate_value[0]->setText(settings.value("descartesspace5/笛卡尔运动下限",0).toString());
        variate_value[1]->setText(settings.value("descartesspace5/descartesminoffset",0).toString());
        variate_value[2]->setText(settings.value("descartesspace5/descartesmax",0).toString());
        variate_value[3]->setText(settings.value("descartesspace5/descartesmaxoffset",0).toString());
        variate_value[4]->setText(settings.value("descartesspace5/velocitymax",0).toString());
        variate_value[5]->setText(settings.value("descartesspace5/addsubtractvelocity",0).toString());
        variate_value[6]->setText(settings.value("descartesspace5/velocitymaxmovp",0).toString());
        variate_value[7]->setText(settings.value("descartesspace5/addsubtractvelocitymovp",0).toString());

        label->setText("1/2");

        break;
    case AXIS6_PAGE1:
        break;
    case AXIS6_PAGE2:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i));
        }
        pagestatus=AXIS6_PAGE1;
//        for(i=0;i<8;++i)
//        {
////            systemparameterxml->readxml(0,6,i);
////            variate_value[i]->setText(systemparameterxml->paremeter_value);
//        }

        variate_value[0]->setText(settings.value("descartesspace6/笛卡尔运动下限",0).toString());
        variate_value[1]->setText(settings.value("descartesspace6/descartesminoffset",0).toString());
        variate_value[2]->setText(settings.value("descartesspace6/descartesmax",0).toString());
        variate_value[3]->setText(settings.value("descartesspace6/descartesmaxoffset",0).toString());
        variate_value[4]->setText(settings.value("descartesspace6/velocitymax",0).toString());
        variate_value[5]->setText(settings.value("descartesspace6/addsubtractvelocity",0).toString());
        variate_value[6]->setText(settings.value("descartesspace6/velocitymaxmovp",0).toString());
        variate_value[7]->setText(settings.value("descartesspace6/addsubtractvelocitymovp",0).toString());

        label->setText("1/2");
        break;
    default:return;
    }
}

void DescartesSpaceWidget::pagedown_slot()
{
    int i;
    switch(pagestatus)
    {
    case AXIS1_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS1_PAGE2;
//        for(i=0;i<8;++i)
//        {
////            systemparameterxml->readxml(0,1,i+8);
////            variate_value[i]->setText(systemparameterxml->paremeter_value);
//        }

        variate_value[0]->setText(settings.value("descartesspace1/add1",0).toString());
        variate_value[1]->setText(settings.value("descartesspace1/add2",0).toString());
        variate_value[2]->setText(settings.value("descartesspace1/add3",0).toString());
        variate_value[3]->setText(settings.value("descartesspace1/add4",0).toString());
        variate_value[4]->setText(settings.value("descartesspace1/add5",0).toString());
        variate_value[5]->setText(settings.value("descartesspace1/add6",0).toString());
        variate_value[6]->setText(settings.value("descartesspace1/add7",0).toString());
        variate_value[7]->setText(settings.value("descartesspace1/add8",0).toString());

        label->setText("2/2");
        break;
    case AXIS1_PAGE2:
        break;
    case AXIS2_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS2_PAGE2;
//        for(i=0;i<8;++i)
//        {
////            systemparameterxml->readxml(0,2,i+8);
////            variate_value[i]->setText(systemparameterxml->paremeter_value);
//        }

        variate_value[0]->setText(settings.value("descartesspace2/add1",0).toString());
        variate_value[1]->setText(settings.value("descartesspace2/add2",0).toString());
        variate_value[2]->setText(settings.value("descartesspace2/add3",0).toString());
        variate_value[3]->setText(settings.value("descartesspace2/add4",0).toString());
        variate_value[4]->setText(settings.value("descartesspace2/add5",0).toString());
        variate_value[5]->setText(settings.value("descartesspace2/add6",0).toString());
        variate_value[6]->setText(settings.value("descartesspace2/add7",0).toString());
        variate_value[7]->setText(settings.value("descartesspace2/add8",0).toString());

        label->setText("2/2");
        break;
    case AXIS2_PAGE2:
        break;
    case AXIS3_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS3_PAGE2;
//        for(i=0;i<8;++i)
//        {
////            systemparameterxml->readxml(0,3,i+8);
////            variate_value[i]->setText(systemparameterxml->paremeter_value);
//        }

        variate_value[0]->setText(settings.value("descartesspace3/add1",0).toString());
        variate_value[1]->setText(settings.value("descartesspace3/add2",0).toString());
        variate_value[2]->setText(settings.value("descartesspace3/add3",0).toString());
        variate_value[3]->setText(settings.value("descartesspace3/add4",0).toString());
        variate_value[4]->setText(settings.value("descartesspace3/add5",0).toString());
        variate_value[5]->setText(settings.value("descartesspace3/add6",0).toString());
        variate_value[6]->setText(settings.value("descartesspace3/add7",0).toString());
        variate_value[7]->setText(settings.value("descartesspace3/add8",0).toString());

        label->setText("2/2");
        break;
    case AXIS3_PAGE2:
        break;
    case AXIS4_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS4_PAGE2;
//        for(i=0;i<8;++i)
//        {
////            systemparameterxml->readxml(0,4,i+8);
////            variate_value[i]->setText(systemparameterxml->paremeter_value);
//        }

        variate_value[0]->setText(settings.value("descartesspace4/add1",0).toString());
        variate_value[1]->setText(settings.value("descartesspace4/add2",0).toString());
        variate_value[2]->setText(settings.value("descartesspace4/add3",0).toString());
        variate_value[3]->setText(settings.value("descartesspace4/add4",0).toString());
        variate_value[4]->setText(settings.value("descartesspace4/add5",0).toString());
        variate_value[5]->setText(settings.value("descartesspace4/add6",0).toString());
        variate_value[6]->setText(settings.value("descartesspace4/add7",0).toString());
        variate_value[7]->setText(settings.value("descartesspace4/add8",0).toString());

        label->setText("2/2");
        break;
    case AXIS4_PAGE2:
        break;
    case AXIS5_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS5_PAGE2;
//        for(i=0;i<8;++i)
//        {
////            systemparameterxml->readxml(0,5,i+8);
////            variate_value[i]->setText(systemparameterxml->paremeter_value);
//        }

        variate_value[0]->setText(settings.value("descartesspace5/add1",0).toString());
        variate_value[1]->setText(settings.value("descartesspace5/add2",0).toString());
        variate_value[2]->setText(settings.value("descartesspace5/add3",0).toString());
        variate_value[3]->setText(settings.value("descartesspace5/add4",0).toString());
        variate_value[4]->setText(settings.value("descartesspace5/add5",0).toString());
        variate_value[5]->setText(settings.value("descartesspace5/add6",0).toString());
        variate_value[6]->setText(settings.value("descartesspace5/add7",0).toString());
        variate_value[7]->setText(settings.value("descartesspace5/add8",0).toString());

        label->setText("2/2");
        break;
    case AXIS5_PAGE2:
        break;
    case AXIS6_PAGE1:
        for(i=0;i<8;++i)
        {
            variate[i]->setText(list2.at(i+8));
        }
        pagestatus=AXIS6_PAGE2;
//        for(i=0;i<8;++i)
//        {
////            systemparameterxml->readxml(0,6,i+8);
////            variate_value[i]->setText(systemparameterxml->paremeter_value);
//        }

        variate_value[0]->setText(settings.value("descartesspace6/add1",0).toString());
        variate_value[1]->setText(settings.value("descartesspace6/add2",0).toString());
        variate_value[2]->setText(settings.value("descartesspace6/add3",0).toString());
        variate_value[3]->setText(settings.value("descartesspace6/add4",0).toString());
        variate_value[4]->setText(settings.value("descartesspace6/add5",0).toString());
        variate_value[5]->setText(settings.value("descartesspace6/add6",0).toString());
        variate_value[6]->setText(settings.value("descartesspace6/add7",0).toString());
        variate_value[7]->setText(settings.value("descartesspace6/add8",0).toString());

        label->setText("2/2");
        break;
    case AXIS6_PAGE2:
        break;
    default:
        return;
    }
}

void DescartesSpaceWidget::load_slot()
{
    variate_value[0]->setText(settings.value("descartesspace1/笛卡尔运动下限",0).toString());
    variate_value[1]->setText(settings.value("descartesspace1/descartesminoffset",0).toString());
    variate_value[2]->setText(settings.value("descartesspace1/descartesmax",0).toString());
    variate_value[3]->setText(settings.value("descartesspace1/descartesmaxoffset",0).toString());
    variate_value[4]->setText(settings.value("descartesspace1/velocitymax",0).toString());
    variate_value[5]->setText(settings.value("descartesspace1/addsubtractvelocity",0).toString());
    variate_value[6]->setText(settings.value("descartesspace1/velocitymaxmovp",0).toString());
    variate_value[7]->setText(settings.value("descartesspace1/addsubtractvelocitymovp",0).toString());
}

void DescartesSpaceWidget::remove_slot()
{
    settings.remove("descartesspace1");
    settings.remove("descartesspace2");
    settings.remove("descartesspace3");
    settings.remove("descartesspace4");
    settings.remove("descartesspace5");
    settings.remove("descartesspace6");
}

void DescartesSpaceWidget::axis_cancle_select_status()
{
    switch(pagestatus)
    {
    case AXIS1_PAGE1:
        axis_button[1]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS1_PAGE2:
        axis_button[1]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS2_PAGE1:
        axis_button[2]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS2_PAGE2:
        axis_button[2]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS3_PAGE1:
        axis_button[3]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS3_PAGE2:
        axis_button[3]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS4_PAGE1:
        axis_button[4]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS4_PAGE2:
        axis_button[4]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS5_PAGE1:
        axis_button[5]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS5_PAGE2:
        axis_button[5]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS6_PAGE1:
        axis_button[6]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    case AXIS6_PAGE2:
        axis_button[6]->setStyleSheet("background-color:rgb(232,232,232)");
        break;
    default:
        return;
    }
}

void DescartesSpaceWidget::axis_change_response()
{
    switch(pagestatus)
    {
    case AXIS1_PAGE1:
        page_display(1);
        break;
    case AXIS2_PAGE1:
        page_display(2);
        break;
    case AXIS3_PAGE1:
        page_display(3);
        break;
    case AXIS4_PAGE1:
        page_display(4);
        break;
    case AXIS5_PAGE1:
        page_display(5);
        break;
    case AXIS6_PAGE1:
        page_display(6);
    default:
        return;
    }
}

void DescartesSpaceWidget::page_display(int num)//轴键、
{
    int i;
    for(i=0;i<8;++i)
    {
        variate[i]->setText(list2.at(i));
    }
    axis_button[num]->setStyleSheet("background-color:rgb(0,238,118)");
    label->setText("1/2");

        variate_value[0]->setText(settings.value("descartesspace"+QString::number(num,10)+"/笛卡尔运动下限",0).toString());
        variate_value[1]->setText(settings.value("descartesspace"+QString::number(num,10)+"/descartesminoffset",0).toString());
        variate_value[2]->setText(settings.value("descartesspace"+QString::number(num,10)+"/descartesmax",0).toString());
        variate_value[3]->setText(settings.value("descartesspace"+QString::number(num,10)+"/descartesmaxoffset",0).toString());
        variate_value[4]->setText(settings.value("descartesspace"+QString::number(num,10)+"/velocitymax",0).toString());
        variate_value[5]->setText(settings.value("descartesspace"+QString::number(num,10)+"/addsubtractvelocity",0).toString());
        variate_value[6]->setText(settings.value("descartesspace"+QString::number(num,10)+"/velocitymaxmovp",0).toString());
        variate_value[7]->setText(settings.value("descartesspace"+QString::number(num,10)+"/addsubtractvelocitymovp",0).toString());
}

void DescartesSpaceWidget::createIni()
{
    QSettings ss("config.ini",QSettings::IniFormat);
    if(settings.value("filesexist/exist",0).toString()!="yes")
    {
        ss.beginGroup("filesexist");
        ss.setValue("exist","yes");
        ss.endGroup();

        ss.beginGroup("descartesspace1");
        ss.setValue("笛卡尔运动下限",0);
        ss.setValue("descartesminoffset",0);
        ss.setValue("descartesmax",0);
        ss.setValue("descartesmaxoffset",0);
        ss.setValue("velocitymax",0);
        ss.setValue("addsubtractvelocity",0);
        ss.setValue("velocitymaxmovp",0);
        ss.setValue("addsubtractvelocitymovp",0);
        ss.setValue("add1",0);
        ss.setValue("add2",0);
        ss.setValue("add3",0);
        ss.setValue("add4",0);
        ss.setValue("add5",0);
        ss.setValue("add6",0);
        ss.setValue("add7",0);
        ss.setValue("add8",0);
        ss.endGroup();

        ss.beginGroup("descartesspace2");
        ss.setValue("笛卡尔运动下限",0);
        ss.setValue("descartesminoffset",0);
        ss.setValue("descartesmax",0);
        ss.setValue("descartesmaxoffset",0);
        ss.setValue("velocitymax",0);
        ss.setValue("addsubtractvelocity",0);
        ss.setValue("velocitymaxmovp",0);
        ss.setValue("addsubtractvelocitymovp",0);
        ss.setValue("add1",0);
        ss.setValue("add2",0);
        ss.setValue("add3",0);
        ss.setValue("add4",0);
        ss.setValue("add5",0);
        ss.setValue("add6",0);
        ss.setValue("add7",0);
        ss.setValue("add8",0);
        ss.endGroup();

        ss.beginGroup("descartesspace3");
        ss.setValue("笛卡尔运动下限",0);
        ss.setValue("descartesminoffset",0);
        ss.setValue("descartesmax",0);
        ss.setValue("descartesmaxoffset",0);
        ss.setValue("velocitymax",0);
        ss.setValue("addsubtractvelocity",0);
        ss.setValue("velocitymaxmovp",0);
        ss.setValue("addsubtractvelocitymovp",0);
        ss.setValue("add1",0);
        ss.setValue("add2",0);
        ss.setValue("add3",0);
        ss.setValue("add4",0);
        ss.setValue("add5",0);
        ss.setValue("add6",0);
        ss.setValue("add7",0);
        ss.setValue("add8",0);
        ss.endGroup();

        ss.beginGroup("descartesspace4");
        ss.setValue("笛卡尔运动下限",0);
        ss.setValue("descartesminoffset",0);
        ss.setValue("descartesmax",0);
        ss.setValue("descartesmaxoffset",0);
        ss.setValue("velocitymax",0);
        ss.setValue("addsubtractvelocity",0);
        ss.setValue("velocitymaxmovp",0);
        ss.setValue("addsubtractvelocitymovp",0);
        ss.setValue("add1",0);
        ss.setValue("add2",0);
        ss.setValue("add3",0);
        ss.setValue("add4",0);
        ss.setValue("add5",0);
        ss.setValue("add6",0);
        ss.setValue("add7",0);
        ss.setValue("add8",0);
        ss.endGroup();

        ss.beginGroup("descartesspace5");
        ss.setValue("笛卡尔运动下限",0);
        ss.setValue("descartesminoffset",0);
        ss.setValue("descartesmax",0);
        ss.setValue("descartesmaxoffset",0);
        ss.setValue("velocitymax",0);
        ss.setValue("addsubtractvelocity",0);
        ss.setValue("velocitymaxmovp",0);
        ss.setValue("addsubtractvelocitymovp",0);
        ss.setValue("add1",0);
        ss.setValue("add2",0);
        ss.setValue("add3",0);
        ss.setValue("add4",0);
        ss.setValue("add5",0);
        ss.setValue("add6",0);
        ss.setValue("add7",0);
        ss.setValue("add8",0);
        ss.endGroup();

        ss.beginGroup("descartesspace6");
        ss.setValue("笛卡尔运动下限",0);
        ss.setValue("descartesminoffset",0);
        ss.setValue("descartesmax",0);
        ss.setValue("descartesmaxoffset",0);
        ss.setValue("velocitymax",0);
        ss.setValue("addsubtractvelocity",0);
        ss.setValue("velocitymaxmovp",0);
        ss.setValue("addsubtractvelocitymovp",0);
        ss.setValue("add1",0);
        ss.setValue("add2",0);
        ss.setValue("add3",0);
        ss.setValue("add4",0);
        ss.setValue("add5",0);
        ss.setValue("add6",0);
        ss.setValue("add7",0);
        ss.setValue("add8",0);
        ss.endGroup();
    }

}

void DescartesSpaceWidget::readIni()
{

}


void DescartesSpaceWidget::descartes_data_init()
{

    //double *maxvelocity,*acc,*movevelocity,*moveacc,*positivelimit,*negativelimit;

    CTRL_SetLinearMaxVelocity(settings.value("descartesspace1/笛卡尔运动下限",0).toDouble());
    CTRL_SetLinearMoveAcc(settings.value("descartesspace1/descartesminoffset",0).toDouble());
    CTRL_SetRotateMoveVelocity(settings.value("descartesspace1/descartesmax",0).toDouble());
    CTRL_SetRotateMoveAcc(settings.value("descartesspace1/descartesmaxoffset",0).toDouble());

    //CTRL_GetLinearMaxVelocity(maxvelocity);
//    CTRL_GetLinearMoveAcc(acc);
//    CTRL_GetRotateMoveVelocity(movevelocity);
//    CTRL_GetRotateMoveAcc(moveacc);

//    qDebug()<<"ddddddddddddddddddddddddddddddddddddddddddddd";
//    qDebug()<<*maxvelocity<<*acc<<*movevelocity<<*moveacc;


    for(int i=1;i<7;++i)
    {
        qDebug()<<"sssssss";
        CTRL_SetLinearPositiveLimit(settings.value("descartesspace"+QString::number(i,10)+"/velocitymax",0).toDouble(),i);
        CTRL_SetLinearNegativeLimit(settings.value("descartesspace1"+QString::number(i,10)+"/addsubtractvelocity",0).toDouble(),i);

//        CTRL_GetLinearPositiveLimit(positivelimit,i);
//        CTRL_GetLinearNegativeLimit(negativelimit,i);

//        qDebug()<<*positivelimit<<*negativelimit;
    }



    ///////////////////error:add "get"corder ,HMI creash!

}




















