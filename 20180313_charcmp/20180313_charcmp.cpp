#include <iostream>
#include <string.h>

using namespace std;

int main(){
	
	while(true){
		cout<<"-----------------\n";
		char a, b;
		cin>>a>>b;
		
		bool check = 
			(a == b? 
			true : 
			!(a > 64 && a < 91 || a > 96 && a < 123) || !(b > 64 && b < 91 || b > 96 && b < 123) ?
			false :
			((a > b) ? (a - 32 == b) : (a + 32 == b)));
			
		if (check) {
			cout<<"same char\n";
		}
		else{
			cout<<"diff char\n";
		}
	}
	
}
