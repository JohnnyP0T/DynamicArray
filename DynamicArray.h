#pragma once
#include<iostream>
#include<stack>
using namespace std;
class DynamicArray
{
private:
	int* _array;
	const int _growthFactor = 2;
	int _length = 0;
	int _capacity = 4;
	
	
public:
	void IncreaseArray();
	int GetElementConsole();
	DynamicArray();

	int& operator[](int index);

	int GetLenght();
	int GetCapacity();

	void BubbleSort();
	void AddElement();
	void DecreaseArray();
	int InsertElement(int index);

	void ShowArray();

	int RemoveElement(int index);

	void LinearSearch(int value);
	int BinarySearch(int value);
	void ShowElement(int index);
	
	bool SortCheck();

	~DynamicArray();
};

