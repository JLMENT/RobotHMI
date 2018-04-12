#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include "specialwork.h"
#include "include.h"

class ConfigDialog :public QDialog
{
    Q_OBJECT
public:
    ConfigDialog(QWidget *parent = 0,Qt::WindowFlags flags = 0);
    ~ConfigDialog();

    void readINI();
    void createINI();

private:
    SpeedAdjust *page1;
    SpecialWork *page3;


};

#endif // CONFIGDIALOG_H
