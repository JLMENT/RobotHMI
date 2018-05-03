#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QTextBlock"
//#include "configdialog.h"
//#include <QRegExp>
//#include "usr_motion_api.h"
#include <QTimer>
//#include "otherspace.h"

ThreadData::ThreadData(QObject *parent)
        :QThread(parent)
{

}

ThreadData::~ThreadData()
{
    mutex.lock();
    condition.wakeOne();
    mutex.unlock();
    wait();
}

void ThreadData::datawrite()
{

}
void ThreadData::run()
{

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QPalette pal(M->palette());
    //setColor(QPalette::Background,Qt::black);
    //setAutoFillBackground(true);
    //setPalette(pal);


    setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);

    page2 = NULL;
    page2 = new Page2();

    axis = NULL;
    axis = new Axis();

    positionseriate = NULL;
    positionseriate = new PositionSeriate();

    robotoriginpointlocationpage = new RobotOriginPointLocation();
    commandlistpage = new CommandList();

    simulationkeypad = NULL;
    simulationkeypad = new SimulationKeypad();

    key = NULL;
    key = new keypad();

    commandinput1 = new CommandInput();

    xmlcancle1 = new XmlCancle();

   // commandinput1 =NULL;
    //commandinput1 = new CommandInput();

    //connect(commandinput1,SIGNAL(commandsig(int)),)

    //other_param = new OtherSetup;
    ui->stackedWidget->addWidget(numeric_type);
    //ui->stackedWidget->setCurrentIndex(28);
    ui->stackedWidget->addWidget(axis_param);
    ui->stackedWidget->addWidget(descarts_param);
    ui->stackedWidget->addWidget(cpspace_setup);
    ui->stackedWidget->addWidget(other_param);
    ui->stackedWidget->addWidget(dh_param);
    ui->stackedWidget->addWidget(origin_offset);
    ui->stackedWidget->addWidget(coordinatemanagewidget);
    ui->stackedWidget->addWidget(toolmanagewidget);
    ui->stackedWidget->addWidget(currentpositionwidget);//37
    ui->stackedWidget->addWidget(alarmwidget);//38
    ui->stackedWidget->setCurrentIndex(37);


    m_menu=new QMenu(this);
    m_addAction = new QAction(m_menu);
    m_subAction = new QAction(m_menu);
    m_delAction = new QAction(m_menu);

    m_addAction->setCheckable(true);
    m_delAction->setAutoRepeat(true);

    m_addAction->setText(QObject::tr("add"));
    m_subAction->setText(QObject::tr("submenu"));
    m_delAction->setText(QObject::tr("select"));

    m_menu->addAction(m_addAction);
    m_menu->addAction(m_subAction);
    m_menu->addAction(m_delAction);

    connect(m_addAction,SIGNAL(triggered()),this,SLOT(addFunc()));
    connect(m_delAction,SIGNAL(triggered()),this,SLOT(delFunc()));

    m_subMenu = new QMenu(this);
    m_subAdd = new QAction(m_subMenu);
    m_subDel = new QAction(m_subMenu);
    m_subAdd->setText(QObject::tr("添加子菜单"));
    m_subDel->setText(QObject::tr("subselect"));
    m_subMenu->addAction(m_subAdd);
    m_subMenu->addAction(m_subDel);
    m_subAction->setMenu(m_subMenu);

    ui->MainMenubutton->setMenu(m_menu);

    m_programmenu = new QMenu(this);

    m_programcontent = new QAction(m_programmenu);
    m_programmain = new QAction(m_programmenu);
    m_programmanage = new  QAction(m_programmenu);
    m_programselect = new QAction(m_programmenu);


    m_programcontent->setText(QObject::tr("程序内容"));
    m_programmain->setText(QObject::tr("主程序"));
    m_programmanage->setText(QObject::tr("程序管理"));
    m_programselect->setText(QObject::tr("程序选择"));


    m_programmenu->addAction(m_programcontent);
    m_programmenu->addAction(m_programselect);
    m_programmenu->addAction(m_programmanage);
    //m_programmenu->addAction(m_programmain);



    ui->ProgramButton1->setMenu(m_programmenu);
    ui->ProgramButton1->setIcon(QIcon("355.png"));
    connect(m_programcontent,SIGNAL(triggered()),this,SLOT(programcontentpage()));
    connect(m_programselect,SIGNAL(triggered()),this,SLOT(programselectpage()));
    connect(m_programmanage,SIGNAL(triggered()),this,SLOT(programmanagepage()));
    connect(m_programmain,SIGNAL(triggered()),this,SLOT(programmainpage()));

  /* m_toolmenu = new  QMenu(this);
    m_setingspecialoperationmenu = new QAction(m_toolmenu);
    m_speedadjustmenu = new QAction(m_toolmenu);

    m_setingspecialoperationmenu->setText(QObject::tr("工具管理"));
    m_speedadjustmenu->setText(QObject::tr("速度调节"));

    m_toolmenu->addAction(m_setingspecialoperationmenu);
    m_toolmenu->addAction(m_speedadjustmenu);

    ui->Goodtoolbutton->setMenu(m_toolmenu);*/



    //stack = new QStackedWidget(this);
   // page1 = new SpeedAdjust;
   // stack->addWidget(page1);

    //MainWindow *MWpage = new MainWindow(this);
   // connect(MWpage,SIGNAL(ActionClick(int)),stack,SLOT(setCurrentIndex(int)));

   /* connect(m_setingspecialoperationmenu,SIGNAL(triggered()),this,SLOT(SpdAdj1()));
    connect(m_speedadjustmenu,SIGNAL(triggered()),this,SLOT(SpeAdj2()));*/

   // QHBoxLayout *mainlayout = new QHBoxLayout(this);
    //mainlayout->addWidget(MWpage);
   // mainlayout->addWidget(stack);
   // mainlayout->setStretchFactor(MWpage,1);
   // mainlayout->setStretchFactor(stack,7);

   // connect(ui->pushButton_6,SIGNAL(clicked()),this,MainWindow_page2());

    m_setmenu = new QMenu(this);

    axisjointmenu = new QAction(m_setmenu);
    dklmenu = new QAction(m_setmenu);
    cpmenu = new QAction(m_setmenu);
    dhmenu = new QAction(m_setmenu);
    dhlmenu = new QAction(m_setmenu);
    axiscontrolmenu = new QAction(m_setmenu);
    otherparam = new QAction(m_setmenu);
    ioparametermenu = new QAction(m_setmenu);


    axisjointmenu->setText(QObject::tr("轴关节空间"));
    dklmenu->setText(QObject::tr("笛卡尔空间"));
    cpmenu->setText(QObject::tr("CP空间"));
    dhmenu->setText(QObject::tr("DH参数"));
    dhlmenu->setText(QObject::tr("DH限制参数"));
    axiscontrolmenu->setText(QObject::tr("轴控制参数设置"));
    otherparam->setText(QObject::tr("其他参数"));
    ioparametermenu->setText(QObject::tr("IO参数设置"));

    m_setmenu->addAction(axisjointmenu);
    m_setmenu->addAction(dklmenu);
    m_setmenu->addAction(cpmenu);
    m_setmenu->addAction(dhmenu);
    m_setmenu->addAction(dhlmenu);
    m_setmenu->addAction(axiscontrolmenu);
    m_setmenu->addAction(otherparam);
    m_setmenu->addAction(ioparametermenu);

    ui->SetupButton->setMenu(m_setmenu);

    qDebug()<<"set up star";
    //connect(axisjointmenu,SIGNAL(triggered()),ui->stackedWidget,SLOT(setCurrentIndex(3)));

    //connect(m_teachingconditionmenu,SIGNAL(triggered()),ui->stackedWidget,SLOT(setCurrentIndex(0)));
    //connect(m_operatingconditionmenu,SIGNAL(triggered()),ui->stackedWidget,SLOT(setCurrentIndex(1)));
    connect(axisjointmenu,SIGNAL(triggered()),this,SLOT(stackpage1()));
    connect(dklmenu,SIGNAL(triggered()),this,SLOT(stackpage2()));
    connect(cpmenu,SIGNAL(triggered()),this,SLOT(cppage()));
    connect(dhmenu,SIGNAL(triggered()),this,SLOT(dhpage()));
    connect(dhlmenu,SIGNAL(triggered()),this,SLOT(dhlpage()));
    connect(axiscontrolmenu,SIGNAL(triggered()),this,SLOT(axiscontrolpage()));
    connect(otherparam,SIGNAL(triggered()),this,SLOT(otherpage()));
    connect(ioparametermenu,SIGNAL(triggered()),this,SLOT(ioparameterpage()));

    connect(ui->robot_op_action,SIGNAL(triggered()),this,SLOT(robotoriginpointpage()));

    qDebug()<<"set up";

    m_robotmenu = new QMenu(this);
    currentpositionmenu = new QAction(m_robotmenu);
    zeropositionsetupmenu = new QAction(m_robotmenu);
    coordinateSMmenu = new QAction(m_robotmenu);
    toolmanagementmenu = new QAction(m_robotmenu);
    //exceptionhandlingmenu = new QAction(m_robotmenu);

    currentpositionmenu->setText(QObject::tr("当前位置"));
    zeropositionsetupmenu->setText(QObject::tr("零位标定"));
    coordinateSMmenu->setText(QObject::tr("坐标系管理"));
    toolmanagementmenu->setText(QObject::tr("工具管理"));
   // exceptionhandlingmenu->setText(QObject::tr("异常处理"));

    m_robotmenu->addAction(currentpositionmenu);
    m_robotmenu->addAction(zeropositionsetupmenu);
    m_robotmenu->addAction(coordinateSMmenu);
    m_robotmenu->addAction(toolmanagementmenu);
   // m_robotmenu->addAction(exceptionhandlingmenu);

    ui->RobotButton->setMenu(m_robotmenu);

    connect(currentpositionmenu,SIGNAL(triggered()),this,SLOT(currentpositionpage()));
    connect(zeropositionsetupmenu,SIGNAL(triggered()),this,SLOT(zeropositionsetuppage()));
    connect(coordinateSMmenu,SIGNAL(triggered()),this,SLOT(coordinateSMpage()));
    connect(toolmanagementmenu,SIGNAL(triggered()),this,SLOT(toolmanagementpage()));
  //  connect(exceptionhandlingmenu,SIGNAL(triggered()),this,SLOT(exceptionhandlingpage()));


    m_systemmenu = new QMenu(this);
    m_systemmenu = new QMenu(this);
    userrightsmenu = new QAction(m_systemmenu);
    warninghistorymenu = new QAction(m_systemmenu);
    editionmenu = new QAction(m_systemmenu);

    userrightsmenu->setText(QObject::tr("用户权限"));
    warninghistorymenu->setText(QObject::tr("报警历史"));
    editionmenu->setText(QObject::tr("版本"));

    m_systemmenu->addAction(userrightsmenu);
    m_systemmenu->addAction(warninghistorymenu);
    m_systemmenu->addAction(editionmenu);

    ui->SystemButton->setMenu(m_systemmenu);

    connect(userrightsmenu,SIGNAL(triggered()),this,SLOT(userrightspage()));
    connect(warninghistorymenu,SIGNAL(triggered()),this,SLOT(warninghistorypage()));
    connect(editionmenu,SIGNAL(triggered()),this,SLOT(editionpage()));






    m_iomenu = new QMenu(this);
    iostatusmenu = new QAction(m_iomenu);
    CAstatusmenu = new QAction(m_iomenu);
    Astatusmenu = new QAction(m_iomenu);

    iostatusmenu->setText(QObject::tr("I/O状态"));
    CAstatusmenu->setText(QObject::tr("控制轴状态"));
    Astatusmenu->setText(QObject::tr("通用轴状态"));

    m_iomenu->addAction(iostatusmenu);
    m_iomenu->addAction(CAstatusmenu);
    m_iomenu->addAction(Astatusmenu);

    ui->I_OButton->setMenu(m_iomenu);

    connect(iostatusmenu,SIGNAL(triggered()),this,SLOT(iostatuspage()));
    connect(CAstatusmenu,SIGNAL(triggered()),this,SLOT(CAstatuspage()));
    connect(Astatusmenu,SIGNAL(triggered()),this,SLOT(Astatuspage()));





    m_seriatemenu = new QMenu(this);
    valuestylemenu = new QAction(m_seriatemenu);
   // valuemonitormenu = new QAction(m_seriatemenu);

    valuestylemenu->setText(QObject::tr("数值型"));
   // valuemonitormenu->setText(QObject::tr("变量监控"));

    m_seriatemenu->addAction(valuestylemenu);
   // m_seriatemenu->addAction(valuemonitormenu);


    ui->VariateButton->setMenu(m_seriatemenu);

    connect(valuestylemenu,SIGNAL(triggered()),this,SLOT(valuestylepage()));
   // connect(valuemonitormenu,SIGNAL(triggered()),this,SLOT(valuemonitorpage()));




 /*   m_outstoragemenu = new QMenu(this);
    installmenu = new QAction(m_outstoragemenu);
    savemenu = new QAction(m_outstoragemenu);
    checkmenu = new QAction(m_outstoragemenu);
    deletemenu = new QAction(m_outstoragemenu);
    equipmentmenu = new QAction(m_outstoragemenu);

    installmenu->setText(QObject::tr("安装"));
    savemenu->setText(QObject::tr("保存"));
    checkmenu->setText(QObject::tr("校验"));
    deletemenu->setText(QObject::tr("删除"));
    equipmentmenu->setText(QObject::tr("设备"));

    m_outstoragemenu->addAction(installmenu);
    m_outstoragemenu->addAction(savemenu);
    m_outstoragemenu->addAction(checkmenu);
    m_outstoragemenu->addAction(deletemenu);
    m_outstoragemenu->addAction(equipmentmenu);

    ui->OutsideStorageButton->setMenu(m_outstoragemenu);

    connect(installmenu,SIGNAL(triggered()),this,SLOT(installpage()));
    connect(savemenu,SIGNAL(triggered()),this,SLOT(savepage()));
    connect(checkmenu,SIGNAL(triggered()),this,SLOT(checkpage()));
    connect(deletemenu,SIGNAL(triggered()),this,SLOT(deletepage()));
    connect(equipmentmenu,SIGNAL(triggered()),this,SLOT(equipmentpage()));*/

    ////菜单////////////////
    m_edit = new QMenu(this);
    copymenu = new QAction(m_edit);
    cutmenu = new QAction(m_edit);
    pastemenu = new QAction(m_edit);
    startrowmenu = new QAction(m_edit);
    endrowmenu = new QAction(m_edit);
    copymenu->setText(QObject::tr("复制"));
    cutmenu->setText(QObject::tr("剪切"));
    pastemenu->setText(QObject::tr("粘贴"));
    startrowmenu->setText(QObject::tr("起始行"));
    endrowmenu->setText(QObject::tr("结束行"));
    m_edit->addAction(startrowmenu);
    m_edit->addAction(endrowmenu);
    m_edit->addAction(copymenu);
    m_edit->addAction(cutmenu);
    m_edit->addAction(pastemenu);

    ui->editpushButton->setMenu(m_edit);

    connect(startrowmenu,SIGNAL(triggered()),this,SLOT(start_line_slot()));
    connect(endrowmenu,SIGNAL(triggered()),this,SLOT(end_line_slot()));
    connect(copymenu,SIGNAL(triggered()),this,SLOT(copy_slot()));
    connect(cutmenu,SIGNAL(triggered()),this,SLOT(cut_slot()));
    connect(pastemenu,SIGNAL(triggered()),this,SLOT(paste_slot()));

    //设置程序编辑器不能编辑
    //ui->plainTextEdit->setDisabled(true);
    //设置编辑器字体大小
    //ui->plainTextEdit->setFont(QFont("Agency FB",15,QFont::Normal));


    //init Tool/User parameter
    mdl.acc = 1;
    mdl.dec = 1;
    mdl.free = 1;

    mdl.tool.x = 0.0;
    mdl.tool.y = 0.0;
    mdl.tool.z = 0.0;
    mdl.tool.rx = 0.0;
    mdl.tool.ry = 0.0;
    mdl.tool.rz = 0.0;

    mdl.user.x = 0.0;
    mdl.user.y = 0.0;
    mdl.user.z = 0.0;
    mdl.user.a = 0.0;
    mdl.user.b = 0.0;
    mdl.user.c = 0.0;

    lm.acc = 1;
    lm.dec = 1;

    /*cm.endPoint.x= ;   //double
    cm.endPoint.y= ;
    cm.endPoint.z= ;

    cm.zyx.a= ;        //double
    cm.zyx.b= ;
    cm.zyx.c= ;*/

    cdm.free= 0;
    cdm.vL= 1000;
    cdm.vR= 50;
    cdm.acc= 1;
    cdm.dec= 1;
    cdm.free = 1;

    cdm.tool.x = 0.0;
    cdm.tool.y = 0.0;
    cdm.tool.z = 0.0;
    cdm.tool.rx = 0.0;
    cdm.tool.ry = 0.0;
    cdm.tool.rz = 0.0;

    cdm.user.x = 0.0;
    cdm.user.y = 0.0;
    cdm.user.z = 0.0;
    cdm.user.a = 0.0;
    cdm.user.b = 0.0;
    cdm.user.c = 0.0;


    cm.vL= 200;
    cm.vR= 50;
    cm.acc= 1;
    cm.dec= 1;

    ui->plainTextEdit->setEnabled(false);



    connect(ui->valuestylecomboBox_2,SIGNAL(currentIndexChanged(int)),ui->stackedWidget_10,SLOT(setCurrentIndex(int)));
    connect(ui->cuzbcomboBox,SIGNAL(currentIndexChanged(int)),ui->stackedWidget_9,SLOT(setCurrentIndex(int)));
    connect(ui->usercomboBox_8,SIGNAL(currentIndexChanged(int)),ui->stackedWidget_17,SLOT(setCurrentIndex(int)));

    //命令输入窗口和主窗口命令显示信号和槽连接
    connect(simulationkeypad,SIGNAL(movj_simula_slot_sig(QString *)),this,SLOT(movj_command_display(QString *)));
    connect(simulationkeypad,SIGNAL(movl_simula_slot_sig(QString*)),this,SLOT(movl_command_display(QString*)));
    connect(simulationkeypad,SIGNAL(movc_simula_slot_sig(QString *)),this,SLOT(movc_command_display(QString *)));
    connect(simulationkeypad,SIGNAL(speed_simula_slot_sig(QString*)),this,SLOT(speed_command_display(QString*)));
    connect(simulationkeypad,SIGNAL(dout_simula_slot_sig(QString*)),this,SLOT(dout_command_display(QString *)));
    connect(simulationkeypad,SIGNAL(din_simula_slot_sig(QString*)),this,SLOT(din_command_display(QString *)));
    connect(simulationkeypad,SIGNAL(pause_simula_slot_sig(QString *)),this,SLOT(pause_command_display(QString *)));
    connect(simulationkeypad,SIGNAL(timer_simula_slot_sig(QString)),this,SLOT(timer_command_display(QString)));
    connect(simulationkeypad,SIGNAL(jump_simula_slot_sig(QString *)),this,SLOT(jump_command_display(QString *)));
    connect(simulationkeypad,SIGNAL(label_simula_slot_sig(QString)),this,SLOT(label_command_display(QString)));
    connect(simulationkeypad,SIGNAL(call_simula_slot_sig(QString *)),this,SLOT(call_command_display(QString *)));
    connect(simulationkeypad,SIGNAL(ret_simula_slot_sig(QString *)),this,SLOT(ret_command_display(QString *)));

    //connect(simulationkeypad,SIGNAL(dout_simula_slot_sig(QString*)),this,SLOT(dout_simula_slot_sig(QString*)));

    connect(simulationkeypad,SIGNAL(simu_up_sig()),this,SLOT(program_cursor_up()));
    connect(simulationkeypad,SIGNAL(simu_down_sig()),this,SLOT(program_cursor_down()));
    connect(simulationkeypad,SIGNAL(simu_delete_sig()),this,SLOT(program_delete_line()));
    //connect(simulationkeypad,SIGNAL(simu_insert_sig()),this,SLOT(program_insert_line()));
    connect(simulationkeypad,SIGNAL(simu_main_insert_sig(QString*)),this,SLOT(insert_slot(QString *)));
    connect(simulationkeypad,SIGNAL(simu_main_modify_sig()),this,SLOT(require_modify_data()),Qt::DirectConnection);

    //multi step P/N
    connect(simulationkeypad,SIGNAL(send_current_line_sig()),this,SLOT(send_current_line_slot()));
    connect(simulationkeypad,SIGNAL(send_single_backward_sig()),this,SLOT(single_step_backward_slot()));
    connect(simulationkeypad,SIGNAL(simu_MultiSP_sig()),this,SLOT(multip_send_line_slot()));
    connect(simulationkeypad,SIGNAL(simu_MultiSN_sig()),this,SLOT(multin_send_line_slot()));
    connect(simulationkeypad,SIGNAL(simu_MultiSP_release_sig()),this,SLOT(multip_release_send_line_slot()));
    connect(simulationkeypad,SIGNAL(simu_MultiSN_release_sig()),this,SLOT(multin_release_send_line_slot()));

    //restart
    connect(simulationkeypad,SIGNAL(simu_restart_sig()),this,SLOT(restart_run_slot()));
    //pause
    connect(simulationkeypad,SIGNAL(simu_pause_sig()),this,SLOT(when_run_pause_slot()));

    mainwindow_timer1 = new QTimer;
    connect(mainwindow_timer1,SIGNAL(timeout()),this,SLOT(mainwindow_refresh_cursor()));
    //mainwindow_timer1->start(100);
    //Time stop connect;
    connect(simulationkeypad,SIGNAL(simu_stop_timer1_sig()),mainwindow_timer1,SLOT(stop()));
    connect(simulationkeypad,SIGNAL(simu_test_run_sig()),this,SLOT(test_run_slot()));

    //copy-cut-display
    connect(xmlcopycut,SIGNAL(refresh_reload_program(QString)),this,SLOT(refresh_reload_program_slot(QString)));

    //file delete_copy_rename_slot
    connect(ui->prog_manage_delete_pushButton,SIGNAL(clicked()),this,SLOT(file_manage_delete()));
    connect(ui->prog_manage_copy_pushButton,SIGNAL(clicked()),this,SLOT(file_manage_copy()));
    connect(ui->prog_manage_rename_pushButton,SIGNAL(clicked()),this,SLOT(file_manage_rename()));


    //keypadboard sig_slot
    connect(this,SIGNAL(main_insert_sig()),commandlistM,SLOT(list_insert_slot()));

    ui->plainTextEdit->setFont(QFont("wenquanyi",9));

    //lineEdit inherit digitkeyboard;

