#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "numeric_type_xml/numerictypexml.h"
#include "digetedit.h"
#include "editkeyboard.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    int up_page_status;
    int down_page_status;
    int page_status;
    int left_change_status;
    int right_change_status;
    int style_status;

private:
    Ui::Form *ui;
    QLineEdit *num_sequence_number[9];// = new QLineEdit;
    //QLineEdit *num_content[9];//= new QLineEdit;
    DigetEdit *num_content[9];
    //QLineEdit *num_name[9];// = new QLineEdit;
    EditKeyboard *num_name[9];
    QPushButton *style_change_left = new QPushButton;
    QPushButton *style_change_right = new QPushButton;
    QLineEdit *style_display = new QLineEdit;
    QPushButton *up_down_button[4];// = new QPushButton;
    QVBoxLayout *vb = new QVBoxLayout;
    QVBoxLayout *vb1 = new QVBoxLayout;
    QVBoxLayout *vb2 = new QVBoxLayout;
    QVBoxLayout *vb3 = new QVBoxLayout;
    QHBoxLayout *hb1 = new QHBoxLayout;
    QHBoxLayout *hb2 = new QHBoxLayout;
    QHBoxLayout *hb3 = new QHBoxLayout;
    QHBoxLayout *hb4 = new QHBoxLayout;

    NumericTypeXml *numerictypexml = new NumericTypeXml;

    void return_start_page();

    void init_number_table();
    void read_number_data(int, int);
    void save_modify_data();
    void cancle_modify_data();

private slots:
    void up_page_slot();
    void down_page_slot();
    void left_change_slot();
    void right_change_slot();
    void save_value_slot();
    void cancle_value_slot();



};

#endif // FORM_H
