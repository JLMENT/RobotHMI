#ifndef DIGITKEYDIALOG_H
#define DIGITKEYDIALOG_H

#include <QDialog>
#include "keyboard.h"
#include "digetedit.h"

namespace Ui {
class DigitKeyDialog;
}

class DigitKeyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DigitKeyDialog(QWidget *parent = 0);
    ~DigitKeyDialog();

private slots:
    void on_pushButton_10_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_dot_clicked();

    void on_pushButton_backspace_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_ensure_clicked();

    void on_pushButton_cancle_clicked();

    void display_edit_str_slot(QString);

private:
    Ui::DigitKeyDialog *ui;
    DigetEdit *editkeyboard = new DigetEdit;

signals:
    void sendstr(QString);
    void remove_last_character_sig();
    void remove_all_sig();
};

#endif // DIGITKEYDIALOG_H
