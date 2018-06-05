//Time Limit: 1000/1000 MS (Java/Others) Memory Limit: 32768/32768 K (Java/Others)
//Total Submission(s): 3890 Accepted Submission(s): 1802
//
//Problem Description
//2007��3��26�գ����ж�����Ԫ�׵ļ�֤�£��й����Һ���־ֳ������������˹�����־ֳ������ŵ��ͬǩ���ˡ��й����Һ���ֺͶ���˹�����ֹ�������̽�����-����һ������Э�顷��ȷ���ж�˫������2009�����϶Ի��Ǽ������ǡ�����һ������̽�⡣
//
//�������ǽ�����Щ̽�����Ҫ���ߣ����ǵ���������֪�������ǵ��������ڣ������ǵ��������ڡ�
// 
//
//Input
//�������ݵĵ�һ��Ϊһ��������T, ��ʾ�������ݵ�����. Ȼ����T���������. ÿ��������ݰ����������������ÿո������ÿ�������������������ʾתnȦ��Ҫ������(26501/6335����ʾת26501ȦҪ6335��)����\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\'/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\'������
// 
//
//Output
//
//            ����ÿ���������, ������ǵ��������ڣ����������������������������ʾ����������������ʾ��
// 
//
//Sample Input
//
//2
//26501/6335 18468/42
//29359/11479 15725/19170
//
// 
//
//Sample Output
//
//81570078/7
//5431415
//
// 
//
//Source
//HDU 2007-Spring Programming Contest
// 
//
//Recommend
//lcy


///HINTS:
///
///// USE ULONGLONG TYPE INTEGER

#include <stdio.h>

using namespace std;

typedef unsigned long long ULL;

template<class T>
T gcd(T a, T b){
	T rem;
	while(rem = a%b){
		a = b;
		b = rem;
	}
	return b;
}

template<class T>
T reduce(T &cnt, T &day){
	T g = gcd<T>(cnt, day);
	cnt /= g;
	day /= g;
	return g;
}

int main(){
	
	int n;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i){
		ULL cnt1, cnt2, day1, day2;
		scanf("%lld/%lld %lld/%lld", &cnt1, &day1, &cnt2, &day2);
		
		reduce<ULL>(cnt1, day1);
		reduce<ULL>(cnt2, day2);
		
		ULL gday = gcd<ULL>(day1, day2);
		ULL gcnt = gcd<ULL>(cnt1, cnt2);
		
		ULL upper, lower;
		
		lower = gday * gcnt;
		upper = cnt1 * cnt2;
		
		reduce<ULL>(upper, lower);
		
		printf("%lld", upper);
		if(lower > 1){
			printf("/%lld", lower);
		}
		printf("\n");
	}
	
	return 0;
}

