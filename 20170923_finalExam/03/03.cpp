#include <iostream>
#include <string.h>

using namespace std;
int a[12][12];
int m,n;
int result[20];

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;++i){
		cin>>m>>n;
		for(int j=1;j<=m;++j){
			a[j][1]=1;
			for(int k=2;k<=n;++k){
				a[j][k]=a[j][k-1];
				if(j==k){
					++a[j][k];
				}
				if(j>k){
					a[j][k]+=a[j-k][k];
				}
			}
		}
		result[i]=a[m][n];
	}
	for(int i=0;i<t;++i){
		cout<<result[i]<<endl;
	}
}
