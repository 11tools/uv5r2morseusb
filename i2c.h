#ifndef __I2C_H_
#define __I2C_H_
#include "CH554.H"
#include "Debug.H"
void i2cStart(void);
void i2cRestart(void);
void i2cWrite(UINT8);
void i2cAck(void);
void i2cNoAck(void);
void i2cStop(void);
void i2cMasterAck(void);
UINT8 i2cRead(void);
void i2cDevWrite(UINT8,UINT8,UINT8);
UINT8 i2cDevRead(UINT8,UINT8);
void i2cDevPageWrite(UINT8,UINT8,UINT8 *,UINT8);
void i2cDevPageRead(UINT8,UINT8,UINT8 *,UINT8);
#endif