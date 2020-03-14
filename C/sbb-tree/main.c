#include <stdio.h>
#include "lib/sbb-tree.h"

typedef struct {
  int key;
  /* DATA */
} Data;

int dataGetKey(Item val) {
  Data d;
  memcpy(&d, val, sizeof(Data));
  return d.key;
}



int main() {

  Data d;

  SBBTree tree;
  sbbTreeInit(&tree, sizeof(Data), dataGetKey);

  d.key = 10;
  sbbTreeInsert(&tree, &d);

  d.key = 15;
  sbbTreeInsert(&tree, &d);

  d.key = 5;
  sbbTreeInsert(&tree, &d);

  d.key = 20;
  sbbTreeInsert(&tree, &d);

  d.key = 13;
  sbbTreeInsert(&tree, &d);

  return 0;
}
