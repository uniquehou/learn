#include <stdio.h>
#define N 100

int main(){
	int get_queue(int num, int queue[N], int count, int list[N][N]);

	int queue[N];  // �洢��������ĳ���-1
	int list[N][N];   // N������
	int count = 0;      // ��ǰʹ�õ���������Ҳ�����Ľ��	

	int max, num[10000], i;
	scanf("%d", &max);
	for (i=0; i<max; i++) {
		scanf("%d", &num[i]);
	}

	// ��ʼ��
	queue[count] = 0;
	list[count++][queue[count]++] = num[0];

	for(i=1; i<max; i++) {
		int index = get_queue(num[i], queue, count, list);
		if (index) {
			queue[index] ++;
			list[index][queue[index]] = num[i];
		} else {
			list[++count][0] = num[i];
			queue[count] = 1;
		}
		
	}
	printf("%d\n", count);
}

int get_queue(int num, int queue[N], int count, int list[N][N]) {
	int min_diff = 0, index = 0, i;
	for (i=0; i<=count; i++) {
		if (num < list[i][queue[i]]) {
			min_diff = list[i][queue[i]] - num;
			index = i;
		}
	}
	return index;
}