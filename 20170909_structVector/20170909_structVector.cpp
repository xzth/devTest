#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
bool dup[110][110];
int va,vb,c;
struct newstat{
	int a;
	int b;
	int father;
	newstat(int x,int y,int f){
		a=x;
		b=y;
		father=f;
	}
};
vector<newstat> q;

int main(){
	q.push_back(newstat(1,2,3));
	cout<<q[0].a<<",";
	cout<<q[0].b<<",";
	cout<<q[0].father;
}
