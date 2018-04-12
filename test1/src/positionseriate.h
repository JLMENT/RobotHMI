#ifndef POSITIONSERIATE_H
#define POSITIONSERIATE_H

#include <QWidget>
#include "xml_cancle/xmlcancle.h"

namespace Ui {
class PositionSeriate;
}

class PositionSeriate : public QWidget
{
    Q_OBJECT

public:
    explicit PositionSeriate(QWidget *parent = 0);
    ~PositionSeriate();

private slots:
    void on_pushButton_new_position_clicked();

    void on_pushButton_select_position_clicked();

    void on_pushButton_pos_save_clicked();

    void refresh_current_position();//refresh_current_position

    void on_pushButton_setpu_currentposition_clicked();

    void on_pushButton_posi_variate_data_clicked();

    void on_comboBox_cu_co_select_currentIndexChanged(int index);

private:
    Ui::PositionSeriate *ui;
    XmlCancle *xmlcancle1;

signals:
    void refresh_posi_vari_sig();
};

#endif // POSITIONSERIATE_H
