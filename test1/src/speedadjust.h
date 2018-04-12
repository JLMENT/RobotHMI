#ifndef SPEEDADJUST_H
#define SPEEDADJUST_H

#include <QDialog>

namespace Ui {
class SpeedAdjust;
}

class SpeedAdjust : public QDialog
{
    Q_OBJECT

public:
    explicit SpeedAdjust(QWidget *parent = 0);
    ~SpeedAdjust();

private:
    Ui::SpeedAdjust *ui;
};

#endif // SPEEDADJUST_H
