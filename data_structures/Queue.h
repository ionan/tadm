#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct QueueElem {
   void *data;
   struct QueueElem *next;
} QueueElem;

typedef struct {
	void (* destroy)(void *data);
	void (* toString)(void *data);
	struct QueueElem *head;
	struct QueueElem *tail;
	int size;
} Queue;

void init_Queue(Queue **queue, void (* destroy)(void *data), void (* toString)(void *data));

void enqueue_Queue(Queue *queue, void *data);

int size_Queue(Queue *queue);

void clear_Queue(Queue *queue);

void destroy_Queue(Queue *queue);

void* dequeue_Queue(Queue *queue);

void toString_Queue(Queue *queue);

#endif /* QUEUE_H_ */
