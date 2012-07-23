#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void buf_alloc(char **c, int buf);
void buf_dealloc(char *c) ;
void buf_scan(char **c, int buf, FILE * f) ;
void buf_reverse(char **, int, int);

typedef struct StackNode* Stack;
Stack  stack_create(int cap);
int stack_push(Stack s, void *el);
void * stack_pop(Stack s);
void stack_destroy(Stack s);


