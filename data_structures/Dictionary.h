#ifndef DICTIONARY_H_
#define DICTIONARY_H_

typedef struct DictionaryElem {
	char *key;
	void *data;
	struct DictionaryElem *next;
} DictionaryElem;

typedef struct {
	void (* destroy)(void *data);
	void (* toString)(void *data);
	struct DictionaryElem *arr[8];
	int size;
	int buckets;
} Dictionary;

void init_Dictionary(Dictionary **dict, void (* destroy)(void *data), void (* toString)(void *data));

void put_Dictionary(Dictionary *dict, char *key, void *data);

void clear_Dictionary(Dictionary *dict);

void destroy_Dictionary(Dictionary *dict);

void* get_Dictionary(Dictionary *dict, char *key);

void remove_Dictionary(Dictionary *dict, char *key);

void toString_Dictionary(Dictionary *dict);

#endif /* DICTIONARY_H_ */
