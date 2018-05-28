#include <iostream>
#include <string.h>
#define maxN 1010

using namespace std;
int result[2*maxN];

void _read(int *a){
	int n , index , coeff;
	cin>>n;
	memset(a,0,maxN*sizeof(int));
	for(int i=0;i<n;++i){
		cin>>coeff>>index;
		a[index]=coeff;
	}
}

void _print(){
	int count=0;
	for(int i=2*maxN-1;i>=0;--i){
		if(result[i]!=0){
			if(count==0){
				cout<<result[i]<<" "<<i;
			}
			else{
				cout<<" "<<result[i]<<" "<<i;
			}
			++count;
		}
	}
	if(count==0){
		cout<<"0 0";
	}
	cout<<endl;
}

void _mult(int *a1 , int *a2){
	memset(result,0,sizeof(result));
	for(int i=0;i<maxN;++i){
		if(a1[i]!=0){
			for(int j=0;j<maxN;++j){
				if(a2[j]!=0){
					result[i+j]+=a1[i]*a2[j];
				}
			}
		}
	}
	_print();
}

void _plus(int *a1 , int *a2){
	memset(result,0,sizeof(result));
	for(int i=0;i<maxN;++i){
		if(a1[i]!=0){
			result[i]+=a1[i];
		}
		if(a2[i]!=0){
			result[i]+=a2[i];
		}
	}
	_print();
}

int main(){
	int p1[maxN],p2[maxN];
	_read(p1);
	_read(p2);
	_mult(p1,p2);
	_plus(p1,p2);
}
