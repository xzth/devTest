#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
int m[101],p[101],maxp[101];
int n,k;
int result[1000];

ofstream fout("out_.txt");

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;++i){
		cin>>n>>k;
		for(int j=1;j<=n;++j){
			cin>>m[j];
		}
		for(int j=1;j<=n;++j){
			cin>>p[j];
		}
		
		memset(maxp,0,sizeof(maxp));
		maxp[1]=p[1];
		for(int j=2;j<=n;++j){
//			cout<<"point "<<j<<endl;
//			cout<<"from the last point: "<<m[j]-m[j-1]<<endl;
			int q=j-1;
			while(m[j]-m[q]<=k&&q>=1){
				maxp[j]=max(maxp[j],maxp[q]);
				--q;
			}
			if(q!=0){
				maxp[j]=max(maxp[j],maxp[q]+p[j]);
			}
			else{
				maxp[j]=max(maxp[j],p[j]);
			}
//			cout<<"max profit of this point: "<<maxp[j]<<endl;
		}
		result[i]=maxp[n];
	}
	for(int i=0;i<t;++i){
		cout<<result[i]<<endl;
	}
}
