#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "Queue.h"

void init_Queue(Queue **queue, void (* destroy)(void *data), void (* toString)(void *data)) {
	*queue = (Queue*) malloc (sizeof(Queue));
	(*queue)->head = NULL;
	(*queue)->tail = NULL;
	(*queue)->size = 0;
	(*queue)->destroy = destroy;
	(*queue)->toString = toString;
}

void enqueue_Queue(Queue *queue, void *data){
	QueueElem *elem = (QueueElem *) malloc (sizeof(QueueElem));
	elem->data = data;
	elem->next = NULL;

	if (queue->size > 0){
		queue->tail->next = elem;
	} else {
		queue->head = elem;
	}
	queue->tail = elem;
	queue->size++;
}

int size_Queue(Queue *queue){
	return queue->size;
}

void clear_Queue(Queue *queue){
	QueueElem *elem = queue->head;
	while(elem != NULL){
		queue->destroy(elem->data);
		QueueElem *temp = elem->next;
		elem->next = NULL;
		elem = temp;
	}
	queue->head = NULL;
	queue->tail = NULL;
	queue->size = 0;
}

void destroy_Queue(Queue *queue){
	QueueElem *elem = queue->head;
	while(elem != NULL){
		queue->destroy(elem->data);
		QueueElem *temp = elem->next;
		elem->next = NULL;
		elem = temp;
	}
	free(queue);
}

void* dequeue_Queue(Queue *queue){
	if (size_Queue(queue) == 0) return NULL;
	QueueElem *head = queue->head;
	queue->head = head->next;
	if (head->next == NULL) queue->tail = NULL;
	queue->size--;
	return head->data;
}

void toString_Queue(Queue *queue){
	QueueElem *elem = queue->head;
	printf("<-- ");
	while(elem != NULL){
		queue->toString(elem->data);
		if (elem->next != NULL) printf(",");
		elem = elem->next;
	}
	printf(" --|\n");
}
