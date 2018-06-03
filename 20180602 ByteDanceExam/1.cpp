
#include <iostream>
#include <string.h>
using namespace std;

int main() {

	int n, *arr, *indx, zeros = 0;
	cin >> n;

	arr = new int[n];
	indx = new int[n];
	memset(arr, 0, n * sizeof(int));
	memset(indx, 0, n * sizeof(int));

	indx[0] = -1;
	for (int i = 0; i<n; ++i) {
		cin >> arr[i];
		if(arr[i] == 0){
			++zeros;
			indx[zeros] = i;
		}
	}
	
	int max = 0;
	
	for(int i = 0; i<=zeros; ++i){
		
		int p1 = indx[i] + 1;
		int count = 0, sum = 0;
		
		for(int j = p1; j < n && count < 4; ++j){
			sum += arr[j];
			if(sum < 0){
				sum = 0;
			}
			if(arr[j] == 0){
				++count;
			}
			if(sum > max){
				max = sum;
			}
		}
	}

	cout << max << endl;

	delete[] arr;
	delete[] indx;
	return 0;
}
