#ifndef DATA_H
#define DATA_H

#include <string.h>

typedef struct t Data;
struct t {
  char name[128];
};

void dataInit(Data *d, char *name);
int dataCompare(void *a, void *b);

#endif
