#include <stdio.h>
int main(int argc, char const *argv[])
{
	int sum = 19-1;
	for (int i=3; sum>2*i; i+=2) {
		if (sum-2*i) {
			sum -= 2*i;
		} else {
			break;
		}
	}
	printf("%d\n", sum);
	return 0;
}