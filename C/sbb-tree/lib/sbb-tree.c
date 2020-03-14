#include "sbb-tree.h"

void sbbTreeInit(SBBTree *tree, uint itemSize, int (*itemGetKey)(Item item)) {
  sbbNodeInit(&tree->head);
  tree->itemSize = itemSize;
  tree->itemGetKey = itemGetKey;
}

void sbbTreeInsert(SBBTree *tree, Item value) {
  sbbNodeInsert(&tree->head, value, tree->itemSize, tree->itemGetKey);
}


