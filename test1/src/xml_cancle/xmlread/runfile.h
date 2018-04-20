#ifndef RUNFILE_H
#define RUNFILE_H
#include <QThread>
#include <xml_cancle/xmlread/operateprogramxml.h>
#include <QMap>
#include "subFile.h"

#define RF_PROGRAM_DEBUG            0x05
#define RF_PROGRAM_DEBUG_ERROR      0x01
#define RF_PROGRAM_DEBUG_INFOR      0x02
#define RF_PROGRAM_DEBUG_INVERSE	0x03

class RunFile;
typedef int (RunFile::*ExeLine)(int lineNumber);
class RunFile : public QThread
{
    Q_OBJECT
public:
    RunFile(QString fileName);      //构造函数，fileName表示需要运行的文件名
    //virtual ~RunFile();
    OperateProgramXml * op;         //操作XML文件的接口
    bool init();					//初始化函数。调用这个函数就会正向，并且从文件开始处运行fileName指定的文件
    bool init(int lineNumber , int mode);  //  从lineNumber制定的行号运行文件。
											//运行模式，mode: 0- forward ,1-inverse
    void run();							//QThread 回调函数，不需要外部调用
    void stop();							//运行停止。
    int exeLine(int lineNumber);				//内部正向运行函数。lineNumber表示运行行号。
    int exeInverseLine(int lineNumber);	//内部逆向运行函数。
    QString getFileName();					//获取当前运行文件名，用于在子程序递归调用时确定当前运行哪个子程序使用。
    int getCurrentNumber();				//获取当前运行行号，
    void setPause();							//暂停过后的继续运行。
    void interpPause();						//按下暂停键，让运行暂停。这里只能使解释器暂停，运动停止需要调用motion对应借口。

private:
    int inverse;								//是否是逆向运行的标志。 0: 
    QString fileName;							//构造函数输入的文件名。						
    ProgramXmlLine line;						//读入的一行程序内容
    int exeMovj(int lineNumber);				//执行movj命令
    int exeMovl(int lineNumber);				//执行movl命令
    int exeMovc(int lineNumber);				//执行movc命令
    int exeSpeed(int lineNumber);			//执行speed命令
    int exeDin(int lineNumber);				//执行DIN命令
    int exeDout(int lineNumber);				//制定DOUT命令
    int exePause(int lineNumber);			//执行暂停指令
    int exeTimer(int lineNumber);			//执行定时器指令
    int exeLabel(int lineNumber);			//记录标签
    int exeJump(int lineNumber);				//执行跳转
    int exeCall(int lineNumber);				//执行调用
    int exeRet(int lineNumber);				//执行返回
    int exeNop(int lineNumber);				//执行程序开始NOP
    int exeEnd(int lineNumber);				//执行程序结束END
    void scanLabel();						//文件开始时扫描标签函数
    int exeCondition();					//执行运行条件IF
    void waitForMotion();					//在执行后续命令之前需要等待运动执行完毕。
    ExeLine exe[COMMAND_END_TYPE+1];			//执行程序程序指针列表。
    int state;									//程序执行状态。
    int movcCount;								//连续输入的movC指令的个数。
    int jointType;								//关节类型: movC中连续输入的关节类型必须一致。

    double default_vj;							//默认的movj的速度值。当movj指令中不输入速度参数，使用这个变量中的速度。
    double default_vl;							//默认的movl和movc的线速度值。当movl和movc指令中不输入线速度参数，使用这个变量中的速度。
    double default_vr;							//默认的movl和movc的角速度值。当movl和movc指令中不输入角速度参数，使用这个变量中的速度。
    double default_acc;							//默认加速度
    int currentFileLine;						//当前文件行号。
    int pause;									//暂停指令状态。0: 执行暂停指令时，表示暂停。1: 表示按下循环启动，暂停结束。
    int runFilePause;							//文件暂停，表示按下暂停按键，程序暂停解释。0 : 表示未暂停。1 : 表示暂停解释。
    QMap <QString,int> labelMap;				//保存整个文件中标签的信息。一个标签包括两个信息: qstring类型的文件名，和一个int型的行号
    QList <SubFile> subList;					//子程序列表
    ProgramXmlLine nextLine;					//下一行程序内容，在逆向执行时使用。
//Q_SIGNALS:
//    void FileNameChanged(QString fileName);
//    void FileClosed();

signals:
    void FileNameChanged1(QString fileName);
    void FileClosed1();

};

#endif // RUNFILE_H
