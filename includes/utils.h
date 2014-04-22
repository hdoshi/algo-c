#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void buf_alloc(char **c, int buf);
void buf_dealloc(char *c) ;
void buf_scan(char **c, int buf, FILE * f) ;
void buf_reverse(char *, int, int);

typedef struct StackNode* Stack;
Stack  stack_create(int cap);
int stack_push(Stack s, void *el);
void * stack_pop(Stack s);
void stack_destroy(Stack s);

struct node {
  int v;
  struct node *next;
};

typedef struct node *vertex;

struct g {
  struct node **vertices;
  int num_vertices;
};

typedef struct g *graph;

graph create_graph(int num_vertex);

void print_graph(graph g);
void add_edge(graph g, int v, int w);
void free_graph(graph g);


struct bn {
  int v;
  struct bn *left;
  struct bn *right;
};

typedef struct bn *bnode;
bnode init_btree();
void free_btree(bnode);


typedef struct tr * trie;

trie init_trie();
void trie_set(trie, const char *, int);
int trie_get(trie, const char *);
void trie_delete(trie, const char *);

