
#line 1 "app\service\cjsion\cJSON.c" /0




















 
 
 
 
 
  
#line 1 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STRING.H" /0






 
 
 
 
 
 
 
 typedef unsigned int size_t;
 
 
 
 
 
 
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
 
 
#line 26 "app\service\cjsion\cJSON.c" /0
 
  
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
 
 
 
#line 27 "app\service\cjsion\cJSON.c" /0
 
  
#line 1 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\MATH.H" /0






 
 
 
 
 
 #pragma SAVE
 #pragma REGPARMS
 extern char  cabs  (char  val);
 extern int    abs  (int   val);
 extern long  labs  (long  val);
 extern float fabs  (float val);
 extern float sqrt  (float val);
 extern float exp   (float val);
 extern float log   (float val);
 extern float log10 (float val);
 extern float sin   (float val);
 extern float cos   (float val);
 extern float tan   (float val);
 extern float asin  (float val);
 extern float acos  (float val);
 extern float atan  (float val);
 extern float sinh  (float val);
 extern float cosh  (float val);
 extern float tanh  (float val);
 extern float atan2 (float y, float x);
 
 extern float ceil  (float val);
 extern float floor (float val);
 extern float modf  (float val, float *n);
 extern float fmod  (float x, float y);
 extern float pow   (float x, float y);
 
 #pragma RESTORE
 
 
#line 28 "app\service\cjsion\cJSON.c" /0
 
  
#line 1 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDLIB.H" /0






 
 
 
 
 
 
#line 13 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDLIB.H" /1
  
 
 
#line 16 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDLIB.H" /0
 
 
#line 18 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDLIB.H" /1
  
 
#line 20 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\STDLIB.H" /0
 
 
 
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
 
 
#line 29 "app\service\cjsion\cJSON.c" /0
 
  
#line 1 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\FLOAT.H" /0






 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 30 "app\service\cjsion\cJSON.c" /0
 
  
#line 1 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\LIMITS.H" /0







 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 31 "app\service\cjsion\cJSON.c" /0
 
  
#line 1 "D:\PROGRAM FILES (X86)\KEIL\C51\INC\CTYPE.H" /0






 
 
 
 
 
 #pragma SAVE
 #pragma REGPARMS
 extern bit isalpha (unsigned char);
 extern bit isalnum (unsigned char);
 extern bit iscntrl (unsigned char);
 extern bit isdigit (unsigned char);
 extern bit isgraph (unsigned char);
 extern bit isprint (unsigned char);
 extern bit ispunct (unsigned char);
 extern bit islower (unsigned char);
 extern bit isupper (unsigned char);
 extern bit isspace (unsigned char);
 extern bit isxdigit (unsigned char);
 extern unsigned char tolower (unsigned char);
 extern unsigned char toupper (unsigned char);
 extern unsigned char toint (unsigned char);
 
 
 
 
 #pragma RESTORE
 
 
#line 32 "app\service\cjsion\cJSON.c" /0
 
  
#line 1 "APP\SERVICE\CJSION\CJSON.H" /0




















 
 
 
 
 
 
#line 27 "APP\SERVICE\CJSION\CJSON.H" /1
 
 
 
