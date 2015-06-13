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

/*
void Array::InsertionSort()
{
	for(int i = 0; i<elem.size(); i++)
	{
		for(int j = i-1; j<0; j--)
		{
			if(elem[j] > elem[i])
			{
				int temp = elem[j];
				elem[j] = elem[i];
				elem[j] = temp;
				i = j;
			}
		}
	}
}
*/

/*
int Size() const
{
	return elem.size();
}
*/