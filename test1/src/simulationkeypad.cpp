#include "simulationkeypad.h"
#include "ui_simulationkeypad.h"
#include <QDebug>
//#include "xml_cancle/xmlcancle.h"

SimulationKeypad::SimulationKeypad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimulationKeypad)
{
    ui->setupUi(this);
    commandlist = new CommandList();
    //XmlCancle *xmlcancle1 = new XmlCancle();
    //正常输入操作
    connect(commandlist,SIGNAL(movj_list_simula_sig(QString *)),this,SLOT(movj_simula_slot(QString *)));
    connect(commandlist,SIGNAL(movl_list_simula_sig(QString *)),this,SLOT(movl_simula_slot(QString *)));
    connect(commandlist,SIGNAL(movc_list_simula_sig(QString *)),this,SLOT(movc_simula_slot(QString *)));
    connect(commandlist,SIGNAL(speed_list_simula_sig(QString *)),this,SLOT(speed_simula_slot(QString *)));
    connect(commandlist,SIGNAL(dout_list_simula_sig(QString *)),this,SLOT(dout_simula_slot(QString *)));
    connect(commandlist,SIGNAL(din_list_simula_sig(QString*)),this,SIGNAL(din_simula_slot_sig(QString *)));
    connect(commandlist,SIGNAL(pause_list_simula_sig(QString*)),this,SIGNAL(pause_simula_slot_sig(QString *)));
    connect(commandlist,SIGNAL(timer_list_simula_sig(QString)),this,SIGNAL(timer_simula_slot_sig(QString)));
    connect(commandlist,SIGNAL(jump_list_simula_sig(QString*)),this,SIGNAL(jump_simula_slot_sig(QString *)));
    connect(commandlist,SIGNAL(label_list_simula_sig(QString)),this,SIGNAL(label_simula_slot_sig(QString)));
    connect(commandlist,SIGNAL(call_list_simula_sig(QString*)),this,SIGNAL(call_simula_slot_sig(QString *)));
    connect(commandlist,SIGNAL(ret_list_simula_sig(QString*)),this,SIGNAL(ret_simula_slot_sig(QString *)));

    //插入操作
    connect(this,SIGNAL(simu_insert_sig()),commandlist,SLOT(list_insert_slot()));
    connect(commandlist,SIGNAL(list_simu_insert_sig(QString*)),this,SLOT(simu_main_insert_slot(QString *)));

    connect(this,SIGNAL(close_input_sig()),commandlist,SLOT(close_input_slot()));
}

SimulationKeypad::~SimulationKeypad()
{
    delete ui;
}

void SimulationKeypad::on_commandviewpushButton_clicked()
{
    commandlist->show();
}

void SimulationKeypad::on_pushButton_emer_stop_clicked()
{
    emit moni_test_sig();
    CTRL_ServoEnable(0);
}

void SimulationKeypad::movj_simula_slot(QString *order)
{
    emit movj_simula_slot_sig(order);
}

void SimulationKeypad::movl_simula_slot(QString *order)
{
    emit movl_simula_slot_sig(order);
}

void SimulationKeypad::movc_simula_slot(QString *order)
{
    emit movc_simula_slot_sig(order);
}

void SimulationKeypad::speed_simula_slot(QString *order)
{
    emit speed_simula_slot_sig(order);
}

void SimulationKeypad::dout_simula_slot(QString *order)
{
    emit dout_simula_slot_sig(order);
}

void SimulationKeypad::on_pushButton_simu_up_clicked()
{
    emit simu_up_sig();
}

void SimulationKeypad::on_pushButton_simu_down_clicked()
{
    emit simu_down_sig();
}

void SimulationKeypad::on_pushButton_simu_delete_pressed()
{
    emit simu_delete_sig();
}

void SimulationKeypad::on_pushButton_simu_insert_pressed()
{
    emit simu_insert_sig();
}

//插入
void SimulationKeypad::simu_main_insert_slot(QString *order)
{
    emit simu_main_insert_sig(order);
}

