#pragma once
#include "List.h"
class Bag {
public:
	Bag();
	void SetStock();
	void ShowStock();
	void ShowBag();
	void Sort();
	void Packing();

private:
	int C;//배낭의 용량 
	List S;//재고
	List L;//배낭에 담긴 물건들
	int w;//배낭에 담긴 무게의 합
	int v;//배낭에 담긴 가치의 합
	int n = 4;//물건 종류 개수
};
