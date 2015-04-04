/*************************************************************************
    > File Name: common.h
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2015年04月03日 星期五 10时13分32秒
 ************************************************************************/

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include "types.h"

//端口写一个字节
void outb(uint16_t port , uint8_t value);

//端口读一个字节
uint8_t inb(uint16_t port);

//端口读一个字
uint16_t inw(uint16_t port);

#endif
