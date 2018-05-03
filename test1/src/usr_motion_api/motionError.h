#ifndef MOTION_ERROR_H
#define MOTION_ERROR_H
#include "Common.h"
#include "motionErrorType.h"
#ifdef __cplusplus
extern "C" {
#endif


//if has an error or more ,return 1 ,else return 0
extern int CTRL_hasError();
//read the first error , to the pointer error if there is an error, and return 0,else return -1; 
extern int CTRL_readFirstError(ErrorData* error);
//return the count current errors
extern u32 CTRL_currrentErrorCount();
//read error at pos to the pointer error , if succeed return 0 ,else return -1
extern int CTRL_readErrorAt(u32 pos,ErrorData* error);


//inset an error to the buffer, type means the error type,joint means the  
extern int insertError(u32 type,u8 joint);
//clear all errors that can be removed, 
//that means some automatically errors may not be removed cause they might still be error state
extern int CTRL_clearError();
//remove one error on the top of the buffer
extern int CTRL_removeError();
#ifdef __cplusplus
}
#endif	

#endif
