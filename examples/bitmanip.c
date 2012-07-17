#include <stdio.h>


int main() {

    int m,n,i,j;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter m: ");
    scanf("%d", &m);
    printf("Enter i: ");
    scanf("%d", &i);
    printf("Enter j: ");
    scanf("%d", &j);

    unsigned int max = ~0;
    unsigned int right, left;
    unsigned int mask;

    /*
      left  = 11111000000 = 11111111111 << j
      right = 00000000011 = (1 << i) -1

    */

    left = max << (j + 1);
    right = (1 << i) - 1;

    mask = right | left;

    unsigned int p = n & mask;
    unsigned int o = p | (m << i);
    printf("Output %u  \n",o);

}


