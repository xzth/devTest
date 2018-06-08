//Largest prime factor
//Time Limit: 5000/1000 MS (Java/Others) Memory Limit: 32768/32768 K (Java/Others)
//Total Submission(s): 7251 Accepted Submission(s): 2202
//
//Problem Description
//Everybody knows any number can be combined by the prime number.
//Now, your task is telling me what position of the largest prime factor.
//The position of prime 2 is 1, prime 3 is 2, and prime 5 is 3, etc.
//Specially, LPF(1) = 0.
// 
//
//Input
//Each line will contain one integer n(0 < n < 1000000).
// 
//
//Output
//Output the LPF(n).
// 
//
//Sample Input
//
//1
//2
//3
//4
//5
//
// 
//
//Sample Output
//
//0
//1
//2
//1
//3
//
// 
//
//Author
//Wiskey
// 
//
//Source
//HDU 2007-11 Programming Contest_WarmUp
// 
//
//Recommend
//ÍþÊ¿¼É

#include <stdio.h>
#include <string.h>

using namespace std;

#define len 1000001

int main(){
	
	int n, pos = 1, list[len];
	
	memset(list, 0, len * sizeof(int));
	
	for(int i = 2; i < len; ++i){
		if(list[i] == 0){
			for(int j = i; j < len; j += i){
				list[j] = pos;
			}
			++pos;
		}
	}
	
	while(scanf("%d", &n) != EOF){
		printf("%d\n", list[n]);
	}
	
	return 0;
	
}
