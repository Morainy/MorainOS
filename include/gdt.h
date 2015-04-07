/*************************************************************************
    > File Name: gdt.h
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2015年04月07日 星期二 11时05分53秒
 ************************************************************************/

#ifndef INCLUDE_GDT_H
#define INCLUDE_GDT_H

#include "types.h"
typedef
struct gdt_entry_t{
	uint16_t limit_low;		//段界限   15-0
	uint16_t base_low;		//段基地址  15-0
	uint8_t base_middle;	//段基地址  23-16
	uint8_t access;			//段存在位、描述符类型、描述符子类别
	uint8_t granularity;	//其他标志、段界限  19-16
	uint8_t base_high;		//段基地址  31-24
} __attribute__((packed)) gdt_entry_t;

typedef
struct gdt_ptr_t{
	uint16_t limit;		//全局描述符表限长
	uint32_t base;		//全局描述符表 32 位基地址
} __attribute__((packed)) gdt_ptr_t;

//初始化全局描述符表
void init_gdt();

//GDT  加载到GDTR的函数
extern void gdt_flush(uint32_t);

#endif
