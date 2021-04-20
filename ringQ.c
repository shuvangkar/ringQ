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
	}
	return me;
}

bool  ramqPush(struct ramq_t *me, void *dataPtr, uint16_t len)
{
	if(me -> _isLock == false)
	{
		// uint8_t *head = me -> _head.ptr;
		uint8_t *tail = me -> _tail.ptr;
		uint8_t *headEnd = me -> _head.ptr + len;

		//reset logic for pointer
		if(headEnd > me -> _endAddr)
		{
			me -> _head.ptr = me -> _baseAddr
			headEnd = me -> _head.ptr + len; //update data end 
			_leadingHead = false;
		}

		//determine lock conditions
		if(_leadingHead == false)
		{
			if(headEnd >= tail)
			{
				//need to reset of cannot save data 
				me -> _isLock = true;
			}
		}
		

		uint8_t *currentStrPtr = me -> _head.ptr + sizeof(struct qObj_t);
		memcpy(currentStrPtr,dataPtr,len);
		me -> _head.len = len;

		//increment 
		me -> _head.ptr += len + sizeof(struct qObj_t);

		//reset logic
		
		//determine lock condition
	}
	
}