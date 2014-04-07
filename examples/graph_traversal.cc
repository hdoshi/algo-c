#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include "utils.h"
using namespace std;


vector<int> processed(5, false);
queue<int> pending_q;
stack<int> pending_st;
vector<int> order;


void bfs(graph g, int start) {

  if (processed[start]) return;

  pending_q.push(start);
  while (!pending_q.empty()) {
    int v = pending_q.front();
    vertex ve = g->vertices[v];
    while (ve->next) {
      if (!processed[ve->next->v]) {
        pending_q.push(ve->next->v);
      }
      ve = ve->next;
    }
    processed[v] = true;
    order.push_back(v);
    pending_q.pop();
  }
}


void post_order_dfs_recursive(graph g, int in) {

  if (processed[in]) return;

  vertex ve = g->vertices[in];
  while (ve->next) {
    if (!processed[ve->next->v])
      post_order_dfs_recursive(g, ve->next->v);
    ve = ve->next;
  }
  processed[in] = true;
  order.push_back(in);
}

void post_order_dfs_iterative(graph g, int start) {

  if (processed[start]) return;

  pending_st.push(start);
  while (!pending_st.empty()) {
    int v = pending_st.top();
    vertex ve = g->vertices[v];
    bool done = true;
    while (ve->next) {
      if (!processed[ve->next->v]) {
        pending_st.push(ve->next->v);
        done = false;
      }
      ve = ve->next;
    }
    if (done) {
      processed[v] = true;
      order.push_back(v);
      pending_st.pop();
    }
  }
}

int main() {
  graph g = create_graph(5);
  add_edge(g, 1, 3);
  add_edge(g, 0, 2);
// CYCLE will break dfs. need to add more state in form of pending list
  //add_edge(g, 2, 0);
  add_edge(g, 3, 4);
  add_edge(g, 1, 2);
  add_edge(g, 2, 3);
  add_edge(g, 0, 4);

  //print_graph(g);

  for (int i = 0; i < 4; i++)
    bfs(g, i);
  for (size_t i = 0; i < (size_t)order.size(); i++)
    cout << order[i] << " ";

  cout << endl;
  order.clear();
  processed = vector<int> (5, false);
  for (int i = 0; i < 4; i++)
    post_order_dfs_iterative(g, i);
  for (size_t i = 0; i < (size_t)order.size(); i++)
    cout << order[i] << " ";

  cout << endl;
  order.clear();
  processed = vector<int> (5, false);
  for (int i = 0; i < 4; i++)
    post_order_dfs_recursive(g, i);
  for (size_t i = 0; i < (size_t)order.size(); i++)
    cout << order[i] << " ";

  cout << endl;
}
