#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include <QDialog>

namespace Ui {
class MoveCommand;
}

class MoveCommand : public QDialog
{
    Q_OBJECT

public:
    explicit MoveCommand(QWidget *parent = 0);
    ~MoveCommand();

private:
    Ui::MoveCommand *ui;
};

#endif // MOVECOMMAND_H
