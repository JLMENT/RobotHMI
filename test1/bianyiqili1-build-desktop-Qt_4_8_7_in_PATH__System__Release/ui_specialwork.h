/********************************************************************************
** Form generated from reading UI file 'specialwork.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECIALWORK_H
#define UI_SPECIALWORK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SpecialWork
{
public:
    QLabel *label;

    void setupUi(QDialog *SpecialWork)
    {
        if (SpecialWork->objectName().isEmpty())
            SpecialWork->setObjectName(QString::fromUtf8("SpecialWork"));
        SpecialWork->resize(400, 300);
        label = new QLabel(SpecialWork);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 80, 211, 101));

        retranslateUi(SpecialWork);

        QMetaObject::connectSlotsByName(SpecialWork);
    } // setupUi

    void retranslateUi(QDialog *SpecialWork)
    {
        SpecialWork->setWindowTitle(QApplication::translate("SpecialWork", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SpecialWork", "\347\211\271\346\256\212\350\277\220\350\241\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SpecialWork: public Ui_SpecialWork {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECIALWORK_H
