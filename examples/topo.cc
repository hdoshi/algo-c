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


vector <int> order;
vector <bool> processed;
vector <bool> pending;

void topo_order(graph g, int v);


int main() {
  graph g = create_graph(5);
  add_edge(g, 1, 3);
  add_edge(g, 0, 2);
  add_edge(g, 3, 4);
  add_edge(g, 1, 2);
  add_edge(g, 2, 3);
  add_edge(g, 0, 4);

  print_graph(g);

  processed = vector<bool> (5,false);
  pending = vector<bool> (5,false);
  for (int i = 0; i < 5; i++) {
    if (!processed[i])
      topo_order(g, i);
  }

  cout << endl;
  for(std::vector<int>::size_type i = 0; i != order.size(); i++) {
    cout <<order[i] << "=> ";
  }
  free_graph(g);
}


void topo_order(graph g, int v) {

  if (processed[v]) return;

  if (pending[v]) {
    cout << "Error cycle detected" <<endl;
    exit(1);
  }
  vertex ve = g->vertices[v];

  vertex t = ve->next;
  pending[v] = true;
  while (t) {
    topo_order(g, t->v);
    t = t->next;
  }
  processed[v] = true;
  order.push_back(v);

}
