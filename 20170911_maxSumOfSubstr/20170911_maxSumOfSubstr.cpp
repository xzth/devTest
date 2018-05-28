#include <iostream>

#define maxN 100000

using namespace std;

int main(){
	int n,a[maxN];
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	
	int hm=0,em=0,h=0,maxsum=-1,sum=0;
	for(int i=0;i<n;++i){
		sum+=a[i];
		if(sum>maxsum){
			hm=h;
			em=i;
			maxsum=sum;
		}
		if(sum<0){
			h=i+1;
			sum=0;
		}
	}
	if(maxsum<0){
		maxsum=0;
		hm=0;
		em=n-1;
	}
	
	cout<<maxsum<<" ";
	cout<<a[hm]<<" ";
	cout<<a[em]<<endl;
}
