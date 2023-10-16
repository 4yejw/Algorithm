#include <iostream>  //����� �������
#include <algorithm>  
#include <limits> //���Ѵ� ���� ��� �������
#include <iomanip>  //��� ���� ���� �������
using namespace std;  //ǥ�� ���ӽ����̽� ���

#define INF  numeric_limits<int>::max() //���Ѵ� ����

void PrimMST(int(*G)[6], int (*MST)[6]);  //MST�� ����� �Լ�
void ShowMatrix(int (*G)[6]);  //��������� ����ϴ� �Լ�

int main() {

	//����ġ �׷��� ����
	int Graph[6][6] = { {0,8,INF,2,4,INF},
					    {8,0,1,4,INF,2 },
					    {INF,1,0,INF,INF,1},
					    {2,4,INF,0,3,7},
					    {4,INF,INF,3,0,9},
					    {INF,2,1,7,9,0} };
	cout << "\n\t\t  ����ġ �׷��� ���\n" << endl;
	ShowMatrix(Graph); 

	//MST ����
	int MST[6][6] = {0,};
	fill(&MST[0][0], &MST[5][6], INF);  //��� ���Ҹ� ���Ѵ�� �ʱ�ȭ

	PrimMST(Graph, MST);  //�־��� �׷������� MST�� �����

	cout << "\n\t\t  �ּ� ���� Ʈ�� ���\n" << endl; 
	ShowMatrix(MST);
	
}

//MST�� ����� �Լ�
void PrimMST(int(*G)[6], int(*MST)[6]){
	int p = 4; //������� e
	MST[p][p] = 0;  //MST�� ����e�߰�

	//�迭 D�� MST�� ���� ������ ������ �����ϴ� ������ �ּҰ���ġ�� ����
	int D[6] = { 0,};
	for (int i = 0; i < 6; i++) 
		D[i] = G[p][i];
	
	//MST�� �����
	for (int k = 0; k < 6;k++) {
		//MST�� �����ϴ� ������ �����ϰ� �ּ� ����ġ�� ���� ������ ã�´�
		int min_v = INF;  //�ּ� ����ġ�� ���� ����
		int min_index = 0;  //�ּ� ����ġ�� ���� ������ �ε���
		for (int i = 0; i < 6; i++) {
			if (D[i] != 0)
				if (D[i] < min_v) {
					min_v = D[i];
					min_index = i;
				}
		}
		//MST�� �ּ� ����ġ�� ���� ������ �߰��Ѵ�
		MST[min_index][min_index] = 0;
		
		//MST�� ���� �� �ּ� ����ġ�� ���� ������ ã�´�
		int MIN = INF;
		int MIN_V = 0;
		for (int i = 0; i < 6; i++) {
			if(D[i]==0)
				if (G[min_index][i] < MIN) {
					MIN = G[min_index][i];
					MIN_V = i;
				}
		}
		//MST�� �ּ� ����ġ�� ���� ������ �߰��Ѵ�
		MST[min_index][MIN_V] = MIN;
		MST[MIN_V][min_index] = MIN;

		//�迭 D�� �����Ѵ�
		for (int i = 0; i < 6; i++) {
			if (G[min_index][i] < D[i])
				D[i] = G[min_index][i];
		}
	}
}

//��������� ����ϴ� �Լ�
void ShowMatrix(int (*G)[6]) {
	cout << "\t          a   b   c   d   e   f\n";
	cout << "\t         [0] [1] [2] [3] [4] [5]\n";
	cout << "\t	 ------------------------\n";
	for (int i = 0; i < 6; i++) {
		cout << "\t " << char(97 + i) << " [" << i << "] | ";
		for (int j = 0; j < 6; j++) {
			if (G[i][j] == INF)
				cout << "INF" << '|';
			else
				cout << setw(3) << G[i][j] << '|'; //setw �Լ��� ��� ���� ������ �����ϴ� �Լ��̴�
		}
		cout << endl;
	}
	cout << "\n\n";
}
