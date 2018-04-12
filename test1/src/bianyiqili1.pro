#-------------------------------------------------
#
# Project created by QtCreator 2017-09-06T10:49:38
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bianyiqi1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    page2.cpp \
    speedadjust.cpp \
    configdialog.cpp \
    specialwork.cpp \
    robotoriginpointlocation.cpp \
    commandlist.cpp \
    movecommand.cpp \
    axis.cpp \
    positionseriate.cpp \
    newfilename.cpp \
    simulationkeypad.cpp \
    commandinput.cpp \
    keypad.cpp \
    codeeditor/codeeditor.cpp \
    xml_cancle/xmlcancle.cpp \
    usr_motion_api/usr_motion_api.c \
    usr_motion_api/pumakin.c \
    usr_motion_api/_posemath.c \
    xml_cancle/xmlread/runfile.cpp \
    xml_cancle/xmlread/operateprogramxml.cpp \
    tthreadtest.cpp \
    xml_cancle/xmlcopy/xmlcopycut.cpp \
    file_manage/filemanage.cpp

HEADERS  += mainwindow.h \
    page2.h \
    speedadjust.h \
    configdialog.h \
    specialwork.h \
    robotoriginpointlocation.h \
    include.h \
    commandlist.h \
    movecommand.h \
    typedef.h \
    axis.h \
    positionseriate.h \
    newfilename.h \
    simulationkeypad.h \
    commandinput.h \
    keypad.h \
    codeeditor/codeeditor.h \
    xml_cancle/xmlcancle.h \
    usr_motion_api/usr_motion_api.h \
    usr_motion_api/posemath.h \
    usr_motion_api/motionParameterType.h \
    usr_motion_api/motionInterfaceBuffer.h \
    usr_motion_api/motionFeedback.h \
    usr_motion_api/motionConfig.h \
    usr_motion_api/motionCommandType.h \
    usr_motion_api/Common.h \
    usr_motion_api/motionParameter.h \
    usr_motion_api/motionIner.h \
    usr_motion_api/tp.h \
    usr_motion_api/tc.h \
    usr_motion_api/robotpos.h \
    usr_motion_api/kinematics.h \
    usr_motion_api/rtos.h \
    usr_motion_api/motionErrorType.h \
    usr_motion_api/pumakins.h \
    usr_motion_api/sincos.h \
    xml_cancle/xmlread/xmlTagName.h \
    xml_cancle/xmlread/subFile.h \
    xml_cancle/xmlread/runfile.h \
    xml_cancle/xmlread/programXmlLine.h \
    xml_cancle/xmlread/opXmlErrorType.h \
    xml_cancle/xmlread/operateprogramxml.h \
    tthreadtest.h \
    xml_cancle/xmlcopy/xmlcopycut.h \
    file_manage/filemanage.h

FORMS    += mainwindow.ui \
    page1.ui \
    page2.ui \
    dialog.ui \
    speedadjust.ui \
    specialwork.ui \
    robotoriginpointlocation.ui \
    commandlist.ui \
    movecommand.ui \
    axis.ui \
    positionseriate.ui \
    newfilename.ui \
    simulationkeypad.ui \
    commandinput.ui \
    keypad.ui


include($$PWD/keyboardedit/simulation_digit.pri)
include($$PWD/numeric_type_module/numeric_type.pri)
include($$PWD/robot_setup/parametersofspaceofaxialjoint/axis_param.pri)
include($$PWD/robot_setup/descartesspace/descartesspace.pri)
include($$PWD/robot_setup/cpspacesetup/cpspacesetup.pri)
include($$PWD/robot_setup/othersetup/othersetup.pri)
include($$PWD/robot_setup/DHSpace/DHSpace.pri)

include ($$PWD/Coor_Posi_Setup/originoffset/originoffset.pri)
include ($$PWD/Coor_Posi_Setup/currentposition/currentposition.pri)
include ($$PWD/Coor_Posi_Setup/CoordinateManage1/CoordinateManage1.pri)
include ($$PWD/Coor_Posi_Setup/Toolmanage/Toolmanage.pri)


RESOURCES += \
    resource.qrc

DISTFILES +=

