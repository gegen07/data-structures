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

static void sbbNodeInsertInternal(SBBNode *root, 
                                  Item value, 
                                  uint itemSize, 
                                  int (*itemGetKey)(Item item), 
                                  Direction *dirDad,
                                  short *flagEnd) {
  if(*root == NULL) {
    sbbNodeAlloc(root, value, itemSize);
    *dirDad = Horizontal;
    return;
  } 

  if(itemGetKey(value) < itemGetKey((*root)->value)) {
    sbbNodeInsertInternal(&(*root)->left, value, itemSize, itemGetKey, &(*root)->dirLeft, flagEnd);
    
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
    sbbNodeInsertInternal(&(*root)->right, value, itemSize, itemGetKey, &(*root)->dirRight, flagEnd);

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







void sbbNodeAlloc(SBBNode *root, Item value, uint itemSize) {
  (*root) = (SBBNode) malloc(sizeof( struct sbb_node_t ));
  (*root)->left = NULL;
  (*root)->right = NULL;
  (*root)->dirLeft = Vertical;
  (*root)->dirRight = Vertical;
  
  (*root)->value = (Item) malloc(itemSize);
  memcpy((*root)->value, value, itemSize);
}

void sbbNodeInit(SBBNode *root) {
  *root = NULL;
}

void sbbNodeInsert(SBBNode *root, Item value, uint itemSize, int (*itemGetKey)(Item item)) {
  short end = FALSE; 
  Direction dir = Horizontal;
  sbbNodeInsertInternal(root, value, itemSize, itemGetKey, &dir, &end);
}

void sbbNodeOrder(SBBNode *root, int (*func)(Item item)) {
  if(*root == NULL) return;

  sbbNodePrint(&(*root)->left, func);
  func((*root)->value);
  sbbNodePrint(&(*root)->right, func);
}

void sbbNodePreOrder(SBBNode *root, int (*func)(Item item)) {
  if(*root == NULL) return;

  func((*root)->value);
  sbbNodePrint(&(*root)->left, func);
  sbbNodePrint(&(*root)->right, func);
}

void sbbNodePostOrder(SBBNode *root, int (*func)(Item item)) {
  if(*root == NULL) return;

  sbbNodePrint(&(*root)->left, func);
  sbbNodePrint(&(*root)->right, func);
  func((*root)->value);
}




// void sbbNodeSetValue(SBBNode *root, Item value, uint itemSize) {
//   memcpy((*root)->value, value, itemSize);
// }

// void sbbNodeSetLeft(SBBNode *root, SBBNode left) {
//   (*root)->left = left; 
// }

// void sbbNodeSetRight(SBBNode *root, SBBNode right) {
//   (*root)->right = right;
// }

// void sbbNodeSetDirLeft(SBBNode *root, Direction left) {
//   (*root)->dirLeft = left;
// }

// void sbbNodeSetDirRight(SBBNode *root, Direction right) {
//   (*root)->dirRight = right;
// }
