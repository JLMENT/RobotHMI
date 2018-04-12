#ifndef PAGE2_H
#define PAGE2_H

#include <QDialog>

namespace Ui {
class Page2;
}

class Page2 : public QDialog
{
    Q_OBJECT

public:
    explicit Page2(QWidget *parent = 0);
    ~Page2();

private:
    Ui::Page2 *ui;
};

#endif // PAGE2_H
