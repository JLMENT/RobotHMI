#ifndef COMMANDINPUT_H
#define COMMANDINPUT_H

#include <QWidget>
//#include "commandlist.h"
//#include "mainwindow.h"
#include "positionseriate.h"
#include "include.h"
#include "xml_cancle/xmlcancle.h"
#include "digetedit.h"

namespace Ui {
class CommandInput;
}

class CommandInput : public QWidget
{
    Q_OBJECT

public:
    explicit CommandInput(QWidget *parent = 0);
    ~CommandInput();



    void commandchangej();
    void commandchangel();
    void commandchangec();
    void commandchangeimov();
    void commandchangespeed();
    void commandchangecoord();
    void commandchangehome();
    void commandchangedout();
    void commandchangedin();
    void commandchangeaout();
    void commandchangeain();
    void commandchangearation();
    void commandchangearatiof();
    void commandchangejump();
    void commandchangelabel();
    void commandchangecall();
    void commandchangeret();
    void commandchangetimer();
    void commandchangepause();
    void commandchangecwait();
    void commandchangeadd();
    void commandchangesub();
    void commandchangemul();
    void commandchangediv();
    void commandchangeinc();
    void commandchangedec();
    void commandchangeand();
    void commandchangeor();
    void commandchangenot();
    void commandchangexor();

    //插入控制命令
    //void input_insert_command(int);

    //修改数据显示
    void modify_movj_display();
    void modify_movl_display();
    void modify_movc_display();
    void modify_speed_display();
    void modify_dout_display();
    void modify_din_display();
    void modify_pause_display();
    void modify_timer_display();
    void modify_jump_display();
    void modify_label_display();
    void modify_call_display();
    void modify_ret_display();


private:
    Ui::CommandInput *ui;

    //CommandList *Cmdlist;
    //MainWindow *mainwindow = new MainWindow();
    PositionSeriate *posate = new PositionSeriate();
    XmlCancle *xmlcancle = new XmlCancle();
signals:
    void commandsig(int);
    //movj确定信号
    void movj_ensure_sig(QString *);
    void movl_ensure_sig(QString *);
    void movc_ensure_sig(QString *);
    void speed_ensure_sig(QString *);
    void dout_ensure_sig(QString *);
    void din_ensure_sig(QString *);

    void pause_ensure_sig(QString *);
    void timer_ensure_sig(QString);
    void jump_ensure_sig(QString *);
    void label_ensure_sig(QString);
    void call_ensure_sig(QString *);
    void ret_ensure_sig(QString *);
    //插入信号 input向list
    void input_list_insert_sig(QString *);





private slots:
    void on_mojpositioneditpushButton_clicked();
    void on_pushButton_movj_ensure_clicked();
    void on_pushButton_TEST_clicked();
    void on_pushButton_movl_ensure_pressed();
    void on_pushButton_movc_ensure_pressed();
    void on_pushButton_speed_ensure_pressed();
    void input_insert_slot();
    void refresh_posi_vari_slot();
    void on_pushButton_movl_editpotiion_clicked();
    void on_pushButton_movc_editposition_clicked();
    void on_io_dout_ensure_pushButton_clicked();
    void on_io_din_ensure_pushButton_clicked();
    void on_pause_ensure_pushButton_clicked();
    void on_timer_ensure_pushButton_clicked();
    void on_jump_ensure_pushButton_clicked();
    void on_label_ensure_pushButton_clicked();
    void on_call_ensure_pushButton_clicked();
    void on_ret_ensure_pushButton_clicked();
};

#endif // COMMANDINPUT_H
