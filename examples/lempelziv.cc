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
    //cout << d << endl;
    trie_set(root, string(1, d).c_str(), i + 1);
  }

  string input = "abcdadaaaaabdaabdabcaaaabc";

  size_t len = input.length();

  int compressed[len];
  int index = 0;
  int seek = 0;
  int prev_end = 0;
  string prev = "";
  //cout << "Index " << index << endl;
  cout << "len " << len << endl;
  bool done = true;
  size_t comp_count = 0;
  while(index < len) {

    done = false;
    while (!done) {
      //cout << prev << endl;
      if (index > len - 1) { cout << "Index " << index << "Seek " << seek << endl;break; }
      string cur = input.substr(index, seek - index + 1);
      if (trie_get(root, cur.c_str()) == -1) {
        i++;
        //cout << "Adding " << cur << " " << i << endl;
        trie_set(root, cur.c_str(), i);
        compressed[comp_count++] = trie_get(root, prev.c_str());
        //cout << "Encoding " << prev << " with " << compressed[comp_count - 1] << endl;
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
      //cout << "Code " << code << " ";
      cout << dict[code];
      cur = dict[code];
      if (prev != "") {
        dict[++i] = prev + cur[0];
        //cout << "Adding " << prev + cur[0] << " " << i << endl;
      }
    }
    else {
      cur = cur + cur[0];
      dict[++i] = cur;
      cout << dict[i];
      //cout << "Adding " << cur  << code << endl;
    }

  }

  return 0;

}
