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

int linkedListRemoveAt(LinkedList *llist, uint index, Item value) {
  if(index > (*llist)->listSize) {
    return 1;
  }
  DataAt(&((*llist)->items), index, value, (*llist)->itemSize);
  DataRemoveAt(&((*llist)->items), index);
  (*llist)->listSize--;
  return 0;
}

int linkedListAt(LinkedList *llist, uint index, Item value) {
  if(index > (*llist)->listSize) {
    return 1;
  }
  DataAt(&((*llist)->items), index, value, (*llist)->itemSize);
  return 0;
}

uint linkedListSize(LinkedList *llist) {
  return (*llist)->listSize;
}

uint linkedListItemSize(LinkedList *llist) {
  return (*llist)->itemSize;
}

int linkedListClear(LinkedList *llist) {
  if(*llist == NULL) {
    return 0;
  }
  while(--(*llist)->listSize) {
    DataRemoveAt(&((*llist)->items), 0);
  }
  return 0;
}

int linkedListFree(LinkedList *llist) {
  linkedListClear(llist);
  free(*llist);
  *llist = NULL;
  return 0;
}
