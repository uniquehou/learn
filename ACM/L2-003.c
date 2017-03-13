#include <stdio.h>
#define M 1000
int main()
{
	int sum_moon, sum_market;
	scanf("%d%d", &sum_moon, &sum_market);
	int moon_total[M], moon_price[M];
	float moon_each_price[M];

	for(int i=0; i<sum_moon; i++) {
		scanf("%d", &moon_total[i]);
	}
	for(int i=0; i<sum_moon; i++) {
		scanf("%d", &moon_price[i]);
		moon_each_price[i] = (float)moon_price[i] / moon_total[i];
	}

	int now_sum=0, index=0, add_num = 0;
	float profit, max = 0;
	while (now_sum < sum_market) {
		max = 0;
		for(int i=0; i<sum_moon; i++) {
			if (moon_each_price[i] > max) {
				max = moon_each_price[i];
				index = i;
			}
		}
		add_num = sum_market - now_sum > moon_total[index]? moon_total[index] : sum_market - now_sum;
		profit += add_num * moon_each_price[index];
		now_sum += add_num;
		moon_each_price[index] = 0;
	}
	printf("%.2f\n", profit);
	return 0;
}