#include <iostream>
#include <string.h>
#include <windows.h>
#include <math.h>

using namespace std;

void out25(int k){
	int temp=abs(k-20);
	for(int i=0;i<temp;++i){
		cout<<"       "<<endl;
	}
	for(int i=0;i<5;++i){
		cout<<"*******"<<endl;
	}
	for(int i=0;i<20-temp;++i){
		cout<<"       "<<endl;
	}
	Sleep(20);
}

int main(){
	char temp;
	for(int i=0;i<500;++i){
		out25((i/5)%40);
	}
	
	cin.get();
}
