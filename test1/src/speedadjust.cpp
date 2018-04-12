#include "speedadjust.h"
#include "ui_speedadjust.h"

SpeedAdjust::SpeedAdjust(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpeedAdjust)
{
    ui->setupUi(this);

    setGeometry(0,0,800,480);

    setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
}

SpeedAdjust::~SpeedAdjust()
{
    delete ui;
}
