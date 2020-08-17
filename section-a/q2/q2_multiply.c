#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>


static int multiplication(int numone, int numtwo) {
		return numone*numtwo;
}
extern int multiplication(int numone, int numtwo);