#include "originoffsetwidget.h"

OriginOffsetWidget::OriginOffsetWidget(QWidget *parent)
    : QWidget(parent)
{

    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //this->resize(200,200);
    for(int i=0;i<4;++i)
    {
        pb[i] = new QPushButton(this);
        pb[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        hb->addWidget(pb[i]);
    }
    hb->setMargin(0);
    hb->setSpacing(0);
    hb->setContentsMargins(10,0,10,0);
    pb[0]->setText("记录零点");
    pb[1]->setEnabled(false);
    pb[2]->setEnabled(false);
    pb[3]->setEnabled(false);

    edit->setEnabled(false);
    edit->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    edit->setText("零位标定");
    edit->setStyleSheet("background-color:rgb(0,238,238)");
    edit->setAlignment(Qt::AlignCenter);
    QPalette palette;
    palette.setColor(QPalette::Text,Qt::white);
    edit->setPalette(palette);
    edit->setFont(QFont("Timers",28,QFont::Bold));

    vb->addWidget(edit,2);
    vb->addWidget(origin_status,4);
    vb->addWidget(encorder_data,4);
    vb->addWidget(selectoa,4);
    vb->addLayout(hb,1);


    this->setLayout(vb);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(ensure_encorde_origin()));
    connect(pb[0],SIGNAL(pressed()),this,SLOT(record_origin_press_slot()));
    connect(pb[0],SIGNAL(released()),this,SLOT(record_origin_release_slot()));



}

OriginOffsetWidget::~OriginOffsetWidget()
{

}

void OriginOffsetWidget::record_origin_press_slot()
{
    timer->start(5000);
    qDebug()<<"start";
}

void OriginOffsetWidget::record_origin_release_slot()
{
    timer->stop();
    qDebug()<<"stop()";
}

void OriginOffsetWidget::ensure_encorde_origin()
{
    qlonglong dl1 = 0;
    qlonglong dl2 = 0;
    qlonglong *dl,*getdl;
    dl = &dl1;
    getdl = &dl2;
    timer->stop();
    switch (QMessageBox::question(this,"确定要标定零位","确定要标定零位",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Cancel)) {
    case QMessageBox::Ok:
        //标定零位
        qDebug()<<"标定零位";
        //获取选定轴状态
        //根据获取编码器数据
        //根据轴选择状态，将对应轴数据写入机器人
        //判断是否写入成功（写入成功--标定零位标定状态；写入失败，报警
        //恢复选定轴状态


        for(int i=0;i<8;++i)
        {
            qDebug()<<selectoa->encord_aix[i];

            if(selectoa->encord_aix[i])
            {
                CTRL_GetOriginOffset(getdl,i);
                encorder_data->set_encorder_data(i,*getdl);
                encorder_data->get_encorder_data(i,dl);
                qDebug()<<*dl;
                //CTRL_SetOriginOffset(*dl,i);
                //CTRL_GetOriginOffset(getdl,i);
                if(*dl==*getdl)
                {
                   //写入数据成功
                    //标定轴状态
                    //save specity axis encorder data
                    encorder_data->save_encorder_data(i,*dl);

                    origin_status->set_specify_axis_status(i);

                    CTRL_SetOriginOffset(*dl,i);
                    qDebug()<<"写入数据成功";
                }
                else
                {
                    QMessageBox::warning(this,"警告","轴值写入失败请重试",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
                    return;
                }

            }
        }
        selectoa->recover_axis_status();


        break;
    case QMessageBox::Cancel:
        //恢复轴选中状态
        qDebug()<<"恢复轴选中状态";
        selectoa->recover_axis_status();
        break;
    default:
        break;
    }
}
