#include "commandlist.h"
#include "ui_commandlist.h"
#include <QDebug>

CommandList::CommandList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CommandList)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setGeometry(1000,300,82,204);


    commandinput = new CommandInput();

    movemenu = new QMenu(this);
    movjAction = new QAction(movemenu);
    movlAction = new QAction(movemenu);
    movcAction = new QAction(movemenu);
    movsAction = new QAction(movemenu);
    imovAction = new QAction(movemenu);
    refpAction = new QAction(movemenu);
    speedAction = new QAction(movemenu);
    coordAction = new QAction(movemenu);
    homeAction = new QAction(movemenu);

    movjAction->setText(QObject::tr("MOVJ"));
    movlAction->setText(QObject::tr("MOVL"));
    movcAction->setText(QObject::tr("MOVC"));
    movsAction->setText(QObject::tr("MOVS"));
    imovAction->setText(QObject::tr("IMOV"));
    refpAction->setText(QObject::tr("REFP"));
    speedAction->setText(QObject::tr("SPEED"));
    coordAction->setText(QObject::tr("COORD"));
    homeAction->setText(QObject::tr("HOME"));


    movemenu->addAction(movjAction);
    movemenu->addAction(movlAction);
    movemenu->addAction(movcAction);
    movemenu->addAction(movsAction);
    movemenu->addAction(imovAction);
    movemenu->addAction(refpAction);
    movemenu->addAction(speedAction);
    movemenu->addAction(coordAction);
    movemenu->addAction(homeAction);

    ui->movecommandButton->setMenu(movemenu);



    connect(movjAction,SIGNAL(triggered()),this,SLOT(commandmovj()));
    connect(movlAction,SIGNAL(triggered()),this,SLOT(commandmovl()));
    connect(movcAction,SIGNAL(triggered()),this,SLOT(commandmovc()));

    connect(imovAction,SIGNAL(triggered()),this,SLOT(commandimov()));

    connect(speedAction,SIGNAL(triggered()),this,SLOT(commandspeed()));
    connect(coordAction,SIGNAL(triggered()),this,SLOT(commandcoord()));
    connect(homeAction,SIGNAL(triggered()),this,SLOT(commandhome()));

    IOmenu = new QMenu(this);
    doutAction = new QAction(IOmenu);
    dinAction = new QAction(IOmenu);
    aoutAction = new QAction(IOmenu);
    ainAction = new QAction(IOmenu);
    arationAction = new QAction(IOmenu);
    aratiofAction = new QAction(IOmenu);

    doutAction->setText(QObject::tr("DOUT"));
    dinAction->setText(QObject::tr("DIN"));
    aoutAction->setText(QObject::tr("AOUT"));
    ainAction->setText(QObject::tr("AIN"));
    arationAction->setText(QObject::tr("ATATION"));
    aratiofAction->setText(QObject::tr("ATATIOF"));

    IOmenu->addAction(doutAction);
    IOmenu->addAction(dinAction);
    IOmenu->addAction(aoutAction);
    IOmenu->addAction(ainAction);
    IOmenu->addAction(arationAction);
    IOmenu->addAction(aratiofAction);

    ui->iopushButton->setMenu(IOmenu);

    connect(doutAction,SIGNAL(triggered()),this,SLOT(commanddout()));
    connect(dinAction,SIGNAL(triggered()),this,SLOT(commanddin()));
    connect(aoutAction,SIGNAL(triggered()),this,SLOT(commandaout()));
    connect(ainAction,SIGNAL(triggered()),this,SLOT(commandain()));
    connect(arationAction,SIGNAL(triggered()),this,SLOT(commandaration()));
    connect(aratiofAction,SIGNAL(triggered()),this,SLOT(commandaratiof()));


    logmenu = new QMenu(this);
    jumpAction = new QAction(logmenu);
    labelAction = new QAction(logmenu);
    callAction = new QAction(logmenu);
    retAction = new QAction(logmenu);
    timerAction  = new QAction(logmenu);
    pauseAction = new QAction(logmenu);
    cwaitAction = new QAction(logmenu);

    jumpAction->setText(QObject::tr("JUMP"));
    labelAction->setText(QObject::tr("LABEL"));
    callAction->setText(QObject::tr("CALL"));
    retAction->setText(QObject::tr("RET"));
    timerAction->setText(QObject::tr("TIMER"));
    pauseAction->setText(QObject::tr("PAUSE"));
    cwaitAction->setText(QObject::tr("CWAIT"));

    logmenu->addAction(jumpAction);
    logmenu->addAction(labelAction);
    logmenu->addAction(callAction);
    logmenu->addAction(retAction);
    logmenu->addAction(timerAction);
    logmenu->addAction(pauseAction);
    logmenu->addAction(cwaitAction);

    ui->controlpushButton->setMenu(logmenu);

    connect(jumpAction,SIGNAL(triggered()),this,SLOT(commandjump()));
    connect(labelAction,SIGNAL(triggered()),this,SLOT(commandlabel()));
    connect(callAction,SIGNAL(triggered()),this,SLOT(commandcall()));
    connect(retAction,SIGNAL(triggered()),this,SLOT(commandret()));
    connect(timerAction,SIGNAL(triggered()),this,SLOT(commandtimer()));
    connect(pauseAction,SIGNAL(triggered()),this,SLOT(commandpause()));
    connect(cwaitAction,SIGNAL(triggered()),this,SLOT(commandcwait()));



    operation = new QMenu(this);
    addAction = new QAction(operation);
    subAction = new QAction(operation);
    mulAction = new QAction(operation);
    divAction = new QAction(operation);
    incAction = new QAction(operation);
    decAction = new QAction(operation);
    andAction = new QAction(operation);
    orAction = new QAction(operation);
    notAction = new QAction(operation);
    xorAction = new QAction(operation);

    addAction->setText(QObject::tr("ADD"));
    subAction->setText(QObject::tr("SUB"));
    mulAction->setText(QObject::tr("MUL"));
    divAction->setText(QObject::tr("DIV"));
    incAction->setText(QObject::tr("INC"));
    decAction->setText(QObject::tr("DEC"));
    andAction->setText(QObject::tr("AND"));
    orAction->setText(QObject::tr("OR"));
    notAction->setText(QObject::tr("NOT"));
    xorAction->setText(QObject::tr("XOR"));

    operation->addAction(addAction);
    operation->addAction(subAction);
    operation->addAction(mulAction);
    operation->addAction(divAction);
    operation->addAction(incAction);
    operation->addAction(decAction);
    operation->addAction(andAction);
    operation->addAction(orAction);
    operation->addAction(notAction);
    operation->addAction(xorAction);

    ui->operationpushButton->setMenu(operation);

    connect(addAction,SIGNAL(triggered()),this,SLOT(commandadd()));
    connect(subAction,SIGNAL(triggered()),this,SLOT(commandsub()));
    connect(mulAction,SIGNAL(triggered()),this,SLOT(commandmul()));
    connect(divAction,SIGNAL(triggered()),this,SLOT(commanddin()));
    connect(incAction,SIGNAL(triggered()),this,SLOT(commandinc()));
    connect(decAction,SIGNAL(triggered()),this,SLOT(commanddec()));
    connect(andAction,SIGNAL(triggered()),this,SLOT(commandand()));
    connect(orAction,SIGNAL(triggered()),this,SLOT(commandor()));
    connect(notAction,SIGNAL(triggered()),this,SLOT(commandnot()));
    connect(xorAction,SIGNAL(triggered()),this,SLOT(commandxor()));


    connect(commandinput,SIGNAL(movj_ensure_sig(QString *)),this,SIGNAL(movj_list_sig(QString *)));
    connect(this,SIGNAL(movj_list_sig(QString *)),this,SLOT(movj_slot(QString *)));
    connect(commandinput,SIGNAL(movl_ensure_sig(QString*)),this,SLOT(movl_slot(QString *)));
    connect(commandinput,SIGNAL(movc_ensure_sig(QString*)),this,SLOT(movc_slot(QString *)));
    connect(commandinput,SIGNAL(speed_ensure_sig(QString*)),this,SLOT(speed_slot(QString*)));
    connect(commandinput,SIGNAL(dout_ensure_sig(QString*)),this,SLOT(dout_slot(QString*)));
    connect(commandinput,SIGNAL(din_ensure_sig(QString*)),this,SIGNAL(din_list_simula_sig(QString*)));
    connect(commandinput,SIGNAL(pause_ensure_sig(QString*)),this,SIGNAL(pause_list_simula_sig(QString*)));
    connect(commandinput,SIGNAL(timer_ensure_sig(QString)),this,SIGNAL(timer_list_simula_sig(QString)));
    connect(commandinput,SIGNAL(jump_ensure_sig(QString*)),this,SIGNAL(jump_list_simula_sig(QString*)));
    connect(commandinput,SIGNAL(label_ensure_sig(QString)),this,SIGNAL(label_list_simula_sig(QString)));
    connect(commandinput,SIGNAL(call_ensure_sig(QString*)),this,SIGNAL(call_list_simula_sig(QString*)));
    connect(commandinput,SIGNAL(ret_ensure_sig(QString*)),this,SIGNAL(ret_list_simula_sig(QString*)));

    connect(this,SIGNAL(list_insert_sig()),commandinput,SLOT(input_insert_slot()));//list向input发送插入信号

    connect(commandinput,SIGNAL(input_list_insert_sig(QString*)),this,SLOT(list_simu_insert_slot(QString *)));





}

