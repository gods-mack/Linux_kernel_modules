#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>

static int hello_init(void){
   printk(KERN_ALERT "Hello Manish; it's your first driver which does nothing:/\n");
   return 0;
}

static void hello_exit(void){
   printk(KERN_INFO "Goodbye Manish; No point in keeping this driver running.\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("Manish");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Manish's first driver with GPL licence.");



// to run it
// 0. switch to root by "sudo -i"
// 1. make
// 2. insmod helloM.ko


// insmod is kernel utility which helps to load kernel module into 
// kernel code.

// insmod stands for "insert_module"

// lsmod command will list the current modules loaded in kernel

// rmmod utility command will unload the loadable module.
// module fails to unload if the kernel belives that the module is still in use.
// e.g rmmod helloM


// modprobe is also a kernel utility which helps to load kernel module into kernel code.

