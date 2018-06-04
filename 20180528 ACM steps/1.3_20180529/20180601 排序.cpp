//Problem Description
//输入一行数字，如果我们把这行数字中的‘5’都看成空格，那么就得到一行用空格分割的若干非负整数（可能有些整数以‘0’开头，这些头部的‘0’应该被忽略掉，除非这个整数就是由若干个‘0’组成的，这时这个整数就是0）。
//
//你的任务是：对这些分割得到的整数，依从小到大的顺序排序输出。
//
// 
//
//Input
//输入包含多组测试用例，每组输入数据只有一行数字（数字之间没有空格），这行数字的长度不大于1000。  
//
//输入数据保证：分割得到的非负整数不会大于100000000；输入数据不可能全由‘5’组成。
// 
//
//Output
//对于每个测试用例，输出分割得到的整数排序的结果，相邻的两个整数之间用一个空格分开，每组输出占一行。
// 
//
//Sample Input
//
//0051231232050775
//
// 
//
//Sample Output
//
//0 77 12312320
//
// 
//
//Source
//POJ
// 
//
//Recommend
//Eddy

//
//HINTS:
//	
//	DO NOT USE '\b' to correct ' ' to '\n' in loop output
//	

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
	
	int num[512];
	char buff[1024];
	
	while(1){
		
		memset(buff, 0, 1024);
		
		if(scanf("%s", buff) == EOF){
			break;
		}
		
		int count = 0, i = 0, len = strlen(buff);
		
		while(1){
			
			while( i < len && buff[i] == '5'){
				++i;
			}
			
			if(i >= len){
				break;
			}
			
			++ count;
			num[count] = 0;
			while( i < len && buff[i] != '5'){
				num[count] *= 10;
				num[count] += buff[i] - '0';
				++i;
			}
			
		}
		
		sort(num+1, num+1+count);
		
		printf("%d", num[1]);
		for(i = 2; i <= count; ++i){
			printf(" %d", num[i]);
		}
		printf("\n");
	}
	
	return 0;
}
