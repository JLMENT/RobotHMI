#include "dhspaceparem.h"
#include <QDebug>

DHSpaceParem::DHSpaceParem(QWidget *parent) : QWidget(parent)
{
    //创建配置参数
    configset->createIni("dhparem",13);

    QString str;
    double a=1.0;
    double *f64;
    f64=&a;
    qDebug()<<11;
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->setMinimumSize(100,100);
    this->setBaseSize(300,300);
    int i;
    list<<"P1"<<"P2"<<"P3"<<"P4"<<"P5"<<"P6"
       <<"P7"<<"P8"<<"P9"<<"P10"<<"P11"<<"P12"
      <<"P13"<<"对应轴的电机编码值"
     <<"Axis5=MAxis5+(P8/P9)*Axis4"<<"Axis6=MAxis6+(P10/P11)*(P12/P13)*Axis5";

    for(i=0;i<30;++i)
    {
        //edit[i] = new QLineEdit;
        edit[i] = new DigetEdit;
        edit[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    }

    piclabel->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    for(i=0;i<13;++i)
    {
        edit[i]->setText(list.at(i));
        edit[i]->setEnabled(false);
        str  = configset->settrings.value("dhparem/num"+QString::number(i+1,10),0).toString();
        //edit[i+13]->setText(configset->settrings.value("dhparem/num"+QString::number(i+1,10),0).toString());
        if(i>=0&&i<5)    //add robot setup 20180321
        {
            CTRL_SetPUMA(str.toDouble(),i+1);
            //CTRL_SetPUMA(1.254,i+1);
            CTRL_GetPUMA(f64,i+1);
            edit[i+13]->setText(QString::number(*f64,10,4));
        }
    }

    edit[26]->setText(list.at(13));
    edit[27]->setText(list.at(14));
    edit[28]->setText(list.at(15));

    edit[29]->setText("DH空间参数设置");
    edit[29]->setEnabled(false);
    //axis_title->setStyleSheet("background-color:blue");
    edit[29]->setStyleSheet("background-color:rgb(0,238,238)");
    edit[29]->setAlignment(Qt::AlignCenter);

    QPixmap pixmap("dh.bmp");
    piclabel->setPixmap(pixmap);
    piclabel->setScaledContents(true);


    for(i=0;i<13;++i)
    {
        fl->addWidget(edit[i],i,0);
        fl->addWidget(edit[i+13],i,1);
//        fl->setRowStretch(0,1);
//        fl->setRowStretch(1,3);

        //fl->addRow(edit[i],edit[13+i]);
        //edit[i]->setMinimumSize(5,5);
    }
    savebutton->setText("save");
    addbutton->setText("additem");
    fl->addWidget(savebutton);
    fl->addWidget(addbutton);
    fl->setColumnStretch(0,1);
    fl->setColumnStretch(1,3);
    //fl->SetFixedSize;
    //fl->SetMinimumSize(50,100);

    QVBoxLayout *vl1 = new QVBoxLayout;
    vl1->addWidget(piclabel);
    vl1->addWidget(edit[26]);
    vl1->addWidget(edit[27]);
    vl1->addWidget(edit[28]);
    vl1->setStretch(0,11);
    vl1->setStretch(1,1);
    vl1->setStretch(2,1);
    vl1->setStretch(3,1);


    QHBoxLayout *hl1 = new QHBoxLayout;
    hl1->addLayout(vl1);
    hl1->addLayout(fl);
    hl1->setStretch(0,5);
    hl1->setStretch(1,1);

    QVBoxLayout *vb = new QVBoxLayout(this);
    //edit[29]->setText();
    vb->addWidget(edit[29]);
    vb->addLayout(hl1);
    vb->setStretch(0,2);
    vb->setStretch(1,8);

//    savebutton->setText("save");
//    savebutton->move(50,50);

    connect(savebutton,SIGNAL(clicked()),this,SLOT(dhsave()));
    connect(addbutton,SIGNAL(clicked()),this,SLOT(dhadd()));


    this->setLayout(vb);



}

void DHSpaceParem::dhsave()
{
    int i;
    double a = 1.0;
    double *f64 = &a;
    QString str;
    for(i=0;i<13;++i)
    {
        //ConfigSet::settrings.setValue("dhparem/num"+QString::number(i+1,10),edit[i+13]->text());
        if(i<=0&&i<5)//add robot setup 20180321
        {
            str = edit[i+13]->text();
            CTRL_SetPUMA(str.toDouble(),i+1);
            CTRL_GetPUMA(f64,i+1);
            edit[i+13]->setText(QString::number(*f64,10,4));
            ConfigSet::settrings.setValue("dhparem/num"+QString::number(i+1,10),edit[i+13]->text());
        }
    }
}

void DHSpaceParem::dhadd()
{
    if(ConfigSet::settrings.value("addpp/num0").toString()!="yes")
    {
    configset->settrings.beginGroup("addapp");
    configset->settrings.setValue("num0","yes");
    for(int i=1;i<=13;++i)
    {
        configset->settrings.setValue("num"+QString::number(i,10),0);
    }
    configset->settrings.endGroup();
    }
}
