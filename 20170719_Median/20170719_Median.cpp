#include <stdio.h>

#define MAXN 3
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

void swap(ElementType *a, ElementType *b){
	ElementType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void reorder_ascend(ElementType *A, int N){
	if(N==1){
		return ;
	}
	ElementType *max = A;
	for(int i=0;i<N;++i){
		if(A[i]>(*max)){
			max = &A[i];
		}
	}
	swap(max,A);
	reorder_ascend(A+1,N-1);
}

ElementType Median( ElementType A[], int N ){
	if(N<=0){
		return 0;
	}
	if(N>MAXN){
		N=MAXN;
	}
	reorder_ascend(A,N);
	if(N%2==0){
		return A[N/2-1];
	}
	return A[N/2];
}
