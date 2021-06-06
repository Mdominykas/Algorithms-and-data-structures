/*{Algorithm name}
Explanation: min heap stores data in a way that parent value is smaller than 
that of both childs. New element is added to the end and then heap is heapified.
When deleting top element is swaped with last, last removed and heapified.
Source: https://en.wikipedia.org/wiki/Binary_heap
Complexity: insertion and deletion is O(logn), get min in O(1)
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

struct MinHeap
{
	vector<int> elements;
	void add(int val)
	{
		elements.push_back(val);
		int id = elements.size() - 1;
		while(id != 0)
		{
			if(elements[id/2] > elements[id])
			{
				swap(elements[id/2], elements[id]);
				id = id/2;
			}
			else
				break;
		}
	}
	void eraseTop()
	{
		if(elements.empty())
			return;
		swap(elements[0], elements.back());
		elements.pop_back();
		int id = 0;
		while(2*id < elements.size())
		{
			if((2*id + 1 < elements.size()) && (elements[2*id + 1] < elements[id]) && (elements[2*id + 1] < elements[id]))
			{
				swap(elements[id], elements[2*id+1]);
				id = 2*id + 1;
			}
			else if (elements[2*id] < elements[id])
			{
				swap(elements[2*id], elements[id]);
				id = 2*id;
			}
			else
				break;
		}
	}
};

int main()
{
	MinHeap heapas;
	heapas.add(100);
	cout << heapas.elements[0] << endl;///100
	heapas.add(23);
	cout << heapas.elements[0] << endl;///23
	heapas.add(10);
	cout << heapas.elements[0] << endl;///10
	heapas.add(15);
	cout << heapas.elements[0] << endl;///10
	heapas.add(52);
	cout << heapas.elements[0] << endl;///10
	heapas.eraseTop();
	cout << heapas.elements[0] << endl;///15
	heapas.add(15);
	cout << heapas.elements[0] << endl;///15
	heapas.add(14);
	cout << heapas.elements[0] << endl;///14
	heapas.eraseTop();
	cout << heapas.elements[0] << endl;///15
	heapas.eraseTop();
	cout << heapas.elements[0] << endl;///15
	heapas.eraseTop();
	cout << heapas.elements[0] << endl;///23

}