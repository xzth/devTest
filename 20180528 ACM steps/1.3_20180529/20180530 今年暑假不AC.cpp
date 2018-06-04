//Problem Description
//��������ٲ�AC����
//���ǵġ���
//�������ʲô�أ���
//�������籭ѽ����������
//��@#$%^&*%...��
//
//ȷʵ��ˣ����籭���ˣ����ԵĽ���Ҳ���ˣ����ƺܶ�ACMerҲ���׿����ԣ���������ˡ�
//��Ϊ���ԣ�һ���뿴������������ı�������Ȼ����Ϊ��ʱ���ĺ����꣬��һ�����ῴһЩ�����Ľ�Ŀ������������������Զ��Ҫ���ǹ��Ĺ��Ҵ��£����ǳ�6+7������Ů�����Լ���СѾ�ġ����Ĵǵ䡷�ȵȣ��������Ѿ�֪����������ϲ�����ĵ��ӽ�Ŀ��ת��ʱ������������𣿣�Ŀ�����ܿ��������������Ŀ��
// 
//
//Input
//�������ݰ����������ʵ����ÿ������ʵ���ĵ�һ��ֻ��һ������n(n<=100)����ʾ��ϲ�����Ľ�Ŀ��������Ȼ����n�����ݣ�ÿ�а�����������Ti_s,Ti_e (1<=i<=n)���ֱ��ʾ��i����Ŀ�Ŀ�ʼ�ͽ���ʱ�䣬Ϊ�˼����⣬ÿ��ʱ�䶼��һ����������ʾ��n=0��ʾ�����������������
// 
//
//Output
//����ÿ������ʵ������������������ĵ��ӽ�Ŀ�ĸ�����ÿ������ʵ�������ռһ�С�
// 
//
//Sample Input
//
//12
//1 3
//3 4
//0 7
//3 8
//15 19
//15 20
//10 15
//8 18
//6 12
//5 10
//4 14
//2 9
//0
//
// 
//
//Sample Output
//
//5
//
// 
//
//Author
//lcy
// 
//
//Source
//ACM���������ĩ���ԣ�2006/06/07��
// 
//
//Recommend
//lcy


//
//
// HINTs ::check whether array indexes are legal before they're used in if() condition
// 
//   

#include <stdio.h>
#include <algorithm>
using namespace std;

int *ts, *te, *indx;
	
bool cmp(int a, int b){
	return ts[a] < ts[b];
}

int main(){
	
	int n, *count, max_te = 0;
	
	while(scanf("%d", &n) && n != 0){
		
		ts = new int[n];
		te = new int[n];
		indx = new int[n];
		
		for(int i = 0; i < n; ++i){
			scanf("%d %d", &ts[i], &te[i]);
			indx[i] = i;
			if(te[i] > max_te){
				max_te = te[i];
			}
		}
		
		sort(indx, indx + n, cmp);
		
		count = new int[max_te + 1];
		
		count[max_te] = 0;
		
		int cur_indx = n - 1;
		
		for(int i = max_te - 1; i >= 0; --i){
			int max_count = count[i + 1], cur_count;
			while(cur_indx >= 0 && ts[indx[cur_indx]] >= i){
				cur_count = 1 + count[te[indx[cur_indx]]];
				if(cur_count > max_count){
					max_count = cur_count;
				}
				--cur_indx;
			}
			count[i] = max_count;
		}
		
		printf("%d\n", count[0]);
		
		delete[] ts;
		delete[] te;
		delete[] indx;
		delete[] count;
	}
	
	return 0;
}
