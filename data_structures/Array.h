#ifndef ARRAY_H_
#define ARRAY_H_

typedef struct {
   void **data;
   void (* destroy)(void *data);
   void (* toString)(void *data);
   size_t allocated;
   size_t used;
   int index;
} Array;

void init_Array(Array **array, void (* destroy)(void *data), void (* toString)(void *data));

void add_Array(Array *array, void *data);

int size_Array(Array *array);

void clear_Array(Array *array);

void destroy_Array(Array *array);

void* get_Array(Array *array, int index);

void insert_Array(Array *array, int index, void *data);

void remove_Array(Array *array, int index);

void toString_Array(Array *array);

#endif /* ARRAY_H_ */
