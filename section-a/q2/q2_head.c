#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>
#include "q2_multiply.c"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Muhammad Areeb Siddiqui");

static int numone = 420;
static int numtwo = 420;
static int result = 0;

module_param(numone, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(numone, "An integer");

module_param(numtwo, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(numtwo, "An integer");

//void
static int __init start(void)
{	
	result  = multiplication(numone,numtwo);
	printk(KERN_INFO "%d * %d : %d",numone,numtwo,result);
	return 0;
}


static void __exit q2_exit(void)
{
	printk(KERN_INFO "Finished \n");
}

module_init(start);
module_exit(q2_exit);
