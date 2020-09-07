#include "DynamicArray.h"
void DynamicArray::CreatArray()
{
	_array = new int[capacity];
}

void DynamicArray::AddElement()
{
    int element;
    element = GetElement();
    if (length >= capacity)
    {
        IncreaseArray(_array);
    }
    _array[length] = element;
    length++;
    
}

int DynamicArray::InsertElement(int j)
{
    int element;
    int buf = 0;
    element = GetElement();
    if (length >= capacity)
    {
        IncreaseArray(_array);
    }
    if (j > length)
    {
        cout << "index does not exist" << endl;
        return 1;
    }
    buf = _array[j];
    _array[j] = element;
    for (int i = j + 1; i <= length; i++)
    {
        element = _array[i];
        _array[i] = buf;
        buf = element;
    }
    length++;
    return 0;
}

void DynamicArray::ShowArray()
{
    cout << "mas: " << endl;
    for (int i = 0; i < length; i++) 
    {
        cout << _array[i] << endl;
    }
    cout << ":mas " << endl;
}

int DynamicArray::RemoveElement(int j)
{
    int buf = 0;
    if (length == 0)
    {
        cout << "array is empty" << endl;
        return 1;
    }

    if (j >= length)
    {
        cout << "index does not exist" << endl;
        return 1;
    }

    for (int i = j + 1; i < length; i++)
    {
        _array[i - 1] = _array[i];
    }
    length -= 1;
    return 0;
}

void DynamicArray::QuickSort()
{
    int i = 0; 
    int j = 0;
    int left = 0;
    int right = length - 1;
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
    for (int i = 0; i < length; i++)
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
    int high = length - 1;
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

void DynamicArray::ShowElement(int i)
{
    cout << "index: " << i << " element: " << _array[i] << endl;
}

bool DynamicArray::SortCheck()
{
    int count = 0;
    for (int i = 0; i < length - 1; i++)
    {
        if (_array[i] < _array[i + 1])
        {
            count++;
        }
    }
    if (count == length - 1)
    {
        return true;
    }
    else 
    { 
        return false; 
    }
}

int DynamicArray::GetElement()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        cout << "Enter a int value: ";
        int a;
        cin >> a;

        // Проверка на предыдущее извлечение
        if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            cin.ignore(32767, '\n'); // удаляем лишние значения

            return a;
        }
    }
    return 0;
}

void DynamicArray::IncreaseArray(int *&array)
{
    int* newArray = new int[capacity * _growthFactor];
    for (int i = 0; i < capacity; i++)
    {
        newArray[i] = array[i];
    }
    capacity *= _growthFactor;
    delete[] array;
    array = newArray;
}


