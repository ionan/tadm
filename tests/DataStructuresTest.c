#include <stdio.h>

#include "../data_structures/Array.h"
#include "../data_structures/LinkedList.h"
#include "../data_structures/Stack.h"
#include "../data_structures/Queue.h"
#include "../data_structures/Dictionary.h"
#include "../data_structures/BinaryTree.h"

/**************************************************************
 * 						Utils
 **************************************************************/

void destroy_int(void *elem){
	int * val = (int *) elem;
	printf("Destroyed %d element\n",*val);
}

void toString_int(void *elem){
	int * val = (int *) elem;
	printf("%d", *val);
}

int compare_int(void *elem1, void *elem2){
	return *(int *)(elem2) - *(int *)(elem1);
}

/**************************************************************
 * 					Binary tree test
 **************************************************************/
void BinaryTreeTest(){
	BinaryTree *a;

	init_BinaryTree(&a,destroy_int,toString_int, compare_int);

	int elem1 = 54;
	int elem2 = 12;
	int elem3 = 87;
	int elem4 = 2;
	int elem5 = 445;
	int elem6 = 1;
	int elem7 = 32;
	int elem8 = 9;
	int elem9 = 48;
	int elem10 = 21;
	int elem11 = 73;
	int elem12 = 56;
	int elem13 = 72;
	int elem14 = 48;
	int elem15 = 7;
	int elem16 = 3;

	insert_BinaryTree(a,(void *)&elem1);
	insert_BinaryTree(a,(void *)&elem2);
	insert_BinaryTree(a,(void *)&elem3);
	insert_BinaryTree(a,(void *)&elem4);
	insert_BinaryTree(a,(void *)&elem5);
	insert_BinaryTree(a,(void *)&elem6);

	toString_BinaryTree(a);

	int exists = exists_BinaryTree(a,&elem13);
	printf("Exists %d => %d\n",elem13,exists);

	insert_BinaryTree(a,(void *)&elem7);
	insert_BinaryTree(a,(void *)&elem8);
	insert_BinaryTree(a,(void *)&elem9);
	insert_BinaryTree(a,(void *)&elem10);
	insert_BinaryTree(a,(void *)&elem11);
	insert_BinaryTree(a,(void *)&elem12);

	toString_BinaryTree(a);

	insert_BinaryTree(a,(void *)&elem13);
	insert_BinaryTree(a,(void *)&elem14);
	insert_BinaryTree(a,(void *)&elem15);
	insert_BinaryTree(a,(void *)&elem16);

	toString_BinaryTree(a);

	exists = exists_BinaryTree(a,&elem13);
	printf("Exists %d => %d\n",elem13,exists);

	void *max = getMaximum_BinaryTree(a);
	if (max != NULL) {
		int *m = (int *) max;
		printf("Maximum value is %d\n",*m);
	}

	void *min = getMinimum_BinaryTree(a);
	if (min != NULL) {
		int *m = (int *) min;
		printf("Minimum value is %d\n",*m);
	}

	/*printf("Removing %d\n",elem16);
	remove_BinaryTree(a,&elem16);
	toString_BinaryTree(a);

	printf("Removing %d\n",elem8);
	remove_BinaryTree(a,&elem8);
	toString_BinaryTree(a);

	printf("Removing %d\n",elem12);
	remove_BinaryTree(a,&elem12);
	toString_BinaryTree(a);*/

	printf("Removing %d\n",elem1);
	remove_BinaryTree(a,&elem1);
	toString_BinaryTree(a);

	destroy_BinaryTree(a);
}

/**************************************************************
 * 					Dictionary test
 **************************************************************/
