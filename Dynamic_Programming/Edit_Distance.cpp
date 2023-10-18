//편집거리문제 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//전체 편집거리 이차원배열을 출력하는 함수
void ShowMatrix(int** E, string S, string T, int m, int n);

int main() {
	string S, T;  //문자열 source, target
	
	//source 와 target을 입력받는다
	cout << "\tinput source : ";
	cin >> S;
	cout << "\tinput target : ";
	cin >> T;

	int m = S.length();  //source 문자열 개수
	int n = T.length();  //target 문자열 개수

	int** E = new int* [m+1];  //이차원배열 열을 동적할당
	for (int i = 0; i <= m; i++)
		E[i] = new int[n+1];  //이차원배열의 행을 동적할당

	//이차원 배열 초기화
	for (int i = 0; i <= m; i++) //문자열이 없는 경우 초기화 
		E[i][0] = i;
	for (int i = 0; i <= n; i++)  //문자열이 없는 경우 초기화
		E[0][i] = i;

	//편집거리 계산
	for (int i=1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (S[i-1] == T[j-1])  //대각선 연산이 필요없는경우
				E[i][j] = min({ E[i][j - 1]+1,E[i - 1][j] + 1,E[i - 1][j - 1] });
			else  //대각선 연산에서 대체연산이 필요한 경우
				E[i][j] = min({ E[i][j - 1]+1,E[i - 1][j] + 1,E[i - 1][j - 1]+1 });
		}
	}

	ShowMatrix(E,S,T,m, n); //전체 편집거리 이차원배열 출력
	cout << "\t"<<S <<" -> "<<T << " 편집거리는 " << E[m][n] << " 입니다\n";

}

//전체 편집거리 이차원배열 출력
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