void SimulationKeypad::on_pushButton_simu_modify_pressed()
{
    //显示对应命令的编辑框-读取当前光标行是什么类型的命令（读取光标位置的命令）
    //将选择行的数据显示到命令输入框
    emit simu_main_modify_sig();//提取需要修改的数据
    qDebug()<<"start display data";
    qDebug()<<doutc2.buf[0]<<doutc2.buf[1];
    commandlist->list_input_display();
    //emit simu_list_modify_sig();//将数据显示出来

}

void SimulationKeypad::on_pushButton_simu_ensure_pressed()
{
    qDebug()<<"select_input_command="<<select_input_command;
    //修改确认，删除当前行，插入命令行。//先插入，再删除

        qDebug("movj modify ensure");
        emit simu_insert_sig();
        emit simu_delete_sig();//删除光标行
        //在删除位置插入修改行
}

void SimulationKeypad::on_pushButton_simu_sevoenabe_clicked()
{
    if(ui->pushButton_simu_sevoenabe->text()=="sevor\nenable")
    {
        ui->pushButton_simu_sevoenabe->setText("STOP");
        ui->pushButton_simu_sevoenabe->setStyleSheet("background-color: rgb(34,139,34);");
        CTRL_ServoEnable(1);
    }else {
        emit simu_MultiSP_release_sig();
        ui->pushButton_simu_sevoenabe->setText("sevor\nenable");
        ui->pushButton_simu_sevoenabe->setStyleSheet("background-color: rgb(250,0,0;");
        CTRL_ServoEnable(0);
    }

}

void SimulationKeypad::on_pushButton_simu_stop_clicked()
{
    //CTRL_MovementStop();
    CTRL_MotionPause();
    emit simu_pause_sig();
//    CTRL_MotionPause();
}

void SimulationKeypad::on_pushButton_simu_clear_clicked()
{
    CTRL_ServoReset();
    qDebug()<<"ServoReset()";
}

