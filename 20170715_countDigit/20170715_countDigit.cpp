#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
				
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

int Count_Digit ( const int N, const int D ){
	if(N==0&&D==0)return 1;
    int count=0;
    for(int i=((N<0)?(~(N-1)):N);i>0;i/=10){
        if(i%10==D)
        	++count;
    }
    return count;
}
