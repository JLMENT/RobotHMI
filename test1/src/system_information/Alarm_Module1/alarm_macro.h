#ifndef ALARM_MACRO_H
#define ALARM_MACRO_H

//////测试开启关闭宏///////
#define ALARM_DEBUG_STATUS       true

//错误与轴组运动状态管理及编码器数据管理等相关
#define ERROR_ALARM_DATA_OVERFLOW_CODE                      1000
#define ERROR_SYSTEM_INTERNAL_OVERTIME_CODE                 1001
#define ERROR_INVERSE_KINEMATICS_FAIL_CODE                  1002
#define ERROR_INTERPOLATION_CONFIGURATION_PARAMETER_CODE    1003
#define ERROR_ENCODER_DATA_CODE                             1004
#define ERROR_ZERO_POSITION_ENCODER_DATA_CODE               1005
#define ERROR_ZERO_POSITION_FILE_CODE                       1006
#define ERROR_JOINT_FIND_REFERENCE_CODE                     1007
#define ERROR_ENABLE_DISNABLE_SERVO_CODE                    1008
#define ERROR_REQUIRE_SERVO_STATUS_CODE                     1009
#define ERROR_SERVO_ALARM_CODE                              1010
#define ERROR_PID_PARAAMETER_CODE                           1011
#define ERROR_SERVO_POSITIVE_LIMITATION_CODE                1012
#define ERROR_SERVO_NEGATIVE_LIMITATION_CODE                1013
#define ERROR_GT_ORDER_CODE                                 1014
#define ERROR_INTERPOLATION_PROGRAM_CODE                    1015
#define ERROR_SERVO_CODE                                    1016
#define ERROR_HARDWARE_PARAMETER_READ_CODE                  1017

//配置文件相关错误信息列表
#define ERROR_SYSTEM_INTERNAl1_CODE                         1100
#define ERROR_CONFIGURATION_FILE_PARAMETER_CODE             1101
#define ERROR_KINEMATICS_INTERPOLATION_AXIS_NUM_CODE        1102
#define ERROR_AUXILIARY_AXIS_CODE                           1103
#define ERROR_DH_PARAMETER_UNIT_CODE                        1104
#define ERROR_DH_PARAMETER_CODE                             1105
#define ERROR_JOINT_REDUCTION_RATIO_NUMERATOR_CODE          1106
#define ERROR_JOINT_REDUCTION_RATIO_DENOMINATOR_CODE        1107
#define ERROR_MOTOR_EXTREMITY_SPEED_CODE                    1108
#define ERROR_MOTOR_ALARM_SPEED_PERCENT_CODE                1109
#define ERROR_MOTOR_A_ROUND_ADD_ENCORDER_DATA_CODE          1110
#define ERROR_A_ROUND_ABSOLUTE_ENCORDER_DATA_CODE           1111
#define ERROR_KINEMATICS_SCOPE_UNIT_CODE                    1112
#define ERROR_KINEMATICS_SCOPE_EXTREMITY_CODE               1113
#define ERROR_KINEMATICS_SCOPE_EXTREMITY_OFFSET1_CODE       1114
#define ERROR_KINEMATICS_SCOPE_EXTREMITY_OFFSET2_CODE       1115
#define ERROR_JOINT_UNIT_CONFIGURATION_CODE                 1116
#define ERROR_SIX_AXIS_EXTREMITY_POSITION_CODE              1117
#define ERROR_SIX_AXIS_EXTREMITY_VALUE1_CODE                1118
#define ERROR_SIX_AXIS_EXTREMITY_VALUE1_CODE                1119
#define ERROR_JOINT_ALARM_STOP_DEC_CODE                     1120
#define ERROR_JOINT_ALARM_STOP_ACC_TIME_CODE                1121
#define ERROR_JOINT_SPEED_PERCENT_CODE                      1122
#define ERROR_JOINT_ACC_CODE                                1123
#define ERROR_MOVJ_SPEED_CODE                               1124
#define ERROR_MOVJ_ACC_CODE                                 1125
#define ERROR_MOVJ_DEC_CODE                                 1126
#define ERROR_DESCARTES_UNIT_CODE                           1127
#define ERROR_DESCARTES_MOTION_SCOPE_CODE                   1128
#define ERROR_DESCARTES_MOTION_LOWER_BIAS_CODE              1129
#define ERROR_DESCARTES_MOTION_UPPER_BIAS_CODE              1130
#define ERROR_INTERNAL_ERROR1_CODE                          1131
#define ERROR_INTERNAL_ERROR2_CODE                          1132
#define ERROR_DESCARTES_MOVP_ALARM_BRAKE_DEC_PARAMETER_CODE 1133
#define ERROR_DESCARTES_POINT_MOTION_SPEED_PARAMETER_CODE   1134
#define ERROR_DESCARTES_POINT_MOTION_ACCDEC_PARAMETER_CODE  1135
#define ERROR_DESCARTES_PTP_SPEED_PARAMETER_CODE            1136
#define ERROR_DESCARTES_PTP_ACC_PARAMETER_CODE              1137
#define ERROR_DESCARTES_PTP_DEC_PARAMETER_CODE              1138
#define ERROR_CP_ALARM_BRAKE_DEC_PARAMETER_CODE             1139
#define ERROR_CP_MOTION_MAX_SPEED_CODE                      1140
#define ERROR_CP_MOTION_MAX_ACC_CODE                        1141
#define ERROR_CP_MOTION_MAX_DEC_CODE                        1142
#define ERROR_CP_MOTION_MAX_ALARM_BRAKE_ACC_TIME_CODE       1143
#define ERROR_CP_ROTATE_ALARM_BRAKE_DEC_CODE                1144
#define ERROR_CP_ROTATE_SPEED_CODE                          1145
#define ERROR_CP_ROTATE_ACC_CODE                            1146
#define ERROR_CP_ROTATE_DEC_CODE                            1147
#define ERROR_CP_ROTATE_INTERPOLATION_ACC_TIME_CODE         1148
#define ERROR_CP_TRANSITION_SPEED_CODE                      1149
#define ERROR_INTERPOLATION_PERIOD_CODE                     1150
#define ERROR_SYSTEM_INTERNAL_PARAMETER_CODE                1151
#define ERROR_KINEMATICS_FORWARD_CALC_CONFIGURATION_CODE    1152

