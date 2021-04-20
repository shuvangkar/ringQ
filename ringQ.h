
#ifndef _RAMQ_PRO_H_
#define _RAMQ_PRO_H_


//|....qObj_t.....|.........Data.............|

struct qObj_t
{
	uint8_t *ptr; //point current data pointer 
	uint8_t *nextPtr; //keep track of the next buffer pointer starting
	uint16_t len;  //data length of current pointer 
}

struct ramq_t
{
	uint8_t *_baseAddr;
	uint8_t *_endAddr;
	uint32_t _len;
	struct qObj_t _head;
	struct qObj_t _tail;
	bool _isLock;
	bool _leadingHead; //true means head > tail | false means head < tail
}

struct ramq_t *ramqNew(void *baseAddr; uint32_t len);
void ramqPush(struct ramq_t *me, void *dataPtr, uint16_t len);
struct qObj_t *ramqPop(struct ramq_t *ramq);
void ramqReset(struct ramq_t *ramq);
bool ramqIsLocked(struct ramq_t *ramq);


#endif