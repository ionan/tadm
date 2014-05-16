#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct LinkedListElem {
   void *data;
   struct LinkedListElem *next;
} LinkedListElem;

typedef struct {
	void (* destroy)(void *data);
	void (* toString)(void *data);
	struct LinkedListElem *head;
	struct LinkedListElem *tail;
	int size;
} LinkedList;

void init_LinkedList(LinkedList **linkedList, void (* destroy)(void *data), void (* toString)(void *data));

void add_LinkedList(LinkedList *array, void *data);

int size_LinkedList(LinkedList *linkedList);

void clear_LinkedList(LinkedList *linkedList);

void destroy_LinkedList(LinkedList *linkedList);

void* get_LinkedList(LinkedList *linkedList, int index);

void insert_LinkedList(LinkedList *linkedList, int index, void *data);

void remove_LinkedList(LinkedList *linkedList, int index);

void toString_LinkedList(LinkedList *linkedList);

#endif /* LINKEDLIST_H_ */
