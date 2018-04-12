#-------------------------------------------------
#
# Project created by QtCreator 2018-03-30T10:14:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Toolmanage
TEMPLATE = app


SOURCES += main.cpp\
        toolmanagewidget.cpp \
    setting/configset.cpp

HEADERS  += toolmanagewidget.h \
    setting/configset.h

RESOURCES += \
    src.qrc
