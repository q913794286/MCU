
#line 1 "app\service\app\function.c" /0
  
#line 1 "config.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef  unsigned int uint;
 typedef  unsigned char uchar;
 
 
 
  
#line 1 ".\STCLIB\STC15FXXXX.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "config.h" /0
 
 
#line 3 "config.h" /1
  
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
 
 
 
  
 
 
#line 19 ".\STCLIB\STC15FXXXX.H" /0
#line 19 ".\STCLIB\STC15FXXXX.H" /0
 
 
  
#line 1 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\INTRINS.H" /0






 
 
 
 
 
 extern void          _nop_     (void);
 extern bit           _testbit_ (bit);
 extern unsigned char _cror_    (unsigned char, unsigned char);
 extern unsigned int  _iror_    (unsigned int,  unsigned char);
 extern unsigned long _lror_    (unsigned long, unsigned char);
 extern unsigned char _crol_    (unsigned char, unsigned char);
 extern unsigned int  _irol_    (unsigned int,  unsigned char);
 extern unsigned long _lrol_    (unsigned long, unsigned char);
 extern unsigned char _chkfloat_(float);
 extern void          _push_    (unsigned char _sfr);
 extern void          _pop_     (unsigned char _sfr);
 
 
 
#line 21 ".\STCLIB\STC15FXXXX.H" /0
 
 
 
 sfr P0   = 0x80;
 sfr SP   = 0x81;
 sfr DPL  = 0x82;
 sfr DPH  = 0x83;
 sfr	S4CON = 0x84;
 sfr	S4BUF = 0x85;
 sfr PCON = 0x87;
 
 sfr TCON = 0x88;
 sfr TMOD = 0x89;
 sfr TL0  = 0x8A;
 sfr TL1  = 0x8B;
 sfr TH0  = 0x8C;
 sfr TH1  = 0x8D;
 sfr	AUXR = 0x8E;
 sfr WAKE_CLKO = 0x8F;
 sfr INT_CLKO = 0x8F;
 sfr	AUXR2    = 0x8F;
 
 sfr RL_TL0  = 0x8A;
 sfr RL_TL1  = 0x8B;
 sfr RL_TH0  = 0x8C;
 sfr RL_TH1  = 0x8D;
 
 
 sfr P1   = 0x90;
 sfr P1M1 = 0x91;	 
 sfr P1M0 = 0x92;	 
 sfr P0M1 = 0x93;	 
 sfr P0M0 = 0x94;	 
 sfr P2M1 = 0x95;	 
 sfr P2M0 = 0x96;	 
 sfr CLK_DIV = 0x97;
 sfr PCON2   = 0x97;
 
 sfr SCON  = 0x98;
 sfr SBUF  = 0x99;
 sfr S2CON = 0x9A;	 
 sfr S2BUF = 0x9B;	 
 sfr P1ASF = 0x9D;	 
 
 sfr P2    = 0xA0;
 sfr BUS_SPEED = 0xA1;
 sfr AUXR1 = 0xA2;
 sfr P_SW1 = 0xA2;
 
 sfr IE    = 0xA8;
 sfr SADDR = 0xA9;
 sfr WKTCL = 0xAA;	 
 sfr WKTCH = 0xAB;	 
 sfr	S3CON = 0xAC;
 sfr S3BUF = 0xAD;
 sfr IE2   = 0xAF;	 
 
 sfr P3    = 0xB0;
 sfr P3M1  = 0xB1;	 
 sfr P3M0  = 0xB2;	 
 sfr P4M1  = 0xB3;	 
 sfr P4M0  = 0xB4;	 
 sfr IP2   = 0xB5;	 
 sfr IPH2  = 0xB6;	 
 sfr IPH   = 0xB7;
 
 sfr IP        = 0xB8;
 sfr SADEN     = 0xB9;
 sfr	P_SW2     = 0xBA;
 sfr ADC_CONTR = 0xBC;	 
 sfr ADC_RES   = 0xBD;	 
 sfr ADC_RESL  = 0xBE;	 
 
 sfr P4        = 0xC0;
 sfr WDT_CONTR = 0xC1;
 sfr IAP_DATA  = 0xC2;
 sfr IAP_ADDRH = 0xC3;
 sfr IAP_ADDRL = 0xC4;
 sfr IAP_CMD   = 0xC5;
 sfr IAP_TRIG  = 0xC6;
 sfr IAP_CONTR = 0xC7;
 
 sfr ISP_DATA  = 0xC2;
 sfr ISP_ADDRH = 0xC3;
 sfr ISP_ADDRL = 0xC4;
 sfr ISP_CMD   = 0xC5;
 sfr ISP_TRIG  = 0xC6;
 sfr ISP_CONTR = 0xC7;
 
 sfr P5     = 0xC8;	 
 sfr P5M1   = 0xC9;	 
 sfr P5M0   = 0xCA;	 
 sfr P6M1   = 0xCB;	 
 sfr P6M0   = 0xCC;	 
 sfr SPSTAT = 0xCD;	 
 sfr SPCTL  = 0xCE;	 
 sfr SPDAT  = 0xCF;	 
 
 sfr PSW  = 0xD0;
 sfr	T4T3M = 0xD1;
 sfr	T4H  = 0xD2;
 sfr	T4L  = 0xD3;
 sfr	T3H  = 0xD4;
 sfr	T3L  = 0xD5;
 sfr	T2H  = 0xD6;
 sfr	T2L  = 0xD7;
 
 sfr	TH4  = 0xD2;
 sfr	TL4  = 0xD3;
 sfr	TH3  = 0xD4;
 sfr	TL3  = 0xD5;
 sfr	TH2  = 0xD6;
 sfr	TL2  = 0xD7;
 
 sfr	RL_T4H  = 0xD2;
 sfr	RL_T4L  = 0xD3;
 sfr	RL_T3H  = 0xD4;
 sfr	RL_T3L  = 0xD5;
 sfr	RL_T2H  = 0xD6;
 sfr	RL_T2L  = 0xD7;
 
 sfr CCON = 0xD8;	 
 sfr CMOD = 0xD9;	 
 sfr CCAPM0 = 0xDA;	 
 sfr CCAPM1 = 0xDB;	 
 sfr CCAPM2 = 0xDC;	 
 
 sfr ACC    = 0xE0;
 sfr	P7M1   = 0xE1;
 sfr	P7M0   = 0xE2;
 sfr	CMPCR1 = 0xE6;
 sfr	CMPCR2 = 0xE7;
 
 
 sfr	P6     = 0xE8;
 sfr CL     = 0xE9;	 
 sfr CCAP0L = 0xEA;	 
 sfr CCAP1L = 0xEB;	 
 sfr CCAP2L = 0xEC;	 
 
 sfr B      = 0xF0;
 sfr PCA_PWM0 = 0xF2;	 
 sfr PCA_PWM1 = 0xF3;	 
 sfr PCA_PWM2 = 0xF4;	 
 
 sfr	P7     = 0xF8;
 sfr CH     = 0xF9;
 sfr CCAP0H = 0xFA;		 
 sfr CCAP1H = 0xFB;		 
 sfr CCAP2H = 0xFC;		 
 
 
 
 
 sbit CY   = PSW^7;
 sbit AC   = PSW^6;
 sbit F0   = PSW^5;
 sbit RS1  = PSW^4;
 sbit RS0  = PSW^3;
 sbit OV   = PSW^2;
 sbit F1   = PSW^1;
 sbit P    = PSW^0;
 
 
 sbit TF1  = TCON^7;	 
 sbit TR1  = TCON^6;	 
 sbit TF0  = TCON^5;	 
 sbit TR0  = TCON^4;	 
 sbit IE1  = TCON^3;	 
 sbit IT1  = TCON^2;	 
 sbit IE0  = TCON^1;	 
 sbit IT0  = TCON^0;	 
 
 
 sbit  P00 = P0^0;
 sbit  P01 = P0^1;
 sbit  P02 = P0^2;
 sbit  P03 = P0^3;
 sbit  P04 = P0^4;
 sbit  P05 = P0^5;
 sbit  P06 = P0^6;
 sbit  P07 = P0^7;
 
 
 sbit  P10 = P1^0;
 sbit  P11 = P1^1;
 sbit  P12 = P1^2;
 sbit  P13 = P1^3;
 sbit  P14 = P1^4;
 sbit  P15 = P1^5;
 sbit  P16 = P1^6;
 sbit  P17 = P1^7;
 
 sbit  RXD2      = P1^0;
 sbit  TXD2      = P1^1;
 sbit  CCP1      = P1^0;
 sbit  CCP0      = P1^1;
 sbit  SPI_SS    = P1^2;
 sbit  SPI_MOSI  = P1^3;
 sbit  SPI_MISO  = P1^4;
 sbit  SPI_SCLK  = P1^5;
 
 
 sbit  P20 = P2^0;
 sbit  P21 = P2^1;
 sbit  P22 = P2^2;
 sbit  P23 = P2^3;
 sbit  P24 = P2^4;
 sbit  P25 = P2^5;
 sbit  P26 = P2^6;
 sbit  P27 = P2^7;
 
 
 sbit  P30 = P3^0;
 sbit  P31 = P3^1;
 sbit  P32 = P3^2;
 sbit  P33 = P3^3;
 sbit  P34 = P3^4;
 sbit  P35 = P3^5;
 sbit  P36 = P3^6;
 sbit  P37 = P3^7;
 
 sbit RXD  = P3^0;
 sbit TXD  = P3^1;
 sbit INT0 = P3^2;
 sbit INT1 = P3^3;
 sbit T0   = P3^4;
 sbit T1   = P3^5;
 sbit WR   = P3^6;
 sbit RD   = P3^7;
 sbit CCP2  = P3^7;
 
 sbit CLKOUT0   = P3^5;
 sbit CLKOUT1   = P3^4;
 
 
 sbit  P40 = P4^0;
 sbit  P41 = P4^1;
 sbit  P42 = P4^2;
 sbit  P43 = P4^3;
 sbit  P44 = P4^4;
 sbit  P45 = P4^5;
 sbit  P46 = P4^6;
 sbit  P47 = P4^7;
 
 
 sbit  P50 = P5^0;
 sbit  P51 = P5^1;
 sbit  P52 = P5^2;
 sbit  P53 = P5^3;
 sbit  P54 = P5^4;
 sbit  P55 = P5^5;
 sbit  P56 = P5^6;
 sbit  P57 = P5^7;
 
 
 sbit SM0  = SCON^7;	 
 sbit SM1  = SCON^6;	 
 sbit SM2  = SCON^5;	 
 sbit REN  = SCON^4;	 
 sbit TB8  = SCON^3;	 
 sbit RB8  = SCON^2;	 
 sbit TI   = SCON^1;	 
 sbit RI   = SCON^0;	 
 
 
 sbit EA   = IE^7;	 
 sbit ELVD = IE^6;	 
 sbit EADC = IE^5;	 
 sbit ES   = IE^4;	 
 sbit ET1  = IE^3;	 
 sbit EX1  = IE^2;	 
 sbit ET0  = IE^1;	 
 sbit EX0  = IE^0;	 
 
 
 









 
 
 sbit ACC0 = ACC^0;
 sbit ACC1 = ACC^1;
 sbit ACC2 = ACC^2;
 sbit ACC3 = ACC^3;
 sbit ACC4 = ACC^4;
 sbit ACC5 = ACC^5;
 sbit ACC6 = ACC^6;
 sbit ACC7 = ACC^7;
 
 sbit B0 = B^0;
 sbit B1 = B^1;
 sbit B2 = B^2;
 sbit B3 = B^3;
 sbit B4 = B^4;
 sbit B5 = B^5;
 sbit B6 = B^6;
 sbit B7 = B^7;
 
 
 
 
 
 
 
 
 
 
 
 
 sbit PPCA	= IP^7;	 
 sbit PLVD	= IP^6;	 
 sbit PADC	= IP^5;	 
 sbit PS   	= IP^4;	 
 sbit PT1	= IP^3;	 
 sbit PX1	= IP^2;	 
 sbit PT0	= IP^1;	 
 sbit PX0	= IP^0;	 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 542 ".\STCLIB\STC15FXXXX.H" /1
  
 
  
 
  
 
