#include "newfilename.h"
#include "ui_newfilename.h"

NewFileName::NewFileName(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewFileName)
{
    ui->setupUi(this);
}

NewFileName::~NewFileName()
{
    delete ui;
}
