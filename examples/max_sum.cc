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



int max_sum (vector <int> list, int index, int max, int cur) {
  if (index == list.size())
    return max;
  else {
    int c = (cur <= 0) ? list[index] : list[index] + cur;
    int m = (c > max) ? c : max;
    return max_sum(list, index + 1, m, c);
  }
}

int main() {

  cout << max_sum({-1, 2, -1, 3, -1, 6}, 0, -100000, 0);

}
