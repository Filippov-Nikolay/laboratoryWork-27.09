#include <iostream>
using namespace std;


struct Element
{
	// ������
	char data;
	// ����� ���������� �������� ������
	Element* Next;
};
// ����������� ������
class List
{
	// ����� ��������� �������� ������
	Element* Head;
	// ����� ��������� �������� ������
	Element* Tail;
	// ���������� ��������� ������
	int Count;

public:
	// �����������
	List();
	// ����������
	~List();

	// ����� ��������
	int SearchElement(char);

	// ���������� �������� � ������
	// (����� ������� ���������� ���������)
	void Add(char data);
	// ������� ���� � ����������� �����
	void AddPosition(int, char);

	// �������� �������� ������
	// (��������� �������� �������)
	void Del();
	// �������� ������������ ����
	void DelPosition(int i);
	// �������� ����� ������
	void DelAll();

	// ���������� ����������� ������
	// (���������� ���������� � ��������� ��������)
	void Print();

	// ��������� ���������� ���������, ����������� � ������
	int GetCount();
};

List::List()
{
	// ���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}
List::~List()
{
	// ����� ������� ��������
	DelAll();
}

int List::GetCount()
{
	// ���������� ���������� ���������
	return Count;
}

int List::SearchElement(char key) {
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	int i = 0;

	while (temp != 0) {
		if (temp->data == key) {
			return i;
		}
		temp = temp->Next;
		i++;
	}

	return -1;
}
void List::Add(char data)
{
	// �������� ������ ��������
	Element* temp = new Element;

	// ���������� �������
	temp->data = data;
	// ��������� ������� �����������
	temp->Next = NULL;
	// ����� ������� ���������� ��������� ��������� ������
	// ���� �� �� ������ �����������
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// ����� ������� ���������� ������������
	// ���� �� ������ �����������
	else {
		Head = Tail = temp;
	}
}
void List::AddPosition(int position, char element) {
	Element* temp = Head;
	Element* newNode = new Element;

	newNode->data = element;
	
	while (position > 2) {
		temp = temp->Next;
		position--;
	}

	newNode->Next = temp->Next;
	temp->Next = newNode;
}

void List::Del()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ������������� ������ �� ��������� �������
	Head = Head->Next;
	// ������� ������ �������� �������
	delete temp;
}
void List::DelPosition(int i) {
	Element* temp = Head;

	while (i > 2) {
		temp = temp->Next;
		i--;
	}

	// cout << "TEMP: " << temp->data << endl;

	Element* del = temp->Next;
	temp->Next = del->Next;
	
	delete del;
}
void List::DelAll()
{
	// ���� ��� ���� ��������
	while (Head != 0)
		// ������� �������� �� ������
		Del();
}
void List::Print()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ���� ��� ���� ��������
	while (temp != 0)
	{
		// ������� ������
		cout << temp->data << " ";
		// ��������� �� ��������� �������
		temp = temp->Next;
	}
}

// �������� ������
void main()
{
	setlocale(0, "");

	// ������� ������ ������ List
	List lst;

	// �������� ������
	char s[] = "Hello, World !!!\n";
	// ������� ������
	cout << s << "\n\n";
	// ���������� ����� ������
	int len = strlen(s);
	// �������� ������ � ������
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	// ������������� ���������� ������
	lst.Print();
	// ������� ��� �������� ������
	/*lst.Del();
	lst.Del();
	lst.Del();*/
	//������������� ���������� ������

	// ������� ���� � ����������� �����
	lst.AddPosition(5, 't');

	//������������� ���������� ������
	lst.Print();

	// �������� 
	lst.DelPosition(5);
	lst.Print();

	int key = lst.SearchElement('W');
	if (key != -1)
		cout << "���� �� �������: " << key << endl;
	else
		cout << "���� �� ������!" << endl;
}

