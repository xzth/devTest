#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;
int dx[]={1,2,-1,-2,1,2,-1,-2};
int dy[]={2,1,-2,-1,-2,-1,2,1};
bool state[11][11];
int count,step;
int m,n,x,y;
int result[10];

void dfs(int _x,int _y){
	++step;
//	cout<<_x<<" , "<<_y<<endl;
	state[_x][_y]=true;
	int x,y;
	for(int i=0;i<8;++i){
		x=_x+dx[i];
		y=_y+dy[i];
		if(!state[x][y]&&x>=0&&x<m&&y>=0&&y<n){
			if(step==m*n-1){
				++count;
				--step;
				state[_x][_y]=false;
				return ;
			}
			dfs(x,y);
		}
	}
	--step;
	state[_x][_y]=false;
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;++i){
		cin>>m>>n>>x>>y;
		memset(state,0,sizeof(state));
		count=0;
		step=0;
		dfs(x,y);
		result[i]=count;
	}
	for(int i=0;i<t;++i){
		cout<<result[i]<<endl;
	}
}
