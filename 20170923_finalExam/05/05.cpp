#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;
struct _case{
	int num;
	int n;
	int m;
}a[1002][502];
int main(){
	int n,m,k;
	int cost,dam;
	int _x,_y;
	cin>>n>>m>>k;
	memset(a,0,sizeof(a));
	for(int i=0;i<k;++i){
		cin>>cost>>dam;
		for(int x=n;x>=1;--x){
			_x=x-cost;
			for(int y=m;_x>=0&&y>=1;--y){
				_y=y-dam;
				if(_y>0){
					if(a[_x][_y].num+1>a[x][y].num){
						a[x][y].num=a[_x][_y].num+1;
						a[x][y].n=a[_x][_y].n+cost;
						a[x][y].m=a[_x][_y].m+dam;
					}
					if(a[_x][_y].num+1==a[x][y].num){
						if(a[_x][_y].m+dam<a[x][y].m){
							a[x][y].n=a[_x][_y].n+cost;
							a[x][y].m=a[_x][_y].m+dam;
						}
					}
				}
				
			}
		}
//		cout<<a[n][m].num<<" "<<n-a[n][m].n<<" "<<m-a[n][m].m<<endl;
//		cout<<"___________"<<endl;
	}
	cout<<a[n][m].num<<" "<<m-a[n][m].m;
}
