#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <tr1/unordered_map>

// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36

using namespace std;

std::tr1::unordered_map<int, int> g;

int getCycle(int n) {
  if (g[n] != 0) {
    return g[n];
  }
  int c;
  if (n == 1) {
    g[n] = 1;
    return g[n];
  }
  if (n % 2 != 0) {
    c = 1 + getCycle(3*n + 1);
  }
  else {
    c = 1 + getCycle(n/2);
  }
  g[n] = c;
  return c;
}


int main() {
  int i_orig, j_orig, i, j;
  while (cin >> i_orig) {
    cin >> j_orig;
    if (i_orig > j_orig) {
      i = j_orig;
      j = i_orig;
    }
    else {
      i = i_orig;
      j = j_orig;
    }
    int max = 0;
    for (int k = i; k <= j; k++) {
      int l = getCycle(k);
      if (l > max) {
        max = l;
      }
    }
    cout << i_orig << " " << j_orig << " " << max << "\n";
  }
  return 0;
}
