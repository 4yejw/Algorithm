//Selection and Quick Sort

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
#define SIZE 1000

void QuickSort(int* A, int left, int right);
int Selection(int* A, int left, int right, int k);

int main() {
	srand((unsigned)time(NULL));

	int A[SIZE];//Selection 할 배열 A

	//A배열의 원소들의 값을 랜덤 생성
	for (int i = 0; i < SIZE; i++) {
		A[i] = rand() % 30000;
		int j = 0;
		while (true) {
			if (A[i] == A[j]) {
				A[i] = rand() % 30000;
				j = -1;
			}
			j++;
			if (j == i)
				break;
		}
	}

	//정렬된 값을 출력할 배열 B 생성
	int B[SIZE];
	for (int i = 0; i < SIZE; i++)
		B[i] = A[i];

	//Selection
	int K = 732;//k번째 작은 수 
	cout << K << "번째 작은 수는 " << Selection(A, 0, 999, K) << "입니다\n\n";

	//정렬된 배열 출력
	QuickSort(B, 0, 999);

	for (int i = K - 10; i <= K + 10; i++)
		cout << i << "번째 인덱스의 값 = " << B[i] << '\n';
}

void QuickSort(int* A, int left, int right) {
	if (left < right) {
		int p = rand() % (right - left + 1) + left;//pivot
		swap(A[left], A[p]);//pivot 과 첫번째 인덱스 교체

		//pivot보다 작은수는 왼쪽 큰수는 오른쪽으로 정렬
		int i = left + 1;
		int j = right;
		while (i < j) {
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

		QuickSort(A, left, p - 1);
		QuickSort(A, p + 1, right);
	}
}

int Selection(int* A, int left, int right, int k) {
	int p = rand() % (right - left + 1) + left;  //pivot

	//pivot 과 첫번째 인덱스 교체
	swap(A[left], A[p]);

	//pivot보다 작은수는 왼쪽 큰수는 오른쪽으로 정렬
	int i = left + 1;
	int j = right;
	while (i < j) {
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
	int q = right;
	while (A[q] > A[left])
		q--;
	swap(A[q], A[left]);
	p = q;

	//Selection
	int Small_Group = (p - 1) - left + 1;

	if (k <= Small_Group)
		Selection(A, left, p - 1, k);  //small group안에 k번째 작은 숫자가 존재하는 경우
	else if (k == Small_Group + 1)  //pivot이 k번째 작은 숫자인 경우
		return A[p];
	else   //large group안에 k번째 작은 숫자가 존재하는 경우 
		Selection(A, p + 1, right, k - Small_Group - 1);
}