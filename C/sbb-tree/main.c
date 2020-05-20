#include <stdio.h>
#include "src/sbb-tree.h"
#include "src/data.h"

int main() {

  SBBTree tree;
  sbbTreeInit(&tree, sizeof(Data), dataCompare);

  Data d;
  dataInit(&d, "dener");
  sbbTreeInsert(&tree, &d);

  Data i;
  dataInit(&i, "is");
  sbbTreeInsert(&tree, &i);

  Data p;
  dataInit(&p, "prety");
  sbbTreeInsert(&tree, &p);

  Data s;
  dataInit(&s, "smart");
  sbbTreeInsert(&tree, &s);

  return 0;
}
