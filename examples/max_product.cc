#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
//#include "utils.h"
using namespace std;


void maxProduct (int *a, int length) {

  int max_product = -100000;
  int max_running_product = 1;
  int max_with_neg = 1;

  for (int i = 0; i < length; i++) {
    if (a[i] > 0 && a[i] * max_running_product > max_product) {
      max_product = max_running_product * a[i];
    }

    if (a[i] > 0)
      max_running_product = max_running_product * a[i];
    else
      max_running_product = 1;

    if (a[i] < 0 && max_with_neg < 0) {
      if (a[i] * max_with_neg > max_product) {
        max_product = a[i] * max_with_neg;
        max_running_product = max_product;
      }
    }
    if (a[i] == 0)
      max_with_neg = 1;
    else
      max_with_neg = a[i] * max_with_neg;

  }

  cout << max_product << endl;
  //cout << max_with_neg << endl;

}


int main() {

  int nums[7] = {1,-2,3,4,0,-5,6};
  maxProduct(nums, 7);
  int nums2[5] = {-1,-2, 0, -4, -5};
  maxProduct(nums2, 5);
  int nums3[5] = {-1, 2, 0, -4, 5};
  maxProduct(nums3, 5);
  int nums4[6] = {1, -2, 3, 4, -5, -6};
  maxProduct(nums4, 6);
  return 0;
}
