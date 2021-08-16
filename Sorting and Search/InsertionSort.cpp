/*Insertion sort
Explanation: algorithm sorts array by sorting from begining and then inserting
each element into it correct location
Source: https://en.wikipedia.org/wiki/Insertion_sort
Complexity: O(N^2)
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
	for(int i=1; i<n; i++)
	{
		for(int j=i; j>=1; j--)
		{
			if(arr[j]<arr[j-1])
				swap(arr[j], arr[j-1]);
			else
				break;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];
	insertionSort(arr, n);
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	return 0;
}