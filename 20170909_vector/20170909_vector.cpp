#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main(){
	vector<int> a;
	for(int i=0;i<10;++i){
		a.push_back(i);
	}
	int k;
	cin>>k;
	for(int i=0;i<k;++i){
		a.push_back(i+10);
	}
	cout<<endl;
	cout<<"max size: "<<a.max_size()<<endl;
	cout<<"capacity: "<<a.capacity()<<endl;
	cout<<"size: "<<a.size()<<endl;
	for(int i=0;i<a.size();++i){
		cout<<a[i]<<",";
	}
}
