#-------------------------------------------------
#
# Project created by QtCreator 2018-03-26T10:23:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CoordinateManage1
TEMPLATE = app


SOURCES += main.cpp\
        coordinatemanagewidget.cpp \
    setting/configset.cpp \
    #coordinateeditoperatewidget.cpp

HEADERS  += coordinatemanagewidget.h \
    coordinatemamagestatus.h \
    setting/configset.h \
    #coordinateeditoperatewidget.h

RESOURCES += \
    src.qrc
