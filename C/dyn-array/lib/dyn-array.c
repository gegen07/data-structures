#include "dyn-array.h"

void dynArrayInit(DynArray *arr, void (*freeObject)(void *)) {
  arr->size = 0;
  arr->capacity = CAPACITY_INIT;
  arr->data = (Data*) malloc(arr->capacity * sizeof(Data));
  arr->freeObject = freeObject;
}

void doubleCapacity(DynArray *arr) {
  if (arr->size >= arr->capacity) {
    arr->capacity *= 2;
    arr->data = realloc(arr->data, arr->capacity * sizeof(Data));
  }
}

Data getElement(DynArray *arr, unsigned int index) {
  if (index >= arr->size || index < 0) {
    exit(1);
  }
  
  return arr->data[index];
}

void setElement(DynArray *arr, int index, Data *data) {
  if (index >= arr->size || index < 0) {
    exit(1);
  }

  arr->data[index] = *data;
}
void dynArrayAppend(DynArray *arr, Data data) {
  doubleCapacity(arr);
  arr->data[arr->size++] = data;
}

void dynArrayFree(DynArray *arr) {
  int i;
  free(arr->data);
}

char *toString(DynArray *arr) {
  char *print = (char*) malloc(sizeof(arr->data) + STRING_MAX);

  int i;
  for (i = 0; i < arr->size; i++) {
    strcat(print, arr->data[i].toString(getKey(&arr->data[i])));
  }

  return print;
}