#include "currentpositionwidget.h"
#include <QDebug>

CurrentPositionWidget::CurrentPositionWidget(QWidget *parent)
    : QWidget(parent)
{
    int i;
    QStringList list1,list2,list3;
    list1<<"坐标系："<<"J1"<<"J2"<<"J3"<<"J4"<<"J5"<<"J6"<<"Ex1"<<"Ex2";
    list2<<"坐标系："<<"X"<<"Y"<<"Z"<<"A"<<"B"<<"C"<<"Ex1"<<"Ex2";
    list3<<"机器人坐标系"<<"世界坐标系"<<"工件坐标系1"<<"工件坐标系2";
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    titleedit = new QLineEdit(tr("当前位置"),this);
    titleedit->setEnabled(false);
    titleedit->setStyleSheet("background-color:rgb(0,238,238)");
    titleedit->setAlignment(Qt::AlignCenter);
    QPalette palette;
    palette.setColor(QPalette::Text,Qt::white);
    titleedit->setPalette(palette);
    titleedit->setFont(QFont("Timers",28,QFont::Bold));
    titleedit->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    combox = new QComboBox(this);
    combox->addItems(list3);

    qDebug()<<"11111111";
    for(i=0;i<9;++i)
    {
        joint_position_label[i] = new QLineEdit(list1.at(i),this);
        joint_position_label[i]->setEnabled(false);
        joint_position_label[i]->setAlignment(Qt::AlignCenter);
        joint_position_label[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

        joint_position[i] = new QLineEdit(this);
        joint_position[i]->setAlignment(Qt::AlignCenter);
        joint_position[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

        qDebug()<<"222";
        fl1->addRow(joint_position_label[i],joint_position[i]);
        //fl1->setSpacing(0);
        qDebug()<<"333";
        other_position_label[i] = new QLineEdit(list2.at(i),this);
        other_position_label[i]->setEnabled(false);
        other_position_label[i]->setAlignment(Qt::AlignCenter);
        other_position_label[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        qDebug()<<"4444";
        if(i<8)
        {
            other_position[i] = new QLineEdit(this);
            other_position[i]->setAlignment(Qt::AlignCenter);
            other_position[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        }
        qDebug()<<"5555";
        if(i==0)
        {
            fl2->addRow(other_position_label[i],combox);
        }
        else
        {
            fl2->addRow(other_position_label[i],other_position[i-1]);
        }

    }
    qDebug()<<"22222";
    joint_position[0]->setText("关节坐标系");
    joint_position[0]->setEnabled(false);
    fl1->setSpacing(0);
    fl1->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
//    fl1->setRowWrapPolicy(QFormLayout::DontWrapRows);
//    fl1->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);

    fl2->setSpacing(0);
    fl2->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
//    fl2->setRowWrapPolicy(QFormLayout::DontWrapRows);
//    fl2->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);

    hb1->addSpacing(20);
    hb1->addLayout(fl1);
    hb1->addSpacing(20);
    hb1->addLayout(fl2);
    hb1->addSpacing(20);

    vb->addWidget(titleedit);
    vb->addSpacing(20);
    vb->addLayout(hb1);
    vb->addSpacing(20);

    vb->setStretch(0,1);
    vb->setStretch(1,1);
    vb->setStretch(2,7);
    vb->setStretch(3,1);

    this->setLayout(vb);

    myTimerId = startTimer(3000);

}

CurrentPositionWidget::~CurrentPositionWidget()
{

}

void CurrentPositionWidget::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==myTimerId)
    {
        for(int i=0;i<8;++i)
        {
            joint_position[i+1]->setText("ddd");
            other_position[i]->setText("d111");
        }
    }
    else{
        QWidget::timerEvent(event);
    }
}
















