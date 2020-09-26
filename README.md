# Linux_kernel_modules
Basic Linux kernel modules/Drivers


-> to run or load 

```make```

```sudo insmod module_name.ko```

```dmesg```

to remove or unloading module ```sudo rmmod module_name```



// insmod is kernel utility which helps to load kernel module into 
// kernel code.

// insmod stands for "insert_module"

// lsmod command will list the current modules loaded in kernel

// rmmod utility command will unload the loadable module.
// module fails to unload if the kernel belives that the module is still in use.
// e.g rmmod helloM


// modprobe is also a kernel utility which helps to load kernel module into kernel code.

