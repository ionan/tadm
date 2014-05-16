#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "LinkedList.h"

void init_LinkedList(LinkedList **linkedList, void (* destroy)(void *data), void (* toString)(void *data)) {
	*linkedList = (LinkedList*) malloc (sizeof(LinkedList));
	(*linkedList)->head = NULL;
	(*linkedList)->tail = NULL;
	(*linkedList)->size = 0;
	(*linkedList)->destroy = destroy;
	(*linkedList)->toString = toString;
}

void add_LinkedList(LinkedList *linkedList, void *data){
	LinkedListElem *elem = (LinkedListElem *) malloc (sizeof(LinkedListElem));
	elem->data = data;
	elem->next = NULL;

	if (linkedList->size > 0){
		linkedList->tail->next = elem;
	} else {
		linkedList->head = elem;
	}
	linkedList->tail = elem;
	linkedList->size++;
}

int size_LinkedList(LinkedList *linkedList){
	return linkedList->size;
}

void clear_LinkedList(LinkedList *linkedList){
	LinkedListElem *elem = linkedList->head;
	while(elem != NULL){
		linkedList->destroy(elem->data);
		LinkedListElem *temp = elem->next;
		elem->next = NULL;
		elem = temp;
	}
	linkedList->head = NULL;
	linkedList->tail = NULL;
	linkedList->size = 0;
}

void destroy_LinkedList(LinkedList *linkedList){
	LinkedListElem *elem = linkedList->head;
	while(elem != NULL){
		linkedList->destroy(elem->data);
		LinkedListElem *temp = elem->next;
		elem->next = NULL;
		elem = temp;
	}
	free(linkedList);
}

void* get_LinkedList(LinkedList *linkedList, int index){
	if (size_LinkedList(linkedList) < index) return NULL;
	LinkedListElem *elem = linkedList->head;
	int i;
	for (i = 0; i < index; i++){
		elem = elem->next;
	}
	return elem->data;
}

void insert_LinkedList(LinkedList *linkedList, int index, void *data){
	if (size_LinkedList(linkedList) < index) return;
	LinkedListElem *elem = linkedList->head;
	int i;
	for (i = 0; i < index; i++){
		elem = elem->next;
	}
	linkedList->destroy(elem->data);
	elem->data = data;
}

void remove_LinkedList(LinkedList *linkedList, int index){
	int size = size_LinkedList(linkedList);
	if (size < index) return;
	if (index == 0) {
		linkedList->head = linkedList->head->next;
		return;
	}
	LinkedListElem *elem = linkedList->head->next, *prev = linkedList->head;
	int i;
	for (i = 0; i < index-1; i++){
		prev = elem;
		elem = elem->next;
	}
	linkedList->destroy(elem->data);
	prev->next = elem->next;
}

void toString_LinkedList(LinkedList *linkedList){
	LinkedListElem *elem = linkedList->head;
	while(elem != NULL){
		printf("{");
		linkedList->toString(elem->data);
		printf("}");
		if (elem->next != NULL) printf("->");
		elem = elem->next;
	}
	printf("\n");
}
