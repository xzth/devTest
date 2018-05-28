#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    
//    Print(L1);
//    Print(L2);
    
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read(){
	int n;
	List head = (List)malloc(sizeof(struct Node));
	List p=head;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		p->Next=(List)malloc(sizeof(struct Node));
		p=p->Next;
		scanf("%d",&p->Data);
	}
	p->Next=NULL;
	return head;
}

void Print( List L ){
	if(L->Next==NULL){
		printf("NULL");
	}
	while(L->Next!=NULL){
		printf("%d ",L->Next->Data);
		L=L->Next;
	}
	printf("\n");
}

List Merge( List L1, List L2 ){
	List L = (List)malloc(sizeof(struct Node)) , p = L;
	List _L1=L1->Next,_L2=L2->Next;
	while(_L1!=NULL&&_L2!=NULL){
		L->Next=(List)malloc(sizeof(struct Node));
		L=L->Next;
		if(_L1->Data<_L2->Data){
			L->Data=_L1->Data;
			_L1=_L1->Next;
		}
		else{
			L->Data=_L2->Data;
			_L2=_L2->Next;
		}
	}
	while(_L1!=NULL){
		L->Next=(List)malloc(sizeof(struct Node));
		L=L->Next;
		L->Data=_L1->Data;
		_L1=_L1->Next;
	}
	while(_L2!=NULL){
		L->Next=(List)malloc(sizeof(struct Node));
		L=L->Next;
		L->Data=_L2->Data;
		_L2=_L2->Next;
	}
	L->Next = NULL;
	L1->Next = NULL;
	L2->Next = NULL;
	return p;
}

// (List)malloc(sizeof(struct Node));
// new Node;
