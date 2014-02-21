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

queue <bnode> processing;

void print_btree(bnode root)
{

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


  //Construct tree
  bnode root = init_btree();
  root->v = 0;
  bnode list[100];
  list[0] = root;
  for (int i = 1; i < 16; i++) {
    bnode tmp = init_btree();
    tmp->v = i;
    bnode parent = list[ ((int) (i + 1) / 2) - 1];
    if ( (i + 1) % 2 == 0)
      parent->left = tmp;
    else
      parent->right = tmp;

    list[i] = tmp;

  }

  //Print tree by level
  print_btree(root);
  free_btree(root);
}

