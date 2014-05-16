#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#include "Dictionary.h"

int getHash(char *key, int modulo);

void init_Dictionary(Dictionary **dict, void (* destroy)(void *data), void (* toString)(void *data)){
	*dict = (Dictionary*) malloc (sizeof(Dictionary));
	(*dict)->destroy = destroy;
	(*dict)->toString = toString;
	(*dict)->size = 0;
	(*dict)->buckets = 8;
	int i;
	for (i = 0; i < 8; i++) (*dict)->arr[i] = NULL;
}

void put_Dictionary(Dictionary *dict, char *key, void *data){
	int index = getHash(key,dict->buckets);
	DictionaryElem *init = dict->arr[index];
	if (init == NULL){
		DictionaryElem *elem = (DictionaryElem *) malloc (sizeof(DictionaryElem));
		elem->data = data;
		elem->key = key;
		elem->next = NULL;
		dict->arr[index] = elem;
	} else {
		DictionaryElem *_elem = init;
		while (init != NULL){
			if (strcmp(key, init->key) == 0){
				init->data = data;
				break;
			}
			_elem = init;
			init = init->next;
		}
		if (init == NULL){
			DictionaryElem *elem = (DictionaryElem *) malloc (sizeof(DictionaryElem));
			elem->data = data;
			elem->key = key;
			elem->next = NULL;
			_elem->next = elem;
			dict->size++;
		}
	}
}

int size_Dictionary(Dictionary *dict){
	return dict->size;
}

void clear_Dictionary(Dictionary *dict){
	int i;
	for (i = 0; i < dict->buckets; i++){
		DictionaryElem *elem = dict->arr[i];
		while(elem != NULL){
			dict->destroy(elem->data);
			DictionaryElem *temp = elem->next;
			elem->next = NULL;
			elem = temp;
		}
		dict->arr[i] = NULL;
	}
	dict->size = 0;
}

void destroy_Dictionary(Dictionary *dict){
	int i;
	for (i = 0; i < dict->buckets; i++){
		DictionaryElem *elem = dict->arr[i];
		while(elem != NULL){
			dict->destroy(elem->data);
			DictionaryElem *temp = elem->next;
			elem->next = NULL;
			elem = temp;
		}
		dict->arr[i] = NULL;
	}
	free(dict->arr);
	free(dict);
}

void* get_Dictionary(Dictionary *dict, char *key){
	int index = getHash(key,dict->buckets);
	DictionaryElem *init = dict->arr[index];
	while (init != NULL){
		if (strcmp(key, init->key) == 0) return init->data;
		init = init->next;
	}
	return NULL;
}

void remove_Dictionary(Dictionary *dict, char *key){
	int index = getHash(key,dict->buckets);
	DictionaryElem *init = dict->arr[index];
	if (init != NULL && strcmp(key, init->key) == 0){
		dict->destroy(init->data);
		dict->arr[index]->next = init->next;
		return;
	}
	DictionaryElem *prev = init;
	init = init->next;
	while (init != NULL){
		if (strcmp(key, init->key) == 0){
			dict->destroy(init->data);
			prev->next = init->next;
			break;
		}
		prev = init;
		init = init->next;
	}
}

void toString_Dictionary(Dictionary *dict){
	int i;
	for (i = 0; i < dict->buckets; i++){
		printf("Bucket %d: ",i);
		DictionaryElem *elem = dict->arr[i];
		while(elem != NULL){
			printf("%s => ",elem->key);
			dict->toString(elem->data);
			elem = elem->next;
			if (elem != NULL) printf(", ");
		}
		printf("\n");
	}
	printf("\n");
}

int getHash(char *key, int modulo){
	int val = 0;
	char *c = key;
	while (c[0] != 	EOF){
		val = val + (int) c[0];
		c++;
	}
	return val % modulo;
}
