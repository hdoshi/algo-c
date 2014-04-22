#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "utils.h"
using namespace std;



int main() {


  const char *foo = "dadasd";
  int f = 10;

  trie root = init_trie();

  trie_set(root, foo, f);
  const char *bar = "dada";
  f = 101;
  trie_set(root, bar, f);

  cout << trie_get(root, bar) << endl;
  cout << trie_get(root, foo) << endl;
  cout << trie_get(root, "doesnt exist") << endl;

  trie_set(root, bar, f + 1);
  cout << trie_get(root, bar) << endl;

  trie_delete(root, bar);
  cout << trie_get(root, bar) << endl;
}
