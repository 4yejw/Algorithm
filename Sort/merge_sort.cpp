//merge_sort 
//O(n*logn) insure 

#include <iostream>
#include <cmath>
using namespace std;

void MergeSort(int *A, int p, int q) {
	if (p < q) {
		int k = floor((p + q) / 2);
		MergeSort(A, p, k);
		MergeSort(A, k + 1, q);
		//합병 
		int B[8] = { 0, };
		int a = p;
		int b = k + 1;
		for (int i = p; i <= q; i++) {
			if (a == k + 1) {//왼쪽을 먼저 다 썼을 때
				B[i] = A[b];
				b++;
			}
			else if (b==q+1){//오른쪽을 먼저 다 썼을 때
				B[i] = A[a];
				a++;
			}
			else {
				if (A[a] < A[b]) {
					B[i] = A[a];
					a++;
				}
				else {
					B[i] = A[b];
					b++;
				}
			}
		}
		for (int i = p; i <= q; i++)
			A[i] = B[i];
	}
}

int main() {
	int A[8] = { 37,10,22,30,35,13,25,24 };

	MergeSort(A, 0, 7);//정렬 중...

	cout << "Sorted A = [";
	for (int i = 0; i < 8; i++)
		cout << A[i] << ' ';
	cout << "]\n";
}
