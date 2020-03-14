#include "LinkedQueue.h"


void linkedQueueInit(LinkedQueue *queue, uint itemSize) {
  linkedListInit(&queue->llist, itemSize);
}

void linkedQueuePush(LinkedQueue *queue, Item value) {
  linkedListInsertAt(&queue->llist, 0, value);
}

int  linkedQueuePop(LinkedQueue *queue, Item value) {
  linkedListRemoveAt(&queue->llist, linkedListSize(&queue->llist) - 1, value);
}

int  linkedQueuePeek(LinkedQueue *queue, Item value) {
  linkedListAt(&queue->llist, linkedListSize(&queue->llist) - 1, value);
}

void linkedQueueClear(LinkedQueue *queue) {
  linkedListClear(&queue->llist);
}
