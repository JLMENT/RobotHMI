
all: obj-target application-target

ifndef PREFIX_PATH
PREFIX_PATH := ../..
endif

ifndef PREFIX_
PREFIX_ := ..
endif

ifndef GUI_SRC
GUI_SRC := $(PWD)
endif

INS_LIBA=0

TARGET = ctlsys_gui

COROSS_COMPILE ?=
OS_ROOT := $(ROBOT_CTLSYS_ARCH)

dir := $(OS_ROOT)/mk
include $(dir)/common.mk

dir := $(OS_ROOT)/mk
include $(dir)/common-sys.mk

dir := $(OS_ROOT)/mk
include $(dir)/app-qt.mk

QT_UI += $(notdir $(wildcard $(GUI_SRC)/*.ui))
QT_DEP_H += $(patsubst %.ui, $(DEP_DIR)/ui_%.h, $(QT_UI))

CPP_H += $(notdir $(wildcard $(GUI_SRC)/*.h))
#MOC_CPP_SRC += $(patsubst main.cpp,, $(CPP_H))
MOC_CPP_SRC += $(CPP_H)
QT_DEP_MOC_CPP += $(patsubst %.h, $(DEP_DIR)/moc_%.cpp, $(MOC_CPP_SRC))
QT_DEP_OBJS += $(patsubst %.h, $(OBJ_DIR)/moc_%.$(DEP_DIR).cpp.o, $(MOC_CPP_SRC))

QT_QRC += $(notdir $(wildcard $(GUI_SRC)/*.qrc))
QT_DEP_QRC_CPP += $(patsubst %.qrc, $(DEP_DIR)/qrc_%.cpp, $(QT_QRC))
QT_DEP_OBJS += $(patsubst %.qrc, $(OBJ_DIR)/qrc_%.$(DEP_DIR).cpp.o, $(QT_QRC))

CPP_SRC += $(notdir $(wildcard $(GUI_SRC)/*.cpp))
CPP_OBJS += $(patsubst %.cpp, $(OBJ_DIR)/%.cpp.o, $(CPP_SRC))
CPP_OBJS += $(QT_DEP_OBJS)

OBJS := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(wildcard $(GUI_SRC)/*.c)))

GUI_CFLAGS = 

GUI_INC := -I$(GUI_SRC) 
GUI_INC += -I$(GUI_SRC)/$(PREFIX_PATH)/common -I$(GUI_SRC)/$(PREFIX_)/inc
GUI_INC += -I$(GUI_SRC)/codeeditor
GUI_INC += -I$(GUI_SRC)/xml_cancle
GUI_INC += -I$(GUI_SRC)/usr_motion_api

dir := $(GUI_SRC)/codeeditor
include $(dir)/codeeditor.mk

dir := $(GUI_SRC)/xml_cancle
include $(dir)/xml_cancle.mk

dir := $(GUI_SRC)/usr_motion_api
include $(dir)/usr_motion_api.mk

CFLAGS_GLOBAL += $(GUI_CFLAGS)
CFLAGS_GLOBAL += $(PLATFORM_COMMON_INC) $(PLATFORM_UTILS_INC)
CFLAGS_GLOBAL += $(PLATFORM_UTILS_DEBUG_INC)
CFLAGS_GLOBAL += $(FRAMEWORK_COMMON_INC) $(FRAMEWORK_FSM_INC)
CFLAGS_GLOBAL += $(PLATFORM_COMMON_CFLAGS) $(FRAMEWORK_COMMON_CFLAGS)
CFLAGS_GLOBAL += $(GUI_INC)

LDFLAGS_GLOBAL += -L$(GUI_SRC)/$(PREFIX_)/lib
LDFLAGS_GLOBAL += $(LD_PLATFORM_UTILS_LIBS) $(LD_FRAMEWORK_FSM_LIBS)
LDFLAGS_GLOBAL += $(LD_PLATFORM_COMMON_LIBS)

TDEPS += $(QT_DEP_H) $(QT_DEP_MOC_CPP) $(QT_DEP_QRC_CPP)

dir := $(OS_ROOT)/mk
include $(dir)/application.mk


clean:
	$(Q)$(RM) -rf $(DEP_DIR) $(OBJ_DIR) $(TARGET) 

export INS_LIBA
