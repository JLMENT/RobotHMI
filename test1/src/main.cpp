#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QString>
#include <QTextCodec>
#include "configdialog.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    a.setFont(QFont("wenquanyi",9));
    // ConfigDialog w;
    CTRL_USR_Init();
    MainWindow M;
    //cmd_ipc_init();
    //cmd_cmdbuf_init();
    //CTRL_USR_Init();
    /*QPalette pal(M->palette());
    pal.setColor(QPalette::Background,Qt::black);
    M->setAutoFillBackground(true);
    M->setPalette(pal);*/
    //M->setStyleSheet("background-color:black;");

    //QIcon icon;
    //icon.addFile(tr("image/Add.png"));
    //ui->ProgramButton->setIcon(icon);
   // M.show();
    M.show();
    M.move((QApplication::desktop()->width()-M.width())/2,(QApplication::desktop()->height()-M.height())/2);

    return a.exec();
}
