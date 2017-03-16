#include <stdio.h>
#include <string.h>
#include <math.h>

int ver(char str[100]) {
	if (strcmp(str, "0") == 0)
		return 0;
	if (strcmp(str, "1000") == 0) 
		return 1;
	if (strlen(str)>3)
		return 0;
	for(int i=0; i<strlen(str); i++)
		if (str[i] < '0' || str[i] > '9')
			return 0;
	return 1;
}

int sum(char str1[100], char str2[100]) {
	int num1 = 0, num2 = 0, ten=1;
	for(int i=strlen(str1)-1; i>=0; i--) {
		num1 += (str1[i] - '0') * ten;
		ten *= 10;
	}
	ten = 1;
	for(int i=strlen(str2)-1; i>=0; i--) {
		num2 += (str2[i] - '0') * ten;
		ten *= 10;
	}
	return num1 + num2;
}
int main() {
	char str1[100], str2[100];
	scanf("%s", str1);
	scanf("%s", str2);

	if (!ver(str1)) strcpy(str1, "?");
	if (!ver(str2)) strcpy(str2, "?");

	if (str1[0] == '?' || str2[0] == '?')
		printf("%s + %s = %c\n", str1, str2, '?');
	else
		printf("%s + %s = %d\n", str1, str2, sum(str1, str2));
}