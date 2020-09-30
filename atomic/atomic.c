
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

#include <linux/atomic.h>


/* atomic integer demo */

static int myatomic_init(void) {
	atomic_t atm;

	atomic_set(&atm, 0);
	printk(KERN_INFO "atomic val: %d",atomic_read(&atm));

	atomic_inc(&atm); // incrementor
	printk(KERN_INFO "after inc atomic val: %d",atomic_read(&atm));


	/* void atomic_add(int i, atomic_t * v) */
	atomic_add(100,&atm);
	printk(KERN_INFO "after adding atomic val: %d",atomic_read(&atm));


	/*
	int atomic_inc_and_test(atomic_t *v);
	int atomic_dec_and_test(atomic_t *v);

	These two routines increment and decrement by 1,
 	respectively, the given atomic counter. They return a boolean 
 	indicating whether the resulting counter value was zero or not.


	bool atomic_sub_and_test(int i, atomic_t * v)

	subtract value from variable and test result


	*/

	return 0;
}

void myatomic_exit(void) {
	printk(KERN_INFO "Bye!!\n");
}

module_init(myatomic_init);
module_exit(myatomic_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Manish");
