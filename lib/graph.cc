#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


graph create_graph(int num_vertex)
{
  graph g = (graph)malloc(sizeof (struct g));
  g->num_vertices = num_vertex;
  g->vertices = (struct node **)malloc(num_vertex * sizeof(vertex));
  for (int i = 0; i < num_vertex; i++) {
    g->vertices[i] = (struct node *)malloc(sizeof(struct node));
    g->vertices[i]->v = i;
  }
  return g;
}

void add_edge(graph g, int v, int w)
{
  vertex v_v = g->vertices[v];
  vertex v_w = g->vertices[w];

  vertex tmp = v_v;

  while (tmp->next) {
    if (tmp->v == w) return;
    tmp = tmp->next;
  }

  tmp->next = (struct node *)malloc(sizeof (struct node));
  tmp->next->v = w;
  tmp->next->next = NULL;
/*  tmp = v_w; */
/*  */
/*  while (tmp->next) { */
/*    tmp = tmp->next; */
/*  } */
/*  tmp->next = (struct node *)malloc(sizeof (struct node)); */
/*  tmp->next->v = v; */
}

void print_graph(graph g)
{
  for (int i = 0; i < g->num_vertices; i++) {
    vertex v = g->vertices[i];
    vertex tmp = v;
    printf("%d->", v->v);
    while(tmp) {
      tmp = tmp->next;
      if (tmp)
        printf("%d->", tmp->v);
    }
    printf("\n");
  }
}


void free_graph(graph g)
{
  for (int i = 0; i < g->num_vertices; i++) {
    vertex v = g->vertices[i];
    while (v) {
      vertex n = v->next;
      free(v);
      v = n;
    }
  }
  free(g);
}

