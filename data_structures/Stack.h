/*
 * Stack.h
 *
 *  Created on: 12/04/2014
 *      Author: root
 */

#ifndef STACK_H_
#define STACK_H_

typedef struct StackElem {
	void *data;
	struct StackElem *prev;
} StackElem;

typedef struct {
	void (* destroy)(void *data);
	void (* toString)(void *data);
	struct StackElem *top;
	int size;
} Stack;

void init_Stack(Stack **stack, void (* destroy)(void *data), void (* toString)(void *data));

void push_Stack(Stack *stack, void *data);

void* pop_Stack(Stack *stack);

void* peek_Stack(Stack *stack);

int size_Stack(Stack *stack);

void clear_Stack(Stack *stack);

void destroy_Stack(Stack *stack);

void toString_Stack(Stack *stack);

#endif /* STACK_H_ */
