#include "print.h"

char putchar2(char c)
{
//    if(c == '\n') 
//	{
//        SBUF = '\r';		   
//        while(!TI);
//    }
//	S2BUF = c;
//	while(!TI2);                 
//	CLR_TI2();
//  return c;
    SBUF = c;
    while(!TI);
    TI=0;
		
    return c;
}

int print2(char* fmt, ...)
{
	char* pfmt = NULL;
	va_list args;
	int printed;
	
	va_start(args, fmt);	
  printed = vsprintf(pfmt,fmt,args);
	va_end(args); 
	 while(*pfmt)
	 {
		putchar2(*pfmt++);
	 }
	 free(pfmt);
	 return printed;
}
