#ifndef __DYN_ARRAY_H__
#define __DYN_ARRAY_H__

#include <stdlib.h>

#define CAPACITY_INIT 100

typedef struct {
  int key;
} Data;

typedef struct {
  unsigned int size;
  unsigned int capacity;
  Data *data;
} DynArray;

void dynArrayInit(DynArray *arr);
void doubleCapacity(DynArray *arr);
Data getElement(DynArray *arr, unsigned int index);
void setElement(DynArray *arr, int index, Data *data);
void dynArrayAppend(DynArray *arr, Data *data);
void dynArrayFree(DynArray *arr);

#endif