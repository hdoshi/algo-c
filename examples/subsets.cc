#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <unordered_map>
#include <math.h>
#include "utils.h"
using namespace std;

// stanford : http://graphics.stanford.edu/~seander/bithacks.html
int get_next_perm(int v) {
    int t = (v | ( v - 1)) + 1;
    int w = t | ((((t & -t) / (v & -v)) >> 1) - 1);
    return w;
}

// subsets in popcount order
void generate_subsets(string l) {
  string letters = l;
  int len = (int)letters.length();
  int max = pow(2, len) - 1;
  for (int i = len; i > 0; i--) {
    int j = pow(2, i);
    int k = j - 1;
    while (true) {
      if (k > max ) break;
      string current;
      for (int m = 0; m < len; m++) {
        if (k & (1 << m)) {
          current.append(letters, m, 1);
        }
      }
      cout << current << endl;
      k = get_next_perm(k);
    }
  }
}


void generate_subsets_graph(string l) {

  unordered_map<string, bool> seen;
  queue<string> process;

  process.push(l);

  while (!process.empty()) {
    string cur = process.front();
    process.pop();
    if (seen.find(cur) == seen.end()) {
      size_t len = cur.length();
      cout << cur << endl;
      for (size_t i = 0; i < len; i++) {
        string t = cur;
        string p = t.erase(i, 1);
        process.push(p);
      }
      seen[cur] = true;
    }
  }
}

int main() {
  string letters = "abcdef";
  //generate_subsets(letters);
  generate_subsets_graph(letters);
  //generate_subsets("abc");
  generate_subsets_graph("abc");
  //generate_subsets("zabck");
  generate_subsets_graph("zabck");
}
