//Problem Description
//��������������������������������С��������
// 
//
//Input
//�����������������ݣ�ÿ��ֻ��һ�У���������������1000��������.
// 
//
//Output
//
//            ����ÿ����������������������������С��������ÿ��ʵ�����һ�С�
// 
//
//Sample Input
//
//10 14
//
// 
//
//Sample Output
//
//70
//
// 
//
//Source
//POJ
// 
//
//Recommend
//Eddy


#include <stdio.h>

using namespace std;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int gcd(int a, int b){
	
	if(a < b){
		swap(a, b);
	}
	
	int tmp;
	
	while(tmp = a%b){
		a = b;
		b = tmp;
	}
	
	return b;
}

int lcm(int a, int b){
	
	return a * b / gcd(a, b);
	
}

int main(){
	
	int a, b;
	
	while(scanf("%d %d", &a, &b) != EOF){
		printf("%d\n", lcm(a, b));	
	}
	
	return 0;
}
