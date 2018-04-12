#include <string.h>
#include "configdialog.h"
#include <QStackedWidget>
#include <QHBoxLayout>
#include "speedadjust.h"


ConfigDialog::ConfigDialog(QWidget *parent, Qt::WindowFlags flags)
         :QDialog(parent,flags)
{

    //××××××××××初始化系统设置参数（创建初始化文件，读取初始化对应参数）××××××××//
    createINI();
    readINI();

    setGeometry(0,0,800,480);
    QStackedWidget *stack=new QStackedWidget(this);
    page1 = new SpeedAdjust;
    page3 = new SpecialWork;
    MainWindow *MWwindow = new MainWindow(this);

   // stack->addWidget(MWwindow);
    stack->addWidget(page3);
    stack->addWidget(page1);
    //stack->addWidget(MWwindow);


    connect(MWwindow,SIGNAL(ActionClick(int)),stack,SLOT(setCurrentIndex(int)));
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(MWwindow);
    mainLayout->addWidget(stack);
    mainLayout->setMargin(5);
    mainLayout->setSpacing(5);


    mainLayout->setStretchFactor(MWwindow,5);
    mainLayout->setStretchFactor(stack,3);
    this->setLayout(mainLayout);

}
ConfigDialog::~ConfigDialog()
{
}
void ConfigDialog::createINI()
{
    QSettings ss("config.ini",QSettings::IniFormat);

    ss.beginGroup("orginpointdata");
    ss.setValue("1pS",0);
    ss.setValue("2pL",0);
    ss.setValue("3pU",0);
    ss.setValue("4pR",0);
    ss.setValue("5pB",0);
    ss.setValue("6pT",0);
    ss.endGroup();

    QDir dir;
    dir.mkdir("db");
    QString str = "date -s 201709014";
    QProcess::execute(str);
    QProcess::execute("hwclock -w");


}

void ConfigDialog::readINI()
{

}

