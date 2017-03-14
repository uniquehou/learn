#include <stdio.h>
#include <malloc.h>
#define True -3
#define False -5
#define M 100   //栈最大数量

struct Stack{
	int data[2];
	struct Stack *top;
	struct Stack *elem;
};

struct Stack * STACK_TOP[M][2];  // 存储栈顶和栈底
int COUNT = 0;   //栈的个数

void InitStack(struct Stack *S) {
	S = (struct Stack *)malloc(sizeof(struct Stack));
	STACK_TOP[COUNT][0] = STACK_TOP[COUNT][1] = S;
}

int StackEmpty(struct Stack *S) {
	if (S->data[0]) {
		return 1;
	} else {
		return 0;
	}
}

int GetTop(struct Stack * S, struct Stack * e) {
	for (int i=0; i<COUNT; i++) {
		if (S == STACK_TOP[i][0]) {
			e = STACK_TOP[i][1];
			return i;
		}
	}
	return False;
}

int StackLength(struct Stack *S) {
	struct Stack * top;
	GetTop(S, top);
	int length = 0;
	for (; top->prior; top=top->prior) {
		length++;
	}
	return length;
}

void Push(struct Stack *S, int data[2]) {
	if (StackLength) {
		struct Stack * top;
		int n = GetTop(S, top);
		// 创建插入结点
		struct Stack * e = (struct Stack *)malloc(sizeof(struct Stack));
		e->data[0] = data[0]; e->data[1] = data[1];
		e->prior = top;
		// 更新栈顶
		STACK_TOP[n][1] = e;
	} else {
		S->data[0] = data[0]; S->data[1] = data[1];
	}
}

void Pop(struct Stack * S) {
	struct Stack * top;
	int n = GetTop(S, top);
	STACK_TOP[n][1] = top->prior;
	free(top);
}

void StackOutput(struct Stack * S) {
	struct Stack * top;
	GetTop(S, top);
	for (; top->prior; top=top->prior) {
		printf("%d %d\n", top->data[0], top->data[1]);
	}
}

// void main() {
// 	struct Stack * S;
// 	InitStack(S);
// 	for (int i = 0; i < 3; ++i)
// 	{
// 		int j;
// 		scanf("%d", &j);
// 		int a[2] = {j, j*2};
// 		Push(S, a);
// 		StackOutput(S);
// 	}
// 	StackOutput(S);
// 	Pop(S);
// 	StackOutput(S);
// }