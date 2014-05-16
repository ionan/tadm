/*
 * Stack.c
 *
 *  Created on: 12/04/2014
 *      Author: Ion Ander Gurrutxaga
 */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "Stack.h"

void init_Stack(Stack **stack, void (* destroy)(void *data), void (* toString)(void *data)) {
	*stack = (Stack*) malloc (sizeof(Stack));
	(*stack)->top = NULL;
	(*stack)->size = 0;
	(*stack)->destroy = destroy;
	(*stack)->toString = toString;
}

void push_Stack(Stack *stack, void *data){
	StackElem *elem = (StackElem*) malloc (sizeof(StackElem));
	elem->data = data;
	elem->prev = stack->top;
	stack->top = elem;
	stack->size++;
}

void* pop_Stack(Stack *stack){
	if (stack->size == 0) return NULL;
	StackElem *top = stack->top;
	stack->top = top->prev;
	stack->size--;
	return top->data;
}

void* peek_Stack(Stack *stack){
	if (stack->size == 0) return NULL;
	return stack->top->data;
}

int size_Stack(Stack *stack){
	return stack->size;
}

void clear_Stack(Stack *stack){
	StackElem *elem = stack->top;
	while(elem != NULL){
		stack->destroy(elem->data);
		StackElem *temp = elem->prev;
		elem->prev = NULL;
		elem = temp;
	}
	stack->top = NULL;
	stack->size = 0;
}

void destroy_Stack(Stack *stack){
	StackElem *elem = stack->top;
	while(elem != NULL){
		stack->destroy(elem->data);
		StackElem *temp = elem->prev;
		elem->prev = NULL;
		elem = temp;
	}
	free(stack);
}

void toString_Stack(Stack *stack){
	printf("----------------------------------\n");
	StackElem *elem = stack->top;
	while(elem != NULL){
		stack->toString(elem->data);
		elem = elem->prev;
		printf("\n");
	}
	printf("----------------------------------\n");
}
