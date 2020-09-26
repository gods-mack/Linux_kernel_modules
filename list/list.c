
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/list.h>     // linked-list kernel API

#include<linux/types.h>
#include<linux/string.h>
#include<linux/init.h>

#include<linux/slab.h> // for kmalloc or kzalloc



static LIST_HEAD(our_list);

struct p_list {
	char *name;
	int uid;
	int mobile;
	struct list_head list; // Linux list 
};



int our_list_init(void) {

	struct p_list *person;	
	int i;
	for(i = 0; i < 4; i++) {
		person = kmalloc(sizeof(*person), GFP_KERNEL);
		person->name = "RAMBO";
		person->uid = 2411 + i;
		person->mobile = 1234567+i;

		INIT_LIST_HEAD(&person->list);
		list_add_tail(&person->list, &our_list);

	}

	printk(KERN_INFO "Loading module...\n");
	printk(KERN_INFO "our list has been constructed\n");

	list_for_each_entry(person, &our_list, list) {

		printk(KERN_INFO "Name: %s uid: %d mobile: %d \n",person->name,person->uid,person->mobile);
	}


	return 0;

}


void our_list_exit(void ){

	struct p_list *person, *next;

	list_for_each_entry_safe(person,next,&our_list,list){
		printk(KERN_INFO "freeing memory\n");
		list_del(&person->list);
		kfree(person);
	}

	printk(KERN_INFO "unregistering module\n");
}

module_init(our_list_init);
module_exit(our_list_exit);



MODULE_LICENSE("GPL");
MODULE_AUTHOR("Manish");
MODULE_DESCRIPTION("Kernel Data Structure (List)");
MODULE_VERSION("0.1");