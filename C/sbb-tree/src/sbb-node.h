#ifndef SBB_NODE_H
#define SBB_NODE_H

#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef unsigned int uint;
typedef struct sbb_node_t * SBBNode;


typedef enum {
  Vertical, Horizontal
} Direction;

struct sbb_node_t {
  void *value;
  SBBNode left, right;
  Direction dirLeft, dirRight;
};

void sbbNodeAlloc(SBBNode *root, void *value, uint itemSize);
void sbbNodeInit(SBBNode *root);
void sbbNodeInsert(SBBNode *root, void *value, uint itemSize, int (*compare)(void *a, void *b));

#endif
