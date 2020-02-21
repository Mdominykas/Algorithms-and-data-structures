/*input
2
5
4 1 3 9 7
10
10 9 8 7 6 5 4 3 2 1
*/
#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int pr1, int pb1, int pr2, int pb2)
{
	int a = pr1, b = pb2;
	int mas[pb1-pr1+pb2-pr2+2];
	int sk = 0;
	while((pr1<=pb1) && (pr2<=pb2))
	{
		if(arr[pr1]<=arr[pr2])
		{
			mas[sk] = arr[pr1];
			sk++;
			pr1++;
		}
		else
		{
			mas[sk] = arr[pr2];
			sk++;
			pr2++;
		}
	}
	while(pr1<=pb1)
	{
		mas[sk] = arr[pr1];
		sk++;
		pr1++;
	}
	while(pr2<=pb2)
	{
		mas[sk] = arr[pr2];
		sk++;
		pr2++;
	}
	for(int i=a; i<=b; i++)
		arr[i] = mas[i-a];
}

void mergesort(int arr[], int pr, int pb)
{
	if(pr!=pb)
	{
		mergesort(arr, pr, (pr+pb)/2);
		mergesort(arr, (pr+pb)/2 + 1, pb);
		merge(arr, pr, (pr+pb)/2, (pr+pb)/2 + 1, pb);

	}
}

int main()
{
	int T = 1;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];
		mergesort(arr, 0, n-1);
		for(int i=0; i<n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	return 0;
}