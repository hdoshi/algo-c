#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/utils.h"


void buf_alloc(char **c, int buf) {
    *c = (char *)malloc(buf*sizeof(char));
}

void buf_dealloc(char *c) {
    free(c);
}

void buf_scan(char **c, int buf, FILE * f) {
    if(!(*c)) buf_alloc(c, buf);
    fgets(*c, buf, f);
    int len = strlen(*c);
    if( (*c)[len-1] == '\n') {
        (*c)[len-1] = '\0';
    }
}

void buf_reverse(char *a, int start, int end) {
    char tmp;
    int l = (end - start);
    if(end > start) {
        for (int i = start; i <= start + (l)/2; i++) {
            if( i != start + end - i) { // crucial, else XOR will go all wierdo! a ^ a will give 0.
                (a)[i]       ^= (a)[start + end - i];
                (a)[start + end - i] ^= (a)[i];
                (a)[i]       ^= (a)[start + end - i];
            }
        }
    }
}


