#include "form_num.h"
#include "ui_form_num.h"
#include "QStringList"
#include <QDebug>
#include <QMessageBox>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    up_page_status=0;
    down_page_status=0;
    page_status=0;
    left_change_status=0;
    right_change_status=0;
    style_status = 0;

    setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);

    QStringList list1;
    QStringList list2;
    QStringList list3;
    list1<<"1"<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8";
    list2<<"0"<<"0"<<"0"<<"0"<<"0"<<"0"<<"0"<<"0"<<"0";
    list3<<"0."<<"0."<<"0."<<"0."<<"0."<<"0."<<"0."<<"0."<<"0.";


    num_sequence_number[0] = new QLineEdit;
    num_sequence_number[0]->setText("序号");
    num_sequence_number[0]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    num_sequence_number[0]->setEnabled(false);
    num_sequence_number[0]->setAlignment(Qt::AlignCenter);
    //num_content[0] = new QLineEdit;
    num_content[0] = new DigetEdit;
    num_content[0]->setText("内容");
    num_content[0]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    num_content[0]->setEnabled(false);
    num_content[0]->setAlignment(Qt::AlignCenter);
    //num_name[0] = new QLineEdit;
    num_name[0] = new EditKeyboard;
    num_name[0]->setText("名称");
    num_name[0]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    num_name[0]->setEnabled(false);
    num_name[0]->setAlignment(Qt::AlignCenter);
    for(int i=1;i<9;i++)
    {
        num_sequence_number[i] = new QLineEdit;
        num_sequence_number[i]->setText(list1.at(i));
        num_sequence_number[i]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
        num_sequence_number[i]->setEnabled(false);
        num_sequence_number[i]->setAlignment(Qt::AlignCenter);
        //num_content[i] = new QLineEdit;
        num_content[i] = new DigetEdit;
        num_content[i]->setText(list2.at(i));
        num_content[i]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
        num_content[i]->setAlignment(Qt::AlignCenter);
        //num_name[i] = new QLineEdit;
        //num_name[i]->setText(list1.at(i));
        num_name[i] = new EditKeyboard;
        num_name[i]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
        num_name[i]->setAlignment(Qt::AlignCenter);
    }
    style_change_left->setText("<-");
    style_change_right->setText("->");
    style_change_left->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    style_change_right->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);

    for(int l=0;l<4;++l)
    {
        up_down_button[l] = new QPushButton;
    }

    //up_down_button[0]->setEnabled(false);
    //up_down_button[1]->setEnabled(false);
    up_down_button[0]->setText("保存");
    up_down_button[1]->setText("取消");
    up_down_button[2]->setText("上一页");
    up_down_button[3]->setText("下一页");

    up_down_button[0]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    up_down_button[1]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    up_down_button[2]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    up_down_button[3]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    style_display->setText("整数型");
    style_display->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    style_display->setEnabled(false);
    style_display->setAlignment(Qt::AlignCenter);

    //vb->setParent(this);
    hb1->addSpacing(80);
    hb1->addWidget(style_change_left);
    hb1->addWidget(style_display);
    hb1->addWidget(style_change_right);
    //hb1->setMargin(0);
    hb1->addSpacing(80);

    hb2->addSpacing(20);
    hb2->addWidget(num_sequence_number[0]);
    hb2->addWidget(num_content[0]);
    hb2->addWidget(num_name[0]);
    hb2->addSpacing(20);

    for(int j=1;j<9;++j)
    {
        vb1->addWidget(num_sequence_number[j]);
        vb2->addWidget(num_content[j]);
        vb3->addWidget(num_name[j]);
    }
    hb3->addSpacing(20);
    hb3->addLayout(vb1);
    hb3->addLayout(vb2);
    hb3->addLayout(vb3);
    hb3->addSpacing(20);

    for(int k=0;k<4;k++)
    {
        hb4->addWidget(up_down_button[k]);
    }
    hb4->stretch(0);
    hb4->setSpacing(0);

    vb->addLayout(hb1);
    vb->addLayout(hb2);
    vb->addLayout(hb3);
    vb->addLayout(hb4);
    vb->setStretch(0,2);
    vb->setStretch(1,1);
    vb->setStretch(2,8);
    vb->setStretch(3,2);

    this->setLayout(vb);

    connect(up_down_button[0],SIGNAL(clicked()),this,SLOT(save_value_slot()));
    connect(up_down_button[1],SIGNAL(clicked()),this,SLOT(cancle_value_slot()));
    connect(up_down_button[2],SIGNAL(clicked()),this,SLOT(up_page_slot()));
    connect(up_down_button[3],SIGNAL(clicked()),this,SLOT(down_page_slot()));
    connect(style_change_left,SIGNAL(clicked()),this,SLOT(left_change_slot()));
    connect(style_change_right,SIGNAL(clicked()),this,SLOT(right_change_slot()));

    init_number_table();
}

