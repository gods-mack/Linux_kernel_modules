

/* List all task kernel module */

#include <linux/sched.h>
#include<linux/sched/signal.h>

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>



const char* state_to_string(long state) {

	switch (state) {
		case TASK_RUNNING: return "TASK_RUNNING";
		case TASK_INTERRUPTIBLE: return "TASK_INTERRUPTIBLE";
		case TASK_UNINTERRUPTIBLE: return "TASK_UNINTERRUPTIBLE";
		case __TASK_STOPPED: return "__TASK_STOPPED";
		case __TASK_TRACED: return "__TASK_TRACED";
		case TASK_DEAD: return "TASK_DEAD";
		case TASK_WAKEKILL: return "TASK_WAKEKILL";
		case TASK_WAKING: return "TASK_WAKING";
		case TASK_PARKED: return "TASK_PARKED";
		case TASK_NOLOAD: return "TASK_NOLOAD";
		default: return "UNKNOWN";
	}
}



int listing_tasks_init(void) {
	struct task_struct *task;

	for_each_process(task) {
		printk(KERN_INFO "[pid: %d] pname: %s [state: %s]\n ", task->pid, task->comm, state_to_string(task->state));
	}
	return 0;
}

void listing_tasks_exit(void) {
	printk(KERN_INFO "unloading module\n");
}

module_init(listing_tasks_init);
module_exit(listing_tasks_exit)



MODULE_LICENSE("GPL");
MODULE_AUTHOR("Manish");
MODULE_DESCRIPTION("Show all tasks kernel module");
MODULE_VERSION("0.1");
