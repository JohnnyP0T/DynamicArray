#include <iostream>
#include <stdlib.h>

#include "windows.h"

#include"DynamicArray.h";


using namespace std;


int main()
{
	DynamicArray dynamicArray;
	int count = 0;
	int valueForManu = 0;
	int value2ForManu = 0;
	for (;;) {
		if (value2ForManu == 9)
		{
			dynamicArray.ShowArray();
		}
		cout << "+=================== Dynamic Array ===================+" << endl;
		cout << "Lenght = " << dynamicArray.GetLenght() << " Capacity = ";
		cout << dynamicArray.GetCapacity() << endl;

		cout << "1 - Add Element |";
		cout << " 2 - Insert Element | 3 - Remove Element" << endl;
		cout << "4 - Line search | 5 - Binary search |"; 
		cout << " 6 - Sort | 7 - Show array \n=++= ";
		cout << " any other button - Exit  =++=" << endl;
		
		cin >> count;
		switch (count)
		{
		case 1:
			cout << "Enter a integer value: ";
			dynamicArray.AddElement();
			cout << endl;
			break;
		case 2:
			cout << "Enter index: ";
			valueForManu = dynamicArray.GetElementConsole();
			cout << endl;
			cout << "Value: ";
			dynamicArray.InsertElement(valueForManu);
			cout << endl;
			break;
		case 3:
			cout << "Enter index: ";
			valueForManu = dynamicArray.GetElementConsole();
			cout << endl;
			dynamicArray.RemoveElement(valueForManu);
			cout << endl;
			break;
		case 4:
			cout << "Enter value: ";
			valueForManu = dynamicArray.GetElementConsole();
			cout << endl;
			dynamicArray.LinearSearch(valueForManu);
			cout << endl;
			cout << "Enter integer for next \n";
			valueForManu = dynamicArray.GetElementConsole();
			break;
		case 5:
			cout << "Enter value: ";
			valueForManu = dynamicArray.GetElementConsole();
			cout << endl;
			dynamicArray.BinarySearch(valueForManu);
			cout << endl;
			cout << "Enter integer for next \n";
			valueForManu = dynamicArray.GetElementConsole();
			break;
		case 6: 
			dynamicArray.BubbleSort();
			break;
		case 7: 
			value2ForManu = 9;
			break;
		default:
			return 0;
			break;
		}
		system("cls");
	}
	
}

