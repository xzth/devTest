#include <iostream>
using namespace std;
#define maxN 30

void init_array(int *p){
	*p=0;
	while(*++p!=-1){
		*p=0;
	}
}

void print_array(int *p, int oriN, int &col){
	if(col!=0&&col%4==0){
		cout<<endl;
	}
	else{
		if(col!=0){
			cout<<";";
		}
	}
	cout<<oriN<<"=";
	cout<<*p;
	while(*++p>0){
		cout<<"+"<<*p;
	}
	col++;
}

void print_decomposition(int oriN, int N, int bottom, int *arr, int *p, int &col){
	if(N<2*bottom){
		*p=N;
		print_array(arr,oriN,col);
		init_array(p);
	}
	else{
		for(int i=bottom;i<N/2+1;++i){
			*p=i;
			print_decomposition(oriN,N-i,i,arr,p+1,col);
			init_array(p);
		}
		*p=N;
		print_array(arr,oriN,col);
		init_array(p);
	}
}

int main(){
	int N,col=0,arr[maxN+1];
	arr[maxN]=-1;
	cin>>N;
	init_array(arr);
	print_decomposition(N,N,1,arr,arr,col);
}
