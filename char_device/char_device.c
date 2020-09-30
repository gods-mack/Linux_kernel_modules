
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

#include <linux/fs.h>




ssize_t read_mydevice(struct file *pfile, char __user *buffer, size_t length, loff_t *offset) {
	printk(KERN_INFO "we are inside %s func \n",__FUNCTION__);

	return 0;

}

ssize_t write_mydevice(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset) {

	printk(KERN_INFO "we are inside %s func \n",__FUNCTION__);
	return length;

}

int open_mydevice(struct inode *pinode, struct file *pfile) {
	printk(KERN_INFO "we are inside %s func \n",__FUNCTION__);
	return 0;

}


int release_mydevice(struct inode *pinode, struct file *pfile) {
	printk(KERN_INFO "we are inside %s func \n",__FUNCTION__);
	return 0;
}

struct file_operations mydevice_file_operations =  {
	.owner   = THIS_MODULE,
	.read    = read_mydevice,
	.write   = write_mydevice,
	.open    = open_mydevice,
	.release = release_mydevice, 

};	
	
static int device_init(void) {
	
	
	/* register_chrdev(major_number, name_of_device, file_operations) */
	register_chrdev(230, "mydevice_dvr", &mydevice_file_operations);

	return 0;
}

static void device_exit(void) {
	printk(KERN_INFO "Goodbye!!\n");

	unregister_chrdev(230, "mydevice_dvr");
}

module_init(device_init);
module_exit(device_exit);

MODULE_AUTHOR("Manish");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("my first char device dvr");

// to add device "sudo mknod /dev/mydevice_dvr c 230 0"
// 230 major number
// 0 minor number