#line 548 ".\STCLIB\STC15FXXXX.H" /0
 
 
#line 550 ".\STCLIB\STC15FXXXX.H" /1
  
 
  
 
  
 
  
 
#line 558 ".\STCLIB\STC15FXXXX.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 






 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 sbit CCF0  = CCON^0;	 
 sbit CCF1  = CCON^1;	 
 sbit CCF2  = CCON^2;	 
 sbit CR    = CCON^6;	 
 sbit CF    = CCON^7;	 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 























 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef 	unsigned char	u8;
 typedef 	unsigned int	u16;
 typedef 	unsigned long	u32;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 









 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 19 "config.h" /0
 
 
 
  
#line 1 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDLIB.H" /0






 
 
 
 
 
 
 
 typedef unsigned int size_t;
 
 
 
 
 
 
 
 
 typedef char wchar_t;
 
 
 
 
 
 
 #pragma SAVE
 #pragma REGPARMS
 
 extern int    abs  (int   val);
 extern long  labs  (long  val);
 
 extern float atof (char *s1);
 extern long  atol (char *s1);
 extern int   atoi (char *s1);
 extern int   rand ();
 extern void  srand (int);
 
 extern float         strtod  (char *, char **);
 extern long          strtol  (char *, char **, unsigned char);
 extern unsigned long strtoul (char *, char **, unsigned char);
 
 
 
 extern void init_mempool          (void xdata *p, unsigned int size);
 extern void xdata *malloc  (unsigned int size);
 extern void free                  (void xdata *p);
 extern void xdata *realloc (void xdata *p, unsigned int size);
 extern void xdata *calloc  (unsigned int size, unsigned int len);
 
 #pragma RESTORE
 
 