CommandList::~CommandList()
{
    delete ui;
}

void CommandList::commandmovj()
{

    commandinput->show();

    commandinput->commandchangej();
    select_input_command = "MOVJ";

}

void CommandList::commandmovl()
{
    commandinput->show();
    commandinput->commandchangel();
    select_input_command = "MOVL";

}

void CommandList::commandmovc()
{
    commandinput->show();
    commandinput->commandchangec();
    select_input_command = "MOVC";
}

void CommandList::commandimov()
{
    commandinput->show();
    commandinput->commandchangeimov();
}

void CommandList::commandspeed()
{
    commandinput->show();
    commandinput->commandchangespeed();
    select_input_command = "SPEED";
}

void CommandList::commandcoord()
{
    commandinput->show();
    commandinput->commandchangecoord();
}

void CommandList::commandhome()
{
    commandinput->show();
    commandinput->commandchangehome();
}

void CommandList::commanddout()
{
    commandinput->show();
    commandinput->commandchangedout();
    select_input_command = "DOUT";
}

void CommandList::commanddin()
{
    commandinput->show();
    commandinput->commandchangedin();
    select_input_command = "DIN";
}

void CommandList::commandaout()
{
    commandinput->show();
    commandinput->commandchangeaout();
}

void CommandList::commandain()
{
    commandinput->show();
    commandinput->commandchangeain();
}

