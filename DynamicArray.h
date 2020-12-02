#pragma once

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
	
	DynamicArray();

	int GetLength() const;
	
	int GetCapacity() const;

	void BubbleSort() const;
	
	void AddElement(int element);
	
	void DecreaseArray();
	
	void InsertElement(int element, int index);

	void RemoveElement(int index);

	int LinearSearch(int value) const;
	
	int BinarySearch(int value) const;
	
	int GetElement(int index) const;
	
	bool SortCheck() const;

	~DynamicArray();
};

