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


