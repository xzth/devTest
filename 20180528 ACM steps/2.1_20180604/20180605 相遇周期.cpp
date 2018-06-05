//Time Limit: 1000/1000 MS (Java/Others) Memory Limit: 32768/32768 K (Java/Others)
//Total Submission(s): 3890 Accepted Submission(s): 1802
//
//Problem Description
//2007年3月26日，在中俄两国元首的见证下，中国国家航天局局长孙来燕与俄罗斯联邦航天局局长别尔米诺夫共同签署了《中国国家航天局和俄罗斯联邦航天局关于联合探测火星-火卫一合作的协议》，确定中俄双方将于2009年联合对火星及其卫星“火卫一”进行探测。
//
//而卫星是进行这些探测的重要工具，我们的问题是已知两颗卫星的运行周期，求它们的相遇周期。
// 
//
//Input
//输入数据的第一行为一个正整数T, 表示测试数据的组数. 然后是T组测试数据. 每组测试数据包含两组正整数，用空格隔开。每组包含两个正整数，表示转n圈需要的天数(26501/6335，表示转26501圈要6335天)，用\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\'/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\'隔开。
// 
//
//Output
//
//            对于每组测试数据, 输出它们的相遇周期，如果相遇周期是整数则用整数表示，否则用最简分数表示。
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

