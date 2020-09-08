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
		cout << "Lenght = " << dynamicArray.GetLenght() << " Capacity = " << dynamicArray.GetCapacity() << endl;

		cout << "1 - Show array | 2 - Add Element | 3 - Insert Element | 4 - Remove Element" << endl;
		cout << "5 - Line search | 6 - Binary search | 7 - Quick Sort | 8 - Exit | 9 - zakrep" << endl;
		
		cin >> count;
		switch (count)
		{
		case 1:
			dynamicArray.ShowArray();
			cout << "Wait..." << endl;
			Sleep(3000);
			break;
		case 2:
			dynamicArray.AddElement();
			break;
		case 3:
			cout << "Enter index: ";
			cin >> value;
			cout << endl;
			dynamicArray.InsertElement(value);
			Sleep(1000);
			break;
		case 4:
			cout << "Enter index: ";
			cin >> value;
			cout << endl;
			dynamicArray.RemoveElement(value);
			Sleep(1000);
			break;
		case 5:
			cout << "Enter value: ";
			cin >> value;
			cout << endl;
			dynamicArray.LinearSearch(value);
			Sleep(1500);
			break;
		case 6:
			cout << "Enter value: ";
			cin >> value;
			cout << endl;
			dynamicArray.BinarySearch(value);
			Sleep(1500);
			break;
		case 7: 
			dynamicArray.QuickSort();
			break;
		case 8: 
			exit(0);
			break;
		case 9:
			value2 = 9;
			break;
		default:
			cout << "unexpected error" << endl;
			break;
		}
		system("cls");
	}
	
}

