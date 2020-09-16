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
	/// Получение элемента с консоли и проверка на int
	int GetElement();

	void IncreaseArray();
	
public:

	DynamicArray();


	int& operator[](int index);

	int GetLenght();
	int GetCapacity();

	void AddElement();

	int InsertElement(int index);

	void ShowArray();

	int RemoveElement(int index);

	void QuickSort();
	
	int LinearSearch(int value);
	int BinarySearch(int value);
	void ShowElement(int index);
	
	bool SortCheck();


	~DynamicArray();
};

