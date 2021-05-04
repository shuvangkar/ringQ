
#ifndef _RAMQ_PRO_H_
#define _RAMQ_PRO_H_

#include <Arduino.h>
#include "Serial.h"

#ifdef __cplusplus
extern "C" {
#endif


//|....qObj_t.....|.........Data.............|

struct qObj_t
{
	uint8_t *ptr; //point current data pointer 
	uint8_t *nextPtr; //keep track of the next buffer pointer 
	uint16_t len;  //data length of current pointer 
}__attribute__((packed));

enum qState_t
{
  RESET = 0,
  RUNNING = 1,
  NO_DATA = 3,
};

struct ramq_t
{
	bool _isLock;
	bool _leadingHead; //true means head > tail | false means head < tail
	uint8_t *_baseAddr;
	uint8_t *_endAddr;
	uint32_t _len;
	struct qObj_t _head;
	struct qObj_t _tail;
	enum qState_t _qState;
}__attribute__((packed));

struct ramq_t *ramqNew(void *baseAddr, uint32_t len);
bool ramqPush(struct ramq_t *me, void *dataPtr, uint16_t len);
struct qObj_t *ramqPop(struct ramq_t *me);
void ramqReset(struct ramq_t *ramq);
bool ramqIsLocked(struct ramq_t *ramq);


#ifdef __cplusplus
}
#endif


#endif