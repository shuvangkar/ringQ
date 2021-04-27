#include "ringQ.h"


#define BUFFER_LEN	 800 

uint8_t *generateData(uint8_t *buff, uint16_t len);
void dataPrint(uint8_t *buff, uint16_t len);


uint8_t data_buff[300];


uint8_t ringQBuff[BUFFER_LEN];

struct ramq_t *ringqObj;

qObj_t *tailObj;





void setup() {
	Serial.begin(115200);
	ringqObj = ramqNew(ringQBuff, BUFFER_LEN);

	randomSeed(micros());

}



void loop() {
	memset(data_buff, '\0', 300);
	uint16_t len = random(240,300);
  generateData(data_buff,len);
  Serial.print("Reading Data Before Push: ");
  dataPrint(data_buff,len);
	ramqPush(ringqObj,data_buff,len);
	tailObj = ramqPop(ringqObj);
	memset(data_buff, '\0', 300);
	memcpy(data_buff, (tailObj ->ptr + sizeof(struct qObj_t)), tailObj->len);
  Serial.print("Reading Data Before Pop: ");
  dataPrint(data_buff,len);
}


uint8_t *generateData(uint8_t *buff, uint16_t len)
{
	uint8_t *tBuff = buff;
	for(int i=0; i<len; i++)
	{
		tBuff[i] = random(255);
	}
	return buff;
}


void dataPrint(uint8_t *buff, uint16_t len)
{
	uint8_t *tBuff = buff;
	for(int i=0; i<len; i++)
	{
		Serial.print(tBuff[i] , HEX);
		Serial.print(" ");
	}
	Serial.println("");
	return buff;
}