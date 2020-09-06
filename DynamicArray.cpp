#include "DynamicArray.h"
int* DynamicArray::creatArray()
{
	array = new int[capacity];
	return array;
}

void DynamicArray::addElement()
{
    int element;
    element = getElement();
    if (length >= capacity)
    {
        increaseArray(array);
    }
    array[length] = element;
    length++;
    
}

void DynamicArray::addElement(int j)
{
    int element;
    int buf = 0;
    element = getElement();
    if (length >= capacity)
    {
        increaseArray(array);
    }

    buf = array[j];
    array[j] = element;
    for (int i = j + 1; i <= length; i++)
    {
        element = array[i];
        array[i] = buf;
        buf = element;
    }
    length++;
}

void DynamicArray::showArray()
{
    cout << "mas: " << endl;
    for (int i = 0; i < length; i++) 
    {
        cout << array[i] << endl;
    }
    cout << ":mas " << endl;
}

int DynamicArray::getElement()
{
    while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
    {
        cout << "Enter a int value: ";
        int a;
        cin >> a;

        // �������� �� ���������� ����������
        if (cin.fail()) // ���� ���������� ���������� ��������� ���������,
        {
            cin.clear(); // �� ���������� cin � '�������' ����� ������
            cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
            cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            cin.ignore(32767, '\n'); // ������� ������ ��������

            return a;
        }
    }
    return 0;
}

void DynamicArray::increaseArray(int *&array)
{
    int* newArray = new int[capacity * growthFactor];
    for (int i = 0; i < capacity; i++)
    {
        newArray[i] = array[i];
    }
    capacity *= growthFactor;
    delete[] array;
    array = newArray;
}


