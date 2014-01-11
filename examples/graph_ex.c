#include <stdio.h>

typedef struct g *graph;
graph create_graph(int num_vertex);

void print_graph(graph g);
void add_edge(graph g, int v, int w);
int main() {
  graph g = create_graph(5);
  add_edge(g, 1, 3);
  add_edge(g, 0, 2);
  add_edge(g, 3, 4);
  print_graph(g);


  //TODO DFS

  //TODO BFS






}
