#pragma once
#include<iostream>
using namespace std;
class DynamicArray
{
	int* array;
	int growthFactor = 2;
	int getElement();
	void increaseArray(int*& array);
public:
	int length = 0;
	int capacity = 4;
	
	int* creatArray();
	
	void addElement();
	void addElement(int j);
	void showArray();
	
	
	

};

