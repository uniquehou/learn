#include <stdio.h>
int main() {
	int n, high[20], weight[20];
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d%d", &high[i], &weight[i]);

	int stand;
	for(int i=0; i<n; i++) {
		stand = (int)(high[i]-100)*0.9*2;
		if (weight[i] > stand*1.1)
			printf("You are tai pang le!\n");
		else if (weight[i] < stand*0.9)
			printf("You are tai shou le!\n");
		else
			printf("You are wan mei!\n");
	}
	return 0;
}