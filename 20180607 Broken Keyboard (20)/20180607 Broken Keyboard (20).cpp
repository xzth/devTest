//
//Broken Keyboard (20)
//
//时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
//题目描述
//
//On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters 
//
//corresponding to those keys will not appear on screen.
//
//
//
//Now given a string that you are supposed to type, and the string that you actually type out, please list those keys 
//
//which are for sure worn out.
//
//
//输入描述:
//
//Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string. Each string contains 
//
//no more than 80 characters which are either English letters [A-Z] (case 
//
//insensitive), digital numbers [0-9], or "_" (representing the space). It is guaranteed that both strings are non-empty.
//
//
//
//输出描述:
//
//For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. 
//
//Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key.
//
//
//输入例子:
//
//7_This_is_a_test
//
//_hs_s_a_es
//
//
//输出例子:
//
//7TI
//



#include <stdio.h>
#include <string.h>
using namespace std;

char c2upper(char a){
    if(a >= 'a' && a <= 'z'){
        a -= 'a' - 'A';
    }
    return a;
}

bool cmp(char a, char b){
	return c2upper(a) == c2upper(b);
}

int main(){
	const int len = 100;
	
    char str1[len], str2[len], str3[len];
    memset(str1, 0, len);
    memset(str2, 0, len);
    int cnt = 0;
    scanf("%s%s", str1, str2);
    
    char *p1 = str1, *p2 = str2, *p3 = str3;
    while(*p1 || *p2){
        while(*p1 != *p2){
            *p3 = *p1;
            ++p1;
            ++p3;
            ++cnt;
        }
        ++p1;
        ++p2;
    }
    
    for(int i = 0; i < cnt; ++i){
        if(str3[i] != 0){
            printf("%c", c2upper(str3[i]));
            for(int j = i+1; j < cnt; ++j){
                if(cmp(str3[j], str3[i])){
                    str3[j] = 0;
                }
            }
        }
    }
    printf("\n");
    
    return 0;
}
