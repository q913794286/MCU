
#line 1 "stclib\USART1.C" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "STCLIB\USART1.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "config.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef  unsigned int uint;
 typedef  unsigned char uchar;
 
 
 
  
#line 1 "STCLIB\STC15FXXXX.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "config.h" /0
 
 
#line 3 "config.h" /1
  
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
  
 
 
  
  
  
  
 
 
 
  
  
  
  
 
 
#line 19 "STCLIB\STC15FXXXX.H" /0
#line 19 "STCLIB\STC15FXXXX.H" /0
 
 
  
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
 
 
 
#line 21 "STCLIB\STC15FXXXX.H" /0
 
 
 
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 542 "STCLIB\STC15FXXXX.H" /1
  
 
  
 
  
 
#line 548 "STCLIB\STC15FXXXX.H" /0
 
 
#line 550 "STCLIB\STC15FXXXX.H" /1
  
 
  
 
  
 
  
 
#line 558 "STCLIB\STC15FXXXX.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 






 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
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
 
 
 sbit LED1 = P0^0 	 ;
 sbit LED2 = P0^1;
 
 
 
 
 
 
#line 18 "STCLIB\USART1.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
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
 extern	u8 xdata  TX1_Buffer[1];	 
 extern	u8 xdata  RX1_Buffer[1];	 
 extern	u8 xdata  TX2_Buffer[1];	 
 extern	u8 xdata  RX2_Buffer[1];	 
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
 
 
#line 15 "stclib\USART1.C" /0
 
  
#line 1 ".\APP\SERVICE\APP\FUNCTION.H" /0
 
 
 
 
 void function(void);
 
 void uart1_set_TimeOut(uint16_t ms);
 void uart2_set_TimeOut(uint16_t ms);
 void uart1_check_TimeOut(void);
 void uart2_check_TimeOut(void);
 
 void usart1_and_usart2();
 void usart1_cmd_write();
 void gprs_conf();
 
 void GPRS_check(uint16_t check_times);
 
#line 16 "stclib\USART1.C" /0
 
  
#line 1 ".\APP\SERVICE\APP\PACKET_DUST.H" /0
 
 
  
#line 1 "config.h" /0
 
 
#line 3 "config.h" /1
  
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
  
 
 
  
  
  
  
 
 
 
  
  
  
  
 
 
#line 3 ".\APP\SERVICE\APP\PACKET_DUST.H" /0
#line 3 ".\APP\SERVICE\APP\PACKET_DUST.H" /0
 
 
 struct frame{
 uint8_t head1;
 uint8_t head2;
 uint16_t len;
 uint16_t data1;
 uint16_t data2;
 uint16_t data3;
 uint16_t data4;
 uint16_t data5;
 uint16_t data6;
 uint16_t data7;
 uint16_t data8;
 uint16_t data9;
 uint16_t data10;
 uint16_t data11;
 uint16_t data12;
 };
 
 extern uint16_t data_temp;
 extern uint16_t data_airhum;
 extern uint16_t data_pm251;
 extern uint16_t data_pm252;
 extern uint16_t data_pm101;
 extern uint16_t data_pm102;
 
 uint16_t get_dustvo(uint16_t *buf);
 void dust_uart_isr(uint8_t byte);
 void cfg_uart_write(uint8_t *src, uint16_t length);
 
 
#line 17 "stclib\USART1.C" /0
 
  
#line 1 ".\APP\SERVICE\APP\PACKET_ROUTE.H" /0
 
 
  
#line 1 "config.h" /0
 
 
#line 3 "config.h" /1
  
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
  
 
 
  
  
  
  
 
 
 
  
  
  
  
 
 
#line 3 ".\APP\SERVICE\APP\PACKET_ROUTE.H" /0
#line 3 ".\APP\SERVICE\APP\PACKET_ROUTE.H" /0
 
 
 
 
 
 
 
 
 
 typedef struct {
 
 uint8_t flag1;
 uint8_t addr;
 uint8_t flag2;
 uint8_t cmd;
 uint8_t data_size;
 uint8_t dat[1];
 
 } term_packet_head_t;
 
 void router_uart_isr(uint8_t byte);
 void term_process();
 void router_uart_write(uint8_t *src, uint16_t length);
 
 
