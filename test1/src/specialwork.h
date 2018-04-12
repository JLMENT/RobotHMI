#ifndef SPECIALWORK_H
#define SPECIALWORK_H

#include <QDialog>

namespace Ui {
class SpecialWork;
}

class SpecialWork : public QDialog
{
    Q_OBJECT

public:
    explicit SpecialWork(QWidget *parent = 0);
    ~SpecialWork();

private:
    Ui::SpecialWork *ui;
};

#endif // SPECIALWORK_H
