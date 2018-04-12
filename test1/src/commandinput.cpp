#include "commandinput.h"
#include "ui_commandinput.h"

QString program_filename="NULL";
MovjCommand movjc1;
MovjCommand movjc2;
MovlCommand movlc1;
MovlCommand movlc2;
MovcCommand movcc1;
MovcCommand movcc2;
SpeedCommand speedc1;
SpeedCommand speedc2;
DoutCommand doutc1;
DoutCommand doutc2;
DinCommand dinc1;
DinCommand dinc2;

QString LabelCommand1;
QString LabelCommand2;
PauseCommand pausec1;
PauseCommand pausec2;
QString timec1;
QString timec2;
JumpCommand jumpc1;
JumpCommand jumpc2;
CallCommand callc1;
CallCommand callc2;
RetCommand retc1;
RetCommand retc2;


QString select_input_command;

PositionData positiondata1;//位置保存结构体变量
PositionData positiondata2;

QStringList posi_vari_point;//保存已经保存的变量

QString coordinate_select = "joint_coordinate";//teaching apparatus coordinate select

bool movc_send_victory_flg = true;

CommandInput::CommandInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandInput)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setGeometry(580,580,511,161);

    //Cmdlist = new CommandList();
    //Cmdlist->setcommandinput(ui);


    //connect(CommandInput,SIGNAL(commandsig(int)),ui->stackedWidget,SLOT(setCurrentIndex(int)));
    connect(this,SIGNAL(commandsig(int)),ui->stackedWidget,SLOT(setCurrentIndex(int)));
    connect(posate,SIGNAL(refresh_posi_vari_sig()),this,SLOT(refresh_posi_vari_slot()));
}

CommandInput::~CommandInput()
{
    delete ui;
}

void CommandInput::commandchangej()
{
    emit commandsig(0);
}

void CommandInput::commandchangel()
{
    emit commandsig(1);
}

void CommandInput::commandchangec()
{
    emit commandsig(2);
}

void CommandInput::commandchangeimov()
{
    emit commandsig(3);
}

void CommandInput::commandchangespeed()
{
    emit commandsig(4);
}

void CommandInput::commandchangecoord()
{
    emit commandsig(5);
}

void CommandInput::commandchangehome()
{
    emit commandsig(29);
}

void CommandInput::commandchangedout()
{
    emit commandsig(6);
}

void CommandInput::commandchangedin()
{
    emit commandsig(7);
}

void CommandInput::commandchangeaout()
{
    emit commandsig(8);
}

void CommandInput::commandchangeain()
{
    emit commandsig(9);
}

void CommandInput::commandchangearation()
{
    emit commandsig(10);
}

void CommandInput::commandchangearatiof()
{
    emit commandsig(11);
}

void CommandInput::commandchangejump()
{
    emit commandsig(12);
}

void CommandInput::commandchangelabel()
{
    emit commandsig(13);
}

void CommandInput::commandchangecall()
{
    emit commandsig(14);
}

void CommandInput::commandchangeret()
{
    emit commandsig(15);
}

void CommandInput::commandchangetimer()
{
    emit commandsig(16);
}
void CommandInput::commandchangepause()
{
    emit commandsig(17);
}

void CommandInput::commandchangecwait()
{
    emit commandsig(18);
}

void CommandInput::commandchangeadd()
{
    emit commandsig(19);
}

void CommandInput::commandchangesub()
{
    emit commandsig(20);
}

void CommandInput::commandchangemul()
{
    emit commandsig(21);
}

void CommandInput::commandchangediv()
{
    emit commandsig(22);
}

void CommandInput::commandchangeinc()
{
    emit commandsig(23);
}

void CommandInput::commandchangedec()
{
    emit commandsig(24);
}

void CommandInput::commandchangeand()
{
    emit commandsig(25);
}

void CommandInput::commandchangeor()
{
    emit commandsig(26);
}

void CommandInput::commandchangenot()
{
    emit commandsig(27);
}

void CommandInput::commandchangexor()
{
    emit commandsig(28);
}

//修改数据显示

void CommandInput::modify_movj_display()
{
    ui->lineEdit_movj_vj->setText(movjc2.buf[1]);
    ui->comboBox_movj_pl->setCurrentText(movjc2.buf[2]);
    if(movjc2.buf[3]=="1")
    {
        ui->checkBox_movj_nutil->setChecked(true);
    }
    else
    {
        ui->checkBox_movj_nutil->setChecked(false);
    }


    ui->comboBox_movj_ioselect->setCurrentText(movjc2.buf[4]);
    ui->lineEdit_movj_ionumber->setText(movjc2.buf[5]);
    ui->comboBox_movj_ioprepare->setCurrentText(movjc2.buf[6]);
    ui->lineEdit_movj_iovalue->setText(movjc2.buf[7]);
    ui->comboBox_movj_ioio->setCurrentText(movjc2.buf[8]);
    ui->lineEdit_movj_acc->setText(movjc2.buf[9]);
    ui->lineEdit_movj_dec->setText(movjc2.buf[10]);
    if(movjc2.buf[11]=="1")
    {
        ui->checkBox_movj_nwait->setChecked(true);
    }
    else
    {
        ui->checkBox_movj_nwait->setChecked(false);
    }

    ui->comboBox_movj_position->setCurrentText(movjc2.buf[0]);
}

