#pragma once
#include <iostream>
using namespace std;

typedef struct nodeRecord {
	int weight=0;
	string name="";
	int value=0;
	int g_value=0;
	nodeRecord* Next=NULL;
}node;

typedef node* Nptr;

class List {
public:
	List();
	List(const List& L);//복사생성자
	~List();
	void Append();
	void Pop();
	void ShowList();
	void Delete(int Position);
	void Insert(int Position,Nptr A);
	void Sort();

	void SetWeight(int Position, int Weight);
	void SetName(int Position, string Name);
	void SetValue(int Position, int Value);
	void SetGValue(int Position);

	int GetWeight(int Position);
	string GetName(int Position);
	int GetValue(int Position);
	int GetGValue(int Position);

	int GetCount() { return Count; }

private:
	Nptr Head;
	Nptr Tail;
	int Count;//List길이 
};
