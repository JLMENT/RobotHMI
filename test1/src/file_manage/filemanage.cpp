#include "filemanage.h"
#include "QMessageBox"

FileManage::FileManage(QObject *parent) :
    QObject(parent)
{
}

void FileManage::display_source_program_list()
{
    //QDir dir = QDir::path("/test1/bianyiqili1-build-desktop-Qt_4_8_7_in_PATH__System__Release");
    strlist.clear();
    QDir dir = QDir::current();
    if(!dir.exists()){
        QMessageBox msgBox;
        msgBox.setText("does not exist!");
        msgBox.exec();
    }
//    QDirIterator qdi(dir.absolutePath(),
//                     QStringList()<<"*.xml",
//                     QDir::NoSymLinks|QDir::Files,
//                     QDirIterator::NoIteratorFlags);
    QStringList filter;
    filter<<"*.xml";
    dir.setNameFilters(filter);
    QList<QFileInfo>*fileInfo = new QList<QFileInfo>(dir.entryInfoList(filter));
    for(int i=0;i<fileInfo->count();i++)
    {
        strlist.append(fileInfo->at(i).baseName());
    }
}
