#include <iostream>
using namespace std;

int mod_inv(int n,int p){
	int a[100],r0,r1,r2=1,i;
	n%=p;
	if(n<0) n+=p;
	r0=p;
	r1=n;
	for(i=0;true;++i){
		r2=r0%r1;
		if(r2==0) break;
		a[i]=r0/r1;
		r0=r1;
		r1=r2;
	}
	int _i=i,b0=1,b1=a[--i],b2=b1;
	for(--i;i>=0;--i){
		b2=b1*a[i]+b0;
		b0=b1;
		b1=b2;
	}
	
	if(_i%2){
		return p-b2;
	}
	return b2;
}

int main(){
	int a;
	int p;
	cout<<"p :";
	cin>>p;
	cout<<"a :";
	cin>>a;
	
	cout<<mod_inv(a,p);
}
