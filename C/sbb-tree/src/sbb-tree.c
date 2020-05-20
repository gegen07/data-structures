#include "sbb-tree.h"

void sbbTreeInit(SBBTree *tree, uint itemSize, int (*compare)(void *a, void *b)) {
  sbbNodeInit(&tree->head);
  tree->itemSize = itemSize;
  tree->compare = compare;
}

void sbbTreeInsert(SBBTree *tree, void *value) {
  sbbNodeInsert(&tree->head, value, tree->itemSize, tree->compare);
}

