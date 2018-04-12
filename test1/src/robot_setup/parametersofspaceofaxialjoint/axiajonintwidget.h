#ifndef AXIAJONINTWIDGET_H
#define AXIAJONINTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <systemparameterxml.h>
#include "digetedit.h"
#include "usr_motion_api/usr_motion_api.h"



class AxiaJonintWidget : public QWidget
{
    Q_OBJECT

public:
    AxiaJonintWidget(QWidget *parent = 0);
    ~AxiaJonintWidget();
    int page_status;
    int axis_status;
    bool saveok;

    QLineEdit *axis_title;
    QPushButton *axis_button[9];
    QLineEdit *variate[8];
//    QLineEdit *variate_value[8];
    DigetEdit *variate_value[8];
    QLabel *label;
    QPushButton *operate[4];

    QVBoxLayout *vb1;
    QHBoxLayout *hb1,*hb2,*hb3;
    QGridLayout *gb1;


private slots:
    void axis1_parameter_slot();
    void axis2_parameter_slot();
    void axis3_parameter_slot();
    void axis4_parameter_slot();
    void axis5_parameter_slot();
    void axis6_parameter_slot();
    void axis7_parameter_slot();
    void axis8_parameter_slot();
    void save_slot();
    void pageup_slot();
    void pagedown_slot();
private:
    void dataInit();
    void axis_response();
    void axis_save_response();
    void axis_change_response();
    void axis_cancle_select_status();

    void page_response();
    void page_save_response();
    void page_change_response();
    void save_response();

    void robot_data_init();

    typedef enum
    {
        AXIS1_PAGE1 =1,
        AXIS1_PAGE2,
        AXIS1_PAGE3,
        AXIS2_PAGE1,
        AXIS2_PAGE2,
        AXIS2_PAGE3,
        AXIS3_PAGE1,
        AXIS3_PAGE2,
        AXIS3_PAGE3,
        AXIS4_PAGE1,
        AXIS4_PAGE2,
        AXIS4_PAGE3,
        AXIS5_PAGE1,
        AXIS5_PAGE2,
        AXIS5_PAGE3,
        AXIS6_PAGE1,
        AXIS6_PAGE2,
        AXIS6_PAGE3,
        AXIS7_PAGE1,
        AXIS7_PAGE2,
        AXIS7_PAGE3,
        AXIS8_PAGE1,
        AXIS8_PAGE2,
        AXIS8_PAGE3
    }AxisPageState;

    AxisPageState pagestatus;

    QStringList list1,list2,list3,list4;

    SystemParameterXml *systemparameterxml;
};

#endif // AXIAJONINTWIDGET_H