void CommandList::commandaration()
{
    commandinput->show();
    commandinput->commandchangearation();
}

void CommandList::commandaratiof()
{
    commandinput->show();
    commandinput->commandchangearatiof();
}

void CommandList::commandjump()
{
    commandinput->show();
    commandinput->commandchangejump();
    select_input_command = "JUMP";
}

void CommandList::commandlabel()
{
    commandinput->show();
    commandinput->commandchangelabel();
    select_input_command = "LABEL";
}

void CommandList::commandcall()
{
    commandinput->show();
    commandinput->commandchangecall();
    select_input_command = "CALL";
}

void CommandList::commandret()
{
    commandinput->show();
    commandinput->commandchangeret();
    select_input_command = "RET";
}

void CommandList::commandtimer()
{
    commandinput->show();
    commandinput->commandchangetimer();
    select_input_command = "TIMER";
}

void CommandList::commandpause()
{
    commandinput->show();
    commandinput->commandchangepause();
    select_input_command = "PAUSE";
}

void CommandList::commandcwait()
{
    commandinput->show();
    commandinput->commandchangecwait();
}

void CommandList::commandadd()
{
    commandinput->show();
    commandinput->commandchangeadd();
}

void CommandList::commandsub()
{
    commandinput->show();
    commandinput->commandchangesub();
}

void CommandList::commandmul()
{
    commandinput->show();
    commandinput->commandchangemul();
}

void CommandList::commanddiv()
{
    commandinput->show();
    commandinput->commandchangediv();
}

void CommandList::commandinc()
{
    commandinput->show();
    commandinput->commandchangeinc();
}

void CommandList::commanddec()
{
    commandinput->show();
    commandinput->commandchangedec();
}

void CommandList::commandand()
{
    commandinput->show();
    commandinput->commandchangeand();
}

void CommandList::commandor()
{
    commandinput->show();
    commandinput->commandchangeor();
}

void CommandList::commandnot()
{
    commandinput->show();
    commandinput->commandchangenot();
}

void CommandList::commandxor()
{
    commandinput->show();
    commandinput->commandchangexor();
}

//void CommandList::on_mojpositioneditpushButton_clicked()

//修改相应命令
void CommandList::list_input_display()
{
    if(select_input_command=="movj")
    {
        commandmovj();
        commandinput->modify_movj_display();
    }
    else if(select_input_command=="movl")
    {
        commandmovl();
        commandinput->modify_movl_display();
    }
    else if(select_input_command=="movc")
    {
        commandmovc();
        commandinput->modify_movc_display();
    }
    else if(select_input_command=="speed")
    {
        commandspeed();
        commandinput->modify_speed_display();
    }
    else if(select_input_command=="dout")
    {
        commanddout();
        commandinput->modify_dout_display();
    }
    else if(select_input_command=="din")
    {
        commanddin();
        commandinput->modify_din_display();
    }
    else if(select_input_command=="pause")
    {
        commandpause();
        commandinput->modify_pause_display();
    }
    else if(select_input_command=="timer")
    {
        commandtimer();
        commandinput->modify_timer_display();
    }
    else if(select_input_command=="jump")
    {
        commandjump();
        commandinput->modify_jump_display();
    }
    else if(select_input_command=="label")
    {
        commandlabel();
        commandinput->modify_label_display();
    }
    else if(select_input_command=="call")
    {
        commandcall();
        commandinput->modify_call_display();
    }
    else if(select_input_command=="ret")
    {
        commandret();
        commandinput->modify_ret_display();
    }
}

void CommandList::on_pushButton_clicked()
{
    emit test_sig();
}

void CommandList::movj_slot(QString *order)
{
    emit movj_list_simula_sig(order);

}
void CommandList::movl_slot(QString *order)
{
    emit movl_list_simula_sig(order);
}

void CommandList::movc_slot(QString *order)
{
    emit movc_list_simula_sig(order);
}
void CommandList::speed_slot(QString *order)
{
    emit speed_list_simula_sig(order);
}

void CommandList::dout_slot(QString *order)
{
    emit dout_list_simula_sig(order);
}

void CommandList::list_insert_slot()
{
    emit list_insert_sig();
}



//插入向主界面方向
void CommandList::list_simu_insert_slot(QString *order)
{
    emit list_simu_insert_sig(order);
}

void CommandList::close_input_slot()
{
    commandinput->close();
}
