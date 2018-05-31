//Problem Description
//FatMouse prepared M pounds of cat food, ready to trade with the cats guarding the warehouse containing his favorite food, JavaBean.
//The warehouse has N rooms. The i-th room contains J[i] pounds of JavaBeans and requires F[i] pounds of cat food. FatMouse does not have to trade for all the JavaBeans in the room, instead, he may get J[i]* a% pounds of JavaBeans if he pays F[i]* a% pounds of cat food. Here a is a real number. Now he is assigning this homework to you: tell him the maximum amount of JavaBeans he can obtain.
// 
//
//Input
//The input consists of multiple test cases. Each test case begins with a line containing two non-negative integers M and N. Then N lines follow, each contains two non-negative integers J[i] and F[i] respectively. The last test case is followed by two -1's. All integers are not greater than 1000.
// 
//
//Output
//For each test case, print in a single line a real number accurate up to 3 decimal places, which is the maximum amount of JavaBeans that FatMouse can obtain.
// 
//
//Sample Input
//
//5 3
//7 2
//4 3
//5 2
//20 3
//25 18
//24 15
//15 10
//-1 -1
//
// 
//
//Sample Output
//
//13.333
//31.500
//
// 
//
//Author
//CHEN, Yue
// 
//
//Source
//ZJCPC2004
// 
//
//Recommend
//JGShining


// HINT ::  USE DOUBLE RATHER THAN FLOAT

// HINT ::  USE sort() RATHER THAN YOUR CUSTOMED SORTING FUNCTION

#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct{
	int j;
	int f;
	double rate;
} ROOM, *PROOM;

PROOM arr;

void swap(int * r1, int * r2){
	int temp;
	temp = *r1;
	*r1 = *r2;
	*r2 = temp;
}

void sortRoomDesc(PROOM arr, int *head, int *tail){
	
	int *p1 = head, *p2 = tail;
	
	if(p1 >= p2){
		return;
	}
	
	double key = arr[*p1].rate;
	
	bool turn = true;
	
	while(1){
		if(turn){
			while(key > arr[*p2].rate){
				p2--;
			}	
		}else{
			while(key < arr[*p1].rate){
				p1++;
			}	
		}
		
		if(p2 == p1){
			break;
		}
		swap(p1, p2);
		turn ^= 1;
	}
	
	sortRoomDesc(arr, head, p1 - 1);
	sortRoomDesc(arr, p1+1, tail);
}

bool cmp(int a, int b){
	return arr[a].rate > arr[b].rate;
}

int main(){
	
	int m, n, *seq;
	
	while(1){
	
		scanf("%d %d", &m, &n);
		
		if(m == -1 && n == -1)	{
			break;
		}
		
		arr = new ROOM[n];
		seq = new int[n];
		
		for(int i = 0; i < n; ++i){
			scanf("%d %d", &arr[i].j, &arr[i].f);
			arr[i].rate = (double)arr[i].j / (double)arr[i].f;
			seq[i] = i;
		}
		
//		sortRoomDesc(arr, seq, seq + n - 1);
		
		sort(seq, seq+n, cmp);
		
//		printf("\n\n - - - \n");
//		for(int i = 0; i< n; ++i){
//			printf("%d : %d : %f\n", arr[seq[i]].j, arr[seq[i]].f, arr[seq[i]].rate);
//		}
//		printf(" - - - \n\n");
		
		double bean = 0;
		
		for(int i = 0; i < n; ++i){
			
			if(m < arr[seq[i]].f){
				bean += (double)m * (double)arr[seq[i]].j / (double)arr[seq[i]].f;
				break;
			}
			
			bean += arr[seq[i]].j;
			m -= arr[seq[i]].f;
			
		}
		
		printf("%.3lf\n", bean);
		
		delete[] arr;
		delete[] seq;
		
	}
	
	return 0;
}
