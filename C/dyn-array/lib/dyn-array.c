#include "dyn-array.h"

void dynArrayInit(DynArray *arr) {
  arr->size = 0;
  arr->capacity = CAPACITY_INIT;
  arr->data = (Data*) malloc(arr->capacity * sizeof(Data));
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
void dynArrayAppend(DynArray *arr, Data *data) {
  doubleCapacity(arr);
  arr->data[arr->size++] = *data;
}

void dynArrayFree(DynArray *arr) {
  free(arr->data);
}