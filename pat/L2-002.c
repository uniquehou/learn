#include <stdio.h>
#include <malloc.h>
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10

struct Node {
	int *elem[3];
	int length;
	int listsize;
}

// int abs(int n) {
// 	return n>0? n: -n;
// }

// int abs_in_list(int list[M][3], int begin, int end, int n) {
// 	for (int i=begin; i<end; i++)
// 		if (abs(list[i][1]) == abs(n))
// 			return 1;
// 	return 0;
// }

// void copylist(int from[][3], int from_index, int to[][3], int to_index) {
// 	for (int i=0; i<3; i++) {
// 		to[to_index][i] = from[from_index][i];
// 	}
// }

void InitList(struct Node * L) {
	L = (struct Node *)malloc(sizeof(struct Node));
	L->elem = (int * [])malloc( LIST_INIT_SIZE * sizeof(int[3]) );
	L->listsize = LIST_INIT_SIZE;
	L->length = 0;
}

void ListInsert(struct Node *L, int index, int data[3]) {
	if (L->length = L->listsize) {
		L->elem = realloc(L->elem, (L->listsize + LISTINCREMENT)*sizeof(int[3]));
		L->listsize += LISTINCREMENT;
	}

	if (L->length != index+1) {
		for(int i = L->length-1; i<=index; i--)
			for (int j=0; j<3; j++)
				L->elem[i][j] = L->elem[i-1][j];
	}

	for(int j=0; j<3; j++)
		*(*((L->elem)+i)+j) = data[j];
	L->length ++;
}

int main(){
	int begin, list_sum;
	scanf("%d%d", &begin, &list_sum);

	// int list[M][3], first;
	// int new_list[M][3];
	// int old_list[M][3];
	// int new_index = 0, old_index = 0;
	// for(int i=0; i<list_sum; i++) {
	// 	scanf("%d%d%d", &list[i][0], &list[i][1], &list[i][2]);
	// 	if (list[i][0] == begin)
	// 		first = i;
	// }

	// copylist(list, new_list, 0, new_index);

	// for (int i=0; i<list_sum; i++) {
	// 	if ( abs_in_list(new_list, 0, new_index, list[i][1]) ) {
	// 		copylist(list, old_list, i, old_index);
	// 		old_index ++;
	// 	} else {
	// 		copylist(list, new_list, i, new_index);
	// 		new_index ++;
	// 	}
	// }

	// for(int i=0; i<new_index; i++)
	// 	printf("%05d %d %05d\n", new_list[i][0], new_list[i][1], new_list[i][2]);
	// for(int i=0; i<old_index; i++)
	// 	printf("%05d %d %05d\n", old_list[i][0], old_list[i][1], old_list[i][2]);
	// return 0;
}
