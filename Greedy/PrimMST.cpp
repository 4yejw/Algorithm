#include <iostream>  //입출력 헤더파일
#include <algorithm>  
#include <limits> //무한대 정의 사용 헤더파일
#include <iomanip>  //출력 형식 지정 헤더파일
using namespace std;  //표준 네임스페이스 사용

#define INF  numeric_limits<int>::max() //무한대 정의

void PrimMST(int(*G)[6], int (*MST)[6]);  //MST를 만드는 함수
void ShowMatrix(int (*G)[6]);  //인접행렬을 출력하는 함수

int main() {

	//가중치 그래프 생성
	int Graph[6][6] = { {0,8,INF,2,4,INF},
					    {8,0,1,4,INF,2 },
					    {INF,1,0,INF,INF,1},
					    {2,4,INF,0,3,7},
					    {4,INF,INF,3,0,9},
					    {INF,2,1,7,9,0} };
	cout << "\n\t\t  가중치 그래프 출력\n" << endl;
	ShowMatrix(Graph); 

	//MST 생성
	int MST[6][6] = {0,};
	fill(&MST[0][0], &MST[5][6], INF);  //모든 원소를 무한대로 초기화

	PrimMST(Graph, MST);  //주어진 그래프에서 MST를 만든다

	cout << "\n\t\t  최소 신장 트리 출력\n" << endl; 
	ShowMatrix(MST);
	
}

//MST를 만드는 함수
void PrimMST(int(*G)[6], int(*MST)[6]){
	int p = 4; //출발정점 e
	MST[p][p] = 0;  //MST에 정점e추가

	//배열 D는 MST의 현재 정점과 정점을 연결하는 간선의 최소가중치를 저장
	int D[6] = { 0,};
	for (int i = 0; i < 6; i++) 
		D[i] = G[p][i];
	
	//MST를 만든다
	for (int k = 0; k < 6;k++) {
		//MST에 존재하는 정점을 제외하고 최소 가중치를 갖는 정점을 찾는다
		int min_v = INF;  //최소 가중치를 갖는 정점
		int min_index = 0;  //최소 가중치를 갖는 정점의 인덱스
		for (int i = 0; i < 6; i++) {
			if (D[i] != 0)
				if (D[i] < min_v) {
					min_v = D[i];
					min_index = i;
				}
		}
		//MST에 최소 가중치를 갖는 정점을 추가한다
		MST[min_index][min_index] = 0;
		
		//MST의 정점 중 최소 가중치를 갖는 간선을 찾는다
		int MIN = INF;
		int MIN_V = 0;
		for (int i = 0; i < 6; i++) {
			if(D[i]==0)
				if (G[min_index][i] < MIN) {
					MIN = G[min_index][i];
					MIN_V = i;
				}
		}
		//MST에 최소 가중치를 갖는 간선을 추가한다
		MST[min_index][MIN_V] = MIN;
		MST[MIN_V][min_index] = MIN;

		//배열 D를 갱신한다
		for (int i = 0; i < 6; i++) {
			if (G[min_index][i] < D[i])
				D[i] = G[min_index][i];
		}
	}
}

//인접행렬을 출력하는 함수
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
				cout << setw(3) << G[i][j] << '|'; //setw 함수는 출력 형식 개수를 지정하는 함수이다
		}
		cout << endl;
	}
	cout << "\n\n";
}
