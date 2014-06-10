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

bool find (bnode root, int a) {
    if (!root) return false;
    if (root->v == a) return true;
    return find(root->left, a) || find(root->right,  a);

}

int lca(bnode root, int a, int b) {


    if (!root) return -1;

    if (root->left && root->left->v == a) return root->v;
    if (root->left && root->left->v == b) return root->v;
    if (root->right && root->right->v == a) return root->v;
    if (root->right && root->right->v == b) return root->v;


    if (find(root->left, a) && find(root->left, b)) return lca(root->left, a, b);
    else if (find(root->right, a) && find(root->right, b)) return lca(root->right, a, b);
    else return root->v;
}


int better_lca(bnode root, int a, int b) {

     if (!root) return -1;

    if (root->left && root->left->v == a) return root->v;
    if (root->left && root->left->v == b) return root->v;
    if (root->right && root->right->v == a) return root->v;
    if (root->right && root->right->v == b) return root->v;

    int l = better_lca(root->left, a, b);
    int r = better_lca(root->right, a, b);

    if (l != -1 && r != -1) return root->v;
    if (l != -1) return l;
    else return r;


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

  print_btree(root);
  cout << lca(root, 11 , 9) << endl;
  cout << lca(root, 1, 9) << endl;
  cout << lca(root, 5 , 6) << endl;
  cout << better_lca(root, 11 , 9) << endl;
  cout << better_lca(root, 1 , 9) << endl;
  cout << better_lca(root, 5 , 6);

}
