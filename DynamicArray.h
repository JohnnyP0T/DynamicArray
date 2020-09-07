#pragma once
#include<iostream>
#include<stack>
using namespace std;
class DynamicArray
{
	int* _array = new int[capacity];
	int _growthFactor = 2;
	int GetElement();
	void IncreaseArray(int*& array);
public:
	int length = 0;
	int capacity = 4;
	
	void CreatArray();
	
	void AddElement();
	int InsertElement(int j);
	void ShowArray();
	
	int RemoveElement(int j);
	
	void QuickSort();
	
	int LinearSearch(int value);

	int BinarySearch(int value);

	void ShowElement(int i);

	bool SortCheck();

};

