#include <iostream>
#include <string.h>

using namespace std;

int main(){
	
	while(true){
		cout<<"-----------------\n";
		char a[100], b[100];
		cin>>a>>b;
		int len = strlen(a);
		if(len != strlen(b)){
			cout<<"diff len!\n";
			continue;
		}
		cout<<"len = "<<len<<endl;
		char *h1 = a+len-1;
		char *h2 = b+len-1;
		int i;
		for (i = 0;
			(*(h1 - i) == *(h2 - i) ? 
			true : 
			!(*(h1 - i)>64 && *(h1 - i)<91 || *(h1 - i)>96 && *(h1 - i)<123) || !(*(h2 - i)>64 && *(h2 - i)<91 || *(h2 - i)>96 && *(h2 - i)<123) ?
			false :
			((*(h1 - i) > *(h2 - i)) ? (*(h1 - i) - 32 == *(h2 - i)) : (*(h1 - i) + 32 == *(h2 - i))))
			&& (i < len);
			i = i + 1) {
		}
		if (i != len) {
			cout<<"diff str at i = "<<i<<endl;
		}
		else{
			cout<<"same str \n";
		}
	}
	
}
