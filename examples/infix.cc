#include <stdio.h>
#include "../includes/utils.h"

int main() {
    Stack s;
    s = stack_create(5);
    const char *si = "foo";
    stack_push(s,(void *)si);
    stack_push(s,(void *)si);
    stack_push(s,(void *)si);
    printf("%s", (char *)stack_pop(s));
}


