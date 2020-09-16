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
    element = GetElement();
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
    element = GetElement();
    if (_length >= _capacity)
    {
        IncreaseArray();
    }
    if (index > _length)
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
    cout << "mas: ";
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

    if (index >= _length)
    {
        cout << "index does not exist" << endl;
        return 1;
    }

    for (int i = index + 1; i < _length; i++)
    {
        _array[i - 1] = _array[i];
    }
    _length -= 1;
    return 0;
}

void DynamicArray::QuickSort()
{
    int i = 0; 
    int j = 0;
    int left = 0;
    int right = _length - 1;
    stack <int> stk;
    stk.push(left);
    stk.push(right);

    do
    {
        right = stk.top();
        stk.pop();
        left = stk.top();
        stk.pop();

        i = left;
        j = right;
        int pivot = (left + right) / 2;
        int pivot_value = _array[pivot];
        do
        {
            while (_array[i] < pivot_value)
            {
                i++;
            }
            while (_array[j] > pivot_value)
            {
                j--;
            }
            if (i <= j)
            {
                int buf = _array[i];
                _array[i] = _array[j];
                _array[j] = buf;
                i++;
                j--;
            }

        } 
        while (i <= j);
        if (left < j)
        {
            stk.push(left);
            stk.push(j);
        }
        if (i < right)
        {
            stk.push(i);
            stk.push(right);
        }
    } 
    while (!stk.empty());
}

int DynamicArray::LinearSearch(int value)
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
    return 0;
}

int DynamicArray::BinarySearch(int value)
{
    if (!SortCheck())
    {
        QuickSort();
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
    else 
    { 
        return false; 
    }
}

DynamicArray::~DynamicArray()
{
    delete[] _array;
}

int DynamicArray::GetElement()
{
    while (true) 
    {
        cout << "Enter a int value: ";
        int a;
        cin >> a;

        if (cin.fail()) 
        {
            cin.clear(); 
            cin.ignore(32767, '\n'); 
            cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            cin.ignore(32767, '\n');

            return a;
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


