#include "LinkedStack.h"


void linkedStackInit(LinkedStack *stack, uint itemSize) {
  linkedListInit(&stack->llist, itemSize);
}

void linkedStackPush(LinkedStack *stack, Item value) {
  linkedListInsertAt(&stack->llist, 0, value);
}

int  linkedStackPop(LinkedStack *stack, Item value) {
  if(linkedListSize(&stack->llist) > 0) {
    linkedListRemoveAt(&stack->llist, 0, value);
  } else {
    value = NULL;
    return -1;
  }
  return 0;
}

int  linkedStackPeek(LinkedStack *stack, Item value) {
  if(linkedListSize(&stack->llist) > 0) {
    linkedListAt(&stack->llist, 0, value);
  } else {
    value = NULL;
    return -1;
  }
  return 0;
}

void linkedStackClear(LinkedStack *stack) {
  linkedListClear(&stack->llist);
}
