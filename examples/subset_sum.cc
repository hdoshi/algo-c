#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include "utils.h"
using namespace std;

unordered_map<int, std::unordered_map<int, bool>> sums;


int main() {

  int n = 5;

  int arr[5] = {-7, -3, -2, 8, 5};
  int b = 0;
  int a = 0;
  for (int i = 0; i < 5; i++) {
    if (arr[i] > 0) b += arr[i];
    else a += arr[i];
  }

  for (int i = a; i <= b; i++) {
    for (int j = 0; j <= 5; j++) {
      if (0 == i)
        sums[j][i] = true;
      else
        sums[j][i] = false;
    }
  }

  for (int j = 1; j <= 5; j++) {
    for (int i = a; i <= b; i++) {
      int k = 0;
      k = i - arr[j - 1];
      if (k >= a && k <= b && sums[j - 1][k] == true)
        sums[j][i] = true;
      else
        sums[j][i] = sums[j - 1][i];
    }
  }

  for ( auto it = sums.begin(); it != sums.end(); ++it ) {
    cout << it->first << endl;
    unordered_map<int, bool> k = it->second;
    for ( auto it2 = k.begin(); it2 != k.end(); ++it2 ) {
      cout << "  " << it2->first << "->" << it2->second << endl;
    }
  }


}
