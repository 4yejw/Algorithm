
//quick_sort 
//about O(n*log n)

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

void ShowList(int* A, int left, int right) {
	cout << "[ ";
	for (int i = left; i <= right; i++)
		cout << A[i] << ' ';
	cout << "]\n";
}

void QuickSort(int* A, int left, int right) {
	if (left < right) {
		cout << "left = " << left << " right = " << right << "\n";
		int p = rand() % (right-left + 1) + left;//pivot
		cout << "pivot index= " << p << '\n';
		cout << "pivot value = " << A[p] << "\n"; 

		swap(A[left], A[p]);//pivot 과 첫번째 인덱스 교체

		//pivot보다 작은수는 왼쪽 큰수는 오른쪽으로 정렬
		int i = left + 1;
		int j = right;
		while (i<j) {
			if (A[i] < A[left]) {
				i++;
				continue;
			}
			while (A[j] > A[left]) {
				j--; 
				if (j == i)
					break;
			}
			swap(A[i], A[j]);
			i++;
		}

		//맨 앞에 있던 pivot을 자기자리에 넣어주기
		int k = right;
		while (A[k] > A[left])
			k--;
		swap(A[k], A[left]);
		p = k;

		cout << "last pivot index = " << p << "\n";

		ShowList(A, left, right);
		cout << "============================\n";
		QuickSort(A, left, p - 1);
		QuickSort(A, p + 1, right);
	}
}

int main() {
	srand((unsigned)time(NULL));

	int A[12] = { 6,3,11,9,12,2,8,15,18,10,7,14 };//원소 값이 중복되면 큰일남
	QuickSort(A, 0, 11);

	cout << "결과 = ";
	ShowList(A, 0,11);
}