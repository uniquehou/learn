#include <stdio.h>
#include <string.h>

int in(char n[9], char str[50][9], int length) {
	for(int i=0; i<length; i++)
		if (strcmp(n, str[i]) == 0)
			return 1;
	return 0;
}

int main() {
	int num, sex[50];
	char name[50][9];
	scanf("%d", &num);
	for(int i=0; i<num; i++)
		scanf("%d %s", &sex[i], name[i]);

	char yet[50][9];
	int index=0;
	for(int i=0; i<num/2; i++) {
		printf("%s ", name[i]);
		for(int j=num-1; j; j--)
			if (sex[j] == !sex[i] && ! in(name[j], yet, index)) {
				printf("%s\n", name[j]);
				strcpy(yet[index++], name[j]);
				break;
			}
	}
}