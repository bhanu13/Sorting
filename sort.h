/* A simple C++ program that implements different sorting algorithms.

- Practice With Sorting Algos
- Bubble, Insertion, Quick, Merge


*/
#include <iostream>
#include <vector>


using namespace std;

class Array
{
	public:
		Array();	// Create an unsorted array of a default size - 10 elements
		Array(int size);	// Create an unsorted array of the given size
		~Array();	// The destructor
		void Resize(int newsize);	// 	Change the array to the new size	

		void PrintArray() const;
		//int Size() const;
		void BubbleSort();
		void InsertionSort();
		void QuickSort();
		void MergeSort();
		void HeapSort();

	private:
		vector<int> elem;
};