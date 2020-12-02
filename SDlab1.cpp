#include <iostream>
#include <cstdlib>

#include "DynamicArray.h"

using namespace std;


int GetElementConsole();


void ShowArray(DynamicArray* dynamicArray);


int main()
{
	DynamicArray* dynamicArray = new DynamicArray;
	int count = 0;
	int valueForMenu = 0;
	int indexForMenu = 0;
	
	for (;;) {
		ShowArray(dynamicArray);
		
		cout << "+=================== Dynamic Array ===================+" << endl;
		cout << "Length = " << dynamicArray->GetLength() << " Capacity = ";
		cout << dynamicArray->GetCapacity() << endl;
		cout << "1 - Add Element |";
		cout << " 2 - Insert Element | 3 - Remove Element" << endl;
		cout << "4 - Line search | 5 - Binary search |"; 
		cout << " 6 - Sort  \n=++= ";
		cout << " any other button - Exit  =++=" << endl;
		
		count = GetElementConsole();
		switch (count)
		{
			case 1:
				cout << "Enter a integer value: ";
				valueForMenu = GetElementConsole();
				dynamicArray->AddElement(valueForMenu);
				cout << endl;
				break;
			case 2:
				cout << "Enter index: ";
				indexForMenu = GetElementConsole();
				cout << endl;
				cout << "Value: ";
				valueForMenu = GetElementConsole();
				dynamicArray->InsertElement(valueForMenu, indexForMenu);
				cout << endl;
				break;
			case 3:
				cout << "Enter index: ";
				valueForMenu = GetElementConsole();
				cout << endl;
				dynamicArray->RemoveElement(valueForMenu);
				cout << endl;
				break;
			case 4:
				cout << "Enter value: ";
				valueForMenu = GetElementConsole();
				cout << endl;
				cout << dynamicArray->LinearSearch(valueForMenu);
				cout << endl;
				system("pause");
				break;
			case 5:
				cout << "Enter value: ";
				valueForMenu = GetElementConsole();
				cout << endl;
				cout << dynamicArray->BinarySearch(valueForMenu);
				cout << endl;
				system("pause");
				break;
			case 6: 
				dynamicArray->BubbleSort();
				break;
			default:
				return 0;
		}
		system("cls");
	}
	
}


int GetElementConsole()
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
}


void ShowArray(DynamicArray* dynamicArray)
{
	cout << "array: ";
	for (int i = 0; i < dynamicArray->GetLength(); i++)
	{
		cout << dynamicArray->GetElement(i) << ' ';
	}
	cout << endl;
}