void CommandInput::modify_movl_display()
{
    ui->lineEdit_movl_vl->setText(movlc2.buf[1]);
    ui->lineEdit_movl_vr->setText(movlc2.buf[2]);
    ui->comboBox_movl_pl->setCurrentText(movlc2.buf[3]);
    if(movlc2.buf[4]=="1")
    {
        ui->checkBox_movl_nutil->setChecked(true);
    }
    else
    {
        ui->checkBox_movl_nutil->setChecked(false);
    }

    ui->comboBox_movl_ioselect->setCurrentText(movlc2.buf[5]);
    ui->lineEdit_movl_ionumber->setText(movlc2.buf[6]);
    ui->comboBox_movl_ioprepare->setCurrentText(movlc2.buf[7]);
    ui->lineEdit_movl_iovalue->setText(movlc2.buf[8]);
    ui->comboBox_movl_ioio->setCurrentText(movlc2.buf[9]);

    ui->lineEdit_movl_acc->setText(movlc2.buf[10]);
    ui->lineEdit_movl_dec->setText(movlc2.buf[11]);
    ui->lineEdit_movl_cr->setText(movlc2.buf[12]);
    if(movlc2.buf[13]=="1")
    {
        ui->checkBox_movl_nwait->setChecked(true);
    }
    else
    {
        ui->checkBox_movl_nwait->setChecked(false);
    }

    if(movlc2.buf[14]=="1")
    {
        ui->checkBox_movl_usr->setChecked(true);
    }
    else
    {
        ui->checkBox_movl_usr->setChecked(false);
    }

    ui->comboBox_movl_usr->setCurrentText(movlc2.buf[15]);

    if(movlc2.buf[16]=="1")
    {
        ui->checkBox_movl_tool->setChecked(true);
    }
    else
    {
        ui->checkBox_movc_tool->setChecked(false);
    }

    ui->comboBox_movl_tool->setCurrentText(movlc2.buf[17]);

    ui->comboBox_movl_position->setCurrentText(movlc2.buf[0]);
}
void CommandInput::modify_movc_display()
{
    ui->lineEdit_movc_vl->setText(movcc2.buf[1]);
    ui->lineEdit_movc_vr->setText(movcc2.buf[2]);
    ui->comboBox_movc_pl->setCurrentText(movcc2.buf[3]);
    if(movcc2.buf[4]=="1")
    {
        ui->checkBox_movc_nuitl->setChecked(true);
    }
    else
    {
        ui->checkBox_movc_nuitl->setChecked(false);
    }

    ui->comboBox_movc_ioselect->setCurrentText(movcc2.buf[5]);
    ui->lineEdit_movc_ionumber->setText(movcc2.buf[6]);
    //ui->comboBox_movc_ioprepare->setCurrentText(movcc2.buf[7]);

    //ui->lineEdit_movc_iovalue->setText(movcc2.buf[8]);
    ui->comboBox_movc_ioio->setCurrentText(movcc2.buf[9]);

    ui->lineEdit_movc_acc->setText(movcc2.buf[10]);
    ui->lineEdit_movc_dec->setText(movcc2.buf[11]);
    ui->lineEdit_movc_cr->setText(movcc2.buf[12]);
    if(movcc2.buf[13]=="1")
    {
        ui->checkBox_movc_nwait->setChecked(true);
    }
    else
    {
        ui->checkBox_movc_nwait->setChecked(false);
    }

    if(movlc2.buf[14]=="1")
    {
        ui->checkBox_movc_usr->setChecked(true);
    }
    else
    {
        ui->checkBox_movc_usr->setChecked(false);
    }

    ui->comboBox_movc_usr->setCurrentText(movcc2.buf[15]);

    if(movcc2.buf[16]=="1")
    {
        ui->checkBox_movc_tool->setChecked(true);
    }
    else
    {
        ui->checkBox_movc_tool->setChecked(false);
    }

    ui->comboBox_movc_tool->setCurrentText(movcc2.buf[17]);

    ui->comboBox_movc_position->setCurrentText(movcc2.buf[0]);
}

void CommandInput::modify_speed_display()
{
    ui->comboBox_speed_vstyle->setCurrentText(speedc2.buf[0]);
    ui->lineEdit_speed_value->setText(speedc2.buf[1]);
    ui->lineEdit_speed_acc->setText(speedc2.buf[2]);
}

void CommandInput::modify_dout_display()
{
    ui->io_dout_address_lineEdit->setText(doutc2.buf[0]);
    ui->io_dout_value_comboBox->setCurrentText(doutc2.buf[1]);
}

void CommandInput::modify_din_display()
{
    ui->io_din_address_lineEdit->setText(dinc2.buf[0]);
    ui->io_din_number_lineEdit->setText(dinc2.buf[1]);
}

void CommandInput::modify_pause_display()
{
    if(pausec2.buf[0]=="1")
    {
        ui->pause_if_checkBox->setChecked(true);
    }
    else
    {
        ui->pause_if_checkBox->setChecked(false);
    }
    ui->pause_vartype_comboBox->setCurrentText(pausec2.buf[1]);
    ui->pause_varaddress_lineEdit->setText(pausec2.buf[2]);
    ui->pause_comparesign_comboBox->setCurrentText(pausec2.buf[3]);
    if(pausec2.buf[1]=="DOUT"||pausec2.buf[1]=="DIN")
    {
        ui->pause_comparevalue2_comboBox->setCurrentText(pausec2.buf[4]);
    }
    else
    {
        ui->pause_comparevalue1_lineEdit->setText(pausec2.buf[4]);
    }
}
void CommandInput::modify_timer_display()
{
    ui->time_value_lineEdit->setText(timec2);
}

