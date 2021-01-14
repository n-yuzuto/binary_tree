#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

int main(void) {
  // Build a binary tree
  Node *d = create_tree("D", NULL, NULL);
  Node *i = create_tree("I", NULL, NULL);
  Node *h = create_tree("H", NULL, NULL);
  Node *g = create_tree("G", NULL, NULL);
  Node *e = create_tree("E", NULL, i);
  Node *f = create_tree("F", h, g);
  Node *b = create_tree("B", f, NULL);
  Node *c = create_tree("C", d, e);
  Node *a = create_tree("A", c, b);
  
  printf("preorder: ");
  preorder(a);
  printf("\n");

  printf("inorder: ");
  inorder(a);
  printf("\n");

  printf("postorder: ");
  postorder(a);
  printf("\n");

  printf("bfs: ");
  breadth_first_search(a);
  printf("\n");

  display(a);
  printf("\n");

  printf("height: %d\n", height(a));

  tree_print(a);

  delete_tree(a);

  return EXIT_SUCCESS;
}
