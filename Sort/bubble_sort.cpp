//bubble sort O(n^2)
#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 9
void BubbleSort(int *A) {
	for (int pass = 1; pass <= SIZE - 1; pass++) {
		for (int i = 1; i <= SIZE - pass; i++) {
			if (A[i - 1] > A[i]) 
				swap(A[i - 1], A[i]);
		}
	}
}
int main() {
	cout << "bubble sort\n";
	int A[SIZE] = {90,50,40,20,10,30,60,80,70};
	cout<<"before : ";
	for (int i = 0; i < 9; i++)
		cout << A[i] << ' ';
	cout<<endl;
	BubbleSort(A);
	cout<<"after  : ";
	for (int i = 0; i < 9; i++) 
		cout << A[i] << ' ';
}