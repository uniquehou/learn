#include <stdio.h>
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 10
typedef struct Stack{
	int* base;
	int* top;
	int stacksize;
}SqStack;

void InitStack(SqStack* S) {
	S->base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
}

void Push(SqStack* S, int e) {
	if (S->top = S->base == S->stacksize)
		S->base = realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(int));
	S->top++ = e;
}

int Pop(SqStack* S) {
	return S->top--;
}

int StackEmpty(SqStack* S) {
	return S->top - S->base;
}