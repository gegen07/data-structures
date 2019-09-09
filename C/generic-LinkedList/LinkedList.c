#include "LinkedList.h"

int linkedListInit(LinkedList *llist, uint itemSize) {
  (*llist) = (LinkedList) malloc(sizeof(struct linkedList_t));
  (*llist)->itemSize = itemSize;
  (*llist)->listSize = 0;
  DataInit(&((*llist)->items));
  return 0;
}

int linkedListInsertAt(LinkedList *llist, uint index, Item value) {
  if(index > (*llist)->listSize) {
    return 1;
  }
  if(DataInsertAt(&((*llist)->items), index, value, (*llist)->itemSize) != 0) {
    return 1;
  }
  (*llist)->listSize++;
  return 0;
}