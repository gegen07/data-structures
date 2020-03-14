#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "../../LinkedList/lib/LinkedList.h"


typedef struct linkedQueue_t LinkedQueue;
struct linkedQueue_t {
  LinkedList llist;
};

void linkedQueueInit(LinkedQueue *queue, uint itemSize);
void linkedQueuePush(LinkedQueue *queue, Item value);
int  linkedQueuePop(LinkedQueue *queue, Item value);
int  linkedQueuePeek(LinkedQueue *queue, Item value);
void linkedQueueClear(LinkedQueue *queue);


#endif
