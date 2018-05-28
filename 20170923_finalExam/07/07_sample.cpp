#include <iostream>
#include <fstream>
using namespace std;  
   
/* 构造完成标志 */  
bool sign;  

/* 创建数独矩阵 */  
int num[10][9][9];  
   
/* 函数声明 */  
void Input(int t);  
void Output(int t);  
bool Check(int t, int n, int key);  
int DFS(int t, int n); 
int t; 
   
/* 主函数 */  
int main()  
{  
//    cout << "请输入一个9*9的数独矩阵，空位以0表示:" << endl;  
	cin>>t;
	for(int i=0;i<t;++i){
		sign=false;
		Input(i);  
    	DFS(i,0);  
	}
	cout<<endl;
	for(int i=0;i<t;++i){
		Output(i);  
	}
    
    system("pause");  
}  
   
/* 读入数独矩阵 */  
void Input(int t)  
{  
    char temp;  
    for (int i = 0; i < 9; i++)  
    {  
        for (int j = 0; j < 9; j++)  
        {  
            cin >> temp;  
            num[t][i][j] = temp - '0';  
        }  
    }  
}  
   
/* 输出数独矩阵 */  
void Output(int t)  
{  
//    cout << endl;  
    for (int i = 0; i < 9; i++)  
    {  
        for (int j = 0; j < 9; j++)  
        {  
            cout << num[t][i][j] ;  
//            if (j % 3 == 2)  
//            {  
//                cout << "   ";  
//            }  
        }  
        cout << endl;  
//        if (i % 3 == 2)  
//        {  
//            cout << endl;  
//        }  
    }  
}  
   
/* 判断key填入n时是否满足条件 */  
bool Check(int t, int n, int key)  
{  
    /* 判断n所在横列是否合法 */  
    for (int i = 0; i < 9; i++)  
    {  
        /* j为n竖坐标 */  
        int j = n / 9;  
        if (num[t][j][i] == key) return false;  
    }  
   
    /* 判断n所在竖列是否合法 */  
    for (int i = 0; i < 9; i++)  
    {  
        /* j为n横坐标 */  
        int j = n % 9;  
        if (num[t][i][j] == key) return false;  
    }  
   
    /* x为n所在的小九宫格左顶点竖坐标 */  
    int x = n / 9 / 3 * 3;  
   
    /* y为n所在的小九宫格左顶点横坐标 */  
    int y = n % 9 / 3 * 3;  
   
    /* 判断n所在的小九宫格是否合法 */  
    for (int i = x; i < x + 3; i++)  
    {  
        for (int j = y; j < y + 3; j++)  
        {  
            if (num[t][i][j] == key) return false;  
        }  
    }  
   
    /* 全部合法，返回正确 */  
    return true;  
}  
   
/* 深搜构造数独 */  
int DFS(int t, int n)  
{  
    /* 所有的都符合，退出递归 */  
    if (n > 80)  
    {  
        sign = true;  
        return 0;  
    }  
    /* 当前位不为空时跳过 */  
    if (num[t][n/9][n%9] != 0)  
    {  
        DFS(t,n+1);  
    }  
    else  
    {  
        /* 否则对当前位进行枚举测试 */  
        for (int i = 1; i <= 9; i++)  
        {  
            /* 满足条件时填入数字 */  
            if (Check(t, n, i) == true)  
            {  
                num[t][n/9][n%9] = i;  
                /* 继续搜索 */  
                DFS(t,n+1);  
                /* 返回时如果构造成功，则直接退出 */  
                if (sign == true) return 0;  
                /* 如果构造不成功，还原当前位 */  
                num[t][n/9][n%9] = 0;  
            }  
        }  
    }  
}
