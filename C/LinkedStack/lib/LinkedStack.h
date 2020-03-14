#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "../../LinkedList/lib/LinkedList.h"


typedef struct linkedStack_t LinkedStack;
struct linkedStack_t {
  LinkedList llist;
};

void linkedStackInit(LinkedStack *stack, uint itemSize);
void linkedStackPush(LinkedStack *stack, Item value);
int  linkedStackPop(LinkedStack *stack, Item value);
int  linkedStackPeek(LinkedStack *stack, Item value);
void linkedStackClear(LinkedStack *stack);


#endif
