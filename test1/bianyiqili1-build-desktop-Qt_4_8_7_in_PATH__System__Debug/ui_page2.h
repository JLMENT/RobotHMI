/********************************************************************************
** Form generated from reading UI file 'page2.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE2_H
#define UI_PAGE2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Page2
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *JEdit_1;
    QLineEdit *JEdit_2;
    QLabel *label_2;
    QLineEdit *JEdit_3;
    QLabel *label_3;
    QLineEdit *JEdit_4;
    QLabel *label_4;
    QLineEdit *JEdit_5;
    QLabel *label_5;
    QLineEdit *JEdit_6;
    QLabel *label_6;

    void setupUi(QDialog *Page2)
    {
        if (Page2->objectName().isEmpty())
            Page2->setObjectName(QString::fromUtf8("Page2"));
        Page2->resize(691, 394);
        groupBox = new QGroupBox(Page2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 60, 671, 121));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 21, 30));
        JEdit_1 = new QLineEdit(groupBox);
        JEdit_1->setObjectName(QString::fromUtf8("JEdit_1"));
        JEdit_1->setGeometry(QRect(40, 50, 71, 27));
        JEdit_2 = new QLineEdit(groupBox);
        JEdit_2->setObjectName(QString::fromUtf8("JEdit_2"));
        JEdit_2->setGeometry(QRect(150, 50, 71, 27));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 50, 21, 30));
        JEdit_3 = new QLineEdit(groupBox);
        JEdit_3->setObjectName(QString::fromUtf8("JEdit_3"));
        JEdit_3->setGeometry(QRect(260, 50, 71, 27));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(340, 50, 21, 30));
        JEdit_4 = new QLineEdit(groupBox);
        JEdit_4->setObjectName(QString::fromUtf8("JEdit_4"));
        JEdit_4->setGeometry(QRect(370, 50, 71, 27));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 50, 21, 30));
        JEdit_5 = new QLineEdit(groupBox);
        JEdit_5->setObjectName(QString::fromUtf8("JEdit_5"));
        JEdit_5->setGeometry(QRect(480, 50, 71, 27));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(560, 50, 21, 30));
        JEdit_6 = new QLineEdit(groupBox);
        JEdit_6->setObjectName(QString::fromUtf8("JEdit_6"));
        JEdit_6->setGeometry(QRect(590, 50, 71, 27));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(450, 50, 21, 30));

        retranslateUi(Page2);

        QMetaObject::connectSlotsByName(Page2);
    } // setupUi

    void retranslateUi(QDialog *Page2)
    {
        Page2->setWindowTitle(QApplication::translate("Page2", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Page2", "JONINT", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Page2", "J1:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Page2", "J2:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Page2", "J4:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Page2", "J3:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Page2", "J6:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Page2", "J5:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Page2: public Ui_Page2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE2_H
