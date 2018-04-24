#ifndef CURRENTPOSITIONWIDGET_H
#define CURRENTPOSITIONWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QStringList>
#include <QPalette>
#include <QFont>
#include <QColor>

#include <QEvent>
#include "usr_motion_api/usr_motion_api.h"

class CurrentPositionWidget : public QWidget
{
    Q_OBJECT

public:
    CurrentPositionWidget(QWidget *parent = 0);
    ~CurrentPositionWidget();
private:
    QLineEdit *joint_position_label[9];
    QLineEdit *joint_position[9];
    QLineEdit *other_position_label[9];
    QLineEdit *other_position[8];
    QComboBox *combox;
    QLineEdit *titleedit;
    QFormLayout *fl1 = new QFormLayout;
    QFormLayout *fl2 = new QFormLayout;
    QHBoxLayout *hb1 = new QHBoxLayout;
    QVBoxLayout *vb = new QVBoxLayout;

    int myTimerId;

protected:
    void timerEvent(QTimerEvent *event);

};

#endif // CURRENTPOSITIONWIDGET_H
