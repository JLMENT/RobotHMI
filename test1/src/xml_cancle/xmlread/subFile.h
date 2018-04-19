#ifndef SUBFILE_H
#define SUBFILE_H
typedef struct
{
    QString fileName;				//进入下一层子程序时，保持的程序文件名
    int     fileLine;				//进入到子程序时，执行call的行号
}SubFile;
#endif // SUBFILE_H
