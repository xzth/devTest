#include <iostream>
using namespace std;

#define MAXLEN 50
typedef int KeyType;

typedef  struct                     
{ KeyType  key;                                             
} elementType;  

typedef  struct
{ elementType   data[MAXLEN+1]; 
  int   len;
} SeqList;                      

void creat(SeqList &L)
{ int i;
  cin>>L.len;
  for(i=1;i<=L.len;i++)
     cin>>L.data[i].key;   
}

int  binSearch(SeqList T, KeyType k);

int main () 
{  SeqList L;  KeyType k;
   creat(L);
   cin>>k;
   int pos=binSearch(L,k);
   if(pos==0) cout<<"NOT FOUND"<<endl;
   else cout<<pos<<endl;
   return 0;
}

void memcpy(elementType* dest, elementType* src, int len){
	for(int i=0;i<len;++i){
		dest[i].key=src[i].key;
	}
}

int  binSearch(SeqList T, KeyType k){
	int L=T.len;
	int MID=(L+1)/2;
	if(T.len==1&&T.data[1].key!=k){
		return 0;
	}
	if(T.data[MID].key==k){
		return MID;
	}
	if(k>T.data[L/2].key){
		T.len/=2;
		memcpy(T.data+1,T.data+MID+1,T.len);
//		T.data=&(T.data[MID+1]);
		int temp = binSearch(T,k);
		if(!temp){return 0;
		}
		return MID+temp;
	}
	else{
		T.len/=2;
		return binSearch(T,k);
	}
}