#line 22 "config.h" /0
 
  
#line 1 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDIO.H" /0






 
 
 
 
 
 
 
 
 
 
#line 17 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDIO.H" /1
  
 
#line 19 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDIO.H" /0
 
 
#line 21 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDIO.H" /1
  
 
 
#line 24 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDIO.H" /0
 
 #pragma SAVE
 #pragma REGPARMS
 extern char _getkey (void);
 extern char getchar (void);
 extern char ungetchar (char);
 extern char putchar (char);
 extern int printf   (const char *, ...);
 extern int sprintf  (char *, const char *, ...);
 extern int vprintf  (const char *, char *);
 extern int vsprintf (char *, const char *, char *);
 extern char *gets (char *, int n);
 extern int scanf (const char *, ...);
 extern int sscanf (char *, const char *, ...);
 extern int puts (const char *);
 
 #pragma RESTORE
 
 
 
#line 23 "config.h" /0
 
  
#line 1 "stdint.h" /0
 
 
 
 typedef unsigned char uint8_t;   
 typedef signed char int8_t;		   
 typedef unsigned short uint16_t;   
 typedef signed short int16_t;
 typedef unsigned long uint32_t;	   
 typedef signed long int32_t;
 
 
#line 24 "config.h" /0
 
  
#line 1 ".\APP\MYSTRING.H" /0
 
 
 
 
 char *strpbrk(const char *cs, const char *ct);
 char *strsep(char **s, const char *ct);
 char * strtrim(char *s);
 void trim(char *strIn, char *strOut);
 char * strtrim_fast(char *s) ;
 
