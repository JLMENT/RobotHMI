#include "alarmwidget.h"

int AlarmWidget::alarm_page_number=1;

AlarmWidget::AlarmWidget(QWidget *parent)
    : QWidget(parent)
{
    alarmPageInit();
}

AlarmWidget::~AlarmWidget()
{

}

bool AlarmWidget::findAlarmInformation(int alarm_number)
{
    current_alarm_number = alarm_number;
    if(alarm_number>500&&alarm_number<3000)
    {
        QFile file("Alarm_information.xml");
        if(file.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            QXmlStreamReader reader(&file);
            while(!reader.atEnd())
            {
                if(reader.isStartElement())
                {
                    if(reader.name()==QString::number(alarm_number,10))
                    {
                        current_alarm_information=reader.readElementText();
                        return true;
                    }
                }
                reader.readNext();
            }
        }
        else
        {
            return false;
        }
        file.close();
    }
    else
    {
        return false;
    }
}

QString AlarmWidget::requireCurrentAlarmInformation()
{
    return current_alarm_information;
}

bool AlarmWidget::recordCurrentAlarmInformation()
{
    alarm_time = requireCurrentAlarmTime();
    QString alarm_number_str = QString::number(current_alarm_number,10);

    QFile file("Alarm_data.xml");
    if(file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QXmlStreamWriter writer(&file);
        writer.writeStartElement("DATA");
        writer.writeAttribute("time",alarm_time);
        writer.writeAttribute("code",alarm_number_str);
        writer.writeAttribute("information",current_alarm_information);
        writer.writeEndElement();
        file.close();
    }
    else
    {
        return false;
    }
}

bool AlarmWidget::displayCurrentPageAlarmInformation()
{
    int i=0;
    QString str_time,str_code,str_information;
    QFile file("Alarm_data.xml");
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QXmlStreamReader reader(&file);
        //while(!reader.atEnd())
        reader.readNextStartElement();
        reader.readNextStartElement();
        //reader.readNextStartElement();
        for(int i=0;i<alarm_page_number*5;++i)
        {
            if(reader.atEnd())
            {
                alarm_page_number-=1;
                if(ALARM_DEBUG_STATUS)
                {
                    qDebug()<<"reader.atEnd";
                }
                file.close();
                return false;
            }
            if(i>=(alarm_page_number-1)*5)
            {
                //if(reader.isStartElement())
                //{
                    if(reader.name()=="DATA")
                    {
                        QXmlStreamAttributes attributes = reader.attributes();
                        if(attributes.hasAttribute("time"))
                        {
                            str_time = attributes.value("time").toString();
                        }
                        if(attributes.hasAttribute("code"))
                        {
                            str_code  = attributes.value("code").toString();
                        }
                        if(attributes.hasAttribute("information"))
                        {
                            str_information = attributes.value("information").toString();
                        }
                    }
                //}
                //else if(reader.isEndElement()&&reader.name()=="DATA")
                //{
                    //                if(i!=0&&i%5==0)
                    //                {
                    //                    return;
                    //                }
                    if(ALARM_DEBUG_STATUS)
                    {
                        qDebug()<<"i="<<i;
                    }
                    textedit[i%5]->setText(QString::number(i+1,10)+" "+str_time+" "+str_code+"\n"+str_information);
                //}
            }
            //reader.readNext();

            reader.readNextStartElement();
            reader.readNextStartElement();

        }
        file.close();
    }
    else
    {
        return false;
    }
}

bool AlarmWidget::clearAlarmInformation()
{
    QFile file("Alarm_data.xml");
    QXmlStreamWriter writer(&file);
    switch(QMessageBox::question(this,"warning","你确定要清除报警记录？",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok))
    {
    case QMessageBox::Ok:
        textedit[0]->clear();
        textedit[1]->clear();
        textedit[2]->clear();
        textedit[3]->clear();
        textedit[4]->clear();
        QProcess::execute("rm -f /opt/log/Alarm_data.xml");
        QProcess::execute("mkdir /opt/log/Alarm_data.xml");
        //QFile file("Alarm_data.xml");
        if(file.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            //QXmlStreamWriter writer(&file);
            writer.setAutoFormatting(true);
            writer.writeStartDocument();
            writer.writeStartElement("DATA");
            writer.writeEndElement();
            writer.writeEndDocument();
            file.close();
        }
        //break;
        return true;

    case QMessageBox::Cancel:
        break;
    default:
        break;
    }

}

