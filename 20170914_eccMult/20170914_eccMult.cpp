#include <iostream>
#include <stdio.h>

using namespace std;
int p,a,b;

struct node{
	int x;
	int y;
	node(int _x,int _y){
		x=_x;
		y=_y;
	}
};

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

node* _plus(node *P1,node *P2){
	int x1=P1->x,y1=P1->y;
	int x2=P2->x,y2=P2->y;
	int x3,y3,m;
	if(x1==x2&&y1==y2){
		m=3*x1*x1+a;
		m*=mod_inv(2*y1,p);
//		m%=p;
//		if(m<0) m+=p;
	}
	
	else{
		m=(y2-y1);
		m*=mod_inv(x2-x1,p);
//		m%=p;
//		if(m<0) m+=p;
	}
	
	x3=m*m-x1-x2;
	x3%=p;
	if(x3<0) x3+=p;
	
	y3=m*(x3-x1)+y1;
	y3=-1*y3;
	y3%=p;
	if(y3<0) y3+=p;
	
	return new node(x3,y3);
}

node* _mult(node* p , int t){
	if(t==1){
		return p;
	}
	if(t==2){
		return _plus(p,p);
	}
	int l1 = t/2;
	return _plus(_mult(p,l1),_mult(p,t-l1));
}

void _print(node* p){
	printf("(%d , %d)\n",p->x,p->y);
}

int main(){
	cout<<"p: ";
	cin>>p;
	cout<<"a: ";
	cin>>a;
	cout<<"b: ";
	cin>>b;
	int t,x1,y1;
	node *result;
	while(true){
		cout<<"point: ";
		cin>>x1>>y1;
		cout<<"times: ";
		cin>>t;
		result=_mult(new node(x1,y1) , t);
		cout<<t<<" * point: ";
		_print(result);
		cout<<endl;
	}
}
