/*input
25
23   6   8  10   3   2  14  22   5   7  12  17  13  18   4  21  20   9   1  15  25  19  24  16  11
*/
/*Shell sort
Explanation: algorithm performs insertion for every part of array, where
difference between elements is gap for each gap in gap sequence .
Shell gap sequence: 1, ... N/4, N/2
Hibbart Gap sequence: 1, 3, 7 ... 2^k-1
Sources: https://en.wikipedia.org/wiki/Shellsort
http://sun.aei.polsl.pl/~mciura/publikacje/shellsort.pdf
Complexity: depends on gap sequence:
Shell: O(N^2))
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> shellGapSequence(int n)
{
	vector<int> ans;
	n /= 2;
	while(n>0)
	{
		ans.push_back(n);
		n /= 2;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

vector<int> hibbartGapSequence(int n)
{
	vector<int> ans;

	for(int i=2; i<=n; i*=2)
		ans.push_back(i-1);
	reverse(ans.begin(), ans.end());
	return ans;
}

void shellSort(int arr[], int n)
{
	vector<int> gaps = hibbartGapSequence(n);
	for(int gap : gaps)
	{
		for(int i=gap; i<n; i++)
		{
			int temp = arr[i];
			int j;
			for(j=i; j>=gap && arr[j-gap] > temp; j -= gap)
				arr[j] = arr[j-gap];
			arr[j] = temp;
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

	shellSort(arr, n);

	for(int i=0; i<n; i++)
		cout << arr[i] << " ";

	return 0;
}