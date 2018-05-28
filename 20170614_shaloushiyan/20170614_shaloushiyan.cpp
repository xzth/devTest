#include <iostream>
#include <string>
using namespace std;

void type_sym(int row,int row_sum,char sym)
	{
		int sym_num = row*2+1;
		int sym_sum = row_sum*2-1;
		int blank_num = (sym_sum-sym_num)/2;
		
		for(int i=0;i<blank_num;i++){
			cout<<" ";
		}
		for(int i=0;i<sym_num;i++){
			cout<<sym;
		}
		cout<<"\n";
	}

int main(){
	int num;
	char symb;
	cout<<"input number and symbol: ";
	cin>>num>>symb;
	
	int i,sum=0;
	for(i=1;true;i++){
		int temp=0;
		for(int j=0;j<i;j++){
			temp += 1+2*j;
		}
		temp = temp*2-1;
		if(temp>num){
			break;
		}
		sum = temp;
	}
	
	int row_num = i-1;
//	cout<<"\n"<<"sum = "<<sum;
//	cout<<"\n"<<"row number = "<<row_num;
	for(int i=0;i<row_num*2-1;i++){
		if(i<row_num){
			type_sym(row_num-i-1,row_num,symb);
		}
		else{
			type_sym(i-row_num+1,row_num,symb);
		}
	}
	cout<<num-sum;
}