Form::~Form()
{
    delete ui;
}

void Form::up_page_slot()
{
    int i;
    QStringList numlist;
    numlist<<"9"<<"9"<<"10"<<"11"<<"12"<<"13"<<"14"<<"15"<<"16"<<"17"<<"18"<<"19"<<"20"<<"21"<<"22"<<"23"<<"24";
    QStringList numlist1;
    numlist1<<"1"<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8";
    if(page_status==0)
    {
//        for(i=1;i<9;++i)
//        {
//            num_sequence_number[i]->setText(numlist.at(i+8));
//        }
//        page_status=1;
        return;
    }
    else if(page_status==1)
    {
        for(i=1;i<9;++i)
        {
            num_sequence_number[i]->setText(numlist1.at(i));
        }

        page_status=0;
        read_number_data(style_status,page_status);

    }
    else if(page_status==2)
    {
        for(i=1;i<9;++i)
        {
            num_sequence_number[i]->setText(numlist.at(i));
        }
        page_status=1;
        read_number_data(style_status,page_status);
        return;
    }
}

void Form::down_page_slot()
{
    int i;
    QStringList numlist;
    numlist<<"9"<<"9"<<"10"<<"11"<<"12"<<"13"<<"14"<<"15"<<"16"<<"17"<<"18"<<"19"<<"20"<<"21"<<"22"<<"23"<<"24";
    QStringList numlist1;
    numlist1<<"1"<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8";
    if(page_status==0)
    {
        for(i=1;i<9;++i)
        {
            num_sequence_number[i]->setText(numlist.at(i));
        }
        page_status=1;
        read_number_data(style_status,page_status);
    }
    else if(page_status==1)
    {
        for(i=1;i<9;++i)
        {
            num_sequence_number[i]->setText(numlist.at(i+8));
        }

        page_status=2;
        read_number_data(style_status,page_status);
    }
    else if(page_status==2)
    {
//        for(i=1;i<9;++i)
//        {
//            num_sequence_number[i]->setText(numlist1.at(i));
//        }
//        page_status=0;
        return;
    }
}

void Form::left_change_slot()
{
    if(style_status==0)
    {
        return;
    }
    else if(style_status==1)
    {
        style_display->setText("整数型");
        style_status=0;
        if(page_status!=0)
        {
            page_status=0;
        }
        //return_start_page();
        read_number_data(style_status,page_status);
    }
    else if(style_status==2)
    {
        style_display->setText("实数型");
        style_status=1;
        if(page_status!=0)
        {
            page_status=0;
        }
        //return_start_page();
        read_number_data(style_status,page_status);

    }
}

void Form::right_change_slot()
{
    if(style_status==0)
    {
        style_display->setText("实数型");
        style_status=1;
        if(page_status!=0)
        {
            page_status=0;
        }
        //return_start_page();
        read_number_data(style_status,page_status);

    }
    else if(style_status==1)
    {
        style_display->setText("byte型");
        style_status=2;
        if(page_status!=0)
        {
            page_status=0;
        }
        //return_start_page();
        read_number_data(style_status,page_status);
    }
    else if(style_status==2)
    {
        return;
    }
}

