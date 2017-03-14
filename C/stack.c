#include <stdio.h>
#include <malloc.h>
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 10

struct Stack {
	struct Stack * base;
	struct Stack * top;
	int stacksize;
}

void InitStack(struct Stack * S) {
	S = (struct Stack *)malloc(sizeof(struct Stack) );
	S->base = (int *)malloc( STACK_INIT_SIZE * sizeof(int) );
	S->top = S->base;
}

struct Stack * GetTop(struct Stack * S) {
	return S->top;
}

void Push(struct Stack * S, int e) {
	if ( S->top - S->base >= S->stacksize ) {
		S->base = (int *)malloc( (S->stacksize + STACKINCREMENT) * sizeof(int) );
	}
	*S->top++ = e;
}

void Pop(struct Stack * S) {
	free(S->top--);
}

int StackLength(struct Stack * S) {
	return S->top - S->base;
}

void StackOutput(struct Stack * S) {
	struct Stack * t;
	for (t=S->base; t > S->top; t++) {
		printf("%d\n", *t);
	}
	printf("\n");
}

int main() {
	struct Stack * S;
	InitStack(S);
	Push(S, 3);
	Push(S, 4);
	StackOutput(S);
}