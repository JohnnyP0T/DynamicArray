#pragma once
#include<iostream>
#include<stack>
using namespace std;
class DynamicArray
{
	int* _array;
	int _growthFactor = 2;
	int GetElement();
	void IncreaseArray();
	int _length = 0;
	int _capacity = 4;
public:
	
	DynamicArray();
	int& operator[](int index);
	int GetLenght();
	int GetCapacity();
	void AddElement();
	int InsertElement(int j);
	void ShowArray();
	
	int RemoveElement(int j);
	
	void QuickSort();
	
	int LinearSearch(int value);

	int BinarySearch(int value);

	void ShowElement(int i);

	bool SortCheck();

	~DynamicArray();
};

