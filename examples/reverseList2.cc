#include <stdio.h>
#include <stdlib.h>


struct node {
  node *next;
  int i;
};

typedef node * link;

link create_node() {
  link tmp = (link)malloc(sizeof(node *));
  tmp->next = NULL;
  return tmp;
}


void print_list(link head) {

  link c = head;
  while (c) {
    printf("%d",c->i);
    if (c->next)
      printf("->",c->i);
    c = c->next;
  }
}


link reverse_list(link head) {

  if (!head || !head->next) {
    return head;
  }
  else {
    link next = head->next;
    link rev = reverse_list(next);
    next->next = head;
    head->next  = NULL;
    return rev;
  }

}

int main() {

  link head = NULL, p = NULL, t = NULL;
  int n;
  printf("Enter size of linked list : ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    t = create_node();
    t->i = i;
    if (i == 0) {
      head = t;
    }
    if (p) {
      p->next = t;
    }
    p = t;
  }
  print_list(head);
  printf("\n");

  head = reverse_list(head);

  print_list(head);
  printf("\n");

}
