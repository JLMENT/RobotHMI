#include "editkeyboard.h"
#include "keyboard.h"
#include <QDebug>
#include <QTextEdit>

EditKeyboard::EditKeyboard(QWidget *parent)
{

    setFocusPolicy(Qt::ClickFocus);
    connect(this,SIGNAL(editSignal()),this,SLOT(showkeyboard()));

}

void EditKeyboard::focusInEvent(QFocusEvent *event)
{

    clearFocus();
    //emit send_current_str_sig(this->text());
    emit editSignal();
    //clearFocus();
    QLineEdit::focusInEvent(event);
}

void EditKeyboard::showkeyboard()
{
    keyboard = new KeyBoard;
    //keyboard->show();
    connect(keyboard,SIGNAL(sendstr(QString)),this,SLOT(disstr(QString)));
    connect(keyboard,SIGNAL(remove_last_character_sig()),this,SLOT(remove_last_character_slot()));
    connect(keyboard,SIGNAL(remove_all_sig()),this,SLOT(remove_all_slot()));
    connect(this,SIGNAL(send_current_str_sig(QString)),keyboard,SLOT(display_edit_str_slot(QString)));
    emit send_current_str_sig(this->text());
    //emit send_current_str_sig(this->text());
    keyboard->exec();
//    connect(keyboard,SIGNAL(sendstr(QString)),this,SLOT(disstr(QString)));
//    connect(keyboard,SIGNAL(remove_last_character_sig()),this,SLOT(remove_last_character_slot()));
//    connect(keyboard,SIGNAL(remove_all_sig()),this,SLOT(remove_all_slot()));
}
void EditKeyboard::disstr(QString str)
{
    this->setText(this->text()+str);
}

void EditKeyboard::remove_last_character_slot()
{
    QString str = this->text();
    str.chop(1);
    this->setText(str);
}

void EditKeyboard::remove_all_slot()
{
    this->clear();
}
