#ifndef ORIGINOFFSETWIDGET_H
#define ORIGINOFFSETWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QGridLayout>
#include <QPalette>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>
//#include "setting/configset.h"
#include "configset.h"
#include "usr_motion_api/usr_motion_api.h"

class OriginStatus:public QFrame//QWidget
{
    Q_OBJECT
public:
    OriginStatus(QWidget *parent = 0)
    {
        this->setStyleSheet(QString::fromUtf8("border:5px solid red"));
        this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        //this->frameGeometry();
        QLabel *label = new QLabel("各轴零位标定状态:",this);
//        label->setFont(QFont("Timers",25,QFont::Bold));
        label->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        for(int i=0;i<9;i++)
        {
            pb[i] = new QPushButton;
//            pb[i]->setFixedSize(QPixmap(":/originoffsetimage/1.png").size());
//            pb[i]->setStyleSheet("border-image:url(:/originoffsetimage/1.png)");
            pb[i]->setFixedSize(QPixmap(":/originoffsetimage/3-"+QString::number(i+1,10)+".png").size());
            pb[i]->setStyleSheet("border-image:url(:/originoffsetimage/3-"+QString::number(i+1,10)+".png)");
            pb[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            pb[i]->setEnabled(false);
        }

        QHBoxLayout *hb = new QHBoxLayout(this);
        QVBoxLayout *vb = new QVBoxLayout(this);
        vb->addWidget(label);

        hb->addWidget(pb[0],1);
        hb->addWidget(pb[1],1);
        hb->addWidget(pb[2],1);
        hb->addWidget(pb[3],1);
        hb->addWidget(pb[4],1);
        hb->addWidget(pb[5],1);
        hb->addWidget(pb[6],1);
        hb->addWidget(pb[7],1);
        hb->addSpacing(40);
        hb->addWidget(pb[8],1);



        hb->setMargin(0);
        hb->setSpacing(0);
        hb->setContentsMargins(0,0,0,0);//left top right buttom
        vb->addLayout(hb);
        this->setLayout(vb);

        origin_status_ini();
    }
    void set_axis_status()
    {
        for(int i=0;i<9;++i)
        {
            if(buf[i])
            {
//                pb[i]->setFixedSize(QPixmap(":/originoffsetimage/11.png").size());
//                pb[i]->setStyleSheet("border-image:url(:/originoffsetimage/11.png)");
                pb[i]->setFixedSize(QPixmap(":/originoffsetimage/3-"+QString::number(i+1,10)+"-1.png").size());
                pb[i]->setStyleSheet("border-image:url(:/originoffsetimage/3-"+QString::number(i+1,10)+"-1.png)");
            }
            else
            {
//                pb[i]->setFixedSize(QPixmap(":/originoffsetimage/1.png").size());
//                pb[i]->setStyleSheet("border-image:url(:/originoffsetimage/1.png)");
                pb[i]->setFixedSize(QPixmap(":/originoffsetimage/3-"+QString::number(i+1,10)+".png").size());
                pb[i]->setStyleSheet("border-image:url(:/originoffsetimage/3-"+QString::number(i+1,10)+".png)");
            }
        }
    }
    void set_specify_axis_status(int i)
    {
//        pb[i]->setFixedSize(QPixmap(":/originoffsetimage/11.png").size());
//        pb[i]->setStyleSheet("border-image:url(:/originoffsetimage/11.png)");
        pb[i]->setFixedSize(QPixmap(":/originoffsetimage/3-"+QString::number(i+1,10)+"-1.png").size());
        pb[i]->setStyleSheet("border-image:url(:/originoffsetimage/3-"+QString::number(i+1,10)+"-1.png)");
        buf[i] = true;
        configset->settrings.setValue("OriginStatus/num"+QString::number(i+1,10),1);
        if(buf[0]==true&&buf[1]==true&&buf[2]==true&&buf[3]==true&&buf[4]==true&&buf[5]==true&&buf[6]==true&&buf[7]==true)
        {
            buf[8]==true;
            pb[8]->setFixedSize(QPixmap(":/originoffsetimage/3-9-1.png").size());
            pb[8]->setStyleSheet("border-image:url(:/originoffsetimage/3-9-1.png)");
            configset->settrings.setValue("OriginStatus/num9",1);
        }
    }

    void origin_status_ini()
    {
        configset->createIni("OriginStatus",9);
        for(int i=0;i<9;++i)
        {
            buf[i] = configset->settrings.value("OriginStatus/num"+QString::number(i+1,10),0).toBool();
            qDebug()<<buf[i]<<configset->settrings.value("OriginStatus/num0",0);
        }
        set_axis_status();
    }

    ~OriginStatus()
    {

    }
private:
    QPushButton *pb[9];
    ConfigSet *configset = new ConfigSet;
    bool buf[9];
};

class EncorderData:public QWidget
{
    Q_OBJECT
public:
    EncorderData(QWidget *parent=0)
    {
        this->setStyleSheet(QString::fromUtf8("border:1px solid red"));
        this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        QGridLayout *gb = new QGridLayout(this);
        label = new QLabel("各轴零位参考点编码器数据：");
        label->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        gb->addWidget(label);
        for(int i=0;i<8;++i)
        {
            edit[i] = new QLineEdit;
            //edit[i]->setText(QString("%1").arg(plucode,4,10,QChar('0')));
            edit[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            if(i<4)
            {
                gb->addWidget(edit[i],1,i);
            }
            else
            {
                gb->addWidget(edit[i],2,i%4);
            }
        }
        this->setLayout(gb);

        recorder_data_ini();
    }
    ~EncorderData()
    {

    }

    void set_encorder_data(int i,qlonglong dl)
    {
        edit[i]->setText(QString::number(dl,10));
    }

    void get_encorder_data(int i,qlonglong *dl)
    {
        //*dl = edit[i]->text().toDouble();
        *dl = edit[i]->text().toLongLong();
    }

    void require_servor_encorder_data(int i,double *dl)
    {
        //如果从伺服驱动器获取编码器的值
    }

    void save_encorder_data(int i,qlonglong dl)
    {
        ConfigSet::settrings.setValue("EncorderData/num"+QString::number(i+1),dl);
    }

    void recorder_data_ini()
    {
        configset->createIni("EncorderData",8);
        for(int i=0;i<8;++i)
        {
            //edit[i]->setText(ConfigSet::settrings.value("EncorderData/num"+QString::number(i+1),0).toString());
            edit[i]->setText(QString("%1").arg(ConfigSet::settrings.value("EncorderData/num"+QString::number(i+1),0).toInt(),4,10,QChar('0')));
        }
    }

private:
    QLabel *label;
    QLineEdit *edit[8];
    ConfigSet *configset = new ConfigSet;
};


class SelectOriginAxis : public QWidget
{
    Q_OBJECT
public:
    SelectOriginAxis(QWidget *parent = 0)
    {
        this->setStyleSheet(QString::fromUtf8("border:1px solid red"));
        this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        QGridLayout *gl = new QGridLayout(this);
        label = new QLabel("请选择要标定记录零位参考点的轴：",this);
        label->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        gl->addWidget(label,0,0,1,8);

        for(int i=0;i<8;++i)
        {
            encord_aix[i] = false;
            pb[i] = new QPushButton(QString::number(i+1,10),this);
            pb[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            gl->addWidget(pb[i],1,i);
        }

        connect(pb[0],SIGNAL(clicked()),this,SLOT(pbslot1()));
        connect(pb[1],SIGNAL(clicked()),this,SLOT(pbslot2()));
        connect(pb[2],SIGNAL(clicked()),this,SLOT(pbslot3()));
        connect(pb[3],SIGNAL(clicked()),this,SLOT(pbslot4()));
        connect(pb[4],SIGNAL(clicked()),this,SLOT(pbslot5()));
        connect(pb[5],SIGNAL(clicked()),this,SLOT(pbslot6()));
        connect(pb[6],SIGNAL(clicked()),this,SLOT(pbslot7()));
        connect(pb[7],SIGNAL(clicked()),this,SLOT(pbslot8()));
    }

    bool encord_aix[8];
    void recover_axis_status()
    {
//        QPalette pal;
        for(int j=0;j<8;++j)
        {
            encord_aix[j]=false;
//            pal = pb[j]->palette();
//            pal.setColor(QPalette::ButtonText,QColor(232,232,232));
//            pb[j]->setPalette(pal);
            pb[j]->setStyleSheet("background-color:rgb(232,232,232)");
        }
    }

    ~SelectOriginAxis()
    {

    }
private:
    QLabel *label;
    QPushButton *pb[8];

private slots:
    void pbslot1()
    {
        QPalette pal;
        //static bool clicked = false;
        if(!encord_aix[0])
        {
            encord_aix[0] = !encord_aix[0];
            pal = pb[0]->palette();
            pal.setColor(QPalette::ButtonText,QColor(255,0,0));
            pb[0]->setPalette(pal);
            pb[0]->setStyleSheet("background-color:rgb(0,238,118)");
        }
        else
        {
            encord_aix[0] = !encord_aix[0];
            pal = pb[0]->palette();
            pal.setColor(QPalette::ButtonText,QColor(0,0,0));
            pb[0]->setPalette(pal);
            pb[0]->setStyleSheet("background-color:rgb(232,232,232)");
        }
    }
    void pbslot2()
    {
        QPalette pal;
        //static bool clicked = false;
        if(!encord_aix[1])
        {
            encord_aix[1] = !encord_aix[1];
            pal = pb[1]->palette();
            pal.setColor(QPalette::ButtonText,QColor(255,0,0));
            pb[1]->setPalette(pal);
            pb[1]->setStyleSheet("background-color:rgb(0,238,118)");
        }
        else
        {
            encord_aix[1] = !encord_aix[1];
            pal = pb[1]->palette();
            pal.setColor(QPalette::ButtonText,QColor(0,0,0));
            pb[1]->setPalette(pal);
            pb[1]->setStyleSheet("background-color:rgb(232,232,232)");
        }
    }
    void pbslot3()
    {
        QPalette pal;
        //static bool clicked = false;
        if(!encord_aix[2])
        {
            encord_aix[2] = !encord_aix[2];
            pal = pb[2]->palette();
            pal.setColor(QPalette::ButtonText,QColor(255,0,0));
            pb[2]->setPalette(pal);
            pb[2]->setStyleSheet("background-color:rgb(0,238,118)");
        }
        else
        {
            encord_aix[2] = !encord_aix[2];
            pal = pb[2]->palette();
            pal.setColor(QPalette::ButtonText,QColor(0,0,0));
            pb[2]->setPalette(pal);
            pb[2]->setStyleSheet("background-color:rgb(232,232,232)");
        }
    }
    void pbslot4()
    {
        QPalette pal;
        //static bool clicked = false;
        if(!encord_aix[3])
        {
            encord_aix[3] = !encord_aix[3];
            pal = pb[3]->palette();
            pal.setColor(QPalette::ButtonText,QColor(255,0,0));
            pb[3]->setPalette(pal);
            pb[3]->setStyleSheet("background-color:rgb(0,238,118)");
        }
        else
        {
            encord_aix[3] = !encord_aix[3];
            pal = pb[3]->palette();
            pal.setColor(QPalette::ButtonText,QColor(0,0,0));
            pb[3]->setPalette(pal);
            pb[3]->setStyleSheet("background-color:rgb(232,232,232)");
        }
    }
    void pbslot5()
    {
        QPalette pal;
        //static bool clicked = false;
        if(!encord_aix[4])
        {
            encord_aix[4] = !encord_aix[4];
            pal = pb[4]->palette();
            pal.setColor(QPalette::ButtonText,QColor(255,0,0));
            pb[4]->setPalette(pal);
            pb[4]->setStyleSheet("background-color:rgb(0,238,118)");
        }
        else
        {
            encord_aix[4] = !encord_aix[4];
            pal = pb[4]->palette();
            pal.setColor(QPalette::ButtonText,QColor(0,0,0));
            pb[4]->setPalette(pal);
            pb[4]->setStyleSheet("background-color:rgb(232,232,232)");
        }
    }
    void pbslot6()
    {
        QPalette pal;
        //static bool clicked = false;
        if(!encord_aix[5])
        {
            encord_aix[5] = !encord_aix[5];
            pal = pb[5]->palette();
            pal.setColor(QPalette::ButtonText,QColor(255,0,0));
            pb[5]->setPalette(pal);
            pb[5]->setStyleSheet("background-color:rgb(0,238,118)");
        }
        else
        {
            encord_aix[5] = !encord_aix[5];
            pal = pb[5]->palette();
            pal.setColor(QPalette::ButtonText,QColor(0,0,0));
            pb[5]->setPalette(pal);
            pb[5]->setStyleSheet("background-color:rgb(232,232,232)");
        }
    }
    void pbslot7()
    {
        QPalette pal;
        //static bool clicked = false;
        if(!encord_aix[6])
        {
            encord_aix[6] = !encord_aix[6];
            pal = pb[6]->palette();
            pal.setColor(QPalette::ButtonText,QColor(255,0,0));
            pb[6]->setPalette(pal);
            pb[6]->setStyleSheet("background-color:rgb(0,238,118)");
        }
        else
        {
            encord_aix[6] = !encord_aix[6];
            pal = pb[6]->palette();
            pal.setColor(QPalette::ButtonText,QColor(0,0,0));
            pb[6]->setPalette(pal);
            pb[6]->setStyleSheet("background-color:rgb(232,232,232)");
        }
    }
    void pbslot8()
    {
        QPalette pal;
        //static bool clicked = false;
        if(!encord_aix[7])
        {
            encord_aix[7] = !encord_aix[7];
            pal = pb[7]->palette();
            pal.setColor(QPalette::ButtonText,QColor(255,0,0));
            pb[7]->setPalette(pal);
            pb[7]->setStyleSheet("background-color:rgb(0,238,118)");
        }
        else
        {
            encord_aix[7] = !encord_aix[7];
            pal = pb[7]->palette();
            pal.setColor(QPalette::ButtonText,QColor(0,0,0));
            pb[7]->setPalette(pal);
            pb[7]->setStyleSheet("background-color:rgb(232,232,232)");
        }
    }
};

class OriginOffsetWidget : public QWidget
{
    Q_OBJECT

public:
    OriginOffsetWidget(QWidget *parent = 0);
    ~OriginOffsetWidget();

private:
    QLineEdit *edit = new QLineEdit(this);
    OriginStatus *origin_status = new OriginStatus(this);
    EncorderData *encorder_data = new EncorderData(this);
    SelectOriginAxis *selectoa = new SelectOriginAxis(this);
    QPushButton *pb[4];// = new QPushButton(this);
    QVBoxLayout *vb  = new QVBoxLayout(this);
    QHBoxLayout *hb = new QHBoxLayout(this);

    QTimer *timer;

private slots:
    void record_origin_press_slot();
    void record_origin_release_slot();
    void ensure_encorde_origin();

};

#endif // ORIGINOFFSETWIDGET_H
