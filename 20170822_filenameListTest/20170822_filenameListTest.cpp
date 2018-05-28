#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <io.h>
using namespace std;

//const char *to_search="S:\\WINDOWS\\*.exe";        //欲查找的文件，支持通配符
const char *to_search="*?.?*"; 

struct _files{
	char name[1000];
	time_t time;
};

void _merge(struct _files *f,struct _files *temp,int s,int mid,int e){
	int p1=s,p2=mid,pt=s;
	while(p1!=mid&&p2!=e+1){
		if(f[p1].time>f[p2].time){
			strcpy(temp[pt].name,f[p2].name);
			temp[pt++].time=f[p2++].time;
		}
		else{
			strcpy(temp[pt].name,f[p1].name);
			temp[pt++].time=f[p1++].time;
		}
	}
	while(p1!=mid){
		strcpy(temp[pt].name,f[p1].name);
		temp[pt++].time=f[p1++].time;
	}
	while(p2!=e+1){
		strcpy(temp[pt].name,f[p2].name);
		temp[pt++].time=f[p2++].time;
	}
	pt=s;
	while(pt<=e){
		strcpy(f[pt].name,temp[pt].name);
		f[pt].time=temp[pt++].time;
	}
}

void _ascend(struct _files *f,struct _files *temp,int s,int e){
	if(s==e){
		return ;
	}
	int mid = (s+e)/2+(s+e)%2;
	_ascend(f,temp,s,mid-1);
	_ascend(f,temp,mid,e);
	_merge(f,temp,s,mid,e);
}

void edit_name(char *name,int index){
	char *p=name+strlen(name);
	while(*(--p)!='.'){}
	char newname[10]="0000";
//	cout<<"index: "<<index<<endl;
	for(int i=0;i<4&&index>0;++i){
		newname[3-i]+=index%10;
		index/=10;
	}
	strcat(newname,p);
	cout<<"new file name : "<<newname<<endl;
	
	if(!_access(name,0))//如果文件存在:
	{
		if(!rename(name,newname))//删除成功
		{
		   cout<<"rename action successful ! "<<endl;
		}
		else//无法重命名:文件打开或无权限执行重命名
		{
		   cout<<"rename failed probably because :"<<endl;
		   cout<<"1. \""<<newname<<"\" already exists"<<endl
		    <<"2. \""<<newname<<"\" is opened now"<<endl
		    <<"3. \""<<"\" action is not authorized"<<endl;
		}
	}
}

int main(int argc,char *argv[])
{
	char   path_buffer[_MAX_PATH]; 
    char   drive[_MAX_DRIVE]; 
    char   dir[_MAX_DIR]; 
    char   fname[_MAX_FNAME]; 
    char   ext[_MAX_EXT];   
	
	_splitpath(argv[0], drive, dir, fname, ext);
    strcat(fname,ext);
//    cout<<fname<<endl;
	
	struct _files f[500],t[500];
	int count=0;
	
    long handle;                                                //用于查找的句柄
    struct _finddata_t fileinfo;                          //文件信息的结构体
    handle=_findfirst(to_search,&fileinfo);         //第一次查找
    if(-1==handle)return -1;                      //打印出找到的文件的文件名
    if(strcmp(fileinfo.name,"..")!=0&&strcmp(fileinfo.name,".")!=0
	&&strcmp(fileinfo.name,fname)!=0&&fileinfo.attrib==32){
    	 ++count;
    	 strcpy(f[count].name,fileinfo.name);
    	 f[count].time=fileinfo.time_write;
	}
//	cout<<fileinfo.name<<endl;
//    cout<<fileinfo.time_write<<endl;
//    cout<<fileinfo.attrib<<endl;
//    cout<<"---------"<<endl;
    while(!_findnext(handle,&fileinfo))               //循环查找其他符合的文件，知道找不到其他的为止
    {
//          printf("%s\n",fileinfo.name);
		if(strcmp(fileinfo.name,"..")!=0&&strcmp(fileinfo.name,".")!=0
		&&strcmp(fileinfo.name,fname)!=0&&fileinfo.attrib==32){
	    	 ++count;
	    	 strcpy(f[count].name,fileinfo.name);
	    	 f[count].time=fileinfo.time_write;
		}
//		cout<<fileinfo.name<<endl;
//		cout<<fileinfo.time_write<<endl;
//		cout<<fileinfo.attrib<<endl;
//		cout<<"---------"<<endl;
	}
    _findclose(handle);                                      //别忘了关闭句柄
    _ascend(f,t,1,count);
	for(int i=1;i<=count;++i){
		cout<<"latest write time : ";
		cout<<asctime(localtime(&f[i].time));
		cout<<"original file name : "<<f[i].name<<endl;
		edit_name(f[i].name,i);
		cout<<"----------"<<endl;
	}
	cin.get();
	return 0;
}
