#ifndef COMMANDLIST_H
#define COMMANDLIST_H

#include <QDialog>
#include <QMenu>
//#include "ui_mainwindow.h"
//#include "ui_commandinput.h"
#include "commandinput.h"

namespace Ui {
class CommandList;
}

class CommandList : public QDialog
{
    Q_OBJECT

public:
    explicit CommandList(QWidget *parent = 0);
    ~CommandList();

    //void setcommandinput(Ui::CommandInput *ui){commandinput_ui = ui;}
    void list_input_display();

private:
    Ui::CommandList *ui;
    //Ui::MainWindow *main_ui;
    //Ui::CommandInput *commandinput_ui = new Ui::CommandInput();

    CommandInput *commandinput;


    QMenu *movemenu;
    QAction *movjAction;
    QAction *movlAction;
    QAction *movcAction;
    QAction *movsAction;
    QAction *imovAction;
    QAction *refpAction;
    QAction *speedAction;
    QAction *coordAction;
    QAction *homeAction;

    QMenu *IOmenu;
    QAction *doutAction;
    QAction *dinAction;
    QAction *aoutAction;
    QAction *ainAction;
    QAction *arationAction;
    QAction *aratiofAction;

    QMenu *logmenu;
    QAction *jumpAction;
    QAction *labelAction;
    QAction *callAction;
    QAction *retAction;
    QAction *timerAction;
    QAction *pauseAction;
    QAction *cwaitAction;

    QMenu *operation;
    QAction *addAction;
    QAction *subAction;
    QAction *mulAction;
    QAction *divAction;
    QAction *incAction;
    QAction *decAction;
    QAction *andAction;
    QAction *orAction;
    QAction *notAction;
    QAction *xorAction;


private slots:
    void commandmovj();
    void commandmovl();
    void commandmovc();
    void commandimov();
    void commandspeed();
    void commandcoord();
    void commandhome();
    void commanddout();
    void commanddin();
    void commandaout();
    void commandain();
    void commandaration();
    void commandaratiof();
    void commandjump();
    void commandlabel();
    void commandcall();
    void commandret();
    void commandtimer();
    void commandpause();
    void commandcwait();
    void commandadd();
    void commandsub();
    void commandmul();
    void commanddiv();
    void commandinc();
    void commanddec();
    void commandand();
    void commandor();
    void commandnot();
    void commandxor();

    void close_input_slot();


   // void on_mojpositioneditpushButton_clicked();



    void on_pushButton_clicked();

    void movj_slot(QString *);
    void movl_slot(QString *);
    void movc_slot(QString *);
    void speed_slot(QString *);
    void dout_slot(QString*);
    void list_insert_slot();

    void list_simu_insert_slot(QString *);

signals:
    //void commandsig(int);
    void test_sig();
    void movj_list_sig(QString *);
    void movj_list_simula_sig(QString *);
    void movl_list_simula_sig(QString *);
    void movc_list_simula_sig(QString *);
    void speed_list_simula_sig(QString *);
    void dout_list_simula_sig(QString *);
    void din_list_simula_sig(QString*);
    void pause_list_simula_sig(QString*);
    void timer_list_simula_sig(QString);
    void jump_list_simula_sig(QString*);
    void label_list_simula_sig(QString);
    void call_list_simula_sig(QString*);
    void ret_list_simula_sig(QString*);

    void list_insert_sig();

    void list_simu_insert_sig(QString *);
};

#endif // COMMANDLIST_H