void AlarmWidget::alarmPageInit()
{
    setGeometry(0,0,400,400);
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //this->resize(300,300);
    title_edit->setText("报警历史");
    title_edit->setMinimumSize(50,20);
    title_edit->setFrameStyle(QFrame::Panel|QFrame::Raised);
    title_edit->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    title_edit->setAlignment(Qt::AlignCenter);
    table_head1->setText("序号");
    table_head1->setMinimumSize(50,20);
    table_head1->setAlignment(Qt::AlignCenter);
    table_head1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    table_head2->setText("报警时间");
    table_head2->setMinimumSize(50,20);
    table_head2->setAlignment(Qt::AlignCenter);
    table_head2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    table_head3->setText("报警代码");
    table_head3->setMinimumSize(50,20);
    table_head3->setAlignment(Qt::AlignCenter);
    table_head3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    table_head4->setText("报警信息");
    table_head4->setMinimumSize(50,20);
    table_head4->setAlignment(Qt::AlignCenter);
    table_head4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    table_head1->setFrameStyle(QFrame::Panel|QFrame::Raised);
    table_head2->setFrameStyle(QFrame::Panel|QFrame::Raised);
    table_head3->setFrameStyle(QFrame::Panel|QFrame::Raised);
    table_head4->setFrameStyle(QFrame::Panel|QFrame::Raised);

    textedit[0] = new QTextEdit(this);
    textedit[1] = new QTextEdit(this);
    textedit[2] = new QTextEdit(this);
    textedit[3] = new QTextEdit(this);
    textedit[4] = new QTextEdit(this);
    textedit[0]->setMinimumSize(50,20);
    textedit[1]->setMinimumSize(50,20);
    textedit[2]->setMinimumSize(50,20);
    textedit[3]->setMinimumSize(50,20);
    textedit[4]->setMinimumSize(50,20);
    textedit[0]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    textedit[1]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    textedit[2]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    textedit[3]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    textedit[4]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    textedit[0]->setEnabled(false);
    textedit[1]->setEnabled(false);
    textedit[2]->setEnabled(false);
    textedit[3]->setEnabled(false);
    textedit[4]->setEnabled(false);


    pb1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    pb1->setEnabled(false);
    pb2->setText("全部清除");
    //pb2->setAlignment(Qt::AlignCenter);
    pb2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    pb3->setText("上一页");
    //pb3->setAlignment(Qt::AlignCenter);
    pb3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    pb4->setText("下一页");
    //pb4->setAlignment(Qt::AlignCenter);
    pb4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    pb1->setMinimumSize(50,20);
    pb2->setMinimumSize(50,20);
    pb3->setMinimumSize(50,20);
    pb4->setMinimumSize(50,20);

    hbl1->addWidget(table_head1,1);
    hbl1->addWidget(table_head2,6);
    hbl1->addWidget(table_head3,2);
    hbl1->addWidget(table_head4,6);
    hbl1->setMargin(0);
    hbl1->setSpacing(0);

    hbl2->addWidget(pb1,1);
    hbl2->addWidget(pb2,1);
    hbl2->addWidget(pb3,1);
    hbl2->addWidget(pb4,1);
    hbl2->setMargin(0);
    hbl2->setSpacing(0);

    vb->addWidget(title_edit,2);
    vb->addLayout(hbl1,1);
    vb->addWidget(textedit[0],2);
    vb->addWidget(textedit[1],2);
    vb->addWidget(textedit[2],2);
    vb->addWidget(textedit[3],2);
    vb->addWidget(textedit[4],2);
    vb->addLayout(hbl2,1);

    connect(pb2,SIGNAL(clicked()),this,SLOT(clear_alarm_information_slot()));
    connect(pb3,SIGNAL(clicked()),this,SLOT(previous_page_information()));
    connect(pb4,SIGNAL(clicked()),this,SLOT(next_page_information()));

    this->setLayout(vb);

    displayCurrentPageAlarmInformation();
    m_timeId1 = startTimer(100);
//    QString str1 = requireCurrentAlarmTime();
//    qDebug()<<str1;

}

///////////////////////////QDataEdit设置系统时间////////////////////////////
//        str = "date -s "+dateEdit->dateTime().toString("yyyyMMddhhmm");
//		QProcess::execute(str);
//		QProcess::execute("hwclock -w");
QString AlarmWidget::requireCurrentAlarmTime()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
    return str;
}

void AlarmWidget::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==m_timeId1)
    {

    }
}

void AlarmWidget::clear_alarm_information_slot()
{

}

void AlarmWidget::previous_page_information()
{
    if(alarm_page_number<=1)
    {
        return;
    }
    else
    {
        alarm_page_number-=1;
    }
    displayCurrentPageAlarmInformation();
}

void AlarmWidget::next_page_information()
{
    alarm_page_number+=1;
    displayCurrentPageAlarmInformation();
}
