#line 25 "config.h" /0
 
  
#line 1 ".\APP\SERVICE\PRINT\PRINT.H" /0
 
 
 
  
#line 1 "config.h" /0
 
 
#line 3 "config.h" /1
  
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
 
 
 
  
 
 
#line 4 ".\APP\SERVICE\PRINT\PRINT.H" /0
#line 4 ".\APP\SERVICE\PRINT\PRINT.H" /0
 
  
#line 1 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDIO.H" /0






 
 
 
#line 10 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDIO.H" /1
  
 
 
  
 
 
 
  
 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 43 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDIO.H" /0
 
#line 5 ".\APP\SERVICE\PRINT\PRINT.H" /0
 
  
#line 1 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDARG.H" /0





 
 
 
 
 
#line 11 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDARG.H" /1
  
 
#line 13 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDARG.H" /0
 
 
 typedef char *va_list;
 
 
 
 
 
 
 
 
#line 6 ".\APP\SERVICE\PRINT\PRINT.H" /0
 
 
 int print2(char* fmt, ...);
 void    print(char* fmt, ...);
 void    printch(char ch);
 void    printdec(int dec);
 void    printflt(double flt);
 void    printbin(int bin);
 void    printhex(int hex);
 void    printstr(char* str);
 
 
 
 
#line 26 "config.h" /0
 
 
 extern uint8_t UsartX_send ;
 
 
 
 
