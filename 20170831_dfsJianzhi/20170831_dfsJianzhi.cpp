#include <iostream>
#include <string.h>
#include <fstream>
#include <windows.h>
#define INF 1<<31
using namespace std;
int m,n,t;
int map[210][210],msmap[210][210][2];
int step,mstep;
int start[2];

void outpt(int x,int y){
	int sx,sy,ex,ey,blank=0; // 24 * 75
	sx=x-12;
	ex=x+11;
	sy=y-40;
	ey=y+34;
	if(sx<=0){
		ex-=sx-1;
		if(ex>m){
			blank=ex-m;
			ex=m;
		}
		sx=0;
	}
	if(ex>m){
		sx-=ex-m;
		ex=m;
		if(sx<1){
			blank=1-sx;
			sx=1;
		}
	}
	if(sy<1){
		ey+=1-sy;
		sy=1;
		if(ey>n) ey=n;
	}
	if(ey>n) ey=n;
//	cout<<"  ";
//	for(int i=1;i<=n;i++){
//		cout<<i%10;
//	}
//	cout<<endl<<" t = "<<t;
	for(int i=sx;i<=ex;++i){
//		cout<<i%10<<" ";
		cout<<endl;
		for(int j=sy;j<=ey;++j){
			if(i==x&&j==y){
				cout<<"@";
			}
			else if(map[i][j]==-1){
				cout<<"#";
			}
			else if(map[i][j]==0){
				cout<<" ";
			}
			else if(map[i][j]==1){
				cout<<"+";
			}
			else if(map[i][j]==-2147483648){
				cout<<"X";
			}
		}
	}
	while(blank>0){
		cout<<endl;
		--blank;
	}
//	Sleep(200);
	return ;
}

void dfs(int x,int y){
//	outpt(x,y);
	if(map[x][y]==1){
		if(step<mstep)
			mstep=step;
		cout<<mstep<<endl;
		return ;
	}
	if(t+map[x][y]<0){
		return ;
	}
	if(step>=mstep-1){
		return ;
	}
	if(step>msmap[x][y][0]&&t<=msmap[x][y][1]){
		return ;
	}
	msmap[x][y][0]=step;
	msmap[x][y][1]=t;
	++step;
	t+=map[x][y];
	
	dfs(x-1,y);
//	outpt(x,y);
	dfs(x+1,y);
//	outpt(x,y);
	dfs(x,y-1);
//	outpt(x,y);
	dfs(x,y+1);
//	outpt(x,y);
	
	t-=map[x][y];
	--step;
	
}

int main(){
	ifstream cin("in_.txt");
//	ofstream fout("out_.txt");
	char temp;
	memset(map,1<<7,sizeof(map));
	memset(msmap,1<<6,sizeof(msmap));
	cin>>m>>n>>t;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			cin>>temp;
			if(temp=='*') 
				map[i][j]=0;
			if(temp=='@'){
				map[i][j]=0;
				start[0]=i;
				start[1]=j;
			}
			if(temp=='+')
				map[i][j]=1;
			if(temp=='#')
				map[i][j]=-1;
		}
	}
	mstep=100000;
	step=0;
	dfs(start[0],start[1]);
	
	if(mstep==100000)
		cout<<-1<<endl;
	else
		cout<<mstep<<endl;
}
