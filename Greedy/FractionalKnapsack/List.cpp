#include "List.h"
List::List() {
	Head = NULL;
	Tail = NULL;
	Count = 0;
}
List::~List() {
	while (!(Count == 0)) {
		Pop();
	}
}
void List::Append() {
	Nptr NewNode = new node;
	if (NewNode == NULL)
		exit(1);
	
	NewNode->Next = NULL;
	if (Count == 0) {
		Head = NewNode;
		Tail = NewNode;
	}
	else {
		Tail->Next = NewNode;
		Tail = NewNode;
	}
	Count++;
}
void List::Delete(int Position) {
	if (Count == 0)
		cout << "no delete!\n";
	else if(Position==1){
		Nptr DeleteNode = Head;
		Head = DeleteNode->Next;
		delete DeleteNode;
		Count--;
	}
	else {
		Nptr DeleteNode;
		Nptr tmp = Head;
		for (int i = 1; i < Position-1; i++)
			tmp = tmp->Next;
		if (Position == Count)
			Tail = tmp;
		DeleteNode=tmp->Next;
		tmp->Next = DeleteNode->Next;
		delete DeleteNode;
		Count--;
	}
}
void List::Insert(int Position, Nptr NewNode) {
	if (Position == 1) {
		NewNode->Next = Head;
		Head = NewNode;
	}
	else {
		Nptr temp = Head;
		for (int i = 1; i < Position-1; i++)
			temp = temp->Next;
		NewNode->Next = temp->Next;
		temp->Next = NewNode;
		if (Position == Count)
			Tail = NewNode;
	}
	Count++;
}
void List::ShowList() {
	Nptr tmp = Head;
	while(tmp!=NULL) {
		cout << tmp->name << " ";
		tmp = tmp->Next;
	}
	cout<<endl;
}
void List::Sort() {
	for (int i = 1; i <= 4; i++) {
		int Position = 1;
		//cout << "i = " << i << endl;
		//ShowList();
		Nptr tmp = Head;
		for (int a = 1; a < i; a++)
			tmp = tmp->Next;

		int max = 0;
		while (tmp != NULL) {
			if (tmp->g_value > max)
				max = tmp->g_value;
			tmp = tmp->Next;
		}

		tmp = Head;
		while (tmp->g_value != max) {
			tmp = tmp->Next;
			Position++;
		}
		//cout << "position = " << Position<<endl;

		Nptr NewNode = new node;
		if (NewNode == NULL) 
			exit(1);
		
		NewNode->name = tmp->name;
		NewNode->value = tmp->value;
		NewNode->weight = tmp->weight;
		NewNode->g_value = tmp->g_value;
		NewNode->Next = NULL;
		Delete(Position);
		//ShowList();
		Insert(i, NewNode);
		//ShowList();
	}
}

void List::Pop() {
	Nptr DeleteNode;
	if (Count == 1) {
		DeleteNode = Head;
		Head = NULL;
		Tail = NULL;
	}
	else {
		DeleteNode = Tail;
		Nptr tmp = Head;
		for (int i = 1; i < Count - 1; i++)
			tmp = tmp->Next;
		Tail = tmp;
	}
	delete DeleteNode;
	Count--;
}
void List::SetWeight(int Position, int Weight) {
	Nptr tmp = Head;
	for (int i = 1; i < Position; i++)
		tmp = tmp->Next;
	tmp->weight = Weight;
}
void List::SetName(int Position, string Name) {
	Nptr tmp = Head;
	for (int i = 1; i < Position; i++)
		tmp = tmp->Next;
	tmp->name = Name;
}
void List::SetValue(int Position, int Value) {
	Nptr tmp = Head;
	for (int i = 1; i < Position; i++)
		tmp = tmp->Next;
	tmp->value = Value;
}
void List::SetGValue(int Position) {
	Nptr tmp = Head;
	for (int i = 1; i < Position; i++)
		tmp = tmp->Next;
	tmp->g_value = tmp->value / tmp->weight;
}
int List::GetWeight(int Position) {
	Nptr tmp = Head;
	for (int i = 1; i < Position; i++)
		tmp = tmp->Next;
	return tmp->weight;
}
string List::GetName(int Position) {
	Nptr tmp = Head;
	for (int i = 1; i < Position; i++)
		tmp = tmp->Next;
	return tmp->name;
}
int List::GetValue(int Position) {
	Nptr tmp = Head;
	for (int i = 1; i < Position; i++)
		tmp = tmp->Next;
	return tmp->value;
}
int List::GetGValue(int Position) {
	Nptr tmp = Head;
	for (int i = 1; i < Position; i++)
		tmp = tmp->Next;
	return tmp->g_value;
}