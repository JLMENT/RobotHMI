
#include "Common.h"
#include "motionErrorType.h"


#ifdef RT_TASK
#include "contrller.h"
#include "mot_priv.h"
	
#else
#include "usr_motion_api.h"
#endif
int CTRL_hasError()
{
	if(errorBuffer->end!=errorBuffer->start)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int CTRL_readFirstError(ErrorData* error)
{
	if(errorBuffer->end!=errorBuffer->start)
	{
		error = &(errorBuffer->error[errorBuffer->start]);
		return 0;
	}
	else
	{
		return -1;
	}
}
u32 CTRL_currrentErrorCount()
{
	if(errorBuffer->end >= errorBuffer->start)
	{
		return errorBuffer->end - errorBuffer->start;
	}
	else
	{
		return errorBuffer->end - errorBuffer->start + MAX_ERROR_NUMBER;
	}
}
int CTRL_readErrorAt(u32 pos,ErrorData* error)
{
	u32 read;
	read = (pos + errorBuffer->start)%MAX_ERROR_NUMBER;
	if(read - errorBuffer->start < 0)
	{
		read+= MAX_ERROR_NUMBER;
	}
	if(read>CTRL_currrentErrorCount())
	{
		return -1;
	}
	error = &(errorBuffer->error[read]);
	return 0;
}
#ifdef RT_TASK
int insertError(u32 type,u8 joint)
{
	if ((errorBuffer->end + 1) % MAX_ERROR_NUMBER== errorBuffer->start)
	{
		return -1;
	}
	LOCK(Mutex);
	errorBuffer->error[errorBuffer->end].errorCode = type;
	errorBuffer->error[errorBuffer->end].jointNumber= joint;
	errorBuffer->end+= 1;
	UNLOCK(Mutex);
	return 0;
}
#endif
int CTRL_clearError()
{
	errorBuffer->start = 0;
	errorBuffer->end = 0;
}
int CTRL_removeError()
{
	if(errorBuffer->start!=errorBuffer->end)
	{
		errorBuffer->start+=1;	
	}
	else
	{
		//there is nothing to remove
		return 0;
	}
}





