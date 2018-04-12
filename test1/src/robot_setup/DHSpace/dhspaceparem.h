#ifndef DHSPACEPAREM_H
#define DHSPACEPAREM_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QStringList>
#include <QPixmap>
#include "configset.h"
#include "digetedit.h"
#include "usr_motion_api/usr_motion_api.h"



class DHSpaceParem : public QWidget
{
    Q_OBJECT
public:
    explicit DHSpaceParem(QWidget *parent = 0);
    //QLineEdit *edit[30];// = new QLineEdit;
    DigetEdit *edit[30];
    QLabel *piclabel = new QLabel;
    QPushButton *savebutton = new QPushButton;
    QPushButton *addbutton = new QPushButton;
    //QFormLayout *fl = new QFormLayout;
    QGridLayout *fl = new QGridLayout;


private:
    QStringList list;
    ConfigSet *configset = new ConfigSet;

private slots:
    void dhsave();
    void dhadd();


signals:

public slots:
};

#endif // DHSPACEPAREM_H
