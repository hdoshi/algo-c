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

int main() {

  int arr[6] = {3, 2, 1, 5, 8, 6};
  map<int, int> sum;
  int s = 11;

  // two numbers that sum;
  //extra storage, linear time.
  for (int i = 0; i < 6; i++) {
    if (sum.count(s - arr[i]) == 1)
      cout << s - arr[i] << " " << arr[i] << "; ";
    sum[arr[i]] = 1;
  }

  cout << endl;

}