void CommandInput::modify_jump_display()
{
    ui->jump_labelnumber_lineEdit->setText(jumpc2.buf[0]);
    if(jumpc2.buf[1]=="1")
    {
        ui->jump_if_checkBox->setChecked(true);
    }
    else
    {
        ui->jump_if_checkBox->setChecked(false);
    }
    ui->jump_vartype_comboBox->setCurrentText(jumpc2.buf[2]);
    ui->jump_varaddress_lineEdit->setText(jumpc2.buf[3]);
    ui->jump_comparesign_comboBox->setCurrentText(jumpc2.buf[4]);
    if(jumpc2.buf[2]=="DOUT"||jumpc2.buf[2]=="DIN")
    {
        ui->jump_comparevalue2_comboBox->setCurrentText(jumpc2.buf[5]);
    }
    else
    {
        ui->jump_comparevalue1_lineEdit->setText(jumpc2.buf[5]);
    }
}

void CommandInput::modify_label_display()
{
    ui->label_lineEdit->setText(LabelCommand2);
}

void CommandInput::modify_call_display()
{
    ui->call_filename_lineEdit->setText(callc2.buf[0]);
    if(callc2.buf[1]=="1")
    {
        ui->call_if_checkBox->setChecked(true);
    }
    else
    {
        ui->call_if_checkBox->setChecked(false);
    }
    ui->call_vartype_comboBox->setCurrentText(callc2.buf[2]);
    ui->call_varaddress_lineEdit->setText(callc2.buf[3]);
    ui->call_comparesign_comboBox->setCurrentText(callc2.buf[4]);
        if(callc2.buf[2]=="DOUT"||callc2.buf[2]=="DIN")
        {
            ui->call_comparevalue2_comboBox->setCurrentText(callc2.buf[5]);
        }
        else
        {

            ui->call_comparevalue1_lineEdit->setText(callc2.buf[5]);
        }
}

void CommandInput::modify_ret_display()
{
    if(retc2.buf[0]=="1")
    {
        ui->ret_if_checkBox->setChecked(true);
    }
    else
    {
        ui->ret_if_checkBox->setChecked(false);
    }

    ui->ret_vartype_comboBox->setCurrentText(retc2.buf[1]);
    ui->ret_varaddress_lineEdit->setText(retc2.buf[2]);
    ui->ret_comparesign_comboBox->setCurrentText(retc2.buf[3]);
        if(retc2.buf[1]=="DOUT"||retc2.buf[1]=="DIN")
        {
            ui->ret_comparevalue2_comboBox->setCurrentText(retc2.buf[4]);
        }
        else
        {
            ui->ret_comparevalue1_lineEdit->setText(retc2.buf[4]);
        }
}


