// 总体思路：依次判断每个身份证号，若有郊，将索引值赋予acceess数组，index为代表无效身份证的个数
#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int access[100], index=0;
	char numble[100][19];
	char M[12] = "10X98765432";
	int X[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	for(int i=0; i<n; i++)
		scanf("%s", numble[i]);

	int sum;  //加权求和
	char z;  //z值
	for(int i=0; i<n; i++) {
		sum = 0;
		int j;
		for (j=0; j<17; j++) {
			if (numble[i][j] < '0' || numble[i][j] > '9')
				break;
			sum += (numble[i][j] - '0') * X[j];
		}
		z = M[sum%11];
		if ( j<17 || numble[i][17] != z )
			access[index ++] = i;
	}

	if (index == 0) {
		printf("All passed");
	} else {
		for(int i=0; i<index; i++)
			printf("%s\n", numble[access[i]]);
	}
	return 0;
}