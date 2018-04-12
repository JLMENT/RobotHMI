#ifndef COORDINATEMANAGEWIDGET_H
#define COORDINATEMANAGEWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPainter>
#include <QSpacerItem>
#include <QLabel>
#include <QTimer>
#include <QMessageBox>
#include <QLineEdit>
#include <QRect>
#include <QDebug>
#include "coordinatemamagestatus.h"
//#include "setting/configset.h"
#include "configset.h"
//#include "coordinateeditoperatewidget.h"
#include "usr_motion_api/usr_motion_api.h"

//bool Interface_Enable_Status = false;

class FaceSelect : public QFrame
{
    Q_OBJECT
public:
    FaceSelect(QWidget *parent = 0)
    {
        this->setMinimumSize(100,40);
        this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        hb = new QHBoxLayout(this);
        QStringList list;
        list<<"XY"<<"YZ"<<"ZX";
        for(int i=0;i<3;++i)
        {
            bt[i] = new QPushButton(this);
            bt[i]->setMaximumSize(30,20);
            bt[i]->setText(list.at(i));
            bt[i]->setEnabled(false);
            bt[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            hb->addWidget(bt[i]);

        }
        hb->setSpacing(0);
        connect(bt[0],SIGNAL(clicked()),this,SLOT(bt_slot0()));
        connect(bt[1],SIGNAL(clicked()),this,SLOT(bt_slot1()));
        connect(bt[2],SIGNAL(clicked()),this,SLOT(bt_slot2()));
        this->setLayout(hb);
        qDebug()<<"faceselect";
    }
    CMPlaneSelect planeselect = NO_PLANE;
    ~FaceSelect()
    {

    }
    void btn_enabled()
    {
        for(int i=0;i<3;++i)
        {
            bt[i]->setEnabled(true);
        }
    }
    void btn_disnabled()
    {
        for(int i=0;i<3;++i)
        {
            bt[i]->setEnabled(false);
        }
    }
private:
    QPushButton *bt[3];
    QHBoxLayout *hb;
private slots:
    void bt_slot0()
    {
        static bool select = false;
        if(!select)
        {
            bt[0]->setStyleSheet("background-color:rgb(0,238,238)");
            planeselect = XY_PLANE;
        }
        else
        {
            bt[0]->setStyleSheet("background-color:rgb(232,232,232)");
            planeselect = NO_PLANE;
        }
        bt[1]->setStyleSheet("background-color:rgb(232,232,232)");
        bt[2]->setStyleSheet("background-color:rgb(232,232,232)");

    }
    void bt_slot1()
    {
        static bool select = false;
        if(!select)
        {
            bt[1]->setStyleSheet("background-color:rgb(0,238,238)");
            planeselect = YZ_PLANE;
        }
        else
        {
            bt[1]->setStyleSheet("background-color:rgb(232,232,232)");
            planeselect = NO_PLANE;
        }
        bt[0]->setStyleSheet("background-color:rgb(232,232,232)");
        bt[2]->setStyleSheet("background-color:rgb(232,232,232)");
    }

    void bt_slot2()
    {
        static bool select = false;
        if(!select)
        {
            bt[2]->setStyleSheet("background-color:rgb(0,238,238)");
            planeselect = ZX_PLANE;
        }
        else
        {
            bt[2]->setStyleSheet("background-color:rgb(232,232,232)");
            planeselect = NO_PLANE;
        }
        bt[0]->setStyleSheet("background-color:rgb(232,232,232)");
        bt[1]->setStyleSheet("background-color:rgb(232,232,232)");
    }

    void face_select_ini()
    {
        btn_disnabled();
        planeselect = NO_PLANE;
        for(int i=0;i<3;++i)
        {
            bt[i]->setStyleSheet("background-color:rgb(232,232,232)");
        }
    }

    void face_enable_select()
    {
        btn_enabled();
    }

};

class OriginalBias : public QWidget
{
    Q_OBJECT
public:
    OriginalBias(QWidget *parent = 0)
    {
//        QPalette palette;
//        QPixmap pixmap(":/CMimage/Origionbias.png");
//        palette.setBrush(QPalette::Window,QBrush(pixmap));
//        this->setPalette(palette);
//        this->setAutoFillBackground(true);
//        this->setStyleSheet("background-image:url(:/CMimage/Origionbias.png)");
        this->setMinimumSize(100,140);
        btn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
        hb->addItem(horizontalSpacer1);
        hb->addWidget(btn);
        hb->addItem(horizontalSpacer2);
        hb->setStretch(0,9);
        hb->setStretch(1,2);
        hb->setStretch(2,1);

        vb->addItem(verticalSpacer1);
        vb->addLayout(hb);
        vb->addItem(verticalSpacer2);
        vb->setStretch(0,1);
        vb->setStretch(1,2);
        vb->setStretch(2,9);

        this->setLayout(vb);

        connect(btn,SIGNAL(clicked()),this,SLOT(btn_slot()));
        qDebug()<<"originalBias";
    }
    bool selected=false;
    ~OriginalBias()
    {

    }

private:
    QPushButton *btn = new QPushButton;
    QVBoxLayout *vb = new QVBoxLayout(this);
    QHBoxLayout *hb = new QHBoxLayout(this);
    QSpacerItem *verticalSpacer1 = new QSpacerItem(20,40,QSizePolicy::Minimum,QSizePolicy::Expanding);
    QSpacerItem *verticalSpacer2 = new QSpacerItem(20,40,QSizePolicy::Minimum,QSizePolicy::Expanding);
    QSpacerItem *horizontalSpacer1 = new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum);
    QSpacerItem *horizontalSpacer2 = new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum);

    void paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
        //painter.drawPixmap(0,0,120,150,QPixmap(":/CMimage/Origionbias.png"));
        painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/CMimage/Origionbias.png"));
    }

