/********************************************************************************
** Form generated from reading UI file 'newfilename.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWFILENAME_H
#define UI_NEWFILENAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewFileName
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *NewFileName)
    {
        if (NewFileName->objectName().isEmpty())
            NewFileName->setObjectName(QString::fromUtf8("NewFileName"));
        NewFileName->resize(362, 146);
        label = new QLabel(NewFileName);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 40, 81, 31));
        lineEdit = new QLineEdit(NewFileName);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 40, 161, 27));
        pushButton = new QPushButton(NewFileName);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(228, 90, 51, 27));
        pushButton_2 = new QPushButton(NewFileName);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 90, 51, 27));

        retranslateUi(NewFileName);

        QMetaObject::connectSlotsByName(NewFileName);
    } // setupUi

    void retranslateUi(QWidget *NewFileName)
    {
        NewFileName->setWindowTitle(QApplication::translate("NewFileName", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewFileName", "\346\226\260\346\226\207\344\273\266\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("NewFileName", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("NewFileName", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewFileName: public Ui_NewFileName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFILENAME_H
