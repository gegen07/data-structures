#include "llist.h"

int llistInit(LList *llist, uint itemSize) {
  llist->itemSize = itemSize;
  llist->listSize = 0;
  llistNodeInit(&llist->head);
  return 0;
}

int llistInsert(LList *llist, uint index, void *value) {
  if(index > llist->listSize) return 0;
  llistNodeInsert(&llist->head, index, value, llist->itemSize);
  llist->listSize++;
  return 1;
}

int llistRemove(LList *llist, uint index) {
  if(index >= llist->listSize) return 0;
  llistNodeRemove(&llist->head, index);
  llist->listSize--;
  return 1;
}

int llistAt(LList *llist, uint index, void *value) {
  if(index >= llist->listSize) return 0;
  llistNodeAt(&llist->head, index, value, llist->itemSize);
  return 1;
}

uint linkedListSize(LList *llist) {
  return llist->listSize;
}

int linkedListClear(LList *llist) {
  if(llist->head == NULL) return 1;
  while(llist->listSize--) {
    llistNodeRemove(&llist->head, 0);
  }
  return 0;
}
