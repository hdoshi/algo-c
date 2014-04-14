// largest area rectangle in a histogram
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <stack>
#include <unordered_map>
#include "utils.h"
using namespace std;

struct pr {
  int height;
  int index;
};

typedef struct pr pairs;

int main() {

  stack<struct pr> state;
  int n = 7;
  int hist[7] = {6, 2, 5, 4, 5, 1, 6};

  int max_area = 0;
  pairs k = {hist[0], 0};
  state.push(k);
  for (int i = 1; i < n; i++) {
    k = state.top();
    int index = i;
    while (!(state.empty()  || k.height < hist [i])) {
      int current_area = (k.height) * (i  - k.index);
      index = k.index;
      if (current_area > max_area) {
        max_area = current_area;
      }

      state.pop();
      index = k.index;

      if (!state.empty())
        k = state.top();
    }
    pairs f = {hist[i], index};
    state.push(f);
  }

  while (!state.empty()) {
    pairs k = state.top();
    int current_area = k.height * (n - k.index);
    if (current_area > max_area) {
      max_area = current_area;
    }

    state.pop();
  }

  cout << "Area "<< max_area <<endl;
}




