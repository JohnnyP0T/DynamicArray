#include <iostream>
#include"DynamicArray.h";
#include <stdlib.h>
#include "windows.h"
using namespace std;
int main()
{
	DynamicArray dynamicArray;
	int count = 0;
	int value = 0;
	int value2 = 0;
	for (;;) {
		if (value2 == 9)
		{
			dynamicArray.ShowArray();
		}
		cout << "+=================== Dynamic Array ===================+" << endl;
		cout << "Lenght = " << dynamicArray.GetLenght() << " Capacity = ";
		cout << dynamicArray.GetCapacity() << endl;

		cout << "1 - Add Element |";
		cout << " 2 - Insert Element | 3 - Remove Element" << endl;
		cout << "4 - Line search | 5 - Binary search |"; 
		cout << " 6 - Quick Sort | 7 - Show array \n=++= ";
		cout << " any other button - Exit  =++=" << endl;
		
		cin >> count;
		switch (count)
		{
		case 1:
			dynamicArray.AddElement();
			break;
		case 2:
			cout << "Enter index: ";
			cin >> value;
			cout << endl;
			dynamicArray.InsertElement(value);
			Sleep(1000);
			break;
		case 3:
			cout << "Enter index: ";
			cin >> value;
			cout << endl;
			dynamicArray.RemoveElement(value);
			Sleep(1000);
			break;
		case 4:
			cout << "Enter value: ";
			cin >> value;
			cout << endl;
			dynamicArray.LinearSearch(value);
			Sleep(1500);
			break;
		case 5:
			cout << "Enter value: ";
			cin >> value;
			cout << endl;
			dynamicArray.BinarySearch(value);
			Sleep(1500);
			break;
		case 6: 
			dynamicArray.QuickSort();
			break;
		case 7: 
			value2 = 9;
			break;
		default:
			return 0;
			break;
		}
		system("cls");
	}
	
}

