/*Counting sort
Explanation: counts the number of occurences of every element and
then creates entire array
Source: https://en.wikipedia.org/wiki/Counting_sort
Complexity: O(n + abs(a))
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int arr[N];
	for(int i=0; i<N; i++)
		cin >> arr[i];
	int maxi = arr[0];
	for(int i=1; i<N; i++)
		maxi = max(maxi, arr[i]);
	int count[maxi+1];
	for(int i=0; i<=maxi; i++)
		count[i] = 0;
	for(int i=0; i<N; i++)
		count[arr[i]]++;
	int num = 0;
	for(int i=0; i<=maxi; i++)
	{
		for(int j=0; j<count[i]; j++)
		{
			arr[num] = i;
			num++;
		}
	}
	for(int i=0; i<N; i++)
		cout << arr[i] << " ";
	return 0;
}