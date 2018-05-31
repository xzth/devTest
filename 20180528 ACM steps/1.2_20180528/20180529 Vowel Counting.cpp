//Problem Description
//The "Vowel-Counting-Word"(VCW), complies with the following conditions.
//Each vowel in the word must be uppercase.
//Each consonant (the letters except the vowels) must be lowercase.
//For example, "ApplE" is the VCW of "aPPle", "jUhUA" is the VCW of "Juhua".
//Give you some words; your task is to get the "Vowel-Counting-Word" of each word.
// 
//
//Input
//The first line of the input contains an integer T (T<=20) which means the number of test cases.
//For each case, there is a line contains the word (only contains uppercase and lowercase). The length of the word is not greater than 50.
// 
//
//Output
//For each case, output its Vowel-Counting-Word.
// 
//
//Sample Input
//
//4
//XYz
//application
//qwcvb
//aeioOa 
//
// 
//
//Sample Output
//
//xyz
//ApplIcAtIOn
//qwcvb
//AEIOOA
//
// 
//
//Author
//AppleMan
// 
//
//Source
//HDU 2nd ¡°Vegetable-Birds Cup¡± Programming Open Contest
// 
//
//Recommend
//lcy

#include <stdio.h>
using namespace std;

bool is2Tog(char c){
	static char arrlow[] = {'a', 'e', 'i', 'o', 'u'};
	static char arrHigh[] = {'A', 'E', 'I', 'O', 'U'};
	
	if(c <= 'z' && c >= 'a'){
		for(int i = 0; i < 5; ++i){
			if(c == arrlow[i]){
				return true;
			}
		}
	}
	else if(c <= 'Z' && c>= 'A'){
		for(int i = 0; i < 5; ++i){
			if(c == arrHigh[i]){
				return false;
			}
		}
		return true;
	}
	
	return false;
}

void tog(char * c){
	if(!is2Tog(*c)){
		return;
	}
	
	if(*c <= 'Z'){
		*c += 'z' - 'Z';
	}
	else{
		*c -= 'z' - 'Z';
	}
}

int main(){
	
	int n;
	
	char c;
	
	scanf("%d", &n);
	getchar();
	
	for(int i = 0; i < n; ++i){
		
		do{
			scanf("%c", &c);
			tog(&c);
			printf("%c", c);
		} while( c != '\n');
		
	}
	
	return 0;
}
