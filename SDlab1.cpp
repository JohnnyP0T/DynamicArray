

#include <iostream>
#include"DynamicArray.h";
using namespace std;
int main()
{
	DynamicArray da;
	int* array;
	da.CreatArray();
	int a = 0;
	for (;;) {
		cin >> a;
		if(a == 1)
		da.AddElement();
	//	if (a != 1)
		//	da.InsertElement(a);
		//if (a != 1)
		//	da.RemoveElement(a);
		if (a != 1)
			da.BinarySearch(a);
		cout << da.capacity << " " << da.length << endl;
		da.ShowArray();
	}
	cout << array[0];
}

