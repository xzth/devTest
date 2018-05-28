#include <iostream>
#include <string.h>
using namespace std;
#define N 15

void print_num(int num){
	if(num==0){
		cout<<num;
		return ;
	}
	int pow[N];
	for(int i=0;i<N;++i){
		pow[i]=num%2;
		num/=2;
	}
	bool first=true;
	for(int i=14;i>=0;--i){
		if(pow[i]!=0){
			if(!first){
				cout<<"+";
			}
			else{
				first=false;
			}
			cout<<"2";
			if(i!=1){
				cout<<"(";
				print_num(i);
				cout<<")";
			}
		}
	}
}

int main(){
	int num;
	cin>>num;
	print_num(num);
}
