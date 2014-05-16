#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Array.h"

void init_Array(Array **array, void (* destroy)(void *data), void (* toString)(void *data)) {
	*array = (Array*) malloc (sizeof(Array));
	(*array)->data = NULL;
	(*array)->destroy = destroy;
	(*array)->toString = toString;
	(*array)->allocated = 0;
	(*array)->used = 0;
	(*array)->index = -1;
}

void add_Array(Array *array, void *data){
	size_t toallocate;
	size_t dataSize = sizeof(void*);

	if ((array->allocated - array->used) < dataSize) {
		toallocate = array->allocated == 0 ? dataSize : (array->allocated * 2);
		array->data = realloc(array->data, toallocate);
		array->allocated = toallocate;
	}

	array->data[++array->index] = data;
	array->used = array->used + dataSize;
}

int size_Array(Array *array){
	return array->index + 1;
}

void clear_Array(Array *array){
	int i;
	for(i = 0; i < size_Array(array); i++){
		array->destroy(array->data[i]);
		array->data[i] = NULL;
	}
	array->used = 0;
	array->index = -1;
}

void destroy_Array(Array *array){
	int i;
	for(i = 0; i < size_Array(array); i++){
		array->destroy(array->data[i]);
	}
	free(array->data);
	free(array);
}

void* get_Array(Array *array, int index){
	return (index < 0 || index > array->index) ? NULL : array->data[index];
}

void insert_Array(Array *array, int index, void *data){
	if (index < 0 || index > array->index) return;
	array->data[index] = data;
}

void remove_Array(Array *array, int index){
	if (size_Array(array) < index) return;

	Array *a;
	init_Array(&a,array->destroy,array->toString);
	int i;
	for (i = 0; i < size_Array(array); i++){
		if (i != index) add_Array(a,array->data[i]);
	}
	*array = *a;
}

void toString_Array(Array *array){
	printf("[");
	int i;
	for(i = 0; i < size_Array(array); i++){
		array->toString(array->data[i]);
		if (i < size_Array(array)-1) printf(",");
	}
	printf("]\n");
}
