#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
char s[6],e[6];
char dic[30][6];
int step[30],i;
queue <int> q;

bool word_cmp(char *w1,char *w2){
	int p=0;
	bool diff=false;
	while(w1[p]!=0){
		if(diff&&w1[p]!=w2[p]){
			return false;
		}
		if(w1[p]!=w2[p]){
			diff=true;
		}
		++p;
	}
	if(w1[p]==0&&diff){
		return true;
	}
	return false;
}

int bfs(){
	if(word_cmp(s,e)){
		return 2;
	}
	char *pre=s;
	int len=1;
	while(true){
		for(int j=0;j<=i;++j){
			if(step[j]==0){
				if(word_cmp(pre,dic[j])){
					if(word_cmp(dic[j],e)){
						return len+2;
					}
					step[j]=len+1;
					q.push(j);
				}
			}
		}
		if(q.empty()){
			break;
		}
		
		pre=dic[q.front()];
		len=step[q.front()];
		q.pop();
	}
	return 0;
}

int main(){
	cin>>s>>e;
	for(i=0;i<30;++i){
		cin>>dic[i];
		if(cin.peek()==10) break;
	}
	memset(step,0,sizeof(step));
	cout<<bfs();
}
