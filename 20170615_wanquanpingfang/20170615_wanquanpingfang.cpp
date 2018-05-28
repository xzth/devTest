#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
				
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
		cnt++;
	}
    printf("cnt = %d\n", cnt);

    return 0;
}


int IsTheNumber ( const int N ){
	if(N==0){
		return 0;
	}
	int a = pow(N,0.5);
	
	if(N%a==0&&N/a==a){
		
		int b,arr[10]={0,0,0,0,0,0,0,0,0,0};
		int test=N;
		
		while(test){
			b=test%10;
			
		//	cout<<test<<" "<<b<<" "<<arr[b]<<"\n";
			if(arr[b]==1){
		//		cout<<"return 1\n";
				return 1;
			}
			else{
				arr[b]=1;
			}
			test/=10;
		}
	//	cout<<"return 0\n";
		
	}
	return 0;
}