void SimulationKeypad::on_pushButton_simu_j1p_pressed()
{
    if(coordinate_select=="joint_coordinate")
    {
        SingleAxisMove single;
        single.axis = 1;
        single.direction = MOVE_DIR_POSITIVE;
        single.vel = 0.1;
        single.endPoint=180.0;
        single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(coordinate_select=="word_coordinate")
    {
        SingleAxisMove single;
        single.axis = 1;
        single.direction = MOVE_DIR_POSITIVE;
        single.vel = 0.5;
        single.endPoint=1000;
        single.coordinate.coordinateType=COORDINATE_TYPE_LINEAR;

        CTRL_AddSingleAxisMove(&single);
    }
    else
    {

    }
}

void SimulationKeypad::on_pushButton_simu_j1p_released()
{
    CTRL_MovementStop();
}

void SimulationKeypad::on_pushButton_j2p_pressed()
{
    if(coordinate_select=="joint_coordinate")
    {
        SingleAxisMove single;
        single.axis = 2;
        single.direction = MOVE_DIR_POSITIVE;
        single.vel = 1.0;
        single.endPoint=180.0;
        single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(coordinate_select=="word_coordinate")
    {
        SingleAxisMove single;
        single.axis = 2;
        single.direction = MOVE_DIR_POSITIVE;
        single.vel = 0.5;
        single.endPoint=1000;
        single.coordinate.coordinateType=COORDINATE_TYPE_LINEAR;

        CTRL_AddSingleAxisMove(&single);
    }
    else
    {

    }

}


void SimulationKeypad::on_pushButton_j2p_released()
{
    CTRL_MovementStop();
}

void SimulationKeypad::on_pushButton_simu_j3p_pressed()
{
    if(coordinate_select=="joint_coordinate")
    {
        SingleAxisMove single;
        single.axis = 3;
        single.direction = MOVE_DIR_POSITIVE;
        single.vel = 0.1;
        single.endPoint=180.0;
        single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(coordinate_select=="word_coordinate")
    {
        SingleAxisMove single;
        single.axis = 3;
        single.direction = MOVE_DIR_POSITIVE;
        single.vel = 0.5;
        single.endPoint=1000;
        single.coordinate.coordinateType=COORDINATE_TYPE_LINEAR;

        CTRL_AddSingleAxisMove(&single);
    }
    else
    {

    }
}

void SimulationKeypad::on_pushButton_simu_j3p_released()
{
    CTRL_MovementStop();
}

void SimulationKeypad::on_pushButton_j4p_pressed()
{
    if(coordinate_select=="joint_coordinate")
    {
        SingleAxisMove single;
        single.axis = 4;
        single.direction = MOVE_DIR_POSITIVE;
        single.vel = 0.1;
        single.endPoint=180.0;
        single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(coordinate_select=="word_coordinate")
    {
        SingleAxisMove single;
        single.axis = 4;
        single.direction = MOVE_DIR_POSITIVE;
        single.vel = 0.5;
        single.endPoint=1000;
        single.coordinate.coordinateType=COORDINATE_TYPE_LINEAR;

        CTRL_AddSingleAxisMove(&single);
    }
    else
    {

    }
}

void SimulationKeypad::on_pushButton_j4p_released()
{
    CTRL_MovementStop();
}

void SimulationKeypad::on_pushButton_j5p_pressed()
{
    if(coordinate_select=="joint_coordinate")
    {
        SingleAxisMove single;
        single.axis = 5;
        single.direction = MOVE_DIR_POSITIVE;
        single.vel = 0.1;
        single.endPoint=180;
        single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(coordinate_select=="word_coordinate")
    {
        SingleAxisMove single;
        single.axis = 5;
        single.direction = MOVE_DIR_POSITIVE;
        single.vel = 0.5;
        single.endPoint=1000;
        single.coordinate.coordinateType=COORDINATE_TYPE_LINEAR;

        CTRL_AddSingleAxisMove(&single);
    }
    else
    {

    }
}

void SimulationKeypad::on_pushButton_j5p_released()
{
    CTRL_MovementStop();
}

void SimulationKeypad::on_pushButton_j6p_pressed()
{
    if(coordinate_select=="joint_coordinate")
    {
        SingleAxisMove single;
        single.axis = 6;
        single.direction = MOVE_DIR_POSITIVE;
        single.vel = 0.5;
        single.endPoint=180.0;
        single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(coordinate_select=="word_coordinate")
    {
        SingleAxisMove single;
        single.axis = 6;
        single.direction = MOVE_DIR_POSITIVE;
        single.vel = 0.5;
        single.endPoint=1000;
        single.coordinate.coordinateType=COORDINATE_TYPE_LINEAR;

        CTRL_AddSingleAxisMove(&single);
    }
    else
    {

    }
}

void SimulationKeypad::on_pushButton_j6p_released()
{
    CTRL_MovementStop();
}

void SimulationKeypad::on_pushButton_simu_j1n_pressed()
{
    if(coordinate_select=="joint_coordinate")
    {
        SingleAxisMove single;
        single.axis = 1;
        single.direction = MOVE_DIR_NEGATIVE;
        single.vel = 0.1;
        single.endPoint = -180.0;
        single.coordinate.coordinateType = COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(coordinate_select=="word_coordinate")
    {
        SingleAxisMove single;
        single.axis = 1;
        single.direction = MOVE_DIR_NEGATIVE;
        single.vel = 0.5;
        single.endPoint = -1000.0;
        single.coordinate.coordinateType = COORDINATE_TYPE_LINEAR;

        CTRL_AddSingleAxisMove(&single);
    }
    else
    {

    }

}

void SimulationKeypad::on_pushButton_simu_j1n_released()
{
    CTRL_MovementStop();
}

void SimulationKeypad::on_pushButton_simu_j2n_pressed()
{
    if(coordinate_select=="joint_coordinate")
    {
        SingleAxisMove single;
        single.axis = 2;
        single.direction = MOVE_DIR_NEGATIVE;
        single.vel = 0.1;
        single.endPoint = -180.0;
        single.coordinate.coordinateType = COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(coordinate_select=="word_coordinate")
    {
        SingleAxisMove single;
        single.axis = 2;
        single.direction = MOVE_DIR_NEGATIVE;
        single.vel = 0.5;
        single.endPoint = -1000.0;
        single.coordinate.coordinateType = COORDINATE_TYPE_LINEAR;

        CTRL_AddSingleAxisMove(&single);
    }
    else
    {

    }
}

void SimulationKeypad::on_pushButton_simu_j2n_released()
{
    CTRL_MovementStop();
}

void SimulationKeypad::on_pushButton_simu_j3n_pressed()
{
    if(coordinate_select=="joint_coordinate")
    {
        SingleAxisMove single;
        single.axis = 3;
        single.direction = MOVE_DIR_NEGATIVE;
        single.vel = 0.1;
        single.endPoint = -180.0;
        single.coordinate.coordinateType = COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(coordinate_select=="word_coordinate")
    {
        SingleAxisMove single;
        single.axis = 3;
        single.direction = MOVE_DIR_NEGATIVE;
        single.vel = 0.5;
        single.endPoint = -1000.0;
        single.coordinate.coordinateType = COORDINATE_TYPE_LINEAR;

        CTRL_AddSingleAxisMove(&single);
    }
    else
    {

    }
}

void SimulationKeypad::on_pushButton_simu_j3n_released()
{
    CTRL_MovementStop();
}

void SimulationKeypad::on_pushButton_simu_j4n_pressed()
{
    if(coordinate_select=="joint_coordinate")
    {
        SingleAxisMove single;
        single.axis = 4;
        single.direction = MOVE_DIR_NEGATIVE;
        single.vel = 0.1;
        single.endPoint = -180.0;
        single.coordinate.coordinateType = COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(coordinate_select=="word_coordinate")
    {
        SingleAxisMove single;
        single.axis = 4;
        single.direction = MOVE_DIR_NEGATIVE;
        single.vel = 0.5;
        single.endPoint = -1000;
        single.coordinate.coordinateType = COORDINATE_TYPE_LINEAR;

        CTRL_AddSingleAxisMove(&single);
    }
    else
    {

    }
}

void SimulationKeypad::on_pushButton_simu_j4n_released()
{
    CTRL_MovementStop();
}

void SimulationKeypad::on_pushButton_j5n_pressed()
{
    if(coordinate_select=="joint_coordinate")
    {
        SingleAxisMove single;
        single.axis = 5;
        single.direction = MOVE_DIR_NEGATIVE;
        single.vel = 0.1;
        single.endPoint = -180.0;
        single.coordinate.coordinateType = COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(coordinate_select=="word_coordinate")
    {
        SingleAxisMove single;
        single.axis = 5;
        single.direction = MOVE_DIR_NEGATIVE;
        single.vel = 0.5;
        single.endPoint = -1000;
        single.coordinate.coordinateType = COORDINATE_TYPE_LINEAR;

        CTRL_AddSingleAxisMove(&single);
    }
    else
    {

    }
}

void SimulationKeypad::on_pushButton_j5n_released()
{
    CTRL_MovementStop();
}

void SimulationKeypad::on_pushButton_j6n_pressed()
{
    if(coordinate_select=="joint_coordinate")
    {
        SingleAxisMove single;
        single.axis = 6;
        single.direction = MOVE_DIR_NEGATIVE;
        single.vel = 0.1;
        single.endPoint = -180.0;
        single.coordinate.coordinateType = COORDINATE_TYPE_JOINT;

        CTRL_AddSingleAxisMove(&single);
    }
    else if(coordinate_select=="word_coordinate")
    {
        SingleAxisMove single;
        single.axis = 6;
        single.direction = MOVE_DIR_NEGATIVE;
        single.vel = 0.5;
        single.endPoint = -1000;
        single.coordinate.coordinateType = COORDINATE_TYPE_LINEAR;

        CTRL_AddSingleAxisMove(&single);
    }
    else
    {

    }
}

void SimulationKeypad::on_pushButton_j6n_released()
{
    CTRL_MovementStop();
}

void SimulationKeypad::on_pushButton_simu_SingleSP_pressed()
{
    //Now MOVJ
    //(1)require current program information
    //a:what is element ?MOVJ/MOVL
    emit send_current_line_sig();
    //MotionFeedback fb;
    /*if((fb.motionState==COMMAND_DONE)&&(fb.lineNum==Current_Line_Num))
    {
        emit
    }*/


    //(2)require position information
    /*if(1)
    {
        JointMoveInformation jm;
        jm.acc = 1.0;
        jm.dec = 1.0;
        jm.vJ = 0.0;                   //toDouble
        jm.endPoint.j1 = 0.0;
        jm.endPoint.j2 = 0.0;
        jm.endPoint.j3 = 0.0;
        jm.endPoint.j4 = 0.0;
        jm.endPoint.j5 = 0.0;
        jm.endPoint.j6 = 0.0;

        CTRL_AddJointMove(&jm,0,0);
    }
else                                //MOVL
    {
        LinearDescartesMoveInformation mdl;
        mdl.acc = 1;
        mdl.dec = 1;
        mdl.free = 1;
        mdl.endPoint.x = 0.0;               //toDouble
        mdl.endPoint.y = 0.0;
        mdl.endPoint.z = 0.0;

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

        mdl.vL = 0.0;                    //toDouble
        mdl.vR = 0.0;
        CTRL_AddDescartesLinearMove(&mdl,0,0);
    }*/
}

void SimulationKeypad::on_pushButton_simu_SingleSP_released()
{
    CTRL_MovementStop();
}

void SimulationKeypad::on_pushButton_simu_SingleSN_pressed()
{
    emit send_single_backward_sig();
}

void SimulationKeypad::on_pushButton_simu_SingleSN_released()
{
    CTRL_MovementStop();
}

void SimulationKeypad::on_comboBox_2_currentIndexChanged(int index)
{
    if(index==0)
    {
        coordinate_select = "joint_coordinate";
    }
    else if(index ==1)
    {
        coordinate_select = "word_coordinate";
    }
    else if(index == 2)
    {
        coordinate_select = "cylindrical_coordinate";
    }
    else if(index == 3)
    {
        coordinate_select = "tool_coordinate";
    }
    else if(index == 4)
    {
        coordinate_select = "piece_coordinate";
    }
}

void SimulationKeypad::on_pushButton_simu_movj_zero_clicked()
{
    JointMoveInformation jm;
    jm.acc = 1.0;
    jm.dec = 1.0;
    jm.vJ = 0.1;                   //toDouble
    jm.endPoint.j1 = 0.0;
    jm.endPoint.j2 = 0.0;
    jm.endPoint.j3 = 0.0;
    jm.endPoint.j4 = 0.0;
    jm.endPoint.j5 = 0.0;
    jm.endPoint.j6 = 0.0;

    CTRL_AddJointMove(&jm,0,0);
}

void SimulationKeypad::on_pushButton_simu_MultiSP_pressed()
{
    emit simu_MultiSP_sig();
}

void SimulationKeypad::on_pushButton_simu_MultiSP_released()
{
    emit simu_MultiSP_release_sig();
    //CTRL_MovementStop();
    //emit simu_stop_timer1_sig();
}

void SimulationKeypad::on_pushButton_simu_MultiSN_pressed()
{
    emit simu_MultiSN_sig();
}

void SimulationKeypad::on_pushButton_simu_MultiSN_released()
{
    //CTRL_MovementStop();
    emit simu_MultiSN_release_sig();
    //emit simu_stop_timer1_sig();
}

void SimulationKeypad::on_pushButton_simu_test_run_pressed()
{
    emit simu_test_run_sig();
}

void SimulationKeypad::on_pushButton_simu_test_run_released()
{
    //CTRL_MovementStop();
    emit simu_stop_timer1_sig();
}

void SimulationKeypad::on_pushButton_simu_run_clicked()
{
    emit simu_test_run_sig();
}

void SimulationKeypad::on_pushButton_simu_closelist_clicked()
{
    commandlist->close();
}

void SimulationKeypad::on_pushButton_33_clicked()
{
    //emit close_commandinput_sig();
}

void SimulationKeypad::on_pushButton_close_list_clicked()
{
    commandlist->close();
}

void SimulationKeypad::on_pushButton_close_input_clicked()
{
    emit close_input_sig();
}

//simu start button
void SimulationKeypad::on_pushButton_simu_start_clicked()
{
    emit simu_restart_sig();
    CTRL_MotionResume();
}
