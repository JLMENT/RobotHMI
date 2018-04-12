#include "movecommand.h"
#include "ui_movecommand.h"

MoveCommand::MoveCommand(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoveCommand)
{
    ui->setupUi(this);
}

MoveCommand::~MoveCommand()
{
    delete ui;
}