//    ui->target_prog_lineEdit->inherits("DigetEdit");
//    ui->source_prog_lineEdit->inherits("EditKeyboard");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::mainwindow_refresh_cursor()
{
    int line_number;
    int total_row;

    MotionFeedback fb;
    CTRL_GetMotionStatus(&fb);
    line_number = fb.lineNumber;
    total_row = ui->plainTextEdit->blockCount();
    total_row-=2;
    //ui->plainTextEdit->setCursorPos(line_number,1);

    if(fb.motionState == COMMAND_EXEC)
    {
        ui->plainTextEdit->setCursorPos(fb.lineNumber,1);
    }
    else
    {
        //run_file = new RunFile(program_filename);
        if(run_file!=NULL)
        {
            ui->plainTextEdit->setCursorPos(run_file->getCurrentNumber(),1);
        }
    }

    //qDebug()<<fb.errCode;

    /*if(line_number==total_row)
    {
        mainwindow_timer1->stop();
    }*/
    //qDebug("timerddddddddddd");
    //qDebug()<<line_number;

}

void MainWindow::addFunc()
{
    if(page2!=NULL)
    {
        page2->exec();
    }

}
void MainWindow::delFunc()
{
}

/*void MainWindow::MainWindow_page2()
{
    if(page2!=NULL)
    {
        page2->exec();
    }
}*/

void MainWindow::on_pushButton_6_clicked()
{
    if(page2!=NULL)
    {
        page2->exec();
    }
}

void MainWindow::programcontentpage()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::programselectpage()
{
    ui->stackedWidget->setCurrentIndex(23);

    int num = ui->selectprogramgridLayout->count();
    if(num>0)
    {
        for(int j=num-1;j>=0;j--)
        {
            QWidget *p = ui->selectprogramgridLayout->itemAt(j)->widget();
            ui->selectprogramgridLayout->removeWidget(p);
            delete p;
        }
    }

    QString strfilename;
    QString buttonname;
    filemanageselect->display_source_program_list();
    for(int i=0;i<filemanageselect->strlist.count();i++)
    {
        strfilename = filemanageselect->strlist.at(i);
        qDebug()<<strfilename;
        buttonname = strfilename;
        FileSelectPushButton *strfilename = new FileSelectPushButton(buttonname);
        ui->selectprogramgridLayout->addWidget(strfilename,i/4,i%4);
        connect(strfilename,SIGNAL(reload_program_sig(QString)),this,SLOT(reload_select_file(QString)));
    }
}

