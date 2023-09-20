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

	int A[SIZE];//Selection �� �迭 A

	//A�迭�� ���ҵ��� ���� ���� ����
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

	//���ĵ� ���� ����� �迭 B ����
	int B[SIZE];
	for (int i = 0; i < SIZE; i++)
		B[i] = A[i];

	//Selection
	int K = 732;//k��° ���� �� 
	cout << K << "��° ���� ���� " << Selection(A, 0, 999, K) << "�Դϴ�\n\n";

	//���ĵ� �迭 ���
	QuickSort(B, 0, 999);

	for (int i = K - 10; i <= K + 10; i++)
		cout << i << "��° �ε����� �� = " << B[i] << '\n';
}

void QuickSort(int* A, int left, int right) {
	if (left < right) {
		int p = rand() % (right - left + 1) + left;//pivot
		swap(A[left], A[p]);//pivot �� ù��° �ε��� ��ü

		//pivot���� �������� ���� ū���� ���������� ����
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

		//�� �տ� �ִ� pivot�� �ڱ��ڸ��� �־��ֱ�
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

	//pivot �� ù��° �ε��� ��ü
	swap(A[left], A[p]);

	//pivot���� �������� ���� ū���� ���������� ����
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

	//�� �տ� �ִ� pivot�� �ڱ��ڸ��� �־��ֱ�
	int q = right;
	while (A[q] > A[left])
		q--;
	swap(A[q], A[left]);
	p = q;

	//Selection
	int Small_Group = (p - 1) - left + 1;

	if (k <= Small_Group)
		Selection(A, left, p - 1, k);  //small group�ȿ� k��° ���� ���ڰ� �����ϴ� ���
	else if (k == Small_Group + 1)  //pivot�� k��° ���� ������ ���
		return A[p];
	else   //large group�ȿ� k��° ���� ���ڰ� �����ϴ� ��� 
		Selection(A, p + 1, right, k - Small_Group - 1);
}