#ifndef SIMULATIONKEYPAD_H
#define SIMULATIONKEYPAD_H

#include <QWidget>
#include "commandlist.h"
#include "usr_motion_api/usr_motion_api.h"

namespace Ui {
class SimulationKeypad;
}

class SimulationKeypad : public QWidget
{
    Q_OBJECT

public:
    explicit SimulationKeypad(QWidget *parent = 0);
    ~SimulationKeypad();

private slots:
    void on_commandviewpushButton_clicked();

    void on_pushButton_emer_stop_clicked();

    void movj_simula_slot(QString *);
    void movl_simula_slot(QString *);
    void movc_simula_slot(QString *);
    void speed_simula_slot(QString *);
    void dout_simula_slot(QString *);

    void on_pushButton_simu_up_clicked();

    void on_pushButton_simu_down_clicked();

    void on_pushButton_simu_delete_pressed();

    void on_pushButton_simu_insert_pressed();

    //插入槽
    void simu_main_insert_slot(QString *);

    void on_pushButton_simu_modify_pressed();
    void on_pushButton_simu_ensure_pressed();


    void on_pushButton_simu_sevoenabe_clicked();

    void on_pushButton_simu_stop_clicked();

    void on_pushButton_simu_clear_clicked();

    void on_pushButton_simu_j1p_pressed();

    void on_pushButton_simu_j1p_released();

    void on_pushButton_j2p_pressed();

    void on_pushButton_j2p_released();

    void on_pushButton_simu_j3p_pressed();

    void on_pushButton_simu_j3p_released();

    void on_pushButton_j4p_pressed();

    void on_pushButton_j4p_released();

    void on_pushButton_j5p_pressed();

    void on_pushButton_j5p_released();

    void on_pushButton_j6p_pressed();

    void on_pushButton_j6p_released();

    void on_pushButton_simu_j1n_pressed();

    void on_pushButton_simu_j1n_released();

    void on_pushButton_simu_j2n_pressed();

    void on_pushButton_simu_j2n_released();

    void on_pushButton_simu_j3n_pressed();

    void on_pushButton_simu_j3n_released();

    void on_pushButton_simu_j4n_pressed();

    void on_pushButton_simu_j4n_released();

    void on_pushButton_j5n_pressed();

    void on_pushButton_j5n_released();

    void on_pushButton_j6n_pressed();

    void on_pushButton_j6n_released();

    void on_pushButton_simu_SingleSP_pressed();

    void on_pushButton_simu_SingleSP_released();

    void on_pushButton_simu_SingleSN_pressed();

    void on_pushButton_simu_SingleSN_released();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_simu_movj_zero_clicked();

    void on_pushButton_simu_MultiSP_pressed();

    void on_pushButton_simu_MultiSP_released();

    void on_pushButton_simu_MultiSN_pressed();

    void on_pushButton_simu_MultiSN_released();

    void on_pushButton_simu_test_run_pressed();

    void on_pushButton_simu_test_run_released();

    void on_pushButton_simu_run_clicked();

    void on_pushButton_simu_closelist_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_close_list_clicked();

    void on_pushButton_close_input_clicked();

    void on_pushButton_simu_start_clicked();

private:
    Ui::SimulationKeypad *ui;
    CommandList *commandlist;

signals:
    void moni_test_sig();//模拟测试信号
    void movj_simula_slot_sig(QString *);//movj输入信号
    void movl_simula_slot_sig(QString *);
    void movc_simula_slot_sig(QString *);
    void speed_simula_slot_sig(QString *);
    void dout_simula_slot_sig(QString *);
    void din_simula_slot_sig(QString *);
    void pause_simula_slot_sig(QString *);
    void timer_simula_slot_sig(QString);
    void jump_simula_slot_sig(QString *);
    void label_simula_slot_sig(QString);
    void call_simula_slot_sig(QString *);
    void ret_simula_slot_sig(QString *);


    void simu_up_sig();//光标上信号(模拟键盘上信号)
    void simu_down_sig();//光标下信号（模拟键盘下信号）
    void simu_delete_sig();//删除信号
    void simu_insert_sig();//插入命令
    void simu_main_insert_sig(QString *);//
    void simu_main_modify_sig();//获取修改数据信号
    //void simu_list_modify_sig();//显示修改数据

    void send_current_line_sig();//next step
    void send_single_backward_sig();//single_backward
    void simu_MultiSP_sig();//Multi step p
    void simu_MultiSP_release_sig();//multi step positive-going release
    void simu_MultiSN_sig();//Multi step n
    void simu_MultiSN_release_sig(); //Multi step backward release

    //stop timer1 sig()
    void simu_stop_timer1_sig();
    //test_run_sig
    void simu_test_run_sig();

    void close_input_sig();

    //start button sig
    void simu_restart_sig();
    //pause sig
    void simu_pause_sig();


};

#endif // SIMULATIONKEYPAD_H
