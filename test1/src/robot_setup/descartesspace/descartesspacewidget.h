#ifndef DESCARTESSPACEWIDGET_H
#define DESCARTESSPACEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include "config/testinclude.h"
#include "digetedit.h"
#include "usr_motion_api/usr_motion_api.h"
#include "file_path_macro.h"
class DescartesSpaceWidget : public QWidget
{
    Q_OBJECT

public:
    DescartesSpaceWidget(QWidget *parent = 0);
    ~DescartesSpaceWidget();
    QLineEdit *axis_title;
    QPushButton *axis_button[7];
    QLineEdit *variate[8];
    //QLineEdit *variate_value[8];
    DigetEdit *variate_value[8];
    QLabel *label;
    QPushButton *operate[6];

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
    void save_slot();
    void pageup_slot();
    void pagedown_slot();

    void load_slot();
    void remove_slot();
private:

    void axis_cancle_select_status();
    void axis_change_response();
    void page_display(int);

    void createIni();
    void readIni();

    void descartes_data_init();

    typedef enum
    {
        AXIS1_PAGE1 =1,
        AXIS1_PAGE2,
        AXIS2_PAGE1,
        AXIS2_PAGE2,
        AXIS3_PAGE1,
        AXIS3_PAGE2,
        AXIS3_PAGE3,
        AXIS4_PAGE1,
        AXIS4_PAGE2,
        AXIS5_PAGE1,
        AXIS5_PAGE2,
        AXIS6_PAGE1,
        AXIS6_PAGE2
    }AxisPageState;
    AxisPageState pagestatus;

    QStringList list1,list2,list3,list4;
};

#endif // DESCARTESSPACEWIDGET_H