void DictionaryTest(){
	Dictionary *a;

	init_Dictionary(&a,destroy_int,toString_int);

	int elem1 = 54;
	int elem2 = 12;
	int elem3 = 87;
	int elem4 = 2;
	int elem5 = 445;
	int elem6 = 1;

	put_Dictionary(a,"One",(void *)&elem1);
	put_Dictionary(a,"Two",(void *)&elem2);
	put_Dictionary(a,"Three",(void *)&elem3);
	put_Dictionary(a,"Four",(void *)&elem4);
	put_Dictionary(a,"Five",(void *)&elem5);
	put_Dictionary(a,"Six",(void *)&elem6);

	toString_Dictionary(a);

	int* el= (int *)get_Dictionary(a,"Two");
	printf("Two => %d\n", *el);

	put_Dictionary(a,"Two",(void *)&elem6);
	el= (int *)get_Dictionary(a,"Two");
	printf("Two => %d\n", *el);

	toString_Dictionary(a);

	destroy_Dictionary(a);
}

/**************************************************************
 * 					Queue test
 **************************************************************/
void QueueTest(){
	Queue *a;

	init_Queue(&a,destroy_int,toString_int);

	int elem1 = 54;
	int elem2 = 12;
	int elem3 = 87;
	int elem4 = 2;
	int elem5 = 445;
	int elem6 = 1;
	int elem7 = 32;
	int elem8 = 9;
	int elem9 = 48;
	int elem10 = 21;
	int elem11 = 73;
	int elem12 = 56;
	int elem13 = 72;
	int elem14 = 48;
	int elem15 = 7;
	int elem16 = 3;

	enqueue_Queue(a, (void *)&elem1);
	enqueue_Queue(a, (void *)&elem2);
	enqueue_Queue(a, (void *)&elem3);
	enqueue_Queue(a, (void *)&elem4);
	enqueue_Queue(a, (void *)&elem5);
	enqueue_Queue(a, (void *)&elem6);
	enqueue_Queue(a, (void *)&elem7);
	enqueue_Queue(a, (void *)&elem8);
	enqueue_Queue(a, (void *)&elem9);
	enqueue_Queue(a, (void *)&elem10);
	enqueue_Queue(a, (void *)&elem11);
	enqueue_Queue(a, (void *)&elem12);
	enqueue_Queue(a, (void *)&elem13);
	enqueue_Queue(a, (void *)&elem14);

	toString_Queue(a);

	enqueue_Queue(a, (void *)&elem15);
	enqueue_Queue(a, (void *)&elem16);

	toString_Queue(a);

	int* el= (int *)dequeue_Queue(a);
	printf("Top element is: %d\n", *el);

	toString_Queue(a);

	destroy_Queue(a);
}

/**************************************************************
 * 					Stack test
 **************************************************************/
void StackTest(){
	Stack *a;

	init_Stack(&a,destroy_int,toString_int);

	int elem1 = 54;
	int elem2 = 12;
	int elem3 = 87;
	int elem4 = 2;
	int elem5 = 445;
	int elem6 = 1;
	int elem7 = 32;
	int elem8 = 9;
	int elem9 = 48;
	int elem10 = 21;
	int elem11 = 73;
	int elem12 = 56;
	int elem13 = 72;
	int elem14 = 48;
	int elem15 = 7;
	int elem16 = 3;

	push_Stack(a, (void *)&elem1);
	push_Stack(a, (void *)&elem2);
	push_Stack(a, (void *)&elem3);
	push_Stack(a, (void *)&elem4);
	push_Stack(a, (void *)&elem5);
	push_Stack(a, (void *)&elem6);
	push_Stack(a, (void *)&elem7);
	push_Stack(a, (void *)&elem8);
	push_Stack(a, (void *)&elem9);
	push_Stack(a, (void *)&elem10);
	push_Stack(a, (void *)&elem11);
	push_Stack(a, (void *)&elem12);
	push_Stack(a, (void *)&elem13);
	push_Stack(a, (void *)&elem14);
	push_Stack(a, (void *)&elem15);
	push_Stack(a, (void *)&elem16);

	toString_Stack(a);

	int* el= (int *)pop_Stack(a);
	printf("Top element is: %d\n", *el);

	toString_Stack(a);

	el= (int *)peek_Stack(a);
	printf("Top element is: %d\n", *el);

	toString_Stack(a);

	destroy_Stack(a);
}

