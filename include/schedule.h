/*
 * =====================================================================================
 *
 *       Filename:  schedule.h
 *
 *    Description:  任务调度描述
 *
 *        Version:  1.0
 *        Created:  2015年04月12日 09时08分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Morain 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef INCLUDE_SCHEDULE_H_
#define INCLUDE_SCHEDULE_H_

#include "task.h"

//可调度进程链表
extern struct task_struct * running_proc_head;

//等待进程链表
extern struct task_struct * wait_proc_head;

//当前运行的任务
extern struct task_struct * current;

// 内核栈的栈顶
extern uint32_t kern_stack_top;

//初始化任务调度
void init_sched();

//任务调度
void schedule();

//任务切换准备
void change_task_to(struct task_struct * next);

//任务切换
void switch_to(struct context * prev , struct context * next);

#endif
