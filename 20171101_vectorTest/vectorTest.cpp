#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector <int *> a;
	int b[]={7,8,9};
//	a.push_back(b);
	a.push_back(new int[3]);
	a.push_back(b);
	a[0][0]=3;
	cout<<a[0][0];
	cout<<a[1][0];
	cout<<a[1][1];
	cout<<a[1][2];
}
