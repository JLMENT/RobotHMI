#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMenu>
#include <QDebug>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QMessageBox>
#include "include.h"
#include "page2.h"
#include "speedadjust.h"
#include "robotoriginpointlocation.h"
#include "commandlist.h"
#include "axis.h"
#include "positionseriate.h"
#include "simulationkeypad.h"
//#include "commandinput.h"
#include "commandlist.h"
#include <QPalette>
#include "keypad.h"
#include "codeeditor/codeeditor.h"
#include "xml_cancle/xmlcancle.h"
//#include "dialog.ui"
#include "usr_motion_api/usr_motion_api.h"
#include "xml_cancle/xmlread/runfile.h"
#include "xml_cancle/xmlcopy/xmlcopycut.h"
#include "file_manage/filemanage.h"
#include "editkeyboard.h"
#include "digetedit.h"
//#include "form_num.h"
#include "numeric_type_module/numwidget/form_num.h"

#include "axiajonintwidget.h"
#include "descartesspacewidget.h"
#include "cpspace.h"
#include "robot_setup/othersetup/otherspace.h"
#include "dhspaceparem.h"

#include "originoffsetwidget.h"
#include "coordinatemanagewidget.h"
#include "toolmanagewidget.h"
#include "currentpositionwidget.h"

//class OtherSetup;
class ThreadData : public QThread
{
    Q_OBJECT

public:
    ThreadData(QObject *parent = 0);
    ~ThreadData();
    void datawrite();
protected:
    void run();
private:
    QMutex mutex;
    QWaitCondition condition;

signals:

};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void movjeditposition();

    QString xml_prog_name;

    //CommandInput *commandinput1;// = new CommandInput();

private:
    Ui::MainWindow *ui;
    Page2 *page2;
    Axis *axis;
    PositionSeriate *positionseriate;
    SimulationKeypad *simulationkeypad;

    RobotOriginPointLocation *robotoriginpointlocationpage;
    CommandList *commandlistpage;
    CommandInput *commandinput1;// = new CommandInput();
    keypad *key;
    XmlCancle *xmlcancle1;

    RunFile *run_file;




    void addFunc();
    void delFunc();

    QMenu *m_menu;
    QAction *m_addAction;
    QAction *m_delAction;
    QAction *m_subAction;

    QMenu *m_subMenu;
    QAction *m_subAdd;
    QAction *m_subDel;

    QMenu *m_programmenu;
    QAction *m_programcontent;
    QAction *m_programselect;
    QAction *m_programmanage;
    QAction *m_programmain;


   /* QMenu *m_toolmenu;
    QAction *m_setingspecialoperationmenu;
    QAction *m_speedadjustmenu;*/

    QMenu *m_setmenu;
    QAction *axisjointmenu;
    QAction *dklmenu;
    QAction *cpmenu;
    QAction *dhmenu;
    QAction *dhlmenu;
    QAction *axiscontrolmenu;
    QAction *otherparam;
    QAction *ioparametermenu;

    QMenu *m_robotmenu;
    QAction *currentpositionmenu;
    QAction *zeropositionsetupmenu;
    QAction *coordinateSMmenu;
    QAction *toolmanagementmenu;
    //QAction *exceptionhandlingmenu;

    QMenu *m_systemmenu;
    QAction *userrightsmenu;
    QAction *warninghistorymenu;
    QAction *editionmenu;

    QMenu *m_iomenu;
    QAction *iostatusmenu;
    QAction *CAstatusmenu;
    QAction *Astatusmenu;

    QMenu *m_seriatemenu;
    QAction *valuestylemenu;
    //QAction *valuemonitormenu;

   /* QMenu *m_outstoragemenu;
    QAction *installmenu;
    QAction *savemenu;
    QAction *checkmenu;
    QAction *deletemenu;
    QAction *equipmentmenu;*/

   ///////菜单的子菜单/////////////////////////
    QMenu *m_edit;
    QAction *copymenu;
    QAction *cutmenu;
    QAction *pastemenu;
    QAction *startrowmenu;
    QAction *endrowmenu;






    /////////////////////栈部件窗口/////////////////////////////

    QStackedWidget *stack;
    SpeedAdjust *page1;
    //SpeOperation *page2;

    //The timer event to get the cursor
    QTimer *mainwindow_timer1;

    LinearDescartesMoveInformation mdl;
    LinearMoveInformation lm;
    CircularDescartesMoveInformation cdm;
    CircularMoveInformation cm;

    /////////////////////copy-cut-paste-class///////////////////////
    XmlCopyCut *xmlcopycut = new XmlCopyCut();
    ////////////////////file manage/////////////////////////////////
    FileManage *filemanage = new FileManage();
    FileManage *filemanageselect = new FileManage();

    ////////////////////program list button//////////////////////////

    //comments of file of program
    ProgFileAnnotation *progfilenote = new ProgFileAnnotation;

    //command list
    CommandList *commandlistM = new CommandList;

    //digit_key_board
    //DigitKeyDialog *digitkeydialog1 = new DigitKeyDialog;

    //numeric_type
    Form *numeric_type = new Form;

    //axis param
    AxiaJonintWidget *axis_param = new AxiaJonintWidget;

    //descartsspace_param
    DescartesSpaceWidget *descarts_param = new DescartesSpaceWidget;

    //cpspace_setup
    CpSpace *cpspace_setup = new CpSpace;

    //other setup
    OtherSetup *other_param = new OtherSetup;

    //DH_Param
    DHSpaceParem *dh_param = new DHSpaceParem;

    //Origin_setup
    OriginOffsetWidget *origin_offset = new OriginOffsetWidget;

    //Coordiante_Manage
    CoordinateManageWidget *coordinatemanagewidget = new CoordinateManageWidget;

    //Tool_Coordinate_Mamage
    ToolManageWidget *toolmanagewidget = new ToolManageWidget;

    //Current_Position
    CurrentPositionWidget *currentpositionwidget = new CurrentPositionWidget;


