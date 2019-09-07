#include <stdio.h>
#include "./lib/dyn-array.h"

typedef struct {
  int key;
} intStruct;

char *toStringIntStruct(void *data) {
  intStruct dataS = *(intStruct*) data; 
  char *print = (char*) malloc(sizeof(intStruct) + STRING_MAX);
  char buffer[BUFFER_SIZE];
  
  sprintf(buffer, "%d", dataS.key);
  strcat(print, "Cell: ");
  strcat(print, buffer);
  strcat(print, "\n");
  
  return print;
}

void freeObj(void *data) {
  free((intStruct*)data);
}

int main() {
  DynArray dynArray;
  Data data;
  intStruct dataInt;

  dynArrayInit(&dynArray, freeObj);
  createData(&data);
  setToStringFunction(&data, toStringIntStruct);

  int i;
  for (i = 200; i > -50; i--) {
    dataInt.key = i;
    setData(&data, &dataInt, sizeof(intStruct));

    dynArrayAppend(&dynArray, data);
  }

  printf("Heres the value at index 27 before CreateDataFunction:\n");
  data = getElement(&dynArray, 27);

  puts(data.toString(getKey(&data)));

  dataInt.key = 27;
  setData(&data, &dataInt, sizeof(intStruct));
  setElement(&dynArray, 27, &data);

  printf("Heres the value at index 27 after Setfunction:\n");
  data = getElement(&dynArray, 27);
  puts(data.toString(getKey(&data))); 
  
  puts(toString(&dynArray));
  
  dynArrayFree(&dynArray);

  return 0;
}