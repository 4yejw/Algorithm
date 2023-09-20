//Selection 
//O(n)

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

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

int main() {
	srand((unsigned)time(NULL));

	int A[12] = { 6,3,11,9,12,2,8,15,18,10,7,14 };  //원소 값이 중복되면 큰일남

	int K = 7;//k번째 작은 수 
	cout<<K<<"번째 작은 수는 "<<Selection(A, 0, 11, K)<<"입니다";

}