void MainWindow::programmanagepage()
{
    ui->stackedWidget->setCurrentIndex(22);
}

void MainWindow::programmainpage()
{
    ui->stackedWidget->setCurrentIndex(24);
}

void MainWindow::SpdAdj1()
{
    emit ActionClick(0);
}
void MainWindow::SpeAdj2()
{
    emit ActionClick(1);
}

void MainWindow::stackpage1()
{
    //ui->stackedWidget->setCurrentIndex(4);
    ui->stackedWidget->setCurrentIndex(29);
}

void MainWindow::stackpage2()
{
    //ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget->setCurrentIndex(30);
}

void MainWindow::cppage()
{
    //ui->stackedWidget->setCurrentIndex(6);
    ui->stackedWidget->setCurrentIndex(31);
}

void MainWindow::dhpage()
{
    //ui->stackedWidget->setCurrentIndex(7);
    ui->stackedWidget->setCurrentIndex(33);
}

void MainWindow::dhlpage()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::axiscontrolpage()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::otherpage()
{
    //ui->stackedWidget->setCurrentIndex(8);
    ui->stackedWidget->setCurrentIndex(32);
}

void MainWindow::ioparameterpage()
{
    ui->stackedWidget->setCurrentIndex(27);
}

void MainWindow::currentpositionpage()
{
    //ui->stackedWidget->setCurrentIndex(13);
    ui->stackedWidget->setCurrentIndex(37);
}
void MainWindow::zeropositionsetuppage()
{
    //ui->stackedWidget->setCurrentIndex(14);
    ui->stackedWidget->setCurrentIndex(34);
}

void MainWindow::coordinateSMpage()
{
    //ui->stackedWidget->setCurrentIndex(19);
    ui->stackedWidget->setCurrentIndex(35);
}

void MainWindow::toolmanagementpage()
{
    //ui->stackedWidget->setCurrentIndex(20);
    ui->stackedWidget->setCurrentIndex(36);
}

void MainWindow::exceptionhandlingpage()
{
    ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::userrightspage()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::warninghistorypage()
{
    //ui->stackedWidget->setCurrentIndex(16);
    ui->stackedWidget->setCurrentIndex(38);
}

void MainWindow::editionpage()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::iostatuspage()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::CAstatuspage()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::Astatuspage()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::valuestylepage()
{
    //ui->stackedWidget->setCurrentIndex(25);
    ui->stackedWidget->setCurrentIndex(28);
}

void MainWindow::valuemonitorpage()
{
    //ui->stackedWidget->setCurrentIndex();
}

void MainWindow::installpage()
{
    ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::savepage()
{
    //ui->stackedWidget->setCurrentIndex();
}

void MainWindow::checkpage()
{
    //ui->stackedWidget->setCurrentIndex();
}

void MainWindow::deletepage()
{
   // ui->stackedWidget->setCurrentIndex();
}

void MainWindow::equipmentpage()
{
    //ui->stackedWidget->setCurrentIndex();
}

void MainWindow::robotoriginpointpage()
{
    robotoriginpointlocationpage->exec();
}



void MainWindow::on_ParameterButton_clicked()
{
    /*if(axis!=NULL)
    {
        axis->show();
    }*/
}

void MainWindow::on_positioneditpushButton_clicked()
{
    if(positionseriate!=NULL)
    {
        positionseriate->show();
    }
}

void MainWindow::on_simulatekeypushButton_clicked()
{
    if(simulationkeypad != NULL)
    {
        simulationkeypad->show();
    }
}

void MainWindow::on_AxispushButton_1_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_AxispushButton_2_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(3);

}

void MainWindow::on_Axis11nextpushButton_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(1);

}

void MainWindow::on_iomnextpushButton_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(1);
}

void MainWindow::on_dgituppushButton_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(0);
}

void MainWindow::on_dgetnextpushButton_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(2);
}

void MainWindow::on_kmuppushButton_clicked()
{
    ui->stackedWidget_8->setCurrentIndex(1);
}

void MainWindow::movjeditposition()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_lwbdcpushButton_581_clicked()
{
    //a++;
   // if(a%2)
   // {
    QPalette pal = ui->lwbdcpushButton_581->palette();
    pal.setColor(QPalette::Button,Qt::blue);
    ui->lwbdcpushButton_581->setPalette(pal);
    ui->lwbdcpushButton_581->setAutoFillBackground(true);
    ui->lwbdcpushButton_581->setFlat(true);
   /* }
    else{
        QPalette pal = ui->lwbdcpushButton_581->palette();
        pal.setColor(QPalette::Button,Qt::white);
        ui->lwbdcpushButton_581->setPalette(pal);
        ui->lwbdcpushButton_581->setAutoFillBackground(true);
        ui->lwbdcpushButton_581->setFlat(true);
    }*/

}

void MainWindow::on_lwbdcpushButton_582_clicked()
{
    QPalette pal = ui->lwbdcpushButton_582->palette();
    pal.setColor(QPalette::Button,Qt::green);
    ui->lwbdcpushButton_582->setPalette(pal);
    ui->lwbdcpushButton_582->setAutoFillBackground(true);
    ui->lwbdcpushButton_582->setFlat(true);
}

void MainWindow::on_lwbdcpushButton_583_clicked()
{
    QPalette pal = ui->lwbdcpushButton_583->palette();
    pal.setColor(QPalette::Button,Qt::blue);
    ui->lwbdcpushButton_583->setPalette(pal);
    ui->lwbdcpushButton_583->setAutoFillBackground(true);
    ui->lwbdcpushButton_583->setFlat(true);
}

void MainWindow::on_lwbdcpushButton_584_clicked()
{
    QPalette pal = ui->lwbdcpushButton_584->palette();
    pal.setColor(QPalette::Button,Qt::red);
    ui->lwbdcpushButton_584->setPalette(pal);
    ui->lwbdcpushButton_584->setAutoFillBackground(true);
    ui->lwbdcpushButton_584->setFlat(true);
}

void MainWindow::on_lwbdcpushButton_587_clicked()
{
    QPalette pal = ui->lwbdcpushButton_587->palette();
    pal.setColor(QPalette::Button,Qt::blue);
    ui->lwbdcpushButton_587->setPalette(pal);
    ui->lwbdcpushButton_587->setAutoFillBackground(true);
    ui->lwbdcpushButton_587->setFlat(true);
}

void MainWindow::on_lwbdcpushButton_588_clicked()
{
    QPalette pal = ui->lwbdcpushButton_588->palette();
    pal.setColor(QPalette::Button,Qt::blue);
    ui->lwbdcpushButton_588->setPalette(pal);
    ui->lwbdcpushButton_588->setAutoFillBackground(true);
    ui->lwbdcpushButton_588->setFlat(true);
}

void MainWindow::on_lwbdcpushButton_586_clicked()
{
    QPalette pal = ui->lwbdcpushButton_586->palette();
    pal.setColor(QPalette::Button,Qt::green);
    ui->lwbdcpushButton_586->setPalette(pal);
    ui->lwbdcpushButton_586->setAutoFillBackground(true);
    ui->lwbdcpushButton_586->setFlat(true);
}

void MainWindow::on_lwbdcpushButton_585_clicked()
{
    QPalette pal = ui->lwbdcpushButton_585->palette();
    pal.setColor(QPalette::Button,Qt::blue);
    ui->lwbdcpushButton_585->setPalette(pal);
    ui->lwbdcpushButton_585->setAutoFillBackground(true);
    ui->lwbdcpushButton_585->setFlat(true);
}

void MainWindow::on_showpushButton_clicked()
{
    if(key != NULL)
    {
        key->show();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

//    int num = ui->programlistverticalLayout->count();
//    qDebug()<<num;
//    if(num>0)
//    {
//        for(int j=num-1;j>=0;j--)
//        {
//            qDebug()<<55;
//            QWidget *p = ui->programlistverticalLayout->itemAt(j)->widget();
//            qDebug()<<66;
//            ui->programlistverticalLayout->removeWidget(p);
//            delete p;
//        }
//    }
    //update();

    int num = ui->programlistgridLayout->count();
    //qDebug()<<num;
    if(num>0)
    {
         //ui->programlistverticalLayout->
        for(int j=num-1;j>=0;j--)
        //for(int j=0;j<num;j++)
        {
            //qDebug()<<55;
            QWidget *p = ui->programlistgridLayout->itemAt(j)->widget();
            //qDebug()<<66;
            ui->programlistgridLayout->removeWidget(p);
            //qDebug()<<j;
            delete p;
        }
    }

    QString strfilename;
    QString buttonname;
    filemanage->display_source_program_list();
    qDebug()<<111111111111;
    qDebug()<<filemanage->strlist.count();
    for(int i=0;i<filemanage->strlist.count();i++)
    //for(int i=0;i<2;i++)
    {
        strfilename = filemanage->strlist.at(i);
        buttonname = strfilename;
        qDebug()<<strfilename;
        FileSelectPushButton *strfilename = new FileSelectPushButton(buttonname);
        //qDebug()<<strfilename;
        //ui->programlistverticalLayout->addWidget(strfilename);
        ui->programlistgridLayout->addWidget(strfilename,i/4,i%4);

        //connect(strfilename,SIGNAL(reload_program_sig(QString)),this,SLOT(reload_select_file(QString)));
        connect(strfilename,SIGNAL(select_program_sig(QString)),this,SLOT(ensure_select_file(QString)));
        //qDebug()<<connect(strfilename,SIGNAL(reload_program_sig(QString)),this,SLOT(reload_select_file(QString)));
//        QPushButton *(filemanage->strlist.at(i)) = new QPushButton(filemanage->strlist.at(i));
//        ui->stackedWidget_4->addWidget(filemanage->strlist.at(i));
        //strfilename = filemanage->strlist.at(i);
        //connect(filemanage->strlist.at(i),SIGNAL(clicked()),this,SLOT(reload_select_file(strfilename)));
    }
    //ui->programlistverticalLayout->update();
}

void MainWindow::on_Goodtoolbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
}

void MainWindow::on_ProgramButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_OutsideStorageButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_new_main_prog_pushButton_pressed()
{
    //xml_prog_name
    program_filename= ui->target_prog_lineEdit->text();

    /////////////write Annotation of File///////////////////////

    progfilenote->write_comments(program_filename,ui->annotation_textEdit->toPlainText());

    //RunFile init
    run_file = new RunFile(program_filename);
    run_file->init();

    /*QRegExp rx;
    rx.setPattern("[A-Za-z_]+[A-Za-z_0-9]*");
    QRegExpValidator v(rx,0);
    int pos = 0;
    QString tring = v.validate(xml_prog_name,pos);
    if(tring=="Intermediate")*/
    if(program_filename.isEmpty())
    {
        QMessageBox::warning(NULL,"WARNING","FILENAME SHI SPACE!");
        return;
    }
    //qDebug("hello");

    //创建对应文件名的程序和对应程序位置的xml文件
    //QString tring = "tring";
    xmlcancle1->create_xml_file(program_filename);
    xmlcancle1->create_xml_position_file(program_filename);

    //读取对应的文件，将里面的数据显示到程序编辑界面中
    xmlcancle1->read_xml_file(ui->plainTextEdit,program_filename);

    ui->stackedWidget->setCurrentIndex(0);
    ui->prog_name_label->setText(program_filename);
}

//正常输入控制命令
void MainWindow::movj_command_display(QString *order)
{
   // int current_row,
   int total_row;
   // current_row = ui->plainTextEdit->textCursor().blockNumber();
    total_row = ui->plainTextEdit->blockCount();
    --total_row;
    if(total_row>=1)
    ui->plainTextEdit->setCursorPos(total_row,1);

    QString untill = (order[3]=="0")?(""):(order[4]+order[5]+order[6]+order[7]+order[8]);
    //ui->plainTextEdit->appendPlainText("MOVJ VJ="+order[1]+" "+"PL="+order[2]+" "+untill+" "+"ACC="+order[9]+" "+"DEC="+order[10]+" "+"N_WAIT="+order[11]+" "+order[0]);
    ui->plainTextEdit->insertPlainText("MOVJ VJ="+order[1]+" "+"PL="+order[2]+" "+untill+" "+"ACC="+order[9]+" "+"DEC="+order[10]+" "+"N_WAIT="+order[11]+" "+order[0]+"\n");
}

