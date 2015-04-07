/*************************************************************************
    > File Name: console.h
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2015年04月03日 星期五 10时17分55秒
 ************************************************************************/

#ifndef INCLUDE_CONSOLE_H_
#define INCLUDE_CONSOLE_H_

#include "types.h"
#include "common.h"
typedef 
enum real_color
{
	rc_black = 0,
	rc_blue = 1,
	rc_green = 2,
	rc_cyan = 3,
	rc_red = 4,
	rc_magenta = 5,
	rc_brown = 6,
	rc_light_grey = 7,
	rc_dark_grey = 8,
	rc_light_blue = 9,
	rc_light_green = 10,
	rc_light_cyan = 11,
	rc_light_red = 12,
	rc_light_magenta = 13,
	rc_light_brown  = 14, 	// yellow
	rc_white = 15
}real_color_t;

//清屏
void console_clear();

// 在屏幕上输出一个带颜色的字符
void console_putc_color(char c , real_color_t back , real_color_t fore);

//在屏幕上输出一个以'\0'结尾的字符串，默认颜色为黑底白字
void console_write(char * cstr);


//在屏幕上输出一个带颜色的字符串
void console_write_color(char * cstr , real_color_t back , real_color_t fore);


//在屏幕上输出一个带颜色整形值的十六进制形式
void console_write_hex(uint32_t n , real_color_t back , real_color_t fore);


//在屏幕上输出一个带颜色整形值的十进制形式
void console_write_dec(uint32_t n , real_color_t back , real_color_t fore);

#endif

