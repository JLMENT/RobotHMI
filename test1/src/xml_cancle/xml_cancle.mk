sp              :=  $(sp).x
dirstack_$(sp)  :=  $(d)
d               :=  $(dir)
CPP_H_$(d) := $(notdir $(wildcard $(d)/*.h))
DEP_MOC_CPP_$(d) := $(patsubst %.h, $(DEP_DIR)/moc_%.cpp, $(CPP_H_$(d)))
DEP_OBJS_$(d) := $(patsubst %.h, $(OBJ_DIR)/moc_%.$(DEP_DIR).cpp.o, $(CPP_H_$(d)))


CPP_SRCS_$(d) := $(notdir $(wildcard $(d)/*.cpp))
DEP_OBJS_$(d) += $(patsubst %.cpp, $(OBJ_DIR)/%.cpp.o, $(CPP_SRCS_$(d)))

C_SRCS_$(d) := $(notdir $(wildcard $(d)/*.c))
OBJS_$(d) := $(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(C_SRCS_$(d))))


#QT_DEP_MOC_CPP += $(DEP_MOC_CPP_$(d))
TDEPS += $(DEP_MOC_CPP_$(d))
CPP_OBJS += $(DEP_OBJS_$(d))
OBJS += $(OBJS_$(d))

CFLAGS_LOCAL_$(d) := 
CFLAGS_LOCAL_$(d) += -I$(d)
#CFLAGS_LOCAL_$(d) += $(CFLAGS_GLOBAL)

$(OBJS_$(d)): CFLAGS_LOCAL := $(CFLAGS_LOCAL_$(d))
$(DEP_OBJS_$(d)): CFLAGS_LOCAL := $(CFLAGS_LOCAL_$(d))

$(OBJ_DIR)/%.o: $(d)/%.c
	$(Q)$(COMPILE)

$(OBJ_DIR)/%.cpp.o: $(d)/%.cpp
	$(Q)$(CXX_COMPILE)

$(DEP_DIR)/moc_%.cpp: $(d)/%.h
	$(Q)$(QT_MOC_CPP)


d	:= $(dirstack_$(sp))
sp	:= $(basename $(sp))
