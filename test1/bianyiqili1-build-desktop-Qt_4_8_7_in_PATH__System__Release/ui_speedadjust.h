/********************************************************************************
** Form generated from reading UI file 'speedadjust.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPEEDADJUST_H
#define UI_SPEEDADJUST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_SpeedAdjust
{
public:
    QLabel *label;
    QTextBrowser *textBrowser;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;

    void setupUi(QDialog *SpeedAdjust)
    {
        if (SpeedAdjust->objectName().isEmpty())
            SpeedAdjust->setObjectName(QString::fromUtf8("SpeedAdjust"));
        SpeedAdjust->resize(481, 381);
        QFont font;
        font.setPointSize(12);
        font.setItalic(true);
        SpeedAdjust->setFont(font);
        label = new QLabel(SpeedAdjust);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 481, 71));
        label->setFrameShape(QFrame::WinPanel);
        textBrowser = new QTextBrowser(SpeedAdjust);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 150, 481, 231));
        textBrowser->setFrameShape(QFrame::WinPanel);
        label_2 = new QLabel(SpeedAdjust);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 67, 17));
        label_3 = new QLabel(SpeedAdjust);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 100, 81, 17));
        label_4 = new QLabel(SpeedAdjust);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 120, 81, 17));
        label_5 = new QLabel(SpeedAdjust);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(230, 100, 81, 17));
        label_6 = new QLabel(SpeedAdjust);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(230, 120, 67, 17));
        lineEdit = new QLineEdit(SpeedAdjust);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 90, 113, 27));
        lineEdit->setFrame(false);
        lineEdit_2 = new QLineEdit(SpeedAdjust);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 120, 113, 27));
        lineEdit_2->setFrame(false);
        lineEdit_3 = new QLineEdit(SpeedAdjust);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(320, 90, 141, 27));
        lineEdit_3->setFrame(false);
        lineEdit_4 = new QLineEdit(SpeedAdjust);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(290, 120, 171, 27));
        lineEdit_4->setFrame(false);

        retranslateUi(SpeedAdjust);

        QMetaObject::connectSlotsByName(SpeedAdjust);
    } // setupUi

    void retranslateUi(QDialog *SpeedAdjust)
    {
        SpeedAdjust->setWindowTitle(QApplication::translate("SpeedAdjust", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SpeedAdjust", "\351\200\237\345\272\246\350\260\203\350\212\202", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SpeedAdjust", "\345\206\215\347\216\260", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SpeedAdjust", "\347\250\213\345\272\217\345\220\215\347\247\260\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SpeedAdjust", "\346\216\247\345\210\266\350\275\264\347\273\204\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SpeedAdjust", "\347\250\213\345\272\217\347\202\271\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SpeedAdjust", "\345\267\245\345\205\267\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SpeedAdjust: public Ui_SpeedAdjust {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPEEDADJUST_H
