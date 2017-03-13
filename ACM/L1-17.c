#include <stdio.h>
#include <string.h>
int main()
{
	char str[51];
	float k = 1, count = 0;
	gets(str);
	int length = 0;
	if (str[0]=='-') {k*=1.5; length++;}
	if ( (str[strlen(str)-1]-'0') % 2==0) k*=2;
	for(int i=0; str[i] != '0'; i++){
		count += str[i] == '2';
	}
	printf("%.2f\n", count/(strlen(str)-length)*k*100);
	return 0;
}