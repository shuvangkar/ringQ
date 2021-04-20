#include "ramqPro.h"





struct ramq_t *ramqNew(void *baseAddr; uint32_t len)
{
	struct ramq_t *me = malloc(sizeof(struct ramq_t));
	if(me != NULL)
	{
		me -> _baseAddr = baseAddr;
		me -> _len = len;
		me -> _endAddr = (uint8_t*)baseAddr + len;
		me -> _head.ptr = baseAddr;
		me -> _tail.ptr = baseAddr;

		me -> _isLock = false;
		me -> _leadingHead = true;
		me -> _qState = RESET;
	}
	return me;
}

bool  ramqPush(struct ramq_t *me, void *dataPtr, uint16_t len)
{
	if(me -> _isLock == false)
	{
		len += sizeof(qObj_t);
		uint8_t *nextHead = me -> _head.ptr + len;

		//reset logic for pointer
		if(nextHead > me -> _endAddr)
		{
			me -> _head.ptr = me -> _baseAddr
			nextHead = me -> _head.ptr + len; //update data end 
			_leadingHead = false;
		}

		//determine lock conditions
		if(_leadingHead == false)
		{
			if(nextHead >= me -> _tail.ptr)
			{
				//need to reset of cannot save data 
				me -> _isLock = true;
				return false
			}
		}
		


		me -> _head.len = len - sizeof(qObj_t);
		me -> _head.nextPtr = nextHead;
		
		uint8_t *dataPtr = me -> _head.ptr + sizeof(struct qObj_t);
		memcpy(dataPtr,dataPtr,me -> _head.len);
		//increment to next head
		me -> _head.ptr = nextHead;

		me -> _qState  = RUNNING;
		return true;
	}
	
}


struct qObj_t *ramqPop(struct ramq_t *me)
{
	if(me -> _qState == RUNNING)
	{
		qObj_t *currentTail= &_tail;

		return &_tail;

	}
}