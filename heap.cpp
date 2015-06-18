// Implementing the heap functions as declared in heap.h

#include "heap.h"

heap::heap(vector<int> v)
{
	elem.clear();
	elem.push_back(-1);	// Building Heap from index 1
	for(auto it = v.begin(); it != v.end(); it++)
	{
		elem.push_back(*it);
	}

	for(int i = v.size() - 1; i>0; i--)
	{
		heapifyDown(i);
	}
}

heap::~heap()
{
	elem.clear();
}

void heap::heapifyUp(int i)
{
	if(i > 0)
	{
		int pidx = Parent(i);
		if(elem[i] < elem[pidx])
			swap(i, pidx);
		heapifyUp(pidx);
	}
}

void heap::heapifyDown(int i)
{
	if(leftChild(i) < elem.size())
	{
		int min = minChild(i);
		if(elem[i] > elem[min])
			swap(i, min);
		heapifyDown(min);
	}
}

int heap::RemoveMin()
{
	int min = elem[1];
	elem[1] = elem[elem.size() - 1];
	elem.pop_back();
	heapifyDown(1);
	return min;
}

void heap::Printheap()
{
	cout<<"Printing the heap";
	for(auto it = elem.begin(); it != elem.end(); it++)
		cout<<(*it)<<" ";
	cout<<endl;
}

int heap::Size()
{
	return elem.size() - 1;
}

int heap::leftChild(int index)
{
	return 2*index;
}

int heap::rightChild(int index)
{
	return 2*index + 1;
}

int heap::minChild(int index)
{
	if(rightChild(index) < elem.size())
		if(elem[rightChild(index)]< elem[leftChild(index)])
			return rightChild(index);
	
	return leftChild(index);
}

int heap::Parent(int index)
{
	return index/2;
}

void heap::swap(int idx1, int idx2)
{
	int temp = elem[idx1];
	elem[idx1] = elem[idx2];
	elem[idx2] = temp;
	return;
}