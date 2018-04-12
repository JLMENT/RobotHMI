#include "robotoriginpointlocation.h"
#include "ui_robotoriginpointlocation.h"

RobotOriginPointLocation::RobotOriginPointLocation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RobotOriginPointLocation)
{
    ui->setupUi(this);

    ui->op_SlineEdit->setText(settings.value("orginpointdata/1pS",0).toString());
    ui->op_LlineEdit->setText(settings.value("orginpointdata/2pL",0).toString());
    ui->op_UlineEdit->setText(settings.value("orginpointdata/3pU",0).toString());
    ui->op_RlineEdit->setText(settings.value("orginpointdata/4pR",0).toString());
    ui->op_BlineEdit->setText(settings.value("orginpointdata/5pB",0).toString());
    ui->op_TlineEdit->setText(settings.value("orginpointdata/6pT",0).toString());


   // connect(ui->op_savepushButton,SLOT(triggered()),this,SLOT(saveopdata()));

}

RobotOriginPointLocation::~RobotOriginPointLocation()
{
    delete ui;
}
/*void RobotOriginPointLocation::saveopdata()
{
    settings.setValue("orginpointdata/op_S",ui->op_SlineEdit->text().toInt());
    settings.setValue("orginpoingdata/op_L",ui->op_LlineEdit->text().toInt());
    settings.setValue("orginpointdata/op_U",ui->op_SlineEdit->text().toInt());
    settings.setValue("orginpoingdata/op_R",ui->op_LlineEdit->text().toInt());
    settings.setValue("orginpointdata/op_B",ui->op_SlineEdit->text().toInt());
    settings.setValue("orginpoingdata/op_T",ui->op_LlineEdit->text().toInt());
    update();
    QMessageBox::information(this,"提示","保存成功！",QMessageBox::Ok,QMessageBox::Ok);

}*/

void RobotOriginPointLocation::on_op_savepushButton_clicked()
{
    switch(QMessageBox::question(this,tr("提示"),tr("保存成功"),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok))
    {
    case QMessageBox::Ok:
        settings.setValue("orginpointdata/1pS",ui->op_SlineEdit->text().toInt());
        settings.setValue("orginpoingdata/2pL",ui->op_LlineEdit->text().toInt());
        settings.setValue("orginpointdata/3pU",ui->op_SlineEdit->text().toInt());
        settings.setValue("orginpoingdata/4pR",ui->op_LlineEdit->text().toInt());
        settings.setValue("orginpointdata/5pB",ui->op_SlineEdit->text().toInt());
        settings.setValue("orginpoingdata/6pT",ui->op_LlineEdit->text().toInt());
        update();
        break;
    case QMessageBox::Cancel:
            break;
        default:
            break;


    }
    //update();
    //QMessageBox::information(this,"提示","保存成功！",QMessageBox::Ok,QMessageBox::Ok);

}
