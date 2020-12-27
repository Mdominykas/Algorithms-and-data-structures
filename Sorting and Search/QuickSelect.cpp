/*Quickselect
Explanation: randomized algortihm to find k-th largest element from unsorted array
it find number of smaller elements and puts them to the left. Then searches
in one of the ranges.
Source: Competitive Programmer’s Handbook p232
Complexity: O(n) on average
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;


int quickSelect(int a[], int first, int last, int k)
{
	if(first==last)
		return a[first];
	int lessNum = 0, equalNum = 0;
	int num = first, x = a[last];
	for(int i=first; i<last; i++)
	{
		if(a[i]<=x)
		{
			swap(a[i], a[num]);
			num++;
		}
	}
	swap(a[last], a[num]);

	if(num==k)
		return a[num];
	if(num<k)
		return quickSelect(a, num+1, last, k);
	if(k<num)
		return quickSelect(a, first, num-1, k);

	return 0;
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];
	int k;
	cin >> k;
	cout << quickSelect(a, 0, n-1, k);
	return 0;
}