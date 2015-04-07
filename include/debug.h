/*************************************************************************
    > File Name: debug.h
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2015年04月04日 星期六 09时17分37秒
 ************************************************************************/

#ifndef INCLUDE_DEBUG_H_
#define INCLUDE_DEBUG_H_

#include "console.h"
#include "vargs.h"
#include "elf.h"

#define assert(x , info)        \
		do{						\
			if(!(x)){           \
				panic(info);    \
			}                   \
		} while(0)
//编译期间静态检测
#define static_assert(x)        \
		switch(x) {case 0:case (x): ;}

// 初始化 Debug 信息
void init_debug();

// 打印当前的函数调用栈信息
void panic(const char * msg);

// 打印当前的段寄存器值
void print_cur_status();

//内核的打印函数
void printk(const char * format , ...);

//带颜色的内核打印函数
void printk_color(real_color_t back , real_color_t fore , const char * format , ...);

#endif
