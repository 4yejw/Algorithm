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
	int C;//�賶�� �뷮 
	List S;//���
	List L;//�賶�� ��� ���ǵ�
	int w;//�賶�� ��� ������ ��
	int v;//�賶�� ��� ��ġ�� ��
	int n = 4;//���� ���� ����
};
