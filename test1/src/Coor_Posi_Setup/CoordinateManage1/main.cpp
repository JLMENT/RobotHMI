#include "coordinatemanagewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CoordinateManageWidget w;
    w.show();

    return a.exec();
}
