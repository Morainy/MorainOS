/*************************************************************************
    > File Name: entry.c
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2015年04月02日 星期四 11时39分32秒
 ************************************************************************/

#include "console.h"
#include "debug.h"

int kern_entry()
{
	init_debug();
	console_clear();
	printk("Hello , Morain\n");
	printk_color(rc_black , rc_green , "Hello , OS kernel\n");	
	panic("test");
	return 0;
}
