#include <stdio.h>
#include "LinkedList.h"

typedef struct {
  int a;
  char b;
} Peso;

int main() {

  uint s = sizeof(Peso);
  int i;
  int pos;

  Peso p;

  LinkedList l;
  linkedListInit(&l, s);

  for(i=0; i < 20; i++) {
    p.a = 10 * (i+1);
    p.b = 'a' + i;

    pos = linkedListInsertAt(&l, i, &p);
    printf("%d, ", pos);
  }

  printf("\ndone\n");


  return 0;
}