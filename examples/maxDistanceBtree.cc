#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include "utils.h"
using namespace std;

void print_btree(bnode root)
{

  queue <bnode> processing;
  processing.push(root);

  bnode tmp;
  int cnt = 1;
  int nxt_cnt = 0;
  while (!processing.empty()) {
    bnode tmp = processing.front();
    processing.pop();
    if (tmp->left) {
      processing.push(tmp->left);
      nxt_cnt++;
    }
    if (tmp->right) {
      processing.push(tmp->right);
      nxt_cnt++;
    }
    cnt--;
    cout << tmp->v << " " ;
    //cout << "cnt: "<<cnt << "nxt :"<<nxt_cnt;
    if (cnt == 0) {
      cout <<endl;
      cnt = nxt_cnt;
      nxt_cnt = 0;
    }
  }
}


int height(bnode root)
{
  if (!root)
    return 0;

  return 1 + max(height(root->left), height(root->right));

}


int max_dist(bnode root) {
    if (!root)
      return 0;

    int max_with_root = height(root->left) + height(root->right);

    int left_max = max_dist(root->left);
    int right_max = max_dist(root->right);

    if (max_with_root > left_max)
      return max(max_with_root, right_max);
    else
      return max(left_max, right_max);

}

int main() {

  //Construct tree
  bnode root = init_btree();
  root->v = 0;
  bnode list[100];
  list[0] = root;
  for (int i = 1; i < 31; i++) {
    bnode tmp = init_btree();
    tmp->v = i;
    bnode parent = list[ ((int) (i + 1) / 2) - 1];
    if ( (i + 1) % 2 == 0)
      parent->left = tmp;
    else
      parent->right = tmp;

    list[i] = tmp;

  }
  print_btree(root);
  cout<<"Max dist " << max_dist(root);
  free_btree(root);

}
