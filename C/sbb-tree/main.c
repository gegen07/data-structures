#include <stdio.h>
#include "lib/sbb-tree.h"

int getKey(Item val) {
  int key;
  memcpy(&key, val, sizeof(int));
  return key;
}

int main() {


  SBBNode t = NULL;

  int num = 16;
  sbbNodeInsert(&t, &num, sizeof(int), getKey);
  num = 8;
  sbbNodeInsert(&t, &num, sizeof(int), getKey);
  num = 24;
  sbbNodeInsert(&t, &num, sizeof(int), getKey);
  num = 4;
  sbbNodeInsert(&t, &num, sizeof(int), getKey);
  num = 12;
  sbbNodeInsert(&t, &num, sizeof(int), getKey);
  num = 18;
  sbbNodeInsert(&t, &num, sizeof(int), getKey);

  printf("%d, %d, %d", getKey(t->value), t->dirLeft, t->dirRight);

  return 0;
}