//插入控制命令-用类的函数的方式去实现插入操作但是操作对象的语句未执行
/*void CommandInput::input_insert_command(int index)
{
    qDebug("inset command success");
    if(select_input_command=="MOVJ")
    {
        bool movj_until;
        bool movj_nwaitcheck;
        QString movj_buf[12];
        movj_buf[1] = ui->lineEdit_movj_vj->text();
        movj_buf[2] = ui->comboBox_movj_pl->currentText();
        movj_until  = ui->checkBox_movj_nutil->isChecked();
        movj_buf[3] = QString::number(movj_until);
        movj_buf[4] = ui->comboBox_movj_ioselect->currentText();
        movj_buf[5] = ui->lineEdit_movj_ionumber->text();
        movj_buf[6] = ui->comboBox_movj_ioprepare->currentText();
        movj_buf[7] = ui->lineEdit_movj_iovalue->text();
        movj_buf[8] = ui->comboBox_movj_ioio->currentText();
        movj_buf[9] = ui->lineEdit_movj_acc->text();
        movj_buf[10] = ui->lineEdit_movj_dec->text();
        movj_nwaitcheck = ui->checkBox_movj_nwait->isChecked();
        movj_buf[11] = QString::number(movj_nwaitcheck);
        movj_buf[0] = ui->comboBox_movj_position->currentText();


        for(int i=0;i<12;i++)
        {
            movjc1.buf[i]=movj_buf[i];
        }
        xmlcancle->insert_MOVJ_command(movjc1,program_filename,index);
    }
    else if(select_input_command=="MOVL")
    {
        bool movl_until;
        bool movl_nwaitcheck;
        bool movl_usr;
        bool movl_tool;
        QString movl_buf[18];
        movl_buf[1] = ui->lineEdit_movl_vl->text();
        movl_buf[2] = ui->lineEdit_movl_vr->text();
        movl_buf[3] = ui->comboBox_movl_pl->currentText();
        movl_until  = ui->checkBox_movl_nutil->isChecked();
        movl_buf[4] = QString::number(movl_until);
        movl_buf[5] = ui->comboBox_movl_ioselect->currentText();
        movl_buf[6] = ui->lineEdit_movl_ionumber->text();
        movl_buf[7] = ui->comboBox_movl_ioprepare->currentText();
        movl_buf[8] = ui->lineEdit_movl_iovalue->text();
        movl_buf[9] = ui->comboBox_movl_ioio->currentText();

        movl_buf[10] = ui->lineEdit_movl_acc->text();
        movl_buf[11] = ui->lineEdit_movl_dec->text();
        movl_buf[12] = ui->lineEdit_movl_cr->text();
        movl_nwaitcheck = ui->checkBox_movl_nwait->isChecked();
        movl_buf[13] = QString::number(movl_nwaitcheck);

        movl_usr = ui->checkBox_movl_usr->isChecked();
        movl_buf[14] = QString::number(movl_usr);
        movl_buf[15] = ui->comboBox_movl_usr->currentText();

        movl_tool = ui->checkBox_movl_tool->isChecked();
        movl_buf[16] = QString::number(movl_tool);
        movl_buf[17] = ui->comboBox_movl_tool->currentText();

        movl_buf[0] = ui->comboBox_movl_position->currentText();
        for(int i=0;i<18;i++)
        {
            movlc1.buf[i]=movl_buf[i];
        }
        xmlcancle->insert_MOVL_command(movlc1,program_filename,index);
    }
    else if(select_input_command=="MOVC")
    {
        bool movc_until;
        bool movc_nwaitcheck;
        bool movc_usr;
        bool movc_tool;
        QString movc_buf[18];
        movc_buf[1] = ui->lineEdit_movc_vl->text();
        movc_buf[2] = ui->lineEdit_movc_vr->text();
        movc_buf[3] = ui->comboBox_movc_pl->currentText();
        movc_until  = ui->checkBox_movc_nuitl->isChecked();
        movc_buf[4] = QString::number(movc_until);
        movc_buf[5] = ui->comboBox_movc_ioselect->currentText();
        movc_buf[6] = ui->lineEdit_movc_ionumber->text();
        movc_buf[7] = "null";//ui->comboBox_movc_ioprepare->currentText();
        movc_buf[8] = "null";//ui->lineEdit_movl_iovalue->text();
        movc_buf[9] = ui->comboBox_movc_ioio->currentText();
        movc_buf[10] = ui->lineEdit_movc_acc->text();
        movc_buf[11] = ui->lineEdit_movc_dec->text();
        movc_buf[12] = ui->lineEdit_movc_cr->text();
        movc_nwaitcheck = ui->checkBox_movc_nwait->isChecked();
        movc_buf[13] = QString::number(movc_nwaitcheck);

        movc_usr = ui->checkBox_movc_usr->isChecked();
        movc_buf[14] = QString::number(movc_usr);
        movc_buf[15] = ui->comboBox_movc_usr->currentText();

        movc_tool = ui->checkBox_movc_tool->isChecked();
        movc_buf[16] = QString::number(movc_tool);
        movc_buf[17] = ui->comboBox_movc_tool->currentText();

        movc_buf[0] = ui->comboBox_movc_position->currentText();
        for(int i=0;i<18;i++)
        {
            movcc1.buf[i]=movc_buf[i];
        }
        xmlcancle->insert_MOVC_command(movcc1,program_filename,index);
    }
    else if(select_input_command=="SPEED")
    {
        QString speed_buf[3];
        speed_buf[0] = ui->comboBox_speed_vstyle->currentText();
        speed_buf[1] = ui->lineEdit_speed_value->text();
        speed_buf[2] = ui->lineEdit_speed_acc->text();
        for(int i=0;i<3;i++)
        {
            speedc1.buf[i]=speed_buf[i];
        }
        for(int j=0;j<3;j++)
        {
            qDebug()<<j<<speed_buf[j];
        }
        xmlcancle->insert_speed_command(speedc1,program_filename,index);
        qDebug("inset progran ok");
    }
}*/

void CommandInput::on_mojpositioneditpushButton_clicked()
{
   posate->show();
}
//movj确定按钮发送将movj命令写入xml文件并且显示到程序编辑器的信号
void CommandInput::on_pushButton_movj_ensure_clicked()
{

    bool movj_until;
    bool movj_nwaitcheck;
    QString movj_buf[12];
    movj_buf[1] = ui->lineEdit_movj_vj->text();
    movj_buf[2] = ui->comboBox_movj_pl->currentText();
    movj_until  = ui->checkBox_movj_nutil->isChecked();
    movj_buf[3] = QString::number(movj_until);
    movj_buf[4] = ui->comboBox_movj_ioselect->currentText();
    movj_buf[5] = ui->lineEdit_movj_ionumber->text();
    movj_buf[6] = ui->comboBox_movj_ioprepare->currentText();
    movj_buf[7] = ui->lineEdit_movj_iovalue->text();
    movj_buf[8] = ui->comboBox_movj_ioio->currentText();
    movj_buf[9] = ui->lineEdit_movj_acc->text();
    movj_buf[10] = ui->lineEdit_movj_dec->text();
    movj_nwaitcheck = ui->checkBox_movj_nwait->isChecked();
    movj_buf[11] = QString::number(movj_nwaitcheck);
    movj_buf[0] = ui->comboBox_movj_position->currentText();


    for(int i=0;i<12;i++)
    {
        movjc1.buf[i]=movj_buf[i];
    }
    //将命令数据发送到编辑器显示
    emit movj_ensure_sig(movj_buf);

    //qDebug("movjsig");
    //调用xml写入函数写入控制命令
    xmlcancle->input_MOVJ_command(movjc1,program_filename);
    //qDebug("input_xml");


}

void CommandInput::on_pushButton_TEST_clicked()
{
    //emit movl_ensure_sig();
    //emit movj_ensure_sig();
}

