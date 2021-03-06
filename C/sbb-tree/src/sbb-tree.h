#ifndef __SBB_TREE_H__
#define __SBB_TREE_H__

#include "sbb-node.h"

typedef struct sbb_tree_t SBBTree;

struct sbb_tree_t {
  SBBNode head;
  uint itemSize;
  int (*compare)(void *a, void *b);
};

void sbbTreeInit(SBBTree *tree, uint itemSize, int (*compare)(void *a, void *b));
void sbbTreeInsert(SBBTree *tree, void *value);

#endif
