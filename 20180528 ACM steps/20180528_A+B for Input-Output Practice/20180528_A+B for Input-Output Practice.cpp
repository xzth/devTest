#include <stdio.h>
using namespace std;

void main1(){

    int a,b;

    while(scanf("%d %d", &a, &b) != EOF){
        printf("%d\n", a + b);
    }

}

void main2(){

    int a, b, n;

    scanf("%d", &n);

    int *res = new int[n];

    for(int i = 0; i < n; ++i){
        scanf("%d %d", &a, &b);
        res[i] = a + b;
    }

    for(int i = 0; i < n; ++i){
        printf("%d\n", res[i]);
    }

    delete[] res;
}

void main3(){

    int a, b;

    do{
        scanf("%d %d", &a, &b); 
        if(a == 0 && b == 0){
            break;
        }
        printf("%d\n", a + b);
    } while(1);
}

void main4(){

    int n, a, sum;

    while(1){
        scanf("%d", &n);
        if(!n){
            break;
        }

        sum = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d", &a);
            sum += a;
        }
        printf("%d\n", sum);
    }
}

void main5(){
    int n1, n2, a, sum;

    scanf("%d", &n1);

    for(int i = 0; i < n1; ++i){
        scanf("%d", &n2);
        sum = 0;

        for(int j = 0; j < n2; ++j){
            scanf("%d", &a);
            sum += a;
        }

        printf("%d\n", sum);
    }
}

void main6(){

    int n, a, sum;

    while(scanf("%d", &n) != EOF){
        
        sum = 0;
        
        for(int i=0; i<n; ++i){
            scanf("%d", &a);
            sum += a;
        }
        printf("%d\n", sum);

    }

}

void main7(){

    int a,b;

    while(scanf("%d %d", &a, &b) != EOF){
        printf("%d\n\n", a + b);
    }

}

void main8(){
    int n1, n2, a, sum, i = 0;

    scanf("%d", &n1);

    while(1){
        scanf("%d", &n2);
        sum = 0;

        for(int j = 0; j < n2; ++j){
            scanf("%d", &a);
            sum += a;
        }

        printf("%d\n", sum);

        if(++i == n1){
            break;
        }

        printf("\n");
    }
}


int main(){

    // main1();

    // main2();

    // main3();

    // main4();

    // main5();

    // main6();

    // main7();

    main8();

    return 0;
}