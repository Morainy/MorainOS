/*************************************************************************
    > File Name: printk.c
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2015年04月03日 星期五 21时06分19秒
 ************************************************************************/

#include "console.h"
#include "string.h"
#include "vargs.h"
#include "debug.h"

static int vsprintf(char * buff , const char * format , char * args);
//内核打印函数
void printk(const char * format , ...)
{
	static char buff[1024];
	va_list args;
	int i;

	va_start(args , format);
	i = vsprintf(buff , format , args);
	va_end(args);

	buff[i] = '\0';

	console_write(buff);
}

//带颜色的内核打印函数

void printk_color(real_color_t back , real_color_t fore , const char * format , ...)
{
	static char buff[1024];

	va_list args;

	int i;

	va_start(args , format);
	i = vsprintf(buff , format , args);
	va_end(args);

	buff[i] = '\0';

	console_write_color(buff , back , fore);

}

#define is_digit(c)  ((c) >= '0' && (c) <= '9')

static int skip_atoi(const char ** s)
{
	int i= 0;
	while(is_digit(**s))
	{
		i = i *10 + *((*s)++) - '0';
	}
	return i;
}

#define ZEROPAD 1
#define SIGN 2
#define PLUS 4
#define SPACE 8
#define LEFT 16
#define SPECIAL 32
#define SMALL 64

#define do_div(n,base) ({ \
		int __res; \
		__asm__("divl %4":"=a" (n),"=d" (__res):"0" (n),"1" (0),"r" (base)); \
		__res; })


