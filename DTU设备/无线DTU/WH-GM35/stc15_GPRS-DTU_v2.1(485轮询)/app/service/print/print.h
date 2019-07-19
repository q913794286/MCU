#ifndef     __PRINT_H_
#define    __PRINT_H_

#include "config.h"
#include <stdio.h>
#include <stdarg.h>

int print2(char* fmt, ...);
void    print(char* fmt, ...);
void    printch(char ch);
void    printdec(int dec);
void    printflt(double flt);
void    printbin(int bin);
void    printhex(int hex);
void    printstr(char* str);

#define console_print(ch)    putchar2(ch)

#endif    /*#ifndef __PRINT_H_*/