private slots:
    void btn_slot()
    {
        if(!selected)
        {
            selected = !selected;
            btn->setStyleSheet("background-color:rgb(0,238,238)");
        }
        else
        {
            selected = !selected;
            btn->setStyleSheet("background-color:rgb(232,232,232)");
        }
    }
};

class ThreeOriginal : public QWidget
{
    Q_OBJECT
public:
    bool selected = false;
    ThreeOriginal(QWidget *parent = 0)
    {
        this->setMinimumSize(100,120);
        this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        btn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
        hb->addItem(horizontalSpacer1);
        hb->addWidget(btn);
        hb->addItem(horizontalSpacer2);
        hb->setStretch(0,6);
        hb->setStretch(1,2);
        hb->setStretch(2,1);

        vb->addItem(verticalSpacer1);
        vb->addLayout(hb);
        vb->addItem(verticalSpacer2);
        vb->setStretch(0,1);
        vb->setStretch(1,2);
        vb->setStretch(2,9);

//        hb->addStretch(20);
//        hb->addWidget(btn);
//        hb->setSpacing(0);
//        //hb->addStretch(1);

//        //vb->addStretch(1);
//        vb->addLayout(hb);
//        vb->addStretch(20);
//        vb->setSpacing(0);

        this->setLayout(vb);

        connect(btn,SIGNAL(clicked()),this,SLOT(btn_slot()));
        qDebug()<<"threeoriginal";
    }
    ~ThreeOriginal()
    {

    }
private:
    QPushButton *btn = new QPushButton;
    QVBoxLayout *vb = new QVBoxLayout(this);
    QHBoxLayout *hb = new QHBoxLayout(this);
    QSpacerItem *verticalSpacer1 = new QSpacerItem(20,40,QSizePolicy::Minimum,QSizePolicy::Expanding);
    QSpacerItem *verticalSpacer2 = new QSpacerItem(20,40,QSizePolicy::Minimum,QSizePolicy::Expanding);
    QSpacerItem *horizontalSpacer1 = new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum);
    QSpacerItem *horizontalSpacer2 = new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum);

    void paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
        //painter.drawPixmap(0,0,120,130,QPixmap(":/CMimage/xy1.png"));
        painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/CMimage/xy1.png"));
    }

private slots:
    void btn_slot()
    {
        if(!selected)
        {
            selected = !selected;
            btn->setStyleSheet("background-color:rgb(0,238,238)");
        }
        else
        {
            selected = !selected;
            btn->setStyleSheet("background-color:rgb(232,232,232)");
        }
    }

};

