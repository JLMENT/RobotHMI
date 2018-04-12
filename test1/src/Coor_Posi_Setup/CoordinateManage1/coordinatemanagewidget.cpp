#include "coordinatemanagewidget.h"

bool Interface_Enable_Status = false;
bool buf[3][10]={{0}};
bool buf_coor[3]={0};

CoordinateManageWidget::CoordinateManageWidget(QWidget *parent)
    : QWidget(parent)
{
    setGeometry(0,0,500,700);
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->resize(300,300);
    qDebug()<<"00";
    edit->setMinimumSize(400,60);
    edit->setText("坐标系管理");
    edit->setEnabled(false);
    edit->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    edit->setStyleSheet("background-color:rgb(0,238,238)");
    QPalette palette;
    palette.setColor(QPalette::Text,Qt::white);
    edit->setPalette(palette);
    edit->setFont(QFont("Timers",28,QFont::Bold));
    edit->setAlignment(Qt::AlignCenter);


    vb1->addWidget(originalbias);
    vb1->addWidget(faceselect);
    vb1->addWidget(currentusrid);
    vb1->setStretch(0,5);
    vb1->setStretch(1,1);
    vb1->setStretch(2,5);

    vb2->addWidget(threeoriginal1);
    vb2->addWidget(threeorigina12);
    vb2->setStretch(0,1);
    vb2->setStretch(1,1);

    hb1->addLayout(vb2);
    hb1->addWidget(coordinateeditoperatewidget);
    hb1->setStretch(0,1);
    hb1->setStretch(1,3);

    qDebug()<<"11";
    vb3->addWidget(coordinateselect);
    qDebug()<<"11";
    vb3->addLayout(hb1);
    vb3->setStretch(0,1);
    vb3->setStretch(1,5);


    hb2->addLayout(vb1);
    hb2->addLayout(vb3);
    hb2->setStretch(0,1);
    hb2->setStretch(1,3);


    vb->addWidget(edit);
    vb->addLayout(hb2);
    vb->setStretch(0,1);
    vb->setStretch(1,7);

    connect(coordinateeditoperatewidget,SIGNAL(control_one_axis_disnable_sig()),this,SIGNAL(sssig()));
    connect(this,SIGNAL(sssig()),coordinateselect,SLOT(one_disnable_slot()));//1~10 axis setup false
    connect(this,SIGNAL(sssig()),faceselect,SLOT(face_select_ini()));

    connect(coordinateselect,SIGNAL(axis_selected_sig()),this,SIGNAL(zero_axis_unselected_sig()));
    connect(this,SIGNAL(zero_axis_unselected_sig()),coordinateeditoperatewidget,SLOT(zero_unselected_slot()));
    connect(this,SIGNAL(zero_axis_unselected_sig()),faceselect,SLOT(face_enable_select()));

    connect(coordinateselect,SIGNAL(reload_data_sig(int,int)),this,SIGNAL(reload_data_com_sig(int,int)));
    connect(this,SIGNAL(reload_data_com_sig(int,int)),coordinateeditoperatewidget,SLOT(reload_data_slot(int,int)));

    this->setLayout(vb);

}

CoordinateManageWidget::~CoordinateManageWidget()
{

}
