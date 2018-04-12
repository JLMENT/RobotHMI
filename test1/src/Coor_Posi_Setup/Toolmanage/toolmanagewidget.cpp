#include "toolmanagewidget.h"
#include <QDebug>
#include <QMessageBox>

ToolManageWidget::ToolManageWidget(QWidget *parent)
    : QWidget(parent)
{
    setGeometry(0,0,300,300);
    //this->setStyleSheet(QString::fromUtf8("border:2px solid red"));
    int i;
    keystyle = NO_KEY;
    QStringList coorlist,methodlist,recordlist,positionlist,operatelist;
    coorlist<<"0"<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9"<<"10";
    methodlist<<"4点法"<<"6点法"<<"3点法"<<"XY"<<"YZ"<<"ZX";
    recordlist<<"记录P1"<<"记录P2"<<"记录P3"<<"记录P4"<<"记录P5"<<"记录P6";
    positionlist<<"X:"<<"Y:"<<"Z:"<<"A:"<<"B:"<<"C:";
    operatelist<<"设置为当前"<<"清除"<<"计算";


    title_edit = new QLineEdit("工具管理",this);
    title_edit->setEnabled(false);
    title_edit->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //title_edit->setText("零位标定");
    title_edit->setStyleSheet("background-color:rgb(0,238,238)");
    title_edit->setAlignment(Qt::AlignCenter);
    QPalette palette;
    palette.setColor(QPalette::Text,Qt::white);
    title_edit->setPalette(palette);
    title_edit->setFont(QFont("Timers",28,QFont::Bold));

    for(i=0;i<6;++i)
    {
        method_btn[i] = new QPushButton(this);
        method_btn[i]->setMinimumSize(40,30);
        method_btn[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        method_btn[i]->setText(methodlist.at(i));
        if(i<3)
        {
            vb1->addWidget(method_btn[i]);
        }
        else
        {
            hb1->addWidget(method_btn[i]);
        }
    }
//    method_btn[2]->setStyleSheet("QPushButton{background-color:black;\
//                           color:white;border-radius:10px;border:2px groove gray;\
//                           border-style:outset;}"
//                           "QPushButton:hover{background-color:white;color:black;}"
//                           "QPushButton:pressed{background-color:rgb(85,170,255);\
//                           border-style:inset;}");
    vb1->addLayout(hb1);

    for(i=0;i<11;++i)
    {
        coor_btn[i] = new QPushButton(coorlist.at(i),this);
        coor_btn[i]->setMinimumSize(35,32);
        coor_btn[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        coor_btn[i]->setStyleSheet("background-color:rgb(255,250,250)");
        if(i>0)
        {
            hb2->addWidget(coor_btn[i]);
        }
    }
    hb2->setSpacing(0);
    for(i=0;i<14;++i)
    {
        position_edit[i] = new QLineEdit;
        position_edit[i]->setMinimumWidth(90);
        position_edit[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        position_label[i] = new QLineEdit;
        //position_label[i]->setMinimumWidth(30);
//        if(i!=0||i!=7){
//        position_label[i]->setMaximumWidth(30);
//        }
        position_label[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    }

    for(i=1;i<7;++i)
    {
        position_label[i]->setMaximumWidth(30);
        //position_edit[i-1]->setMaximumWidth(90);
    }
    for(i=8;i<14;++i)
    {
        position_label[i]->setMaximumWidth(30);
        //position_edit[i-2]->setMaximumWidth(90);
    }
    position_label[0]->setText("手动设置");
    position_label[7]->setText("被选中的TCS");



    for(i=0;i<7;++i)
    {
        manual_setting_btn[i] = new QPushButton(this);
//        manual_setting_btn[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        manual_setting_btn[i]->setFixedSize(QPixmap(":/toolimage/toolwrite.png").size());
        manual_setting_btn[i]->setStyleSheet("border-image:url(:/toolimage/toolwrite.png)");
        manual_setting_btn[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    }
    gd1->addWidget(position_label[0],0,0,1,4);
    position_label[0]->setEnabled(false);
    gd1->addWidget(manual_setting_btn[0],0,4,1,2);
    gd1->addWidget(position_label[7],0,6,1,4);
    position_label[7]->setEnabled(false);


    gd1->addWidget(position_label[1],1,0,1,1);
    position_label[1]->setEnabled(false);
    gd1->addWidget(position_edit[0],1,1,1,3);
    gd1->addWidget(manual_setting_btn[1],1,4,1,2);
    gd1->addWidget(position_label[8],1,6,1,1);
    gd1->addWidget(position_edit[6],1,7,1,3);
    position_label[8]->setEnabled(false);
    position_edit[6]->setEnabled(false);

    gd1->addWidget(position_label[2],2,0,1,1);
    position_label[2]->setEnabled(false);
    gd1->addWidget(position_edit[1],2,1,1,3);
    gd1->addWidget(manual_setting_btn[2],2,4,1,2);
    gd1->addWidget(position_label[9],2,6,1,1);
    gd1->addWidget(position_edit[7],2,7,1,3);
    position_label[9]->setEnabled(false);
    position_edit[7]->setEnabled(false);

    gd1->addWidget(position_label[3],3,0,1,1);
    position_label[3]->setEnabled(false);
    gd1->addWidget(position_edit[2],3,1,1,3);
    gd1->addWidget(manual_setting_btn[3],3,4,1,2);
    gd1->addWidget(position_label[10],3,6,1,1);
    gd1->addWidget(position_edit[8],3,7,1,3);
    position_label[10]->setEnabled(false);
    position_edit[8]->setEnabled(false);

    gd1->addWidget(position_label[4],4,0,1,1);
    position_label[4]->setEnabled(false);
    gd1->addWidget(position_edit[3],4,1,1,3);
    gd1->addWidget(manual_setting_btn[4],4,4,1,2);
    gd1->addWidget(position_label[11],4,6,1,1);
    gd1->addWidget(position_edit[9],4,7,1,3);
    position_label[11]->setEnabled(false);
    position_edit[9]->setEnabled(false);

    gd1->addWidget(position_label[5],5,0,1,1);
    position_label[5]->setEnabled(false);
    gd1->addWidget(position_edit[4],5,1,1,3);
    gd1->addWidget(manual_setting_btn[5],5,4,1,2);
    gd1->addWidget(position_label[12],5,6,1,1);
    gd1->addWidget(position_edit[10],5,7,1,3);
    position_label[12]->setEnabled(false);
    position_edit[10]->setEnabled(false);

    gd1->addWidget(position_label[6],6,0,1,1);
    position_label[6]->setEnabled(false);
    gd1->addWidget(position_edit[5],6,1,1,3);
    gd1->addWidget(manual_setting_btn[6],6,4,1,2);
    gd1->addWidget(position_label[13],6,6,1,1);
    gd1->addWidget(position_edit[11],6,7,1,3);
    position_label[13]->setEnabled(false);
    position_edit[11]->setEnabled(false);

    gd1->addWidget(position_edit[13],7,0,1,10);
    position_edit[13]->setEnabled(false);
    position_edit[13]->setText("当前使用的TCS的ID号：");

//    gd1->setColumnStretch(0,1);
//    gd1->setColumnStretch(1,3);
////    gd1->setColumnStretch(2,1);
////    gd1->setColumnStretch(3,1);
//    gd1->setColumnStretch(8,3);


    for(i=0;i<6;++i)
    {
        record_btn[i] = new QPushButton(recordlist.at(i),this);
        record_btn[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        vb2->addWidget(record_btn[i]);
    }

    for(i=0;i<3;++i)
    {
        operate_btn[i] = new QPushButton(operatelist.at(i),this);
        operate_btn[i]->setStyleSheet(btn_style1);
        operate_btn[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    }
///////////////////////////////////////////////////////////////
    //初始状态
    set_coorbtn_select_status(0);
    btn_disnable();
    for(i=0;i<11;++i)
    {
        configset->createIni("ToolCoordinate"+QString::number(i,10),8);//创建配置文件
        //num1保存注释
    }
    configset->createIni("ToolCoordinatecomment",2);//当前使用ID


    for(i=0;i<6;++i)
    {
        position_label[1+i]->setText(positionlist.at(i));
        position_label[8+i]->setText(positionlist.at(i));
        position_edit[i+6]->setText(ConfigSet::settrings.value("ToolCoordinate0/num"+QString::number(i+2,10),0).toString());
    }
    position_edit[12]->setText(ConfigSet::settrings.value("ToolCoordinate0/num"+QString::number(1,10),0).toString());
    position_edit[13]->setText("当前使用的TCS的ID号："+ConfigSet::settrings.value("ToolCoordinatecomment/num1",0).toString());

///////////////////////////////////////////////////////////////


    gd2->addLayout(gd1,0,0,8,2);
    gd2->addLayout(vb2,0,2,8,1);
    gd2->addWidget(operate_btn[0],8,0,1,1);
    gd2->addWidget(operate_btn[1],8,1,1,1);
    gd2->addWidget(operate_btn[2],8,2,1,1);
    gd2->setColumnStretch(0,2);
    gd2->setColumnStretch(1,1);
    gd2->setRowStretch(0,8);
    gd2->setRowStretch(1,1);


    hb3->addWidget(position_edit[12]);
    hb3->addWidget(coor_btn[0]);
    hb3->setStretch(0,9);
    hb3->setStretch(1,1);
    hb3->setSpacing(0);

    vb3->addLayout(hb2);
    vb3->addLayout(hb3);
    vb3->addLayout(gd2);
    vb3->setStretch(0,1);
    vb3->setStretch(1,1);
    vb3->setStretch(2,10);
    vb3->setSpacing(0);

    hb4->addLayout(vb1);
    hb4->addLayout(vb3);
    hb4->setSpacing(0);
    hb4->setStretch(0,1);
    hb4->setStretch(1,3);

    //hb4->setMargin(5);

    vb->addWidget(title_edit);
    vb->addLayout(hb4);
    vb->setStretch(0,1);
    vb->setStretch(1,11);

    connect(timer,SIGNAL(timeout()),this,SLOT(timeout_slot()));

    connect(method_btn[0],SIGNAL(clicked()),this,SLOT(four_method_slot()));
    connect(method_btn[1],SIGNAL(clicked()),this,SLOT(six_method_slot()));
    connect(method_btn[2],SIGNAL(clicked()),this,SLOT(three_method_slot()));
    connect(method_btn[3],SIGNAL(clicked()),this,SLOT(xy_plane_slot()));
    connect(method_btn[4],SIGNAL(clicked()),this,SLOT(yz_plane_slot()));
    connect(method_btn[5],SIGNAL(clicked()),this,SLOT(zx_plane_slot()));

    connect(coor_btn[0],SIGNAL(clicked()),this,SLOT(coor0_slot()));
    connect(coor_btn[1],SIGNAL(clicked()),this,SLOT(coor1_slot()));
    connect(coor_btn[2],SIGNAL(clicked()),this,SLOT(coor2_slot()));
    connect(coor_btn[3],SIGNAL(clicked()),this,SLOT(coor3_slot()));
    connect(coor_btn[4],SIGNAL(clicked()),this,SLOT(coor4_slot()));
    connect(coor_btn[5],SIGNAL(clicked()),this,SLOT(coor5_slot()));
    connect(coor_btn[6],SIGNAL(clicked()),this,SLOT(coor6_slot()));
    connect(coor_btn[7],SIGNAL(clicked()),this,SLOT(coor7_slot()));
    connect(coor_btn[8],SIGNAL(clicked()),this,SLOT(coor8_slot()));
    connect(coor_btn[9],SIGNAL(clicked()),this,SLOT(coor9_slot()));
    connect(coor_btn[10],SIGNAL(clicked()),this,SLOT(coor10_slot()));

    connect(record_btn[0],SIGNAL(pressed()),this,SLOT(record_p1_press_slot()));
    connect(record_btn[1],SIGNAL(pressed()),this,SLOT(record_p2_press_slot()));
    connect(record_btn[2],SIGNAL(pressed()),this,SLOT(record_p3_press_slot()));
    connect(record_btn[3],SIGNAL(pressed()),this,SLOT(record_p4_press_slot()));
    connect(record_btn[4],SIGNAL(pressed()),this,SLOT(record_p5_press_slot()));
    connect(record_btn[5],SIGNAL(pressed()),this,SLOT(record_p6_press_slot()));

    connect(record_btn[0],SIGNAL(released()),this,SLOT(record_p1_release_slot()));
    connect(record_btn[1],SIGNAL(released()),this,SLOT(record_p2_release_slot()));
    connect(record_btn[2],SIGNAL(released()),this,SLOT(record_p3_release_slot()));
    connect(record_btn[3],SIGNAL(released()),this,SLOT(record_p4_release_slot()));
    connect(record_btn[4],SIGNAL(released()),this,SLOT(record_p5_release_slot()));
    connect(record_btn[5],SIGNAL(released()),this,SLOT(record_p6_release_slot()));


    connect(operate_btn[0],SIGNAL(pressed()),this,SLOT(set_current_data_press_slot()));
    connect(operate_btn[1],SIGNAL(pressed()),this,SLOT(clear_current_data_press_slot()));
    connect(operate_btn[2],SIGNAL(pressed()),this,SLOT(calc_data_press_slot()));
    connect(operate_btn[0],SIGNAL(released()),this,SLOT(set_current_data_release_slot()));
    connect(operate_btn[1],SIGNAL(released()),this,SLOT(clear_current_data_release_slot()));
    connect(operate_btn[2],SIGNAL(released()),this,SLOT(calc_data_release_slot()));

    connect(manual_setting_btn[0],SIGNAL(pressed()),this,SLOT(manual_setup_all_slot()));
    connect(manual_setting_btn[1],SIGNAL(pressed()),this,SLOT(manual_setup_X_slot()));
    connect(manual_setting_btn[2],SIGNAL(pressed()),this,SLOT(manual_setup_Y_slot()));
    connect(manual_setting_btn[3],SIGNAL(pressed()),this,SLOT(manual_setup_Z_slot()));
    connect(manual_setting_btn[4],SIGNAL(pressed()),this,SLOT(manual_setup_A_slot()));
    connect(manual_setting_btn[5],SIGNAL(pressed()),this,SLOT(manual_setup_B_slot()));
    connect(manual_setting_btn[6],SIGNAL(pressed()),this,SLOT(manual_setup_C_slot()));

    this->setLayout(vb);



}

ToolManageWidget::~ToolManageWidget()
{

}

void ToolManageWidget::set_coorbtn_select_status(int index)
{
    for(int i=0;i<11;++i)
    {
        tool_buf[i]=false;
    }
    tool_buf[index]=true;
    coor_btn[index]->setStyleSheet("background-color:rgb(0,238,238);border-radius:4px;border:2px black;border-style:inset");
    for(int j=0;j<11;++j)
    {
        if(j!=index)
        {
            coor_btn[j]->setStyleSheet("background-color:rgb(250,250,250);border-radius:4px;border:0.5px black;border-style:outset");
        }
    }
}

void ToolManageWidget::btn_disnable()
{
    int i;
    for(i=0;i<6;++i)
    {
        method_btn[i]->setEnabled(false);
        //if(i<4)
        //{
            record_btn[i]->setEnabled(false);
            if(i<3)
            {
                operate_btn[i]->setEnabled(false);
            }
        //}
    }
}

void ToolManageWidget::btn_enable()
{
    int i;
    for(i=0;i<6;++i)
    {
        method_btn[i]->setEnabled(true);
        //if(i<4)
        //{
            record_btn[i]->setEnabled(true);
            if(i<3)
            {
                operate_btn[i]->setEnabled(true);
            }
        //}
    }
}

void ToolManageWidget::method_record_clear()
{
    int i;

    for(i=0;i<6;++i)
    {
        method_btn[i]->setStyleSheet(BTN_RELEASE_STYPE);
        //if(i<4)
        //{
            record_btn[i]->setStyleSheet(BTN_RELEASE_STYPE);
            if(i<3)
            {
//                operate_btn[i]->setStyleSheet(BTN_STYPE);
                method_buf[i] = false;
                plane_buf[i] = false;
            }
        //}
    }
}

void ToolManageWidget::menual_setup_assignment(int index)
{
    if(index!=0)
    {
        if(position_edit[index-1]->text()!=""&&position_edit[index-1]->text()!=" ")
        {
            position_edit[index+5]->setText(position_edit[index-1]->text());
        }
    }
    else
    {
        qDebug()<<"all";
        for(int i=0;i<6;i++)
        {
            position_edit[i+6]->setText(position_edit[i]->text());
        }
    }
}

void ToolManageWidget::load_position_data(int index)
{

    for(int i=0;i<6;++i)
    {
        position_edit[i+6]->setText(ConfigSet::settrings.value("ToolCoordinate"+QString::number(index,10)+"/num"+QString::number(i+2,10),0).toString());
    }
    position_edit[12]->setText(ConfigSet::settrings.value("ToolCoordinate"+QString::number(index,10)+"/num"+QString::number(1,10),0).toString());
}

void ToolManageWidget::save_position_data()
{
    int i,j;
    if(!(tool_buf[0]|tool_buf[1]|tool_buf[2]|tool_buf[3]|tool_buf[4]|tool_buf[5]|tool_buf[6]|tool_buf[7]|tool_buf[8]|tool_buf[9]|tool_buf[10]))
    {
        QMessageBox::warning(this,"警告","保存出错！",QMessageBox::Ok);
        return;
    }
    for(j=0;j<11;++j)
    {
        if(tool_buf[j]==true)
        {
            ConfigSet::settrings.setValue("ToolCoordinate"+QString::number(j,10)+"/num1",position_edit[12]->text());
            for(i=0;i<6;++i)
            {
//                ConfigSet::settrings.setValue("ToolCoordinate"+QString::number(j,10)+"/num1",position_edit[12]->text());
                ConfigSet::settrings.setValue("ToolCoordinate"+QString::number(j,10)+"/num"+QString::number(i+2,10),position_edit[6+i]->text());
                qDebug()<<position_edit[6+i]->text();
            }

            qDebug()<<position_edit[12]->text();
        }
    }

}

void ToolManageWidget::timeout_slot()
{
    MotionFeedback fb;
    ToolCoordianteInformation out;
    int i;
    static bool p1=false,p2=false,p3=false,p4=false,p5=false,p6=false;
    switch (keystyle) {
    case P1_KEY:
        if(method_buf[2]==true)
        {
            if(method_buf[3]==false&&method_buf[4]==false&&method_buf[5]==false)
            {
                QMessageBox::warning(this,"警告","您还未选择指定的平面\n请先选定指定的平面！",QMessageBox::Ok);
                return;
            }
        }
        if(!p1)//记录
        {
            CTRL_GetMotionStatus(&fb);

            jointpoint1[0].j1=fb.jointCmd.j1;
            jointpoint1[0].j2=fb.jointCmd.j2;
            jointpoint1[0].j3=fb.jointCmd.j3;
            jointpoint1[0].j4=fb.jointCmd.j4;
            jointpoint1[0].j5=fb.jointCmd.j5;
            jointpoint1[0].j6=fb.jointCmd.j6;


            record_btn[0]->setStyleSheet(BTN_STYPE);
            position_record_buf[0]=true;
            p1=!p1;
        }
        else//清除
        {

            record_btn[0]->setStyleSheet(BTN_RELEASE_STYPE);
            position_record_buf[0]=false;
            p1=!p1;
        }
        break;
    case P2_KEY:
        if(method_buf[2]==true)
        {
            if(method_buf[3]==false&&method_buf[4]==false&&method_buf[5]==false)
            {
                QMessageBox::warning(this,"警告","您还未选择指定的平面\n请先选定指定的平面！",QMessageBox::Ok);
                return;
            }
        }
        if(!p2)//记录
        {
            CTRL_GetMotionStatus(&fb);

            jointpoint1[1].j1=fb.jointCmd.j1;
            jointpoint1[1].j2=fb.jointCmd.j2;
            jointpoint1[1].j3=fb.jointCmd.j3;
            jointpoint1[1].j4=fb.jointCmd.j4;
            jointpoint1[1].j5=fb.jointCmd.j5;
            jointpoint1[1].j6=fb.jointCmd.j6;

            record_btn[1]->setStyleSheet(BTN_STYPE);
            position_record_buf[1]=true;
            p2=!p2;
        }
        else//清除
        {
            record_btn[1]->setStyleSheet(BTN_RELEASE_STYPE);
            position_record_buf[1]=false;
            p2=!p2;
        }
        break;
    case P3_KEY:
        if(method_buf[2]==true)
        {
            if(method_buf[3]==false&&method_buf[4]==false&&method_buf[5]==false)
            {
                QMessageBox::warning(this,"警告","您还未选择指定的平面\n请先选定指定的平面！",QMessageBox::Ok);
                return;
            }
        }
        if(!p3)//记录
        {
            CTRL_GetMotionStatus(&fb);

            jointpoint1[2].j1=fb.jointCmd.j1;
            jointpoint1[2].j2=fb.jointCmd.j2;
            jointpoint1[2].j3=fb.jointCmd.j3;
            jointpoint1[2].j4=fb.jointCmd.j4;
            jointpoint1[2].j5=fb.jointCmd.j5;
            jointpoint1[2].j6=fb.jointCmd.j6;

            record_btn[2]->setStyleSheet(BTN_STYPE);
            position_record_buf[2]=true;
            p3=!p3;
        }
        else//清除
        {
            record_btn[2]->setStyleSheet(BTN_RELEASE_STYPE);
            position_record_buf[2]=false;
            p3=!p3;
        }
        break;
    case P4_KEY:
        if(!p4)//记录
        {
            CTRL_GetMotionStatus(&fb);

            jointpoint1[3].j1=fb.jointCmd.j1;
            jointpoint1[3].j2=fb.jointCmd.j2;
            jointpoint1[3].j3=fb.jointCmd.j3;
            jointpoint1[3].j4=fb.jointCmd.j4;
            jointpoint1[3].j5=fb.jointCmd.j5;
            jointpoint1[3].j6=fb.jointCmd.j6;

            record_btn[3]->setStyleSheet(BTN_STYPE);
            position_record_buf[3]=true;
            p4=!p4;
        }
        else//清除
        {
            record_btn[3]->setStyleSheet(BTN_RELEASE_STYPE);
            position_record_buf[3]=false;
            p4=!p4;
        }
        break;
    case P5_KEY:
        if(!p5)//记录
        {
            CTRL_GetMotionStatus(&fb);

            jointpoint1[4].j1=fb.jointCmd.j1;
            jointpoint1[4].j2=fb.jointCmd.j2;
            jointpoint1[4].j3=fb.jointCmd.j3;
            jointpoint1[4].j4=fb.jointCmd.j4;
            jointpoint1[4].j5=fb.jointCmd.j5;
            jointpoint1[4].j6=fb.jointCmd.j6;

            record_btn[4]->setStyleSheet(BTN_STYPE);
            position_record_buf[4]=true;
            p5=!p5;
        }
        else//清除
        {
            record_btn[4]->setStyleSheet(BTN_RELEASE_STYPE);
            position_record_buf[4]=false;
            p5=!p5;
        }
        break;
    case P6_KEY:
        if(!p6)//记录
        {
            CTRL_GetMotionStatus(&fb);

            jointpoint1[5].j1=fb.jointCmd.j1;
            jointpoint1[5].j2=fb.jointCmd.j2;
            jointpoint1[5].j3=fb.jointCmd.j3;
            jointpoint1[5].j4=fb.jointCmd.j4;
            jointpoint1[5].j5=fb.jointCmd.j5;
            jointpoint1[5].j6=fb.jointCmd.j6;

            record_btn[5]->setStyleSheet(BTN_STYPE);
            position_record_buf[5]=true;
            p6=!p6;
        }
        else//清除
        {
            record_btn[5]->setStyleSheet(BTN_RELEASE_STYPE);
            position_record_buf[5]=false;
            p6=!p6;
        }
        break;
    case SET_CURRENT_KEY:
        for(i=0;i<11;i++)
        {
            if(tool_buf[i])
            {
                position_edit[13]->setText("当前使用的TCS的ID号："+QString::number(i,10));
                ConfigSet::settrings.setValue("ToolCoordinatecomment/num1",i);
            }
        }
        break;
    case CLEAR_KEY:
        switch (QMessageBox::warning(this,"警告","确定要清除当前数据",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Cancel)) {
        case QMessageBox::Ok:
            qDebug()<<"clear current data";
            break;
        case QMessageBox::Cancel:

            break;
        default:
            break;
        }
        break;
    case CALC_KEY:
        if(method_buf[0]==true)
        {
            if(position_record_buf[0]==true&&position_record_buf[1]==true&&position_record_buf[2]==true&&position_record_buf[3]==true)
            {
                qDebug()<<"计算位置值";
                save_position_data();
            }
            else{
            QMessageBox::warning(this,"警告","还未记录位置",QMessageBox::Ok);
            }
        }else if(method_buf[1]==true)
        {
            if(position_record_buf[0]==true&&position_record_buf[1]==true&&position_record_buf[2]==true&&position_record_buf[3]==true&&position_record_buf[4]==true&&position_record_buf[5]==true)
            {
                qDebug()<<"六点法";
                CTRL_ToolCalibration(jointpoint1,6,&out);
                position_edit[6]->setText(QString::number(out.x));
                position_edit[7]->setText(QString::number(out.y));
                position_edit[8]->setText(QString::number(out.z));
                position_edit[9]->setText(QString::number(out.rx));
                position_edit[10]->setText(QString::number(out.ry));
                position_edit[11]->setText(QString::number(out.rz));

                save_position_data();
            }
            else{
            QMessageBox::warning(this,"警告","还未记录位置",QMessageBox::Ok);
            }
//            qDebug()<<"六点法";
//            save_position_data();
        }
        else if(method_buf[2]==true)
        {
            qDebug()<<"三点法";
            save_position_data();
        }

        break;
    default:
        break;
    }
}

void ToolManageWidget::four_method_slot()
{
    for(int i=0;i<3;++i)
    {
        method_buf[i] = false;
        plane_buf[i] = false;
    }
    method_buf[0] = true;
    method_btn[0]->setStyleSheet("background-color:rgb(0,238,238);border-radius:4px;border:2px black;border-style:inset");
    method_btn[1]->setStyleSheet("background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset");
    method_btn[2]->setStyleSheet("background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset");
    method_btn[3]->setStyleSheet("background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset");
    method_btn[4]->setStyleSheet("background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset");
    method_btn[5]->setStyleSheet("background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset");
}

void ToolManageWidget::six_method_slot()
{
    for(int i=0;i<3;++i)
    {
        method_buf[i] = false;
        plane_buf[i] = false;
    }
    method_buf[1] = true;
    method_btn[1]->setStyleSheet("background-color:rgb(0,238,238);border-radius:4px;border:2px black;border-style:inset");
    method_btn[0]->setStyleSheet("background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset");
    method_btn[2]->setStyleSheet("background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset");
    method_btn[3]->setStyleSheet("background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset");
    method_btn[4]->setStyleSheet("background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset");
    method_btn[5]->setStyleSheet("background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset");
}

void ToolManageWidget::three_method_slot()
{
    for(int i=0;i<3;++i)
    {
        method_buf[i] = false;
        plane_buf[i] = false;
    }
    method_buf[2] = true;
    method_btn[2]->setStyleSheet("background-color:rgb(0,238,238);border-radius:4px;border:2px black;border-style:inset");
    method_btn[0]->setStyleSheet("background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset");
    method_btn[1]->setStyleSheet("background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset");
}

void ToolManageWidget::xy_plane_slot()
{
    if(!method_buf[2])
    {
        return;
    }
    for(int i=0;i<3;++i)
    {
        plane_buf[i] = false;
    }
    plane_buf[0]=true;
    method_btn[3]->setStyleSheet("background-color:rgb(0,238,238);border-radius:4px;border:2px black;border-style:inset");
    method_btn[4]->setStyleSheet("background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset");
    method_btn[5]->setStyleSheet("background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset");
}

void ToolManageWidget::yz_plane_slot()
{
    if(!method_buf[2])
    {
        return;
    }
    for(int i=0;i<3;++i)
    {
        plane_buf[i] = false;
    }
    plane_buf[1]=true;
    method_btn[4]->setStyleSheet("background-color:rgb(0,238,238);border-radius:4px;border:2px black;border-style:inset");
    method_btn[3]->setStyleSheet("background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset");
    method_btn[5]->setStyleSheet("background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset");
}

void ToolManageWidget::zx_plane_slot()
{
    if(!method_buf[2])
    {
        return;
    }
    for(int i=0;i<3;++i)
    {
        plane_buf[i] = false;
    }
    plane_buf[2]=true;
    method_btn[5]->setStyleSheet("background-color:rgb(0,238,238);border-radius:4px;border:2px black;border-style:inset");
    method_btn[4]->setStyleSheet("background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset");
    method_btn[3]->setStyleSheet("background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset");
}

void ToolManageWidget::coor0_slot()
{
    if(!tool_buf[0])
    {
        method_record_clear();
    }
    btn_disnable();
    set_coorbtn_select_status(0);

    //加载数据
    load_position_data(0);

}

void ToolManageWidget::coor1_slot()
{
    if(!tool_buf[1])
    {
        method_record_clear();
    }
    btn_enable();
    set_coorbtn_select_status(1);
    load_position_data(1);
}

void ToolManageWidget::coor2_slot()
{
    if(!tool_buf[2])
    {
        method_record_clear();
    }
    btn_enable();
    set_coorbtn_select_status(2);
    load_position_data(2);
}

void ToolManageWidget::coor3_slot()
{
    if(!tool_buf[3])
    {
        method_record_clear();
    }
    btn_enable();
    set_coorbtn_select_status(3);
    load_position_data(3);
}

void ToolManageWidget::coor4_slot()
{
    if(!tool_buf[4])
    {
        method_record_clear();
    }
    btn_enable();
    set_coorbtn_select_status(4);
    load_position_data(4);
}

void ToolManageWidget::coor5_slot()
{
    if(!tool_buf[5])
    {
        method_record_clear();
    }
    btn_enable();
    set_coorbtn_select_status(5);
    load_position_data(5);
}

void ToolManageWidget::coor6_slot()
{
    if(!tool_buf[6])
    {
        method_record_clear();
    }
    btn_enable();
    set_coorbtn_select_status(6);
    load_position_data(6);
}

void ToolManageWidget::coor7_slot()
{
    if(!tool_buf[7])
    {
        method_record_clear();
    }
    btn_enable();
    set_coorbtn_select_status(7);
    load_position_data(7);
}

void ToolManageWidget::coor8_slot()
{
    if(!tool_buf[8])
    {
        method_record_clear();
    }
    btn_enable();
    set_coorbtn_select_status(8);
    load_position_data(8);
}

void ToolManageWidget::coor9_slot()
{
    if(!tool_buf[9])
    {
        method_record_clear();
    }
    btn_enable();
    set_coorbtn_select_status(9);
    load_position_data(9);
}

void ToolManageWidget::coor10_slot()
{
    if(!tool_buf[10])
    {
        method_record_clear();
    }
    btn_enable();
    set_coorbtn_select_status(10);
    load_position_data(10);
}

void ToolManageWidget::record_p1_press_slot()
{
    keystyle = P1_KEY;
    timer->start(DELAY_TIME1);
}

void ToolManageWidget::record_p1_release_slot()
{
    timer->stop();
}

void ToolManageWidget::record_p2_press_slot()
{
    keystyle = P2_KEY;
    timer->start(DELAY_TIME1);
}

void ToolManageWidget::record_p2_release_slot()
{
    timer->stop();
}

void ToolManageWidget::record_p3_press_slot()
{
    keystyle = P3_KEY;
    timer->start(DELAY_TIME1);
}

void ToolManageWidget::record_p3_release_slot()
{
    timer->stop();
}

void ToolManageWidget::record_p4_press_slot()
{
    keystyle = P4_KEY;
    timer->start(DELAY_TIME1);
}

void ToolManageWidget::record_p4_release_slot()
{
    timer->stop();
}

void ToolManageWidget::record_p5_press_slot()
{
    keystyle = P5_KEY;
    timer->start(DELAY_TIME1);
}

void ToolManageWidget::record_p5_release_slot()
{
    timer->stop();
}

void ToolManageWidget::record_p6_press_slot()
{
    keystyle = P6_KEY;
    timer->start(DELAY_TIME1);
}

void ToolManageWidget::record_p6_release_slot()
{
    timer->stop();
}

void ToolManageWidget::set_current_data_press_slot()
{
    keystyle = SET_CURRENT_KEY;
    timer->start(DELAY_TIME1);
}

void ToolManageWidget::clear_current_data_press_slot()
{
    keystyle = CLEAR_KEY;
    timer->start(DELAY_TIME1);
}

void ToolManageWidget::calc_data_press_slot()
{
    keystyle = CALC_KEY;
    timer->start(DELAY_TIME1);
}

void ToolManageWidget::set_current_data_release_slot()
{
    timer->stop();
}

void ToolManageWidget::clear_current_data_release_slot()
{
    timer->stop();
}

void ToolManageWidget::calc_data_release_slot()
{
    timer->stop();
}

void ToolManageWidget::manual_setup_all_slot()
{
    qDebug()<<"alldd";
    menual_setup_assignment(0);
}

void ToolManageWidget::manual_setup_X_slot()
{
    menual_setup_assignment(1);
}

void ToolManageWidget::manual_setup_Y_slot()
{
    menual_setup_assignment(2);
}

void ToolManageWidget::manual_setup_Z_slot()
{
    menual_setup_assignment(3);
}

void ToolManageWidget::manual_setup_A_slot()
{
    menual_setup_assignment(4);
}

void ToolManageWidget::manual_setup_B_slot()
{
    menual_setup_assignment(5);
}

void ToolManageWidget::manual_setup_C_slot()
{
    menual_setup_assignment(6);
}
