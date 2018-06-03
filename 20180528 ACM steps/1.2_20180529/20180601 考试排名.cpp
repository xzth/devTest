//Problem Description
//C++编程考试使用的实时提交系统，具有即时获得成绩排名的特点。它的功能是怎么实现的呢？
//我们做好了题目的解答，提交之后，要么“AC”，要么错误，不管怎样错法，总是给你记上一笔，表明你曾经有过一次错误提交，因而当你一旦提交该题“AC”后，就要与你算一算帐了，总共该题错误提交了几回。虽然你在题数上，大步地跃上了一个台阶，但是在耗时上要摊上你共花去的时间。特别是，曾经有过的错误提交，每次都要摊上一定的单位时间分。这样一来，你在做出的题数上，可能领先别人很多，但是，在做出同样题数的人群中，你可能会在耗时上处于排名的劣势。
//例如：某次考试一共8题（A，B，C，D，E，F，G，H），每个人做的题都在对应的题号下有个数量标记，负数表示该学生在该题上有过的错误提交次数，但到现在还没有AC，正数表示AC所耗的时间，如果正数a跟上一对括号，里面有个整数b，那就表示该学生提交该题AC了，耗去了时间a，同时，曾经错误提交了b次，因此对于下述输入数据：
//
//
//
//若每次错误提交的罚分为20分，则其排名从高到低应该是这样的：
//Josephus 5 376
//John 4 284
//Alice 4 352
//Smith 3 167
//Bob 2 325
//Bush 0 0
// 
//
//Input
//输入数据的第一行是考试题数n（1≤n≤12）以及单位罚分数m（10≤m≤20），每行数据描述一个学生的用户名（不多于10个字符的字串）以及对所有n道题的答题现状，其描述采用问题描述中的数量标记的格式，见上面的表格，提交次数总是小于100，AC所耗时间总是小于1000。
//
// 
//
//Output
//将这些学生的考试现状，输出一个实时排名。实时排名显然先按AC题数的多少排，多的在前，再按时间分的多少排，少的在前，如果凑巧前两者都相等，则按名字的字典序排，小的在前。每个学生占一行，输出名字（10个字符宽），做出的题数（2个字符宽，右对齐）和时间分（4个字符宽，右对齐）。名字、题数和时间分相互之间有一个空格。
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
//迎接新学期——超级Easy版热身赛
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
