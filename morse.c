#include "CH554.H"                                                 
#include "Debug.H"
#include "PWM.H"
#include "morse.h"
#include "stdio.h"


#define TICK_TIME 40

sbit	LED=P1^4;

void dot() {
    LED = 0;
    PWM1OutEnable( );
	mDelaymS(TICK_TIME);
	DsiablePWM1Out( );
	LED = 1;
	mDelaymS(TICK_TIME);
}

void dash(){
    LED = 0;
    PWM1OutEnable( );
	mDelaymS(3*TICK_TIME);
	DsiablePWM1Out( );
	LED = 1;
	mDelaymS(TICK_TIME);
}

void nop(){
   mDelaymS(3*TICK_TIME);
}

void encode(char c){

   switch(c){
      case 'A':
	  case 'a':
	     dot();
		 dash();
	     break;
	 case 'B':
	 case 'b':
	     dash();
		 dot();
		 dot();
		 dot();
		 break;
	 case 'C':
	 case 'c':
	     dash();
		 dot();
		 dash();
		 dot();
		 break;
	 case 'D':
	 case 'd':
	     dash();
		 dot();
		 dot();
		 break;
     case 'E':
	 case 'e':
	     dot();
		 break;
     case 'F':
	 case 'f':
	     dot();
		 dot();
		 dash();
		 dot();
		 break;
	 case 'G':
	 case 'g':
	     dash();
		 dash();
		 dot();
		 break;
     case 'H':
	 case 'h':
	     dot();
		 dot();
		 dot();
		 dot();
		 break;
	 case 'I':
	 case 'i': 
	     dot();
		 dot();
		 break;
     case 'J':
	 case 'j':
	     dot();
		 dash();
		 dash();
		 dash();
		 break;
	 case 'K':
	 case 'k':
	     dash();
		 dot();
		 dash();
		 break;
	 case 'L':
	 case 'l':
	     dot();
		 dash();
		 dot();
		 dot();
		 break;
	 case 'M':
	 case 'm':
	     dash();
		 dash();
		 break;
     case 'N':
	 case 'n':
	     dash();
		 dot();
		 break;
     case 'O':
	 case 'o':
	     dash();
		 dash();
		 dash();
		 break;
	 case 'P':
	 case 'p':
	     dot();
		 dash();
		 dash();
		 dot();
		 break;
     case 'Q':
	 case 'q':
	     dash();
		 dash();
		 dot();
		 dash();
		 break;
	 case 'R':
	 case 'r':
	     dot();
		 dash();
		 dot();
	     break;
	 case 'S':
	 case 's':
	     dot();
		 dot();
		 dot();
		 break;
	 case 'T':
	 case 't':
	     dash();
		 break;																					 
	 case 'U':
	 case 'u':
	     dot();
		 dot();
		 dash();
		 break;
	 case 'V':
	 case 'v':
	     dot();
		 dot();
		 dot();
		 dash();
		 break;
	 case 'W':
	 case 'w':
	     dot();
		 dash();
		 dash();
		 break;
	 case 'X':
	 case 'x':
	     dash();
		 dot();
		 dot();
		 dash();
		 break;
	 case 'Y':
	 case 'y':
	     dash();
		 dot();
		 dash();
		 dash();
		 break;
	 case 'Z':
	 case 'z':
	     dash();
		 dash();
		 dot();
		 dot();
		 break;
     case '0':
	     dash();
		 dash();
		 dash();
		 dash();
		 dash();
		 break;
	 case '1':
	     dot();
		 dash();
		 dash();
		 dash();
		 dash();
		 break;
	 case '2':
	     dot();
		 dot();
		 dash();
		 dash();
		 dash();
		 break;
	case '3':
	     dot();
		 dot();
		 dot();
		 dash();
		 dash();
		 break;
	case '4':
	     dot();
		 dot();
		 dot();
		 dot();
		 dash();
		 break;
	case '5':
	     dot();
		 dot();
		 dot();
		 dot();
		 dot();
		 break;
	case '6':
	     dash();
		 dot();
		 dot();
		 dot();
		 dot();
		 break;
	case '7':
	     dash();
		 dash();
		 dot();
		 dot();
		 dot();
		 break;
	case '8':
	     dash();
		 dash();
		 dash();
		 dot();
		 dot();
		 break;
	case '9':
	     dash();
		 dash();
		 dash();
		 dash();
		 dot();
		 break;
	case '\.':
	     dot();
		 dash();
		 dot();
		 dash();
		 dot();
		 dash();
	     break;
    case '\:':
	     dash();
		 dash();
		 dash();
		 dot();
		 dot();
		 dot();
	     break;
    case '\,':
	     dash();
		 dash();
		 dot();
		 dot();
		 dash();
		 dash();
	     break;
	case '\?':
	     dot();
		 dot();
		 dash();
		 dash();
		 dot();
		 dot();
	     break;
	case '\=':
	     dash();
		 dot();
		 dot();
		 dot();
		 dash();
	     break;
	case '\'':
	     dot();
		 dash();
		 dash();
		 dash();
		 dash();
		 dot();
	     break;
	case '\/':
	     dash();
		 dot();
		 dot();
		 dash();
		 dot();
	     break;
	case '\!':
	     dash();
		 dot();
		 dash();
		 dot();
		 dash();
		 dash();
	     break;
	case '\-':
	     dash();
		 dot();
		 dot();
		 dot();
		 dot();
		 dash();
	     break;
	case '\_':
	     dot();
		 dot();
		 dash();
		 dash();
		 dot();
		 dash();
	     break;
	case '\"':
	     dot();
		 dash();
		 dot();
		 dot();
		 dash();
		 dot();
	     break;
	case '\(':
	     dash();
		 dot();
		 dash();
		 dash();
		 dot();
	     break;
	case '\)':
	     dash();
		 dot();
		 dash();
		 dash();
		 dot();
		 dash();
	     break;
	case '\$':
	     dot();
		 dot();
		 dot();
		 dash();
		 dot();
		 dot();
		 dash();
	     break;
	case '\&':
	     dot();
		 dash();
		 dot();
		 dot();
		 dot();
	     break;
	case '\@':
	     dot();
		 dash();
		 dash();
		 dot();
		 dash();
		 dot();
	     break;
	case '\+':
	     dot();
		 dash();
		 dot();
		 dash();
		 dot();
	     break;
	case 32:		   //Space
	     nop();
	     break;
	 default:
	     break; 
   }
}


void encodestring(char *str, UINT16 len){

	UINT16 i;
    for(i=0; i<len; i++){
	   encode(str[i]);
	   mDelaymS(3*TICK_TIME);

	}
   
}
