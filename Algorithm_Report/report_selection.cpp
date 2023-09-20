//선택 문제
#include <iostream> //입출력 헤더파일
#include <algorithm>  //swap함수를 사용하기 위한 헤더파일
#include <cstdlib>  //난수생성을 위한 헤더파일
#include <ctime>  //난수생성을 위한 헤더파일
using namespace std;  //표준 네임스페이스 사용

#define SIZE 1000  //SIZE 값을 1000으로 정의

//선택 문제 함수 원형 선언
int Selection(int* A, int left, int right, int k);

int main() {
	srand((unsigned)time(NULL));  //시간에 따라 seed값을 변경

	int A[SIZE];  //임의의 정수 1000개를 저장할 배열 A 선언

	//중복되지 않는 임의의 정수 1000개를 생성하여 배열 A에 저장
	for (int i = 0; i < SIZE; i++) {
		A[i] = rand();  //임의의 정수 생성

		//중복된 수가 있는지 확인
		int j = 0;
		while (true) {
			if (A[i] == A[j]) {  //중복된 수가 있으면 임의의 정수 재설정
				A[i] = rand();
				j = -1;
			}
			j++;
			if (j == i)  //중복된 수가 없다면 반복루프 벗어남
				break;
		}
	}

	//K번째 크기를 가지는 숫자 제시
	int K = 732; //K번째 작은 수 
	cout << K << "번째 작은 수는 " << Selection(A, 0, 999, K) << "입니다\n\n";
}

int Selection(int* A, int left, int right, int k) {
	int pivot = rand() % (right - left + 1) + left;  //A[left]~A[right]에서 랜덤하게 피봇을 설정

	swap(A[left], A[pivot]);  //피봇과 A[left] 자리를 바꿈

	//원소를 피봇보다 큰 그룹과 작은 그룹으로 분할
	int i = left + 1;  //left+1 index부터 피봇과 원소의 값을 비교
	int j = right; 
	while (i < j) {
		//원소가 피봇보다 작을 떄
		if (A[i] < A[left]) { 
			i++;  
			continue;
		}
		//원소가 피봇보다 클 때
		while (A[j] > A[left]) {  //right인덱스부터 앞쪽으로 피봇보다 작은 값을 갖는 인덱스를 찾는다
			j--;
			if (j == i)  //찾을 값이 없을 때
				break;
		}
		swap(A[i], A[j]);  //두 값의 자리를 바꿈
		i++;
	}

	//피봇보다 큰 그룹과 작은 그룹 사이에 피봇을 위치시킴
	int q = right;
	while (A[q] > A[left])
		q--;
	swap(A[q], A[left]);
	pivot = q;

	int Small_Group = (pivot - 1) - left + 1; //small group의 크기

	if (k <= Small_Group)
		Selection(A, left, pivot - 1, k);  //small group안에 k번째 작은 숫자가 존재하는 경우
	else if (k == Small_Group + 1)  //피봇이 k번째 작은 숫자인 경우
		return A[pivot];
	else   //large group안에 k번째 작은 숫자가 존재하는 경우 
		Selection(A, pivot + 1, right, k - Small_Group - 1);
}
