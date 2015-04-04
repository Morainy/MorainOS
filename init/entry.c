/*************************************************************************
    > File Name: entry.c
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2015年04月02日 星期四 11时39分32秒
 ************************************************************************/

#include "../include/console.h"
#include "debug.h"

int kern_entry()
{
	init_debug();
	console_clear();
	//console_write_color("Hello , OS Kernel!\n" , rc_black , rc_green);
	panic("test");
	return 0;
}
