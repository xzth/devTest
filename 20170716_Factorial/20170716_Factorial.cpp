#include <stdio.h>
using namespace std;

void product(int *A, int B){ //only positive number multiply for Factorial computing
	int *p;
	for(p=A;*p!=-1;++p){
		(*p)*=B;
	}
	for(p=A;*p!=-1;++p){
		if(*(p+1)==-1&&(*p/10)){
			*(p+1)+=1;
		}
		*(p+1)+=*p/10;
		*p%=10;
	}
}

void print_P(int *P){
	int len=0;
	while(P[len]!=-1)++len;
	for(int i=len-1;i>-1;--i){
		printf("%d",P[i]);
	}
}

void Print_Factorial ( const int N ){
	if(N<0||N>1000){
		printf("Invalid input");
	}
	else if(N==0){
		printf("1");
	}
	else{
		int P[3000];
		for(int i=0;i<3000;++i)P[i]=-1;
		int temp=N;
		for(int i=0;temp!=0;++i){
			P[i]=temp%10;
			temp/=10;
		}
		temp=N;
		while(temp!=1){
			product(P,--temp);
		}
		print_P(P);
	}
}

int main(){
	int N;
	scanf("%d", &N);
	
	Print_Factorial(N);
}