void CommandInput::on_pushButton_movl_ensure_pressed()
{
    bool movl_until;
    bool movl_nwaitcheck;
    bool movl_usr;
    bool movl_tool;
    QString movl_buf[18];
    movl_buf[1] = ui->lineEdit_movl_vl->text();
    movl_buf[2] = ui->lineEdit_movl_vr->text();
    movl_buf[3] = ui->comboBox_movl_pl->currentText();
    movl_until  = ui->checkBox_movl_nutil->isChecked();
    movl_buf[4] = QString::number(movl_until);
    movl_buf[5] = ui->comboBox_movl_ioselect->currentText();
    movl_buf[6] = ui->lineEdit_movl_ionumber->text();
    movl_buf[7] = ui->comboBox_movl_ioprepare->currentText();
    movl_buf[8] = ui->lineEdit_movl_iovalue->text();
    movl_buf[9] = ui->comboBox_movl_ioio->currentText();

    movl_buf[10] = ui->lineEdit_movl_acc->text();
    movl_buf[11] = ui->lineEdit_movl_dec->text();
    movl_buf[12] = ui->lineEdit_movl_cr->text();
    movl_nwaitcheck = ui->checkBox_movl_nwait->isChecked();
    movl_buf[13] = QString::number(movl_nwaitcheck);

    movl_usr = ui->checkBox_movl_usr->isChecked();
    movl_buf[14] = QString::number(movl_usr);
    movl_buf[15] = ui->comboBox_movl_usr->currentText();

    movl_tool = ui->checkBox_movl_tool->isChecked();
    movl_buf[16] = QString::number(movl_tool);
    movl_buf[17] = ui->comboBox_movl_tool->currentText();

    movl_buf[0] = ui->comboBox_movl_position->currentText();
    for(int i=0;i<18;i++)
    {
        movlc1.buf[i]=movl_buf[i];
    }
    emit movl_ensure_sig(movl_buf);
    xmlcancle->input_MOVL_command(movlc1,program_filename);
}



void CommandInput::on_pushButton_movc_ensure_pressed()
{
    bool movc_until;
    bool movc_nwaitcheck;
    bool movc_usr;
    bool movc_tool;
    QString movc_buf[18];
    movc_buf[1] = ui->lineEdit_movc_vl->text();
    movc_buf[2] = ui->lineEdit_movc_vr->text();
    movc_buf[3] = ui->comboBox_movc_pl->currentText();
    movc_until  = ui->checkBox_movc_nuitl->isChecked();
    movc_buf[4] = QString::number(movc_until);
    movc_buf[5] = ui->comboBox_movc_ioselect->currentText();
    movc_buf[6] = ui->lineEdit_movc_ionumber->text();
    movc_buf[7] = "=";//ui->comboBox_movc_ioprepare->currentText();
    movc_buf[8] = "null";//ui->lineEdit_movl_iovalue->text();
    movc_buf[9] = ui->comboBox_movc_ioio->currentText();
    movc_buf[10] = ui->lineEdit_movc_acc->text();
    movc_buf[11] = ui->lineEdit_movc_dec->text();
    movc_buf[12] = ui->lineEdit_movc_cr->text();
    movc_nwaitcheck = ui->checkBox_movc_nwait->isChecked();
    movc_buf[13] = QString::number(movc_nwaitcheck);

    movc_usr = ui->checkBox_movc_usr->isChecked();
    movc_buf[14] = QString::number(movc_usr);
    movc_buf[15] = ui->comboBox_movc_usr->currentText();

    movc_tool = ui->checkBox_movc_tool->isChecked();
    movc_buf[16] = QString::number(movc_tool);
    movc_buf[17] = ui->comboBox_movc_tool->currentText();

    movc_buf[0] = ui->comboBox_movc_position->currentText();
    for(int i=0;i<18;i++)
    {
        movcc1.buf[i]=movc_buf[i];
    }
    emit movc_ensure_sig(movc_buf);
    xmlcancle->input_MOVC_command(movcc1,program_filename);
}

