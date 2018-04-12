INCLUDEPATH +=$$PWD
DEPENDPATH +=$$PWD

SOURCES += $$PWD/editkeyboard.cpp \
    $$PWD/keyboard.cpp \
    $$PWD/digitkeydialog.cpp \
    $$PWD/digetedit.cpp

HEADERS  += $$PWD/editkeyboard.h \
    $$PWD/keyboard.h \
    $$PWD/digitkeydialog.h \
    $$PWD/digetedit.h

#FORMS    += simulation_digit/keyboard.ui \
#    simulation_digit/digitkeydialog.ui

FORMS    += $$PWD/keyboard.ui \
    $$PWD/digitkeydialog.ui
