#include "axis.h"
#include "ui_axis.h"

Axis::Axis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Axis)
{
    ui->setupUi(this);
}

Axis::~Axis()
{
    delete ui;
}

void Axis::on_AxispushButton_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Axis::on_AxispushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