void Form::save_value_slot()
{
    save_modify_data();
}

void Form::cancle_value_slot()
{
    read_number_data(style_status,page_status);
}

void Form::return_start_page()
{
    int i;
    QStringList numlist1;
    numlist1<<"1"<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8";
    QStringList numlist2;
    QStringList numlist3;
    QStringList numlist4;
    numlist2<<"0"<<"0"<<"0"<<"0"<<"0"<<"0"<<"0"<<"0"<<"0";
    numlist3<<"0."<<"0."<<"0."<<"0."<<"0."<<"0."<<"0."<<"0."<<"0.";
    numlist4<<"0x"<<"0x"<<"0x"<<"0x"<<"0x"<<"0x"<<"0x"<<"0x"<<"0x";

    if(style_status==0)
    {
        for(i=1;i<9;i++)
        {
            num_sequence_number[i]->setText(numlist1.at(i));
            num_content[i]->setText(numlist2.at(i));
            page_status=0;
        }
    }
    else if(style_status==1)
    {
        for(i=1;i<9;i++)
        {
            num_sequence_number[i]->setText(numlist1.at(i));
            num_content[i]->setText(numlist3.at(i));
            page_status=0;
        }
    }
    else if(style_status==2)
    {
        for(i=1;i<9;i++)
        {
            num_sequence_number[i]->setText(numlist1.at(i));
            num_content[i]->setText(numlist4.at(i));
            page_status=0;
        }
    }
}

void Form::init_number_table()
{
    for(int i = 0;i<8;i++)
    {
        //numerictypexml->readxml("interger",i);
        numerictypexml->domreadxml("interger",QString::number(i,10));
        num_name[i+1]->setText(numerictypexml->name);
        num_content[i+1]->setText(numerictypexml->content);
    }

}

void Form::read_number_data(int style_status_value,int page_status_value)
{
    if(style_status_value==0&&page_status_value==0)
    {
        for(int i = 0;i<8;i++)
        {
            numerictypexml->domreadxml("interger",QString::number(i,10));
            num_name[i+1]->setText(numerictypexml->name);
            num_content[i+1]->setText(numerictypexml->content);
        }
    }
    else if(style_status_value==0&&page_status_value==1)
    {
        for(int i = 0;i<8;i++)
        {
            numerictypexml->domreadxml("interger",QString::number(i+8,10));
            num_name[i+1]->setText(numerictypexml->name);
            num_content[i+1]->setText(numerictypexml->content);
        }
    }
    else if(style_status_value==0&&page_status_value==2)
    {
        for(int i = 0;i<8;i++)
        {
            numerictypexml->domreadxml("interger",QString::number(i+16,10));
            num_name[i+1]->setText(numerictypexml->name);
            num_content[i+1]->setText(numerictypexml->content);
        }
    }
    else if(style_status_value==1&&page_status_value==0)
    {
        for(int i = 0;i<8;i++)
        {
            numerictypexml->domreadxml("realnumber",QString::number(i,10));
            num_name[i+1]->setText(numerictypexml->name);
            num_content[i+1]->setText(numerictypexml->content);
        }
    }
    else if(style_status_value==1&&page_status_value==1)
    {
        for(int i = 0;i<8;i++)
        {
            numerictypexml->domreadxml("realnumber",QString::number(i+8,10));
            num_name[i+1]->setText(numerictypexml->name);
            num_content[i+1]->setText(numerictypexml->content);
        }
    }
    else if(style_status_value==1&&page_status_value==2)
    {
        for(int i = 0;i<8;i++)
        {
            numerictypexml->domreadxml("realnumber",QString::number(i+16,10));
            num_name[i+1]->setText(numerictypexml->name);
            num_content[i+1]->setText(numerictypexml->content);
        }
    }
    else if(style_status_value==2&&page_status_value==0)
    {
        for(int i = 0;i<8;i++)
        {
            numerictypexml->domreadxml("byte",QString::number(i,10));
            num_name[i+1]->setText(numerictypexml->name);
            num_content[i+1]->setText(numerictypexml->content);
        }
    }
    else if(style_status_value==2&&page_status_value==1)
    {
        for(int i = 0;i<8;i++)
        {
            numerictypexml->domreadxml("byte",QString::number(i+8,10));
            num_name[i+1]->setText(numerictypexml->name);
            num_content[i+1]->setText(numerictypexml->content);
        }
    }
    else if(style_status_value==2&&page_status_value==2)
    {
        for(int i = 0;i<8;i++)
        {
            numerictypexml->domreadxml("byte",QString::number(i+16,10));
            num_name[i+1]->setText(numerictypexml->name);
            num_content[i+1]->setText(numerictypexml->content);
        }
    }

}

