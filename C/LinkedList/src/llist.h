#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "llist-node.h"

#include <stdio.h>

typedef struct llist_t LList;
typedef unsigned int uint;

struct llist_t {
  LListNode head;
  uint itemSize;
  uint listSize;
};

int  llistInit(LList *llist, uint itemSize);
int  llistInsert(LList *llist, uint index, void *value);
int  llistRemove(LList *llist, uint index);
int  llistAt(LList *llist, uint index, void *value);
uint llistSize(LList *llist);
int  llistClear(LList *llist);

#endif
