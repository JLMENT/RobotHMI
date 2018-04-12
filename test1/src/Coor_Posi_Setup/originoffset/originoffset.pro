#-------------------------------------------------
#
# Project created by QtCreator 2018-03-22T11:18:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = originoffset
TEMPLATE = app


SOURCES += main.cpp\
        originoffsetwidget.cpp \
    setting/configset.cpp

HEADERS  += originoffsetwidget.h \
    setting/configset.h

RESOURCES += \
    originsrc.qrc
