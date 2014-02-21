#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/utils.h"


struct StackNode {
    int capacity;
    void ** elements;
    int top;
};

Stack  stack_create(int cap) {
    Stack s = (Stack) malloc(sizeof(StackNode));
    //Stack s = malloc(sizeof(StackNode));
    s->elements = (void **) malloc(cap * sizeof(void *));
    s->capacity = cap;
    return s;
}

int stack_push (Stack s, void *el) {
    if(s->top < s->capacity) {
        s->elements[++(s->top)] = (void *) el;
    }
    else {
        fprintf(stderr, "Stack is full \n");
        return -1;
    }

}

void * stack_pop (Stack s) {
    if(s->top >= 0) {
        return (s->elements[(s->top)--]);
    }
}

void stack_destroy (Stack s) {
    free(s->elements);
    free(s);
}














