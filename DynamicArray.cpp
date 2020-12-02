#include <iostream>

#include "DynamicArray.h"


int DynamicArray::GetLength() const
{
    return _length;
}


int DynamicArray::GetCapacity() const
{
    return _capacity;
}


DynamicArray::DynamicArray()
{
    _array = new int[_capacity];
}


void DynamicArray::AddElement(const int element)
{
    if (_length >= _capacity)
    {
        IncreaseArray();
    }
	
    _array[_length] = element;
    _length++;
}

	
void DynamicArray::InsertElement(int element, const int index)
{
    int buf = 0;
	
    if (_length >= _capacity)
    {
        IncreaseArray();
    }
	
    if (index > _length || index < 0)
    {
        return;
    }
	
    buf = _array[index];
    _array[index] = element;
    for (int i = index + 1; i <= _length; i++)
    {
        element = _array[i];
        _array[i] = buf;
        buf = element;
    }
	
    _length++;
}


void DynamicArray::RemoveElement(const int index)
{
    int buf = 0;
    if (_length == 0)
    {
        return;
    }

    if (index >= _length || index < 0)
    {
        return;
    }

    for (int i = index + 1; i < _length; i++)
    {
        _array[i - 1] = _array[i];
    }
	
    _length -= 1;
    if (_length > 1 && (_capacity / _length) >= 2)
    {
        DecreaseArray();
    }
	
    return;
}


void DynamicArray::BubbleSort() const
{
	for (int i = 1; i < _length; i++)
    {
        for (int j = 1; j < _length; j++)
        {
            if (_array[j - 1] > _array[j])
            {
                const int tmp = _array[j - 1];
                _array[j - 1] = _array[j];
                _array[j] = tmp;
            }
        }
    }
}


int DynamicArray::LinearSearch(const int value) const
{
    int count = 0;
    for (int i = 0; i < _length; i++)
    {
        if (value == _array[i])
        {
            count++;
            return i;
        }
    }
	
	if(!count)
	{
        return -1;
	}
}


int DynamicArray::BinarySearch(const int value) const
{
    if (!SortCheck())
    {
        BubbleSort();
    }
    int low = 0;
    int high = _length - 1;
    while (low <= high)
    {
	    const int mid = (low + high) / 2;
        if (value == _array[mid])
        {
            return mid;
        }
        if (value > _array[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}


int DynamicArray::GetElement(const int index) const
{
    return _array[index];
}


bool DynamicArray::SortCheck() const
{
    int count = 0;
    for (int i = 0; i < _length - 1; i++)
    {
        if (_array[i] < _array[i + 1])
        {
            count++;
        }
    }
    if (count == _length - 1)
    {
        return true;
    }

    return false; 
}


DynamicArray::~DynamicArray()
{
    delete[] _array;
}


void DynamicArray::IncreaseArray()
{
    int* newArray = new int[_capacity * _growthFactor];
    for (int i = 0; i < _capacity; i++)
    {
        newArray[i] = _array[i];
    }
    _capacity *= _growthFactor;
    delete[] _array;
    _array = newArray;
}


void DynamicArray::DecreaseArray()
{
    int* newArray = new int[_capacity / _growthFactor];
	
    for (int i = 0; i < _length; i++)
    {
        newArray[i] = _array[i];
    }
	
    _capacity /= _growthFactor;
    delete[] _array;
    _array = newArray;
}
