/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SpeOperation
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBox_5;
    QComboBox *comboBox_6;
    QLabel *label_7;

    void setupUi(QDialog *SpeOperation)
    {
        if (SpeOperation->objectName().isEmpty())
            SpeOperation->setObjectName(QString::fromUtf8("SpeOperation"));
        SpeOperation->resize(405, 327);
        label = new QLabel(SpeOperation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 401, 51));
        QFont font;
        font.setPointSize(12);
        font.setItalic(true);
        label->setFont(font);
        label->setFrameShape(QFrame::WinPanel);
        label_2 = new QLabel(SpeOperation);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(16, 90, 121, 20));
        comboBox = new QComboBox(SpeOperation);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(170, 80, 151, 27));
        comboBox_2 = new QComboBox(SpeOperation);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(170, 110, 151, 27));
        label_3 = new QLabel(SpeOperation);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(16, 120, 121, 20));
        label_4 = new QLabel(SpeOperation);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(16, 180, 121, 20));
        comboBox_3 = new QComboBox(SpeOperation);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(170, 170, 151, 27));
        comboBox_4 = new QComboBox(SpeOperation);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(170, 140, 151, 27));
        label_5 = new QLabel(SpeOperation);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(16, 150, 121, 20));
        label_6 = new QLabel(SpeOperation);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(16, 240, 141, 20));
        comboBox_5 = new QComboBox(SpeOperation);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(170, 230, 151, 27));
        comboBox_6 = new QComboBox(SpeOperation);
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));
        comboBox_6->setGeometry(QRect(170, 200, 151, 27));
        label_7 = new QLabel(SpeOperation);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(16, 210, 121, 20));

        retranslateUi(SpeOperation);

        QMetaObject::connectSlotsByName(SpeOperation);
    } // setupUi

    void retranslateUi(QDialog *SpeOperation)
    {
        SpeOperation->setWindowTitle(QApplication::translate("SpeOperation", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SpeOperation", "\347\211\271\346\256\212\350\277\220\350\241\214", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SpeOperation", "\344\275\216\351\200\237\350\277\220\350\241\214\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("SpeOperation", "\346\234\211\346\225\210", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpeOperation", "\346\227\240\346\225\210", 0, QApplication::UnicodeUTF8)
        );
        comboBox->setCurrentText(QApplication::translate("SpeOperation", "\346\227\240\346\225\210", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("SpeOperation", "\346\234\211\346\225\210", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpeOperation", "\346\227\240\346\225\210", 0, QApplication::UnicodeUTF8)
        );
        comboBox_2->setCurrentText(QApplication::translate("SpeOperation", "\346\234\211\346\225\210", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SpeOperation", "\351\231\220\351\200\237\350\277\220\350\241\214\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SpeOperation", "\346\234\272\346\242\260\351\224\201\345\256\232\350\277\220\350\241\214\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("SpeOperation", "\346\234\211\346\225\210", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpeOperation", "\346\227\240\346\225\210", 0, QApplication::UnicodeUTF8)
        );
        comboBox_3->setCurrentText(QApplication::translate("SpeOperation", "\346\234\211\346\225\210", 0, QApplication::UnicodeUTF8));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("SpeOperation", "\346\234\211\346\225\210", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpeOperation", "\346\227\240\346\225\210", 0, QApplication::UnicodeUTF8)
        );
        comboBox_4->setCurrentText(QApplication::translate("SpeOperation", "\346\234\211\346\225\210", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SpeOperation", "\347\251\272\350\277\220\350\241\214\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SpeOperation", "\346\243\200\346\237\245\350\277\220\350\241\214\345\201\234\346\255\242\346\221\206\347\204\212\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("SpeOperation", "\346\234\211\346\225\210", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpeOperation", "\346\227\240\346\225\210", 0, QApplication::UnicodeUTF8)
        );
        comboBox_5->setCurrentText(QApplication::translate("SpeOperation", "\346\234\211\346\225\210", 0, QApplication::UnicodeUTF8));
        comboBox_6->clear();
        comboBox_6->insertItems(0, QStringList()
         << QApplication::translate("SpeOperation", "\346\234\211\346\225\210", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SpeOperation", "\346\227\240\346\225\210", 0, QApplication::UnicodeUTF8)
        );
        comboBox_6->setCurrentText(QApplication::translate("SpeOperation", "\346\234\211\346\225\210", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SpeOperation", "\346\243\200\346\237\245\350\277\220\350\241\214\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SpeOperation: public Ui_SpeOperation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
