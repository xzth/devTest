//Problem Description
//Crixalis - Sand King used to be a giant scorpion(аЋзг) in the deserts of Kalimdor. Though he's a guardian of Lich King now, he keeps the living habit of a scorpion like living underground and digging holes.
//
//Someday Crixalis decides to move to another nice place and build a new house for himself (Actually it's just a new hole). As he collected a lot of equipment, he needs to dig a hole beside his new house to store them. This hole has a volume of V units, and Crixalis has N equipment, each of them needs Ai units of space. When dragging his equipment into the hole, Crixalis finds that he needs more space to ensure everything is placed well. Actually, the ith equipment needs Bi units of space during the moving. More precisely Crixalis can not move equipment into the hole unless there are Bi units of space left. After it moved in, the volume of the hole will decrease by Ai. Crixalis wonders if he can move all his equipment into the new hole and he turns to you for help.
// 
//
//Input
//The first line contains an integer T, indicating the number of test cases. Then follows T cases, each one contains N + 1 lines. The first line contains 2 integers: V, volume of a hole and N, number of equipment respectively. The next N lines contain N pairs of integers: Ai and Bi.
//0<T<= 10, 0<V<10000, 0<N<1000, 0 <Ai< V, Ai <= Bi < 1000.
// 
//
//Output
//For each case output "Yes" if Crixalis can move all his equipment into the new hole or else output "No".
// 
//
//Sample Input
//
//2
//
//20 3
//10 20
//3 10
//1 7
//
//10 2
//1 10
//2 11
//
// 
//
//Sample Output
//
//Yes
//No
//
// 
//
//Source
//HDU 2009-10 Programming Contest
// 
//
//Recommend
//lcy

#include <stdio.h>
#include <algorithm>
using namespace std;

int *A, *B;

double rate(int indx){
	return (double)B[indx] / (double)A[indx];
}

bool cmp(int indx1, int indx2){
//	return rate(indx1) > rate(indx2);
	return (B[indx1] - A[indx1]) > (B[indx2] - A[indx2]);
}

int main(){
	
	int T;
	scanf("%d", &T);
	for(int _i = 0; _i < T; ++_i){
		
		int V, N;
		scanf("%d %d", &V, &N);
		
		A = new int[N];
		B = new int[N];
		int *indx = new int[N];
		
		for(int i = 0; i < N; ++i){
			scanf("%d %d", A+i, B+i);
			indx[i] = i;
		}
		
		sort(indx, indx + N, cmp);
		
//		printf("\n after sort \n");
//		for(int i = 0; i < N; ++i){
//			printf("%d %d\n", A[indx[i]], B[indx[i]]);
//		}
//		printf("\n");
		
		int i;
		for(i = 0; i < N; ++i){
			if(V >= B[indx[i]]){
				V -= A[indx[i]];
			}
			else{
				break;
			}
		}
		
		if(i == N){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
		
		delete[] A;
		delete[] B;
		delete[] indx;
	}
	
	return 0;
}
