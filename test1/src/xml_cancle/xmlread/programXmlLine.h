#ifndef PROGRAMXMLLINE_H
#define PROGRAMXMLLINE_H
#include <QString>
#include <QtXml>

//contains information of one xml line

class OperateProgramXml;
typedef enum
{
    IO_NONE=-1,
    OFF=0,
    ON
}DigitalValue;

typedef enum
{
    VAR_TYPE_NONE=-1,
    DIN=0,
    DOUT,
    BYTE,
    INT
}VarType;

typedef enum
{
    VSTYLE_NONE = -1,
    VJ = 0,
    VL,
    VR
}VStyle;
typedef enum
{
    CMP_TYPE_NONE=-1,
    EQ=0,
    GT,
    LT,
    GE,
    LE
}CompareSign;


typedef enum
{
    COMMAND_NONE_TYPE=-1,
    COMMAND_MOVJ_TYPE=0,
    COMMAND_MOVL_TYPE,
    COMMAND_MOVC_TYPE,
    COMMAND_DOUT_TYPE,
    COMMAND_DIN_TYPE,
    CMOMAND_SPEED_TYPE,
    COMMAND_JUMP_TYPE,
    COMMAND_LABEL_TYPE,
    COMMAND_CALL_TYPE,
    COMMAND_PAUSE_TYPE,
    COMMAND_TIMER_TYPE,
    COMMAND_RET_TYPE,
    COMMAND_NOP_TYPE,
    COMMAND_END_TYPE
}CommandType;

typedef struct
{
    double vj;
    double vl;
    double vr;
}Velocity;

typedef struct
{
    VarType         type;
    int             varAddress;
    CompareSign     sign;
    union
    {
        DigitalValue dio;
        int          integerValue;
    }value;
}Condition;

typedef enum
{
    JOINT,
    WORLD,
    USR,
    TOOL,
    NONE
}CoordinateType;


typedef struct
{
    CoordinateType coord;
    double p[6];
}Position;

typedef struct
{
    double x;
    double y;
    double z;
    double a;
    double b;
    double c;
}UsrInformation;

typedef struct
{
    double x;
    double y;
    double z;
    double a;
    double b;
    double c;
}ToolInformation;


typedef struct
{
    CommandType         commandType;        //comannd type
    Velocity            vel;                //
    double              acc;
    double              dec;
    int                 lablel;
    QString             fileName;
    double              time;
    Position            p;
    int                 pl;                 //movement pl level
    Condition           condition;         //
    int                 nwait;
    UsrInformation      usr;
    ToolInformation     tool;
    int                 IoPort;
    DigitalValue        dOutValue;          //ON OFF
    int                 byteAddress;        //DIN store variable address

}ProgramXmlLine;

typedef int (OperateProgramXml::*ReadParamFun)(QDomNode node,ProgramXmlLine *line);

#endif // PROGRAMXMLLINE_H
