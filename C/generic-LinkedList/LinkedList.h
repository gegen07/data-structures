#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Data.h"

typedef struct linkedList_t * LinkedList;
typedef unsigned int uint;

struct linkedList_t {
  Data items;
  uint itemSize;
  uint listSize;
};

int linkedListInit(LinkedList *llist, uint itemSize);
int linkedListInsertAt(LinkedList *llist, uint index, Item value);
int 

#endif