#pragma once
#include<iostream>
#include<stack>
using namespace std;
class DynamicArray
{

	int* _array;
	int _growthFactor = 2;
	int _length = 0;
	int _capacity = 4;

	int GetElement();

	//увеличение массива
	void IncreaseArray();
	
public:
	//конструктор
	DynamicArray();

	//перегрузка оператора индексирования
	//(в данной задаче не пригодилось)
	int& operator[](int index);

	//получение переменных массива 
	//(нет сетеров  потому что пользователю их менять не надо)
	int GetLenght();
	int GetCapacity();

	//добавление элемента
	void AddElement();

	//вставка элемента
	int InsertElement(int j);

	//вывод массива
	void ShowArray();

	//удаление элемента
	int RemoveElement(int j);

	//быстрая сортировка
	void QuickSort();

	int LinearSearch(int value);
	int BinarySearch(int value);
	void ShowElement(int i);
	
	//проверка для бинарного поиска
	bool SortCheck();


	~DynamicArray();
};

