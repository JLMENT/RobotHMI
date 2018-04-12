#ifndef OPXMLERRORTYPE_H
#define OPXMLERRORTYPE_H

#define CANNOT_OPEN_PROGRAM_FILE                    0X01
#define CANNOT_OPEN_POSITION_FILE                   0X02
#define CANNOT_MAP_PROGRAM_FILE_TO_DOM              0X03
#define CANNOT_MAP_POSITION_FILE_TO_DOM             0x04
#define READ_LINE_FIRST_CHILD_NULL                  0x05
#define READ_LINE_CANNOT_FIND_CMD_TYPE              0x06
#define READ_POSITION_NO_POSITION_TAG               0x07
#define READ_POSITION_NO_POSITION_NAME              0x08
#define READ_POSITION_INFORMATION_FAILED            0x09
#define FAILD_TO_READ_VELOCITY                      0x0a
#define FAILD_TO_READ_ACC                           0x0b
#define FAILD_TO_READ_PL                            0x0c
#define FAILD_TO_READ_IF_TAG                        0x0d
#define FAILD_TO_READ_IO_TYPE                       0x0e
#define READ_CONDITION_INFORMATION_ERROR            0x0f
#define FAILD_TO_READ_NWAIT                         0x10
#define FAILD_TO_READ_USR_FILE                      0x11
#define FAILD_TO_READ_TOOL_FILE                     0x12
#define CANNOT_MAP_USR_FILE_TO_DOM                  0X13
#define CANNOT_MAP_TOOL_FILE_TO_DOM                 0x14
#define READ_USR_NO_USR_NAME                        0x15
#define READ_USR_INFORMATION_FAILED                 0x16
#define READ_TOOL_NO_TOOL_NAME                      0x15
#define READ_TOOL_INFORMATION_FAILED                0x16
#define FAILD_TO_READ_IO_PORT                       0x17
#define FAILD_TO_READ_BYTE_ADDRESS                  0x18
#define FAILD_TO_READ_FILE_NAME                     0x19
#define FAILD_TO_READ_LABEL_NUMBER                  0x1a
#define UNKNOWN_VELOCITY_TYPE                       0x1b



#define ADD_MOVJ_WITH_NON_JOINT_POS                 0x30
#define UNKNONW_COORDINATE_TYPE                     0x31
#define CAN_NOT_DO_MOVL_BEFORE_END_OF_MOVC          0x32
#define CAN_NOT_DO_MOVJ_BEFORE_END_OF_MOVC          0x33
#define MOVC_POSTION_TYPE_CONFLIC                   0x34

#endif // OPXMLERRORTYPE_H
