#ifndef DATA_H
#define DATA_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct data_t * Data;
typedef unsigned int uint;
typedef void * Item;

struct data_t {
  Item data;
  Data next;
};

int DataInit(Data *data);
int DataInsertAt(Data *data, uint index, void *value, uint itemLength);
int DataRemoveAt(Data *data, uint index);
int DataAt(Data *data, uint index, Item value, uint itemLength);

#endif