//insertion sort O(n^2) Ω(n)
#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 9
void InsertionSort(int *A) {
	for (int i = 1; i <= SIZE - 1; i++) {
		int CurrentElement = A[i];
		int j = i - 1;
		while (j >= 0 && (A[j] > CurrentElement)) {
			A[j + 1] = A[j]; //뒤로 당김
			j--;//인덱스는 앞으로 
		}
		A[j + 1] = CurrentElement;
	}
}
int main() {
	cout << "insertion sort\n";
	int A[SIZE] = { 40,10,50,90,20,80,30,60,70 };
	cout << "before : ";
	for (int i = 0; i < 9; i++)
		cout << A[i] << ' ';
	cout << endl;
	InsertionSort(A);
	cout << "after  : ";
	for (int i = 0; i < 9; i++)
		cout << A[i] << ' ';
}