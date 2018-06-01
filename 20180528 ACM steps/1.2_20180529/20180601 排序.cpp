//Problem Description
//����һ�����֣�������ǰ����������еġ�5�������ɿո���ô�͵õ�һ���ÿո�ָ�����ɷǸ�������������Щ�����ԡ�0����ͷ����Щͷ���ġ�0��Ӧ�ñ����Ե�����������������������ɸ���0����ɵģ���ʱ�����������0����
//
//��������ǣ�����Щ�ָ�õ�������������С�����˳�����������
//
// 
//
//Input
//��������������������ÿ����������ֻ��һ�����֣�����֮��û�пո񣩣��������ֵĳ��Ȳ�����1000��  
//
//�������ݱ�֤���ָ�õ��ķǸ������������100000000���������ݲ�����ȫ�ɡ�5����ɡ�
// 
//
//Output
//����ÿ����������������ָ�õ�����������Ľ�������ڵ���������֮����һ���ո�ֿ���ÿ�����ռһ�С�
// 
//
//Sample Input
//
//0051231232050775
//
// 
//
//Sample Output
//
//0 77 12312320
//
// 
//
//Source
//POJ
// 
//
//Recommend
//Eddy

//
//HINTS:
//	
//	DO NOT USE '\b' to correct ' ' to '\n' in loop output
//	

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
	
	int num[512];
	char buff[1024];
	
	while(1){
		
		memset(buff, 0, 1024);
		
		if(scanf("%s", buff) == EOF){
			break;
		}
		
		int count = 0, i = 0, len = strlen(buff);
		
		while(1){
			
			while( i < len && buff[i] == '5'){
				++i;
			}
			
			if(i >= len){
				break;
			}
			
			++ count;
			num[count] = 0;
			while( i < len && buff[i] != '5'){
				num[count] *= 10;
				num[count] += buff[i] - '0';
				++i;
			}
			
		}
		
		sort(num+1, num+1+count);
		
		printf("%d", num[1]);
		for(i = 2; i <= count; ++i){
			printf(" %d", num[i]);
		}
		printf("\n");
	}
	
	return 0;
}