#line 1 "app\service\app\function.c" /0
 
  
#line 1 ".\STCLIB\USART1.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "config.h" /0
 
 
#line 3 "config.h" /1
  
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
 
 
 
  
 
 
#line 18 ".\STCLIB\USART1.H" /0
#line 18 ".\STCLIB\USART1.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef struct
 { 
 u8	id;				 
 
 u8	TX_read;		 
 u8	TX_write;		 
 u8	B_TX_busy;		 
 
 u8 	RX_Cnt;			 
 u8	RX_TimeOut;		 
 u8	B_RX_OK;		 
 } COMx_Define; 
 
 typedef struct
 { 
 u8	UART_Mode;			 
 u8	UART_BRT_Use;		 
 u32	UART_BaudRate;		 
 u8	Morecommunicate;	 
 u8	UART_RxEnable;		 
 u8	BaudRateDouble;		 
 u8	UART_Interrupt;		 
 u8	UART_Polity;		 
 u8	UART_P_SW;			 
 u8	UART_RXD_TXD_Short;	 
 
 } COMx_InitDefine; 
 
 extern volatile	COMx_Define	COM1,COM2;
 extern	u8 xdata  TX1_Buffer[64];	 
 extern	u8 xdata  RX1_Buffer[128];	 
 extern	u8 xdata  TX2_Buffer[64];	 
 extern	u8 xdata  RX2_Buffer[128];	 
 extern volatile uint8_t uart1_cmd;
 extern volatile uint16_t uart1_cnt;
 extern volatile uint8_t config_mode;
 
 u8	USART_Configuration(u8 UARTx, COMx_InitDefine *COMx);
 void TX1_write2buff(u8 dat);	 
 void TX2_write2buff(u8 dat);	 
 void PrintString1(u8 *puts);
 void PrintString2(u8 *puts);
 void Printf1(u8 *puts, u8 len);
 
 
 void Printf1(u8 *puts, u8 len);
 void Printf2(u8 *puts, u8 len);
 
 
#line 2 "app\service\app\function.c" /0
 
  
#line 1 ".\STCLIB\DELAY.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void  delay_ms(unsigned int ms);
 void Delay1000ms();		 
 
#line 3 "app\service\app\function.c" /0
 
  
#line 1 ".\STCLIB\GPIO.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "config.h" /0
 
 
#line 3 "config.h" /1
  
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
 
 
 
  
 
 
#line 18 ".\STCLIB\GPIO.H" /0
#line 18 ".\STCLIB\GPIO.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef struct
 {
 u8	Mode;		 
 u8	Pin;		 
 } GPIO_InitTypeDef;
 
 u8	GPIO_Inilize(u8 GPIO, GPIO_InitTypeDef *GPIOx);
 
 
#line 4 "app\service\app\function.c" /0
 
  
#line 1 ".\STCLIB\EEPROM.H" /0
 
 
 
 
  
#line 1 "config.h" /0
 
 
#line 3 "config.h" /1
  
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
 
 
 
  
 
 
#line 5 ".\STCLIB\EEPROM.H" /0
#line 5 ".\STCLIB\EEPROM.H" /0
 
  
#line 1 "stdint.h" /0
 
#line 2 "stdint.h" /1
  
 
 
 
 
 
 
 
 
 
#line 6 ".\STCLIB\EEPROM.H" /0
#line 6 ".\STCLIB\EEPROM.H" /0
 
 
 
 
 
 

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void	DisableEEPROM(void);
 void 	EEPROM_read_n(uint16_t EE_address,uint8_t *DataAddress,uint16_t number);
 void 	EEPROM_write_n(uint16_t EE_address,uint8_t *DataAddress,uint16_t number);
 void	EEPROM_SectorErase(uint16_t EE_address);
 
 
 
#line 5 "app\service\app\function.c" /0
 
 
  
#line 1 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDIO.H" /0






 
 
 
#line 10 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDIO.H" /1
  
 
 
  
 
 
 
  
 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 43 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDIO.H" /0
 
#line 7 "app\service\app\function.c" /0
 
  
#line 1 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDLIB.H" /0






 
 
 
#line 10 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDLIB.H" /1
  
 
 
  
 
 
 
 
  
 
 
 
  
 
 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
 
#line 8 "app\service\app\function.c" /0
#line 8 "app\service\app\function.c" /0
 
  
#line 1 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STRING.H" /0






 
 
 
 
 
 
#line 13 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STRING.H" /1
  
 
 
