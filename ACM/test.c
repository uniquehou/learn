#include <stdio.h>
#include <string.h>
int main(){
	int num[10000];
	int max;
	int n = 0;
	scanf("%d",&max);
	for (int i=0; i<max; i++)
		scanf("%d",&num[i]);
	int j = max;
	for (i=0; i<max; i++)
		if (num[i]==j){
			j--;
		} else {
			n++;
		}
	printf("%d\n", n);
}








/*
	char str[51];
	float k = 1, count = 0;
	gets(str);
	int length = 0;
	if (str[0]=='-') {k*=1.5; length++;}
	if ( (str[strlen(str)-1]-'0') % 2==0) k*=2;
	for(int i=0; str[i] != '0'; i++){
		count += str[i] == '2';
	}
	printf("%.2f%\n", count/(strlen(str)-length)*k*100);
*/