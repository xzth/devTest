#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
int a[3];
int result[50];
ifstream fin("in_.txt");

int main(){
	int t,n,last,now,next;
	fin>>t;
	for(int k=0;k<t;++k){
		fin>>n;
		fin>>a[0];
		next=a[0];
		if(n>1){
			fin>>a[1];
			next=max(a[0],a[1]);
		}
		if(n>2){
			last=a[0];
			now=max(a[0],a[1]);
			for(int i=2;i<n;++i){
				fin>>a[2];
				next=max(last+a[2],now);
				last=now;
				now=next;
			}
		}
		result[k]=next;
	}
	for(int k=0;k<t;++k){
		cout<<result[k]<<endl;
	}
}
