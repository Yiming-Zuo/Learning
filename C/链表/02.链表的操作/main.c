#include <stdio.h>
#include "linkedlist.h"

int main(int argc, char *argv[]) {
	struct LinkNode *p_header = init_linkedlist();
	
//	insert_node_right(p_header, 30, 35);
//	insert_node_left(p_header, 30, 25);
	
//	del_node(p_header, 30);
	
//	clear_ll(p_header);
//	foreach_linkedlist(p_header);
	
	destory_ll(p_header);
	
	return 0;
}