#include <stdio.h>
using namespace std;

int main(){
	unsigned long a,b;
	long c = 2;
	a = 0xffffffff;
	b = 2;
	printf("a>b : %d\n", a>b);
	printf("a>2 : %d\n", a>2);
	printf("a>c : %d\n", a>c);
	a = a + 2;
	printf("a>b : %d\n", a>b);
	printf("a>2 : %d\n", a>2);
	printf("a>c : %d\n", a>c);
	
	return 0;
}
