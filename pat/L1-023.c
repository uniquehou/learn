#include <stdio.h>
#include <string.h>
int main() {
  int a[4] = {0,0,0,0};
  char ch;
  while ( (ch=getchar()) != '\n' ){
    switch (ch) {
        case 'g':
        case 'G': a[0]++; break;
        case 'p':
        case 'P': a[1]++; break;
        case 'l':
        case 'L': a[2]++; break;
        case 't':
        case 'T': a[3]++; break;
      }
  }
  while(a[0]>0 || a[1]>0 || a[2]>0 || a[3]>0) {
    if (a[0]-- > 0) putchar('G');
    if (a[1]-- > 0) putchar('P');
    if (a[2]-- > 0) putchar('L');
    if (a[3]-- > 0) putchar('T');
  }

  return 0;
}