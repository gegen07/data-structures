#include <stdio.h>
#include "./lib/LinkedList.h"




int main() {
  int v = 7;
  LinkedList ll;

  linkedListInit(&ll, sizeof(int));

  linkedListInsertAt(&ll, 0, &v);

  v = 11;
  linkedListAt(&ll, 0, &v);

  printf("%d\n\n", v);
  

  return 0;
}
