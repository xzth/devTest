#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int main(){
	queue<int> a;
	for(int i=0;i<10;++i){
		a.push(i);
	}
	int k;
//	cin>>k;
	for(int i=0;i<10;++i){
		cout<<a.front();
		a.pop();
	}
}
