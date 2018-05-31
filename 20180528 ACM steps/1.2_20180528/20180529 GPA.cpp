//
//Problem Description
//Each course grade is one of the following five letters: A, B, C, D, and F. (Note that there is no grade E.) The grade A indicates superior achievement , whereas F stands for failure. In order to calculate the GPA, the letter grades A, B, C, D, and F are assigned the following grade points, respectively: 4, 3, 2, 1, and 0.
// 
//
//Input
//The input file will contain data for one or more test cases, one test case per line. On each line there will be one or more upper case letters, separated by blank spaces.
// 
//
//Output
//Each line of input will result in exactly one line of output. If all upper case letters on a particular line of input came from the set {A, B, C, D, F} then the output will consist of the GPA, displayed with a precision of two decimal places. Otherwise, the message "Unknown letter grade in input" will be printed.
// 
//
//Sample Input
//
//A B C D F
//B F F C C A
//D C E F
//
// 
//
//Sample Output
//
//2.00
//1.83
//Unknown letter grade in input
//
// 
//
//Author
//2006Rocky Mountain Warmup
// 
//
//Source
//HDU ¡°Valentines Day¡± Open Programming Contest 2009-02-14
// 
//
//Recommend
//lcy


#include <stdio.h>
using namespace std;

int main(){
	
	char c;
	
	int count;
	float sum;
	
	sum = 0;
	count = 0;
	
	while(scanf("%c", &c) != EOF){
		
		if(sum != -1){
			if(c <= 'D' && c >= 'A'){
				sum += 4 - c + 'A';
			}
			else if( c != 'F'){
				sum = -1;
			}
		}
		
		count++;
		
		scanf("%c", &c);
		
		if(c == '\n'){
			if(sum == -1){
				printf("Unknown letter grade in input\n");
			}
			else{
				printf("%.2f\n", sum / count);
			}
			sum = 0;
			count = 0;
		}
	}
	
	
	return 0;
}
