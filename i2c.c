
#include <intrins.h>
#include "CH554.H"
#include "Debug.H"
#include "i2c.h"

#define THERM_SDA 7
#define THERM_SCL 6
sbit    SDA=P1^7;
sbit 	SCL=P1^6;


void i2cStart(void)
{
    SDA=1;  
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();	 
       
    SCL=1;   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    SDA=0;   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();
	SCL=0;
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();	    
}

void i2cWrite(UINT8 d)
{
    UINT8 BitCounter=8; /*位数控制*/  
       
    UINT8 temp; /*中间变量控制*/  
       
    do     
    {          
        temp=d;   
           
        SCL=0;   
           
        _nop_ ();   
           
        _nop_ ();   
           
        _nop_ ();   
           
        _nop_ ();   
           
        if((temp&0x80)==0x80)/* 如果最高位是1*/              
            SDA=1;         
        else               
            SDA=0;   
           
        SCL=1;   
           
        temp=d<<1; /*RLC*/  
           
        d=temp;   
           
        BitCounter--;          
    }while(BitCounter);   
       
    SCL=0;   
}

void i2cAck(void)
{
    SCL=0; 
    SDA=0;   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    SCL=1;   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    SCL=0;  
}
void i2cStop(void)
{
    SCL=0;
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   	   
       
    SDA=1;   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    SCL=1;   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ (); 
	SDA=1;
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ (); 
}
void i2cRestart(void)
{
SCL=0;
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ (); 
SDA=1;
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ (); 
SCL=1;
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ (); 
SDA=0;
}

void i2cNoAck(void)
{
    SDA=1;   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    SCL=1;   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    _nop_ ();   
       
    SCL=0;  
}

void i2cMasterAck(void)
{
SCL=0;
SDA=0;
SCL=1;
SCL=0;
SDA=1;
}

UINT8 i2cRead(void )
{
    UINT8 temp=0;   
       
    UINT8 temp1=0;   
       
    UINT8 BitCounter=8;   
       
    SDA=1;   
       
    do{        
        SCL=0;   
           
        _nop_ ();   
           
        _nop_ ();   
           
        _nop_ ();   
           
        _nop_ ();   
           
        SCL=1;   
           
        _nop_ ();   
           
        _nop_ ();   
           
        _nop_ ();   
           
        _nop_ ();   
           
        if(SDA) /*如果Sda=1;*/               
            temp=temp|0x01; /*temp的最低位置1*/         
        else               
            temp=temp&0xfe; /*否则temp的最低位清0*/  
           
        if(BitCounter-1)               
        {    
            temp1=temp<<1;             
            temp=temp1;            
        }   
           
        BitCounter--;   
           
    }while(BitCounter);   
       
    return(temp);   
}

void i2cDevWrite(UINT8 slaveAddr,UINT8 buffAddr,UINT8 dat)
{
i2cStart();
i2cWrite(slaveAddr);
i2cAck();
i2cWrite(buffAddr);
i2cAck();
i2cWrite(dat);
i2cAck();
i2cStop();
mDelaymS(10);
}

UINT8 i2cDevRead(UINT8 slaveAddr,UINT8 buffAddr)
{
	UINT8 buff;
	i2cStart();
	i2cWrite(slaveAddr);
	i2cAck();
	i2cWrite(buffAddr);
	i2cAck();
	i2cRestart();
	i2cWrite(slaveAddr|1);
	i2cAck();
	buff=i2cRead();
	i2cNoAck();
	i2cStop();
	return buff;
	
}

void i2cDevPageWrite(UINT8 slaveAddr,UINT8 buffStartAddr,UINT8 *str,UINT8 size)
{
	UINT8 i;
	i2cStart();
	i2cWrite(slaveAddr);
	i2cAck();
	i2cWrite(buffStartAddr);
	i2cAck();
	for(i=0;i<size;i++)
	{
		i2cWrite(*str++);
		i2cAck();
	}
	i2cStop();
	mDelaymS(10);
}

void i2cDevPageRead(UINT8 slaveAddr,UINT8 buffStartAddr,UINT8 *str,UINT8 size)
{
	UINT8 i;
	i2cStart();
	i2cWrite(slaveAddr);
	i2cAck();
	i2cWrite(buffStartAddr);
	i2cAck();
	i2cRestart();
	i2cWrite(slaveAddr|1);
	i2cAck();
	for(i=0;i<size-1;i++)
	{
		str[i]=i2cRead();
		i2cMasterAck();
	}
	str[i++] =i2cRead();
	str[i]='\0';
	i2cNoAck();
	i2cStop();
}