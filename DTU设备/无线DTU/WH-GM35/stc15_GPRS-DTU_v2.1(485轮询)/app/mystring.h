#ifndef __MYSTRING__h
#define __MYSTRING__H


char *strpbrk(const char *cs, const char *ct);
char *strsep(char **s, const char *ct);
char * strtrim(char *s);
void trim(char *strIn, char *strOut);
char * strtrim_fast(char *s) ;
#endif