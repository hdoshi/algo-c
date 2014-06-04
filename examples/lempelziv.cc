#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include "utils.h"
using namespace std;


int main() {
  trie root = init_trie();

  int i;

  //Encoding
  for (i = 0; i < 26; i++) {
    int c = 97 + i;
    char d = c;
    trie_set(root, string(1, d).c_str(), i + 1);
  }

  //string input = "abcdadaaaaabdaabdabcaaaabc";
  string input = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

  size_t len = input.length();

  int compressed[len];
  int index = 0;
  int seek = 0;
  int prev_end = 0;
  string prev = "";
  cout << "len " << len << endl;
  bool done = true;
  size_t comp_count = 0;
  while(index < len) {
    done = false;
    while (!done) {
      string cur = input.substr(index, seek - index + 1);
      if (trie_get(root, cur.c_str()) == -1) {
        trie_set(root, cur.c_str(), ++i);
        compressed[comp_count++] = trie_get(root, prev.c_str());
        index = seek;
        done = true;
      }
      else {
        prev = cur;
        seek++;
        if (seek > len - 1) {
          compressed[comp_count++] = trie_get(root, prev.c_str());
          done = true;
          index = seek;
        }
      }
    }

  }

  for (size_t k = 0; k < comp_count; k++)
    cout << compressed[k] << " ";

  cout << endl << input << endl;


  // Decoding
  unordered_map<int, string> dict;

  for (i = 0; i < 26; i++) {
    int c = 97 + i;
    char d = c;
    dict[i + 1] = string(1,d);
  }

  prev = "";
  string cur = "";
  for (size_t k = 0; k < comp_count ; k++) {
    int code = compressed[k];
    if (dict.find(code) != dict.end()) {
      prev = cur;
      cout << dict[code];
      cur = dict[code];
      if (prev != "") {
        dict[++i] = prev + cur[0];
      }
    }
    else {
      // the tricky case
      cur = cur + cur[0];
      dict[++i] = cur;
      cout << dict[i];
    }

  }

  return 0;

}