private slots:
     //void MainWindow_page2();
     void programcontentpage();
     void programselectpage();
     void programmanagepage();
     void programmainpage();

     void on_pushButton_6_clicked();
     void SpdAdj1();
     void SpeAdj2();
     void stackpage1();
     void stackpage2();
     void cppage();
     void dhpage();
     void dhlpage();
     void axiscontrolpage();
     void otherpage();
     void ioparameterpage();

     void currentpositionpage();
     void zeropositionsetuppage();
     void coordinateSMpage();
     void toolmanagementpage();
     void exceptionhandlingpage();

     void userrightspage();
     void warninghistorypage();
     void editionpage();

     void iostatuspage();
     void CAstatuspage();
     void Astatuspage();

     void valuestylepage();
     void valuemonitorpage();

     void installpage();
     void savepage();
     void checkpage();
     void deletepage();
     void equipmentpage();




     void robotoriginpointpage();



     void on_ParameterButton_clicked();

     void on_positioneditpushButton_clicked();

     void on_simulatekeypushButton_clicked();

     void on_AxispushButton_1_clicked();

     void on_AxispushButton_2_clicked();

     void on_Axis11nextpushButton_clicked();

     void on_iomnextpushButton_clicked();

     void on_dgituppushButton_clicked();

     void on_dgetnextpushButton_clicked();

     void on_kmuppushButton_clicked();

     void on_lwbdcpushButton_581_clicked();

     void on_lwbdcpushButton_582_clicked();

     void on_lwbdcpushButton_583_clicked();

     void on_lwbdcpushButton_584_clicked();

     void on_lwbdcpushButton_587_clicked();

     void on_lwbdcpushButton_588_clicked();

     void on_lwbdcpushButton_586_clicked();

     void on_lwbdcpushButton_585_clicked();

     void on_showpushButton_clicked();

     void on_pushButton_2_clicked();

     void on_Goodtoolbutton_clicked();

     void on_ProgramButton_clicked();

     void on_OutsideStorageButton_clicked();

     void on_new_main_prog_pushButton_pressed();
     void on_pushButton_5_clicked();
     void program_cursor_up();//光标向上移函数
     void program_cursor_down();//光标下移函数
     void program_delete_line();//删除光标右边整行
     //void program_insert_line();
     void insert_slot(QString *);
     void on_pushButton_seprog_ensure_clicked();

     void require_modify_data();//获得修改的数据

     //next step slot
     void send_current_line_slot();

     //single_backward
     void single_step_backward_slot();

     //multi P/N
     void multip_send_line_slot();
     void multin_send_line_slot();
     void multip_release_send_line_slot();
     void multin_release_send_line_slot();

     //test run
     void test_run_slot();

     //start run
     void restart_run_slot();

     //pause
     void when_run_pause_slot();

     void on_new_sub_prog_pushButton_clicked();

     //program process emit sig corresponding slot
     void display_changed_file(QString);
     void file_run_end();

     //copy - paste  clear and insert signal slot
     //void copy_cut_paste();
     //void cut_clear();
     //refresh_reload_program
     void refresh_reload_program_slot(QString);

     //edit button start line/end line/copy/cut/paste
     void start_line_slot();
     void end_line_slot();
     void copy_slot();
     void cut_slot();
     void paste_slot();

     //
     void reload_select_file(QString filename);

     void ensure_select_file(QString filename);

     ///////////file delete_copy_rename///////////////
     void file_manage_delete();
     void file_manage_copy();
     void file_manage_rename();

public slots:
     //命令输入框输入数据显示到程序编辑器界面的响应函数

     void movj_command_display(QString *);
     void movl_command_display(QString *);
     void movc_command_display(QString *);
     void speed_command_display(QString *);
     void dout_command_display(QString *);
     void din_command_display(QString *);
     void pause_command_display(QString *);
     void timer_command_display(QString);
     void jump_command_display(QString *);
     void label_command_display(QString);
     void call_command_display(QString *);
     void ret_command_display(QString *);

     void mainwindow_refresh_cursor();//refresh cursor

protected:
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
signals:
     void ActionClick(int);
     //void commandsig(int);
     void main_insert_sig();//key insert sig;

};

class FileSelectPushButton : public QPushButton
{
    Q_OBJECT
public:
    FileSelectPushButton(QString buttonname);
private:
    QString buttonname;
private slots:
    void send_select_program_slot();
signals:
    void reload_program_sig(QString);
    void select_program_sig(QString);
};

#endif // MAINWINDOW_H
