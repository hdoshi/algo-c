#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/utils.h"

#define BUFFER 1024


int main() {
    char *c = NULL;
    printf("Enter words to reverse: ");
    buf_scan(&c, BUFFER, stdin);
    buf_reverse(&c, 0, strlen(c) - 1);
    int j = 0;
    for(int i = 0; i <= strlen(c) ; i++) {
        if(c[i] == ' ' || c[i] == '\0' ) {
            buf_reverse(&c,j,i - 1);
            i++;
            j = i;
        }
    }
    printf("Reversed words: ");
    puts(c);
    buf_dealloc(c);
}
