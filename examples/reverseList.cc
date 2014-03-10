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


link reverse_list(link prev, link cur) {

  if (!cur) {
    return prev;
  }
  else {
    link next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
    return reverse_list(prev, cur);
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

  head = reverse_list(NULL, head);

  print_list(head);
  printf("\n");

}
