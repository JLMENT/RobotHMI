#ifndef FILEMANAGE_H
#define FILEMANAGE_H

#include <QObject>
#include <QStringList>
#include <QDirIterator>
#include <QDir>
#include "file_path_macro.h"

class FileManage : public QObject
{
    Q_OBJECT
public:
    explicit FileManage(QObject *parent = 0);
    void display_source_program_list();
    QStringList strlist;

private:
   // QStringList strlist;
signals:
    
public slots:
    
};

#endif // FILEMANAGE_H
