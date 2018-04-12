#include "positionseriate.h"
#include "ui_positionseriate.h"
#include "usr_motion_api/usr_motion_api.h"
#include <QTimer>

PositionSeriate::PositionSeriate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PositionSeriate)
{
    ui->setupUi(this);
    xmlcancle1 = new XmlCancle;

    QTimer *timer1 = new QTimer(this);

    connect(timer1,SIGNAL(timeout()),this,SLOT(refresh_current_position()));
    timer1->start(100);
}

PositionSeriate::~PositionSeriate()
{
    delete ui;
}

void PositionSeriate::on_pushButton_new_position_clicked()
{
    qDebug()<<"posi 1aa";
    //QString posi_variable1;
    //posi_variable1 = ui->lineEdit_posi_variable->text();
    PositionData posi_data1;
    qDebug()<<"posi 1111bbbbbbbbb";
    posi_data1.buf[0] = ui->lineEdit_posi_variable->text();
    //posi_data1.buf[1] = ui->lineEdit_jj1->text();
    qDebug()<<"posi 1111111111111";
    if(ui->comboBox_po_co_select->currentIndex()==0)
    {
        posi_data1.buf[1] = "Join";
    }
    else if(ui->comboBox_po_co_select->currentIndex()==1)
    {
        posi_data1.buf[1] = "World";
    }
    else if(ui->comboBox_po_co_select->currentIndex()==2)
    {
        posi_data1.buf[1] = "Cylindrical";
    }
    else if(ui->comboBox_po_co_select->currentIndex()==3)
    {
        posi_data1.buf[1] = "Tool";
    }
    else if(ui->comboBox_po_co_select->currentIndex()==4)
    {
        posi_data1.buf[1] = "Workpiece";
    }
    qDebug()<<"posi 22222221AAAAA";
    posi_data1.buf[2] = ui->lineEdit_posS_Sjj1->text();
    qDebug()<<"posi_2BBBBBB";
    posi_data1.buf[3] = ui->lineEdit_posS_Sjj2->text();
    qDebug()<<"posi 2CCCCCCCCCC";
    posi_data1.buf[4] = ui->lineEdit_posS_Sjj3->text();
    posi_data1.buf[5] = ui->lineEdit_posS_Sjj4->text();
    posi_data1.buf[6] = ui->lineEdit_posS_Sjj5->text();
    qDebug()<<"posi 2DDDDDDDDDDDDD";
    posi_data1.buf[7] = ui->lineEdit_posS_Sjj6->text();

    qDebug()<<"into xml";

    xmlcancle1->input_position_data(posi_data1,program_filename);

}

void PositionSeriate::on_pushButton_select_position_clicked()
{
    QString posi_variable1;
    posi_variable1 = ui->lineEdit_posi_variable->text();
    if(posi_variable1.isNull())
    {
        return;
    }
    else
    {
        xmlcancle1->delete_position_data(program_filename,posi_variable1);
    }
}

void PositionSeriate::on_pushButton_pos_save_clicked()
{
    xmlcancle1->require_position_variable();
    emit refresh_posi_vari_sig();
}

void PositionSeriate::refresh_current_position()//get current position
{
    MotionFeedback fb;
    CTRL_GetMotionStatus(&fb);
    ui->lineEdit_posC_j1->setText(QString::number(fb.jointCmd.j1));
    ui->lineEdit_posC_j2->setText(QString::number(fb.jointCmd.j2));
    ui->lineEdit_posC_j3->setText(QString::number(fb.jointCmd.j3));
    ui->lineEdit_posC_j4->setText(QString::number(fb.jointCmd.j4));
    ui->lineEdit_posC_j5->setText(QString::number(fb.jointCmd.j5));
    ui->lineEdit_posC_j6->setText(QString::number(fb.jointCmd.j6));

    ui->lineEdit_posS_X->setText(QString::number(fb.positionCmd.x));
    ui->lineEdit_posS_Y->setText(QString::number(fb.positionCmd.y));
    ui->lineEdit_posS_Z->setText(QString::number(fb.positionCmd.z));
    ui->lineEdit_posS_A->setText(QString::number(fb.positionCmd.a));
    ui->lineEdit_posS_B->setText(QString::number(fb.positionCmd.b));
    ui->lineEdit_posS_C->setText(QString::number(fb.positionCmd.c));
    /*qDebug()<<fb.usrCmd.x
              <<fb.usrCmd.y
                <<fb.usrCmd.z
                  <<fb.usrCmd.a
                    <<fb.usrCmd.b
                      <<fb.usrCmd.c;*/

}

void PositionSeriate::on_pushButton_setpu_currentposition_clicked()
{
    MotionFeedback fb;
    CTRL_GetMotionStatus(&fb);
    ui->lineEdit_posS_Sjj1->setText(QString::number(fb.jointCmd.j1));
    ui->lineEdit_posS_Sjj2->setText(QString::number(fb.jointCmd.j2));
    ui->lineEdit_posS_Sjj3->setText(QString::number(fb.jointCmd.j3));
    ui->lineEdit_posS_Sjj4->setText(QString::number(fb.jointCmd.j4));
    ui->lineEdit_posS_Sjj5->setText(QString::number(fb.jointCmd.j5));
    ui->lineEdit_posS_Sjj6->setText(QString::number(fb.jointCmd.j6));
}

void PositionSeriate::on_pushButton_posi_variate_data_clicked()
{
    QString posi_variable_name;
    posi_variable_name = ui->lineEdit_posi_variable->text();
    xmlcancle1->require_position_data(posi_variable_name);
    if(positiondata2.buf[0]=="Join")
    {
        ui->lineEdit_posS_Sjj1->setText(positiondata2.buf[1]);
        ui->lineEdit_posS_Sjj2->setText(positiondata2.buf[2]);
        ui->lineEdit_posS_Sjj3->setText(positiondata2.buf[3]);
        ui->lineEdit_posS_Sjj4->setText(positiondata2.buf[4]);
        ui->lineEdit_posS_Sjj5->setText(positiondata2.buf[5]);
        ui->lineEdit_posS_Sjj6->setText(positiondata2.buf[6]);
    }
    else if(positiondata2.buf[0]=="World")
    {

    }
    else if(positiondata2.buf[0]=="Cylindrical")
    {

    }
    else if(positiondata2.buf[0]=="Tool")
    {

    }
    else if(positiondata2.buf[0]=="Workpiece")
    {

    }

}

void PositionSeriate::on_comboBox_cu_co_select_currentIndexChanged(int index)
{
    if(index == 0)
    {
        ui->stackedWidget_2->setCurrentIndex(0);
    }
    else if(index ==1)
    {
        ui->stackedWidget_2->setCurrentIndex(1);
    }
    else
    {

    }
}
