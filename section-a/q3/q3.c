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
	printk(KERN_ALERT "House color is %s & area is %d", house->color, house->area);
}

void add_in_list(struct House *house, int param_area, char *param_color) {	
	house->area = param_area;
	strcpy(house->color, param_color);
	INIT_LIST_HEAD(&house->list);
    list_add(&house->list, &houselist);
	// print_node(house);
}

void module_a_get_house5(int *val) {
	
	//For getting pointer to house_1
	struct House *houseptr;
	houseptr=container_of(val, struct House, area);

	//Initialize a counter
	int count = 10; 
	
	//set a pointer to house_1 address 
	// OR set a pointer to pointer which points to house one i.e houseptr)
	struct House *pointer = houseptr;
	
	//Traversing the list
	list_for_each_entry(pointer, &houselist, list){
	count--;
	// if (count == 4) 
	print_node(pointer);
}
}

int module_c_cal_all_area(int *val) {
	static int total_area=0;	
	//For getting pointer to house_1
	struct House *houseptr;
	houseptr=container_of(val, struct House, area);
	struct House *pointer = houseptr;

	list_for_each_entry(pointer, &houselist, list){
		total_area = total_area+pointer->area;
	}
	return total_area;
}

int module_d_insert_in_between(struct House *house, struct House *new_house) {
	INIT_LIST_HEAD(&new_house->list);
	list_add(&new_house->list , &house->list);

	new_house->area=11;
	strcpy(house->color, "blue");

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
	add_in_list(house_4, 4, "pink");

	struct House *house_5 = kzalloc(sizeof(struct House), GFP_KERNEL);
	add_in_list(house_5, 5, "purple");

	struct House *house_6 = kzalloc(sizeof(struct House), GFP_KERNEL);
	add_in_list(house_6, 6, "grey");

	struct House *house_7 = kzalloc(sizeof(struct House), GFP_KERNEL);
	add_in_list(house_7, 7, "cyan");

	struct House *house_8 = kzalloc(sizeof(struct House), GFP_KERNEL);
	add_in_list(house_8, 8, "yellow");

	struct House *house_9 = kzalloc(sizeof(struct House), GFP_KERNEL);
	add_in_list(house_9, 9, "orange");

	struct House *house_10 = kzalloc(sizeof(struct House), GFP_KERNEL);
	add_in_list(house_10, 10, "brown");

	struct House *house_11 = kzalloc(sizeof(struct House), GFP_KERNEL);
	// add_in_list(house_11, 11, "purp-grey");

//Function calling	// int *val = &house_1->area;//ref pg# 44
		// int result = module_c_cal_all_area(&house_1->area);
		// printk(KERN_ALERT "Total area is %d", result);
		// list_del(&house_8->list);
		module_d_insert_in_between(house_5,house_11);
		module_a_get_house5(&house_1->area);

	return 0;
}

void __exit q3_exit(void) {
	printk(KERN_ALERT "exited q3");
}

module_init(start);
module_exit(q3_exit);
