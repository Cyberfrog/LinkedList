#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
LinkedList createList(){
	LinkedList list;
	list.head=NULL;
	list.tail=NULL;
	list.count =0;
	return list;
}
Node* create_node(void* data){
	Node* node = (Node *)malloc(sizeof(node));
	node->data = data;
	node->next = NULL;
	return node;
}
int add_to_list(LinkedList* list,Node* node){
	if(!list->head){
		list->head=node;
	}
	else{
		list->tail->next = node;
	}
	list->tail = node;
	return 1;
}
