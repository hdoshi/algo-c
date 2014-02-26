#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void catalan(char *s, int close, int open, int index, int n)
{

  if (close == n) {
    s[index] = '\0';
    printf("%s\n", s);
    return;
  }


  if (open < n) {
    s[index] = '(';
    catalan(s, close, open + 1, index + 1, n);
  }

  if (close < open) {
    s[index] = ')';
    catalan(s, close + 1, open, index + 1, n);
  }

}


int main() {


 int n;
 scanf("%d", &n);
 char *s = (char *)malloc((2*n + 1)*sizeof(char));
 catalan(s, 0, 0, 0, n);
 free(s);

}
