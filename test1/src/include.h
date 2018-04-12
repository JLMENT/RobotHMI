#ifndef INCLUDE_H
#define INCLUDE_H

#include <QSettings>
#include <QDir>
#include <QProcess>
#include <QMessageBox>
#include <QString>

extern QSettings settings;

extern QString program_filename;
extern QString prosition_filename;

extern QString select_input_command;

struct MovjCommand
{
    QString buf[12];
};
extern MovjCommand movjc1;
extern MovjCommand movjc2;
struct MovlCommand
{
    QString buf[18];
};
extern MovlCommand movlc1;
extern MovlCommand movlc2;

struct MovcCommand
{
    QString buf[18];
};
extern MovcCommand movcc1;
extern MovcCommand movcc2;
struct SpeedCommand
{
    QString buf[3];
};
extern SpeedCommand speedc1;
extern SpeedCommand speedc2;

struct PositionData
{
    QString buf[8];
};

extern PositionData positiondata1;  //Store position data

extern PositionData positiondata2;

extern QStringList posi_vari_point;

extern QString coordinate_select;

extern bool movc_send_victory_flg;

struct DoutCommand
{
    QString buf[2];
};
extern DoutCommand doutc1;
extern DoutCommand doutc2;
struct DinCommand
{
    QString buf[2];
};
extern DinCommand dinc1;
extern DinCommand dinc2;
extern QString LabelCommand1;
extern QString LabelCommand2;
struct PauseCommand
{
    QString buf[5];
};
extern PauseCommand pausec1;
extern PauseCommand pausec2;
extern QString timec1;
extern QString timec2;
struct JumpCommand
{
    QString buf[6];
};
extern JumpCommand jumpc1;
extern JumpCommand jumpc2;
struct CallCommand
{
    QString buf[6];
};
extern CallCommand callc1;
extern CallCommand callc2;
struct RetCommand
{
    QString buf[5];
};
extern RetCommand retc1;
extern RetCommand retc2;


#endif // INCLUDE_H

