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

    link a = head;
    link tmp, previous = NULL;
    link b, c;
    int j = 0;

    while(a && a->next) {
        b = a->next;
        c = b->next;
        b->next = a;
        a->next = c;
        if(previous) {
            previous->next = b;
        }
        previous = a;
        a = c;

        if(j == 0 ) {
            head = b;
        }
        j++;
    }

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