#line 18 "stclib\USART1.C" /0
 
 
 volatile COMx_Define	COM1,COM2;
 u8 xdata TX1_Buffer[1];	 
 u8 xdata RX1_Buffer[1];	 
 
 u8 xdata TX2_Buffer[1];	 
 u8 xdata RX2_Buffer[1];	 
 
 
 u8 rec,count;
 u8 Rec_over;
 volatile uint8_t uart1_cmd;
 
 u8 USART_Configuration(u8 UARTx, COMx_InitDefine *COMx)
 {
 u8	i;
 u32	j;
 
 if(UARTx == 1)
 {
 COM1.id = 1;
 COM1.TX_read    = 0;
 COM1.TX_write   = 0;
 COM1.B_TX_busy  = 0;
 COM1.RX_Cnt     = 0;
 COM1.RX_TimeOut = 0;
 COM1.B_RX_OK    = 0;
 uart1_cmd		= 0;
 for(i=0; i<1; i++)	TX1_Buffer[i] = 0;
 for(i=0; i<1; i++)	RX1_Buffer[i] = 0;
 
 if(COMx->UART_Mode > (3<<6))	return 2;	 
 if(COMx->UART_Polity == 1)		PS = 1;	 
 else									PS = 0;	 
 SCON = (SCON & 0x3f) | COMx->UART_Mode;
 if((COMx->UART_Mode == (3<<6)) ||(COMx->UART_Mode == (1<<6)))	 
 {
 j = (11059200L / 4) / COMx->UART_BaudRate;	 
 if(j >= 65536UL)	return 2;	 
 j = 65536UL - j;
 if(COMx->UART_BRT_Use == 1)
 {
 TR1 = 0;
 AUXR &= ~0x01;		 
 TMOD &= ~(1<<6);	 
 TMOD &= ~0x30;		 
 AUXR |=  (1<<6);	 
 TH1 = (u8)(j>>8);
 TL1 = (u8)j;
 ET1 = 0;	 
 TMOD &= ~0x40;	 
 INT_CLKO &= ~0x02;	 
 TR1  = 1;
 }
 else if(COMx->UART_BRT_Use == 2)
 {
 AUXR &= ~(1<<4);	 
 AUXR |= 0x01;		 
 AUXR &= ~(1<<3);	 
 AUXR |=  (1<<2);	 
 TH2 = (u8)(j>>8);
 TL2 = (u8)j;
 IE2  &= ~(1<<2);	 
 AUXR &= ~(1<<3);	 
 AUXR |=  (1<<4);	 
 }
 else return 2;	 
 }
 else if(COMx->UART_Mode == 0)
 {
 if(COMx->BaudRateDouble == 1)	AUXR |=  (1<<5);	 
 else								AUXR &= ~(1<<5);	 
 }
 else if(COMx->UART_Mode == (2<<6))	 
 {
 if(COMx->BaudRateDouble == 1)	PCON |=  (1<<7);	 
 else								PCON &= ~(1<<7);	 
 }
 if(COMx->UART_Interrupt == 1)	ES = 1;	 
 else								ES = 0;	 
 if(COMx->UART_RxEnable == 1)	REN = 1;	 
 else								REN = 0;	 
 P_SW1 = (P_SW1 & 0x3f) | (COMx->UART_P_SW & 0xc0);	 
 if(COMx->UART_RXD_TXD_Short == 1)	PCON2 |=  (1<<4);	 
 else									PCON2 &= ~(1<<4);
 return	0;
 }
 
 if(UARTx == 2)
 {
 COM2.id = 2;
 COM2.TX_read    = 0;
 COM2.TX_write   = 0;
 COM2.B_TX_busy  = 0;
 COM2.RX_Cnt     = 0;
 COM2.RX_TimeOut = 0;
 COM2.B_RX_OK    = 0;
 for(i=0; i<1; i++)	TX2_Buffer[i] = 0;
 for(i=0; i<1; i++)	RX2_Buffer[i] = 0;
 
 if((COMx->UART_Mode == (3<<6)) ||(COMx->UART_Mode == (1<<6)))	 
 {
 if(COMx->UART_Polity == 1)		IP2 |=  1;	 
 else									IP2 &= ~1;	 
 if(COMx->UART_Mode == (3<<6))	S2CON |=  (1<<7);	 
 else									S2CON &= ~(1<<7);	 
 j = (11059200L / 4) / COMx->UART_BaudRate;	 
 if(j >= 65536UL)	return 2;	 
 j = 65536UL - j;
 AUXR &= ~(1<<4);	 
 AUXR &= ~(1<<3);	 
 AUXR |=  (1<<2);	 
 TH2 = (u8)(j>>8);
 TL2 = (u8)j;
 IE2  &= ~(1<<2);	 
 AUXR |=  (1<<4);	 
 }
 else	return 2;	 
 if(COMx->UART_Interrupt == 1)	IE2   |=  1;		 
 else								IE2   &= ~1;		 
 if(COMx->UART_RxEnable == 1)	S2CON |=  (1<<4);	 
 else								S2CON &= ~(1<<4);	 
 P_SW2 = (P_SW2 & ~1) | (COMx->UART_P_SW & 0x01);	 
 }
 return 3;	 
 
 }
 
 uint8_t temp;
 int Rend;
 uint8_t config_mode;
 
 void UART1_int (void) interrupt 4 using 2
 {
 char buf;
 if(RI)
 {
 RI = 0;
 router_uart_isr(SBUF);
 if(COM1.B_RX_OK == 0)
 {		 
 buf	= SBUF;
 
 
 
 
 
 
 }
 }
 
 if(buf == 0xaf)
 {			   
 temp ++;
 }
 if(temp==5)
 {
 if(SBUF == 0x7f)
 {
 ISP_CONTR = 0x60;
 temp = 0;
 }
 }
 
 if(TI)
 {
 TI = 0;
 
 
 
 
 
 
 COM1.B_TX_busy = 0;
 }
 }
 
 
 void UART2_int (void) interrupt 8 using 3
 {
 if((S2CON & 1) != 0)
 {
  S2CON &= ~1;
 if(COM2.B_RX_OK == 0)	  
 {
 
 dust_uart_isr(S2BUF);
 
 
 
 }
 }
 
 if((S2CON & 2) != 0)
 {
  S2CON &= ~2;
 
 
 
 
 
 
 COM2.B_TX_busy = 0;
 }
 
 }
 
 void TX1_write2buff(u8 dat)	 
 {
 
 
 
 
 
 
 
 
 while(COM1.B_TX_busy);
 COM1.B_TX_busy = 1;
 SBUF = dat;
 }
 
 void PrintString1(u8 *puts)
 {
 for (; *puts != 0;	puts++)  TX1_write2buff(*puts); 	 
 }
 
 void Printf1(u8 *puts, u8 len)
 {
 u8 i;
 for( i=0;i<len;i++)
 {
 TX1_write2buff(puts[i]);
 }
 }
 
 void TX2_write2buff(u8 dat)	 
 {	
 
 
 
 
 
 
 
 
 while(COM2.B_TX_busy);
 COM2.B_TX_busy = 1;
 S2BUF = dat;
 }
 
 void PrintString2(u8 *puts)
 {
 for (; *puts != 0;	puts++)  TX2_write2buff(*puts); 	 
 }
 
 void Printf2(u8 *puts, u8 len)
 {
 u8 i;
 for( i=0;i<len;i++)
 {
 TX2_write2buff(puts[i]);
 }
 }
 
 
 
 
 
 
 
