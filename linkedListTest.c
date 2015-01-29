#include "expr_assert.h"
#include "linkedList.h"
#include <stdio.h>
int data =10,data1=20;
Node n1 ; 
LinkedList l1,l2;
void setup(){
	n1=(Node){&data,NULL};
	l1=(LinkedList){&n1,&n1,1};
	l2=(LinkedList){NULL,NULL,0};
}
void test_creatLinkList_has_head_tail_and_count_initialized_to_NULL(){
	LinkedList list =createList();
	assert(list.head==NULL);
	assert(list.tail== NULL);
	assertEqual(list.count, 0);
}
void test_creat_node_contains_given_data(){
	Node* node =create_node(&data);
	assert(node->data==&data);
}
void test_add_to_List_adds_node_at_the_end_of_list(){
	add_to_list(&l1,create_node(&data1));	
	assertEqual(*(int*)(l1.tail->data),20);
}

void test_add_to_List_for_empty_list_sets_node_as_head(){
	add_to_list(&l2,create_node(&data1));
	assert((l2.head->data)==&data1);	
	assertEqual(*(int*)(l2.head->data),20);
}

void test_add_to_List_incress_count(){
	add_to_list(&l1,create_node(&data1));
	assertEqual((l1.count),2);
}
void test_tail_points_to_last_added_element(){
	add_to_list(&l1,create_node(&data1));
	assert((l1.tail->data)==&data1);	

}
void test_getFirstElement_in_list(){
	int * d = (int *)get_first_element(l1);
	assertEqual(*d, 10);	
}
void test_getlastElement_in_list(){
	int *d;
	add_to_list(&l1,create_node(&data1));

	d = (int *)get_last_element(l1);
	assertEqual(*d, 20);	
}