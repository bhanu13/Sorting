/* A simple C++ program that implements different sorting algorithms.

- Practice With Sorting Algos
- Bubble, Insertion, Quick, Merge, Heap


*/
#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>
#include "heap.h"

using namespace std;

class Array
{
	public:
		Array();	// Create an unsorted array of a default size - 10 elements
		Array(int size);	// Create an unsorted array of the given size
		~Array();	// The destructor
		void Resize(int newsize);	// 	Change the array to the new size	

		void PrintArray() const;
		void CheckSort() const;
		//int Size() const;
		void BubbleSort();
		void InsertionSort();
		void QuickSort();
		void MergeSort();
		void HeapSort();

	private:
		vector<int> elem;
		void QuickSortHelp(int l, int h);
		int partition(int l, int h);
		void MergeSortHelp(int l, int h);
		void Merge(int l1, int l2, int h1, int h2);
};

#endif