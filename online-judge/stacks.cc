#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>

//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=39

using namespace std;

struct box {
  int num;
  int dims[10];
};

int d, n;
vector <int> seq;
int longest[30];
int previous[30];

int compare(const void *a, const void *b ) {
  return ( *(int*)b - *(int*)a );
}

int compare_box(const void *a, const void *b) {
  for (int i = 0; i < d; i ++ ) {
    if ( ((box *)a)->dims[i] <= ((box *)b)->dims[i] )
      return -1;
  }
  return 1;
}

void lis(struct box boxes[]) {

  for ( int i = 0; i < n; i++ ) {
    longest[i] = 1;
    previous[i] = i;
  }

  for(int i = 1; i < n; i++ ) {
    for(int j = 0; j < i; j++ ) {
      if((compare_box(&boxes[i], &boxes[j]) == 1) && (longest[i] < longest[j] + 1)) {
        longest[i] = longest[j] + 1;
        previous[i] = j;
      }
    }
  }

  int start;
  int max = 0;
  for ( int i = 0; i < n; i++ ) {
    if ( max <= longest[i] ) {
      max = longest[i];
      start = i;
    }
  }
  int current = start;
  while (current != previous[current]) {
    seq.push_back(boxes[current].num);
    current = previous[current];
  }
  seq.push_back(boxes[current].num);

  cout << max << endl;
  for(std::vector<int>::reverse_iterator it = seq.rbegin(); it != seq.rend(); ++it) {
    std::cout << *it << " ";
  }
  cout << endl;
}

int main() {
  while (cin >> n) {
    cin >> d;
    int box_list[n];
    struct box boxes[n];
    for (int i = 0; i < n; i++) {
      boxes[i].num = i + 1;
      for (int j = 0; j < d; j++) {
        cin >> boxes[i].dims[j];
      }
      qsort(boxes[i].dims, d, sizeof(int), compare);
    }
    qsort(boxes, n, sizeof(box), compare_box);
    seq.clear();
    lis(boxes);
  }
  return 0;
}