/**************************************************************
 * 					LinkedList test
 **************************************************************/
void LinkedListTest(){
	LinkedList *a;

	init_LinkedList(&a,destroy_int,toString_int);

	int elem1 = 54;
	int elem2 = 12;
	int elem3 = 87;
	int elem4 = 2;
	int elem5 = 445;
	int elem6 = 1;
	int elem7 = 32;
	int elem8 = 9;
	int elem9 = 48;
	int elem10 = 21;
	int elem11 = 73;
	int elem12 = 56;
	int elem13 = 72;
	int elem14 = 48;
	int elem15 = 7;
	int elem16 = 3;

	add_LinkedList(a, (void *)&elem1);
	add_LinkedList(a, (void *)&elem2);
	add_LinkedList(a, (void *)&elem3);
	add_LinkedList(a, (void *)&elem4);
	add_LinkedList(a, (void *)&elem5);
	add_LinkedList(a, (void *)&elem6);
	add_LinkedList(a, (void *)&elem7);
	add_LinkedList(a, (void *)&elem8);
	add_LinkedList(a, (void *)&elem9);
	add_LinkedList(a, (void *)&elem10);
	add_LinkedList(a, (void *)&elem11);
	add_LinkedList(a, (void *)&elem12);
	add_LinkedList(a, (void *)&elem13);
	add_LinkedList(a, (void *)&elem14);
	add_LinkedList(a, (void *)&elem15);
	add_LinkedList(a, (void *)&elem16);

	int* el9 = (int *)get_LinkedList(a,9);
	printf("Ninth element is: %d\n", *el9);

	printf("Array size is: %d\n", size_LinkedList(a));

	toString_LinkedList(a);

	printf("Array size is: %d\n", size_LinkedList(a));

	remove_LinkedList(a,5);
	printf("Removed 6th element\n");

	toString_LinkedList(a);

	remove_LinkedList(a,0);
	printf("Removed first element\n");

	toString_LinkedList(a);

	remove_LinkedList(a,13);
	printf("Removed last element\n");

	toString_LinkedList(a);

	destroy_LinkedList(a);
}

/**************************************************************
 * 					Array test
 **************************************************************/
void ArrayTest(){
	Array *a;

	init_Array(&a,destroy_int,toString_int);

	int elem1 = 54;
	int elem2 = 12;
	int elem3 = 87;
	int elem4 = 2;
	int elem5 = 445;
	int elem6 = 1;
	int elem7 = 32;
	int elem8 = 9;
	int elem9 = 48;
	int elem10 = 21;
	int elem11 = 73;
	int elem12 = 56;
	int elem13 = 72;
	int elem14 = 48;
	int elem15 = 7;
	int elem16 = 3;

	add_Array(a, (void *)&elem1);
	add_Array(a, (void *)&elem2);
	add_Array(a, (void *)&elem3);
	add_Array(a, (void *)&elem4);
	add_Array(a, (void *)&elem5);
	add_Array(a, (void *)&elem6);
	add_Array(a, (void *)&elem7);
	add_Array(a, (void *)&elem8);
	add_Array(a, (void *)&elem9);
	add_Array(a, (void *)&elem10);
	add_Array(a, (void *)&elem11);
	add_Array(a, (void *)&elem12);
	add_Array(a, (void *)&elem13);
	add_Array(a, (void *)&elem14);
	add_Array(a, (void *)&elem15);
	add_Array(a, (void *)&elem16);

	int* el9 = (int *)get_Array(a,9);
	printf("Ninth element is: %d\n", *el9);

	printf("Array size is: %d\n", size_Array(a));

	toString_Array(a);

	remove_Array(a,5);
	printf("Removed 6th element\n");

	toString_Array(a);

	remove_Array(a,0);
	printf("Removed first element\n");

	toString_Array(a);

	remove_Array(a,13);
	printf("Removed last element\n");

	toString_Array(a);

	destroy_Array(a);
}