void CommandInput::on_pushButton_speed_ensure_pressed()
{
    QString speed_buf[3];
    speed_buf[0] = ui->comboBox_speed_vstyle->currentText();
    speed_buf[1] = ui->lineEdit_speed_value->text();
    speed_buf[2] = ui->lineEdit_speed_acc->text();
    for(int i=0;i<3;i++)
    {
        speedc1.buf[i]=speed_buf[i];
    }
    emit speed_ensure_sig(speed_buf);
    xmlcancle->input_speed_command(speedc1,program_filename);
}
void CommandInput::input_insert_slot()
{
    if(select_input_command=="MOVJ")
    {
        bool movj_until;
        bool movj_nwaitcheck;
        QString movj_buf[12];
        movj_buf[1] = ui->lineEdit_movj_vj->text();
        movj_buf[2] = ui->comboBox_movj_pl->currentText();
        movj_until  = ui->checkBox_movj_nutil->isChecked();
        movj_buf[3] = QString::number(movj_until);
        movj_buf[4] = ui->comboBox_movj_ioselect->currentText();
        movj_buf[5] = ui->lineEdit_movj_ionumber->text();
        movj_buf[6] = ui->comboBox_movj_ioprepare->currentText();
        movj_buf[7] = ui->lineEdit_movj_iovalue->text();
        movj_buf[8] = ui->comboBox_movj_ioio->currentText();
        movj_buf[9] = ui->lineEdit_movj_acc->text();
        movj_buf[10] = ui->lineEdit_movj_dec->text();
        movj_nwaitcheck = ui->checkBox_movj_nwait->isChecked();
        movj_buf[11] = QString::number(movj_nwaitcheck);
        movj_buf[0] = ui->comboBox_movj_position->currentText();


        for(int i=0;i<12;i++)
        {
            movjc1.buf[i]=movj_buf[i];
        }
        emit input_list_insert_sig(movj_buf);
        //xmlcancle->insert_MOVJ_command(movjc1,program_filename,index);
    }
    else if(select_input_command=="MOVL")
    {
        bool movl_until;
        bool movl_nwaitcheck;
        bool movl_usr;
        bool movl_tool;
        QString movl_buf[18];
        movl_buf[1] = ui->lineEdit_movl_vl->text();
        movl_buf[2] = ui->lineEdit_movl_vr->text();
        movl_buf[3] = ui->comboBox_movl_pl->currentText();
        movl_until  = ui->checkBox_movl_nutil->isChecked();
        movl_buf[4] = QString::number(movl_until);
        movl_buf[5] = ui->comboBox_movl_ioselect->currentText();
        movl_buf[6] = ui->lineEdit_movl_ionumber->text();
        movl_buf[7] = ui->comboBox_movl_ioprepare->currentText();
        movl_buf[8] = ui->lineEdit_movl_iovalue->text();
        movl_buf[9] = ui->comboBox_movl_ioio->currentText();

        movl_buf[10] = ui->lineEdit_movl_acc->text();
        movl_buf[11] = ui->lineEdit_movl_dec->text();
        movl_buf[12] = ui->lineEdit_movl_cr->text();
        movl_nwaitcheck = ui->checkBox_movl_nwait->isChecked();
        movl_buf[13] = QString::number(movl_nwaitcheck);

        movl_usr = ui->checkBox_movl_usr->isChecked();
        movl_buf[14] = QString::number(movl_usr);
        movl_buf[15] = ui->comboBox_movl_usr->currentText();

        movl_tool = ui->checkBox_movl_tool->isChecked();
        movl_buf[16] = QString::number(movl_tool);
        movl_buf[17] = ui->comboBox_movl_tool->currentText();

        movl_buf[0] = ui->comboBox_movl_position->currentText();
        for(int i=0;i<18;i++)
        {
            movlc1.buf[i]=movl_buf[i];
        }
        emit input_list_insert_sig(movl_buf);
    }
    else if(select_input_command=="MOVC")
    {
        bool movc_until;
        bool movc_nwaitcheck;
        bool movc_usr;
        bool movc_tool;
        QString movc_buf[18];
        movc_buf[1] = ui->lineEdit_movc_vl->text();
        movc_buf[2] = ui->lineEdit_movc_vr->text();
        movc_buf[3] = ui->comboBox_movc_pl->currentText();
        movc_until  = ui->checkBox_movc_nuitl->isChecked();
        movc_buf[4] = QString::number(movc_until);
        movc_buf[5] = ui->comboBox_movc_ioselect->currentText();
        movc_buf[6] = ui->lineEdit_movc_ionumber->text();
        movc_buf[7] = "null";//ui->comboBox_movc_ioprepare->currentText();
        movc_buf[8] = "null";//ui->lineEdit_movl_iovalue->text();
        movc_buf[9] = ui->comboBox_movc_ioio->currentText();
        movc_buf[10] = ui->lineEdit_movc_acc->text();
        movc_buf[11] = ui->lineEdit_movc_dec->text();
        movc_buf[12] = ui->lineEdit_movc_cr->text();
        movc_nwaitcheck = ui->checkBox_movc_nwait->isChecked();
        movc_buf[13] = QString::number(movc_nwaitcheck);

        movc_usr = ui->checkBox_movc_usr->isChecked();
        movc_buf[14] = QString::number(movc_usr);
        movc_buf[15] = ui->comboBox_movc_usr->currentText();

        movc_tool = ui->checkBox_movc_tool->isChecked();
        movc_buf[16] = QString::number(movc_tool);
        movc_buf[17] = ui->comboBox_movc_tool->currentText();

        movc_buf[0] = ui->comboBox_movc_position->currentText();
        for(int i=0;i<18;i++)
        {
            movcc1.buf[i]=movc_buf[i];
        }
        emit input_list_insert_sig(movc_buf);

    }
    else if(select_input_command=="SPEED")
    {
        QString speed_buf[3];
        speed_buf[0] = ui->comboBox_speed_vstyle->currentText();
        speed_buf[1] = ui->lineEdit_speed_value->text();
        speed_buf[2] = ui->lineEdit_speed_acc->text();
        for(int i=0;i<3;i++)
        {
            speedc1.buf[i]=speed_buf[i];
        }
        emit input_list_insert_sig(speed_buf);
    }
    else if(select_input_command=="DOUT")
    {
        QString dout_buf[2];
        dout_buf[0] = ui->io_dout_address_lineEdit->text();
        dout_buf[1] = ui->io_dout_value_comboBox->currentText();
        for(int i=0;i<2;i++)
        {
            doutc1.buf[i] = dout_buf[i];
        }
        emit input_list_insert_sig(dout_buf);
    }
    else if(select_input_command=="DIN")
    {
        QString din_buf[2];
        din_buf[0] = ui->io_din_address_lineEdit->text();
        din_buf[1] = ui->io_din_number_lineEdit->text();
        for(int i=0;i<2;i++)
        {
            dinc1.buf[i] = din_buf[i];
        }
        emit input_list_insert_sig(din_buf);
    }
    else if(select_input_command=="PAUSE")
    {
        QString pause_buf[5];
        bool if_check;
        if_check = ui->pause_if_checkBox->isChecked();
        pause_buf[0] = QString::number(if_check);
        pause_buf[1] = ui->pause_vartype_comboBox->currentText();
        pause_buf[2] = ui->pause_varaddress_lineEdit->text();
        pause_buf[3] = ui->pause_comparesign_comboBox->currentText();
        if(pause_buf[1]=="DOUT"||pause_buf[1]=="DIN")
        {
            pause_buf[4] = ui->pause_comparevalue2_comboBox->currentText();
        }
        else
        {
            pause_buf[4] = ui->pause_comparevalue1_lineEdit->text();
        }
        for(int i=0;i<5;i++)
        {
            pausec1.buf[i]=pause_buf[i];
        }
        emit input_list_insert_sig(pause_buf);
    }
    else if(select_input_command=="TIMER")
    {
        QString timer_buf;
        timer_buf=ui->time_value_lineEdit->text();
        timec1 = timer_buf;
        emit input_list_insert_sig(&timer_buf);
    }
    else if(select_input_command=="JUMP")
    {
        QString jump_buf[6];
        bool if_jump;
        jump_buf[0] = ui->jump_labelnumber_lineEdit->text();
        if_jump = ui->jump_if_checkBox->isChecked();
        jump_buf[1] = QString::number(if_jump);
        jump_buf[2] = ui->jump_vartype_comboBox->currentText();
        jump_buf[3] = ui->jump_varaddress_lineEdit->text();
        jump_buf[4] = ui->jump_comparesign_comboBox->currentText();
        if(jump_buf[2]=="DOUT"||jump_buf[2]=="DIN")
        {
            jump_buf[5] = ui->jump_comparevalue2_comboBox->currentText();
        }
        else
        {
            jump_buf[5] = ui->jump_comparevalue1_lineEdit->text();
        }
        for(int i=0;i<6;i++)
        {
            jumpc1.buf[i]=jump_buf[i];
        }
        emit input_list_insert_sig(jump_buf);
    }
    else if(select_input_command=="LABEL")
    {
        QString label_buf;
        label_buf = ui->label_lineEdit->text();
        LabelCommand1 = label_buf;
        emit input_list_insert_sig(&label_buf);
    }
    else if(select_input_command=="CALL")
    {
        QString call_buf[6];
        bool if_call;
        call_buf[0] = ui->call_filename_lineEdit->text();
        if_call = ui->call_if_checkBox->isChecked();
        call_buf[1] = QString::number(if_call);
        call_buf[2] = ui->call_vartype_comboBox->currentText();
        call_buf[3] = ui->call_varaddress_lineEdit->text();
        if(call_buf[1]=="DOUT"||call_buf[1]=="DIN")
        {
            call_buf[4] = "=";
            call_buf[5] = ui->call_comparevalue2_comboBox->currentText();
        }
        else
        {
            call_buf[4] = ui->call_comparesign_comboBox->currentText();
            call_buf[5] = ui->call_comparevalue1_lineEdit->text();
        }
        for(int i=0;i<6;i++)
        {
            callc1.buf[i] = call_buf[i];
        }
        emit input_list_insert_sig(call_buf);
    }
    else if(select_input_command=="RET")
    {
        QString ret_buf[5];
        bool if_ret;
        if_ret = ui->ret_if_checkBox->isChecked();
        ret_buf[0] = QString::number(if_ret);
        ret_buf[1] = ui->ret_vartype_comboBox->currentText();
        ret_buf[2] = ui->ret_varaddress_lineEdit->text();
        ret_buf[3] = ui->ret_comparesign_comboBox->currentText();
        if(ret_buf[1]=="DOUT"||ret_buf[1]=="DIN")
        {
            ret_buf[4] = ui->ret_comparevalue2_comboBox->currentText();
        }
        else
        {
            ret_buf[4] = ui->ret_comparevalue1_lineEdit->text();
        }
        for(int i=0;i<5;i++)
        {
            retc1.buf[i] = ret_buf[i];
        }
        emit input_list_insert_sig(ret_buf);
    }

}

