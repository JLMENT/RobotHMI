#ifndef TOOLMANAGEWIDGET_H
#define TOOLMANAGEWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSplitter>
#include <QStringList>
#include <QPainter>
#include <QEvent>
#include <QTimer>
//#include "setting/configset.h"
#include "configset.h"
#include "usr_motion_api/usr_motion_api.h"

#define BTN_STYPE "background-color:rgb(0,238,238);border-radius:4px;border:2px black;border-style:inset"
#define BTN_RELEASE_STYPE "background-color:rgb(232,232,232);border-radius:4px;border:0.5px black;border-style:outset"

#define DELAY_TIME1 2000
#define DELAY_TIME2 3000
//class ToolBtn : public QPushButton
//{
//public:
//    ToolBtn()
//    {

//    }
//private:
//    void paintEvent(QPaintDevice *event)
//    {
//        QPainter painter(this);
//        painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/toolimage/toolwrite.png"));

//    }

//};

class ToolManageWidget : public QWidget
{
    Q_OBJECT

public:
    ToolManageWidget(QWidget *parent = 0);
    ~ToolManageWidget();

private:
    QPushButton *coor_btn[11];
    QPushButton *method_btn[6];
    //QPushButton *record_btn[4];
    QPushButton *record_btn[6];
    QPushButton *manual_setting_btn[7];
    QPushButton *operate_btn[3];
    QLineEdit *position_edit[14];
    QLineEdit *position_label[14];
    QLineEdit *comment_edit;
    QLineEdit *current_id;
    QLineEdit *title_edit;
    //QWidget *widget1 = new QWidget;
    QVBoxLayout *vb = new QVBoxLayout;
    QVBoxLayout *vb1 = new QVBoxLayout;
    QVBoxLayout *vb2 = new QVBoxLayout;
    QVBoxLayout *vb3 = new QVBoxLayout;


    QHBoxLayout *hb1 = new QHBoxLayout;
    QHBoxLayout *hb2 = new QHBoxLayout;
    QHBoxLayout *hb3 = new QHBoxLayout;
    QHBoxLayout *hb4 = new QHBoxLayout;

    QGridLayout *gd1 = new QGridLayout;
    QGridLayout *gd2 = new QGridLayout;

    QTimer *timer = new QTimer;\

    ConfigSet *configset = new ConfigSet;

    bool method_buf[3] = {false};//buf[0]~buf[2]那个为真表示那种方法被选中463
    bool plane_buf[3] = {false};//依次为xy/yz/zx面被选中标记
    bool tool_buf[11] =  {false};//依次为0~10坐标系被选中标记
    bool position_record_buf[6] = {false};//点是否都被记录标记

    typedef enum
    {
        NO_KEY = -1,
        P1_KEY = 0,
        P2_KEY = 1,
        P3_KEY = 2,
        P4_KEY,
        P5_KEY,
        P6_KEY,
        SET_CURRENT_KEY,
        CLEAR_KEY,
        CALC_KEY
    }KeyStyle;
    KeyStyle keystyle;

    QString btn_style1 = "QPushButton{background-color:black;\
            color:white;border-radius:10px;border:2px groove gray;\
            border-style:outset;}"
            "QPushButton:hover{background-color:white;color:black;}"
            "QPushButton:pressed{background-color:rgb(85,170,255);\
            border-style:inset;}";

//arithmetic
    JointPoint jointpoint1[6];


    void set_coorbtn_select_status(int);
    void btn_disnable();
    void btn_enable();
    void method_record_clear();
    void menual_setup_assignment(int);
    void load_position_data(int);
    void save_position_data();

private slots:

    void timeout_slot();

    void four_method_slot();
    void six_method_slot();
    void three_method_slot();
    void xy_plane_slot();
    void yz_plane_slot();
    void zx_plane_slot();

    void coor0_slot();
    void coor1_slot();
    void coor2_slot();
    void coor3_slot();
    void coor4_slot();
    void coor5_slot();
    void coor6_slot();
    void coor7_slot();
    void coor8_slot();
    void coor9_slot();
    void coor10_slot();

    void record_p1_press_slot();
    void record_p1_release_slot();
    void record_p2_press_slot();
    void record_p2_release_slot();
    void record_p3_press_slot();
    void record_p3_release_slot();
    void record_p4_press_slot();
    void record_p4_release_slot();
    void record_p5_press_slot();
    void record_p5_release_slot();
    void record_p6_press_slot();
    void record_p6_release_slot();

    void set_current_data_press_slot();
    void clear_current_data_press_slot();
    void calc_data_press_slot();
    void set_current_data_release_slot();
    void clear_current_data_release_slot();
    void calc_data_release_slot();

    void manual_setup_all_slot();
    void manual_setup_X_slot();
    void manual_setup_Y_slot();
    void manual_setup_Z_slot();
    void manual_setup_A_slot();
    void manual_setup_B_slot();
    void manual_setup_C_slot();

};
#endif // TOOLMANAGEWIDGET_H
