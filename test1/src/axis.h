#ifndef AXIS_H
#define AXIS_H

#include <QWidget>

namespace Ui {
class Axis;
}

class Axis : public QWidget
{
    Q_OBJECT

public:
    explicit Axis(QWidget *parent = 0);
    ~Axis();

private slots:
    void on_AxispushButton_1_clicked();

    void on_AxispushButton_2_clicked();

private:
    Ui::Axis *ui;
};

#endif // AXIS_H
