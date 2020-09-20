#include "DynamicArray.h"


int DynamicArray::GetLenght()
{
    return _length;
}


int DynamicArray::GetCapacity()
{
    return _capacity;
}


DynamicArray::DynamicArray()
{
    _array = new int[_capacity];
}


int& DynamicArray::operator[](int index)
{
    if (index < 0)
    {
        cout << "Index does not exist" << endl;
        exit(1);
    }
    if (index >= _length)
    {
        cout << "Index does not exist" << endl;
        exit(1);
    }
    return _array[index];
}

void DynamicArray::AddElement()
{
    int element;
    element = GetElementConsole();
    if (_length >= _capacity)
    {
        IncreaseArray();
    }
    _array[_length] = element;
    _length++;
    
}

int DynamicArray::InsertElement(int index)
{
    int element;
    int buf = 0;
    element = GetElementConsole();
    if (_length >= _capacity)
    {
        IncreaseArray();
    }
    if (index > _length || index < 0)
    {
        cout << "index does not exist" << endl;
        return 1;
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
    return 0;
}


void DynamicArray::ShowArray()
{
    cout << "array: ";
    for (int i = 0; i < _length; i++) 
    {
        cout << _array[i] << ' ';
    }
    cout << endl;
}


int DynamicArray::RemoveElement(int index)
{
    int buf = 0;
    if (_length == 0)
    {
        cout << "array is empty" << endl;
        return 1;
    }

    if (index >= _length || index < 0)
    {
        cout << "index does not exist" << endl;
        return 1;
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
    return 0;
}


void DynamicArray::BubbleSort()
{
    int tmp;
    for (int i = 1; i < _length; i++)
    {
        for (int j = 1; j < _length; j++)
        {
            if (_array[j - 1] > _array[j])
            {
                tmp = _array[j - 1];
                _array[j - 1] = _array[j];
                _array[j] = tmp;
            }
        }
    }
}


void DynamicArray::LinearSearch(int value)
{
    int count = 0;
    for (int i = 0; i < _length; i++)
    {
        if (value == _array[i])
        {
            ShowElement(i);
            count++;
        }
    }
    if (count == 0)
    {
        cout << "Not found" << endl;
    }
}

int DynamicArray::BinarySearch(int value)
{
    if (!SortCheck())
    {
        BubbleSort();
    }
    int low = 0;
    int high = _length - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (value == _array[mid])
        {
            ShowElement(mid);
            return 0;
        }
        else if (value > _array[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "Not found" << endl;
    return 1;
}

void DynamicArray::ShowElement(int index)
{
    cout << "index: " << index << " element: " << _array[index] << endl;
}

bool DynamicArray::SortCheck()
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

int DynamicArray::GetElementConsole()
{
    while (true) 
    {
        int value;
        cin >> value;

        if (cin.fail()) 
        {
            cin.clear(); 
            cin.ignore(32767, '\n'); 
            cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            cin.ignore(32767, '\n');

            return value;
        }
    }
    return 0;
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
