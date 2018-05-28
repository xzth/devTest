#include <iostream>
#include <string.h>

using namespace std;
struct route_node{
	char word[6];
	int step;
}route[35];
int rhead=0,rtail=1;

struct dic_node{
	char word[6];
	dic_node* next;
}dhead;
dic_node* dp=&dhead;
char s[6],e[6];

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

void del_dnode(){
	dic_node* temp=dp->next;
	dp->next=dp->next->next;
	delete temp;
}

bool get_neighbor(){
	dp=&dhead;
	while(dp->next!=NULL){
		if(word_cmp(dp->next->word,route[rhead].word)){
			strcpy(route[rtail].word,dp->next->word);
			route[rtail].step=route[rhead].step+1;
			if(word_cmp(e,route[rtail].word)){
				return true;
			}
			++rtail;
			del_dnode();
		}
		else{
			dp=dp->next;
		}
	}
	++rhead;
	return false;
}

bool bfs(){
	if(word_cmp(s,e)){
		rtail=rhead;
		return true;
	}
	while(rtail!=rhead){
		if(get_neighbor()){
			return true;
		}
	}
	return false;
}

int main(){
	cin>>s>>e;
	while(true){
		dp->next=new dic_node;
		dp=dp->next;
		cin>>dp->word;
		if(cin.peek()==10) break;
	}
	dp->next=NULL;
	dp=dhead.next;
	strcpy(route[0].word,s);
	route[0].step=1;
	if(bfs()){
		cout<<route[rtail].step+1;
	}
	else{
		cout<<0;
	}
//	cout<<"end!";
}