void MainWindow::movl_command_display(QString *order)
{
   // int current_row,
   int  total_row;
   // current_row = ui->plainTextEdit->textCursor().blockNumber();
    total_row = ui->plainTextEdit->blockCount();
    --total_row;
    if(total_row>=1)
    ui->plainTextEdit->setCursorPos(total_row,1);

    QString untill = (order[4]=="0")?(""):(order[5]+order[6]+order[7]+order[8]+order[9]);
    QString usr = (order[14]=="0")?(""):(order[15]);
    QString tool = (order[16]=="0")?(""):(order[17]);
    //ui->plainTextEdit->appendPlainText("MOVJ VJ="+order[1]+" "+"PL="+order[2]+" "+untill+" "+"ACC="+order[9]+" "+"DEC="+order[10]+" "+"N_WAIT="+order[11]+" "+order[0]);
    ui->plainTextEdit->insertPlainText("MOVL VL="+order[1]+" "+"VR="+order[2]+" "+"PL="+order[3]+" "+untill+" "+"ACC="+order[10]+" "+"DEC="+order[11]+" "+"CR="+order[12]+"N_WAIT="+order[13]+" "+usr+" "+tool+" "+order[0]+"\n");
}
void MainWindow::movc_command_display(QString *order)
{
   // int current_row,
    int total_row;
   // current_row = ui->plainTextEdit->textCursor().blockNumber();
    total_row = ui->plainTextEdit->blockCount();
    --total_row;
    if(total_row>=1)
    ui->plainTextEdit->setCursorPos(total_row,1);

    QString untill = (order[4]=="0")?(""):(order[5]+order[6]+"="+order[9]);
    QString usr = (order[14]=="0")?(""):(order[15]);
    QString tool = (order[16]=="0")?(""):(order[17]);
    //ui->plainTextEdit->appendPlainText("MOVJ VJ="+order[1]+" "+"PL="+order[2]+" "+untill+" "+"ACC="+order[9]+" "+"DEC="+order[10]+" "+"N_WAIT="+order[11]+" "+order[0]);
    ui->plainTextEdit->insertPlainText("MOVC VL="+order[1]+" "+"VR="+order[2]+" "+"PL="+order[3]+" "+untill+" "+"ACC="+order[10]+" "+"DEC="+order[11]+" "+"CR="+order[12]+"N_WAIT="+order[13]+" "+usr+" "+tool+" "+order[0]+"\n");
}

void MainWindow::speed_command_display(QString *order)
{
   // int current_row,
    int total_row;
   // current_row = ui->plainTextEdit->textCursor().blockNumber();
    total_row = ui->plainTextEdit->blockCount();
    --total_row;
    if(total_row>=1)
    ui->plainTextEdit->setCursorPos(total_row,1);
    ui->plainTextEdit->insertPlainText("SPEED "+order[0]+"="+order[1]+" ACC="+order[2]+"\n");
}

void MainWindow::dout_command_display(QString *order)
{
    int total_row;
    total_row = ui->plainTextEdit->blockCount();
    --total_row;
    if(total_row>=1)
    ui->plainTextEdit->setCursorPos(total_row,1);
    ui->plainTextEdit->insertPlainText("DOUT OUT"+order[0]+"="+order[1]+"\n");
}

void MainWindow::din_command_display(QString *order)
{
    int total_row;
    total_row = ui->plainTextEdit->blockCount();
    --total_row;
    if(total_row>=1)
    {
        ui->plainTextEdit->setCursorPos(total_row,1);
        ui->plainTextEdit->insertPlainText("DIN B"+order[0]+" IN"+order[1]+"\n");
    }
}

void MainWindow::pause_command_display(QString *order)
{
    int total_row;
    total_row = ui->plainTextEdit->blockCount();
    --total_row;
    if(total_row>=1)
    {
        ui->plainTextEdit->setCursorPos(total_row,1);
        if(order[0]=="1")
        {
            ui->plainTextEdit->insertPlainText("PAUSE IF "+order[1]+order[2]+order[3]+order[4]+"\n");
        }
        else
        {
            ui->plainTextEdit->insertPlainText("PAUSE\n");
        }
    }
}

void MainWindow::timer_command_display(QString order)
{
    int total_row;
    total_row = ui->plainTextEdit->blockCount();
    --total_row;
    if(total_row>=1)
    {
        ui->plainTextEdit->setCursorPos(total_row,1);
        ui->plainTextEdit->insertPlainText("TIMER T="+order+"\n");
    }
}

void MainWindow::jump_command_display(QString *order)
{
    int total_row;
    total_row = ui->plainTextEdit->blockCount();
    --total_row;
    qDebug()<<order[0]<<order[1]<<order[2]<<order[3]<<order[4]<<order[5];
    if(total_row>=1)
    {
        ui->plainTextEdit->setCursorPos(total_row,1);
        if(order[1]=="1")
        {
            ui->plainTextEdit->insertPlainText("JUMP IF"+order[2]+order[3]+order[4]+order[5]+" LABEL="+order[0]+"\n");
        }
        else
        {
            ui->plainTextEdit->insertPlainText("JUMP LABEL="+order[0]+"\n");
        }
    }
}

void MainWindow::label_command_display(QString order)
{
    int total_row;
    total_row = ui->plainTextEdit->blockCount();
    --total_row;
    if(total_row>=1)
    {
        ui->plainTextEdit->setCursorPos(total_row,1);
        ui->plainTextEdit->insertPlainText("LABEL "+order+"\n");
    }
}

void MainWindow::call_command_display(QString *order)
{
    int total_row;
    total_row = ui->plainTextEdit->blockCount();
    --total_row;
    if(total_row>=1)
    {
        ui->plainTextEdit->setCursorPos(total_row,1);
        if(order[1]=="1")
        {
            ui->plainTextEdit->insertPlainText("CALL FILE="+order[0]+"IF "+order[2]+order[3]+order[4]+order[5]+"\n");
        }
        else
        {
            ui->plainTextEdit->insertPlainText("CALL FILE="+order[0]+"\n");
        }
    }
}

void MainWindow::ret_command_display(QString *order)
{
    int total_row;
    total_row = ui->plainTextEdit->blockCount();
    --total_row;
    if(total_row>=1)
    {
        ui->plainTextEdit->setCursorPos(total_row,1);
        if(order[0]=="1")
        {
            ui->plainTextEdit->insertPlainText("RET IF "+order[1]+order[2]+order[3]+order[4]+"\n");
        }
        else
        {
            ui->plainTextEdit->insertPlainText("RET\n");
        }
    }
}

void MainWindow::on_pushButton_5_clicked()//程序编辑按键，，测试用
{
    ui->plainTextEdit->appendPlainText("MOVJ VJ \n");
}

void MainWindow::program_cursor_up()
{
    int current_row;//,total_row;
    current_row = ui->plainTextEdit->textCursor().blockNumber();
   // total_row = ui->plainTextEdit->blockCount();
    qDebug()<<ui->plainTextEdit->textCursor().blockNumber();
    qDebug()<<ui->plainTextEdit->blockCount();
    --current_row;
    if(current_row>=0)
    ui->plainTextEdit->setCursorPos(current_row,1);



    /*const QTextBlock block = ui->plainTextEdit->document()->findBlockByLineNumber(1);

    if(block.isValid())
    {



        QTextCursor cursor = ui->plainTextEdit->textCursor();
        cursor.setPosition(block.position()+1);

        ui->plainTextEdit->setFocus();
        ui->plainTextEdit->setTextCursor(cursor);
        ui->plainTextEdit->ensureCursorVisible();
    }*/
    /*QTextCursor cursor;
    cursor = ui->plainTextEdit->textCursor();
    cursor.setPosition(2);*/
    //QPlaintextedit光标位置由一个数决定，这个数就是文本中有多扫个字符，但是不知道其中一个行的
    //字符数单单一个数无法完成“上下键”换行移动光标。需要得到要移动行以上的字符数，然后加上移动到的列数就可以了。

}
void MainWindow::program_cursor_down()
{
    int current_row,total_row;
    current_row = ui->plainTextEdit->textCursor().blockNumber();
    total_row = ui->plainTextEdit->blockCount();
    qDebug()<<ui->plainTextEdit->textCursor().blockNumber();
    qDebug()<<ui->plainTextEdit->blockCount();
    ++current_row;
    if(current_row<=total_row)
    ui->plainTextEdit->setCursorPos(current_row,1);
}
//删除一行
void MainWindow::program_delete_line()
{
    int current_row,total_row,index;
    current_row = ui->plainTextEdit->textCursor().blockNumber();
    index = current_row;
    total_row = ui->plainTextEdit->blockCount();
    if(current_row==0)
        return;
    current_row++;
    if(current_row==total_row)
        return;
    //ui->plainTextEdit->deleteLater();
    QTextCursor tc = ui->plainTextEdit->textCursor();
    tc.select(QTextCursor::BlockUnderCursor);
    tc.removeSelectedText();

    xmlcancle1->delete_command(program_filename,index);

}
//插入一行命令
/*void MainWindow::program_insert_line()
{

    int current_row,total_row;
    current_row = ui->plainTextEdit->textCursor().blockNumber();
    total_row = ui->plainTextEdit->blockCount();
    ui->plainTextEdit->setCursorPos(current_row,1);
    commandinput1->input_insert_command(current_row);
    qDebug("start display");
    if(select_input_command=="MOVJ")
    {
        QString untill = (movjc1.buf[3]=="0")?(""):(movjc1.buf[4]+movjc1.buf[5]+movjc1.buf[6]+movjc1.buf[7]+movjc1.buf[8]);
        ui->plainTextEdit->insertPlainText("MOVJ VJ="+movjc1.buf[1]+" "+"PL="+movjc1.buf[2]+" "+untill+" "+"ACC="+movjc1.buf[9]+" "+"DEC="+movjc1.buf[10]+" "+"N_WAIT="+movjc1.buf[11]+" "+movjc1.buf[0]+"\n");
    }
    else if(select_input_command=="MOVL")
    {

        QString untill = (movlc1.buf[4]=="0")?(""):(movlc1.buf[5]+movlc1.buf[6]+movlc1.buf[7]+movlc1.buf[8]+movlc1.buf[9]);
        QString usr = (movlc1.buf[14]=="0")?(""):(movlc1.buf[15]);
        QString tool = (movlc1.buf[16]=="0")?(""):(movlc1.buf[17]);
        ui->plainTextEdit->insertPlainText("MOVL VL="+movlc1.buf[1]+" "+"VR="+movlc1.buf[2]+" "+"PL="+movlc1.buf[3]+" "+untill+" "+"ACC="+movlc1.buf[10]+" "+"DEC="+movlc1.buf[11]+" "+"CR="+movlc1.buf[12]+"N_WAIT="+movlc1.buf[13]+" "+usr+" "+tool+" "+movlc1.buf[0]+"\n");
    }
    else if(select_input_command=="MOVC")
    {


        QString untill = (movcc1.buf[4]=="0")?(""):(movcc1.buf[5]+movcc1.buf[6]+movcc1.buf[9]);
        QString usr = (movcc1.buf[14]=="0")?(""):(movcc1.buf[15]);
        QString tool = (movcc1.buf[16]=="0")?(""):(movcc1.buf[17]);
        //ui->plainTextEdit->appendPlainText("MOVJ VJ="+order[1]+" "+"PL="+order[2]+" "+untill+" "+"ACC="+order[9]+" "+"DEC="+order[10]+" "+"N_WAIT="+order[11]+" "+order[0]);
        ui->plainTextEdit->insertPlainText("MOVC VL="+movcc1.buf[1]+" "+"VR="+movcc1.buf[2]+" "+"PL="+movcc1.buf[3]+" "+untill+" "+"ACC="+movcc1.buf[10]+" "+"DEC="+movcc1.buf[11]+" "+"CR="+movcc1.buf[12]+"N_WAIT="+movcc1.buf[13]+" "+usr+" "+tool+" "+movcc1.buf[0]+"\n");
    }
    else if(select_input_command=="SPEED")
    {

        ui->plainTextEdit->insertPlainText("SPEED "+speedc1.buf[0]+"="+speedc1.buf[1]+" ACC="+speedc1.buf[2]+"\n");
        qDebug("display complete");
    }
}*/

