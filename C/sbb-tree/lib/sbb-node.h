#ifndef __SBB_NODE_H__
#define __SBB_NODE_H__

#include <stdlib.h>
#include <string.h>

// #include <stdio.h>

#define FALSE 0
#define TRUE 1

typedef void * Item;
typedef unsigned int uint;
typedef struct sbb_node_t * SBBNode;


typedef enum {
  Vertical, Horizontal
} Direction;

struct sbb_node_t {
  Item value;
  SBBNode left, right;
  Direction dirLeft, dirRight;
};

void sbbNodeAlloc(SBBNode *root);
void sbbNodeInit(SBBNode *root, Item value, uint itemSize);

void sbbNodeInsert(SBBNode *root, Item value, uint itemSize, int (*itemGetKey)(Item item));

void sbbNodeSetValue(SBBNode *root, Item value, uint itemSize);
void sbbNodeSetLeft(SBBNode *root, SBBNode left);
void sbbNodeSetRight(SBBNode *root, SBBNode right);
void sbbNodeSetDirLeft(SBBNode *root, Direction left);
void sbbNodeSetDirRight(SBBNode *root, Direction right);

#endif
