//Problem Description
//C++��̿���ʹ�õ�ʵʱ�ύϵͳ�����м�ʱ��óɼ��������ص㡣���Ĺ�������ôʵ�ֵ��أ�
//������������Ŀ�Ľ���ύ֮��Ҫô��AC����Ҫô���󣬲��������������Ǹ������һ�ʣ������������й�һ�δ����ύ���������һ���ύ���⡰AC���󣬾�Ҫ������һ�����ˣ��ܹ���������ύ�˼��ء���Ȼ���������ϣ��󲽵�Ծ����һ��̨�ף������ں�ʱ��Ҫ̯���㹲��ȥ��ʱ�䡣�ر��ǣ������й��Ĵ����ύ��ÿ�ζ�Ҫ̯��һ���ĵ�λʱ��֡�����һ�������������������ϣ��������ȱ��˺ܶ࣬���ǣ�������ͬ����������Ⱥ�У�����ܻ��ں�ʱ�ϴ������������ơ�
//���磺ĳ�ο���һ��8�⣨A��B��C��D��E��F��G��H����ÿ���������ⶼ�ڶ�Ӧ��������и�������ǣ�������ʾ��ѧ���ڸ������й��Ĵ����ύ�������������ڻ�û��AC��������ʾAC���ĵ�ʱ�䣬�������a����һ�����ţ������и�����b���Ǿͱ�ʾ��ѧ���ύ����AC�ˣ���ȥ��ʱ��a��ͬʱ�����������ύ��b�Σ���˶��������������ݣ�
//
//
//
//��ÿ�δ����ύ�ķ���Ϊ20�֣����������Ӹߵ���Ӧ���������ģ�
//Josephus 5 376
//John 4 284
//Alice 4 352
//Smith 3 167
//Bob 2 325
//Bush 0 0
// 
//
//Input
//�������ݵĵ�һ���ǿ�������n��1��n��12���Լ���λ������m��10��m��20����ÿ����������һ��ѧ�����û�����������10���ַ����ִ����Լ�������n����Ĵ�����״���������������������е�������ǵĸ�ʽ��������ı���ύ��������С��100��AC����ʱ������С��1000��
//
// 
//
//Output
//����Щѧ���Ŀ�����״�����һ��ʵʱ������ʵʱ������Ȼ�Ȱ�AC�����Ķ����ţ������ǰ���ٰ�ʱ��ֵĶ����ţ��ٵ���ǰ���������ǰ���߶���ȣ������ֵ��ֵ����ţ�С����ǰ��ÿ��ѧ��ռһ�У�������֣�10���ַ�����������������2���ַ����Ҷ��룩��ʱ��֣�4���ַ����Ҷ��룩�����֡�������ʱ����໥֮����һ���ո�
// 
//
//Sample Input
//
//8 20
//Smith	  -1	-16	8	0	0	120	39	0
//John	  116	-2	11	0	0	82	55(1)	0
//Josephus  72(3)	126	10	-3	0	47	21(2)	-2
//Bush	  0	-1	-8	0	0	0	0	0
//Alice	  -2	67(2)	13	-1	0	133	79(1)	-1
//Bob	  0	0	57(5)	0	0	168	-7	0
//
// 
//
//Sample Output
//
//Josephus    5  376
//John        4  284
//Alice       4  352
//Smith       3  167
//Bob         2  325
//Bush        0    0
//
// 
//
//Author
//qianneng
// 
//
//Source
//ӭ����ѧ�ڡ�������Easy��������
// 
//
//Recommend
//lcy


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

#define NAME_LEN 11
#define SCORE_LEN 10

typedef struct {
	char name[NAME_LEN];
	int count;
	int time;
} STU, *PSTU;

struct STU_LIST_NODE{
	STU stu;
	STU_LIST_NODE *next;
};
typedef STU_LIST_NODE *PSTU_LIST_NODE;

bool nameCmp(char *n1, char *n2, int len){
	for(int i = 0; i < len; ++i){
		if(n1[i] > n2[i]){
			return true;
		}
		if(n1[i] < n2[i]){
			return false;
		}
	}
	return false;
}

bool stuCmp(PSTU stu1, PSTU stu2){
	if(stu1->count != stu2->count){
		return stu1->count > stu2->count;
	}
	if(stu1->time != stu2->time){
		return stu1->time < stu2->time;
	}
	return !nameCmp(stu1->name, stu2->name, NAME_LEN); // bigger alphabetical order ranks behind
}

void insrtStu(PSTU_LIST_NODE head, PSTU_LIST_NODE stu){
	PSTU_LIST_NODE p = head, temp = NULL;
	while(p->next != NULL && stuCmp(&p->next->stu, &stu->stu)){
		p = p->next;
	}
	temp = p->next;
	p->next = stu;
	stu->next = temp;
}

int getScore(char *str, int m){
	if(str[0] == '-' || str[0] == '0'){
		return 0;
	}
	int time = 0;
	while(*str >= '0' && *str <= '9'){
		time *= 10;
		time += *str - '0';
		++str;
	}
	if(*str == '('){
		int try_count = 0;
		while(*++str != ')'){
			try_count *= 10;
			try_count += *str - '0';
		}
		time += try_count * m;
	}
	return time;
}

void printStuList(PSTU_LIST_NODE head){
	PSTU_LIST_NODE p = head->next;
	while(p != NULL){
		printf("%-10s ", p->stu.name);
		printf("%2d ", p->stu.count);
		printf("%4d\n", p->stu.time);
		p = p->next;
	}
}

void delStuList(PSTU_LIST_NODE head){
	PSTU_LIST_NODE p = head->next, temp;
	while(p != NULL){
		temp = p;
		p = p->next;
		delete temp;
	}
}

int main(){
	
	int n, m, stu_count;
	char name_tmp[NAME_LEN], score_tmp[SCORE_LEN];
	STU_LIST_NODE stu_list, *stu_node_tmp;
	
	PSTU_LIST_NODE head = &stu_list;
	memset(head, 0, sizeof(STU_LIST_NODE));
	
	scanf("%d %d", &n, &m);
	while(1){
		
		memset(name_tmp, 0, NAME_LEN);
		if(scanf("%s", name_tmp) == EOF){
//		if(scanf("%s", name_tmp) && name_tmp[0] == '0'){
			break;
		}
		
		stu_node_tmp = new STU_LIST_NODE;
		memset(stu_node_tmp, 0, sizeof(STU_LIST_NODE));
		memcpy(stu_node_tmp->stu.name, name_tmp, NAME_LEN);
		
		stu_node_tmp->stu.time = 0;
		
		int score;
		for(int i = 0; i < n; ++i){
			
			memset(score_tmp, 0, SCORE_LEN);
			scanf("%s", score_tmp);
			
			score = getScore(score_tmp, m);
			if(score != 0){
				++ stu_node_tmp->stu.count;
				stu_node_tmp->stu.time += score;
			}
			
		}
		
		insrtStu(head, stu_node_tmp);
	}
	
	printStuList(head);
	
	delStuList(head);
	
	return 0;
}
