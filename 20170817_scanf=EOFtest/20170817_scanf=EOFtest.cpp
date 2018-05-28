#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int c;
//	while(scanf("%c",&c)!=EOF){
//		printf("output: %c\n",c);
//	}
	cin>>c;
	cout<<c-EOF<<endl;
//	while((cin>>c)!=EOF){
//		cout<<"output: "<<c<<endl;
//	}
}
//scanf returns the param number inputted 
//when input ctrl+z, it returns -1
