#include <stdio.h>

int in(int n, int arr[11], int length) {
	for(int i=0; i<length; i++)
		if (arr[i] == n)
			return i;
	return -1;
}

int main() {
	int num[11], arr[11], index[11], n=0;
	for (int i=0; i<11; i++) {
		scanf("%1d", &num[i]);
		if ( in(num[i], arr, n) < 0 )
			arr[n++] = num[i];
	}

	int temp;
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if (arr[i]<arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

	for(int i=0; i<11; i++)
		index[i] = in(num[i], arr, n);

	printf("int[] arr = new int[]{");
	for(int i=0; i<n; i++) {
		printf("%d", arr[i]);
		if (i != n-1)
			printf(",");
		else
			printf("};\n");
	}
	printf("int[] index = new int[]{");
	for(int i=0; i<11; i++) {
		printf("%d", index[i]);
		if (i != 10)
			printf(",");
		else
			printf("};\n");
	}
}