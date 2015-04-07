/*************************************************************************
    > File Name: gdt.c
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2015年04月07日 星期二 11时22分23秒
 ************************************************************************/

#include "gdt.h"
#include "string.h"

#define GDT_LENGTH 5

gdt_entry_t gdt_entries[GDT_LENGTH];

gdt_ptr_t gdt_ptr;

static void gdt_set_gate(int32_t num , uint32_t base , uint32_t limit , 
		uint8_t access , uint8_t gran);

extern uint32_t stack;

void init_gdt()
{
	//全局描述符表界限  
	gdt_ptr.limit = sizeof(gdt_entry_t) * GDT_LENGTH - 1;
	gdt_ptr.base = (uint32_t)&gdt_entries;
	
	//采用Intel  平坦模型
	gdt_set_gate(0 , 0 , 0 , 0 , 0);
	gdt_set_gate(1 , 0 , 0xffffffff , 0x9A , 0xCF);
	gdt_set_gate(2 , 0 , 0xffffffff , 0x92 , 0xCF);
	gdt_set_gate(3 , 0 , 0xffffffff , 0xFA , 0xCF);
	gdt_set_gate(4 , 0 , 0xffffffff , 0xF2 , 0xCF);
	
	//加载全局描述符表地址到GPTR 寄存器
	gdt_flush((uint32_t)&gdt_ptr);
}

static void gdt_set_gate(int32_t num , uint32_t base , uint32_t limit , uint8_t access , uint8_t gran)
{
	gdt_entries[num].base_low =  (base & 0xFFFF);
	gdt_entries[num].base_middle =  (base >> 16) & 0xFF;
	gdt_entries[num].base_high =  (base >> 24) & 0xFF;
	
	gdt_entries[num].limit_low =  (limit & 0xFFFF);
	gdt_entries[num].granularity =  (limit >> 16) & 0xFF;
	
	gdt_entries[num].granularity |=  gran & 0xF0;
	gdt_entries[num].access =  access ;

}
