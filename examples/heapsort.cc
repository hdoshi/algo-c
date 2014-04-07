#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "utils.h"
using namespace std;

void max_heapify(int *a, int i, int length) {

  int left = 2 * i;
  int right = 2 * i + 1;
  int max = i;
  if (left < length && a[max] < a[left])
    max = left;
  if (right < length && a[max] < a[right])
    max = right;

  if (max != i) {
    a[max] = a[i] ^ a[max];
    a[i] = a[i] ^ a[max];
    a[max] = a[i] ^ a[max];
    max_heapify(a, max, length);
  }
}

void build_heap(int *nums, int length) {
  for (int i = (length / 2); i >= 0; i--) {
    max_heapify(nums, i, length);
  }
}


void heap_sort(int *a, int length) {

  build_heap(a, length);
  for (int i = 0 ; i < length; i++) {

    a[0] = a[length - i - 1] ^ a[0];
    a[length - i - 1] = a[length - i - 1] ^ a[0];
    a[0] = a[length - i - 1] ^ a[0];

    max_heapify(a, 0, (length - i - 1));
  }
}

int main() {

  int foo[11] = {3, 4, 1212, 2, 223, 121, 6, 5, 9, 10, 4};
  heap_sort(foo, 11);

  for (int i = 0; i < 11; i++)
    cout << foo[i] << " ";

  cout << endl;
  return 0;
}
