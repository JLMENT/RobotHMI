/********************************************************************************
** Form generated from reading UI file 'robotoriginpointlocation.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTORIGINPOINTLOCATION_H
#define UI_ROBOTORIGINPOINTLOCATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_RobotOriginPointLocation
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;
    QRadioButton *op_SradioButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *op_SlineEdit;
    QRadioButton *op_LradioButton;
    QLineEdit *op_LlineEdit;
    QRadioButton *op_RradioButton;
    QRadioButton *op_UradioButton;
    QLineEdit *op_RlineEdit;
    QLineEdit *op_UlineEdit;
    QRadioButton *op_TradioButton;
    QRadioButton *op_BradioButton;
    QLineEdit *op_TlineEdit;
    QLineEdit *op_BlineEdit;
    QPushButton *op_savepushButton;

    void setupUi(QDialog *RobotOriginPointLocation)
    {
        if (RobotOriginPointLocation->objectName().isEmpty())
            RobotOriginPointLocation->setObjectName(QString::fromUtf8("RobotOriginPointLocation"));
        RobotOriginPointLocation->resize(651, 491);
        buttonBox = new QDialogButtonBox(RobotOriginPointLocation);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(450, 450, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButton = new QPushButton(RobotOriginPointLocation);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 30, 181, 27));
        op_SradioButton = new QRadioButton(RobotOriginPointLocation);
        op_SradioButton->setObjectName(QString::fromUtf8("op_SradioButton"));
        op_SradioButton->setGeometry(QRect(170, 130, 117, 22));
        label = new QLabel(RobotOriginPointLocation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 90, 101, 31));
        label_2 = new QLabel(RobotOriginPointLocation);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(350, 90, 101, 31));
        op_SlineEdit = new QLineEdit(RobotOriginPointLocation);
        op_SlineEdit->setObjectName(QString::fromUtf8("op_SlineEdit"));
        op_SlineEdit->setGeometry(QRect(350, 130, 181, 27));
        op_LradioButton = new QRadioButton(RobotOriginPointLocation);
        op_LradioButton->setObjectName(QString::fromUtf8("op_LradioButton"));
        op_LradioButton->setGeometry(QRect(170, 170, 117, 22));
        op_LlineEdit = new QLineEdit(RobotOriginPointLocation);
        op_LlineEdit->setObjectName(QString::fromUtf8("op_LlineEdit"));
        op_LlineEdit->setGeometry(QRect(350, 170, 181, 27));
        op_RradioButton = new QRadioButton(RobotOriginPointLocation);
        op_RradioButton->setObjectName(QString::fromUtf8("op_RradioButton"));
        op_RradioButton->setGeometry(QRect(170, 250, 117, 22));
        op_UradioButton = new QRadioButton(RobotOriginPointLocation);
        op_UradioButton->setObjectName(QString::fromUtf8("op_UradioButton"));
        op_UradioButton->setGeometry(QRect(170, 210, 117, 22));
        op_RlineEdit = new QLineEdit(RobotOriginPointLocation);
        op_RlineEdit->setObjectName(QString::fromUtf8("op_RlineEdit"));
        op_RlineEdit->setGeometry(QRect(350, 250, 181, 27));
        op_UlineEdit = new QLineEdit(RobotOriginPointLocation);
        op_UlineEdit->setObjectName(QString::fromUtf8("op_UlineEdit"));
        op_UlineEdit->setGeometry(QRect(350, 210, 181, 27));
        op_TradioButton = new QRadioButton(RobotOriginPointLocation);
        op_TradioButton->setObjectName(QString::fromUtf8("op_TradioButton"));
        op_TradioButton->setGeometry(QRect(170, 330, 117, 22));
        op_BradioButton = new QRadioButton(RobotOriginPointLocation);
        op_BradioButton->setObjectName(QString::fromUtf8("op_BradioButton"));
        op_BradioButton->setGeometry(QRect(170, 290, 117, 22));
        op_TlineEdit = new QLineEdit(RobotOriginPointLocation);
        op_TlineEdit->setObjectName(QString::fromUtf8("op_TlineEdit"));
        op_TlineEdit->setGeometry(QRect(350, 330, 181, 27));
        op_BlineEdit = new QLineEdit(RobotOriginPointLocation);
        op_BlineEdit->setObjectName(QString::fromUtf8("op_BlineEdit"));
        op_BlineEdit->setGeometry(QRect(350, 290, 181, 27));
        op_savepushButton = new QPushButton(RobotOriginPointLocation);
        op_savepushButton->setObjectName(QString::fromUtf8("op_savepushButton"));
        op_savepushButton->setGeometry(QRect(80, 430, 99, 27));

        retranslateUi(RobotOriginPointLocation);
        QObject::connect(buttonBox, SIGNAL(accepted()), RobotOriginPointLocation, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RobotOriginPointLocation, SLOT(reject()));

        QMetaObject::connectSlotsByName(RobotOriginPointLocation);
    } // setupUi

    void retranslateUi(QDialog *RobotOriginPointLocation)
    {
        RobotOriginPointLocation->setWindowTitle(QApplication::translate("RobotOriginPointLocation", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("RobotOriginPointLocation", " \345\216\237\347\202\271\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
        op_SradioButton->setText(QApplication::translate("RobotOriginPointLocation", "S", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RobotOriginPointLocation", "\351\200\211\346\213\251\350\275\264", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RobotOriginPointLocation", "\347\273\235\345\257\271\345\216\237\347\202\271\344\275\215\347\275\256", 0, QApplication::UnicodeUTF8));
        op_LradioButton->setText(QApplication::translate("RobotOriginPointLocation", "L", 0, QApplication::UnicodeUTF8));
        op_RradioButton->setText(QApplication::translate("RobotOriginPointLocation", "R", 0, QApplication::UnicodeUTF8));
        op_UradioButton->setText(QApplication::translate("RobotOriginPointLocation", "U", 0, QApplication::UnicodeUTF8));
        op_TradioButton->setText(QApplication::translate("RobotOriginPointLocation", "T", 0, QApplication::UnicodeUTF8));
        op_BradioButton->setText(QApplication::translate("RobotOriginPointLocation", "B", 0, QApplication::UnicodeUTF8));
        op_savepushButton->setText(QApplication::translate("RobotOriginPointLocation", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RobotOriginPointLocation: public Ui_RobotOriginPointLocation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTORIGINPOINTLOCATION_H
