#ifndef EDITKEYBOARD_H
#define EDITKEYBOARD_H
#include <QLineEdit>
#include <QWidget>
//#include "keyboard.h"

class KeyBoard;

class EditKeyboard : public QLineEdit
{
    Q_OBJECT
public:
    EditKeyboard(QWidget *parent=0);
    virtual void focusInEvent(QFocusEvent *event);

signals:
    void editSignal();
    void send_current_str_sig(QString);
private slots:
    void showkeyboard();
    void disstr(QString);
    void remove_last_character_slot();
    void remove_all_slot();
private:
    KeyBoard *keyboard ;


};

#endif // EDITKEYBOARD_H
