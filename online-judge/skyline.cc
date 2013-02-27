#include <cstdlib>
#include <iostream>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>

//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=41

using namespace std;
typedef size_t point;

struct triple {
  point l;
  point h;
  point r;
};

point heights[10000];

int main() {

  struct triple points[5000];
  int i = 0;
  memset(heights, 0, sizeof(heights));
  point min_x = 10001, max_x = 0;
  while (cin >> points[i].l) {
    cin >> points[i].h;
    cin >> points[i].r;
    if (min_x > points[i].l) {
      min_x = points[i].l;
    }
    if (points[i].r > max_x) {
      max_x = points[i].r;
    }
    for (int l = points[i].l; l < points[i].r; l++) {
      if(heights[l] < points[i].h) heights[l] = points[i].h;
    }
    i++;
  }

  point bug = min_x;
  cout << min_x << " ";
  point cur_height = heights[bug];
  cout << cur_height << " ";
  while (bug < max_x) {
    if (cur_height != heights[bug]) {
      cout << bug  << " ";
      cur_height = heights[bug];
      cout << cur_height << " ";
    }
    bug++;
  }
  cout << max_x << " ";
  cout << 0 << endl;

  return 0;
}

