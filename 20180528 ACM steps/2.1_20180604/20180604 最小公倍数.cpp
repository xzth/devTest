//Problem Description
//给定两个正整数，计算这两个数的最小公倍数。
// 
//
//Input
//输入包含多组测试数据，每组只有一行，包括两个不大于1000的正整数.
// 
//
//Output
//
//            对于每个测试用例，给出这两个数的最小公倍数，每个实例输出一行。
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
