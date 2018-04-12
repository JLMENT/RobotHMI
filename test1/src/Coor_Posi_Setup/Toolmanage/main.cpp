#include "toolmanagewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ToolManageWidget w;
    w.show();

    return a.exec();
}
