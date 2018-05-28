#include <iostream>

using namespace std;

int mod_inv(int n,int p){
	int a[100],r0,r1,r2=1,i;
	r0=p;
	r1=n;
	for(i=0;true;++i){
		r2=r0%r1;
		if(r2==0) break;
		a[i]=r0/r1;
		r0=r1;
		r1=r2;
	}
	int _i=i,b0=1,b1=a[--i],b2;
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
	int a,n;
	cout<<"AxB = 1 (mod N)"<<endl;
	cout<<"A : ";
	cin>>a;
	cout<<"N : ";
	cin>>n;
	cout<<"B : "<<mod_inv(a,n);
}
