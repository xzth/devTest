//Largest prime factor
//Time Limit: 5000/1000 MS (Java/Others) Memory Limit: 32768/32768 K (Java/Others)
//Total Submission(s): 7251 Accepted Submission(s): 2202
//
//Problem Description
//Everybody knows any number can be combined by the prime number.
//Now, your task is telling me what position of the largest prime factor.
//The position of prime 2 is 1, prime 3 is 2, and prime 5 is 3, etc.
//Specially, LPF(1) = 0.
// 
//
//Input
//Each line will contain one integer n(0 < n < 1000000).
// 
//
//Output
//Output the LPF(n).
// 
//
//Sample Input
//
//1
//2
//3
//4
//5
//
// 
//
//Sample Output
//
//0
//1
//2
//1
//3
//
// 
//
//Author
//Wiskey
// 
//
//Source
//HDU 2007-11 Programming Contest_WarmUp
// 
//
//Recommend
//ÍþÊ¿¼É

#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

class PrimeList{
	int *plist;
	int length;
	
	void expand(){
		int *newlist = new int[2 * length];
		memset(newlist, 0, 2 * length * sizeof(int));
		memcpy(newlist, plist, length * sizeof(int));
		delete[] plist;
		plist = newlist;
	}
	
	public:
		PrimeList(){
			length = 100;
			plist = new int[100];
			memset(plist, 0, 100 * sizeof(int));
			plist[0] = 1;
			plist[1] = 2;
			plist[2] = 3;
		}
		~PrimeList(){
			delete[] plist;
		}
		
		bool isPrime(int n){
			
			if(n == 2){
				return true;
			}
			if(n < 2){
				return false;
			}
			if((n&1) == 0){
				return false;
			}
			
			int roof = (int)sqrt((double)n);
			int i = 2;
			while(plist[i] <= roof){
				if(n%plist[i] == 0){
					return false;
				}
				++i;
				if(i >= length){
					expand();
				}
				if(plist[i] == 0){
					int j;
					for(j = plist[i-1]+2; !isPrime(j); j+=2){}
					plist[i] = j;
				}
			}
			return true;
		}
		
		int getPrimePos(int n){
			
			if(n == 1){
				return 0;
			}
			
			int roof = (int)sqrt((double)n);
			int i = 1, max = 0;
			while(plist[i] <= roof){
				if(n%plist[i] == 0){
					max = getPrimePos(n / plist[i]);
					if(i > max){
						max = i;
					}
					return max;
				}
				++i;
				if(i >= length){
					expand();
				}
				if(plist[i] == 0){
					int j;
					for(j = plist[i-1]+2; !isPrime(j); j+=2){}
					plist[i] = j;
				}
			}
			
			while(plist[i] != n){
				++i;
				
				if(i >= length){
					expand();
				}
				if(plist[i] == 0){
					int j;
					for(j = plist[i-1]+2; !isPrime(j); j+=2){}
					plist[i] = j;
				}
			}
			return i;
		}
};

int main(){
	
	int n;
	
	PrimeList list;
	
	while(scanf("%d", &n) != EOF){
		printf("%d\n", list.getPrimePos(n));
//		printf("%d\n", list.isPrime(n));
	}
	
	return 0;
}
