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
	list->count++;
	return 1;
}
void *get_first_element(LinkedList list){
	return list.head->data;
}
void *get_last_element(LinkedList list){
	return list.tail->data;
}
void traverse(LinkedList list, Oprate * oprate){
	Node * walker = list.head;
	while(walker!=NULL){
		oprate(walker->data);
		walker = walker->next;
	}
}

void * getElementAt(LinkedList list, int index){
	int i;
	Node* n =list.head;
	if(index>=list.count){
		return NULL;
	} 
	for(i=0;i<index;i++){
		n=n->next;
	}
	return n->data;
}