#line 16 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STRING.H" /0
 
 
#line 18 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STRING.H" /1
  
 
#line 20 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STRING.H" /0
 
 #pragma SAVE
 #pragma REGPARMS
 extern char *strcat (char *s1, char *s2);
 extern char *strncat (char *s1, char *s2, int n);
 
 extern char strcmp (char *s1, char *s2);
 extern char strncmp (char *s1, char *s2, int n);
 
 extern char *strcpy (char *s1, char *s2);
 extern char *strncpy (char *s1, char *s2, int n);
 
 extern int strlen (char *);
 
 extern char *strchr (const char *s, char c);
 extern int strpos (const char *s, char c);
 extern char *strrchr (const char *s, char c);
 extern int strrpos (const char *s, char c);
 
 extern int strspn (char *s, char *set);
 extern int strcspn (char *s, char *set);
 extern char *strpbrk (char *s, char *set);
 extern char *strrpbrk (char *s, char *set);
 extern char *strstr  (char *s, char *sub);
 extern char *strtok  (char *str, const char *set);
 
 extern char memcmp (void *s1, void *s2, int n);
 extern void *memcpy (void *s1, void *s2, int n);
 extern void *memchr (void *s, char val, int n);
 extern void *memccpy (void *s1, void *s2, char val, int n);
 extern void *memmove (void *s1, void *s2, int n);
 extern void *memset  (void *s, char val, int n);
 #pragma RESTORE
 
 
#line 9 "app\service\app\function.c" /0
 
  
#line 1 ".\APP\SYS_CLOCK.H" /0
 
 
 
 
 
 
 
  
#line 1 "config.h" /0
 
 
#line 3 "config.h" /1
  
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
 
 
 
  
 
 
#line 8 ".\APP\SYS_CLOCK.H" /0
#line 8 ".\APP\SYS_CLOCK.H" /0
 
  
#line 1 "stdint.h" /0
 
#line 2 "stdint.h" /1
  
 
 
 
 
 
 
 
 
 
#line 9 ".\APP\SYS_CLOCK.H" /0
#line 9 ".\APP\SYS_CLOCK.H" /0
 
 
 typedef struct{
 u16 ms;
 u16 start;
 
 }timer_out;
 
 extern timer_out timerout1, timerout2;
 
 extern data volatile uint16_t sys_ticks;
 extern void sys_clock_init(void);
 extern uint16_t get_sys_ticks(void);
 
 
#line 10 "app\service\app\function.c" /0
 
  
#line 1 "APP\SERVICE\APP\FUNCTION.H" /0
 
 
 
 
 void function(void);
 
 void uart1_set_TimeOut(uint16_t ms);
 void uart2_set_TimeOut(uint16_t ms);
 void uart1_check_TimeOut(void);
 void uart2_check_TimeOut(void);
 
 void usart1_and_usart2();
 void usart1_cmd_write();
 void gprs_conf();
 
 void GPRS_check(uint16_t check_times);
 void Unpack(uint8_t byte);
 
 struct frame{
 uint8_t addr;
 uint8_t func;
 uint8_t data_size;
 uint8_t data12[12];
 uint8_t crcL;
 uint8_t crcH;	
 };
 
#line 11 "app\service\app\function.c" /0
 
  
#line 1 ".\APP\SERVICE\AES128\AES.H" /0
 
 
 
  
#line 1 "stdint.h" /0
 
#line 2 "stdint.h" /1
  
 
 
 
 
 
 
 
 
 
#line 4 ".\APP\SERVICE\AES128\AES.H" /0
#line 4 ".\APP\SERVICE\AES128\AES.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void AES128_ECB_encrypt(const uint8_t* input, const uint8_t* key, uint8_t *output);
 void AES128_ECB_decrypt(const uint8_t* input, const uint8_t* key, uint8_t *output);
 
 
 
 
 
 
 void AES128_CBC_encrypt_buffer(uint8_t* output, uint8_t* input, uint32_t length, const uint8_t* key, const uint8_t* iv);
 void AES128_CBC_decrypt_buffer(uint8_t* output, uint8_t* input, uint32_t length, const uint8_t* key, const uint8_t* iv);
 
 
 
 
 
 
#line 12 "app\service\app\function.c" /0
 
  
#line 1 ".\APP\SERVICE\AES128\AES128APP.H" /0
 
 
 
 typedef struct{
 uint8_t id[8];
 uint8_t key[16];
 uint8_t iv[16];
 uint8_t state;
 }AES128;
 
 extern AES128 aes128;																			
 
 int app_encrypt_cbc(uint8_t *key, uint8_t *iv, uint8_t *in, uint8_t len, uint8_t *out);  
 int app_decrypt_cbc(uint8_t *key, uint8_t *iv, uint8_t *in, uint8_t *out);  
 
 
 
#line 13 "app\service\app\function.c" /0
 
  
#line 1 ".\APP\SERVICE\CRC16\CRC16.H" /0
 
 
 






 
 uint16_t crc16(uint8_t *puchMsg, uint16_t usDataLen);
 uint16_t crc16_2(uint8_t *puchMsg1, uint16_t usDataLen1,  uint8_t *puchMsg2,  uint16_t usDataLen2);
 
 
