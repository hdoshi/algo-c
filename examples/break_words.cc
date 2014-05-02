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

trie dict;

void break_words(string input, string current) {
  if (!input.length()) {
    cout << current << endl;
  }
  else {
    for (int i = 0; i < input.length(); i++) {
      string t = input.substr(0, i + 1);
      if (trie_get(dict, t.c_str()) != -1) {
        break_words(input.substr(i + 1, input.length() - i), current + " " + t);
      }
    }
  }
}


int main() {

  dict = init_trie();
  trie_set(dict, "foo", 1);
  trie_set(dict, "bar", 2);
  trie_set(dict, "disk", 3);
  trie_set(dict, "isk", 4);
  trie_set(dict, "food", 5);

  break_words("foodiskbar", "");


}





