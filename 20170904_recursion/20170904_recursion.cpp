#include <iostream>

using namespace std;
bool down;

void printN(int n){
	if(n==0) {
		cout<<" success";
		down=false;
	}
	else printN(--n);
}

int main(){
	int i=100;
	while(true){
		down=true;
		i+=100;
		cout<<"N = "<<i;
		printN(i);
		cout<<endl;
		if(down) break;
	}
}
