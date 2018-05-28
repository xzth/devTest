#include <iostream>
#include <string.h>
#include <memory.h>
using namespace std;

int main(){
	char a[10];
	char b[] = "123456";
//	int c=3,d=3,e=3;
//	cout<<(c==d==e)<<endl;
	cout<<a<<endl;
	cout<<b<<endl;
//	
//	strncpy(a,b,3);
//	a[3]='\0';
	strcpy(a,b);

	cout<<a<<endl;
	cout<<b<<endl;
	cout<<strlen(b)<<endl;
	
}