#line 30 "APP\SERVICE\CJSION\CJSON.H" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef struct cJSON {
 struct cJSON *next,*prev;	 
 struct cJSON *child;		 
 
 int type;					 
 
 char *valuestring;			 
 int valueint;				 
 double valuedouble;			 
 
 char *string;				 
 } cJSON;
 
 typedef struct cJSON_Hooks {
 void *(*malloc_fn)(size_t sz);
 void (*free_fn)(void *ptr);
 } cJSON_Hooks;
 
 
 extern void cJSON_InitHooks(cJSON_Hooks* hooks);
 
 
 
 extern cJSON *cJSON_Parse(const char *value);
 
 extern char  *cJSON_Print(cJSON *item);
 
 extern char  *cJSON_PrintUnformatted(cJSON *item);
 
 extern char *cJSON_PrintBuffered(cJSON *item,int prebuffer,int fmt);
 
 extern void   cJSON_Delete(cJSON *c);
 
 
 extern int	  cJSON_GetArraySize(cJSON *array);
 
 extern cJSON *cJSON_GetArrayItem(cJSON *array,int item);
 
 extern cJSON *cJSON_GetObjectItem(cJSON *object,const char *string);
 
 
 extern const char *cJSON_GetErrorPtr(void);
 
 
 extern cJSON *cJSON_CreateNull(void);
 extern cJSON *cJSON_CreateTrue(void);
 extern cJSON *cJSON_CreateFalse(void);
 extern cJSON *cJSON_CreateBool(int b);
 extern cJSON *cJSON_CreateNumber(double num);
 extern cJSON *cJSON_CreateString(const char *string);
 extern cJSON *cJSON_CreateArray(void);
 extern cJSON *cJSON_CreateObject(void);
 
 
 extern cJSON *cJSON_CreateIntArray(const int *numbers,int count);
 extern cJSON *cJSON_CreateFloatArray(const float *numbers,int count);
 extern cJSON *cJSON_CreateDoubleArray(const double *numbers,int count);
 extern cJSON *cJSON_CreateStringArray(const char **strings,int count);
 
 
 extern void cJSON_AddItemToArray(cJSON *array, cJSON *item);
 extern void	cJSON_AddItemToObject(cJSON *object,const char *string,cJSON *item);
 extern void	cJSON_AddItemToObjectCS(cJSON *object,const char *string,cJSON *item);	 
 
 extern void cJSON_AddItemReferenceToArray(cJSON *array, cJSON *item);
 extern void	cJSON_AddItemReferenceToObject(cJSON *object,const char *string,cJSON *item);
 
 
 extern cJSON *cJSON_DetachItemFromArray(cJSON *array,int which);
 extern void   cJSON_DeleteItemFromArray(cJSON *array,int which);
 extern cJSON *cJSON_DetachItemFromObject(cJSON *object,const char *string);
 extern void   cJSON_DeleteItemFromObject(cJSON *object,const char *string);
 
 
 extern void cJSON_InsertItemInArray(cJSON *array,int which,cJSON *newitem);	 
 extern void cJSON_ReplaceItemInArray(cJSON *array,int which,cJSON *newitem);
 extern void cJSON_ReplaceItemInObject(cJSON *object,const char *string,cJSON *newitem);
 
 
 extern cJSON *cJSON_Duplicate(cJSON *item,int recurse);


 
 
 
 extern cJSON *cJSON_ParseWithOpts(const char *value,const char **return_parse_end,int require_null_terminated);
 
 extern void cJSON_Minify(char *json);
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 146 "APP\SERVICE\CJSION\CJSON.H" /1
 
 
#line 148 "APP\SERVICE\CJSION\CJSON.H" /0
 
 
#line 33 "app\service\cjsion\cJSON.c" /0
 
 
 static const char *ep;
 
 const char *cJSON_GetErrorPtr(void) {return ep;}
 
 static int cJSON_strcasecmp(const char *s1,const char *s2)
 {
 if (!s1) return (s1==s2)?0:1;if (!s2) return 1;
 for(; tolower(*s1) == tolower(*s2); ++s1, ++s2)	if(*s1 == 0)	return 0;
 return tolower(*(const unsigned char *)s1) - tolower(*(const unsigned char *)s2);
 }
 
 static void *(*cJSON_malloc)(size_t sz) = malloc;
 static void (*cJSON_free)(void *ptr) = free;
 
 static char* cJSON_strdup(const char* str)
 {
 size_t len;
 char* copy;
 
 len = strlen(str) + 1;
 if (!(copy = (char*)cJSON_malloc(len))) return 0;
 memcpy(copy,str,len);
 return copy;
 }
 
 void cJSON_InitHooks(cJSON_Hooks* hooks)
 {
 if (!hooks) {  
 cJSON_malloc = malloc;
 cJSON_free = free;
 return;
 }
 
 cJSON_malloc = (hooks->malloc_fn)?hooks->malloc_fn:malloc;
 cJSON_free	 = (hooks->free_fn)?hooks->free_fn:free;
 }
 
 
 static cJSON *cJSON_New_Item(void)
 {
 cJSON* node = (cJSON*)cJSON_malloc(sizeof(cJSON));
 if (node) memset(node,0,sizeof(cJSON));
 return node;
 }
 
 
 void cJSON_Delete(cJSON *c)
 {
 cJSON *next;
 while (c)
 {
 next=c->next;
 if (!(c->type&64) && c->child) cJSON_Delete(c->child);
 if (!(c->type&64) && c->valuestring) cJSON_free(c->valuestring);
 if (!(c->type&128) && c->string) cJSON_free(c->string);
 cJSON_free(c);
 c=next;
 }
 }
 
 
 static const char *parse_number(cJSON *item,const char *num)
 {
 double n=0,sign=1,scale=0;int subscale=0,signsubscale=1;
 
 if (*num=='-') sign=-1,num++;	 
 if (*num=='0') num++;			 
 if (*num>='1' && *num<='9')	do	n=(n*10.0)+(*num++ -'0');	while (*num>='0' && *num<='9');	 
 if (*num=='.' && num[1]>='0' && num[1]<='9') {num++;		do	n=(n*10.0)+(*num++ -'0'),scale--; while (*num>='0' && *num<='9');}	 
 if (*num=='e' || *num=='E')		 
 {	num++;if (*num=='+') num++;	else if (*num=='-') signsubscale=-1,num++;		 
 while (*num>='0' && *num<='9') subscale=(subscale*10)+(*num++ - '0');	 
 }
 
 n=sign*n*pow(10.0,(scale+subscale*signsubscale));	 
 
 item->valuedouble=n;
 item->valueint=(int)n;
 item->type=3;
 return num;
 }
 
 static int pow2gt (int x)	{	--x;	x|=x>>1;	x|=x>>2;	x|=x>>4;	x|=x>>8;	x|=x>>16;	return x+1;	}
 
 typedef struct {char *buffer; int length; int offset; } printbuffer;
 
 static char* ensure(printbuffer *p,int needed)
 {
 char *newbuffer;int newsize;
 if (!p || !p->buffer) return 0;
 needed+=p->offset;
 if (needed<=p->length) return p->buffer+p->offset;
 
 newsize=pow2gt(needed);
 newbuffer=(char*)cJSON_malloc(newsize);
 if (!newbuffer) {cJSON_free(p->buffer);p->length=0,p->buffer=0;return 0;}
 if (newbuffer) memcpy(newbuffer,p->buffer,p->length);
 cJSON_free(p->buffer);
 p->length=newsize;
 p->buffer=newbuffer;
 return newbuffer+p->offset;
 }
 
 static int update(printbuffer *p)
 {
 char *str;
 if (!p || !p->buffer) return 0;
 str=p->buffer+p->offset;
 return p->offset+strlen(str);
 }
 
 
 static char *print_number(cJSON *item,printbuffer *p)
 {
 char *str=0;
 double d=item->valuedouble;
 if (d==0)
 {
 if (p)	str=ensure(p,2);
 else	str=(char*)cJSON_malloc(2);	 
 if (str) strcpy(str,"0");
 }
 else if (fabs(((double)item->valueint)-d)<=5.96046e-8 && d<=32767 && d>=(-32767-1))
 {
 if (p)	str=ensure(p,21);
 else	str=(char*)cJSON_malloc(21);	 
 if (str)	sprintf(str,"%d",item->valueint);
 }
 else
 {
 if (p)	str=ensure(p,64);
 else	str=(char*)cJSON_malloc(64);	 
 if (str)
 {
 if (fabs(floor(d)-d)<=5.96046e-8 && fabs(d)<1.0e60)sprintf(str,"%.0f",d);
 else if (fabs(d)<1.0e-6 || fabs(d)>1.0e9)			sprintf(str,"%e",d);
 else												sprintf(str,"%f",d);
 }
 }
 return str;
 }
 
 static unsigned parse_hex4(const char *str)
 {
 unsigned h=0;
 if (*str>='0' && *str<='9') h+=(*str)-'0'; else if (*str>='A' && *str<='F') h+=10+(*str)-'A'; else if (*str>='a' && *str<='f') h+=10+(*str)-'a'; else return 0;
 h=h<<4;str++;
 if (*str>='0' && *str<='9') h+=(*str)-'0'; else if (*str>='A' && *str<='F') h+=10+(*str)-'A'; else if (*str>='a' && *str<='f') h+=10+(*str)-'a'; else return 0;
 h=h<<4;str++;
 if (*str>='0' && *str<='9') h+=(*str)-'0'; else if (*str>='A' && *str<='F') h+=10+(*str)-'A'; else if (*str>='a' && *str<='f') h+=10+(*str)-'a'; else return 0;
 h=h<<4;str++;
 if (*str>='0' && *str<='9') h+=(*str)-'0'; else if (*str>='A' && *str<='F') h+=10+(*str)-'A'; else if (*str>='a' && *str<='f') h+=10+(*str)-'a'; else return 0;
 return h;
 }
 
 
 static const unsigned char firstByteMark[7] = { 0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC };
 static const char *parse_string(cJSON *item,const char *str)
 {
 const char *ptr=str+1;char *ptr2;char *out;int len=0;unsigned uc,uc2;
 if (*str!='\"') {ep=str;return 0;}	 
 
 while (*ptr!='\"' && *ptr && ++len) if (*ptr++ == '\\') ptr++;	 
 
 out=(char*)cJSON_malloc(len+1);	 
 if (!out) return 0;
 
 ptr=str+1;ptr2=out;
 while (*ptr!='\"' && *ptr)
 {
 if (*ptr!='\\') *ptr2++=*ptr++;
 else
 {
 ptr++;
 switch (*ptr)
 {
 case 'b': *ptr2++='\b';	break;
 case 'f': *ptr2++='\f';	break;
 case 'n': *ptr2++='\n';	break;
 case 'r': *ptr2++='\r';	break;
 case 't': *ptr2++='\t';	break;
 case 'u':	  
 uc=parse_hex4(ptr+1);ptr+=4;	 
 
 if ((uc>=0xDC00 && uc<=0xDFFF) || uc==0)	break;	 
 
 if (uc>=0xD800 && uc<=0xDBFF)	 
 {
 if (ptr[1]!='\\' || ptr[2]!='u')	break;	 
 uc2=parse_hex4(ptr+3);ptr+=6;
 if (uc2<0xDC00 || uc2>0xDFFF)		break;	 
 uc=0x10000 + (((uc&0x3FF)<<10) | (uc2&0x3FF));
 }
 
 len=4;if (uc<0x80) len=1;else if (uc<0x800) len=2;else if (uc<0x10000) len=3; ptr2+=len;
 
 switch (len) {
 case 4: *--ptr2 =((uc | 0x80) & 0xBF); uc >>= 6;
 case 3: *--ptr2 =((uc | 0x80) & 0xBF); uc >>= 6;
 case 2: *--ptr2 =((uc | 0x80) & 0xBF); uc >>= 6;
 case 1: *--ptr2 =(uc | firstByteMark[len]);
 }
 ptr2+=len;
 break;
 default:  *ptr2++=*ptr; break;
 }
 ptr++;
 }
 }
 *ptr2=0;
 if (*ptr=='\"') ptr++;
 item->valuestring=out;
 item->type=4;
 return ptr;
 }
 
 
 static char *print_string_ptr(const char *str,printbuffer *p)
 {
 const char *ptr;char *ptr2,*out;int len=0,flag=0;unsigned char token;
 
 for (ptr=str;*ptr;ptr++) flag|=((*ptr>0 && *ptr<32)||(*ptr=='\"')||(*ptr=='\\'))?1:0;
 if (!flag)
 {
 len=ptr-str;
 if (p) out=ensure(p,len+3);
 else		out=(char*)cJSON_malloc(len+3);
 if (!out) return 0;
 ptr2=out;*ptr2++='\"';
 strcpy(ptr2,str);
 ptr2[len]='\"';
 ptr2[len+1]=0;
 return out;
 }
 
 if (!str)
 {
 if (p)	out=ensure(p,3);
 else	out=(char*)cJSON_malloc(3);
 if (!out) return 0;
 strcpy(out,"\"\"");
 return out;
 }
 ptr=str;while ((token=*ptr) && ++len) {if (strchr("\"\\\b\f\n\r\t",token)) len++; else if (token<32) len+=5;ptr++;}
 
 if (p)	out=ensure(p,len+3);
 else	out=(char*)cJSON_malloc(len+3);
 if (!out) return 0;
 
 ptr2=out;ptr=str;
 *ptr2++='\"';
 while (*ptr)
 {
 if ((unsigned char)*ptr>31 && *ptr!='\"' && *ptr!='\\') *ptr2++=*ptr++;
 else
 {
 *ptr2++='\\';
 switch (token=*ptr++)
 {
 case '\\':	*ptr2++='\\';	break;
 case '\"':	*ptr2++='\"';	break;
 case '\b':	*ptr2++='b';	break;
 case '\f':	*ptr2++='f';	break;
 case '\n':	*ptr2++='n';	break;
 case '\r':	*ptr2++='r';	break;
 case '\t':	*ptr2++='t';	break;
 default: sprintf(ptr2,"u%04x",token);ptr2+=5;	break;	 
 }
 }
 }
 *ptr2++='\"';*ptr2++=0;
 return out;
 }
 
 static char *print_string(cJSON *item,printbuffer *p)	{return print_string_ptr(item->valuestring,p);}
 
 
 static const char *parse_value(cJSON *item,const char *value);
 static char *print_value(cJSON *item,int depth,int fmt,printbuffer *p);
 static const char *parse_array(cJSON *item,const char *value);
 static char *print_array(cJSON *item,int depth,int fmt,printbuffer *p);
 static const char *parse_object(cJSON *item,const char *value);
 static char *print_object(cJSON *item,int depth,int fmt,printbuffer *p);
 
 
 static const char *skip(const char *in) {while (in && *in && (unsigned char)*in<=32) in++; return in;}
 
 
 cJSON *cJSON_ParseWithOpts(const char *value,const char **return_parse_end,int require_null_terminated)
 {
 const char *end=0;
 cJSON *c=cJSON_New_Item();
 ep=0;
 if (!c) return 0;        
 
 end=parse_value(c,skip(value));
 if (!end)	{cJSON_Delete(c);return 0;}	 
 
 
 if (require_null_terminated) {end=skip(end);if (*end) {cJSON_Delete(c);ep=end;return 0;}}
 if (return_parse_end) *return_parse_end=end;
 return c;
 }
 
 cJSON *cJSON_Parse(const char *value) {return cJSON_ParseWithOpts(value,0,0);}
 
 
 char *cJSON_Print(cJSON *item)				{return print_value(item,0,1,0);}
 char *cJSON_PrintUnformatted(cJSON *item)	{return print_value(item,0,0,0);}
 
 char *cJSON_PrintBuffered(cJSON *item,int prebuffer,int fmt)
 {
 printbuffer p;
 p.buffer=(char*)cJSON_malloc(prebuffer);
 p.length=prebuffer;
 p.offset=0;
 return print_value(item,0,fmt,&p);
 return p.buffer;
 }
 
 
 
 static const char *parse_value(cJSON *item,const char *value)
 {
 if (!value)						return 0;	 
 if (!strncmp(value,"null",4))	{ item->type=2;  return value+4; }
 if (!strncmp(value,"false",5))	{ item->type=0; return value+5; }
 if (!strncmp(value,"true",4))	{ item->type=1; item->valueint=1;	return value+4; }
 if (*value=='\"')				{ return parse_string(item,value); }
 if (*value=='-' || (*value>='0' && *value<='9'))	{ return parse_number(item,value); }
 if (*value=='[')				{ return parse_array(item,value); }
 if (*value=='{')				{ return parse_object(item,value); }
 
 ep=value;return 0;	 
 }
 
 
 static char *print_value(cJSON *item,int depth,int fmt,printbuffer *p)
 {
 char *out=0;
 if (!item) return 0;
 if (p)
 {
 switch ((item->type)&255)
 {
 case 2:	{out=ensure(p,5);	if (out) strcpy(out,"null");	break;}
 case 0:	{out=ensure(p,6);	if (out) strcpy(out,"false");	break;}
 case 1:	{out=ensure(p,5);	if (out) strcpy(out,"true");	break;}
 case 3:	out=print_number(item,p);break;
 case 4:	out=print_string(item,p);break;
 case 5:	out=print_array(item,depth,fmt,p);break;
 case 6:	out=print_object(item,depth,fmt,p);break;
 }
 }
 else
 {
 switch ((item->type)&255)
 {
 case 2:	out=cJSON_strdup("null");	break;
 case 0:	out=cJSON_strdup("false");break;
 case 1:	out=cJSON_strdup("true"); break;
 case 3:	out=print_number(item,0);break;
 case 4:	out=print_string(item,0);break;
 case 5:	out=print_array(item,depth,fmt,0);break;
 case 6:	out=print_object(item,depth,fmt,0);break;
 }
 }
 return out;
 }
 
 
 static const char *parse_array(cJSON *item,const char *value)
 {
 cJSON *child;
 if (*value!='[')	{ep=value;return 0;}	 
 
 item->type=5;
 value=skip(value+1);
 if (*value==']') return value+1;	 
 
 item->child=child=cJSON_New_Item();
 if (!item->child) return 0;		  
 value=skip(parse_value(child,skip(value)));	 
 if (!value) return 0;
 
 while (*value==',')
 {
 cJSON *new_item;
 if (!(new_item=cJSON_New_Item())) return 0; 	 
 child->next=new_item;new_item->prev=child;child=new_item;
 value=skip(parse_value(child,skip(value+1)));
 if (!value) return 0;	 
 }
 
 if (*value==']') return value+1;	 
 ep=value;return 0;	 
 }
 
 
 static char *print_array(cJSON *item,int depth,int fmt,printbuffer *p)
 {
 char **entries;
 char *out=0,*ptr,*ret;int len=5;
 cJSON *child=item->child;
 int numentries=0,i=0,fail=0;
 size_t tmplen=0;
 
 
 while (child) numentries++,child=child->next;
 
 if (!numentries)
 {
 if (p)	out=ensure(p,3);
 else	out=(char*)cJSON_malloc(3);
 if (out) strcpy(out,"[]");
 return out;
 }
 
 if (p)
 {
 
 i=p->offset;
 ptr=ensure(p,1);if (!ptr) return 0;	*ptr='[';	p->offset++;
 child=item->child;
 while (child && !fail)
 {
 print_value(child,depth+1,fmt,p);
 p->offset=update(p);
 if (child->next) {len=fmt?2:1;ptr=ensure(p,len+1);if (!ptr) return 0;*ptr++=',';if(fmt)*ptr++=' ';*ptr=0;p->offset+=len;}
 child=child->next;
 }
 ptr=ensure(p,2);if (!ptr) return 0;	*ptr++=']';*ptr=0;
 out=(p->buffer)+i;
 }
 else
 {
 
 entries=(char**)cJSON_malloc(numentries*sizeof(char*));
 if (!entries) return 0;
 memset(entries,0,numentries*sizeof(char*));
 
 child=item->child;
 while (child && !fail)
 {
 ret=print_value(child,depth+1,fmt,0);
 entries[i++]=ret;
 if (ret) len+=strlen(ret)+2+(fmt?1:0); else fail=1;
 child=child->next;
 }
 
 
 if (!fail)	out=(char*)cJSON_malloc(len);
 
 if (!out) fail=1;
 
 
 if (fail)
 {
 for (i=0;i<numentries;i++) if (entries[i]) cJSON_free(entries[i]);
 cJSON_free(entries);
 return 0;
 }
 
 
 *out='[';
 ptr=out+1;*ptr=0;
 for (i=0;i<numentries;i++)
 {
 tmplen=strlen(entries[i]);memcpy(ptr,entries[i],tmplen);ptr+=tmplen;
 if (i!=numentries-1) {*ptr++=',';if(fmt)*ptr++=' ';*ptr=0;}
 cJSON_free(entries[i]);
 }
 cJSON_free(entries);
 *ptr++=']';*ptr++=0;
 }
 return out;	
 }
 
 
 static const char *parse_object(cJSON *item,const char *value)
 {
 cJSON *child;
 if (*value!='{')	{ep=value;return 0;}	 
 
 item->type=6;
 value=skip(value+1);
 if (*value=='}') return value+1;	 
 
 item->child=child=cJSON_New_Item();
 if (!item->child) return 0;
 value=skip(parse_string(child,skip(value)));
 if (!value) return 0;
 child->string=child->valuestring;child->valuestring=0;
 if (*value!=':') {ep=value;return 0;}	 
 value=skip(parse_value(child,skip(value+1)));	 
 if (!value) return 0;
 
 while (*value==',')
 {
 cJSON *new_item;
 if (!(new_item=cJSON_New_Item()))	return 0;  
 child->next=new_item;new_item->prev=child;child=new_item;
 value=skip(parse_string(child,skip(value+1)));
 if (!value) return 0;
 child->string=child->valuestring;child->valuestring=0;
 if (*value!=':') {ep=value;return 0;}	 
 value=skip(parse_value(child,skip(value+1)));	 
 if (!value) return 0;
 }
 
 if (*value=='}') return value+1;	 
 ep=value;return 0;	 
 }
 
 
 static char *print_object(cJSON *item,int depth,int fmt,printbuffer *p)
 {
 char **entries=0,**names=0;
 char *out=0,*ptr,*ret,*str;int len=7,i=0,j;
 cJSON *child=item->child;
 int numentries=0,fail=0;
 size_t tmplen=0;
 
 while (child) numentries++,child=child->next;
 
 if (!numentries)
 {
 if (p) out=ensure(p,fmt?depth+4:3);
 else	out=(char*)cJSON_malloc(fmt?depth+4:3);
 if (!out)	return 0;
 ptr=out;*ptr++='{';
 if (fmt) {*ptr++='\n';for (i=0;i<depth-1;i++) *ptr++='\t';}
 *ptr++='}';*ptr++=0;
 return out;
 }
 if (p)
 {
 
 i=p->offset;
 len=fmt?2:1;	ptr=ensure(p,len+1);	if (!ptr) return 0;
 *ptr++='{';	if (fmt) *ptr++='\n';	*ptr=0;	p->offset+=len;
 child=item->child;depth++;
 while (child)
 {
 if (fmt)
 {
 ptr=ensure(p,depth);	if (!ptr) return 0;
 for (j=0;j<depth;j++) *ptr++='\t';
 p->offset+=depth;
 }
 print_string_ptr(child->string,p);
 p->offset=update(p);
 
 len=fmt?2:1;
 ptr=ensure(p,len);	if (!ptr) return 0;
 *ptr++=':';if (fmt) *ptr++='\t';
 p->offset+=len;
 
 print_value(child,depth,fmt,p);
 p->offset=update(p);
 
 len=(fmt?1:0)+(child->next?1:0);
 ptr=ensure(p,len+1); if (!ptr) return 0;
 if (child->next) *ptr++=',';
 if (fmt) *ptr++='\n';*ptr=0;
 p->offset+=len;
 child=child->next;
 }
 ptr=ensure(p,fmt?(depth+1):2);	 if (!ptr) return 0;
 if (fmt)	for (i=0;i<depth-1;i++) *ptr++='\t';
 *ptr++='}';*ptr=0;
 out=(p->buffer)+i;
 }
 else
 {
 
 entries=(char**)cJSON_malloc(numentries*sizeof(char*));
 if (!entries) return 0;
 names=(char**)cJSON_malloc(numentries*sizeof(char*));
 if (!names) {cJSON_free(entries);return 0;}
 memset(entries,0,sizeof(char*)*numentries);
 memset(names,0,sizeof(char*)*numentries);
 
 
 child=item->child;depth++;if (fmt) len+=depth;
 while (child)
 {
 names[i]=str=print_string_ptr(child->string,0);
 entries[i++]=ret=print_value(child,depth,fmt,0);
 if (str && ret) len+=strlen(ret)+strlen(str)+2+(fmt?2+depth:0); else fail=1;
 child=child->next;
 }
 
 
 if (!fail)	out=(char*)cJSON_malloc(len);
 if (!out) fail=1;
 
 
 if (fail)
 {
 for (i=0;i<numentries;i++) {if (names[i]) cJSON_free(names[i]);if (entries[i]) cJSON_free(entries[i]);}
 cJSON_free(names);cJSON_free(entries);
 return 0;
 }
 
 
 *out='{';ptr=out+1;if (fmt)*ptr++='\n';*ptr=0;
 for (i=0;i<numentries;i++)
 {
 if (fmt) for (j=0;j<depth;j++) *ptr++='\t';
 tmplen=strlen(names[i]);memcpy(ptr,names[i],tmplen);ptr+=tmplen;
 *ptr++=':';if (fmt) *ptr++='\t';
 strcpy(ptr,entries[i]);ptr+=strlen(entries[i]);
 if (i!=numentries-1) *ptr++=',';
 if (fmt) *ptr++='\n';*ptr=0;
 cJSON_free(names[i]);cJSON_free(entries[i]);
 }
 
 cJSON_free(names);cJSON_free(entries);
 if (fmt) for (i=0;i<depth-1;i++) *ptr++='\t';
 *ptr++='}';*ptr++=0;
 }
 return out;	
 }
 
 
 int    cJSON_GetArraySize(cJSON *array)							{cJSON *c=array->child;int i=0;while(c)i++,c=c->next;return i;}
 cJSON *cJSON_GetArrayItem(cJSON *array,int item)				{cJSON *c=array->child;  while (c && item>0) item--,c=c->next; return c;}
 cJSON *cJSON_GetObjectItem(cJSON *object,const char *string)	{cJSON *c=object->child; while (c && cJSON_strcasecmp(c->string,string)) c=c->next; return c;}
 
 
 static void suffix_object(cJSON *prev,cJSON *item) {prev->next=item;item->prev=prev;}
 
 static cJSON *create_reference(cJSON *item) {cJSON *ref=cJSON_New_Item();if (!ref) return 0;memcpy(ref,item,sizeof(cJSON));ref->string=0;ref->type|=64;ref->next=ref->prev=0;return ref;}
 
 
 void   cJSON_AddItemToArray(cJSON *array, cJSON *item)						{cJSON *c=array->child;if (!item) return; if (!c) {array->child=item;} else {while (c && c->next) c=c->next; suffix_object(c,item);}}
 void   cJSON_AddItemToObject(cJSON *object,const char *string,cJSON *item)	{if (!item) return; if (item->string) cJSON_free(item->string);item->string=cJSON_strdup(string);cJSON_AddItemToArray(object,item);}
 void   cJSON_AddItemToObjectCS(cJSON *object,const char *string,cJSON *item)	{if (!item) return; if (!(item->type&128) && item->string) cJSON_free(item->string);item->string=(char*)string;item->type|=128;cJSON_AddItemToArray(object,item);}
 void	cJSON_AddItemReferenceToArray(cJSON *array, cJSON *item)						{cJSON_AddItemToArray(array,create_reference(item));}
 void	cJSON_AddItemReferenceToObject(cJSON *object,const char *string,cJSON *item)	{cJSON_AddItemToObject(object,string,create_reference(item));}
 
 cJSON *cJSON_DetachItemFromArray(cJSON *array,int which)			{cJSON *c=array->child;while (c && which>0) c=c->next,which--;if (!c) return 0;
 if (c->prev) c->prev->next=c->next;if (c->next) c->next->prev=c->prev;if (c==array->child) array->child=c->next;c->prev=c->next=0;return c;}
 void   cJSON_DeleteItemFromArray(cJSON *array,int which)			{cJSON_Delete(cJSON_DetachItemFromArray(array,which));}
 cJSON *cJSON_DetachItemFromObject(cJSON *object,const char *string) {int i=0;cJSON *c=object->child;while (c && cJSON_strcasecmp(c->string,string)) i++,c=c->next;if (c) return cJSON_DetachItemFromArray(object,i);return 0;}
 void   cJSON_DeleteItemFromObject(cJSON *object,const char *string) {cJSON_Delete(cJSON_DetachItemFromObject(object,string));}
 
 
 void   cJSON_InsertItemInArray(cJSON *array,int which,cJSON *newitem)		{cJSON *c=array->child;while (c && which>0) c=c->next,which--;if (!c) {cJSON_AddItemToArray(array,newitem);return;}
 newitem->next=c;newitem->prev=c->prev;c->prev=newitem;if (c==array->child) array->child=newitem; else newitem->prev->next=newitem;}
 void   cJSON_ReplaceItemInArray(cJSON *array,int which,cJSON *newitem)		{cJSON *c=array->child;while (c && which>0) c=c->next,which--;if (!c) return;
 newitem->next=c->next;newitem->prev=c->prev;if (newitem->next) newitem->next->prev=newitem;
 if (c==array->child) array->child=newitem; else newitem->prev->next=newitem;c->next=c->prev=0;cJSON_Delete(c);}
 void   cJSON_ReplaceItemInObject(cJSON *object,const char *string,cJSON *newitem){int i=0;cJSON *c=object->child;while(c && cJSON_strcasecmp(c->string,string))i++,c=c->next;if(c){newitem->string=cJSON_strdup(string);cJSON_ReplaceItemInArray(object,i,newitem);}}
 
 
 cJSON *cJSON_CreateNull(void)					{cJSON *item=cJSON_New_Item();if(item)item->type=2;return item;}
 cJSON *cJSON_CreateTrue(void)					{cJSON *item=cJSON_New_Item();if(item)item->type=1;return item;}
 cJSON *cJSON_CreateFalse(void)					{cJSON *item=cJSON_New_Item();if(item)item->type=0;return item;}
 cJSON *cJSON_CreateBool(int b)					{cJSON *item=cJSON_New_Item();if(item)item->type=b?1:0;return item;}
 cJSON *cJSON_CreateNumber(double num)			{cJSON *item=cJSON_New_Item();if(item){item->type=3;item->valuedouble=num;item->valueint=(int)num;}return item;}
 cJSON *cJSON_CreateString(const char *string)	{cJSON *item=cJSON_New_Item();if(item){item->type=4;item->valuestring=cJSON_strdup(string);}return item;}
 cJSON *cJSON_CreateArray(void)					{cJSON *item=cJSON_New_Item();if(item)item->type=5;return item;}
 cJSON *cJSON_CreateObject(void)					{cJSON *item=cJSON_New_Item();if(item)item->type=6;return item;}
 
 
 cJSON *cJSON_CreateIntArray(const int *numbers,int count)		{int i;cJSON *n=0,*p=0,*a=cJSON_CreateArray();for(i=0;a && i<count;i++){n=cJSON_CreateNumber(numbers[i]);if(!i)a->child=n;else suffix_object(p,n);p=n;}return a;}
 cJSON *cJSON_CreateFloatArray(const float *numbers,int count)	{int i;cJSON *n=0,*p=0,*a=cJSON_CreateArray();for(i=0;a && i<count;i++){n=cJSON_CreateNumber(numbers[i]);if(!i)a->child=n;else suffix_object(p,n);p=n;}return a;}
 cJSON *cJSON_CreateDoubleArray(const double *numbers,int count)	{int i;cJSON *n=0,*p=0,*a=cJSON_CreateArray();for(i=0;a && i<count;i++){n=cJSON_CreateNumber(numbers[i]);if(!i)a->child=n;else suffix_object(p,n);p=n;}return a;}
 cJSON *cJSON_CreateStringArray(const char **strings,int count)	{int i;cJSON *n=0,*p=0,*a=cJSON_CreateArray();for(i=0;a && i<count;i++){n=cJSON_CreateString(strings[i]);if(!i)a->child=n;else suffix_object(p,n);p=n;}return a;}
 
 
 cJSON *cJSON_Duplicate(cJSON *item,int recurse)
 {
 cJSON *newitem,*cptr,*nptr=0,*newchild;
 
 if (!item) return 0;
 
 newitem=cJSON_New_Item();
 if (!newitem) return 0;
 
 newitem->type=item->type&(~64),newitem->valueint=item->valueint,newitem->valuedouble=item->valuedouble;
 if (item->valuestring)	{newitem->valuestring=cJSON_strdup(item->valuestring);	if (!newitem->valuestring)	{cJSON_Delete(newitem);return 0;}}
 if (item->string)		{newitem->string=cJSON_strdup(item->string);			if (!newitem->string)		{cJSON_Delete(newitem);return 0;}}
 
 if (!recurse) return newitem;
 
 cptr=item->child;
 while (cptr)
 {
 newchild=cJSON_Duplicate(cptr,1);		 
 if (!newchild) {cJSON_Delete(newitem);return 0;}
 if (nptr)	{nptr->next=newchild,newchild->prev=nptr;nptr=newchild;}	 
 else		{newitem->child=newchild;nptr=newchild;}					 
 cptr=cptr->next;
 }
 return newitem;
 }
 
 void cJSON_Minify(char *json)
 {
 char *into=json;
 while (*json)
 {
 if (*json==' ') json++;
 else if (*json=='\t') json++;	 
 else if (*json=='\r') json++;
 else if (*json=='\n') json++;
 else if (*json=='/' && json[1]=='/')  while (*json && *json!='\n') json++;	 
 else if (*json=='/' && json[1]=='*') {while (*json && !(*json=='*' && json[1]=='/')) json++;json+=2;}	 
 else if (*json=='\"'){*into++=*json++;while (*json && *json!='\"'){if (*json=='\\') *into++=*json++;*into++=*json++;}*into++=*json++;}  
 else *into++=*json++;			 
 }
 *into=0;	 
 }
