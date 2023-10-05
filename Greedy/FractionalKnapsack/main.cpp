//부분배낭문제 O(nlogn)
#include "Bag.h"

int main() {
	Bag B;
	B.ShowStock();
	cout << "g당 가격순으로 정렬\n";
	B.Sort();
	B.ShowStock();


	B.Packing();
	B.ShowBag();

}