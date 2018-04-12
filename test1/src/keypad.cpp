#include "keypad.h"
#include "ui_keypad.h"

keypad::keypad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::keypad)
{
    ui->setupUi(this);
}

keypad::~keypad()
{
    delete ui;
}
