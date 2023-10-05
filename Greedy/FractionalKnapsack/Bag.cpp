#include "Bag.h"

Bag::Bag() {//Bag을 초기화한다
	SetStock();//재고를 불러온다
	C = 40;
	w = 0;
	v = 0;
}
void Bag::Sort() {
	S.Sort();
}
void Bag::SetStock() {
	S.Append();
	S.Append();
	S.Append();
	S.Append();
	S.SetName(1, "주석");
	S.SetWeight(1, 50);
	S.SetValue(1, 50000);
	S.SetGValue(1);
	S.SetName(2, "백금");
	S.SetWeight(2, 10);
	S.SetValue(2, 600000);
	S.SetGValue(2);
	S.SetName(3, "은");
	S.SetWeight(3, 25);
	S.SetValue(3, 100000);
	S.SetGValue(3);
	S.SetName(4, "금");
	S.SetWeight(4, 15);
	S.SetValue(4, 750000);
	S.SetGValue(4);
}
void Bag::ShowStock() {
	cout << "===========Stock==========\n";
	for (int i = 1; i <= n; i++) {
		cout << S.GetName(i) << " ";
		cout << "weight = " << S.GetWeight(i) << ' ';
		cout << "value = " << S.GetValue(i) << ' ';
		cout << " g_value = " << S.GetGValue(i) << "\n";
	}
	cout << "==========================" << endl;
}

void Bag::ShowBag() {
	cout << "=========Bag==========\n";
	cout << "w = " << w << endl;
	cout << "v = " << v << endl;
	cout << "===========L==========\n";
	for (int i = 1; i <= L.GetCount(); i++) {
		cout << L.GetName(i) << " ";
		cout << "weight = " << L.GetWeight(i) << ' ';
		cout << "value = " << L.GetValue(i) << ' ';
		cout << " g_value = " << L.GetGValue(i) << "\n";
	}
	cout << "==========================" << endl;

}

void Bag::Packing() {
	int x= S.GetWeight(1);
	while (x + w <= C) {
		L.Append();
		L.SetName(L.GetCount(), S.GetName(1));
		L.SetWeight(L.GetCount(), S.GetWeight(1));
		L.SetValue(L.GetCount(), S.GetValue(1));
		L.SetGValue(L.GetCount());

		w += L.GetWeight(L.GetCount());
		v += L.GetValue(L.GetCount());
		S.Delete(1);
		x = S.GetWeight(1);
	}
	if (C - w > 0) {
		L.Append();
		L.SetName(L.GetCount(), S.GetName(1));
		L.SetWeight(L.GetCount(), S.GetWeight(1));
		L.SetValue(L.GetCount(), S.GetValue(1));
		L.SetGValue(L.GetCount());
		L.SetWeight(L.GetCount(), C-w);
		L.SetValue(L.GetCount(), S.GetGValue(1)*(C-w));

		v += L.GetGValue(L.GetCount()) * (C - w);
		w = C;
	}
}