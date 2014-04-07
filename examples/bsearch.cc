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


void bin_search(int *a, int s, int start, int end) {

  if (end < start) {
    cout << "Number not found " << s << endl;
    return;
  }

  int mid = (end + start) / 2;

  int m = a[mid];

  if (s == m) {
    cout << "Found number " <<s << " Index "<< mid << endl;
  }
  else {
    if (s < m)
      bin_search(a, s, start, mid - 1);
    else
      bin_search(a, s, mid + 1, end);
  }

}


int main() {


  int arr[10] = {3, 2, 5, 8, 9, 4, 7, 10, 1, 11};
  heap_sort(arr, 10);

  int s = 10;
  bin_search(arr, s, 0, 10);

  s = 21;
  bin_search(arr, s, 0, 10);
}
