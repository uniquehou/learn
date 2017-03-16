#include <stdio.h>
int main() {
	int sum_a, sum_b, sum;
	scanf("%d%d%d", &sum_a, &sum_b, &sum);

	int start[100][4];
	for(int i=0; i<sum; i++)
		scanf("%d%d%d%d", &start[i][0], &start[i][1], &start[i][2], &start[i][3]);

	int yet_a=0, yet_b=0;
	for(int i=0; i<sum; i++) {
		if (start[i][0]+start[i][2] == start[i][1] && start[i][0]+start[i][2] == start[i][3])
			continue;
		if (start[i][0]+start[i][2] == start[i][1])
			yet_a ++;
		if (start[i][0]+start[i][2] == start[i][3])
			yet_b ++;
		if (yet_a - sum_a < 0) {
			printf("%c\n%d\n", 'A', sum_b);
			break;
		}
		if (yet_b - sum_b < 0) {
			printf("%c\n%d\n", 'B', sum_a);
			break;
		}
	}
	return 0;
}