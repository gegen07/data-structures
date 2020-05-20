#include "data.h"

void dataInit(Data *d, char *name) {
  strcpy(d->name, name);
}

int dataCompare(void *a, void *b) {
  Data *aa = (Data*)(a);
  Data *bb = (Data*)(b);
  return strcmp(aa->name, bb->name);
}
