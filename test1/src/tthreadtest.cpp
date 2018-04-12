#include "tthreadtest.h"

TthreadTest::TthreadTest(QString file)
{
}
void TthreadTest::run()
{
    emit Testsig(123);
}
