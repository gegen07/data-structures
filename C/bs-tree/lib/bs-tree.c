#include "bs-tree.h"

static void __bst_pre_order(Node *node) {  
  if (node == NULL) return;
  
  Data *key = node->data;
  puts(key->toString(getKey(key)));
  __bst_pre_order(node->left);
  __bst_pre_order(node->right);
}

static void __bst_post_order(Node *node) {
  if (node == NULL) return;
  
  Data *key = node->data;
  __bst_post_order(node->left);
  __bst_post_order(node->right);
  puts(key->toString(getKey(key)));
}

static int __bst_in_order(bs_tree_t *tree) {
  if (node == NULL) return;
  
  Data *key = node->data;
  __bst_post_order(node->left);
  puts(key->toString(getKey(key)));
  __bst_post_order(node->right);
}

int node_init(Node *node, Data *data) {
  (*node) = (Node) malloc(sizeof(struct node_t));
  node->data = data;
}

int bst_init(bs_tree_t *tree) {
  tree->level = 1;
  tree->head = NULL;
  return 0;
}

int bst_insert(Node *node, Node *node_insert, int (*compare_data)(void*, void*)) {
  if (node == NULL) {
    node_init(node, node_insert->data);
    return 0;
  } 
  
  comparator = compare_data(node_insert->data, node->data);
  if(comparator > 0)  { // greater than father node, node_right
    bst_insert(node->right, node_insert, compare_node);
  } else if (comparator < 0) { // lower than father node, node_left
    bst_insert(node->left, node_insert, compare_node);
  }
  
}

int bst_print(bs_tree_t *tree, Order_print_t order_print) {
  switch (order_print) {
    case pre_order:
      __bst_pre_order(tree);
      break;
    case post_order:
      __bst_post_order(tree);
      break;
    case in_order:
      __bst_in_order(tree);
      break;
    default:
      return -1;
  }
  return 0;
}
