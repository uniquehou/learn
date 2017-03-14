#include<iostream>
using namespace std;
#define OK 1
#define OVERFLOW -2
#define LIST_INIT_SIZE 10 //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 2    //���Ա�洢�ռ�ķ������� 
#define ERROR 0
typedef int ElemType;
typedef int Status;

typedef struct{
	ElemType *elem;//�洢�ռ��ַ
	int length; //��ǰ����
	int listsize;//��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ�� 
}SqList;

Status InitList_Sq(SqList &L){
	L.elem=new int[LIST_INIT_SIZE];
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return OK;
}
Status OutputList_Sq(SqList L){
	int i;
	for(i=0;i<=L.length-1;i++)
	cout<<L.elem[i]<<" ";
	cout<<endl;
	return OK;
}
Status CreateList_Sq(SqList &L,int n){
	int i;
	InitList_Sq(L);
	L.length=n;
	for(i=0;i<L.length;i++)
	cin>>L.elem[i];
	return OK;
}
Status Sort_List_Sq(SqList &L){
	for(int j=0;j<L.length-1;j++){
		for(int i=0;i<L.length-1;i++){
			if(L.elem[i]>L.elem[i+1]){
				int temp;
				temp=L.elem[i];
				L.elem[i]=L.elem[i+1];
				L.elem[i+1]=temp;
		}
	}
	
	}
	return OK;	
} 
Status ListInsert_Sq(SqList &L,int i,ElemType e){//i��������λ�ã�e������������ 
	int j;
	if(i<1||i>L.length+1)
	return ERROR;
	for(j=L.length-1;j>=i-1;j--)
		L.elem[j+1]=L.elem[j];
		L.elem[i-1]=e;
		++L.length;//����1
		return OK; 
}
Status ListRemove_element_Sq(SqList &L,int i){
	for(int j=0;j<L.length;j++){
		if(i==L.elem[j]){
			for(int a=0;a<L.length-(j+1);a++)
				L.elem[a]=L.elem[a+1];
		}
	}
	--L.length;
	return OK;
	
}

Status Search_element_Sq(SqList L,int i,Status &m){
	//search element and return subscript.if not have ,return -1. 
	//	Sort_List_Sq(L);
	for(int q=0;q<L.length;q++){
		cout<<L.elem[q]<<endl;
	}
	int j;
	for(j=0;j<L.length;j++){
		if(i==L.elem[j]){
			cout<<"�ҵ���"<<endl;
			m=j;
			return OK;
		}
		
	}
		
		m=-1;
		return ERROR; 
		 
}
Status  Merge_element_Sq(SqList L1,SqList L2,SqList &L){//��û��ʵ�����Sq_list����ͬ��Ԫ���ˡ� 
	int j;
	int i;

	for(j=0;j<L1.length;j++){
		L.elem[j]=L1.elem[j];
	} 
	for(i=L1.length;i<=L1.length+L2.length-1;i++){
		L.elem[i]=L2.elem[i-L1.length];
		
	}
	Sort_List_Sq(L);
	cout<<"�ף�������ڼ���д���ˣ�"<<endl; 

	for(int g=0;g<L1.length+L2.length;g++){
		cout<<L.elem[g]<<" ";
	}		

	
 	return OK;
	}
Status Remove_Same_Element_Of_Order_List_Sq(SqList &L){
	int i;
	for(i=0;i<L.length-1;i++){
		if(L.elem[i] == L.elem[i+1]){
			ListRemove_element_Sq(L, L.elem[i+1]);
		}
	}
	return OK;
}
	

void main(){
	SqList L1;
	int i;
	cout<<"����������Ҫ������List_Sq�Ĵ�С"<<endl;
	cin>>i; 
	cout<<"������������Lisy_Sq������"<<endl;
	CreateList_Sq(L1,i);
	cout<<"��������List_SqΪ��"<<endl; 
	OutputList_Sq(L1);

	for(i=0;i<L1.length-1;i++){
		if(L1.elem[i] == L1.elem[i+1]){
			ListRemove_element_Sq(L1, L1.elem[i+1]);
		}
	}
	OutputList_Sq(L1);
}