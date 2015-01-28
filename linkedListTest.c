#include "expr_assert.h"
#include "linkedList.h"
#include <stdio.h>
int data =10;
Node n1 ; 
LinkedList l1,l2;
void setup(){
	n1=(Node){&data,NULL};
	l1=(LinkedList){&n1,&n1,1};
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
	int data1 =15;
	add_to_list(&l1,create_node(&data1));	
	assertEqual(*(int*)(l1.tail->data),15);
}

void test_add_to_List_for_empty_list_sets_node_as_head(){
	int data1 =20;
	add_to_list(&l2,create_node(&data1));
	assert((l2.head->data)==&data1);	
	assertEqual(*(int*)(l2.head->data),20);
}