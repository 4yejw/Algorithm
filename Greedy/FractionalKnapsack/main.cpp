//�κй賶���� O(nlogn)
#include "Bag.h"

int main() {
	Bag B;
	B.ShowStock();
	cout << "g�� ���ݼ����� ����\n";
	B.Sort();
	B.ShowStock();


	B.Packing();
	B.ShowBag();

}