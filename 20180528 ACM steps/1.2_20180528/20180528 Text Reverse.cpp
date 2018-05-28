
// Problem Description
// Ignatius likes to write words in reverse way. Given a single line of text which is written by Ignatius, you should reverse all the words and then output them.
 

// Input
// The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.
// Each test case contains a single line with several words. There will be at most 1000 characters in a line.
 

// Output
// For each test case, you should output the text which is processed.
 

// Sample Input

// 3
// olleh !dlrow
// m'I morf .udh
// I ekil .mca

 

// Sample Output

// hello world!
// I'm from hdu.
// I like acm.

// Hint

// Remember to use getchar() to read '\n' after the interger T, then you may use gets() to read a line and process it.
 

 

// Author
// Ignatius.L

#include <stdio.h>
#include <string.h>
using namespace std;

void swap(char *c1, char *c2){
    char temp;
    temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}

void reverse(char *str, int len){
    for(int i=0; i<len/2; ++i){
        swap(str + i, str + len - 1 - i);
    }
}

int main(){
    int n;
    char line[1024];

    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; ++i){
        
        memset(line, '\0', 1024);
        gets(line);

        char *p1 = line, *p2 = line;
        while(*p1 != '\0'){
            
            int len = 0;
            while(*p2 != ' ' && *p2 != '\0'){
                ++p2;
                ++len;
            }
            
            reverse(p1, len);

            p1 = ++p2;

        }

        printf("%s\n", line);
    }

    return 0;
}
