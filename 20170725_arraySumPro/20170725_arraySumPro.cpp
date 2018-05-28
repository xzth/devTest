#include <iostream>
using namespace std;

#define maxN 100000
#define strLEN maxN+100

void initial_arr(int *arr, int A, int N){
	for(int i=0;i<strLEN;++i){
		if(i<N){
			arr[i]=(N-i)*A;
		}
		else{
			arr[i]=-1;
		}
	}
}

void carry_bit(int *arr, int &N){
	int i=0,carry=0;
	while(true){
		carry=arr[i]/10;
		if(carry&&arr[i+1]==-1){
			arr[i+1]+=1;
		}
		if(arr[i+1]==-1){
			break;
		}
		arr[i+1]+=carry;
		arr[i]%=10;
		++i;
	}
	N=i+1;
}

void print_arr(int *Arr,int N){
//	cout<<endl;
	if(Arr[0]==-1){
		cout<<0;
	}
	else{
		for(int i=0;i<N;++i){
			cout<<Arr[N-1-i];
		}
	}
}

int main(){
	int A,N;
	int array[strLEN];
	cin>>A>>N;
	A%=10;
	initial_arr(array,A,N);
	carry_bit(array,N);
	print_arr(array,N);
}
