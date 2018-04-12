#ifndef KEYPAD_H
#define KEYPAD_H

#include <QWidget>

namespace Ui {
class keypad;
}

class keypad : public QWidget
{
    Q_OBJECT

public:
    explicit keypad(QWidget *parent = 0);
    ~keypad();

private:
    Ui::keypad *ui;
};

#endif // KEYPAD_H
