# include <stdio.h>
# include <malloc.h>
// 定义正数或0可以会跟创建链表冲突，在此随便定义了两个负数
#define True -5  
#define False -7
typedef int INT;  //方便之前修改为别的数据类型

struct Node {
	INT data;
	struct Node * before;
	struct Node * next;
};

// 创建一个空链表，返回地址
void InitList(struct Node *L) {
	struct Node *p;
	p = (struct Node *)malloc(sizeof(struct Node));
	L = p;
}

// 判断是否为空，是返回 True，否则返回 False
int ListEmpty(struct Node *L) {
	if (L->next->data == 1528349827) {
		return True;
	} else {
		return False;
	}
}

int ListLength(struct Node *L) {
	struct Node *t;
	int length = 0;
	for ( t=L; t->data; t=t->next ) {
		length++;
		//C语言链表中 t->next == NULL 不能用，我电脑中 int 型默认值是 1528349827，以此判断是否为最后一个结点
		if (t->next->data == 1528349827) {   
			break;
		}
	}
	return length;
}

// 从0开始，返回第i个结点的值，超出索引长度返回 False
INT GetElem(struct Node *L, int i) {
	struct Node *t;
	t = L;
	if (i >= 0 && i < ListLength(L) ) {
		for(int count=0; t->next->data != 1528349827; count++) {
			if (count == i) {
				return t->data;
			}
			t = t->next;
		}
	} else {
		return False;
	}
}

// 从0开始，在第 i 个元素后插入元素 e
INT ListInsert(struct Node *L, int index, INT data) {
	int ListOutput(struct Node *L);
	int length = ListLength(L) + 1;
	// printf("now, the length is: %d\n", length+1);

	if (length-1 == 0) {
		L->data = data;
		printf("now, the link is: ");
		ListOutput(L);
		return True;
	}

	int count = 0;
	struct Node *t;
	struct Node *e = (struct Node *)malloc(sizeof(struct Node));
	e->data = data;
	if (index >= -1 && index < length ) {
		for ( t=L; t->data; t=t->next) {
			if (count == index) {
				e->before = t;
				if (index != length-1 ) {
					e->next = t->next;
				}
				printf("1\n");
				t->next = e;   //这步一直出错，无法执行此语句
				printf("2\n");
				// 测试现在的链表
				printf("now, the link is: ");
				ListOutput(L);

				return True;
			}
			count++;
		}
	} else {
		return False;
	}
}

// 从0开始，删除第 index 个元素
INT ListDelete(struct Node *L, int index) {
	int count = 0;
	if (index < 0 || index > ListLength(L) ) {
		return False;
	}
	struct Node * t;
	for (t=L; index != ++count; t=t->next);
	struct Node *e = t;
	t->next = t->next->next;
	free(e);
	return True;
}

int ListOutput(struct Node *L) {
	if (ListEmpty(L) == True) {
		return False;
	}

	struct Node *t = L;
	for(; t->next->data != 1528349827; t=t->next) {
		printf("%d\n", t->data);
	}
}

void SortInsert(struct Node *L, int data) {
	struct Node *e = (struct Node *)malloc(sizeof(struct Node));
	e->data = data;
	int bool = L->data > L->next->data;
	struct Node * t;

	for (t=L; t->next->data != 1528349827; t=t->next) {
		if ( ! ((t->data < data) ^ bool) ) {
			e->before = t;
			e->next = t->next;
			t->next = e;
			exit;
		}
	}

	e->before = t;
	t->next = e;
}

int main() {
	struct Node *L;
	InitList(L);
	for (int i = 0; i < 3; ++i)	{
		int n;
		scanf("%d", &n);
		ListInsert(L, i, n);
	}
	ListOutput(L);
}