void Form::save_modify_data()
{
    QString name_value;
    QString content_value;
    int i;
    if(style_status==0&&page_status==0)
    {
        for(i=0;i<8;++i)
        {
            name_value = num_name[i+1]->text();
            content_value = num_content[i+1]->text();
            numerictypexml->writexml1("interger",i,name_value,content_value);
        }
        QMessageBox::information(NULL,"title","save success!",QMessageBox::Yes);
    }
    else if(style_status==0&&page_status==1)
    {
        for(i=0;i<8;++i)
        {
            name_value = num_name[i+1]->text();
            content_value = num_content[i+1]->text();
            numerictypexml->writexml1("interger",i+8,name_value,content_value);
        }
        QMessageBox::information(NULL,"title","save success!",QMessageBox::Yes);
    }
    else if(style_status==0&&page_status==2)
    {
        for(i=0;i<8;++i)
        {
            name_value = num_name[i+1]->text();
            content_value = num_content[i+1]->text();
            numerictypexml->writexml1("interger",i+16,name_value,content_value);
        }
        QMessageBox::information(NULL,"title","save success!",QMessageBox::Yes);
    }
    else if(style_status==1&&page_status==0)
    {
        for(i=0;i<8;++i)
        {
            name_value = num_name[i+1]->text();
            content_value = num_content[i+1]->text();
            numerictypexml->writexml1("realnumber",i,name_value,content_value);
        }
        QMessageBox::information(NULL,"title","save success!",QMessageBox::Yes);
    }
    else if(style_status==1&&page_status==1)
    {
        for(i=0;i<8;++i)
        {
            name_value = num_name[i+1]->text();
            content_value = num_content[i+1]->text();
            numerictypexml->writexml1("realnumber",i+8,name_value,content_value);
        }
        QMessageBox::information(NULL,"title","save success!",QMessageBox::Yes);
    }
    else if(style_status==1&&page_status==2)
    {
        for(i=0;i<8;++i)
        {
            name_value = num_name[i+1]->text();
            content_value = num_content[i+1]->text();
            numerictypexml->writexml1("realnumber",i+16,name_value,content_value);
        }
        QMessageBox::information(NULL,"title","save success!",QMessageBox::Yes);
    }
    else if(style_status==2&&page_status==0)
    {
        for(i=0;i<8;++i)
        {
            name_value = num_name[i+1]->text();
            content_value = num_content[i+1]->text();
            numerictypexml->writexml1("byte",i,name_value,content_value);
        }
        QMessageBox::information(NULL,"title","save success!",QMessageBox::Yes);
    }
    else if(style_status==2&&page_status==1)
    {
        for(i=0;i<8;++i)
        {
            name_value = num_name[i+1]->text();
            content_value = num_content[i+1]->text();
            numerictypexml->writexml1("byte",i+8,name_value,content_value);
        }
        QMessageBox::information(NULL,"title","save success!",QMessageBox::Yes);
    }
    else if(style_status==2&&page_status==2)
    {
        for(i=0;i<8;++i)
        {
            name_value = num_name[i+1]->text();
            content_value = num_content[i+1]->text();
            numerictypexml->writexml1("byte",i+16,name_value,content_value);
        }
        QMessageBox::information(NULL,"title","save success!",QMessageBox::Yes);
    }

}

void Form::cancle_modify_data()
{

}


