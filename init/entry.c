/*************************************************************************
    > File Name: entry.c
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2015年04月02日 星期四 11时39分32秒
 ************************************************************************/

#include "console.h"
#include "string.h"
#include "debug.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"
#include "pmm.h"
#include "vmm.h"

void kern_init();

multiboot_t * glb_mboot_ptr;

extern uint32_t phy_page_count;

char kern_stack[STACK_SIZE];

__attribute__((section(".init.data"))) pgd_t * pgd_tmp = (pgd_t *)0x1000;
__attribute__((section(".init.data"))) pgd_t * pte_low = (pgd_t *)0x2000;
__attribute__((section(".init.data"))) pgd_t * pte_hign = (pgd_t *)0x3000;

__attribute__((section(".init.text"))) void kern_entry()
{
	pgd_tmp[0] = (uint32_t)pte_low | PAGE_PRESENT | PAGE_WRITE;
	pgd_tmp[PGD_INDEX(PAGE_OFFSET)] = (uint32_t)pte_hign | PAGE_PRESENT | PAGE_WRITE;

	//映射内核虚拟地址4MB到物理地址的前4MB
	int i;
	for(i = 0 ; i < 1024 ; i++)
	{
		pte_low[i] = (i << 12) | PAGE_PRESENT | PAGE_WRITE;
	}

	//映射0x00000000 - 0x00400000 的物理地址到虚拟地址0xC0000000 - 0xC0400000
	for(i = 0; i <1024 ; i++)
	{
		pte_hign[i] = (i << 12) | PAGE_PRESENT | PAGE_WRITE;
	}

	//设置临时页表
	asm volatile ("mov %0 , %%cr3"::"r"(pgd_tmp));

	uint32_t cr0;

	//启用分页机制，将cr0寄存器的分页位置设为1
	asm volatile ("mov %%cr0 , %0":"=r"(cr0));
	cr0 |= 0x80000000;
	asm volatile ("mov %0 , %%cr0"::"r"(cr0));


	//切换内核栈
	uint32_t kern_stack_top = ((uint32_t)kern_stack + STACK_SIZE) & 0xFFFFFFF0;
	asm volatile ("mov %0 , %%esp \n\t""xor %%ebp, %%ebp" : : "r" (kern_stack_top));

	//更新全局multiboot_t指针
	glb_mboot_ptr = mboot_ptr_tmp + PAGE_OFFSET;

	//调用内核初始化函数
	kern_init();
}

void kern_init()
{
	init_debug();
	init_gdt();
	init_idt();

	console_clear();
	printk_color(rc_black , rc_green , "Hello , OS kernel!\n\n");

	init_timer(200);

	printk("kernel in memory start:0x%08X\n",kern_start);
	printk("kernel in memory end:  0x%08X\n", kern_end);
	printk("kernel in memory used: %d KB\n\n",kern_end - kern_start);

	show_memory_map();
	init_pmm();

	printk_color(rc_black, rc_red, "\nThe Count of Physical Memory Page is: %u\n\n", phy_page_count);

    uint32_t allc_addr = NULL;
    printk_color(rc_black, rc_light_brown, "Test Physical Memory Alloc :\n");
    allc_addr = pmm_alloc_page();
    printk_color(rc_black, rc_light_brown, "Alloc Physical Addr: 0x%08X\n", allc_addr);
    allc_addr = pmm_alloc_page();
    printk_color(rc_black, rc_light_brown, "Alloc Physical Addr: 0x%08X\n", allc_addr);
    allc_addr = pmm_alloc_page();
    printk_color(rc_black, rc_light_brown, "Alloc Physical Addr: 0x%08X\n", allc_addr);
    allc_addr = pmm_alloc_page();
    printk_color(rc_black, rc_light_brown, "Alloc Physical Addr: 0x%08X\n", allc_addr);

}

