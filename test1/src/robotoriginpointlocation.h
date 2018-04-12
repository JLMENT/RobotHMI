#ifndef ROBOTORIGINPOINTLOCATION_H
#define ROBOTORIGINPOINTLOCATION_H

#include "include.h"

#include <QDialog>

namespace Ui {
class RobotOriginPointLocation;
}

class RobotOriginPointLocation : public QDialog
{
    Q_OBJECT

public:
    explicit RobotOriginPointLocation(QWidget *parent = 0);
    ~RobotOriginPointLocation();

private:
    Ui::RobotOriginPointLocation *ui;
    QSettings settings;
private slots:
    //void saveopdata();
    void on_op_savepushButton_clicked();
};

#endif // ROBOTORIGINPOINTLOCATION_H
