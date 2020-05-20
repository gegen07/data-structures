#ifndef DATA_H
#define DATA_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct llist_node_t * LListNode;
typedef unsigned int uint;

struct llist_node_t {
  void *value;
  LListNode next;
};

int llistNodeInit(LListNode *llist);
int llistNodeInsert(LListNode *llist, uint index, void *value, uint itemLength);
int llistNodeRemove(LListNode *llist, uint index);
int llistNodeAt(LListNode *llist, uint index, void *value, uint itemLength);

#endif