class CurrentUsrID : public QWidget
{
    Q_OBJECT
public:
    CurrentUsrID(QWidget *parent = 0)
    {
        this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        QStringList list;
        list<<"当前使用的ID号"<<"WCS:0"<<"PCS1:0"<<"PCS2:0";
        vb->setSpacing(0);
        for(int i=0;i<4;++i)
        {
            label[i] = new QLabel(this);
            label[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            label[i]->setFrameStyle(QFrame::Panel|QFrame::Sunken);
            label[i]->setText(list.at(i));
            label[i]->setAlignment(Qt::AlignBottom|Qt::AlignRight);
            vb->addWidget(label[i]);
        }
        btn->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        vb->addWidget(btn);

        connect(btn,SIGNAL(pressed()),this,SLOT(set_current_position_press_slot()));
        connect(btn,SIGNAL(released()),this,SLOT(set_current_position_release_slot()));
        connect(timer,SIGNAL(timeout()),this,SLOT(set_current_position_response()));

        this->setLayout(vb);

        configset->createIni("CurrentID",3);
        load_init_data();
        qDebug()<<"CurrentUsrID";

    }
    ~CurrentUsrID()
    {

    }
    void set_current_wcs_id(QString str)
    {
        label[1]->setText(str);
        ConfigSet::settrings.setValue("CurrentID/num1",str);
    }

    void set_current_pcs1_id(QString str)
    {
        label[2]->setText(str);
        ConfigSet::settrings.setValue("CurrentID/num2",str);
    }

    void set_current_pcs2_id(QString str)
    {
        label[3]->setText(str);
        ConfigSet::settrings.setValue("CurrentID/num3",str);
    }

private:
    ConfigSet *configset = new ConfigSet;
    QLabel *label[4];
    QPushButton *btn = new QPushButton("设置为当前",this);
    QVBoxLayout *vb = new QVBoxLayout(this);
    QTimer *timer = new QTimer(this);

    void load_init_data()
    {
        for(int i=0;i<3;++i)
        {
            label[i+1]->setText(ConfigSet::settrings.value("CurrentID/num"+QString::number(i+1,10)).toString());
        }
    }

private slots:
    void set_current_position_press_slot()
    {
        timer->start(DELAY_TIME2);
    }
    void set_current_position_release_slot()
    {
        timer->stop();
    }

    void set_current_position_response()
    {
        timer->stop();
        int i,j;
        QMessageBox msgBox;
        msgBox.setText("Seting Current ID.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save|QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox.exec();
        switch (ret) {
        case QMessageBox::Save:
            for(i=0;i<3;++i)
            {
                for(j=0;j<10;++j)
                {
                    if(buf[i][j])
                    {
                        if(i==0)
                        {
                            set_current_wcs_id(QString::number(j+1,10));
                        }
                        else if(i==1)
                        {
                            set_current_pcs1_id(QString::number(j+1,10));
                        }
                        else if(i==2)
                        {
                            set_current_pcs2_id(QString::number(j+1,10));
                        }
                    }
                }
            }
            break;
        case QMessageBox::Cancel:

            break;
        default:
            break;
        }
    }
};


class CoordinateSelect : public QWidget
{
    Q_OBJECT
public:
//    bool buf[3][10]={{0}};
//    bool buf_coor[3]={0};
    CoordinateSelect(QWidget *parent = 0)
    {
        this->setMinimumSize(300,60);
        this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        hb1->setSpacing(0);
        hb2->setSpacing(0);
        vb->setSpacing(0);
        QStringList list;
        list<<"WCS"<<"PCS1"<<"PCS2"
           <<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9"<<"10";
        for(int i=0;i<13;++i)
        {
            btn[i] = new QPushButton(list.at(i),this);
            btn[i]->setMinimumSize(20,20);
            btn[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            btn[i]->setGeometry(QRect(0,0,10,10));
            btn[i]->setStyleSheet("background-color:rgb(255,255,255)");
            if(i<3)
            {
                hb1->addWidget(btn[i]);
                //hb1->SetMinAndMaxSize

            }
            else
            {
                hb2->addWidget(btn[i]);
                //hb2->SetFixedSize(100);
            }
        }
        vb->addLayout(hb1);
        vb->addLayout(hb2);
            connect(btn[0],SIGNAL(clicked()),this,SLOT(WCS_slot()));
            connect(btn[1],SIGNAL(clicked()),this,SLOT(PCS1_slot()));
            connect(btn[2],SIGNAL(clicked()),this,SLOT(PCS2_slot()));
            connect(btn[3],SIGNAL(clicked()),this,SLOT(one_axis_slot()));
            connect(btn[4],SIGNAL(clicked()),this,SLOT(two_axis_slot()));
            connect(btn[5],SIGNAL(clicked()),this,SLOT(three_axis_slot()));
            connect(btn[6],SIGNAL(clicked()),this,SLOT(four_axis_slot()));
            connect(btn[7],SIGNAL(clicked()),this,SLOT(five_axis_slot()));
            connect(btn[8],SIGNAL(clicked()),this,SLOT(six_axis_slot()));
            connect(btn[9],SIGNAL(clicked()),this,SLOT(seven_axis_slot()));
            connect(btn[10],SIGNAL(clicked()),this,SLOT(eight_axis_slot()));
            connect(btn[11],SIGNAL(clicked()),this,SLOT(nine_axis_slot()));
            connect(btn[12],SIGNAL(clicked()),this,SLOT(ten_axis_slot()));



        this->setLayout(vb);
        qDebug()<<"CoordinateSelect";
        qDebug()<<"dddddddddddddddddddddddd";
    }
//    CoordinateSelect(class CoordinateEditOperateWidget *cor)
//    {
//        coordinateeditoperatewidget=cor;
//    }
    ~CoordinateSelect()
    {

    }

private:
    ConfigSet *configset = new ConfigSet;
    //CoordinateEditOperateWidget *coordinateeditoperatewidget;// = new CoordinateEditOperateWidget;
    QPushButton *btn[13];
    QVBoxLayout *vb = new QVBoxLayout(this);
    QHBoxLayout *hb1 = new QHBoxLayout;//(this);
    QHBoxLayout *hb2 = new QHBoxLayout;//(this);
    void btn_selected(int index)
    {
//        if(buf_coor[0]==false&&buf[1]==false&&buf[2]==false)
//        {
//            return;
//        }
//        int i,j,a;

//        //coordinateeditoperatewidget->set_zero_axis_status();
//        Interface_Enable_Status = true;
//        for(i=0;i<3;++i)
//        {
//            if(buf_coor[i]==true)
//            {
//                buf[i][index] = true;
//                btn[index+3]->setStyleSheet("background-color:rgb(0,238,238)");
//            }
//        }
//        for(j=0;j<3;++j)
//        {
//            for(a=0;a<10;++a)
//            {
//                if(j!=i&&a!=index)
//                {
//                   buf[j][i]=0;
//                }
//            }
//        }

        qDebug()<<buf_coor[0]<<buf_coor[1]<<buf_coor[2];
        if(buf_coor[0]==false&&buf_coor[1]==false&&buf_coor[2]==false)
        {
            return;
        }
        int i,j,a;
        //coordinateeditoperatewidget->set_zero_axis_status();
        Interface_Enable_Status = true;
        for(i=0;i<3;++i)
        {
            if(buf_coor[i]==true)
            {
                emit reload_data_sig(i,index+1);
//                buf[i][index] = true;
                btn[index+3]->setStyleSheet("background-color:rgb(0,238,238)");
                qDebug()<<"sss";
                for(j=0;j<3;++j)
                {
                    for(a=0;a<10;++a)
                    {
                        buf[j][a]=false;
//                        if(j!=i&&a!=index)
//                        {
//                           buf[j][i]=0;
//                        }
                        qDebug()<<j<<i<<buf[j][i];
                    }
                }
                qDebug()<<"=========";
                buf[i][index] = true;
                qDebug()<<i<<index<<buf[i][index];
                for(i=0;i<3;++i)
                {
                    for(j=0;j<10;++j)
                    {
                        qDebug()<<i<<j<<buf[i][j];
                    }
                }
                for(a=0;a<10;++a)
                {
                    if(a!=index)
                    {
                        btn[a+3]->setStyleSheet("background-color:rgb(255,255,255)");
                    }
                }
//                emit reload_data_sig(i,index+1);
            }
        }
        emit axis_selected_sig();

    }

private slots:
    void one_disnable_slot()
    {
        int i,j;
        for(int i=0;i<10;++i)
        {
            btn[i+3]->setStyleSheet("background-color:rgb(255,255,255)");
        }
        for(i=0;i<3;++i)
        {
            for(j=0;j<10;j++)
            {
                buf[i][j]=false;
            }
        }
    }
    void WCS_slot()
    {
        if(buf_coor[0]==true)
        {
            return;
        }
        int i,j;
        btn[0]->setStyleSheet("background-color:rgb(0,238,238)");
        buf_coor[0]=true;
        buf_coor[1] = false;
        buf_coor[2] = false;
        for(i=0;i<13;++i)
        {
            if(i!=0)
            {
                btn[i]->setStyleSheet("background-color:rgb(255,255,255)");
            }
        }
        for(i=0;i<3;++i)
        {
            for(j=0;j<10;++j)
            {
                buf[i][j]=false;
            }
        }
        qDebug()<<buf_coor[0]<<buf_coor[1]<<buf_coor[2];
    }
    void PCS1_slot()
    {
        if(buf_coor[1]==true)
        {
            return;
        }
        int i,j;
        btn[1]->setStyleSheet("background-color:rgb(0,238,238)");
        buf_coor[0]=false;
        buf_coor[1] = true;
        buf_coor[2] = false;
        for(i=0;i<13;++i)
        {
            if(i!=1)
            {
                btn[i]->setStyleSheet("background-color:rgb(255,255,255)");
            }
        }
        for(i=0;i<3;++i)
        {
            for(j=0;j<10;++j)
            {
                buf[i][j]=false;
            }
        }
    }
    void PCS2_slot()
    {
        if(buf_coor[2]==true)
        {
            return;
        }
        int i,j;
        btn[2]->setStyleSheet("background-color:rgb(0,238,238)");
        buf_coor[0]=false;
        buf_coor[1] = false;
        buf_coor[2] = true;
        for(i=0;i<13;++i)
        {
            if(i!=2)
            {
                btn[i]->setStyleSheet("background-color:rgb(255,255,255)");
            }
        }
        for(i=0;i<3;++i)
        {
            for(j=0;j<10;++j)
            {
                buf[i][j]=false;
            }
        }
    }
    void one_axis_slot()
    {
        //qDebug()<<buf_coor[0]<<buf_coor[1]<<buf_coor[2];
        if(buf_coor[0]==false&&buf_coor[1]==false&&buf_coor[2]==false)
        {
            return;
        }        
        int i,j,a;
        //coordinateeditoperatewidget->set_zero_axis_status1();
        Interface_Enable_Status = true;
        for(i=0;i<3;++i)
        {
            if(buf_coor[i]==true)
            {


                //qDebug()<<"select axis !!!!!!"<<buf[i][0];
                btn[3]->setStyleSheet("background-color:rgb(0,238,238)");
                //qDebug()<<"sss";
                for(j=0;j<3;++j)
                {
                    for(a=0;a<10;++a)
                    {
                        buf[j][a]=false;
                        //qDebug()<<j<<a<<buf[j][a];
                    }
                }
                buf[i][0] = true;
                for(a=0;a<10;++a)
                {
                    if(a!=0)
                    {
                        btn[a+3]->setStyleSheet("background-color:rgb(255,255,255)");
                    }
                }
                emit reload_data_sig(i,1);
            }
        }
        emit axis_selected_sig();
        //qDebug()<<"emit sig";

    }
    void two_axis_slot()
    {
        btn_selected(1);
    }
    void three_axis_slot()
    {
        btn_selected(2);
    }
    void four_axis_slot()
    {
        btn_selected(3);
    }
    void five_axis_slot()
    {
        btn_selected(4);
    }
    void six_axis_slot()
    {
        btn_selected(5);
    }
    void seven_axis_slot()
    {
        btn_selected(6);
    }
    void eight_axis_slot()
    {
        btn_selected(7);
    }
    void nine_axis_slot()
    {
        btn_selected(8);
    }
    void ten_axis_slot()
    {
        btn_selected(9);
    }

signals:
    void axis_selected_sig();
    void reload_data_sig(int,int);
};

class CoordinateEditOperateWidget : public QWidget
{
    Q_OBJECT
public:
    CoordinateEditOperateWidget(QWidget *parent=0)
    {
        qDebug()<<"s00000";
        this->setMinimumSize(200,240);
        this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        CMBtn = NO_BTN;
        int i;
        zero_coordinate_btn = new QPushButton("0",this);
        zero_coordinate_btn->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        zero_coordinate_btn->setStyleSheet("background-color:rgb(0,238,238)");
        QStringList list1,list2,list3;
        list1<<"注释:"<<"X:0.000"<<"Y:0.000"<<"Z:0.000"<<"A:0.000"<<"B:0.000"<<"C:0.000";
        list2<<"记录P1"<<"记录P2"<<"记录P3"<<"记录P4";
        list3<<"编辑"<<"确定"<<"清除"<<"计算";
        qDebug()<<"s1111111";
        for(i=0;i<7;++i)
        {
            position_data[i]= new QLineEdit(this);
            position_data[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            position_data[i]->setText(list1.at(i));
            if(i>0)
            {
                vb1->addWidget(position_data[i]);
                position_data[i]->setEnabled(false);
            }
        }
        for(i=0;i<4;++i)
        {
            record_position_btn[i] = new QPushButton(list2.at(i),this);
            record_position_btn[i]->setEnabled(false);
            record_position_btn[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            record_state_display_btn[i] = new QPushButton;
            record_state_display_btn[i]->setFixedSize(QPixmap(":/CMimage/disnable.png").size());
            record_state_display_btn[i]->setStyleSheet("border-image:url(:/CMimage/disnable.png)");
            record_state_display_btn[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            record_state_display_btn[i]->setEnabled(false);

            gb1->addWidget(record_position_btn[i],i,0);
            gb1->addWidget(record_state_display_btn[i],i,1);
            operate_btn[i] = new QPushButton(list3.at(i),this);
            operate_btn[i]->setEnabled(false);
            operate_btn[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            hb1->addWidget(operate_btn[i]);
            qDebug()<<"s22";
        }
        hb2->addLayout(vb1);
        hb2->addLayout(gb1);

        vb->addWidget(zero_coordinate_btn);
        vb->addWidget(position_data[0]);
        vb->addLayout(hb2);
        vb->addLayout(hb1);
        vb->setStretch(0,1);
        vb->setStretch(1,1);
        vb->setStretch(2,6);
        vb->setStretch(3,1);

        timer = new QTimer;
        connect(timer,SIGNAL(timeout()),this,SLOT(overtime_respons()));

        connect(zero_coordinate_btn,SIGNAL(clicked()),this,SLOT(zero_btn_slot()));

        connect(record_position_btn[0],SIGNAL(pressed()),this,SLOT(record_position_btn1_press_slot()));
        connect(record_position_btn[0],SIGNAL(released()),this,SLOT(record_position_btn1_release_slot()));
        connect(record_position_btn[1],SIGNAL(pressed()),this,SLOT(record_position_btn2_press_slot()));
        connect(record_position_btn[1],SIGNAL(released()),this,SLOT(record_position_btn2_release_slot()));
        connect(record_position_btn[2],SIGNAL(pressed()),this,SLOT(record_position_btn3_press_slot()));
        connect(record_position_btn[2],SIGNAL(released()),this,SLOT(record_position_btn3_release_slot()));
        connect(record_position_btn[3],SIGNAL(pressed()),this,SLOT(record_position_btn0_press_slot()));
        connect(record_position_btn[3],SIGNAL(released()),this,SLOT(record_position_btn0_release_slot()));

        connect(operate_btn[0],SIGNAL(pressed()),this,SLOT(operate_btn1_press_slot()));
        connect(operate_btn[0],SIGNAL(released()),this,SLOT(operate_btn1_release_slot()));
        connect(operate_btn[1],SIGNAL(pressed()),this,SLOT(operate_btn2_press_slot()));
        connect(operate_btn[1],SIGNAL(released()),this,SLOT(operate_btn2_release_slot()));
        connect(operate_btn[2],SIGNAL(pressed()),this,SLOT(operate_btn3_press_slot()));
        connect(operate_btn[2],SIGNAL(released()),this,SLOT(operate_btn3_release_slot()));
        connect(operate_btn[3],SIGNAL(pressed()),this,SLOT(operate_btn4_press_slot()));
        connect(operate_btn[3],SIGNAL(released()),this,SLOT(operate_btn4_release_slot()));


        this->setLayout(vb);
        for(i=0;i<11;++i)
        {
            configset->createIni("WCS"+QString::number(i,10),7);
        }
        for(i=0;i<11;++i)
        {
            configset->createIni("PCS1"+QString::number(i,10),7);
        }
        for(i=0;i<11;++i)
        {
            configset->createIni("PCS2"+QString::number(i,10),7);
        }
        qDebug()<<"CoordinateEditOperateWidget";

    }
    ~CoordinateEditOperateWidget()
    {

    }

    void set_btn_disnable()
    {
        for(int i=0;i<4;++i)
        {
            record_position_btn[i]->setEnabled(false);
            operate_btn[i]->setEnabled(false);
        }
    }
    void set_btn_enable()
    {
        for(int i=0;i<4;++i)
        {
            record_position_btn[i]->setEnabled(true);
            operate_btn[i]->setEnabled(true);
        }
    }
    void set_zero_axis_status1()
    {
        zero_coordinate_btn->setStyleSheet("background-color:rgb(255,255,255)");
    }

private:
    QString strbuf[7];
    ConfigSet *configset = new ConfigSet;
    CoordinateSelect *coordinateselect = new CoordinateSelect;
    QPushButton *zero_coordinate_btn;
    QPushButton *record_position_btn[4];//记录按钮
    QPushButton *record_state_display_btn[4];   //记录状态显示按钮
    QLineEdit *position_data[7]; //第一个编辑框显示和编辑注释
    QPushButton *operate_btn[4];//分别为编辑、确定、清除、计算按钮
    //QTimer *timer[8];//分别为4个记录、编辑、确定、清除、计算按钮的定时。
    QTimer *timer;
    typedef enum
    {
        NO_BTN = -1,
        P1_BTN = 0,
        P2_BTN,
        P3_BTN,
        P4_BTN,
        EDIT_BTN,
        ENSURE_BTN,
        CLEAR_BTN,
        CALC_BTN
    }CoordinateManageBtn;
    CoordinateManageBtn CMBtn;

    bool position_recorder_status[3]={false};//position whether recorder flag

    //arithmetic
    //JointPoint jpbuf[3];//0-origin 1-x,2-y
    ThreeJointPoints threejointpoints1;

    QVBoxLayout *vb = new QVBoxLayout(this);
    QVBoxLayout *vb1 = new QVBoxLayout(this);
    QGridLayout *gb1 = new QGridLayout(this);
    QHBoxLayout *hb1 = new QHBoxLayout(this);
    QHBoxLayout *hb2 = new QHBoxLayout(this);

    void set_position_data(QString *str)
    {
        for(int i=0;i<7;++i)
        {
            position_data[i]->setText(str[i]);
        }
    }
    void set_zero_axis_status()
    {
        zero_coordinate_btn->setStyleSheet("background-color:rgb(255,255,255)");
    }

    void require_current_data()
    {
        for(int i=0;i<7;++i)
        {
            strbuf[i] = position_data[i]->text();
        }
    }

    //recorver points init status
    void recorver_points_init_status()
    {
        record_state_display_btn[0]->setStyleSheet("border-image:url(:/CMimage/disnable.png)");
        record_state_display_btn[1]->setStyleSheet("border-image:url(:/CMimage/disnable.png)");
        record_state_display_btn[2]->setStyleSheet("border-image:url(:/CMimage/disnable.png)");
        position_recorder_status[0] = false;
        position_recorder_status[0] = false;
        position_recorder_status[0] = false;
    }

private slots:
    void reload_data_slot(int coorstr,int axisnum)
    {
        qDebug()<<coorstr<<axisnum;
        QString str;
        if(coorstr==0)
        {
            str="WCS";
        }
        else if(coorstr==1)
        {
            str="PCS1";
        }
        else if(coorstr==2)
        {
            str="PCS2";
        }
        for(int i=0;i<7;++i)
        {

            position_data[i]->setText(ConfigSet::settrings.value(str+QString::number(axisnum,10)+"/num"+QString::number(i+1,10),0).toString());
//            qDebug()<<ConfigSet::settrings.value(str+QString::number(axisnum,10)+"/num"+QString::number(i+1,10),0).toString();
//            qDebug()<<ConfigSet::settrings.value("WCS1/num1",0).toString();
        }
//        qDebug()<<"reload data";
    }
    void zero_unselected_slot()
    {
        zero_coordinate_btn->setStyleSheet("background-color:rgb(255,255,255)");
        Interface_Enable_Status=false;
        set_btn_enable();
    }
    //    void coordinate_selected()
//    {
//        qDebug()<<"axis select";
//        set_btn_enable();
//        set_zero_axis_status();
//    }
    void zero_btn_slot()
    {
        zero_coordinate_btn->setStyleSheet("background-color:rgb(0,238,238)");
        set_btn_disnable();
        emit control_one_axis_disnable_sig();
    }

    void record_position_btn1_press_slot()
    {
        CMBtn = P1_BTN;
        timer->start(DELAY_TIME2);
    }
    void record_position_btn1_release_slot()
    {
        timer->stop();
    }
    void record_position_btn2_press_slot()
    {
        CMBtn = P2_BTN;
        timer->start(DELAY_TIME2);
    }
    void record_position_btn2_release_slot()
    {
        timer->stop();
    }
    void record_position_btn3_press_slot()
    {
        CMBtn = P3_BTN;
        timer->start(DELAY_TIME2);
    }
    void record_position_btn3_release_slot()
    {
        timer->stop();
    }
    void record_position_btn0_press_slot()
    {
        CMBtn = P4_BTN;
        timer->start(DELAY_TIME2);
    }
    void record_position_btn0_release_slot()
    {
        timer->stop();
    }

    void operate_btn1_press_slot()
    {
        CMBtn = EDIT_BTN;
        timer->start(DELAY_TIME2);
    }
    void operate_btn1_release_slot()
    {
        timer->stop();
    }
    void operate_btn2_press_slot()
    {
        CMBtn = ENSURE_BTN;
        timer->start(DELAY_TIME2);
    }
    void operate_btn2_release_slot()
    {
        timer->stop();
    }
    void operate_btn3_press_slot()
    {
        CMBtn = CLEAR_BTN;
        timer->start(DELAY_TIME2);
    }
    void operate_btn3_release_slot()
    {
        timer->stop();
    }
    void operate_btn4_press_slot()
    {
        CMBtn = CALC_BTN;
        timer->start(DELAY_TIME2);
    }
    void operate_btn4_release_slot()
    {
        timer->stop();
    }


    void overtime_respons()
    {
        MotionFeedback fb;
        int i,j,a,ret,k;
        QStringList listIni;
        timer->stop();
        switch (CMBtn) {
        case P1_BTN:
            //记录位置1
            //状态灯显示
            ret = QMessageBox::information(this,"datasave","是否保存数据",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Cancel);
            switch (ret) {
            case QMessageBox::Ok:
                CTRL_GetMotionStatus(&fb);
                threejointpoints1.org.j1=fb.jointCmd.j1;
                threejointpoints1.org.j2=fb.jointCmd.j2;
                threejointpoints1.org.j3=fb.jointCmd.j3;
                threejointpoints1.org.j4=fb.jointCmd.j4;
                threejointpoints1.org.j5=fb.jointCmd.j5;
                threejointpoints1.org.j6=fb.jointCmd.j6;

                position_recorder_status[0]= true;
                record_state_display_btn[0]->setStyleSheet("border-image:url(:/CMimage/enable.png)");
                break;
            case QMessageBox::Cancel:
                break;
            default:
                break;
            }

            break;
        case P2_BTN:
            ret = QMessageBox::information(this,"datasave","是否保存数据",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Cancel);
            switch (ret) {
            case QMessageBox::Ok:
                CTRL_GetMotionStatus(&fb);
                threejointpoints1.ox.j1=fb.jointCmd.j1;
                threejointpoints1.ox.j2=fb.jointCmd.j2;
                threejointpoints1.ox.j3=fb.jointCmd.j3;
                threejointpoints1.ox.j4=fb.jointCmd.j4;
                threejointpoints1.ox.j5=fb.jointCmd.j5;
                threejointpoints1.ox.j6=fb.jointCmd.j6;

                position_recorder_status[1]= true;
                record_state_display_btn[1]->setStyleSheet("border-image:url(:/CMimage/enable.png)");
                break;
            case QMessageBox::Cancel:
                break;
            default:
                break;
            }
            //record_state_display_btn[1]->setStyleSheet("border-image:url(:/CMimage/enable.png)");
            break;
        case P3_BTN:
            ret = QMessageBox::information(this,"datasave","是否保存数据",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Cancel);
            switch (ret) {
            case QMessageBox::Ok:
                CTRL_GetMotionStatus(&fb);
                threejointpoints1.oy.j1=fb.jointCmd.j1;
                threejointpoints1.oy.j2=fb.jointCmd.j2;
                threejointpoints1.oy.j3=fb.jointCmd.j3;
                threejointpoints1.oy.j4=fb.jointCmd.j4;
                threejointpoints1.oy.j5=fb.jointCmd.j5;
                threejointpoints1.oy.j6=fb.jointCmd.j6;

                position_recorder_status[2]= true;
                record_state_display_btn[2]->setStyleSheet("border-image:url(:/CMimage/enable.png)");
                break;
            case QMessageBox::Cancel:
                break;
            default:
                break;
            }
            //record_state_display_btn[2]->setStyleSheet("border-image:url(:/CMimage/enable.png)");
            break;
        case P4_BTN:
            ret = QMessageBox::information(this,"datasave","是否保存数据",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Cancel);
            switch (ret) {
            case QMessageBox::Ok:
                record_state_display_btn[3]->setStyleSheet("border-image:url(:/CMimage/enable.png)");
                break;
            case QMessageBox::Cancel:
                break;
            default:
                break;
            }
            //record_state_display_btn[3]->setStyleSheet("border-image:url(:/CMimage/enable.png)");
            break;
        case EDIT_BTN:

            for(i=0;i<6;++i)
            {
                position_data[i+1]->setEnabled(true);
            }
            break;
        case ENSURE_BTN:
            //将数据保存
            qDebug()<<"save data";
            for(i=0;i<3;++i)
            {
                for(j=0;j<10;++j)
                {
                    qDebug()<<buf[i][j];
                    if(buf[i][j])
                    {
                        qDebug()<<i<<j;
                        require_current_data();
                        if(i==0)
                        {
                            for(a=0;a<7;++a)
                            {
                                //ConfigSet::settrings.setValue("WCS"+QString::number(j+1,10)+"/num"+QString::number(a+1,10),position_data[a]->text().toDouble());
                                ConfigSet::settrings.setValue("WCS"+QString::number(j+1,10)+"/num"+QString::number(a+1,10),position_data[a]->text());
                            }
                        }
                        else if(i==1)
                        {
                            for(a=0;a<7;++a)
                            {
                                //ConfigSet::settrings.setValue("PCS1"+QString::number(j+1,10)+"/num"+QString::number(a+1,10),position_data[a]->text().toDouble());
                                ConfigSet::settrings.setValue("PCS1"+QString::number(j+1,10)+"/num"+QString::number(a+1,10),position_data[a]->text());
                            }
                        }
                        else if(i==2)
                        {
                            for(a=0;a<7;++a)
                            {
                                //ConfigSet::settrings.setValue("PCS2"+QString::number(j+1,10)+"/num"+QString::number(a+1,10),position_data[a]->text().toDouble());
                                ConfigSet::settrings.setValue("PCS2"+QString::number(j+1,10)+"/num"+QString::number(a+1,10),position_data[a]->text());
                            }
                        }
                    }
                }
            }
            //编辑框为不可编辑状态
            for(j=0;j<6;++j)
            {
                position_data[j+1]->setEnabled(false);
            }
            break;
        case CLEAR_BTN:
            //将显示数据和保存数据设为0
            ret = QMessageBox::warning(this,"warning","是否将数据清除",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Cancel);
            switch (ret) {
            case QMessageBox::Ok:
                listIni<<"注释:"<<"X:0.000"<<"Y:0.000"<<"Z:0.000"<<"A:0.000"<<"B:0.000"<<"C:0.000";
                //清除保存文件中的数据

                for(k=0;k<7;++k)
                {
                    position_data[k]->setText(listIni.at(k));
                }
                //清除文件数据
                for(i=0;i<3;++i)
                {
                    for(j=0;j<10;++j)
                    {
                        if(buf[i][j])
                        {
                            require_current_data();
                            if(i==0)
                            {
                                for(a=0;a<7;++a)
                                {
                                    ConfigSet::settrings.setValue("WCS"+QString::number(j+1,10)+"/num"+QString::number(a+1,10),0);
                                }
                            }
                            else if(i==1)
                            {
                                for(a=0;a<7;++a)
                                {
                                    ConfigSet::settrings.setValue("PCS1"+QString::number(j+1,10)+"/num"+QString::number(a+1,10),0);
                                }
                            }
                            else if(i==2)
                            {
                                for(a=0;a<7;++a)
                                {
                                    ConfigSet::settrings.setValue("PCS2"+QString::number(j+1,10)+"/num"+QString::number(a+1,10),0);
                                }
                            }
                        }
                    }
                }
                break;
            case QMessageBox::Cancel:
                break;
            default:
                break;
            }
        case CALC_BTN:
            //根据记录的位置点值，计算当前坐标系的值，并将数据保存到文件中
            //调用算法接口进行计算
            //将数据保存
            //将数据显示（显示的数据应该调用保存的数据）
            if(!(position_recorder_status[0]&position_recorder_status[1]&position_recorder_status[2]))
            {
                QMessageBox::warning(this,"warning","not recorder all point!",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Cancel);
                return;
            }

            UserCoordianteInformation user1;
            ToolCoordianteInformation tool1;

            for(i=0;i<3;++i)
            {
                for(j=0;j<10;++j)
                {
                    if(buf[i][j])
                    {
                        require_current_data();
                        if(i==0)
                        {
                            for(a=0;a<7;++a)
                            {
                                ConfigSet::settrings.setValue("WCS"+QString::number(j+1,10)+"/num"+QString::number(a+1,10),position_data[a]->text());
                            }
                        }
                        else if(i==1)
                        {
                            CTRL_UserCalibration(&threejointpoints1,&tool1,&user1);
                            position_data[1]->setText(QString::number(user1.x));
                            position_data[2]->setText(QString::number(user1.y));
                            position_data[3]->setText(QString::number(user1.z));
                            position_data[4]->setText(QString::number(user1.a));
                            position_data[5]->setText(QString::number(user1.b));
                            position_data[6]->setText(QString::number(user1.c));
                            for(a=0;a<7;++a)
                            {

                                ConfigSet::settrings.setValue("PCS1"+QString::number(j+1,10)+"/num"+QString::number(a+1,10),position_data[a]->text());
                            }
                        }
                        else if(i==2)
                        {
                            CTRL_UserCalibration(&threejointpoints1,&tool1,&user1);
                            position_data[1]->setText(QString::number(user1.x));
                            position_data[2]->setText(QString::number(user1.y));
                            position_data[3]->setText(QString::number(user1.z));
                            position_data[4]->setText(QString::number(user1.a));
                            position_data[5]->setText(QString::number(user1.b));
                            position_data[6]->setText(QString::number(user1.c));
                            for(a=0;a<7;++a)
                            {
                                ConfigSet::settrings.setValue("PCS2"+QString::number(j+1,10)+"/num"+QString::number(a+1,10),position_data[a]->text());
                            }
                        }
                    }
                }
            }

            //calc complete ,will recorver point ini status
            recorver_points_init_status();

            break;
        default:
            break;
        }
    }
signals:
    void control_one_axis_disnable_sig();
};


class CoordinateManageWidget : public QWidget
{
    Q_OBJECT

public:
    CoordinateManageWidget(QWidget *parent = 0);
    ~CoordinateManageWidget();
private:
    QLineEdit *edit = new QLineEdit(this);
    FaceSelect *faceselect = new FaceSelect(this);
    OriginalBias *originalbias = new OriginalBias(this);
    ThreeOriginal *threeoriginal1 = new ThreeOriginal(this);
    ThreeOriginal *threeorigina12 = new ThreeOriginal(this);
    CurrentUsrID *currentusrid = new CurrentUsrID(this);
    CoordinateSelect *coordinateselect = new CoordinateSelect(this);
    CoordinateEditOperateWidget *coordinateeditoperatewidget = new CoordinateEditOperateWidget(this);
    QVBoxLayout *vb = new QVBoxLayout;
    QVBoxLayout *vb1 = new QVBoxLayout;
    QVBoxLayout *vb2 = new QVBoxLayout;
    QVBoxLayout *vb3 = new QVBoxLayout;
    QHBoxLayout *hb1 = new QHBoxLayout;
    QHBoxLayout *hb2 = new QHBoxLayout;
    QHBoxLayout *hb3 = new QHBoxLayout;


signals:
    void sssig();//点0轴1~10轴恢复初始状态
    void zero_axis_unselected_sig();
    void reload_data_com_sig(int,int);


};

#endif // COORDINATEMANAGEWIDGET_H
