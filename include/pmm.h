/*************************************************************************
    > File Name: pmm.h
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2015年04月08日 星期三 10时24分47秒
 ************************************************************************/

#ifndef INCLUDE_PMM_H_
#define INCLUDE_PMM_H_

#include "multiboot.h"

//线程栈大小
#define STACK_SIZE 8192

//支持的最大物理内存（512MB）
#define PMM_MAX_SIZE 0x20000000

//物理内存页框大小（4KB）
#define PMM_PAGE_SIZE 0x1000

//最多支持的物理页面个数
#define PAGE_MAX_SIZE (PMM_MAX_SIZE/PMM_PAGE_SIZE)

//页掩码   按照4KB对齐地址
#define PHY_PAGE_MASK 0xFFFFF000


//内核文件字在内存中的起始和结束位置
//在连接器脚本中部要求连接器定义
extern uint8_t kern_start[];
extern uint8_t kern_end[];

//输出BIOS提供的物理内存布局
void show_memory_map();

//初始化物理内存管理程序
void init_pmm();

//返回一个内存页的物理地址
uint32_t pmm_alloc_page();

//释放申请的内存
void pmm_free_page(uint32_t p);

#endif
