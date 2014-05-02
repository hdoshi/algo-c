// Given an array of numbers output for each value a count of the numbers less than current number to the right.
// Example: for [ 3, 5, 2, 1, 7, 0] Output: [3, 3, 2, 1, 1, 0]
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include "utils.h"
using namespace std;

// Given an array find the count of numbers which are less than the current index and are on the right of the current index

//TODO: Use a balanced BST
int insert_bst(bnode root, int v) {

  bnode current = root;
  bnode prev = NULL;
  int count = 0;
  bool insert_left = false;
  while (current) {
    prev = current;
    if (current->v < v) {
      count = count + current->left_count + 1;
      current = current->right;
      insert_left = false;
    }
    else {
      current->left_count++;
      current = current->left;
      insert_left = true;
    }
  }

  if (prev) {
    bnode tmp = init_btree();
    tmp->v = v;
    if (insert_left) {
      prev->left = tmp;
    }
    else {
      prev->right = tmp;
    }
  }
  return count;
}

int main() {

  int n = 12;
  int nums[12] = {300, 5, 2, 1, 7, 0, -12, 12, 3, 12, 11, 210};
  bnode root = init_btree();
  root->v = nums[n - 1];
  root->left = root->right = NULL;
  cout << 0 << " ";
  for (int i = n - 2; i >= 0; i--) {
    int count = insert_bst(root, nums[i]);
    cout << count << " ";
  }
  cout << endl;

}
