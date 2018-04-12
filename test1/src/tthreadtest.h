#ifndef TTHREADTEST_H
#define TTHREADTEST_H

#include <QThread>

class TthreadTest : public QThread
{
    Q_OBJECT
public:
    TthreadTest(QString file);
    void run();
    
signals:
    void Testsig(int);
    
public slots:
    
};

#endif // TTHREADTEST_H
