/*************************************************************************
    > File Name: vargs.h
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2015年04月03日 星期五 20时48分50秒
 ************************************************************************/

#ifndef INCLUDE_VARGS_H_
#define INCLUDE_VARGS_H_

typedef __builtin_va_list va_list;

#define va_start(ap , last)    (__builtin_va_start(ap , last))
#define va_arg(ap , type)	(__builtin_va_arg(ap , type))
#define va_end(ap)

#endif
