#include<iostream>
using namespace std;
#define OK 1
#define OVERFLOW -2
#define LIST_INIT_SIZE 10 //线性表存储空间的初始分配量
#define LISTINCREMENT 2    //线性表存储空间的分配增量 
#define ERROR 0
typedef int ElemType;
typedef int Status;

typedef struct{
	ElemType *elem;//存储空间基址
	int length; //当前长度
	int listsize;//当前分配的存储容量（以sizeof(ElemType)为单位） 
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
Status ListInsert_Sq(SqList &L,int i,ElemType e){//i代表插入的位置，e代表插入的数字 
	int j;
	if(i<1||i>L.length+1)
	return ERROR;
	for(j=L.length-1;j>=i-1;j--)
		L.elem[j+1]=L.elem[j];
		L.elem[i-1]=e;
		++L.length;//表长增1
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
			cout<<"找到了"<<endl;
			m=j;
			return OK;
		}
		
	}
		
		m=-1;
		return ERROR; 
		 
}
Status  Merge_element_Sq(SqList L1,SqList L2,SqList &L){//还没有实现清除Sq_list中相同的元素了。 
	int j;
	int i;

	for(j=0;j<L1.length;j++){
		L.elem[j]=L1.elem[j];
	} 
	for(i=L1.length;i<=L1.length+L2.length-1;i++){
		L.elem[i]=L2.elem[i-L1.length];
		
	}
	Sort_List_Sq(L);
	cout<<"亲，这是你第几回写的了？"<<endl; 

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
	cout<<"请输入您需要创建的List_Sq的大小"<<endl;
	cin>>i; 
	cout<<"请依次输入您Lisy_Sq的内容"<<endl;
	CreateList_Sq(L1,i);
	cout<<"您创建的List_Sq为："<<endl; 
	OutputList_Sq(L1);

	for(i=0;i<L1.length-1;i++){
		if(L1.elem[i] == L1.elem[i+1]){
			ListRemove_element_Sq(L1, L1.elem[i+1]);
		}
	}
	OutputList_Sq(L1);
}