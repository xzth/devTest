#include <iostream>
#include <fstream>
using namespace std;  
   
/* ������ɱ�־ */  
bool sign;  

/* ������������ */  
int num[10][9][9];  
   
/* �������� */  
void Input(int t);  
void Output(int t);  
bool Check(int t, int n, int key);  
int DFS(int t, int n); 
int t; 
   
/* ������ */  
int main()  
{  
//    cout << "������һ��9*9���������󣬿�λ��0��ʾ:" << endl;  
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
   
/* ������������ */  
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
   
/* ����������� */  
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
   
/* �ж�key����nʱ�Ƿ��������� */  
bool Check(int t, int n, int key)  
{  
    /* �ж�n���ں����Ƿ�Ϸ� */  
    for (int i = 0; i < 9; i++)  
    {  
        /* jΪn������ */  
        int j = n / 9;  
        if (num[t][j][i] == key) return false;  
    }  
   
    /* �ж�n���������Ƿ�Ϸ� */  
    for (int i = 0; i < 9; i++)  
    {  
        /* jΪn������ */  
        int j = n % 9;  
        if (num[t][i][j] == key) return false;  
    }  
   
    /* xΪn���ڵ�С�Ź����󶥵������� */  
    int x = n / 9 / 3 * 3;  
   
    /* yΪn���ڵ�С�Ź����󶥵������ */  
    int y = n % 9 / 3 * 3;  
   
    /* �ж�n���ڵ�С�Ź����Ƿ�Ϸ� */  
    for (int i = x; i < x + 3; i++)  
    {  
        for (int j = y; j < y + 3; j++)  
        {  
            if (num[t][i][j] == key) return false;  
        }  
    }  
   
    /* ȫ���Ϸ���������ȷ */  
    return true;  
}  
   
/* ���ѹ������� */  
int DFS(int t, int n)  
{  
    /* ���еĶ����ϣ��˳��ݹ� */  
    if (n > 80)  
    {  
        sign = true;  
        return 0;  
    }  
    /* ��ǰλ��Ϊ��ʱ���� */  
    if (num[t][n/9][n%9] != 0)  
    {  
        DFS(t,n+1);  
    }  
    else  
    {  
        /* ����Ե�ǰλ����ö�ٲ��� */  
        for (int i = 1; i <= 9; i++)  
        {  
            /* ��������ʱ�������� */  
            if (Check(t, n, i) == true)  
            {  
                num[t][n/9][n%9] = i;  
                /* �������� */  
                DFS(t,n+1);  
                /* ����ʱ�������ɹ�����ֱ���˳� */  
                if (sign == true) return 0;  
                /* ������첻�ɹ�����ԭ��ǰλ */  
                num[t][n/9][n%9] = 0;  
            }  
        }  
    }  
}
