#ifndef __BS_TREE_H__
#define __BS_TREE_H__

#include "data.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t *Node;
struct node_t {
  Data data;
  struct node_t *left;
  struct node_t *right;
};

typedef struct {
  Node head;
} bs_tree_t;

typedef enum {pre_order, post_order, in_order} Order_print_t;

int node_init(Node *node, Data *data);

int bst_init(bs_tree_t *tree);
int bst_insert(Node *node, Node *node_insert, int (*compare_data)(void*, void*));
int bst_print(bs_tree_t *tree, Order_print_t order_print);

#endif
