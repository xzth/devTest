//Problem Description
//Uniform Resource Identifiers (or URIs) are strings like http://icpc.baylor.edu/icpc/, mailto:foo@bar.org, ftp://127.0.0.1/pub/linux, or even just readme.txt that are used to identify a resource, usually on the Internet or a local computer. Certain characters are reserved within URIs, and if a reserved character is part of an identifier then it must be percent-encoded by replacing it with a percent sign followed by two hexadecimal digits representing the ASCII code of the character. A table of seven reserved characters and their encodings is shown below. Your job is to write a program that can percent-encode a string of characters.
//
//Character  Encoding
//" " (space)  %20
//"!" (exclamation point)  %21
//"$" (dollar sign)  %24
//"%" (percent sign)  %25
//"(" (left parenthesis)  %28
//")" (right parenthesis)  %29
//"*" (asterisk)  %2a
// 
//
//Input
//The input consists of one or more strings, each 1�C79 characters long and on a line by itself, followed by a line containing only "#" that signals the end of the input. The character "#" is used only as an end-of-input marker and will not appear anywhere else in the input. A string may contain spaces, but not at the beginning or end of the string, and there will never be two or more consecutive spaces.
// 
//
//Output
//For each input string, replace every occurrence of a reserved character in the table above by its percent-encoding, exactly as shown, and output the resulting string on a line by itself. Note that the percent-encoding for an asterisk is %2a (with a lowercase "a") rather than %2A (with an uppercase "A").
// 
//
//Sample Input
//
//Happy Joy Joy!
//http://icpc.baylor.edu/icpc/
//plain_vanilla
//(**)
//?
//the 7% solution
//#
//
// 
//
//Sample Output
//
//Happy%20Joy%20Joy%21
//http://icpc.baylor.edu/icpc/
//plain_vanilla
//%28%2a%2a%29
//?
//the%207%25%20solution
//
// 
//
//Source
//Mid-Central USA 2007
// 
//
//Recommend
//teddy

#include <stdio.h>
#include <string.h>
using namespace std;

char code[7][5] = {"%20", "%21", "%24", "%25", "%28", "%29", "%2a"};
char word[7] = {' ', '!', '$', '%', '(', ')', '*'};

void peprint(char c){
	for(int i = 0; i < 7; ++i){
		if(c == word[i]){
			printf("%s", code[i]);
			return;
		}
	}
	printf("%c", c);
}

int main(){
    
    char c;
    
    while(true){
    	c = getchar();
    	if(c == '#'){
    		break;
		}
    	peprint(c);
	}

    return 0;
}
