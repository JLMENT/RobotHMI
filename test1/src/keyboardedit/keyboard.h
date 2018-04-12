#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include "editkeyboard.h"
#include <QString>
#include <QDialog>

namespace Ui {
class KeyBoard;
}

class KeyBoard : public QDialog
{
    Q_OBJECT

public:
    explicit KeyBoard(QWidget *parent = 0);
    ~KeyBoard();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_dot_clicked();

    void on_pushButton_b_clicked();

    void on_pushButton_underline_clicked();

    void on_pushButton_cancle_clicked();

    void on_pushButton_ensure_clicked();

    void on_pushButton_capsmall_clicked();

    void on_pushButton_backspace_clicked();

    void on_pushButton_clearall_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_q_clicked();

    void on_pushButton_w_clicked();

    void on_pushButton_e_clicked();

    void on_pushButton_r_clicked();

    void on_pushButton_t_clicked();

    void on_pushButton_y_clicked();

    void on_pushButton_u_clicked();

    void on_pushButton_i_clicked();

    void on_pushButton_o_clicked();

    void on_pushButton_p_clicked();

    void on_pushButton_a_clicked();

    void on_pushButton_s_clicked();

    void on_pushButton_d_clicked();

    void on_pushButton_f_clicked();

    void on_pushButton_g_clicked();

    void on_pushButton_h_clicked();

    void on_pushButton_j_clicked();

    void on_pushButton_k_clicked();

    void on_pushButton_l_clicked();

    void on_pushButton_z_clicked();

    void on_pushButton_x_clicked();

    void on_pushButton_c_clicked();

    void on_pushButton_v_clicked();

    void on_pushButton_n_clicked();

    void on_pushButton_m_clicked();

    void display_edit_str_slot(QString);

private:
    Ui::KeyBoard *ui;
    EditKeyboard *editkeyboard = new EditKeyboard;
signals:
    void sendstr(QString);
    void remove_last_character_sig();
    void remove_all_sig();

};

#endif // KEYBOARD_H
