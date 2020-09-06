

#include <iostream>
#include"DynamicArray.h";
using namespace std;
int main()
{
	DynamicArray da;
	int* array;
	array = da.creatArray();
	int a = 0;
	for (;;) {
		cin >> a;
		if(a == 0)
		da.addElement();
		if (a > 0)
			da.addElement(a);
		cout << da.capacity << " " << da.length << endl;
		da.showArray();
	}
	cout << array[0];
}

