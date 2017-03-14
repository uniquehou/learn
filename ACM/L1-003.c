#include <stdio.h>
#include <string.h>
int main()
{
	int num[10];
	char str[1000];
	gets(str);

	for (int i=0; i<10; i++)
		num[i] = 0;

	for (int i=0; i<strlen(str); i++)
		num[(str[i]-'0')]++;

	for (int i=0; i<10; i++)
		if (num[i])
			printf("%d:%d\n", i, num[i]);

	return 0;
}