//运动插补常规错误代码
#define ERROR_MOTION_BEYOND_WORK_SPACE_CODE                 1200
#define ERROR_JOINT_MOTION_SPEED_BEYOND_SETUP_CODE          1201
#define ERROR_INTERPOLATION_IDENDIFICATIION_MOTOR_PATTERN_CODE  1202
#define ERROR_INTERNAL_DEBUG1_CODE                          1203
#define ERROR_INTERNAL_DEBUG2_CODE                          1204
#define ERROR_COORDINATE_SWITCH_CODE                        1205
#define ERROR_FORWARD_KINEMATICS_CALC_CODE                  1206
#define ERROR_DESCARTES_ATTITUDE_SWITCH_CODE                1207
#define ERROR_SINGULAR_POINT_CODE                           1208
#define ERROR_SYSTEM_INTERNAL2_CODE                         1209
#define ERROR_SYSTEM_INTERNAL_BRUTE_FORCE_FILTER_CODE       1210

//点动Jog运动时出现的错误
#define ERROR_JOINT_POINT_MOTION_SPEED_PERCETN_CODE         1300
#define ERROR_DESCARTES_ATTITUDE_MOTION1_CODE                1301

//PTP运动时出现的错误及异常
#define ERROR_PTP_SPEED_PERCENT_BEYOND_1_CODE               1400
#define ERROR_DESCARTES_ATTITUDE_MOTION2_CODE               1401
#define ERROR_DESCARTES_MOVP_FORWARD_KINEMATICS_CALC_CODE   1402
#define ERROR_NOT_OPEN_CODE                                 1403
#define ERROR_MOVP_MOVJ_SPEED_CODE                          1404
#define ERROR_MOVP_MOVJ_ACC_CODE                            1405
#define ERROR_MOVP_MOVJ_DEC_CODE                            1406
#define ERROR_MOVP_MOVJ_JERKTIME_CODE                       1407


