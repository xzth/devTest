#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main(){
	string mod[54],tag="SHCDJ";
	for(int i=0;i<54;i++){
		mod[i]=tag[i/13];
		char num[4];
		sprintf(num,"%d",i%13+1);
		mod[i].append(num);
//		cout<<mod[i]<<" ";
	}
//	cout<<"\n";
	
	int shuf_time,a[2][54],*from,*to;
	int c[54];//={36,52,37,38,3,39,40,53,54,41,11,12,13,42,43,44,2,4,23,24,25,26,27,6,7,8,48,49,50,51,9,10,14,15,16,5,17,18,19,1,20,21,22,28,29,30,31,32,33,34,35,45,46,47};
	cin>>shuf_time;
	for(int i=0;i<54;i++){
		a[0][i]=i;
		cin>>c[i];
	}
//	
//	cout<<"\n";
//	for(int i=0;i<54;i++){
//		cout<<a[0][i]<<" ";
//	}
//	cout<<"\n";
//	for(int i=0;i<54;i++){
//		cout<<c[i]<<" ";
//	}
	
	for(int i=0;i<shuf_time;i++){
		from = a[i%2];
		to = a[(i+1)%2];
		for(int i=0;i<54;i++){
			*(to+c[i]-1) = *(from+i);
		}
	}
	
	cout<<mod[*to];
	for(int i=1;i<54;i++){
		cout<<" "<<mod[to[i]];
	}
}
