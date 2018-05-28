#include <iostream>
using namespace std;
#define maxN 30
void init_arr(int *arr, int N){
	for(int i=0;i<maxN;++i){
		if(i<N){
			arr[i]=1;
		}
		else{
			arr[i]=0;
		}
	}
}

void print_decomposition(int N, int stat_len, int *mut, int len, int &col){
	if(col%4==0){
		cout<<endl;
	}
	else{
		cout<<";";
	}
	cout<<N<<"=";
	for(int i=0;i<stat_len;++i){
		cout<<"1+";
	}
	for(int i=0;i<len-1;++i){
		cout<<mut[i]<<"+";
	}
	cout<<mut[len-1];
	++col;
}

void compute_decomposition(int N, int stat_len, int &col){
//initial matrix
	int volumn=N-stat_len;
	if(volumn==1){
		cout<<N<<"=";
		for(int i=0;i<stat_len;++i){
			cout<<"1+";
		}
		cout<<"1";
		++col;
		return ;
	}
	
//initial group
	int len = volumn/2;
	int mut[maxN/2];
	for(int i=0;i<maxN/2;++i){
		if(i<len){
			mut[i]=2;
		}
		else{
			mut[i]=0;
		}
	}
	mut[len-1]+=volumn%2;
	
//	
	while(true){
		print_decomposition(N,stat_len,mut,len,col);
		if(len==1){
			break;
		}
		if(mut[len-1]-mut[len-2]>1){
			--mut[len-1];
			++mut[len-2];
		}
		else{
			mut[len-2]+=mut[len-1];
			--len;
		}
	}
}

int main(){
	int arr[maxN];
	int N,col=0;
	cin>>N;
	
	init_arr(arr,N);
	for(int i=N-1;i>=0;--i){
		compute_decomposition(N,i,col);
	}
}