//CP连续运动时出现的错误及异常
#define ERROR_CP_MOVL_MOVC_SPEED_PERCENT_CODE               1500
#define ERROR_CP_LENGTH_TOO_LONG_CODE                       1501
#define ERROR_CP_BLENDING_LENGTH_TOO_LONG_CODE              1502
#define ERROR_CP_BLENDING_PARAMETER_CODE                    1503
#define ERROR_CP_JERTIME_PARAMETER_CODE                     1504
#define ERROR_CP_CORDER_SPEED_PARAMETER_CODE                1505
#define ERROR_CP_CORDER_ACC_CODE                            1506
#define ERROR_CP_CORDER_DEC_CODE                            1507
#define ERROR_CP_CORDER_BEFORE_CODE                         1508
#define ERROR_CP_SYSTEM_INTERNAL_CODE                       1509
#define ERROR_CP_PATH_SMOOTHING_FACTOR_CODE                 1510
#define ERROR_CP_FORWARD_KINEMATICS_CALC_CODE               1511
#define ERROR_CP_CORDER_TOO_MANY_CODE                       1512
#define ERROR_MOVC_CORDER_CODE                              1513

//坐标系管理及工具管理出现的错误及异常
#define ERROR_COORDINATE_ASSIGNMENT_CODE                    1600
#define ERROR_COORDINATE_DATAPOINT_INCOMPLETE_CODE          1601
#define ERROR_COORDINATE_O0_CODE                            1602
#define ERROR_COORDINATE_P1_CODE                            1603
#define ERROR_COORDINATE_P2_CODE                            1604
#define ERROR_COORDINATE_P3_CODE                            1605
#define ERROR_COORDINATE_FILE_OPEN_ERROR_CODE               1606
#define ERROR_COORDINATE_FILE_READ_ERROR_CODE               1607
#define ERROR_COORDINATE_POINTS_TOO_CLOSE_CODE              1608
#define ERROR_TOOLCOORDINATE_SIXPOINTS_TOO_CLOSE_CODE       1609
#define ERROR_TOOLCOORDINATE_POINT_P1_CODE                  1610
#define ERROR_TOOLCOORDINATE_POINT_P2_CODE                  1611
#define ERROR_TOOLCOORDINATE_POINT_P3_CODE                  1612
#define ERROR_TOOLCOORDINATE_POINT_P4_CODE                  1613
#define ERROR_TOOLCOORDINATE_POINT_P5_CODE                  1614
#define ERROR_TOOLCOORDINATE_POINT_P6_CODE                  1615
#define ERROR_TOOLCOORDINATE_DATAPOINT_INCOMPLETE_CODE      1616


//二级错误
//错误等级稍低，错误与操作相关
#define ERROR_PROGRAM_CONTENT_LISTSHOW_CODE                 2001
#define ERROR_NO_ID_POSITION_POINT_CODE                     2002
#define ERROR_TEACHFILE_EXCUTE_CODE                         2003
#define ERROR_LISTINSERT_NOT_ALLOWED_BEFORE_NOP_CODE        2004
#define ERROR_LISTINSERT_CHECK_INVALID_CODE                 2005
#define ERROR_TEACHFILE_EXCUTE_NEED_RESET_CODE              2006
#define ERROR_TEACHFILE_EDITFAIL_CODE                       2007
#define ERROR_TEACHFILE_INSERTERROR_CODE                    2008
#define ERROR_TEACHFILE_DELETE_CODE                         2009
#define ERROR_TEACHFILE_MODIFY_CODE                         2010
#define ERROR_TEACHFILE_NOT_FIND_CODE                       2011
#define ERROR_Cannotvfind_file_CODE                         2012
#define ERROR_TEACHFILE_ID_NOT_ALLOWED_CODE                 2013
#define ERROR_TEACHFILE_NOT_ALLOWED_SELECT_CODE             2014
#define ERROR_UNKNOWWORKMODEL_CODE                          2015
#define ERROR_LIST_EDIT_PARA_NULL_CODE                      2016
#define ERROR_MODIFY_ID_NOT_EQUAL_SELECT_ID_CODE            2017
#define ERROR_EDIT_SELECT_FIRST_LINE_CODE                   2018
#define ERROR_EDIT_SELECT_END_LINE_CODE                     2019
#define ERROR_EDIT_COPY_CODE                                2020
#define ERROR_EDIT_CUT_CODE                                 2021
#define ERROR_EDIT_PASTE_CODE                               2022
#define ERROR_TEACHFILE_NAME_ALREADY_EXIST_CODE             2023
#define ERROR_EMERGENCY_STOP_BUTTON_PRESSED_DOWN_CODE       2024


//////////////报警文件路径//////////////////////////////
#define ALARM_INFORMATION_PATH             "/opt/log/"
#define ALARM_RECORD_INFORMATION_PATH      "/opt/log/"



#endif // ALARM_MACRO_H

















