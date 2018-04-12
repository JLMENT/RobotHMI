#include "digitkeydialog.h"
#include "ui_digitkeydialog.h"

DigitKeyDialog::DigitKeyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DigitKeyDialog)
{
    ui->setupUi(this);
}

DigitKeyDialog::~DigitKeyDialog()
{
    delete ui;
}

void DigitKeyDialog::on_pushButton_10_clicked()
{
    emit sendstr(ui->pushButton_10->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_10->text());
}

void DigitKeyDialog::on_pushButton_1_clicked()
{
    emit sendstr(ui->pushButton_1->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_1->text());
}

void DigitKeyDialog::on_pushButton_2_clicked()
{
    emit sendstr(ui->pushButton_2->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_2->text());
}

void DigitKeyDialog::on_pushButton_3_clicked()
{
    emit sendstr(ui->pushButton_3->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_3->text());
}

void DigitKeyDialog::on_pushButton_4_clicked()
{
    emit sendstr(ui->pushButton_4->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_4->text());
}

void DigitKeyDialog::on_pushButton_5_clicked()
{
    emit sendstr(ui->pushButton_5->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_5->text());
}

void DigitKeyDialog::on_pushButton_6_clicked()
{
    emit sendstr(ui->pushButton_6->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_6->text());
}

void DigitKeyDialog::on_pushButton_7_clicked()
{
    emit sendstr(ui->pushButton_7->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_7->text());
}

void DigitKeyDialog::on_pushButton_8_clicked()
{
    emit sendstr(ui->pushButton_8->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_8->text());
}

void DigitKeyDialog::on_pushButton_9_clicked()
{
    emit sendstr(ui->pushButton_9->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_9->text());
}

void DigitKeyDialog::on_pushButton_dot_clicked()
{
    emit sendstr(ui->pushButton_dot->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_dot->text());
}

void DigitKeyDialog::on_pushButton_backspace_clicked()
{
    emit remove_last_character_sig();
    QString str = ui->lineEdit->text();
    str.chop(1);
    ui->lineEdit->setText(str);
}

void DigitKeyDialog::on_pushButton_clear_clicked()
{
    emit remove_all_sig();
    ui->lineEdit->clear();
}

void DigitKeyDialog::on_pushButton_ensure_clicked()
{
    emit remove_all_sig();
    emit sendstr(ui->lineEdit->text());

    this->close();
}

void DigitKeyDialog::on_pushButton_cancle_clicked()
{
    emit remove_all_sig();
    this->close();
}

void DigitKeyDialog::display_edit_str_slot(QString str)
{
    ui->lineEdit->setText(str);
}
