//���� ����
#include <iostream> //����� �������
#include <algorithm>  //swap�Լ��� ����ϱ� ���� �������
#include <cstdlib>  //���������� ���� �������
#include <ctime>  //���������� ���� �������
using namespace std;  //ǥ�� ���ӽ����̽� ���

#define SIZE 1000  //SIZE ���� 1000���� ����

//���� ���� �Լ� ���� ����
int Selection(int* A, int left, int right, int k);

int main() {
	srand((unsigned)time(NULL));  //�ð��� ���� seed���� ����

	int A[SIZE];  //������ ���� 1000���� ������ �迭 A ����

	//�ߺ����� �ʴ� ������ ���� 1000���� �����Ͽ� �迭 A�� ����
	for (int i = 0; i < SIZE; i++) {
		A[i] = rand();  //������ ���� ����

		//�ߺ��� ���� �ִ��� Ȯ��
		int j = 0;
		while (true) {
			if (A[i] == A[j]) {  //�ߺ��� ���� ������ ������ ���� �缳��
				A[i] = rand();
				j = -1;
			}
			j++;
			if (j == i)  //�ߺ��� ���� ���ٸ� �ݺ����� ���
				break;
		}
	}

	//K��° ũ�⸦ ������ ���� ����
	int K = 732; //K��° ���� �� 
	cout << K << "��° ���� ���� " << Selection(A, 0, 999, K) << "�Դϴ�\n\n";
}

int Selection(int* A, int left, int right, int k) {
	int pivot = rand() % (right - left + 1) + left;  //A[left]~A[right]���� �����ϰ� �Ǻ��� ����

	swap(A[left], A[pivot]);  //�Ǻ��� A[left] �ڸ��� �ٲ�

	//���Ҹ� �Ǻ����� ū �׷�� ���� �׷����� ����
	int i = left + 1;  //left+1 index���� �Ǻ��� ������ ���� ��
	int j = right; 
	while (i < j) {
		//���Ұ� �Ǻ����� ���� ��
		if (A[i] < A[left]) { 
			i++;  
			continue;
		}
		//���Ұ� �Ǻ����� Ŭ ��
		while (A[j] > A[left]) {  //right�ε������� �������� �Ǻ����� ���� ���� ���� �ε����� ã�´�
			j--;
			if (j == i)  //ã�� ���� ���� ��
				break;
		}
		swap(A[i], A[j]);  //�� ���� �ڸ��� �ٲ�
		i++;
	}

	//�Ǻ����� ū �׷�� ���� �׷� ���̿� �Ǻ��� ��ġ��Ŵ
	int q = right;
	while (A[q] > A[left])
		q--;
	swap(A[q], A[left]);
	pivot = q;

	int Small_Group = (pivot - 1) - left + 1; //small group�� ũ��

	if (k <= Small_Group)
		Selection(A, left, pivot - 1, k);  //small group�ȿ� k��° ���� ���ڰ� �����ϴ� ���
	else if (k == Small_Group + 1)  //�Ǻ��� k��° ���� ������ ���
		return A[pivot];
	else   //large group�ȿ� k��° ���� ���ڰ� �����ϴ� ��� 
		Selection(A, pivot + 1, right, k - Small_Group - 1);
}
