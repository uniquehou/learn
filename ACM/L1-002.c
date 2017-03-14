#include <stdio.h>
int main()
{
  int sum, row=0, i;
  scanf("%d", &sum);
  char ch;
  getchar(); ch=getchar();

  sum--;
  for(i=3; sum > 2*i; i+=2) {
    if (sum-2*i) {
      sum -= 2*i;
      row++;
    } else {
      break;
    }
  }
  int add = -2, m=0;
  for(row = row*2+1, i-=2; row; row--) {
    for (int j=0; j<m; j++)
      printf(" ");
    for (int j=0; j<i; j++)
      printf("%c", ch);
    if (i==1)
      add = 2;
    i += add;
    m += (-add)/2;
    printf("\n");
  }
  printf("%d\n", sum);
  return 0;
}