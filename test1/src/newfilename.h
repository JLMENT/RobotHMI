#ifndef NEWFILENAME_H
#define NEWFILENAME_H

#include <QWidget>

namespace Ui {
class NewFileName;
}

class NewFileName : public QWidget
{
    Q_OBJECT

public:
    explicit NewFileName(QWidget *parent = 0);
    ~NewFileName();

private:
    Ui::NewFileName *ui;
};

#endif // NEWFILENAME_H
