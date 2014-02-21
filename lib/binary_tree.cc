#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

bnode init_btree() {
  bnode b = (bnode)malloc(sizeof(struct bn));
  *b = {0};
  return b;
}

void free_btree(bnode root) {

  if (root->left)
    free_btree(root->left);
  if (root->right)
    free_btree(root->right);

  if (root) {
    root->left = NULL;
    root->right = NULL;
    free(root);
    root = NULL;
  }
}
