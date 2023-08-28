//selection sort O(n^2)
#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 9
void SelectionSort(int *A) {
	for (int i = 0; i <= SIZE - 2;i++) {
		int min = i;
		for (int j = i + 1; j <= SIZE - 1; j++) {
			if (A[min] > A[j])
				min = j;
		}
		swap(A[i], A[min]);
	}
}
int main() {
	cout << "selection sort\n";
	int A[SIZE] = { 40,10,50,90,20,80,30,60,70 };
	cout << "before : ";
	for (int i = 0; i < 9; i++)
		cout << A[i] << ' ';
	cout << endl;
	SelectionSort(A);
	cout << "after  : ";
	for (int i = 0; i < 9; i++)
		cout << A[i] << ' ';
}
