#include <stdio.h>
#include <stdlib.h>

struct node {
  int v;
  struct node *next;
};

typedef struct node *vector;

struct g {
  struct node **vertices;
  int num_vertices;
};

typedef struct g *graph;

graph create_graph(int num_vertex)
{
  graph g = (graph)malloc(sizeof (struct g));
  g->num_vertices = num_vertex;
  g->vertices = (struct node **)malloc(num_vertex * sizeof(vector));
  for (int i = 0; i < num_vertex; i++) {
    g->vertices[i] = (struct node *)malloc(sizeof(struct node));
    g->vertices[i]->v = i;
  }
  return g;
}

void add_edge(graph g, int v, int w)
{
  vector v_v = g->vertices[v];
  vector v_w = g->vertices[w];

  vector tmp = v_v;

  while (tmp->next) {
    if (tmp->v == w) return;
    tmp = tmp->next;
  }

  tmp->next = (struct node *)malloc(sizeof (struct node));
  tmp->next->v = w;

  tmp = v_w;

  while (tmp->next) {
    tmp = tmp->next;
  }
  tmp->next = (struct node *)malloc(sizeof (struct node));
  tmp->next->v = v;
}

void print_graph(graph g)
{
  for (int i = 0; i < g->num_vertices; i++) {
    vector v = g->vertices[i];
    vector tmp = v;
    printf("%d->", v->v);
    while(tmp) {
      tmp = tmp->next;
      if (tmp)
        printf("%d->", tmp->v);
    }
    printf("\n");
  }
}


