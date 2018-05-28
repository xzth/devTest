#include <iostream>
#include <string.h>
#include <math.h>
#include <fstream>
using namespace std;
const int PLIST=10010;
const int GRP=2002;
int m,a,b,w,h;
int W[GRP],H[GRP];
int p[PLIST];
ofstream fout("out_test.txt");

void createp(){
	p[0]=0;
	p[1]=1;
	p[2]=2;
	p[3]=3;
	int lastp=3;
	int j;
	for(int i=4;i<PLIST;++i){
		for(j=p[i/2];j>=2;){
			if(i%j==0){
				p[i]=lastp;
				break;
			}
			j=p[j-1];
		}
		if(j==1){
			p[i]=i;
			lastp=i;
		}
	}
}

void printp(){
	int count=1;
	for(int i=2;i<PLIST;++i){
		if(p[i]==i){
			cout<<i<<"\t";
			if(count%10==0){
				cout<<endl;
			}
			++count;
		}
	}
}

bool rate_cmp(double w,double h,double a,double b){
	return (w/h>=a/b);
}

void countwh(int m,int a,int b,int &_h,int &_w){
	int maxh=pow(m*b/a,0.5);
	int h,w,maxa=0;
	for(h=p[maxh];true;h=p[h-1]){
		w=m/h+1;
		w=p[w];
		if(w*h>m){
			w=p[w-1];
		}
		if(w>=h){
			w=h;
			if(w*h>maxa){
//				cout<<w<<" "<<h<<" "<<maxa<<endl;
				maxa=w*h;
				_h=h;
				_w=w;
			}
			break;
		}
		else{
//			if(w==139&&h==151){
////				cout<<w<<" "<<h<<" "<<a<<" "<<b<<endl;
//			}
			if(rate_cmp(w,h,a,b)){
				if(w*h>maxa){
//					cout<<w<<" "<<h<<" "<<maxa<<endl;
					maxa=w*h;
					_h=h;
					_w=w;
				}
			}
		}
	}
}

int main(){
	createp();
//	printp();
	int g;
	for(g=0;;++g){
		cin>>m;
		if(m==0){
			break;
		}
		cin>>a>>b;
		
		countwh(m,a,b,H[g],W[g]);
	}
	for(int i=0;i<g;++i){
		cout<<W[i]<<" "<<H[i]<<endl;
	}
}
