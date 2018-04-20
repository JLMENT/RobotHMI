#ifndef OPERATEPROGRAMXML_H
#define OPERATEPROGRAMXML_H

#include <QObject>
#include <QtCore>
#include <QDebug>
#include <QtXml>
#include "opXmlErrorType.h"
#include "programXmlLine.h"
#include "xmlTagName.h"

#define OP_PROGRAM_DEBUG            0x03
#define OP_PROGRAM_DEBUG_ERROR      0x01
#define OP_PROGRAM_DEBUG_INFOR      0x02

/*
  Create this class to operate usr edited program file
  like program.xml and program_position.xml.
  The program file is organized and edited by line,so this class will
  only supply methods that could operate one line of the file.
*/

class OperateProgramXml
{

public:
    explicit OperateProgramXml();

    int init(QString fileName);
    
    int readLine(int lineNumber);

    ProgramXmlLine getLine();

private:
    ProgramXmlLine line;
    QDomElement programRoot;
    QDomDocument positionDoc;
    QDomDocument usrDoc;
    QDomDocument toolDoc;

    int openFile(QString fileName);
    int openPositionFile(QString fileName);
    void initLine(void);
    CommandType readCmdType(QDomElement cmdType);
    int readVelocity(QDomNode vel,Velocity *out);
    int readAcc(QDomNode acc,double *out);
    int readPosition(QDomNode position,Position *out);
    int readPL(QDomNode pl,int *out);
    int readCondition(QDomNode condition,Condition *out);
    int readNwait(QDomNode nwait,int *out);
    int readUsrInformation(QDomNode usr, UsrInformation *out);
    int readToolInformation(QDomNode tool, ToolInformation *out);
    int readIOPort(QDomNode port,int *out);
    int readOutputValue(QDomNode output,DigitalValue *out);
    int readByteNumber(QDomNode number,int *out);
    int readFileName(QDomNode file,QString *out);
    int readLabelNumber(QDomNode label,int *out);
    int readTime(QDomNode time,double *out);


    int readMovj(QDomNode node,ProgramXmlLine *line);
    int readMovl(QDomNode node,ProgramXmlLine *line);
    int readMovc(QDomNode node,ProgramXmlLine *line);
    int readSpeed(QDomNode node,ProgramXmlLine *line);
    int readDout(QDomNode node,ProgramXmlLine *line);
    int readDin(QDomNode node,ProgramXmlLine *line);
    int readJump(QDomNode node,ProgramXmlLine *line);
    int readLabel(QDomNode node,ProgramXmlLine *line);
    int readPause(QDomNode node,ProgramXmlLine *line);
    int readTimer(QDomNode node,ProgramXmlLine *line);
    int readCall(QDomNode node,ProgramXmlLine *line);
    int readRet(QDomNode node,ProgramXmlLine *line);
    int readNOP(QDomNode node,ProgramXmlLine *line);
    int readEND(QDomNode node,ProgramXmlLine *line);
    ReadParamFun readParamFun[COMMAND_END_TYPE+1];
};

#endif // OPERATEPROGRAMXML_H
