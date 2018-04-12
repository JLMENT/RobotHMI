#include "keyboard.h"
#include "ui_keyboard.h"
#include <QDebug>

KeyBoard::KeyBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KeyBoard)
{
    ui->setupUi(this);
    //connect(editkeyboard,SIGNAL(send_current_str_sig(QString)),this,SLOT(display_edit_str_slot(QString)));

}

KeyBoard::~KeyBoard()
{
    delete ui;
}

void KeyBoard::display_edit_str_slot(QString str)
{
    ui->lineEdit->setText(str);
}

void KeyBoard::on_pushButton_1_clicked()
{
    emit sendstr(ui->pushButton_1->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_1->text());
}

void KeyBoard::on_pushButton_dot_clicked()
{
    emit sendstr(ui->pushButton_dot->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_dot->text());
}

void KeyBoard::on_pushButton_b_clicked()
{
    emit sendstr(ui->pushButton_b->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_b->text());
}

void KeyBoard::on_pushButton_underline_clicked()
{
    emit sendstr(ui->pushButton_underline->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_underline->text());
}

void KeyBoard::on_pushButton_cancle_clicked()
{
    //undo
    emit remove_all_sig();
    this->close();


}

void KeyBoard::on_pushButton_ensure_clicked()
{
    //ensure
    emit remove_all_sig();
    emit sendstr(ui->lineEdit->text());

    this->close();
}

void KeyBoard::on_pushButton_capsmall_clicked()
{
    //caps/small
    static bool capsmall=1;
    if(capsmall)
    {
        ui->pushButton_a->setText("A");
        ui->pushButton_b->setText("B");
        ui->pushButton_c->setText("C");
        ui->pushButton_d->setText("D");
        ui->pushButton_e->setText("E");
        ui->pushButton_f->setText("F");
        ui->pushButton_g->setText("G");
        ui->pushButton_h->setText("H");
        ui->pushButton_i->setText("I");
        ui->pushButton_j->setText("J");
        ui->pushButton_k->setText("K");
        ui->pushButton_l->setText("L");
        ui->pushButton_m->setText("M");
        ui->pushButton_n->setText("N");
        ui->pushButton_o->setText("O");
        ui->pushButton_p->setText("P");
        ui->pushButton_q->setText("Q");
        ui->pushButton_r->setText("R");
        ui->pushButton_s->setText("S");
        ui->pushButton_t->setText("T");
        ui->pushButton_u->setText("U");
        ui->pushButton_v->setText("V");
        ui->pushButton_w->setText("W");
        ui->pushButton_x->setText("X");
        ui->pushButton_y->setText("Y");
        ui->pushButton_z->setText("Z");
        ui->pushButton_capsmall->setText("small");
    }else
    {
        ui->pushButton_a->setText("a");
        ui->pushButton_b->setText("b");
        ui->pushButton_c->setText("c");
        ui->pushButton_d->setText("d");
        ui->pushButton_e->setText("e");
        ui->pushButton_f->setText("f");
        ui->pushButton_g->setText("g");
        ui->pushButton_h->setText("h");
        ui->pushButton_i->setText("i");
        ui->pushButton_j->setText("j");
        ui->pushButton_k->setText("k");
        ui->pushButton_l->setText("l");
        ui->pushButton_m->setText("m");
        ui->pushButton_n->setText("n");
        ui->pushButton_o->setText("o");
        ui->pushButton_p->setText("p");
        ui->pushButton_q->setText("q");
        ui->pushButton_r->setText("r");
        ui->pushButton_s->setText("s");
        ui->pushButton_t->setText("t");
        ui->pushButton_u->setText("u");
        ui->pushButton_v->setText("v");
        ui->pushButton_w->setText("w");
        ui->pushButton_x->setText("x");
        ui->pushButton_y->setText("y");
        ui->pushButton_z->setText("z");
        ui->pushButton_capsmall->setText("CAPS");
    }
    capsmall=!capsmall;
}

void KeyBoard::on_pushButton_backspace_clicked()
{
    emit remove_last_character_sig();
    QString str = ui->lineEdit->text();
    str.chop(1);
    ui->lineEdit->setText(str);
}

void KeyBoard::on_pushButton_clearall_clicked()
{
    emit remove_all_sig();
    ui->lineEdit->clear();
}

void KeyBoard::on_pushButton_2_clicked()
{
    emit sendstr(ui->pushButton_2->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_2->text());
}

