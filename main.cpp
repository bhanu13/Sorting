//main.cpp

#include "sort.h"

int main()
{
	Array A;
	cout<<"The Unsorted Array"<<endl;
	A.PrintArray();
	A.InsertionSort();
	cout<<"The Sorted Array"<<endl;
	A.PrintArray();
	return 0;
}