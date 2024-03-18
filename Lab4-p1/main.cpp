#include "Sort.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main() {
	Sort c1(15, 10, 50);  //nr of elements,min,max   random values
	cout << "Nr of elements :" << c1.GetElementsCount() << "\n";
	cout << "Element on index 10 is :" << c1.GetElementFromIndex(10) << "\n";
	c1.Print();

	int v[5] = { 4, 2, 7, 1, 5 };
	Sort c2(v, 5); //array + nr of elements
	c2.BubbleSort(false);
	c2.Print();

	Sort c3(6, 10, 9, 8, 7, 5, 6); //va_list
	c3.InsertSort();
	c3.Print();

	char c[] = "112,34,56,178";
	Sort c4(c);  //string
	c4.QuickSort(true);
	c4.Print();
	c4.QuickSort(false);
	c4.Print();

	Sort c5 = { 1, 2, 3, 4, 5, 6 };  //initialization list
	c5.Print();



	return 0;
}