void KeyBoard::on_pushButton_3_clicked()
{
    emit sendstr(ui->pushButton_3->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_3->text());
}

void KeyBoard::on_pushButton_4_clicked()
{
    emit sendstr(ui->pushButton_4->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_4->text());
}

void KeyBoard::on_pushButton_5_clicked()
{
    emit sendstr(ui->pushButton_5->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_5->text());
}

void KeyBoard::on_pushButton_6_clicked()
{
    emit sendstr(ui->pushButton_6->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_6->text());
}

void KeyBoard::on_pushButton_7_clicked()
{
    emit sendstr(ui->pushButton_7->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_7->text());
}

void KeyBoard::on_pushButton_8_clicked()
{
    emit sendstr(ui->pushButton_8->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_8->text());
}

void KeyBoard::on_pushButton_9_clicked()
{
    emit sendstr(ui->pushButton_9->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_9->text());
}

void KeyBoard::on_pushButton_10_clicked()
{
    emit sendstr(ui->pushButton_10->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_10->text());
}

void KeyBoard::on_pushButton_q_clicked()
{
    emit sendstr(ui->pushButton_q->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_q->text());
}

void KeyBoard::on_pushButton_w_clicked()
{
    emit sendstr(ui->pushButton_w->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_w->text());
}

void KeyBoard::on_pushButton_e_clicked()
{
    emit sendstr(ui->pushButton_e->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_e->text());
}

void KeyBoard::on_pushButton_r_clicked()
{
    emit sendstr(ui->pushButton_r->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_r->text());
}

void KeyBoard::on_pushButton_t_clicked()
{
    emit sendstr(ui->pushButton_t->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_t->text());
}

void KeyBoard::on_pushButton_y_clicked()
{
    emit sendstr(ui->pushButton_y->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_y->text());
}

void KeyBoard::on_pushButton_u_clicked()
{
    emit sendstr(ui->pushButton_u->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_u->text());
}

void KeyBoard::on_pushButton_i_clicked()
{
    emit sendstr(ui->pushButton_i->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_i->text());
}

void KeyBoard::on_pushButton_o_clicked()
{
    emit sendstr(ui->pushButton_o->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_o->text());
}

void KeyBoard::on_pushButton_p_clicked()
{
    emit sendstr(ui->pushButton_p->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_p->text());
}

void KeyBoard::on_pushButton_a_clicked()
{
    emit sendstr(ui->pushButton_a->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_a->text());
}

void KeyBoard::on_pushButton_s_clicked()
{
    emit sendstr(ui->pushButton_s->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_s->text());
}

void KeyBoard::on_pushButton_d_clicked()
{
    emit sendstr(ui->pushButton_d->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_d->text());
}

void KeyBoard::on_pushButton_f_clicked()
{
    emit sendstr(ui->pushButton_f->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_f->text());
}

void KeyBoard::on_pushButton_g_clicked()
{
    emit sendstr(ui->pushButton_g->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_g->text());
}

void KeyBoard::on_pushButton_h_clicked()
{
    emit sendstr(ui->pushButton_h->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_h->text());
}

void KeyBoard::on_pushButton_j_clicked()
{
    emit sendstr(ui->pushButton_j->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_j->text());
}

void KeyBoard::on_pushButton_k_clicked()
{
    emit sendstr(ui->pushButton_k->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_k->text());
}

void KeyBoard::on_pushButton_l_clicked()
{
    emit sendstr(ui->pushButton_l->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_l->text());
}

void KeyBoard::on_pushButton_z_clicked()
{
    emit sendstr(ui->pushButton_z->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_z->text());
}

void KeyBoard::on_pushButton_x_clicked()
{
    emit sendstr(ui->pushButton_x->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_x->text());
}

void KeyBoard::on_pushButton_c_clicked()
{
    emit sendstr(ui->pushButton_c->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_c->text());
}

void KeyBoard::on_pushButton_v_clicked()
{
    emit sendstr(ui->pushButton_v->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_v->text());
}

void KeyBoard::on_pushButton_n_clicked()
{
    emit sendstr(ui->pushButton_n->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_n->text());
}

void KeyBoard::on_pushButton_m_clicked()
{
    emit sendstr(ui->pushButton_m->text());
    ui->lineEdit->setText(ui->lineEdit->text()+ui->pushButton_m->text());
}
