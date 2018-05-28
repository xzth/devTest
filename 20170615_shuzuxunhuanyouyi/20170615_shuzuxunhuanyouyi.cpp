#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void mov(int *arr,int arr_len,int start,int steps,int step_len){
	if(step_len == 0){
		return;
	}
	int temp,index=start;
//	temp = arr[start];
	for(int i=1;i<steps;i++){
		temp = arr[(index+step_len)%arr_len];
		arr[(index+step_len)%arr_len] = arr[start];
		arr[start] = temp;
		index = (index+step_len)%arr_len;
	}
}

int gcd(int a,int b){
	int c;
	if(a>b){
		c=a;
		a=b;
		b=c;
	}
	if(a==0){
		return b;
	}
	for(int i=0;i<=a;i++){
		if(a%(a-i) == 0 && b%(a-i) == 0){
			return a-i;
		}
	}
}

int lcm(int a,int b){
	if(a*b==0){
		return 0;
	}
	return a*b/gcd(a,b);
}

int main(){


	int N=30 , arr[100] , M = 18;
	cin>>N>>M;
	for(int i = 0;i<N;i++){
		cin>>arr[i];
	}
	
//	for(int i = 0;i<N;i++){
//		cout<<*(arr+i);
//	}
	
	if(M!=0){
		int G = gcd(N,M) , L = lcm(N,M);
		int steps = L/M , groups = G;
		
//		cout<<"\n";
//		cout<<G<<"\n";
//		cout<<L<<"\n";
		
		for(int i = 0;i<groups;i++){
			mov(arr,N,i,steps,M);
		}
	}	
	
	cout<<*arr;
	for(int i = 1;i<N;i++){
		cout<<" "<<*(arr+i);
	}
}