void MainWindow::insert_slot(QString *order)
{
    int current_row;//,total_row;
    current_row = ui->plainTextEdit->textCursor().blockNumber();
    //total_row = ui->plainTextEdit->blockCount();

    if(current_row==0)
        return;
    ui->plainTextEdit->setCursorPos(current_row,1);
    if(select_input_command=="MOVJ")
    {
        QString untill = (order[3]=="0")?(""):(order[4]+order[5]+order[6]+order[7]+order[8]);
        ui->plainTextEdit->insertPlainText("MOVJ VJ="+order[1]+" "+"PL="+order[2]+" "+untill+" "+"ACC="+order[9]+" "+"DEC="+order[10]+" "+"N_WAIT="+order[11]+" "+order[0]+"\n");
        xmlcancle1->insert_MOVJ_command(movjc1,program_filename,current_row);
    }
    else if(select_input_command=="MOVL")
    {
        QString untill = (order[4]=="0")?(""):(order[5]+order[6]+order[7]+order[8]+order[9]);
        QString usr = (order[14]=="0")?(""):(order[15]);
        QString tool = (order[16]=="0")?(""):(order[17]);
        //ui->plainTextEdit->appendPlainText("MOVJ VJ="+order[1]+" "+"PL="+order[2]+" "+untill+" "+"ACC="+order[9]+" "+"DEC="+order[10]+" "+"N_WAIT="+order[11]+" "+order[0]);
        ui->plainTextEdit->insertPlainText("MOVL VL="+order[1]+" "+"VR="+order[2]+" "+"PL="+order[3]+" "+untill+" "+"ACC="+order[10]+" "+"DEC="+order[11]+" "+"CR="+order[12]+"N_WAIT="+order[13]+" "+usr+" "+tool+" "+order[0]+"\n");
        xmlcancle1->insert_MOVL_command(movlc1,program_filename,current_row);
    }
    else if(select_input_command=="MOVC")
    {
        QString untill = (order[4]=="0")?(""):(order[5]+order[6]+order[9]);
        QString usr = (order[14]=="0")?(""):(order[15]);
        QString tool = (order[16]=="0")?(""):(order[17]);
        //ui->plainTextEdit->appendPlainText("MOVJ VJ="+order[1]+" "+"PL="+order[2]+" "+untill+" "+"ACC="+order[9]+" "+"DEC="+order[10]+" "+"N_WAIT="+order[11]+" "+order[0]);
        ui->plainTextEdit->insertPlainText("MOVC VL="+order[1]+" "+"VR="+order[2]+" "+"PL="+order[3]+" "+untill+" "+"ACC="+order[10]+" "+"DEC="+order[11]+" "+"CR="+order[12]+"N_WAIT="+order[13]+" "+usr+" "+tool+" "+order[0]+"\n");
        xmlcancle1->insert_MOVC_command(movcc1,program_filename,current_row);
    }
    else if(select_input_command=="SPEED")
    {
        ui->plainTextEdit->insertPlainText("SPEED "+order[0]+"="+order[1]+" ACC="+order[2]+"\n");
        xmlcancle1->insert_speed_command(speedc1,program_filename,current_row);
    }
    else if(select_input_command=="DOUT")
    {
        ui->plainTextEdit->insertPlainText("DOUT OUT"+order[0]+"="+order[1]+"\n");
        xmlcancle1->insert_DOUT_command(doutc1,program_filename,current_row);
    }
    else if(select_input_command=="DIN")
    {
        ui->plainTextEdit->insertPlainText("DIN B"+order[0]+" IN"+order[1]+"\n");
        xmlcancle1->insert_DIN_command(dinc1,program_filename,current_row);
    }
    else if(select_input_command=="PAUSE")
    {
        if(order[0]=="1")
        {
            ui->plainTextEdit->insertPlainText("PAUSE IF "+order[1]+order[2]+order[3]+order[4]+"\n");
        }
        else
        {
            ui->plainTextEdit->insertPlainText("PAUSE\n");
        }
        xmlcancle1->insert_PAUSE_command(pausec1,program_filename,current_row);
    }
    else if(select_input_command=="TIMER")
    {
        ui->plainTextEdit->insertPlainText("TIMER T="+*order+"\n");
        xmlcancle1->insert_TIMER_command(timec1,program_filename,current_row);
    }
    else if(select_input_command=="JUMP")
    {
        if(order[1]=="1")
        {
            ui->plainTextEdit->insertPlainText("CALL FILE="+order[0]+"IF "+order[2]+order[3]+order[4]+order[5]+"\n");
        }
        else
        {
            ui->plainTextEdit->insertPlainText("CALL FILE="+order[0]+"\n");
        }
        xmlcancle1->insert_JUMP_command(jumpc1,program_filename,current_row);
    }
    else if(select_input_command=="LABEL")
    {
        ui->plainTextEdit->insertPlainText("LABEL "+*order+"\n");
        xmlcancle1->insert_LABEL_command(LabelCommand1,program_filename,current_row);
    }
    else if(select_input_command=="CALL")
    {
        if(order[1]=="1")
        {
            ui->plainTextEdit->insertPlainText("CALL FILE="+order[0]+"IF "+order[2]+order[3]+order[4]+order[5]+"\n");
        }
        else
        {
            ui->plainTextEdit->insertPlainText("CALL FILE="+order[0]+"\n");
        }
        xmlcancle1->insert_CALL_command(callc1,program_filename,current_row);
    }
    else if(select_input_command=="RET")
    {
        if(order[0]=="1")
        {
            ui->plainTextEdit->insertPlainText("RET IF "+order[1]+order[2]+order[3]+order[4]+"\n");
        }
        else
        {
            ui->plainTextEdit->insertPlainText("RET\n");
        }
        xmlcancle1->insert_RET_command(retc1,program_filename,current_row);
    }
}

void MainWindow::require_modify_data()
{
    //在修改的过程中光标不能移动
    int current_row,total_row;
    current_row = ui->plainTextEdit->textCursor().blockNumber();
    total_row = ui->plainTextEdit->blockCount();
    qDebug()<<current_row;
    if(current_row==0||(total_row-1)==current_row)
        return;
    xmlcancle1->get_command_style(program_filename,current_row);
    qDebug()<<select_input_command;
    if(select_input_command=="movj")
    {
        xmlcancle1->get_MOVJ(movjc1,program_filename,current_row);
        xmlcancle1->require_position_data(movjc2.buf[0]);
        JointMoveInformation jm;
        jm.acc = 1.0;
        jm.dec = 1.0;
        jm.vJ = 0.1;                   //toDouble
        jm.endPoint.j1 = positiondata1.buf[1].toDouble();
        jm.endPoint.j2 = positiondata1.buf[2].toDouble();
        jm.endPoint.j3 = positiondata1.buf[3].toDouble();
        jm.endPoint.j4 = positiondata1.buf[4].toDouble();
        jm.endPoint.j5 = positiondata1.buf[5].toDouble();
        jm.endPoint.j6 = positiondata1.buf[6].toDouble();

        CTRL_AddJointMove(&jm,0,0);
        /*for(int i=0;i<12;i++)
        {
            qDebug()<<movjc1.buf[i];
        }*/
    }
    else if(select_input_command=="movl")
    {   qDebug("select movl");
        xmlcancle1->get_MOVL(movlc1,program_filename,current_row);

    }
    else if(select_input_command=="movc")
    {
        qDebug("select movc");
        xmlcancle1->get_MOVC(movcc1,program_filename,current_row);
    }
    else if(select_input_command=="speed")
    {
        qDebug("select speed");
        xmlcancle1->get_speed(speedc1,program_filename,current_row);
    }
    else if(select_input_command=="dout")
    {
        xmlcancle1->get_DOUT(doutc1,program_filename,current_row);
    }
    else if(select_input_command=="din")
    {
        //xmlcancle1->get_DIN(dinc1,program_filename,current_row);
        xmlcancle1->get_DIN(dinc1,program_filename,current_row);
    }
    else if(select_input_command=="pause")
    {
        xmlcancle1->get_PAUSE_command(pausec1,program_filename,current_row);
    }
    else if(select_input_command=="label")
    {
        xmlcancle1->get_LABEL_command(LabelCommand1,program_filename,current_row);
    }
    else if(select_input_command=="call")
    {
        xmlcancle1->get_CALL_command(callc1,program_filename,current_row);
    }
    else if(select_input_command=="timer")
    {
        xmlcancle1->get_TIMER_command(timec1,program_filename,current_row);
    }
    else if(select_input_command=="jump")
    {
        xmlcancle1->get_JUMP_command(jumpc1,program_filename,current_row);
    }
    else if(select_input_command=="ret")
    {
        xmlcancle1->get_RET_command(retc1,program_filename,current_row);
    }
    else
    {
        qDebug("requre data failure");
        return;
    }
    qDebug()<<"read data complete";
}

//程序选择，输入程序名，点击确定按钮打开已有程序文件
void MainWindow::on_pushButton_seprog_ensure_clicked()
{
    program_filename= ui->lineEdit_seprog_name->text();

//    if(run_file!=NULL)
//    {
//        free(run_file);
//        run_file=NULL;
//    }

    //run_file = new RunFile(program_filename);
    //run_file->init();


    if(program_filename.isEmpty())
    {
        QMessageBox::warning(NULL,"WARNING","FILENAME SHI SPACE!");
        return;
    }

    //读取对应的文件，将里面的数据显示到程序编辑界面中
    xmlcancle1->read_xml_file(ui->plainTextEdit,program_filename);
    ui->plainTextEdit->setCursorPos(1,1);

    ui->stackedWidget->setCurrentIndex(0);
    ui->prog_name_label->setText(program_filename);
}

//send current line

void MainWindow::send_current_line_slot()
{
    int current_row,total_row;
    //static bool movc_send_victory_flag = true;
    current_row = ui->plainTextEdit->textCursor().blockNumber();
    total_row = ui->plainTextEdit->blockCount();
    qDebug()<<current_row;
    if(current_row==0||(total_row-1)==current_row)
        return;

    qDebug()<< "opening the file" << program_filename;
    run_file = new RunFile(program_filename);
    qDebug()<< "executing the file" << program_filename;
    //run_file->init();
    run_file->exeLine(current_row);

    free(run_file);
    run_file = NULL;


}

