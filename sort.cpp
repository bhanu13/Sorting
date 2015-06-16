/*
Implementing all the functions as declared in sort.h

*/

#include "sort.h"

Array::Array()
{
	Resize(10);
}

Array::Array(int size)
{
	Resize(size);
}

Array::~Array()
{
	elem.clear();
}

void Array::Resize(int newsize)
{
	elem.clear();
	for(int i = 0; i<newsize; i++)
	{
		elem.push_back(rand()%100);
	}
}

void Array::PrintArray() const
{
	for(auto it = elem.begin(); it != elem.end(); it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

void Array::CheckSort() const
{
	int prev = -1;
	for(int i = 0; i<elem.size(); i++)
	{
		int curr = elem[i];
		if(prev > curr)
		{
			cout<<"Incorrect Sorting"<<endl;
			return;
		}
		prev = curr;
	}
	cout<<"Sorting Successful"<<endl;
}

//================= BubbleSort =======================

void Array::BubbleSort()
{
	for(int j = elem.size(); j>0; j--)
	{
		for(int i = 0; i< j - 1; i++)
		{
				if(elem[i] > elem[i+1])
				{
					int temp = elem[i+1];
					elem[i+1] = elem[i];
					elem[i] = temp;
				}
		}	
	}
}

//================= InsertionSort ====================

void Array::InsertionSort()
{
	for(int i = 0; i<elem.size(); i++)
	{
		int curr = elem[i];
		for(int j = i-1; j>=0; j--)
		{
			if(curr < elem[j])
			{
				elem[j+1] = elem[j];
				elem[j] = curr;
			}
		}
	}
}
//================= QuickSort ======================== 

void Array::QuickSort()
{
	QuickSortHelp(0, elem.size()-1);
}


void Array::QuickSortHelp(int l, int h)
{
	if(l<h)
	{
		int p = partition(l, h);
		QuickSortHelp(l, p - 1);
		QuickSortHelp(p + 1, h);
	}
}

int Array::partition(int l, int h)
{
	int p = (l + h)/2;
	int t = elem[p];
	elem[p] = elem[h];
	elem[h] = t;

	int newpivot = l;
	for(int j = l; j<h; j++)
	{
		if(elem[j] < elem[h])
		{
			t = elem[newpivot];
			elem[newpivot] = elem[j];
			elem[j] = t;
			newpivot++;
		}
	}
	t = elem[newpivot];
	elem[newpivot] = elem[h];
	elem[h] = t;
	return newpivot;
}

//================= MergeSort ========================

void Array::MergeSort()
{
	MergeSortHelp(0, elem.size()-1);
}

void Array::MergeSortHelp(int l, int h)
{
	if(l < h)
	{
		int m = (l + h)/2;
		MergeSortHelp(l, m);
		MergeSortHelp(m+1, h);
		Merge(l, m+1, m, h);
	}
}

void Array::Merge(int l1, int l2, int h1, int h2)	// Includes merging the two arrays defined by their respective start and end indecies
{
	if(l1 < l2)
	{
		int i0 = l1;	// Temp iterating variable for first array
		int i1 = l2;	// Temp iterating variable for second array

		vector<int> newelem;	// Temp vector for copying
		for(int i = l1; i<=h2; i++)
		{
			if(i0 < l2 && (elem[i0] < elem[i1] || i1 > h2))
			{
				newelem.push_back(elem[i0]);
				i0++;
			}
			else
			{
				newelem.push_back(elem[i1]);
				i1++;
			}
		}
		int j = 0;
		for(int i = l1; i<=h2; i++)
		{
			elem[i] = newelem[j];
			j++;
		}
	}
}

void Array::HeapSort()
{

}

//===================== Extra Code ===================
/*
int Size() const
{
	return elem.size();
}
*/