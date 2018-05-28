	#include <iostream>
	#include <cstdio>
	#include <cstring>
	using namespace std;
	 
	int N;
	int a[101][101];
	int dp[101];
	 
	int getMaxArray(int a[], int N) {
	    int max = a[0], tmp = 0;
	    for (int i = 0; i < N; ++i) {
	        if (tmp > 0) {
	            tmp += a[i];
	        } else {
	            tmp = a[i];
	        }
	        max = max > tmp ? max : tmp;
	    }
	    return max;
	}
	 
	int main() {
	    //freopen("input.txt", "r", stdin);
	    while (scanf("%d", &N) != EOF) {
	        for (int i = 0; i < N; ++i) {
	            for (int j = 0; j < N; ++j) {
	                scanf("%d", &a[i][j]);
	            }
	        }
	        int res = a[0][0], tmp;
	        for (int i = 0; i < N; ++i) {
	            memset(dp, 0, sizeof(dp));
	            for (int j = i; j < N; ++j) {
	                for (int k = 0; k < N; ++k) {
	                    dp[k] += a[j][k];
	                }
	                tmp = getMaxArray(dp, N);
	                res = res > tmp ? res : tmp;
	            }
	        }
	        printf("%d\n", res);
	    }
	    return 0;
	}
