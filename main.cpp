//main.cpp

#include "sort.h"

int main()
{
	srand(time(0));
	Array A;
	cout<<"The Unsorted Array"<<endl;
	A.PrintArray();
	//A.BubbleSort();
	//A.InsertionSort();
	//A.QuickSort();
	//A.MergeSort();
	A.HeapSort();

	cout<<"The Sorted Array"<<endl;
	A.PrintArray();
	A.CheckSort();
	return 0;
}