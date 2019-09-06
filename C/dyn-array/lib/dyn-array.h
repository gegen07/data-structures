#ifndef __DYN_ARRAY_H__
#define __DYN_ARRAY_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

#define CAPACITY_INIT 100
typedef struct {
  unsigned int size;
  unsigned int capacity;
  Data *data;
  void (*freeObject)(void *);
} DynArray;

void dynArrayInit(DynArray *arr, void (*freeObject)(void *));
void doubleCapacity(DynArray *arr);
Data getElement(DynArray *arr, unsigned int index);
void setElement(DynArray *arr, int index, Data *data);
void dynArrayAppend(DynArray *arr, Data data);
void dynArrayFree(DynArray *arr);
char *toString(DynArray *arr);

#endif