void CommandInput::refresh_posi_vari_slot()
{
    qDebug()<<"select_input_command=="<<select_input_command;
    if(select_input_command=="MOVJ")
    {
        ui->comboBox_movj_position->clear();
        ui->comboBox_movj_position->addItems(posi_vari_point);
        //ui->comboBox_movj_position->insertItems(0,posi_vari_point);
        //ui->comboBox_movj_position->clear();
    }
    else if(select_input_command=="MOVL")
    {
        ui->comboBox_movl_position->clear();
        ui->comboBox_movl_position->addItems(posi_vari_point);
    }
    else if(select_input_command=="MOVC")
    {
        ui->comboBox_movc_position->clear();
        ui->comboBox_movc_position->addItems(posi_vari_point);
    }
}

void CommandInput::on_pushButton_movl_editpotiion_clicked()
{
    posate->show();
}

void CommandInput::on_pushButton_movc_editposition_clicked()
{
    posate->show();
}

void CommandInput::on_io_dout_ensure_pushButton_clicked()
{
    QString dout_buf[2];
    dout_buf[0] = ui->io_dout_address_lineEdit->text();
    dout_buf[1] = ui->io_dout_value_comboBox->currentText();

    doutc1.buf[0] = dout_buf[0];
    doutc1.buf[1] = dout_buf[1];
    //display dout command
    emit dout_ensure_sig(dout_buf);
    //write dout command
    xmlcancle->input_DOUT_command(doutc1,program_filename);

}

