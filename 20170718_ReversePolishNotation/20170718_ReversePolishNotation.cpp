#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

double exp() { 
  char s[20];    
  cin >> s; 
  switch(s[0]) { 
    case '+':  return exp()+exp();
    case '-':  return exp()-exp();
    case '*':  return exp()*exp();
    case '/':  return exp()/exp();
    default:   return atof(s); 
    break; 
  } 
} 

int main(){
//	cout<<"hello world!"<<endl;
//	char a[] = {'5'};
//	cout<<atof(a)+5<<endl;

	printf("%lf",exp()); 
  	return 0;
}
