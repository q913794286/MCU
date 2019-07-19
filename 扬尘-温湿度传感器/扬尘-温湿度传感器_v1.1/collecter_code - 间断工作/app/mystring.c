#include "mystring.h"


#define NULL 0
/**
 * strpbrk - Find the first occurrence of a set of characters
 * @cs: The string to be searched
 * @ct: The characters to search for
 */
char *strpbrk(const char *cs, const char *ct)
{
    const char *sc1, *sc2;

    for (sc1 = cs; *sc1 != '\0'; ++sc1) {
        for (sc2 = ct; *sc2 != '\0'; ++sc2) {
            if (*sc1 == *sc2)
                return (char *)sc1;
        }
    }
    return NULL;
}


/**
 * strsep - Split a string into tokens
 * @s: The string to be searched
 * @ct: The characters to search for
 *
 * strsep() updates @s to point after the token, ready for the next call.
 *
 * It returns empty tokens, too, behaving exactly like the libc function
 * of that name. In fact, it was stolen from glibc2 and de-fancy-fied.
 * Same semantics, slimmer shape. ;)
 */
char *strsep(char **s, const char *ct)
{
    char *sbegin = *s;
    char *end;

    if (sbegin == NULL)
        return NULL;

    end = strpbrk(sbegin, ct);
    if (end)
        *end++ = '\0';
    *s = end;
    return sbegin;
}

//char *rtrim(char *str)
//{
//    if (str == NULL || *str == '\0')
//    {
//        return str;
//    }
//
//    int len = strlen(str);
//    char *p = str + len - 1;
//    while (p >= str  && isspace(*p))
//    {
//        *p = '\0';
//        --p;
//    }
//
//    return str;
//}

/*
 * strtrim 去掉字符串前后的空格和制表符
 */ 

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

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

