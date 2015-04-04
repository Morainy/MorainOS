/*************************************************************************
    > File Name: string.c
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2015年04月03日 星期五 17时07分19秒
 ************************************************************************/

#include "string.h"

inline void memcpy(uint8_t * dest , uint8_t * src , uint32_t len)
{
	while(len > 0)
	{
		*dest++ = *src++;
		len--;
	}
}

inline void memset(void * dest , uint8_t val , uint32_t len)
{
	int i;
	uint8_t * dst = (uint8_t *)dest;
	for(i =0 ; i < len ; i++)
	{
		dst[i] = val;
	}
}

inline void bzero(void * dest , uint32_t len)
{
	memset(dest , 0  , len);
}

inline int strcmp(const char * str1 , const char * str2)
{
	char * p1 = str1;
	char * p2 = str2;
	int ret;
	while(*p1 !='\0' && *p2 != '\0' && *p1 == *p1)
	{
		p1++;
		p2++;
	}
	ret = *p1 - *p2;
	return ret;
}

inline char * strcat(char * dest , const char * src)
{
	char * pdes = dest;
	char * psrc = src;
	while( *pdes != '\0')
	{
		pdes++;
	}
	while(*psrc != '\0')
	{
		*pdes++ = *psrc++;
	}
	*pdes = '\0';
	return dest;
}
inline int strlen(const char * src)
{
	int count = 0;
	char * psrc = src;
	while(*psrc != '\0')
	{
		count++;
	}
	return count;
}
