// Problem Description
// In the new year party, everybody will get a "special present".Now it's your turn to get your special present, a lot of presents now putting on the desk, and only one of them will be yours.Each present has a card number on it, and your present's card number will be the one that different from all the others, and you can assume that only one number appear odd times.For example, there are 5 present, and their card numbers are 1, 2, 3, 2, 1.so your present will be the one with the card number of 3, because 3 is the number that different from all the others.
 

// Input
// The input file will consist of several cases.
// Each case will be presented by an integer n (1<=n<1000000, and n is odd) at first. Following that, n positive integers will be given in a line, all integers will smaller than 2^31. These numbers indicate the card numbers of the presents.n = 0 ends the input.
 

// Output

//             For each case, output an integer in a line, which is the card number of your present.
 

// Sample Input

// 5
// 1 1 3 2 2
// 3
// 1 2 1
// 0

 

// Sample Output

// 3
// 2

// Hint
// Hint
 
// use scanf to avoid Time Limit Exceeded

#include <stdio.h>
#include <string.h>
using namespace std;

typedef struct {
    int num;
    int count;
} NODE, *PNODE;

int main(){
    int n, num;
    PNODE arr;

    while(true){
        scanf("%d", &n);
        if(!n){
            break;
        }

        arr = new NODE[n/2+1];
        memset(arr, 0, (n / 2 + 1) * sizeof(NODE));

        for(int i = 0; i < n; ++i){

            scanf("%d", &num);

            int j = 0;
            while(arr[j].num != num && arr[j].num != 0){
                ++j;
            }

            arr[j].num = num;
            ++arr[j].count;

        }

        int k = 0;
        while(arr[k].count > 1 ){
            ++k;
        }

        printf("%d\n", arr[k].num);
    }

    delete[] arr;
    return 0;
}