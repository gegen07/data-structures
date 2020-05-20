#include "sbb-node.h"

static void sbbNodeInsertLL(SBBNode *root) {
  SBBNode middle = (*root)->left;
  (*root)->left = middle->right;
  (*root)->dirLeft = Vertical;
  middle->right = (*root);
  middle->dirLeft = Vertical;
  middle->dirRight = Vertical;
  *root = middle;
}

static void sbbNodeInsertLR(SBBNode *root) {
  SBBNode middle = (*root)->left->right;
  (*root)->left->right = middle->left;
  (*root)->left->dirRight = Vertical;
  middle->left = (*root)->left;
  (*root)->left = middle->right;
  (*root)->dirLeft = Vertical;
  middle->right = *root;
  middle->dirLeft = Vertical;
  middle->dirRight = Vertical;
  *root = middle;
}

static void sbbNodeInsertRL(SBBNode *root) {
  SBBNode middle = (*root)->right->left;
  (*root)->right->left = middle->right;
  (*root)->right->dirLeft = Vertical;
  middle->right = (*root)->right;
  (*root)->right = middle->left;
  (*root)->dirRight = Vertical;
  middle->left = *root;
  middle->dirLeft = Vertical;
  middle->dirRight = Vertical;
  *root = middle;
}

static void sbbNodeInsertRR(SBBNode *root) {
  SBBNode middle = (*root)->right;
  (*root)->right = middle->left;
  (*root)->dirRight = Vertical;
  middle->left = (*root);
  middle->dirLeft = Vertical;
  middle->dirRight = Vertical;
  *root = middle;
}

static void sbbNodeInsertInternal(SBBNode *root, void *value, uint itemSize, int (*compare)(void *a, void *b), Direction *dirDad, short *flagEnd) {

  if(*root == NULL) {
    sbbNodeAlloc(root, value, itemSize);
    *dirDad = Horizontal;
    return;
  } 

  if(compare(value, (*root)->value) < 0) {
    sbbNodeInsertInternal(&(*root)->left, value, itemSize, compare, &(*root)->dirLeft, flagEnd);
    
    if(*flagEnd || (*root)->dirLeft == Vertical) {
      *flagEnd = TRUE;
      return;
    }

    if((*root)->left->dirLeft == Horizontal) {
      sbbNodeInsertLL(root); 
      *dirDad = Horizontal;
    } else if((*root)->left->dirRight == Horizontal) {
      sbbNodeInsertLR(root);
      *dirDad = Horizontal;
    }

  } else {
    sbbNodeInsertInternal(&(*root)->right, value, itemSize, compare, &(*root)->dirRight, flagEnd);

    if(*flagEnd || (*root)->dirRight == Vertical) {
      *flagEnd = TRUE;
      return;
    }

    if((*root)->right->dirLeft == Horizontal) {
      sbbNodeInsertRL(root);
      *dirDad = Horizontal;
    } else if((*root)->right->dirRight == Horizontal) {
      sbbNodeInsertRR(root);
      *dirDad = Horizontal;
    }
  }
}







void sbbNodeAlloc(SBBNode *root, void *value, uint itemSize) {
  (*root) = (SBBNode) malloc(sizeof( struct sbb_node_t ));
  (*root)->left = NULL;
  (*root)->right = NULL;
  (*root)->dirLeft = Vertical;
  (*root)->dirRight = Vertical;
  
  (*root)->value = (void*) malloc(itemSize);
  memcpy((*root)->value, value, itemSize);
}

void sbbNodeInit(SBBNode *root) {
  *root = NULL;
}

void sbbNodeInsert(SBBNode *root, void *value, uint itemSize, int (*compare)(void *a, void *b)) {
  short end = FALSE; 
  Direction dir = Horizontal;
  sbbNodeInsertInternal(root, value, itemSize, compare, &dir, &end);
}


