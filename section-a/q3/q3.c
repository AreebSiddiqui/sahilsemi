#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h>

struct House {
	int area;
	char color[20];
	struct list_head list; /* kernel's list structure */
};
struct House *ahouse; /* loop counter */

static LIST_HEAD(houselist);

void print_node(struct House *house) {
	printk(KERN_ALERT "area is %d cm^2 & color is %s", house->area, house->color);
}

void add_in_list(struct House *house, int param_area, char *param_color) {
	
	house->area = param_area;
	strcpy(house->color, param_color);
	INIT_LIST_HEAD(&house->list);
    list_add(&house->list, &houselist);
	// print_node(house);
}


//Starting Module
static int __init start(void) {
	
	struct House *house_1 = kzalloc(sizeof(struct House), GFP_KERNEL);
	add_in_list(house_1, 1, "red"); 

	struct House *house_2 = kzalloc(sizeof(struct House), GFP_KERNEL);
	add_in_list(house_2, 2, "blue");

	struct House *house_3 = kzalloc(sizeof(struct House), GFP_KERNEL);
	add_in_list(house_3, 3, "green");

	struct House *house_4 = kzalloc(sizeof(struct House), GFP_KERNEL);
	add_in_list(house_4, 4, "red");

	int blue_car_num = 0;
	/* 'list' is the name of the list_head struct in our data structure */
	list_for_each_entry(ahouse, &houselist, list){
	if(ahouse == 3)
	blue_car_num++;
	}
	printk(KERN_ALERT "%d", blue_car_num);
	
	return 0;
}


void __exit q3_exit(void) {
	printk(KERN_ALERT "exited q3");
}

module_init(start);
module_exit(q3_exit);







