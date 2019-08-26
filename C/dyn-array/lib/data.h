#ifndef __DATA_H__
#define __DATA_H__

#include <stdlib.h>

typedef void (*toString)(const char*);

typedef struct {
  void *key;
  toString printStruct;
} Data;

void alloc(Data *data, void *key);
void init(Data *data, void *key, toString *function);

#endif