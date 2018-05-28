#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool isprime(int num){
	int b = pow(double(num),0.5);
	for(int i = 2;i<=b;i++){
		if(num%i == 0){
			return false;
		}
	}
	return true;
}


int main(){
	int N=99999 , sum=0 , p_low=3 , p_high=5;
	cin>>N;
	while(p_high<=N){
		if(isprime(p_high)){
			if(p_high-p_low == 2){
			sum++;
			}
			p_low=p_high;
		}
		p_high += 2;
	}
	cout<<sum;

//	while (true){
//		int test;
//		cin>>test;
//		cout<<pow(double(test),0.5)<<"\n";
//		cout<<isprime(test)<<"\n";
//		if(test==0){
//			break;
//		}
//	}	
}
