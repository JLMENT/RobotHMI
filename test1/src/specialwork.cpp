#include "specialwork.h"
#include "ui_specialwork.h"

SpecialWork::SpecialWork(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpecialWork)
{
    ui->setupUi(this);
    setGeometry(0,0,800,480);
    setWindowFlags(Qt::FramelessWindowHint);
    setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
}

SpecialWork::~SpecialWork()
{
    delete ui;
}
