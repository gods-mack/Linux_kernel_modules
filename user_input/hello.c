
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>


// to pass the arugument to he driver or module
#include <linux/moduleparam.h>




static int parm_var = 0;
// sudo insmod parm_var = 123122

module_param(parm_var,int, S_IRUSR | S_IWUSR);





int arr[3] = {0,0,0};


// #define module_param_array(name, type, nump, perm)

/**
 * module_param_array - a parameter which is an array of some type
 * @name: the name of the array variable
 * @type: the type, as per module_param()
 * @nump: optional pointer filled in with the number written
 * @perm: visibility in sysfs
 *
 * Input and output are as comma-separated values.  Commas inside values
 * don't work properly (eg. an array of charp).
 *
 * ARRAY_SIZE(@name) is used to determine the number of elements in the
 * array, so the definition must be visible.
 */

		
module_param_array(arr,int,NULL,S_IRUSR | S_IWUSR);


void display_arr(void) {
	printk(KERN_INFO "arr elements arr[0]:%d\n",arr[0]);
	printk(KERN_INFO "arr elements arr[1]:%d\n",arr[1]);
	printk(KERN_INFO "arr elements arr[2]:%d\n",arr[2]);
}

void display(void) {
	printk(KERN_INFO "value: %d\n",parm_var);
}

static int hello_init(void) {
        printk(KERN_INFO "welcome to LKM\n");
        display();
        display_arr();
        return 0;
}

static void hello_exit(void) {
	printk(KERN_INFO "Bye!!\n");
}


module_init(hello_init);
module_exit(hello_exit);
