#include <stdio.h>
#include <stdlib.h>

/*
    Swap Nodes of a Linked List as below

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


link swap_nodes(link cur) {

  if (!cur || !cur->next)
    return cur;
  else {
    link next = cur->next;
    link next_next = next->next;
    next->next = cur;
    cur->next = swap_nodes(next_next);
    return next;
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
        if(p) {
            p->next = t;
        }
        p = t;
    }
    print_list(head);
    printf("\n");


    head = swap_nodes(head);


    print_list(head);
}


/*
// Reverse a Linked List
while (current) {
next = current->next;
current->next = previous;
previous = current;
current = next;
}
*/
