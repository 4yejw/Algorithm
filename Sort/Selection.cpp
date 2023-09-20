//Selection 
//O(n)

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

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

int main() {
	srand((unsigned)time(NULL));

	int A[12] = { 6,3,11,9,12,2,8,15,18,10,7,14 };  //���� ���� �ߺ��Ǹ� ū�ϳ�

	int K = 7;//k��° ���� �� 
	cout<<K<<"��° ���� ���� "<<Selection(A, 0, 11, K)<<"�Դϴ�";

}