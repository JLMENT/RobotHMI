#ifndef ALARMWIDGET_H
#define ALARMWIDGET_H

#include <QWidget>
#include <QtXml>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QDateTime>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDebug>
#include <QTimerEvent>
#include <usr_motion_api/usr_motion_api.h>
#include <usr_motion_api/motionError.h>

#include "alarm_macro.h"


class AlarmWidget : public QWidget
{
    Q_OBJECT

public:
    AlarmWidget(QWidget *parent = 0);
    ~AlarmWidget();
    bool findAlarmInformation(int alarm_number);
    QString requireCurrentAlarmInformation();

    bool recordCurrentAlarmInformation();
    bool displayCurrentPageAlarmInformation();
    bool clearAlarmInformation();




private:
    QString current_alarm_information;
    int current_alarm_number;
    QString alarm_time;
    static int alarm_page_number;

    QLabel *title_edit = new QLabel(this);
    QLabel *table_head1 = new QLabel(this);
    QLabel *table_head2 = new QLabel(this);
    QLabel *table_head3 = new QLabel(this);
    QLabel *table_head4 = new QLabel(this);
    QTextEdit *textedit[5];// = new QTextEdit();
    QPushButton *pb1 = new QPushButton(this);
    QPushButton *pb2 = new QPushButton(this);
    QPushButton *pb3 = new QPushButton(this);
    QPushButton *pb4 = new QPushButton(this);
    QHBoxLayout *hbl1 = new QHBoxLayout;
    QHBoxLayout *hbl2 = new QHBoxLayout;
    QVBoxLayout *vb = new QVBoxLayout(this);



    void alarmPageInit();
    QString requireCurrentAlarmTime();

    int m_timeId1;
    int arithmetic_arror_count;
    int current_alarm_status;
    int previous_alarm_status;

    ErrorData errordata1;
    ErrorData errordatadisplay1;
    QString current_alarm_str;
    int whether_has_error;


protected:
    void timerEvent(QTimerEvent *event);//当上一状态的报警状态和当前的报警状态相同，则不处理这个报警



private slots:
    void clear_alarm_information_slot();
    void previous_page_information();
    void next_page_information();

signals:
    void current_alarm_information_sig(QString alarm_information);
    void current_alarm_number_sig(int number);

};

#endif // ALARMWIDGET_H
