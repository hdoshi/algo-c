#include <stdio.h>
#include <stdlib.h>

/*
  Input
    0->1->2->3->4->5..
  Output
    1->0->3->2->5->4...
*/



struct node {
  node *next;
  int i;
};

typedef node * link;

link create_node() {
  link tmp = (link)malloc(sizeof(node *));
  return tmp;

}

int main() {

  link head, p, t;
  for (int i = 0; i < 10; i++) {
    t = create_node();
    t->i = i;
    if (i == 0) {
      head = t;
    }
    if(p) {
      p->next = t;
    }
    p = t;
  }
  link c = head;
  while (c) {
    printf("%d->",c->i);
    c = c->next;
  }

  printf("\n");

  link a = head;
  link tmp, previous = NULL;
  link b;
  int j = 0;
  while(a) {
    //              b = a->next;
    //              a->next = previous;
    //             previous = a;
    //              a = b;

    b = a->next;
    c = b->next;

    b->next = a;
    if(previous) { previous->next = b;}
    a->next = c;

    if(j == 0 ) { head = b;} j++;
    previous = a;
    a = c;

  }
  c = head;
  while (c) {
    printf("%d->",c->i);
    c = c->next;
  }



}
/*
  while (current) {
  next = current->next;
  current->next = previous;
  previous = current;
  current = next;
  }
  */
