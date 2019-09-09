#include <stdio.h>
#include "LinkedList.h"

int main() {

  int data;
  int reader = 0;
  int i;

  LinkedList l;
  linkedListInit(&l, sizeof(int));

  for(i=0; i<10; i++) {
    data = 2*i;
    linkedListInsertAt(&l, i, &data);
  }

  linkedListFree(&l);

  //reader = linkedListSize(&l);

  //printf("%d\n", reader);

  if(l == NULL) {
    printf("null\n");
  } else {
    printf("empty\n");
  }

  return 0;
}