
#line 1 "app\mystring.c" /0
  
#line 1 "APP\MYSTRING.H" /0
 
 
 
 
 char *strpbrk(const char *cs, const char *ct);
 char *strsep(char **s, const char *ct);
 char * strtrim(char *s);
 void trim(char *strIn, char *strOut);
 char * strtrim_fast(char *s) ;
 
#line 1 "app\mystring.c" /0
 
 
 
 




 
 char *strpbrk(const char *cs, const char *ct)
 {
 const char *sc1, *sc2;
 
 for (sc1 = cs; *sc1 != '\0'; ++sc1) {
 for (sc2 = ct; *sc2 != '\0'; ++sc2) {
 if (*sc1 == *sc2)
 return (char *)sc1;
 }
 }
 return 0;
 }
 
 










 
 char *strsep(char **s, const char *ct)
 {
 char *sbegin = *s;
 char *end;
 
 if (sbegin == 0)
 return 0;
 
 end = strpbrk(sbegin, ct);
 if (end)
 *end++ = '\0';
 *s = end;
 return sbegin;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


 
 
  
#line 1 "D:\KEIL_V5\C51\INC\STDLIB.H" /0






 
 
 
 
 
 
 
 typedef unsigned int size_t;
 
 
 
#line 18 "D:\KEIL_V5\C51\INC\STDLIB.H" /1
  
 
#line 20 "D:\KEIL_V5\C51\INC\STDLIB.H" /0
 
 
 
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
 
 
#line 72 "app\mystring.c" /0
 
  
#line 1 "D:\KEIL_V5\C51\INC\STDIO.H" /0






 
 
 
 
 
 
 
 
 
 
#line 17 "D:\KEIL_V5\C51\INC\STDIO.H" /1
  
 
#line 19 "D:\KEIL_V5\C51\INC\STDIO.H" /0
 
 
#line 21 "D:\KEIL_V5\C51\INC\STDIO.H" /1
  
 
 
#line 24 "D:\KEIL_V5\C51\INC\STDIO.H" /0
 
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
 
 
 
#line 73 "app\mystring.c" /0
 
  
#line 1 "D:\KEIL_V5\C51\INC\STRING.H" /0






 
 
 
 
 
 
#line 13 "D:\KEIL_V5\C51\INC\STRING.H" /1
  
 
 
#line 16 "D:\KEIL_V5\C51\INC\STRING.H" /0
 
 
#line 18 "D:\KEIL_V5\C51\INC\STRING.H" /1
  
 
#line 20 "D:\KEIL_V5\C51\INC\STRING.H" /0
 
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
 
 
#line 74 "app\mystring.c" /0
 
 
 char * strtrim(char *s) {
 char *p = s;
 char *q = s;
 while (*p==' ' || *p=='\t') ++p;
 while (*q++=*p++)
 ;
 q -= 2;
 while (*q==' ' || *q=='\t') --q;
 *(q+1) ='\0';
 return s;
 }
 
 char * strtrim_fast(char *s) {
 char *p = s;
 char *q = s;
 char *end = s;
 while (*p==' ' || *p=='\t') ++p;
 while (*q = *p) {
 if (*q!=' ' && *q!='\t') end = q+1;
 ++q, ++p;
 }
 *end = '\0';
 
 return s;
 }
 
 void trim(char *strIn, char *strOut){
 
 int i, j ;
 
 i = 0;
 
 j = strlen(strIn) - 1;
 
 while(strIn[i] == ' ' || strIn[i] == '\t')
 ++i;
 
 while(strIn[j] == ' ' || strIn[j] == '\t')
 --j;
 strncpy(strOut, strIn + i , j - i + 1);
 strOut[j - i + 1] = '\0';
 }
 