/*void MainWindow::send_current_line_slot()
{
    int current_row,total_row;
    //static bool movc_send_victory_flag = true;
    current_row = ui->plainTextEdit->textCursor().blockNumber();
    total_row = ui->plainTextEdit->blockCount();
    qDebug()<<current_row;
    if(current_row==0||(total_row-1)==current_row)
        return;
    xmlcancle1->get_command_style(program_filename,current_row);
    qDebug()<<select_input_command;
    if(select_input_command=="movj")
    {
        xmlcancle1->get_MOVJ(movjc1,program_filename,current_row);

        xmlcancle1->require_position_data(movjc2.buf[0]);

        JointMoveInformation jm;
        jm.acc = 1.0;
        jm.dec = 1.0;
        jm.vJ = 0.1;                   //toDouble
        jm.endPoint.j1 = positiondata2.buf[1].toDouble();
        jm.endPoint.j2 = positiondata2.buf[2].toDouble();
        jm.endPoint.j3 = positiondata2.buf[3].toDouble();
        jm.endPoint.j4 = positiondata2.buf[4].toDouble();
        jm.endPoint.j5 = positiondata2.buf[5].toDouble();
        jm.endPoint.j6 = positiondata2.buf[6].toDouble();

        CTRL_AddJointMove(&jm,0,0);




    }
    else if(select_input_command=="movl")
    {   qDebug("select movl");
        xmlcancle1->get_MOVL(movlc1,program_filename,current_row);
        xmlcancle1->require_position_data(movlc2.buf[0]);
        if(positiondata2.buf[0] == "Join")
        {
            lm.endPoint.j1 = positiondata2.buf[1].toDouble();
            lm.endPoint.j2 = positiondata2.buf[2].toDouble();
            lm.endPoint.j3 = positiondata2.buf[3].toDouble();
            lm.endPoint.j4 = positiondata2.buf[4].toDouble();
            lm.endPoint.j5 = positiondata2.buf[5].toDouble();
            lm.endPoint.j6 = positiondata2.buf[6].toDouble();

            lm.vL = movlc2.buf[1].toDouble();
            lm.vR = movlc2.buf[2].toDouble();
            CTRL_AddLinearMove(&lm,current_row,0);



        }
        else if(positiondata2.buf[0]== "World")
        {
            mdl.endPoint.x=positiondata2.buf[1].toDouble();
            mdl.endPoint.y=positiondata2.buf[2].toDouble();
            mdl.endPoint.z=positiondata2.buf[3].toDouble();

            mdl.vL = movlc2.buf[1].toDouble();
            mdl.vR = movlc2.buf[2].toDouble();
            CTRL_AddDescartesLinearMove(&mdl,current_row,0);
        }
        else
        {

        }

    }
    else if(select_input_command=="movc")
    {

        qDebug("select movc");

        xmlcancle1->get_MOVC(movcc1,program_filename,current_row);
        xmlcancle1->require_position_data(movcc2.buf[0]);
        if(positiondata2.buf[0] == "Join")                                       //1
        {
            xmlcancle1->get_command_style(program_filename,current_row+1);
            if(select_input_command=="movc")
            {
                xmlcancle1->get_MOVC(movcc1,program_filename,current_row+1);
                xmlcancle1->require_position_data(movcc2.buf[0]);
                if(positiondata2.buf[0] == "Join")                               //2
                {
                    xmlcancle1->get_command_style(program_filename,current_row+2);
                    if(select_input_command=="movc")
                    {
                        xmlcancle1->get_MOVC(movcc1,program_filename,current_row+2);
                        xmlcancle1->require_position_data(movcc2.buf[0]);
                        if(positiondata2.buf[0] == "Join")                               //3
                        {
                            for(int i=0;i<3;i++)
                            {
                                xmlcancle1->get_MOVC(movcc1,program_filename,current_row+i);
                                xmlcancle1->require_position_data(movcc2.buf[0]);
                                cm.endPoint[i].j1=positiondata2.buf[1].toDouble();
                                cm.endPoint[i].j2=positiondata2.buf[2].toDouble();
                                cm.endPoint[i].j3=positiondata2.buf[3].toDouble();
                                cm.endPoint[i].j4=positiondata2.buf[4].toDouble();
                                cm.endPoint[i].j5=positiondata2.buf[5].toDouble();
                                cm.endPoint[i].j6=positiondata2.buf[6].toDouble();
                                qDebug()<<cm.endPoint[i].j1
                                          <<cm.endPoint[i].j2
                                         <<cm.endPoint[i].j3
                                         <<cm.endPoint[i].j4
                                           <<cm.endPoint[i].j5
                                             <<cm.endPoint[i].j6;

                            }
                            CTRL_AddCircularMove(&cm,current_row+2,0);

                        }
                        else
                        {
                            qDebug()<<"joint3 error!";
                        }
                    }
                    else
                    {
                        qDebug()<<"movc3 error!";
                    }

                }
                else
                {
                    qDebug()<<"joint2 error!";
                }
            }
            else
            {
                qDebug()<<"movc2 error!";
            }
        }
        else if(positiondata2.buf[0] == "World")
        {
            xmlcancle1->get_command_style(program_filename,current_row+1);
            if(select_input_command=="movc")
            {
                xmlcancle1->get_MOVC(movcc1,program_filename,current_row+1);
                xmlcancle1->require_position_data(movcc2.buf[0]);
                if(positiondata2.buf[0] == "World")                               //2
                {
                    xmlcancle1->get_command_style(program_filename,current_row+2);
                    if(select_input_command=="movc")
                    {
                        xmlcancle1->get_MOVC(movcc1,program_filename,current_row+2);
                        xmlcancle1->require_position_data(movcc2.buf[0]);
                        if(positiondata2.buf[0] == "World")                               //3
                        {
                            for(int i=0;i<3;i++)
                            {
                                xmlcancle1->get_MOVC(movcc1,program_filename,current_row+i);
                                xmlcancle1->require_position_data(movcc2.buf[0]);
                                cdm.endPoint[i].x = movcc2.buf[1].toDouble();
                                cdm.endPoint[i].y = movcc2.buf[2].toDouble();
                                cdm.endPoint[i].z = movcc2.buf[3].toDouble();

                                cdm.zyx[i].a = movcc2.buf[4].toDouble();
                                cdm.zyx[i].b = movcc2.buf[5].toDouble();
                                cdm.zyx[i].c = movcc2.buf[6].toDouble();

                            }
                            CTRL_AddDescartesCircularMove(&cdm,current_row+2,0);

                        }
                        else
                        {
                            qDebug()<<"World3 error!";
                        }
                    }
                    else
                    {
                        qDebug()<<"movc3 error!";
                    }

                }
                else
                {
                    qDebug()<<"World3 error!";
                }
            }
            else
            {
                qDebug()<<"movc2 error!";
            }
        }
        else
        {
            qDebug()<<"World3 error!";
        }
    }
    else if(select_input_command=="speed")
    {
        qDebug("select speed");
        xmlcancle1->get_speed(speedc1,program_filename,current_row);
    }
    else
    {
        qDebug("requre data failure");
        return;
    }
    qDebug()<<"read data complete";

}*/

void MainWindow::single_step_backward_slot()
{
    int current_row,total_row;
    //static bool movc_send_victory_flag = true;
    current_row = ui->plainTextEdit->textCursor().blockNumber();
    total_row = ui->plainTextEdit->blockCount();
    qDebug()<<current_row;
    if(current_row==0||(total_row-1)==current_row)
        return;

    run_file = new RunFile(program_filename);
    run_file->init();
    run_file->exeInverseLine(current_row);

    free(run_file);
    run_file = NULL;
}

void MainWindow::multip_send_line_slot()
{
    int current_row,total_row;
    //static bool movc_send_victory_flag = true;
    current_row = ui->plainTextEdit->textCursor().blockNumber();
    total_row = ui->plainTextEdit->blockCount();
    //qDebug()<<current_row;
    if(current_row==0||(total_row-1)==current_row)
        return;

    run_file = new RunFile(program_filename);
    connect(run_file,SIGNAL(FileNameChanged1(QString)),this,SLOT(display_changed_file(QString)));
    connect(run_file,SIGNAL(FileClosed1()),this,SLOT(file_run_end()));
    qDebug()<<"create link";
    run_file->init(current_row,0);
    run_file->start();
    mainwindow_timer1->start();


    //delete run_file;
    //run_file = NULL;
}

void MainWindow::multip_release_send_line_slot()
{
    //run_file = new RunFile(program_filename);
    run_file->stop();
    run_file->wait();
    CTRL_MovementStop();
    mainwindow_timer1->stop();
    delete run_file;
    run_file = NULL;
}

void MainWindow::multin_send_line_slot()
{
    int current_row,total_row;
    //static bool movc_send_victory_flag = true;
    current_row = ui->plainTextEdit->textCursor().blockNumber();
    total_row = ui->plainTextEdit->blockCount();
    qDebug()<<current_row;
    if(current_row==0||(total_row-1)==current_row)
        return;

    run_file = new RunFile(program_filename);
    run_file->init(current_row,1);
    run_file->start();
    mainwindow_timer1->start();


}

void MainWindow::multin_release_send_line_slot()
{
    run_file->stop();
    run_file->wait();
    CTRL_MovementStop();
    mainwindow_timer1->stop();
    delete run_file;
    run_file = NULL;
}

void MainWindow::test_run_slot()
{
    int current_row,total_row;
    bool communication;
    //static bool movc_send_victory_flag = true;
    current_row = ui->plainTextEdit->textCursor().blockNumber();
    total_row = ui->plainTextEdit->blockCount();
    qDebug()<<current_row;
    if(current_row==0||(total_row-1)==current_row)
        return;
    run_file = new RunFile(program_filename);



    communication = connect(run_file,SIGNAL(FileNameChanged1(QString)),this,SLOT(display_changed_file(QString)));

    qDebug()<<"commmunication Success!!!!!!!!!!!!!!!!!!!!!";
    qDebug()<<communication;

    connect(run_file,SIGNAL(FileClosed1()),this,SLOT(file_run_end()));
    run_file->init();
    run_file->start();
    mainwindow_timer1->start();
//        connect(run_file,SIGNAL(FileNameChanged1(QString)),this,SLOT(display_changed_file(QString)));
//        connect(run_file,SIGNAL(FileClosed1()),this,SLOT(file_run_end()));

}

void MainWindow::restart_run_slot()
{
    if(run_file!=NULL)
    {
        run_file->setPause();
    }
}

void MainWindow::when_run_pause_slot()
{
    run_file->interpPause();
}

