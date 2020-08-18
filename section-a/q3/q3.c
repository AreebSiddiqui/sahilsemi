#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h>

struct House {
	int area;
	char color[20];
	struct list_head list; /* kernel's list structure */
};

//Starting Module
static int __init start(void) {

	static LIST_HEAD(houselist);
	struct House *house_1 = kzalloc(sizeof(struct House), GFP_KERNEL);
	house_1->area = 1;
	strcpy(house_1->color, "red");
	INIT_LIST_HEAD(&house_1->list);
    list_add(&house_1->list, &houselist);
	
	return 0;
}

void __exit q3_exit(void) {
	printk(KERN_ALERT "exited q3");
}

module_init(start);
module_exit(q3_exit);







