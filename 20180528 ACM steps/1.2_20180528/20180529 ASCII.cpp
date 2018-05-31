//Problem Description
//Since all we know the ASCII code, your job is simple: input numbers and output corresponding messages.
// 
//
//Input
//The first line contains one integer T (1<=T<=1000).
//The input will contain T positive integers separated by whitespaces (spaces, newlines, TABs).
//The integers will be no less than 32.
// 
//
//Output
//Output the corresponding message in just one line.
//Warning: no extra characters are allowed.
// 
//
//Sample Input
//
//13
//72 101 108 108 111 44
//32 119 111 114 108 100 33
//
// 
//
//Sample Output
//
//Hello, world!
//
// 
//
//Source
//“光庭杯”第五届华中北区程序设计邀请赛 暨 WHU第八届程序设计竞赛
// 
//
//Recommend
//lcy
// 

#include <stdio.h>
using namespace std;

int main(){
	
	int n, a;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i){
		
		scanf("%d", &a);
		
		printf("%c", a);
		
	}
	
	return 0;
	
}