/*void MainWindow::multip_send_line_slot()
{
    int current_row,total_row;
    current_row = ui->plainTextEdit->textCursor().blockNumber();
    total_row = ui->plainTextEdit->blockCount();
    qDebug()<<current_row;
    //mainwindow_timer1->start();
    if(current_row==0||(total_row-1)==current_row)
        return;
    for(int i=current_row;i<total_row-1;i++)
    {
        qDebug()<<"gggggggggggggggggggggg"<<i;
    xmlcancle1->get_command_style(program_filename,i);

    if(select_input_command=="movj")
    {
        xmlcancle1->get_MOVJ(movjc1,program_filename,i);

        xmlcancle1->require_position_data(movjc2.buf[0]);

        JointMoveInformation jm;
        jm.acc = 1.0;
        jm.dec = 1.0;
        jm.vJ = 0.1;                   //toDouble
        jm.endPoint.j1 = positiondata2.buf[1].toDouble();
        jm.endPoint.j2 = positiondata2.buf[2].toDouble();
        jm.endPoint.j3 = positiondata2.buf[3].toDouble();
        jm.endPoint.j4 = positiondata2.buf[4].toDouble();
        jm.endPoint.j5 = positiondata2.buf[5].toDouble();
        jm.endPoint.j6 = positiondata2.buf[6].toDouble();

        CTRL_AddJointMove(&jm,i,0);
        qDebug()<<"iiiiiiiiiiii="<<i;

    }
    else if(select_input_command=="movl")
    {   qDebug("select movl");
        xmlcancle1->get_MOVL(movlc1,program_filename,i);
        xmlcancle1->require_position_data(movlc2.buf[0]);
        if(positiondata2.buf[0] == "Join")
        {
            lm.endPoint.j1 = positiondata2.buf[1].toDouble();
            lm.endPoint.j2 = positiondata2.buf[2].toDouble();
            lm.endPoint.j3 = positiondata2.buf[3].toDouble();
            lm.endPoint.j4 = positiondata2.buf[4].toDouble();
            lm.endPoint.j5 = positiondata2.buf[5].toDouble();
            lm.endPoint.j6 = positiondata2.buf[6].toDouble();

            lm.vL = movlc2.buf[1].toDouble();
            lm.vR = movlc2.buf[2].toDouble();
            CTRL_AddLinearMove(&lm,i,0);
        }
        else if(positiondata2.buf[0]== "World")
        {
            mdl.endPoint.x=positiondata2.buf[1].toDouble();
            mdl.endPoint.y=positiondata2.buf[2].toDouble();
            mdl.endPoint.z=positiondata2.buf[3].toDouble();

            mdl.vL = movlc2.buf[1].toDouble();
            mdl.vR = movlc2.buf[2].toDouble();
            CTRL_AddDescartesLinearMove(&mdl,i,0);
        }
        else
        {

        }

    }
    else if(select_input_command=="movc")
    {
        qDebug("select movc");
        xmlcancle1->get_MOVC(movcc1,program_filename,i);
        xmlcancle1->require_position_data(movcc2.buf[0]);
        if(positiondata2.buf[0] == "Join")                                       //1
        {
            xmlcancle1->get_command_style(program_filename,i+1);
            if(select_input_command=="movc")
            {
                xmlcancle1->get_MOVC(movcc1,program_filename,i+1);
                xmlcancle1->require_position_data(movcc2.buf[0]);
                if(positiondata2.buf[0] == "Join")                               //2
                {
                    xmlcancle1->get_command_style(program_filename,i+2);
                    if(select_input_command=="movc")
                    {
                        xmlcancle1->get_MOVC(movcc1,program_filename,i+2);
                        xmlcancle1->require_position_data(movcc2.buf[0]);
                        if(positiondata2.buf[0] == "Join")                               //3
                        {
                            for(int a=0;a<3;a++)
                            {
                                xmlcancle1->get_MOVC(movcc1,program_filename,i+a);
                                xmlcancle1->require_position_data(movcc2.buf[0]);
                                cm.endPoint[a].j1=positiondata2.buf[1].toDouble();
                                cm.endPoint[a].j2=positiondata2.buf[2].toDouble();
                                cm.endPoint[a].j3=positiondata2.buf[3].toDouble();
                                cm.endPoint[a].j4=positiondata2.buf[4].toDouble();
                                cm.endPoint[a].j5=positiondata2.buf[5].toDouble();
                                cm.endPoint[a].j6=positiondata2.buf[6].toDouble();
                                qDebug()<<cm.endPoint[a].j1
                                          <<cm.endPoint[a].j2
                                         <<cm.endPoint[a].j3
                                         <<cm.endPoint[a].j4
                                           <<cm.endPoint[a].j5
                                             <<cm.endPoint[a].j6;

                            }
                            CTRL_AddCircularMove(&cm,i,0);
                            i+=2;


                        }
                        else
                        {
                            qDebug()<<"joint3 error!";
                        }
                    }
                    else
                    {
                        qDebug()<<"movc3 error!";
                    }

                }
                else
                {
                    qDebug()<<"joint2 error!";
                }
            }
            else
            {
                qDebug()<<"movc2 error!";
            }
        }
        else if(positiondata2.buf[0] == "World")
        {
            xmlcancle1->get_command_style(program_filename,i+1);
            if(select_input_command=="movc")
            {
                xmlcancle1->get_MOVC(movcc1,program_filename,i+1);
                xmlcancle1->require_position_data(movcc2.buf[0]);
                if(positiondata2.buf[0] == "World")                               //2
                {
                    xmlcancle1->get_command_style(program_filename,i+2);
                    if(select_input_command=="movc")
                    {
                        xmlcancle1->get_MOVC(movcc1,program_filename,i+2);
                        xmlcancle1->require_position_data(movcc2.buf[0]);
                        if(positiondata2.buf[0] == "World")                               //3
                        {
                            for(int b=0;b<3;b++)
                            {
                                xmlcancle1->get_MOVC(movcc1,program_filename,i+b);
                                xmlcancle1->require_position_data(movcc2.buf[0]);
                                cdm.endPoint[b].x = movcc2.buf[1].toDouble();
                                cdm.endPoint[b].y = movcc2.buf[2].toDouble();
                                cdm.endPoint[b].z = movcc2.buf[3].toDouble();

                                cdm.zyx[b].a = movcc2.buf[4].toDouble();
                                cdm.zyx[b].b = movcc2.buf[5].toDouble();
                                cdm.zyx[b].c = movcc2.buf[6].toDouble();

                            }
                            CTRL_AddDescartesCircularMove(&cdm,i,0);
                            i+=2;

                        }
                        else
                        {
                            qDebug()<<"World3 error!";
                        }
                    }
                    else
                    {
                        qDebug()<<"movc3 error!";
                    }

                }
                else
                {
                    qDebug()<<"World3 error!";
                }
            }
            else
            {
                qDebug()<<"movc2 error!";
            }
        }
        else
        {
            qDebug()<<"World3 error!";
        }

    }
    else if(select_input_command=="speed")
    {
        qDebug("select speed");
        xmlcancle1->get_speed(speedc1,program_filename,current_row);
    }
    else
    {
        qDebug("requre data failure");
        return;
    }
   }
    mainwindow_timer1->start();
    //mainwindow_timer1->stop();
    qDebug()<<"read data complete";
}

void MainWindow::multin_send_line_slot()
{
    int current_row,total_row;
    current_row = ui->plainTextEdit->textCursor().blockNumber();
    total_row = ui->plainTextEdit->blockCount();
    qDebug()<<current_row;
    //mainwindow_timer1->start();
    if(current_row==0||(total_row-1)==current_row)
        return;
    for(int i=current_row;i>0;i--)
    {
        qDebug("gggggggggggggggggggggg");
        qDebug()<<"i="<<i;
    xmlcancle1->get_command_style(program_filename,i);

    if(select_input_command=="movj")
    {
        xmlcancle1->get_MOVJ(movjc1,program_filename,i);

        xmlcancle1->require_position_data(movjc2.buf[0]);

        JointMoveInformation jm;
        jm.acc = 1.0;
        jm.dec = 1.0;
        jm.vJ = 0.1;                   //toDouble
        jm.endPoint.j1 = positiondata2.buf[1].toDouble();
        jm.endPoint.j2 = positiondata2.buf[2].toDouble();
        jm.endPoint.j3 = positiondata2.buf[3].toDouble();
        jm.endPoint.j4 = positiondata2.buf[4].toDouble();
        jm.endPoint.j5 = positiondata2.buf[5].toDouble();
        jm.endPoint.j6 = positiondata2.buf[6].toDouble();

        CTRL_AddJointMove(&jm,i,0);
        qDebug()<<"iiiiiiiiiiii="<<i;




    }
    else if(select_input_command=="movl")
    {   qDebug("select movl");
        xmlcancle1->get_MOVL(movlc1,program_filename,i);
        xmlcancle1->require_position_data(movlc2.buf[0]);
        if(positiondata2.buf[0] == "Join")
        {
            lm.endPoint.j1 = positiondata2.buf[1].toDouble();
            lm.endPoint.j2 = positiondata2.buf[2].toDouble();
            lm.endPoint.j3 = positiondata2.buf[3].toDouble();
            lm.endPoint.j4 = positiondata2.buf[4].toDouble();
            lm.endPoint.j5 = positiondata2.buf[5].toDouble();
            lm.endPoint.j6 = positiondata2.buf[6].toDouble();

            lm.vL = movlc2.buf[1].toDouble();
            lm.vR = movlc2.buf[2].toDouble();
            CTRL_AddLinearMove(&lm,i,0);
        }
        else if(positiondata2.buf[0]== "World")
        {
            mdl.endPoint.x=positiondata2.buf[1].toDouble();
            mdl.endPoint.y=positiondata2.buf[2].toDouble();
            mdl.endPoint.z=positiondata2.buf[3].toDouble();

            mdl.vL = movlc2.buf[1].toDouble();
            mdl.vR = movlc2.buf[2].toDouble();
            CTRL_AddDescartesLinearMove(&mdl,i,0);
        }
        else
        {

        }


    }
    else if(select_input_command=="movc")
    {
        qDebug("select movc");
        xmlcancle1->get_MOVC(movcc1,program_filename,i);
        xmlcancle1->require_position_data(movcc2.buf[0]);
        if(positiondata2.buf[0] == "Join")                                       //1
        {
            xmlcancle1->get_command_style(program_filename,i-1);
            if(select_input_command=="movc")
            {
                xmlcancle1->get_MOVC(movcc1,program_filename,i-1);
                xmlcancle1->require_position_data(movcc2.buf[0]);
                if(positiondata2.buf[0] == "Join")                               //2
                {
                    xmlcancle1->get_command_style(program_filename,i-2);
                    if(select_input_command=="movc")
                    {
                        xmlcancle1->get_MOVC(movcc1,program_filename,i-2);
                        xmlcancle1->require_position_data(movcc2.buf[0]);
                        if(positiondata2.buf[0] == "Join")                               //3
                        {
                            for(int a=0;a<3;a++)
                            {
                                xmlcancle1->get_MOVC(movcc1,program_filename,i-a);
                                xmlcancle1->require_position_data(movcc2.buf[0]);
                                cm.endPoint[a].j1=positiondata2.buf[1].toDouble();
                                cm.endPoint[a].j2=positiondata2.buf[2].toDouble();
                                cm.endPoint[a].j3=positiondata2.buf[3].toDouble();
                                cm.endPoint[a].j4=positiondata2.buf[4].toDouble();
                                cm.endPoint[a].j5=positiondata2.buf[5].toDouble();
                                cm.endPoint[a].j6=positiondata2.buf[6].toDouble();
                                qDebug()<<cm.endPoint[a].j1
                                          <<cm.endPoint[a].j2
                                         <<cm.endPoint[a].j3
                                         <<cm.endPoint[a].j4
                                           <<cm.endPoint[a].j5
                                             <<cm.endPoint[a].j6;

                            }
                            CTRL_AddCircularMove(&cm,i,0);
                            i-=2;



                        }
                        else
                        {
                            qDebug()<<"joint3 error!";
                        }
                    }
                    else
                    {
                        qDebug()<<"movc3 error!";
                    }

                }
                else
                {
                    qDebug()<<"joint2 error!";
                }
            }
            else
            {
                qDebug()<<"movc2 error!";
            }
        }
        else if(positiondata2.buf[0] == "World")
        {
            xmlcancle1->get_command_style(program_filename,i-1);
            if(select_input_command=="movc")
            {
                xmlcancle1->get_MOVC(movcc1,program_filename,i-1);
                xmlcancle1->require_position_data(movcc2.buf[0]);
                if(positiondata2.buf[0] == "World")                               //2
                {
                    xmlcancle1->get_command_style(program_filename,i-2);
                    if(select_input_command=="movc")
                    {
                        xmlcancle1->get_MOVC(movcc1,program_filename,i-2);
                        xmlcancle1->require_position_data(movcc2.buf[0]);
                        if(positiondata2.buf[0] == "World")                               //3
                        {
                            for(int b=0;b<3;b++)
                            {
                                xmlcancle1->get_MOVC(movcc1,program_filename,i-b);
                                xmlcancle1->require_position_data(movcc2.buf[0]);
                                cdm.endPoint[b].x = movcc2.buf[1].toDouble();
                                cdm.endPoint[b].y = movcc2.buf[2].toDouble();
                                cdm.endPoint[b].z = movcc2.buf[3].toDouble();

                                cdm.zyx[b].a = movcc2.buf[4].toDouble();
                                cdm.zyx[b].b = movcc2.buf[5].toDouble();
                                cdm.zyx[b].c = movcc2.buf[6].toDouble();

                            }
                            CTRL_AddDescartesCircularMove(&cdm,i,0);
                            i-=2;

                        }
                        else
                        {
                            qDebug()<<"World3 error!";
                        }
                    }
                    else
                    {
                        qDebug()<<"movc3 error!";
                    }

                }
                else
                {
                    qDebug()<<"World3 error!";
                }
            }
            else
            {
                qDebug()<<"movc2 error!";
            }
        }
        else
        {
            qDebug()<<"World3 error!";
        }
    }
    else if(select_input_command=="speed")
    {
        qDebug("select speed");
        xmlcancle1->get_speed(speedc1,program_filename,i);
    }
    else
    {
        qDebug("requre data failure");
        return;
    }
   }
    mainwindow_timer1->start();
    //mainwindow_timer1->stop();
    qDebug()<<"read data complete";
}

void MainWindow::test_run_slot()
{

    ui->plainTextEdit->setCursorPos(1,1);
    multip_send_line_slot();
}*/

















//new subfile

void MainWindow::on_new_sub_prog_pushButton_clicked()
{
    program_filename= ui->target_prog_lineEdit->text();
    if(program_filename.isEmpty())
    {
        QMessageBox::warning(NULL,"WARNING","FILENAME SHI SPACE!");
        return;
    }
    //qDebug("hello");

    //创建对应文件名的程序和对应程序位置的xml文件
    //QString tring = "tring";
    xmlcancle1->create_xml_subfile(program_filename);
    xmlcancle1->create_xml_position_file(program_filename);

    //读取对应的文件，将里面的数据显示到程序编辑界面中
    xmlcancle1->read_xml_file(ui->plainTextEdit,program_filename);

    ui->stackedWidget->setCurrentIndex(0);
    ui->prog_name_label->setText(program_filename);
}

//
void MainWindow::display_changed_file(QString program_filename)
{
    xmlcancle1->read_xml_file(ui->plainTextEdit,program_filename);

    ui->stackedWidget->setCurrentIndex(0);
    ui->prog_name_label->setText(program_filename);
    qDebug()<<"change display";
    qDebug()<<"change display";
    qDebug()<<"change display";
    qDebug()<<"change display";
    qDebug()<<"change display";
    qDebug()<<"change display";

}

void MainWindow::file_run_end()
{

}

void MainWindow::refresh_reload_program_slot(QString filename)
{
    xmlcancle1->read_xml_file(ui->plainTextEdit,filename);
    ui->plainTextEdit->setCursorPos(1,1);

    ui->stackedWidget->setCurrentIndex(0);
    ui->prog_name_label->setText(filename);
}

void MainWindow::start_line_slot()
{
    if(program_filename=="NULL")
    {
        QMessageBox message(QMessageBox::Warning,"Information","program havent open!",
                            QMessageBox::Yes,NULL);
        if(message.exec()==QMessageBox::Yes)
        {
            return;
        }
    }
    xmlcopycut->ensure_head_line(program_filename,ui->plainTextEdit->textCursor().blockNumber());
}

void MainWindow::end_line_slot()
{
    if(program_filename=="NULL")
    {
        QMessageBox message(QMessageBox::Warning,"Information","program havent open!",
                            QMessageBox::Yes,NULL);
        if(message.exec()==QMessageBox::Yes)
        {
            return;
        }
    }
    xmlcopycut->ensure_end_line(program_filename,ui->plainTextEdit->textCursor().blockNumber());
}

void MainWindow::copy_slot()
{
    xmlcopycut->program_copy();
}

void MainWindow::cut_slot()
{
    xmlcopycut->program_cut();
}

void MainWindow::paste_slot()
{
    xmlcopycut->program_paste(ui->plainTextEdit->textCursor().blockNumber());
}

void MainWindow::reload_select_file(QString filename)
{
    qDebug()<<"inter program display";
    program_filename=filename;
    xmlcancle1->read_xml_file(ui->plainTextEdit,filename);
    ui->plainTextEdit->setCursorPos(1,1);

    ui->stackedWidget->setCurrentIndex(0);
    ui->prog_name_label->setText(filename);
}

void MainWindow::ensure_select_file(QString filename)
{
    ui->stackedWidget->setCurrentIndex(22);
    ui->source_prog_lineEdit->setText(filename);
    progfilenote->read_comments(filename);
    ui->annotation_textEdit->clear();
    qDebug()<<progfilenote->comments;
    ui->annotation_textEdit->append(progfilenote->comments);

}

