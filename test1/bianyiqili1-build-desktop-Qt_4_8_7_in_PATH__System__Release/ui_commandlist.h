/********************************************************************************
** Form generated from reading UI file 'commandlist.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMANDLIST_H
#define UI_COMMANDLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommandList
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *iopushButton;
    QPushButton *controlpushButton;
    QPushButton *pushButton_3;
    QPushButton *movecommandButton;
    QPushButton *operationpushButton;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_9;

    void setupUi(QDialog *CommandList)
    {
        if (CommandList->objectName().isEmpty())
            CommandList->setObjectName(QString::fromUtf8("CommandList"));
        CommandList->resize(82, 204);
        widget = new QWidget(CommandList);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 82, 201));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        iopushButton = new QPushButton(widget);
        iopushButton->setObjectName(QString::fromUtf8("iopushButton"));

        verticalLayout->addWidget(iopushButton);

        controlpushButton = new QPushButton(widget);
        controlpushButton->setObjectName(QString::fromUtf8("controlpushButton"));

        verticalLayout->addWidget(controlpushButton);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        movecommandButton = new QPushButton(widget);
        movecommandButton->setObjectName(QString::fromUtf8("movecommandButton"));

        verticalLayout->addWidget(movecommandButton);

        operationpushButton = new QPushButton(widget);
        operationpushButton->setObjectName(QString::fromUtf8("operationpushButton"));

        verticalLayout->addWidget(operationpushButton);

        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(widget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        verticalLayout->addWidget(pushButton_8);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_9 = new QPushButton(widget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        verticalLayout->addWidget(pushButton_9);


        retranslateUi(CommandList);

        QMetaObject::connectSlotsByName(CommandList);
    } // setupUi

    void retranslateUi(QDialog *CommandList)
    {
        CommandList->setWindowTitle(QApplication::translate("CommandList", "Dialog", 0, QApplication::UnicodeUTF8));
        iopushButton->setText(QApplication::translate("CommandList", "I/O", 0, QApplication::UnicodeUTF8));
        controlpushButton->setText(QApplication::translate("CommandList", "\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("CommandList", "\344\275\234\344\270\232", 0, QApplication::UnicodeUTF8));
        movecommandButton->setText(QApplication::translate("CommandList", "\347\247\273\345\212\250", 0, QApplication::UnicodeUTF8));
        operationpushButton->setText(QApplication::translate("CommandList", "\346\274\224\347\256\227", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("CommandList", "\345\271\263\347\247\273", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("CommandList", "\345\205\266\344\273\226", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("CommandList", "\347\233\270\345\220\214", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("CommandList", "\345\220\214\345\211\215", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CommandList: public Ui_CommandList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMANDLIST_H
