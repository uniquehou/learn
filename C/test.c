# include <stdio.h>
#define True -5
#define False -7
typedef int DATA;

struct Node
{
	DATA data;
	struct Node * before;
	struct Node * next;
};

// 创建一个空链表，返回地址
struct Node * InitList() {
	struct Node *L;
	return L;
}

// void DestoryList(struct Node *L) {
// 	L = NULL;
// }

// 清空列表
void ClearList(struct Node *L) {
	if (*L) {
		L = InitList();
	}
}

// 判断是否为空，是返回 True，否则返回 False
int ListEmpty(struct Node *L) {
	if (*L) {
		return True;
	} else {
		return False;
	}
}

// 返回链表长度
int ListLength(struct Node *L) {
	struct Node *t;
	t = L;
	int length = 0;
	while (t) {
		length++;
		t = t->next;
	}
	return length;
}

// 从0开始，返回第i个结点的值，超出索引长度返回-1
DATA GetElem(struct Node *L, int i) {
	int count = 0;
	struct Node *t;
	t = L;
	if (i >= 0 && i < ListLength(L) ) {
		while(t) {
			if (count == i) {
				return t->data;
			}
			t = t->next;
			count++;
		}
	} else {
		return False;
	}
}

// 从0开始，在第 i 个元素后插入元素 e
DATA ListInsert(struct Node *L, int i, struct Node *e) {
	int count = 0;
	struct Node *t;
	t = L;
	if (i >= -1 && i < ListLength(L) ) {
		while (t) {
			if (count == i) {
				e->next = t->next;
				e->before = t;
				t->next = e;
				return True;
			}
			t = t->next;
			count++;
		}
	} else {
		return False;
	}
}

// 从0开始，删除第 i 个元素
DATA ListDelete(struct Node *L, int i) {
	int count = 0;
	struct Node *t;
	t = L;
	if (i >= 0 && i < ListLength(L)-1 ) {
		if (i == count) {
			t->before->next = t->next->before;
			return True;
		}
		t = t->next;
		count++;
	} else {
		return False;
	}
}

int main() {
	struct Node L;
	&L = InitList();

	struct Node t[5];
	for (int i=0; i<5; i++) {
		t[i].data = i * 2;
	}

	for (int i=0; i<5; i++) {
		ListInsert(&L, i-1, &t[i]);
	}

	for (int i=0; i<ListLength(&L); i++) {
		printf("%d\n", GetElem(&L, i));
	}
}
