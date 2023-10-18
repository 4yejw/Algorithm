//�����Ÿ����� 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//��ü �����Ÿ� �������迭�� ����ϴ� �Լ�
void ShowMatrix(int** E, string S, string T, int m, int n);

int main() {
	string S, T;  //���ڿ� source, target
	
	//source �� target�� �Է¹޴´�
	cout << "\tinput source : ";
	cin >> S;
	cout << "\tinput target : ";
	cin >> T;

	int m = S.length();  //source ���ڿ� ����
	int n = T.length();  //target ���ڿ� ����

	int** E = new int* [m+1];  //�������迭 ���� �����Ҵ�
	for (int i = 0; i <= m; i++)
		E[i] = new int[n+1];  //�������迭�� ���� �����Ҵ�

	//������ �迭 �ʱ�ȭ
	for (int i = 0; i <= m; i++) //���ڿ��� ���� ��� �ʱ�ȭ 
		E[i][0] = i;
	for (int i = 0; i <= n; i++)  //���ڿ��� ���� ��� �ʱ�ȭ
		E[0][i] = i;

	//�����Ÿ� ���
	for (int i=1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (S[i-1] == T[j-1])  //�밢�� ������ �ʿ���°��
				E[i][j] = min({ E[i][j - 1]+1,E[i - 1][j] + 1,E[i - 1][j - 1] });
			else  //�밢�� ���꿡�� ��ü������ �ʿ��� ���
				E[i][j] = min({ E[i][j - 1]+1,E[i - 1][j] + 1,E[i - 1][j - 1]+1 });
		}
	}

	ShowMatrix(E,S,T,m, n); //��ü �����Ÿ� �������迭 ���
	cout << "\t"<<S <<" -> "<<T << " �����Ÿ��� " << E[m][n] << " �Դϴ�\n";

}

//��ü �����Ÿ� �������迭 ���
void ShowMatrix(int** E, string S, string T, int m, int n) {
	cout << "\n\t\t     ";
	for (int i = 0; i <= n; i++)
		cout << T[i] << "   ";
	cout << "\n\t\t";
	for (int i = 0; i <= n; i++)
		cout << "[" << i << "] ";
	cout << "\n\t\t";
	for (int i = 0; i <= n; i++)
		cout << "----";
	cout << "\n";

	for (int i = 0; i <= m; i++) {
		if (i == 0)
			cout << "\t   [" << i << "] | ";
		else
			cout << "\t " << S[i - 1] << " [" << i << "] | ";
		for (int j = 0; j <= n; j++) {
			cout << E[i][j] << "   ";
		}
		cout << '\n';
	}
	cout << "\n\n";
}