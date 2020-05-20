#include "llist-node.h"

static int nodeAlloc(LListNode *llist, void *value, uint itemLength) {
  (*llist) = (LListNode) malloc(sizeof(struct llist_node_t));
  (*llist)->value = (void*) malloc(itemLength);
  (*llist)->next = NULL;
  memcpy((*llist)->value, value, itemLength);
  return 1;
}

static int nodeFree(LListNode *llist) {
  if((*llist) == NULL) return 0;
  free((*llist)->value);
  free((*llist));
  *llist = NULL;
  return 1;
}

int llistNodeInit(LListNode *llist) {
  *llist = NULL;
  return 1;
}

int llistNodeInsert(LListNode *llist, uint index, void *value, uint itemLength) {
  if((*llist) == NULL) {
    nodeAlloc(llist, value, itemLength);
    return 1;
  }
  LListNode new;
  nodeAlloc(&new, value, itemLength);
  if(index == 0) {
    new->next = *llist;
    *llist = new;
    return 1;
  }
  LListNode iterator = *llist;
  while(--index && iterator != NULL) {
    iterator = iterator->next;
  }
  if(iterator == NULL) return 0;
  LListNode next = iterator->next;
  iterator->next = new;  
  new->next = next;
  return 1;
}

int llistNodeRemove(LListNode *llist, uint index) {
  LListNode iterator = *llist;
  LListNode previous = NULL;
  while(index-- && iterator != NULL) {
    previous = iterator;
    iterator = iterator->next;
  }
  if(iterator == NULL) return 0;
  LListNode next = iterator->next;
  nodeFree(&iterator);
  if(previous == NULL) {
    (*llist) = next;
  } else {
    previous->next = next;
  }
  return 1;
}

int llistNodeAt(LListNode *llist, uint index, void *value, uint itemLength) {
  LListNode iterator = *llist;
  while(index-- && iterator != NULL) {
    iterator = iterator->next;
  }
  if(iterator == NULL) return 0;
  memcpy(value, iterator->value, itemLength);
  return 1;
}
