//使用顺序表，只有10分，不知道哪错了
#include <stdio.h>
#include <malloc.h>
#define INITSIZE 10
#define INCREMENT 10

typedef struct Node{
	int* elem;
	int length;
	int listsize;
}SqList;

void InitList(SqList* L) {
	L->elem = (int *)malloc(INITSIZE * sizeof(int));
	L->length = 0;
	L->listsize = INITSIZE;
}

void AppendtList(SqList* L, int data) {
	if (L->length == L->listsize)
		L->elem = (int *)realloc(L->elem, (L->listsize + INCREMENT) * sizeof(int));
	L->elem[L->length++] = data;
}

int In_list(SqList* L, int data) {
	for (int i=0; i <= L->length; i++) {
		if (L->elem[i] == data) {
			return 1;
		}
	}
	return 0;
}

int main() {
	SqList ugly;
	InitList(&ugly);

	int a, b, c;
	scanf("%d", &a);
	for(int i=0; i<a; i++) {
		scanf("%d", &b);
		for(int j=0; j<b; j++) {
			scanf("%d", &c);
			AppendtList(&ugly, c);
		}
	}

	SqList beautiful;
	InitList(&beautiful);

	int d, e, bool=0;
	scanf("%d", &d);
	for(int i=0; i<d; i++) {
		scanf("%d", &e);
		if (! In_list(&ugly, e) && ! In_list(&beautiful, e) ) {
			AppendtList(&beautiful, e);
			if (bool) printf(" ");
			printf("%d", e);
			bool += 1;
		}
	}

	if (bool == 0)
		printf("No one is handsome\n");
	return 0;
}