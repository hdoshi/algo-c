#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <map>
#include "utils.h"
using namespace std;



bnode construct_btree(int *in, int *pre, int *index, int s, int e) {
  if (s > e) {
    return NULL;
  }

  bnode tmp = init_btree();
  tmp->v = pre[*index];
  (*index)++;

  int i = s;
  for (i = s; i <= e; i++) {
    if (in[i] == tmp->v)
      break;
  }

  tmp->left = construct_btree(in, pre, index, s, i - 1);
  tmp->right = construct_btree(in, pre, index, i + 1, e);

  return tmp;

}

void print_btree(bnode root)
{

  queue<bnode> processing;
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

int main() {

  int inorder[8] = {4,10,3,1,7,11,8,2};
  int preorder[8] = {7,10,4,3,1,2,8,11};

  int index = 0;
  bnode root = construct_btree(inorder, preorder, &index, 0, 7);

  print_btree(root);

}