void CommandInput::on_io_din_ensure_pushButton_clicked()
{
    QString din_buf[2];
    din_buf[0] = ui->io_din_address_lineEdit->text();
    din_buf[1] = ui->io_din_number_lineEdit->text();
    dinc1.buf[0] = din_buf[0];
    dinc1.buf[1] = din_buf[1];
    emit din_ensure_sig(din_buf);
    xmlcancle->input_DIN_command(dinc1,program_filename);
}

void CommandInput::on_pause_ensure_pushButton_clicked()
{
    QString pause_buf[5];
    bool if_check;
    if_check = ui->pause_if_checkBox->isChecked();
    pause_buf[0] = QString::number(if_check);
    pause_buf[1] = ui->pause_vartype_comboBox->currentText();
    pause_buf[2] = ui->pause_varaddress_lineEdit->text();
    pause_buf[3] = ui->pause_comparesign_comboBox->currentText();
    if(pause_buf[1]=="DOUT"||pause_buf[1]=="DIN")
    {
        pause_buf[4] = ui->pause_comparevalue2_comboBox->currentText();
    }
    else
    {
        pause_buf[4] = ui->pause_comparevalue1_lineEdit->text();
    }
    for(int i=0;i<5;i++)
    {
        pausec1.buf[i]=pause_buf[i];
    }
    emit pause_ensure_sig(pause_buf);
    xmlcancle->input_PAUSE_command(pausec1,program_filename);
}

void CommandInput::on_timer_ensure_pushButton_clicked()
{
    QString timer_buf;
    timer_buf=ui->time_value_lineEdit->text();
    timec1 = timer_buf;
    emit timer_ensure_sig(timer_buf);
    xmlcancle->input_TIMER_command(timec1,program_filename);
}

void CommandInput::on_jump_ensure_pushButton_clicked()
{
    QString jump_buf[6];
    bool if_jump;
    jump_buf[0] = ui->jump_labelnumber_lineEdit->text();
    if_jump = ui->jump_if_checkBox->isChecked();
    jump_buf[1] = QString::number(if_jump);
    jump_buf[2] = ui->jump_vartype_comboBox->currentText();
    jump_buf[3] = ui->jump_varaddress_lineEdit->text();
    jump_buf[4] = ui->jump_comparesign_comboBox->currentText();
    if(jump_buf[2]=="DOUT"||jump_buf[2]=="DIN")
    {
        jump_buf[5] = ui->jump_comparevalue2_comboBox->currentText();
    }
    else
    {
        jump_buf[5] = ui->jump_comparevalue1_lineEdit->text();
    }
    for(int i=0;i<6;i++)
    {
        jumpc1.buf[i]=jump_buf[i];
    }
    emit jump_ensure_sig(jump_buf);
    xmlcancle->input_JUMP_command(jumpc1,program_filename);
}

void CommandInput::on_label_ensure_pushButton_clicked()
{
    QString label_buf;
    label_buf = ui->label_lineEdit->text();
    LabelCommand1 = label_buf;
    emit label_ensure_sig(label_buf);
    xmlcancle->input_LABEL_command(LabelCommand1,program_filename);
}

void CommandInput::on_call_ensure_pushButton_clicked()
{
    QString call_buf[6];
    bool if_call;
    call_buf[0] = ui->call_filename_lineEdit->text();
    if_call = ui->call_if_checkBox->isChecked();
    call_buf[1] = QString::number(if_call);
    call_buf[2] = ui->call_vartype_comboBox->currentText();
    call_buf[3] = ui->call_varaddress_lineEdit->text();
    if(call_buf[1]=="DOUT"||call_buf[1]=="DIN")
    {
        call_buf[4] = "=";
        call_buf[5] = ui->call_comparevalue2_comboBox->currentText();
    }
    else
    {
        call_buf[4] = ui->call_comparesign_comboBox->currentText();
        call_buf[5] = ui->call_comparevalue1_lineEdit->text();
    }
    for(int i=0;i<6;i++)
    {
        callc1.buf[i] = call_buf[i];
    }
    emit call_ensure_sig(call_buf);
    xmlcancle->input_CALL_command(callc1,program_filename);
}

void CommandInput::on_ret_ensure_pushButton_clicked()
{
    QString ret_buf[5];
    bool if_ret;
    if_ret = ui->ret_if_checkBox->isChecked();
    ret_buf[0] = QString::number(if_ret);
    ret_buf[1] = ui->ret_vartype_comboBox->currentText();
    ret_buf[2] = ui->ret_varaddress_lineEdit->text();
    ret_buf[3] = ui->ret_comparesign_comboBox->currentText();
    if(ret_buf[1]=="DOUT"||ret_buf[1]=="DIN")
    {
        ret_buf[4] = ui->ret_comparevalue2_comboBox->currentText();
    }
    else
    {
        ret_buf[4] = ui->ret_comparevalue1_lineEdit->text();
    }
    for(int i=0;i<5;i++)
    {
        retc1.buf[i] = ret_buf[i];
    }
    emit ret_ensure_sig(ret_buf);
    xmlcancle->input_RET_command(retc1,program_filename);
}
