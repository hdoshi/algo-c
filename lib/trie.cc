#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

struct tr {
  struct tr *children[26];
  int v;
};

trie init_trie() {
  trie t = (trie)malloc(sizeof(struct tr));
  memset(t, 0, sizeof(struct tr));
  return t;
}

void trie_set(trie root, const char *key, int value) {
  size_t len = strlen(key);
  trie tmp = root;
  for (size_t i = 0; i < len; i++) {
    char c = key[i];
    int index = c - 'a';
    if (tmp->children[i] == NULL) {
      tmp->children[i] = init_trie();
    }
    tmp = tmp->children[i];
  }

  if (tmp->v) {
    fprintf(stderr, "Overwriting existing value %d for %s\n", tmp->v, key);
  }
  tmp->v = value;
}

int trie_get(trie root, const char *key) {
  size_t len = strlen(key);
  trie tmp = root;
  for (size_t i = 0; i < len; i++) {
    char c = key[i];
    int index = c - 'a';
    if (tmp->children[i] == NULL) {
      return -1;
    }
    tmp = tmp->children[i];
  }

  if (tmp && tmp->v)
    return tmp->v;
  else
    return -1;

}

void trie_delete(trie root, const char *key) {
  size_t len = strlen(key);
  trie tmp = root;
  for (size_t i = 0; i < len; i++) {
    char c = key[i];
    int index = c - 'a';
    if (tmp)
      tmp = tmp->children[i];
    else
      break;
  }

  if (tmp && tmp->v)
    tmp->v = 0;;
}
