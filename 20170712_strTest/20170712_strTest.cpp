#include <iostream>
#include <string.h>
#include <memory.h>
using namespace std;

void print_str(char *str){
	cout<<str<<endl;
	int N = strlen(str);
	for(int i=0;i<N;++i){
		cout<<*(str+i)<<endl;
		cout<<char((*(str+i))|'0')<<endl;
	}
} 

void flip(char &c, char act){
	c = 48+((c-48)^(act-48));
}

int main(){
	char s[30];
	cin>>s;
	print_str(s); 
	char c = '1';
	flip(c,'1');
	cout<<c;
}