#line 14 "app\service\app\function.c" /0
 
  
#line 1 ".\APP\SERVICE\GPRS\GPRS.H" /0
 
 
 
 sbit Power = P0^0;
 
 
 
 typedef struct{
 uint8_t *baud;
 uint8_t *server;
 }S_config;
 
 extern S_config s_config;
 extern u8 gprs_status;
 
 void init_GPRS( S_config *s);
 void check_gprs();
 u8 gprs_cmd(u8 *cmd, u8 *input, u8 *ck_str, u8 outtime_s);
 
 
 
 
#line 15 "app\service\app\function.c" /0
 
 
 
 timer_out timerout1, timerout2;		  
 
 AES128 aes128;
 
 
 
 
 
 
 void usart1_cmd_write(void);
 void usart1_and_usart2(void);
 extern void USRT1_config(u32 buad);
 void RS485_coil();
 
 
 
 void init_config()
 {
 uint8_t s_buf[50];
 uint8_t *ptr,*ptr2;
 S_config config;
 uint8_t sta=0;
 unsigned long baud;
 
 uart1_cmd = 0; 			 
 
 
 memcpy(s_buf,0,50);
 EEPROM_read_n(0x200,&s_buf,50);
 delay_ms(6);
 ptr2 = strtrim(s_buf);	 
 while((ptr = strsep(&ptr2, ";")) != ((void *) 0L)){	 
 if(sta==0)
 {
 config.baud = ptr; 
 }
 if(sta==1) 
 {
 config.server = ptr;
 }
 sta++;
 }
 baud =strtoul(config.baud,((void *) 0L),10);	   
 printf("parameter: \r\n");
 printf("baud=%ld\r\n",baud);
 printf("server=%s\r\n",config.server);
 if(baud<1200)
 {USRT1_config(9600);	   
 printf("default baud 9600\r\n");}
 else
 USRT1_config(baud);	   
 
 init_GPRS(&config);  
 
 }
 
 
 void function(void)
 {
 
 init_config();
 while(1)
 {






 
 
 
 uart2_check_TimeOut(); 
 
 
 
 
 RS485_coil();
 }
 }
 
 uint8_t code send_cmd[]={0x01,0x03,0x00,0x00,0x06,0xc5,0xc8};  
 
 void RS485_coil()
 {
 static uint32_t timer0_1=0, timer0_2=0;
 timer0_1 = get_sys_ticks();
 if((timer0_1 - timer0_2)>500)   
 { 
 
 Printf1(send_cmd,sizeof(send_cmd));
 
 timer0_2 = get_sys_ticks(); 
 }
 }
 
 const uint8_t code T[]  = "\"T\":";       
 const uint8_t code PH[] = "\"PH\":";      
 const uint8_t code DO[] = "\"DO\":";      
 const uint8_t code NTU[]= "\"NTU\":";     
 const uint8_t code GC[] = "\"GC\":";      
 
 void Unpack(uint8_t byte)
 {
 static uint16_t received_bytes = 0;
 uint8_t read_index = 0;
 struct frame *packet;
 uint16_t crc;
 
 if(received_bytes >= sizeof(RX1_Buffer)) received_bytes=0;
 RX1_Buffer[received_bytes] = byte;
 received_bytes++;
 
 while(received_bytes>=17)
 {  
 
 packet = (struct frame*) &RX1_Buffer[read_index];
 
 if(packet->addr == 0x01 && packet->func == 0x03)
 {
 if(packet->data_size + 5 > received_bytes) return;
 crc = crc16(&RX1_Buffer[read_index],packet->data_size+3);
 
 
 
 
 if((packet->crcL == (crc>>8&0xff))&&(packet->crcH == (crc&0xff)))
 {
 
 UsartX_send = 2;
 printf("%s\r\n","{");
 printf("%s%.2f%s",T,(float)(packet->data12[0]<<8|packet->data12[1])/100,",\r\r\n");
 printf("%s%.3f,\r\r\n",PH,(float)(packet->data12[2]<<8|packet->data12[3])/1000);
 printf("%s%.3f,\r\r\n",DO,(float)(packet->data12[4]<<8|packet->data12[5])/1000);
 printf("%s%.2f,\r\r\n",NTU,(float)(packet->data12[6]<<8|packet->data12[7])/100); 
 printf("%s%d\n",GC,(int)(packet->data12[8]<<8|packet->data12[9]));
 printf("%s\r\r\n","}");
 UsartX_send = 1;
 received_bytes -= packet->data_size+5;
 read_index += packet->data_size+5;
 continue;
 }			 
 }
 received_bytes--;
 read_index++;
 
 }
 if(read_index != 0)
 memmove(RX1_Buffer, &RX1_Buffer [read_index], received_bytes);
 }
 
 
 
 



 
 void uart1_set_TimeOut(uint16_t ms)
 {
 
 timerout1.start = get_sys_ticks();
 timerout1.ms = ms;
 }
 
 void uart2_set_TimeOut(uint16_t ms)
 {
 
 timerout2.start = get_sys_ticks();
 timerout2.ms = ms;
 }
 


 
 u8 code sbuf1[]={0xc3,0x01};
 
 
 
 
 
 void uart1_check_TimeOut(void)
 {
 uint16_t count1;
 
#line 203 "app\service\app\function.c" /1
 
 
 
 
#line 207 "app\service\app\function.c" /0
 if(COM1.RX_TimeOut > 0)		 
 {
 count1 = get_sys_ticks();
 if((count1 - timerout1.start)>timerout1.ms)
 {
 
#line 213 "app\service\app\function.c" /1
 
 



 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 240 "app\service\app\function.c" /0
 
 
#line 242 "app\service\app\function.c" /1
 
 
#line 244 "app\service\app\function.c" /0
 COM1.RX_TimeOut = 0;   
 COM1.RX_Cnt = 0;       
 }
 }
 }
 
 void uart2_check_TimeOut(void)
 {
 uint16_t count2;
 
 if(COM2.RX_TimeOut > 0)		 
 {
 count2 = get_sys_ticks();
 if((count2 - timerout2.start)>timerout2.ms)
 {            



 
 
 
 
 
 
 Printf1(RX2_Buffer,COM2.RX_Cnt);
 
 COM2.RX_TimeOut = 0;   
 COM2.RX_Cnt = 0;       
 }
 }
 }
 
 
 void usart1_cmd_write()
 {
 
 
 
 
 
 
 
 
 EEPROM_SectorErase(0x00);
 delay_ms(6);		 
 EEPROM_write_n(0x00,RX1_Buffer,COM1.RX_Cnt);	   
 delay_ms(6);
 Printf1("ok",2);
 memset(RX1_Buffer,0,128);
 COM1.RX_Cnt = 0;
 
 }
 
 
 void gprs_conf()
 {	
 EEPROM_SectorErase(0x200);
 delay_ms(10);		 
 EEPROM_write_n(0x200,RX1_Buffer,50);	   
 delay_ms(6);
 Printf1("ok\n",4);
 
 memset(RX1_Buffer,0,128);
 COM1.RX_Cnt = 0;
 }
 
 
 
 sbit LED1 = P3^5;
 sbit LED2 = P3^4;
 
 uint8_t second,minute;
 void GPRS_check(uint16_t times)
 {
 static uint16_t start_T;
 
 start_T = get_sys_ticks();
 if((get_sys_ticks() - start_T)>100)
 {	
 if(gprs_status==1) LED1=1;
 else 
 LED1=~LED1;	
 LED2=~LED2;
 if(++second>=60)
 {
 second=0;
 if(++minute>=times)
 { 				
 if(gprs_cmd("AT", RX2_Buffer, "OK", 500)==0)	 
 {
 Power = 1;   
 delay_ms(100);		   
 Power = 0;   
 delay_ms(200);
 ISP_CONTR = 0x60;   
 }
 minute=0;
 }
 }		  
 }	
 }
 
 void usart1_and_usart2()
 {
 static uint16_t count1, count2;
 
 if(COM1.RX_TimeOut > 0)		 
 {
 count1 = get_sys_ticks();
 if((count1 - timerout1.start)>timerout1.ms)
 {    
 UsartX_send = 2;
 printf(RX1_Buffer);
 UsartX_send = 1;
 
 
 memset(RX1_Buffer,0,128);
 COM1.RX_TimeOut = 0;   
 COM1.RX_Cnt = 0;       
 }
 }
 
 if(COM2.RX_TimeOut > 0)		 
 {
 count2 = get_sys_ticks();
 if((count2 - timerout2.start)>timerout2.ms)
 {            
 
 
 printf(RX2_Buffer);
 printf("\r");
 memset(RX2_Buffer,0,128);
 COM2.RX_TimeOut = 0;   
 COM2.RX_Cnt = 0;       
 }
 }
 }
