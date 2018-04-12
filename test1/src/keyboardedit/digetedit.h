#ifndef DIGETEDIT_H
#define DIGETEDIT_H
#include <QLineEdit>
#include <QWidget>
//#include "editkeyboard.h"

class DigitKeyDialog;
class DigetEdit : public QLineEdit
{
    Q_OBJECT
public:
    DigetEdit(QWidget *parent=0);
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
    DigitKeyDialog *keyboard ;

};

#endif // DIGETEDIT_H
