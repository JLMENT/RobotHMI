#ifndef USR_MOTION_API_H
#define USR_MOTION_API_H
#include "motionCommandType.h"
#include "motionInterfaceBuffer.h"

#include "motionParameterType.h"
#include "motionConfig.h"
#include "motionFeedback.h"
#include "posemath.h"



#ifdef __cplusplus
extern "C" {
#endif

extern MotionConfig *emcmotConfig ;
extern MotionCommandBuffer *commandShmem ;
extern VRobotMotionCommand  *motCmd ;
extern MotionCommandQueue *interpList ;
extern VRobotMotionCommand *emcmotCommand;
extern MotionFeedback *motionFb;

extern int CTRL_ServoReset(void);			//ŷλŷ屨
extern int CTRL_ServoEnable(int enable);	//ŷʹܣenbale Ϊ0ʹ Ϊ1ʹ


extern int CTRL_USR_Init(void);
extern void CTRL_USR_Exit(void);



extern int CTRL_AddSingleAxisMove(SingleAxisMove *singleMove); //˶
extern int CTRL_AddJointMove(JointMoveInformation *jointMove,u32 lineNumber,u32 fileNumber);		//ؽڲ岹movj
extern int CTRL_AddLinearMove(LinearMoveInformation *movl,u32 lineNumber,u32 fileNumber);			//ֱ߲岹յλùؽڱʾ
extern int CTRL_AddCircularMove(CircularMoveInformation *movC,u32 lineNumber,u32 fileNumber);
extern void CTRL_MovementStop();										//˶ֹͣҺδִеҲִ
extern int CTRL_AddDescartesLinearMove(LinearDescartesMoveInformation *movDL,u32 lineNumber,u32 fileNumber);//ֱ߲岹յλx/y/zʾ
extern int CTRL_AddDescartesCircularMove(CircularDescartesMoveInformation *movDC,u32 lineNumber,u32 fileNumber);//Բ岹Ŀλʹõѿλֵ
extern void CTRL_GetJointValue(JointPoint * joint);
extern double CTRL_GetJointValueFor3DTest(int jointNumber);
extern double CTRL_GetPositionValue(int axis);


extern int CTRL_GetTCPInUserSpace(PointPose *pos,JointPoint *joint,UserCoordianteInformation* user,ToolCoordianteInformation* tool);//ؽλã㹤߼˵ûϵµλˡ
 extern int CTRL_GetTCPInUserSpaceInMatrix(PmHomogeneous *pos,JointPoint *joint,UserCoordianteInformation* user,ToolCoordianteInformation* tool); // ڲʹ

extern int CTRL_GetTCPInJoint(JointPoint *joint,PointPose *point,UserCoordianteInformation* user,ToolCoordianteInformation* tool);//֪λˣؽλýŵjointСֵΪ0ʱʾЧ
extern int CTRL_GetTCPInJointInMatrix(JointPoint *joint,JointPoint *preJoint,PmHomogeneous *point,UserCoordianteInformation* user,ToolCoordianteInformation* tool);

extern int CTRL_GetMotionStatus(MotionFeedback * fb); 
//extern	 void CTRL_SetSocket(char * IP, int port, int cycleTime);
//jp , ûĹؽֵϢout ûϵx/y/z/a/bcֵ
extern int CTRL_UserCalibration(ThreeJointPoints *jp, ToolCoordianteInformation *tool,UserCoordianteInformation *out);
extern int CTRL_ToolCalibration(JointPoint *jp,int pointNumber,ToolCoordianteInformation *out);

//ŷԭƫֵoffset ʾıֵaxisʾ:1-6
extern int CTRL_SetOriginOffset(s64 offset,u32 axis);
//ȡԭƫֵaxisΪ(1-6)offsetƫֵ
extern int CTRL_GetOriginOffset(s64 * offset,u32 axis);


//û˲, length : ˲ȣnum: ˲
extern int CTRL_SetPUMA(f64 length,u32 num);

//û˲, length : ˲ȣnum: ˲
extern int CTRL_GetPUMA(f64 *length,u32 num);



//ʾʱٶȣvelocity: õٶֵ
extern int CTRL_SetTeachLinearVelocity(f64 velocity);
//ʾʱٶȣvelocity: õٶֵ
extern int CTRL_GetTeachLinearVelocity(f64 *velocity);
//ֱ˶(MOVL) ٶȣvelocity: õٶֵ
extern int CTRL_SetLinearMaxVelocity(f64 velocity);
//ֱ˶(MOVL) ٶȣvelocity: õٶֵ
extern int CTRL_GetLinearMaxVelocity(f64 *velocity);
//ֱ˶(MOVL) ļٶȣacc: õļٶֵ
extern int CTRL_SetLinearMoveAcc(f64 acc);
//ֱ˶(MOVL) ļٶȣacc: õļٶֵ
extern int CTRL_GetLinearMoveAcc(f64 *acc);
//ת˶ٶȣvelocity: õٶֵ
extern int CTRL_SetRotateMoveVelocity(f64 velocity);
//ת˶ٶȣvelocity: õٶֵ
extern int CTRL_GetRotateMoveVelocity(f64 *velocity);
//ת˶ļٶȣacc:õļٶֵ
extern int CTRL_SetRotateMoveAcc(f64 acc);
//ת˶ļٶȣacc:õļٶֵ
extern int CTRL_GetRotateMoveAcc(f64 *acc);



//˶ޣlimit:ֵaxis:ؽں1-6  δ:X/Y/Z/A/B/C
extern int CTRL_SetLinearPositiveLimit(f64 limit,u32 axis);
//ȡ˶ޣlimit:ֵaxis:ؽں1-6  δ:X/Y/Z/A/B/C
extern int CTRL_GetLinearPositiveLimit(f64 *limit,u32 axis);
//˶ޣlimit:ֵaxis:ؽں1-6  δ:X/Y/Z/A/B/C
extern int CTRL_SetLinearNegativeLimit(f64 limit,u32 axis);
//ȡ˶ޣlimit:ֵaxis:ؽں1-6  δ:X/Y/Z/A/B/C
extern int CTRL_GetLinearNegativeLimit(f64 *limit,u32 axis);




//ùؽ˶ޣlimit:ֵaxis:ؽں1-6  δ:J1-J6
extern int CTRL_SetJointPositiveLimit(f64 limit,u32 axis);
//ȡؽ˶ޣlimit:ֵaxis:ؽں1-6  δ:J1-J6
extern int CTRL_GetJointPositiveLimit(f64 *limit,u32 axis);
//ùؽ˶ޣlimit:ֵaxis:ؽں1-6  δ:J1-J6
extern int CTRL_SetJointNegativeLimit(f64 limit,u32 axis);
//ȡؽ˶ޣlimit:ֵaxis:ؽں1-6  δ:J1-J6
extern int CTRL_GetJointNegativeLimit(f64 *limit,u32 axis);
//ùؽ˶ٶȣvelocity:ٶֵaxis:ؽں1-6  δ:J1-J6
extern int CTRL_SetJointMaxVelocity(f64 velocity,u32 axis);
//ùؽ˶ٶȣvelocity:ٶֵaxis:ؽں1-6  δ:J1-J6
extern int CTRL_GetJointMaxVelocity(f64 *velocity,u32 axis);

//ùؽ˶ٶȣacc:ٶֵaxis:ؽں1-6  δ:J1-J6
extern int CTRL_SetJointMaxAcc(f64 acc,u32 axis);
//ȡؽ˶ٶȣacc:ٶֵaxis:ؽں1-6  δ:J1-J6
extern int CTRL_GetJointMaxAcc(f64 *acc,u32 axis);
//øؽڵļٱȣdemoninator:ٱȷĸnumerator:ٱȷӣaxis:ؽں1-6  δ:J1-J6
extern int CTRL_SetReductionRate(s64 demoninator, s64 numerator, u32 axis);
//ȡؽڵļٱȣrate:ٱaxis:ؽں1-6  δ:J1-J6
extern int CTRL_GetReductionRate(s64 *demoninator, s64 *numerator,u32 axis);

//5/6ؽڵϱ
extern int CTRL_SetCoupleRate(s64 rate);

//ȡ5/6ؽڵϱ
extern int CTRL_GetCoupleRate(s64 *rate);
 

extern int CTRL_MotionPause();
extern int CTRL_MotionResume();




#ifdef __cplusplus
}
#endif	
	

#endif

