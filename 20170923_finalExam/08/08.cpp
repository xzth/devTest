#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
int inpt[15];
int map[15];
int n,m=0;

bool getbit(int src, int i){
	return 1 & (src>>i);
}
void setbit(int &src, int i){
	src |= (1<<i);
}
void swapbit(int &src, int i){
	src ^= (1<<i);
}
void printbits(int a){
	for(int i=0;i<n;++i){
		cout<<getbit(a,i);
	}
	cout<<endl;
}
int draw(int line,int mask){
	int count=0;
	mask&=m;
	for(int i=0,temp=mask;i<n;++i){
		if(temp%2){
			count++;
		}
		temp/=2;
	}
	if(line<n-1){
		map[line+1] ^= mask;
	}
	if(line>0){
		map[line-1] ^= mask;
	}
	mask=mask^(mask<<1)^(mask>>1);
	mask&=m;
	map[line]^=mask;
//	printbits(map[line]);
	return count;
}



int main(){
	cin>>n;
	char c;
	for(int i=0;i<n;++i){
		setbit(m,i);
		for(int j=0;j<n;++j){
			cin>>c;
			if(c=='y'){
				setbit(inpt[i],j);
			}
		}
		map[i]=inpt[i];
	}
	
	int t=pow(2,n),count,maxd=300;
	for(int k=0;k<t;++k){
		for(int i=0;i<n;++i){
			map[i]=inpt[i];
		}
		count=draw(0,k);
		for(int i=1;i<n;++i){
			count+=draw(i,~map[i-1]);
		}
		if((map[n-1]+1)%t==0){
//			cout<<"__________"<<endl;
//			for(int i=0;i<n;++i){
//				printbits(map[i]);
//			}
//			cout<<count<<endl;
//			cout<<k<<endl;
			maxd=min(maxd,count);
		}
	}
	if(maxd==300){
		cout<<"inf";
	}
	else{
		cout<<maxd;
	}	
}
