# DynamicArray
Демонический массив.

## Введение

### Массивы

*Массив* – набор однотипных компонентов (элементов),
расположенных в памяти друг за другом, доступ к которым
осуществляется по индексу.

*Размерность массива* – количество индексов,
необходимое для однозначного доступа к элементу
массива 

```c++
int data = new int[10];
int el = data[5];
delete data;
```
#### Линейный поиск.

Проверить, есть данный элемент в массиве
Последовательно проверяем все элементы массива, пока
не найдем заданный элемент, либо, пока не закончится
массив.
O(n), где n – количество элементов в массиве.

```c++
bool HasElement(int* array, int count, int element)
{
  for(int i = 0; i < count; i++)
  {
    if (array[i] == element)
    {
      return true;
    }
  }
  return false;
}

```

#### Бинарный поиск.

Проверить, есть ли заданный элемент в *упорядоченном*
массиве. Если он есть, вернуть позицию его первого
вхождения. Если нет – вернуть -1.
Шаг: Сравниваем элемент в середине массива с заданным
элементом. Выбираем нужную половину массива в
зависимости от результата сравнения. Повторяем шаг до
тех пор, пока размер массива не уменьшится до 1.

Время работы:
O(log n), где n - количество элементов в массиве.

Объем дополнительной памяти:
В нерекурсивном: M(n) = O(1);
В рекурсивном: M(n) = O(log n), так как максимальная
глубина рекурсии – log n.

### АСД Динамический массив
Абстрактная структура данных «Динамический массив» -
интерфейс с операциями:
* Добавление элемента в конец массива (Add, PushBack,
Append)
* Доступ к элементу массива по индексу за O(1) (GetAt,
ElementAt, operator[])

C++ - vector<T>
C# - List<T>

Динамический массив содержит внутренний массив
(буфер) фиксированной длинны для хранения элементов.
Хранит количество добавленных элементов.
Размер буфера имеет некоторый запас для возможности
добавления новых элементов.

![Динамический массив](https://i.imgur.com/UTFwbAo.png)

Если буфер заканчивается:
* Выделим новый буфер большей длинны
* Скопируем содержимое старого буфера в новый
* Добавим элемент

![Сложности](https://i.imgur.com/35YU15Y.png)
