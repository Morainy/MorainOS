/*************************************************************************
    > File Name: pmm.c
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2015年04月08日 星期三 10时31分16秒
 ************************************************************************/

#include "multiboot.h"
#include "common.h"
#include "debug.h"
#include "pmm.h"

//物理内存页面管理的栈
static uint32_t pmm_stack[PAGE_MAX_SIZE + 1];

//物理内存管理的栈指针
static uint32_t pmm_stack_top;


//物理内存页的数量
uint32_t phy_page_count;

void show_memory_map()
{
	uint32_t mmap_addr = glb_mboot_ptr->mmap_addr;
	uint32_t mmap_length = glb_mboot_ptr->mmap_length;

	printk("Memory map:\n");

	mmap_entry_t * mmap = (mmap_entry_t * )mmap_addr;

	for(mmap = (mmap_entry_t *)mmap_addr ; (uint32_t)mmap < mmap_addr + mmap_length ; mmap++)
	{
		printk("base_addr = 0x%X%08X , length = 0x%X%08X , type = 0x%X\n" ,
			(uint32_t)mmap->base_addr_high , 
			(uint32_t)mmap->base_addr_low , 
			(uint32_t)mmap->length_high , 
			(uint32_t)mmap->length_low , 
			(uint32_t)mmap->type);
	}
}

void init_pmm()
{
	mmap_entry_t * mmap_start_addr = (mmap_entry_t *)glb_mboot_ptr->mmap_addr;
	mmap_entry_t * mmap_end_addr = (mmap_entry_t *)glb_mboot_ptr->mmap_addr + glb_mboot_ptr->mmap_length;
	mmap_entry_t * mmap_entry;
	for(mmap_entry = mmap_start_addr ; mmap_entry < mmap_end_addr ; mmap_entry++)
	{
		if(mmap_entry->type == 1 && mmap_entry->base_addr_low == 0x100000)
		{
			uint32_t page_addr = mmap_entry->base_addr_low + (uint32_t)(kern_end - kern_start);
			uint32_t length = mmap_entry->base_addr_low + mmap_entry->length_low;

			while(page_addr <= length && page_addr <= PMM_MAX_SIZE)
			{
				pmm_free_page(page_addr);
				page_addr += PMM_PAGE_SIZE;
				phy_page_count++;
			}
		}
	}
}

uint32_t pmm_alloc_page()
{
	assert(pmm_stack_top != 0 , "out of memory");
	uint32_t page = pmm_stack[pmm_stack_top--];
	return page;
}
void pmm_free_page(uint32_t p)
{
	assert(pmm_stack_top != PAGE_MAX_SIZE , "out of pmm_stack stack");
	pmm_stack[++pmm_stack_top] = p;
}
