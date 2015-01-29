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

int indexOf(LinkedList list, void* data){
	int index=0;
	Node* walker = list.head;  
	while(walker!=NULL){
		if(walker->data == data){
			return index;
		}
		index++;
		walker = walker->next;
	}
	return -1;
}
void * deleteElementAt(LinkedList *list, int index){
	int i;
	void* data;
	Node* n =list->head;
	Node* prev=NULL;
	
	if(index>=list->count||index<0){
		return NULL;
	} 

	for(i=0;i<index;i++){
		prev = n;
		n=n->next;
	}
	
	if(list->tail==n){
		list->tail=prev;
	}

	data= n->data;
	prev?(prev->next =n->next):(list->head =list->head->next);
	

	list->count--;
	free(n);
	return data;
}
