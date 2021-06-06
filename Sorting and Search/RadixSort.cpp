/*Radix Sort
Explanation: radix sort sorts dy digits on base b. It first starts sorting by lowest
digit and then goes to higher ones.
Source: https://www.geeksforgeeks.org/radix-sort/
Complexity: O(nlog_b(n))
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n, int exp, int base)
{
	int output[n];

	int count[base];
	for(int i=0; i<base; i++)
		count[i] = 0;

	for(int i=0; i<n; i++)
		count[(arr[i]/exp)%base]++;

	for(int i=1; i<base; i++)
		count[i] += count[i-1];
	// for(int i=0; i<base; i++)
	// 	cout << count[i] << " ";
	// cout << endl;

	for(int i=n-1; i>=0; i--)
	{
		output[count[(arr[i]/exp)%base]-1] = arr[i];
		count[(arr[i]/exp)%base]--;
	}


	for(int i=0; i<n; i++)
		arr[i] = output[i];
}

void radixSort(int arr[], int n, int base)
{
	int maxi = arr[0];
	for(int i=0; i<n; i++)
		maxi = max(maxi, arr[i]);
	for(int exp = 1; maxi/exp>0; exp *= base)
		countSort(arr, n, exp, base);
}


int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];

	radixSort(arr, n, 15);

	for(int i=0; i<n; i++)
		cout << arr[i] << " ";

	return 0;
}