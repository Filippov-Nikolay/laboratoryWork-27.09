#include <iostream>
using namespace std;


struct Element
{
	// Данные
	char data;
	// Адрес следующего элемента списка
	Element* Next;
};
// Односвязный список
class List
{
	// Адрес головного элемента списка
	Element* Head;
	// Адрес головного элемента списка
	Element* Tail;
	// Количество элементов списка
	int Count;

public:
	// Конструктор
	List();
	// Деструктор
	~List();

	// Поиск элемента
	int SearchElement(char);

	// Добавление элемента в список
	// (Новый элемент становится последним)
	void Add(char data);
	// Вставка узла в определённое место
	void AddPosition(int, char);

	// Удаление элемента списка
	// (Удаляется головной элемент)
	void Del();
	// Удаление определённого узла
	void DelPosition(int i);
	// Удаление всего списка
	void DelAll();

	// Распечатка содержимого списка
	// (Распечатка начинается с головного элемента)
	void Print();

	// Получение количества элементов, находящихся в списке
	int GetCount();
};

List::List()
{
	// Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}
List::~List()
{
	// Вызов функции удаления
	DelAll();
}

int List::GetCount()
{
	// Возвращаем количество элементов
	return Count;
}

int List::SearchElement(char key) {
	// запоминаем адрес головного элемента
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
	// создание нового элемента
	Element* temp = new Element;

	// заполнение данными
	temp->data = data;
	// следующий элемент отсутствует
	temp->Next = NULL;
	// новый элемент становится последним элементом списка
	// если он не первый добавленный
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// новый элемент становится единственным
	// если он первый добавленный
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
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// перебрасываем голову на следующий элемент
	Head = Head->Next;
	// удаляем бывший головной элемент
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
	// Пока еще есть элементы
	while (Head != 0)
		// Удаляем элементы по одному
		Del();
}
void List::Print()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// Пока еще есть элементы
	while (temp != 0)
	{
		// Выводим данные
		cout << temp->data << " ";
		// Переходим на следующий элемент
		temp = temp->Next;
	}
}

// Тестовый пример
void main()
{
	setlocale(0, "");

	// Создаем объект класса List
	List lst;

	// Тестовая строка
	char s[] = "Hello, World !!!\n";
	// Выводим строку
	cout << s << "\n\n";
	// Определяем длину строки
	int len = strlen(s);
	// Загоняем строку в список
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	// Распечатываем содержимое списка
	lst.Print();
	// Удаляем три элемента списка
	/*lst.Del();
	lst.Del();
	lst.Del();*/
	//Распечатываем содержимое списка

	// Вставка узла в определённое место
	lst.AddPosition(5, 't');

	//Распечатываем содержимое списка
	lst.Print();

	// Удаление 
	lst.DelPosition(5);
	lst.Print();

	int key = lst.SearchElement('W');
	if (key != -1)
		cout << "Ключ на позиции: " << key << endl;
	else
		cout << "Ключ не найден!" << endl;
}

