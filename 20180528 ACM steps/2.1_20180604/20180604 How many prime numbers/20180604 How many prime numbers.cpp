//Problem Description
//Give you a lot of positive integers, just to find out how many prime numbers there are.
// 
//
//Input
//There are a lot of cases. In each case, there is an integer N representing the number of integers to find. Each integer won¡¯t exceed 32-bit signed integer, and each of them won¡¯t be less than 2.
// 
//
//Output
//
//            For each case, print the number of prime numbers you have found out.
// 
//
//Sample Input
//
//3
//2 3 4
//
// 
//
//Sample Output
//
//2
//
// 
//
//Author
//wangye
// 
//
//Source
//HDU 2007-11 Programming Contest_WarmUp
// 
//
//Recommend
//ÍþÊ¿¼É




#include <stdio.h>

#include<time.h>

using namespace std;

template<class T>
class PrimeListNode {
	T value;
	PrimeListNode* next;
	
	public:
		PrimeListNode(){
			value = 2;
			next = NULL;
		}
		PrimeListNode(T _value){
			value = _value;
			next = NULL;
		}
		
		void append(T _value){
			PrimeListNode* node = new PrimeListNode(_value);
			node->next = next;
			next = node;
		}
		T getValue(){
			return value;
		}
		PrimeListNode* Mov(){
			return next;
		}
};


template<class T>
class PrimeList{
	PrimeListNode<T> primeList;
	
	public:
		~PrimeList(){
			PrimeListNode<T> *tmp, *p = primeList.Mov();
			while(p != NULL){
				tmp = p;
				p = p->Mov();
				delete tmp;
			}
		}
		
		bool isPrime(T n){
			
			if(n <= 1){
				return false;
			}
			
			if(n == 2){
				return true;
			}
			
			PrimeListNode<T>* p = &primeList;
			T i = p->getValue();
			while(i*i <= n){
				
				if(n%i == 0){
					return false;
				}
				
				if(p->Mov()){
					p = p->Mov();
					i = p->getValue();
				}
				else{
					
					while(!isPrime(++i)){}
					p->append(i);
					p = p->Mov();
					
				}
			}
			
			return true;
		}
};


int main(){
	
	PrimeList<int> list;
	
	int n, tmp, count;
	clock_t ts, te;
	
	while(scanf("%d", &n) != EOF){
		
		ts = clock();
		
		count = 0;
		
		for(int i = 0; i < n; ++i){
			scanf("%d", &tmp);
			if(list.isPrime(tmp)){
				++count;
			}
		}
		
		te = clock();
		
		printf("%d in %ld ms \n", count, te - ts);
		
	}
	return 0;
	
}
