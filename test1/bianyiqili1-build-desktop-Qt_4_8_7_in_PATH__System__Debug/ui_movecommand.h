/********************************************************************************
** Form generated from reading UI file 'movecommand.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVECOMMAND_H
#define UI_MOVECOMMAND_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MoveCommand
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *comboBox;
    QComboBox *comboBox_2;

    void setupUi(QDialog *MoveCommand)
    {
        if (MoveCommand->objectName().isEmpty())
            MoveCommand->setObjectName(QString::fromUtf8("MoveCommand"));
        MoveCommand->setEnabled(true);
        MoveCommand->resize(608, 300);
        stackedWidget = new QStackedWidget(MoveCommand);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 581, 221));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label = new QLabel(page_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 51, 21));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 30, 31, 21));
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 20, 61, 31));
        lineEdit_2 = new QLineEdit(page_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(190, 20, 61, 31));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 30, 31, 21));
        checkBox = new QCheckBox(page_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(60, 90, 97, 22));
        checkBox_2 = new QCheckBox(page_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(150, 90, 97, 22));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(260, 30, 41, 21));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(390, 30, 41, 21));
        comboBox = new QComboBox(page_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(300, 20, 85, 31));
        comboBox_2 = new QComboBox(page_2);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(430, 20, 85, 31));
        stackedWidget->addWidget(page_2);

        retranslateUi(MoveCommand);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MoveCommand);
    } // setupUi

    void retranslateUi(QDialog *MoveCommand)
    {
        MoveCommand->setWindowTitle(QApplication::translate("MoveCommand", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MoveCommand", "MOVJ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MoveCommand", "VJ=", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MoveCommand", "PL=", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MoveCommand", "NWAIT", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("MoveCommand", "UNTIL", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MoveCommand", "ACC=", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MoveCommand", "DEC=", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MoveCommand", "20%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MoveCommand", "30%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MoveCommand", "40%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MoveCommand", "50%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MoveCommand", "60%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MoveCommand", "70%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MoveCommand", "80%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MoveCommand", "90%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MoveCommand", "100%", 0, QApplication::UnicodeUTF8)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MoveCommand", "20%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MoveCommand", "30%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MoveCommand", "40%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MoveCommand", "50%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MoveCommand", "60%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MoveCommand", "70%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MoveCommand", "80%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MoveCommand", "90%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MoveCommand", "100%", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class MoveCommand: public Ui_MoveCommand {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVECOMMAND_H
