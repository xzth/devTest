#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main(){
	char str[21] , *test = str;
	cin>>str;
//	cout<<str;
	
	int status1[10] = {0,0,0,0,0,0,0,0,0,0},
		status2[10] = {0,0,0,0,0,0,0,0,0,0};
	
	while(*test){
		status1[int(*test)-48]++;
		test++;
	}
	
//	for(int i=0;i<10;i++){
//		cout<<status1[i]<<" ";
//	}
	
	int c=0 , s=0 , L=strlen(str);
//	cout<<"\n"<<L;
	for(int i=1;i<=L;i++){
		s = ((str[L-i]-48)*2)+c;
		if(s>=10){
			c = 1;
		}
		else{
			c = 0;
		}
		str[L-i] = char(s%10+48);
	}
	
	if(c == 1){
		cout<<"No\n";
		cout<<c;
	}
	else{
		test = str;
		while(*test){
			status2[int(*test)-48]++;
			test++;
		}
		int i;
		for(i=0;i<10;i++){
			if(status1[i] != status2[i]){
				cout<<"No\n";
				break;
			}
		}
		if(i==10){
			cout<<"Yes\n";
		}
	}
	cout<<str;
}
