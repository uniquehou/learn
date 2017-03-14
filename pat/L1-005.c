#include <stdio.h>
int main() {
	char numble[1000][15];
	int site[1000][2];
	int max;

	scanf("%d", &max);
	getchar();
	for(int i=0; i<max; i++) {
		scanf("%14c", numble[i]);
		scanf("%d%d", &site[i][0], &site[i][1]);
		getchar();
	}
		
	
	int search_sum, search[1000];
	scanf("%d", &search_sum);
	for(int i=0; i<search_sum; i++)
		scanf("%d", &search[i]);

	for(int i=0; i<search_sum; i++) {
		for (int j=0; j<max; j++) {
			if (search[i] == site[j][0]) {
				printf("%s %d\n", numble[j], site[j][1]);
				break;
			}
		}
	}
}