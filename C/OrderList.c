// begin with 0, if num%10 == 1, remove
#include <stdio.h>
#include <malloc.h>

struct Node{
	int data;
	struct Node * next;
};

void output(struct Node * L) {
	struct Node *t = L;
	do {
		printf("%d ", t->data);
		t = t->next;
	} while( t!= L );
}

int main()
{
	struct Node * L;
	L = (struct Node *)malloc(sizeof(struct Node));

	int num;
	printf("please enter the sum of people: ");
	scanf("%d", &num);
	int remove_num;
	printf("remove_num: ");
	scanf("%d", &remove_num);

	struct Node * t = L;
	t->data = 1;
	for(int i=2; i<=num; i++) {
		struct Node * e = (struct Node *)malloc(sizeof(struct Node));
		e->data = i;
		t->next = e;
		t = t->next;
	}
	t->next = L;

	t = L;
	for (int i=0; num != 1; i++, t=t->next) {
		printf("%d: %d\n", i, t->data);
		if ( (i+1)%10 == remove_num ) {
			printf("remove %d, now: ", t->next->data);
			t->next = t->next->next;
			output(t);
			printf("\n");
			i++;
			num--;
		}
	}
	printf("The master is %d\n", t->data);
	return 0;
}