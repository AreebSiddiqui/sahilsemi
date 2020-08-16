#include<linux/kernel.h>
#include<linux/module.h>

int init_module(void) {
    printk(KERN_INFO "Hello world 1. \n");
    return 0;
}
void cleanup_module() {
    printk(KERN_INFO "Good Bye! 1. \n");
}
