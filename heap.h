// This file contains the heap class to be used for Heap Sort
#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>

using namespace std;

class heap
{
public:
	heap(vector<int> v);
	~heap();
	void heapifyUp(int index);
	void heapifyDown(int index);
	int RemoveMin();
	void Printheap();
	int Size();
private:
	vector<int> elem;
	int leftChild(int index);
	int rightChild(int index);
	int Parent(int index);
	int minChild(int index);
	void swap(int idx1, int idx2);


};

#endif