void MainWindow::file_manage_delete()
{
    QString str = ui->source_prog_lineEdit->text();
    bool ok = QFile::remove(str+".xml");
    if(ok)
    {
        QMessageBox::information(NULL,"Title","remove success",QMessageBox::Yes);
    }
    else
    {
        QMessageBox::information(NULL,"Title","filename not",QMessageBox::Yes);
    }
}

void MainWindow::file_manage_copy()
{
    QString str1 = ui->source_prog_lineEdit->text();
    QString str2 = ui->target_prog_lineEdit->text();
    bool exist = QFile::exists(str1+".xml");
    if(!exist)
    {
        QMessageBox::information(NULL,"Title","file not exist",QMessageBox::Yes);
        return;
    }
    bool ok = QFile::copy(str1+".xml",str2+".xml");
    if(ok)
    {
        QMessageBox::information(NULL,"Title","copy success",QMessageBox::Yes);
    }
    else
    {
        QMessageBox::information(NULL,"Title","copy failed",QMessageBox::Yes);
    }
}

void MainWindow::file_manage_rename()
{
    QString str1 = ui->source_prog_lineEdit->text();
    QString str2 = ui->target_prog_lineEdit->text();
    bool exist = QFile::exists(str1+".xml");
    if(!exist)
    {
        QMessageBox::information(NULL,"Title","file not exist",QMessageBox::Yes);
        return;
    }
    //bool ok = QFile::remove(str1+".xml",str2+".xml");
    bool ok = QFile::rename(str1+".xml",str2+".xml");
    if(ok)
    {
        QMessageBox::information(NULL,"Title","rename success",QMessageBox::Yes);
    }
    else
    {
        QMessageBox::information(NULL,"Title","rename failed",QMessageBox::Yes);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_A && !e->isAutoRepeat())
    {
        SingleAxisMove single;
        single.axis = 2;
        single.direction = MOVE_DIR_NEGATIVE;
        single.vel = 0.1;
        single.endPoint = -180.0;
        single.coordinate.coordinateType = COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(e->key() == Qt::Key_B && !e->isAutoRepeat())
    {

    }
    else if(e->key() == Qt::Key_C && !e->isAutoRepeat())
    {
        SingleAxisMove single;
        single.axis = 6;
        single.direction = MOVE_DIR_NEGATIVE;
        single.vel = 0.1;
        single.endPoint = -180.0;
        single.coordinate.coordinateType = COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(e->key() == Qt::Key_D && !e->isAutoRepeat())
    {
        SingleAxisMove single;
        single.axis = 5;
        single.direction = MOVE_DIR_NEGATIVE;
        single.vel = 0.1;
        single.endPoint = -180.0;
        single.coordinate.coordinateType = COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(e->key() == Qt::Key_E && !e->isAutoRepeat())
    {
        SingleAxisMove single;
        single.axis = 4;
        single.direction = MOVE_DIR_NEGATIVE;
        single.vel = 0.1;
        single.endPoint = -180.0;
        single.coordinate.coordinateType = COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(e->key() == Qt::Key_F && !e->isAutoRepeat())
    {
        SingleAxisMove single;
        single.axis = 5;
        single.direction = MOVE_DIR_POSITIVE;
        single.vel = 0.1;
        single.endPoint=180;
        single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(e->key() == Qt::Key_G && !e->isAutoRepeat())
    {
        static int coordi = 0;
        if(coordi==0)
        {
            coordinate_select="joint_coordinate";
            ui->statusBar->showMessage(tr("COORDINATE:joint"),0);
        }
        else if(coordi == 1)
        {
            coordinate_select="word_coordinate";
            ui->statusBar->showMessage(tr("COORDINATE:world"),0);
        }
        else if(coordi == 2)
        {
            coordinate_select = "tool_coordinate";
            ui->statusBar->showMessage(tr("COORDINATE:tool"),0);
        }
        else if(coordi == 3)
        {
            coordinate_select = "piece_coordinate";
            ui->statusBar->showMessage(tr("COORDINATE:usr"),0);
        }

        ++coordi;
        if(coordi>3)
        {
            coordi=0;
        }

    }
    else if(e->key() == Qt::Key_H && !e->isAutoRepeat())
    {
        int current_row,total_row;
        current_row = ui->plainTextEdit->textCursor().blockNumber();
        total_row = ui->plainTextEdit->blockCount();
        if(current_row==0||(total_row-1)==current_row)
            return;
        run_file = new RunFile(program_filename);
        connect(run_file,SIGNAL(FileNameChanged1(QString)),this,SLOT(display_changed_file(QString)));
        connect(run_file,SIGNAL(FileClosed1()),this,SLOT(file_run_end()));
        run_file->init();
        run_file->start();
        mainwindow_timer1->start();
    }
    else if(e->key() == Qt::Key_I && !e->isAutoRepeat())
    {
        if(run_file!=NULL)
        {
            run_file->setPause();
        }
        CTRL_MotionResume();
    }
    else if(e->key() == Qt::Key_J && !e->isAutoRepeat())
    {
        int current_row,total_row;
        current_row = ui->plainTextEdit->textCursor().blockNumber();
        total_row = ui->plainTextEdit->blockCount();
        if(current_row==0||(total_row-1)==current_row)
            return;

        run_file = new RunFile(program_filename);
        run_file->init();
        run_file->exeLine(current_row);

        free(run_file);
        run_file = NULL;
    }
    else if(e->key() == Qt::Key_K && !e->isAutoRepeat())
    {
        int current_row,total_row;
        current_row = ui->plainTextEdit->textCursor().blockNumber();
        total_row = ui->plainTextEdit->blockCount();
        if(current_row==0||(total_row-1)==current_row)
            return;
        run_file = new RunFile(program_filename);
        run_file->init();
        run_file->exeInverseLine(current_row);

        free(run_file);
        run_file = NULL;
    }
    else if(e->key() == Qt::Key_L && !e->isAutoRepeat())
    {

    }
    else if(e->key() == Qt::Key_M && !e->isAutoRepeat())
    {
        int current_row,total_row;
        //static bool movc_send_victory_flag = true;
        current_row = ui->plainTextEdit->textCursor().blockNumber();
        total_row = ui->plainTextEdit->blockCount();
        if(current_row==0||(total_row-1)==current_row)
            return;

        run_file = new RunFile(program_filename);
        run_file->init(current_row,1);
        run_file->start();
        mainwindow_timer1->start();
    }
    else if(e->key() == Qt::Key_N && !e->isAutoRepeat())
    {
        int current_row,total_row;
        current_row = ui->plainTextEdit->textCursor().blockNumber();
        total_row = ui->plainTextEdit->blockCount();
        if(current_row==0||(total_row-1)==current_row)
            return;
        run_file = new RunFile(program_filename);
        connect(run_file,SIGNAL(FileNameChanged1(QString)),this,SLOT(display_changed_file(QString)));
        connect(run_file,SIGNAL(FileClosed1()),this,SLOT(file_run_end()));

        run_file->init(current_row,0);
        run_file->start();
        mainwindow_timer1->start();

    }
    else if(e->key() == Qt::Key_O && !e->isAutoRepeat())
    {
        CTRL_MotionPause();
        run_file->interpPause();

    }
    else if(e->key() == Qt::Key_P && !e->isAutoRepeat())
    {
        static bool orderlist = true;
        if(orderlist)
        {
            commandlistM->show();
        }
        else
        {
            commandlistM->close();
        }
        orderlist = !orderlist;

    }
    else if(e->key() == Qt::Key_Q && !e->isAutoRepeat())
    {
        SingleAxisMove single;
        single.axis = 1;
        single.direction = MOVE_DIR_NEGATIVE;
        single.vel = 0.1;
        single.endPoint = -180.0;
        single.coordinate.coordinateType = COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(e->key() == Qt::Key_R && !e->isAutoRepeat())
    {
        SingleAxisMove single;
        single.axis = 4;
        single.direction = MOVE_DIR_POSITIVE;
        single.vel = 0.1;
        single.endPoint=180.0;
        single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(e->key() == Qt::Key_S && !e->isAutoRepeat())
    {
        SingleAxisMove single;
        single.axis = 2;
        single.direction = MOVE_DIR_POSITIVE;
        single.vel = 1.0;
        single.endPoint=180.0;
        single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(e->key() == Qt::Key_T && !e->isAutoRepeat())
    {
        int current_row;
        current_row = ui->plainTextEdit->textCursor().blockNumber();
        --current_row;
        if(current_row>=0)
        ui->plainTextEdit->setCursorPos(current_row,1);
    }
    else if(e->key() == Qt::Key_U && !e->isAutoRepeat())
    {
        CTRL_ServoEnable(0);
        if(run_file==NULL)
        {
            return;
        }
        else
        {
            run_file->stop();
            run_file->wait();
            //CTRL_MovementStop();
            mainwindow_timer1->stop();
            delete run_file;
            run_file = NULL;
        }
    }
    else if(e->key() == Qt::Key_V && !e->isAutoRepeat())
    {
        SingleAxisMove single;
        single.axis = 6;
        single.direction = MOVE_DIR_POSITIVE;
        single.vel = 0.5;
        single.endPoint=180.0;
        single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(e->key() == Qt::Key_W && !e->isAutoRepeat())
    {
        SingleAxisMove single;
        single.axis = 1;
        single.direction = MOVE_DIR_POSITIVE;
        single.vel = 0.1;
        single.endPoint=180.0;
        single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(e->key() == Qt::Key_X && !e->isAutoRepeat())
    {
        SingleAxisMove single;
        single.axis = 3;
        single.direction = MOVE_DIR_POSITIVE;
        single.vel = 0.1;
        single.endPoint=180.0;
        single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(e->key() == Qt::Key_Y && !e->isAutoRepeat())
    {
        int current_row,total_row;
        current_row = ui->plainTextEdit->textCursor().blockNumber();
        total_row = ui->plainTextEdit->blockCount();
        qDebug()<<ui->plainTextEdit->textCursor().blockNumber();
        qDebug()<<ui->plainTextEdit->blockCount();
        ++current_row;
        if(current_row<=total_row)
        ui->plainTextEdit->setCursorPos(current_row,1);
    }
    else if(e->key() == Qt::Key_Z && !e->isAutoRepeat())
    {
        SingleAxisMove single;
        single.axis = 3;
        single.direction = MOVE_DIR_NEGATIVE;
        single.vel = 0.1;
        single.endPoint = -180.0;
        single.coordinate.coordinateType = COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(e->key() == Qt::Key_1 && !e->isAutoRepeat())
    {
        CTRL_ServoReset();
        if(run_file!=NULL)
        {
            delete run_file;
            run_file = NULL;
        }
    }
    else if(e->key() == Qt::Key_2 && !e->isAutoRepeat())
    {
        emit main_insert_sig();
    }
    else if(e->key() == Qt::Key_3 && !e->isAutoRepeat())
    {
        program_delete_line();
    }
    else if(e->key() == Qt::Key_4 && !e->isAutoRepeat())
    {
        require_modify_data();
        commandlistM->list_input_display();
    }
    else if(e->key() == Qt::Key_5 && !e->isAutoRepeat())
    {
        emit main_insert_sig();
        program_delete_line();
    }
    else if(e->key() == Qt::Key_6 && !e->isAutoRepeat())
    {
        static bool onoff=true;
        if(onoff)
        {
            CTRL_ServoEnable(1);
            ui->statusBar->showMessage(tr("SERVO ENABLE"),0);
        }
        else
        {
            CTRL_ServoEnable(0);
            ui->statusBar->showMessage(tr("SERVO DISNABLE"),0);
        }
        onoff=!onoff;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    if(!e->isAutoRepeat())
    {
        CTRL_MovementStop();
    }
    if(e->key() == Qt::Key_U && !e->isAutoRepeat())
    {
        delete run_file;
    }
    else if(e->key() == Qt::Key_N && !e->isAutoRepeat())
    {
        run_file->stop();
        run_file->wait();
        CTRL_MovementStop();
        mainwindow_timer1->stop();
        delete run_file;
        run_file = NULL;
    }
    else if(e->key() == Qt::Key_M && !e->isAutoRepeat())
    {
        run_file->stop();
        run_file->wait();
        CTRL_MovementStop();
        mainwindow_timer1->stop();
        delete run_file;
        run_file = NULL;
    }
}

FileSelectPushButton::FileSelectPushButton(QString buttonname)
{
    this->buttonname = buttonname;
    this->setText(this->buttonname);
    connect(this,SIGNAL(clicked()),this,SLOT(send_select_program_slot()));
}

void FileSelectPushButton::send_select_program_slot()
{
    emit reload_program_sig(buttonname);
    emit select_program_sig(buttonname);
}
