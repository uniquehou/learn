#include <stdio.h>
#define M 100000

int abs(int n) {
	return n>0? n: -n;
}

int abs_in_list(int list[M][3], int begin, int end, int n) {
	for (int i=begin; i<end; i++)
		if (abs(list[i][1]) == abs(n))
			return 1;
	return 0;
}

void copylist(int from[M][3], int to[M][3], int from_index, int to_index) {
	for (int i=0; i<3; i++) {
		to[to_index][i] = from[from_index][i];
	}
}

int main(int argc, char const *argv[]){
	int begin, list_sum;
	scanf("%d%d", &begin, &list_sum);

	int list[M][3], first;
	int new_list[M][3];
	int old_list[M][3];
	int new_index = 0, old_index = 0;
	for(int i=0; i<list_sum; i++) {
		scanf("%d%d%d", &list[i][0], &list[i][1], &list[i][2]);
		if (list[i][0] == begin)
			first = i;
	}

	copylist(list, new_list, 0, new_index);

	for (int i=0; i<list_sum; i++) {
		if ( abs_in_list(new_list, 0, new_index, list[i][1]) ) {
			copylist(list, old_list, i, old_index);
			old_index ++;
		} else {
			copylist(list, new_list, i, new_index);
			new_index ++;
		}
	}

	for(int i=0; i<new_index; i++)
		printf("%d %d %d\n", new_list[i][0], new_list[i][1], new_list[i][2]);
	for(int i=0; i<old_index; i++)
		printf("%d %d %d\n", old_list[i][0], old_list[i][1], old_list[i][2]);
	return 0;
}
