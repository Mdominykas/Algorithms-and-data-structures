/*Longest increasing subsequence
Explanation: finds longest increasing subsquence in array. By iterating through
it algorithms stores previous element if sequence would end here and minimal 
final element of each length increasing subsequence. When updating one only
have to  update one sequence it is optimal
Source: https://en.wikipedia.org/wiki/Longest_increasing_subsequence
Complexity: O(nlog(n))
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;
		int X[n];
		for(int i=0; i<n; i++)
			cin >> X[i];
		int M[n+1];///M[j] = indeksas maziausio X[i], kuriame baigiasi j elementu nemazejanti seka
		int P[n];///jei siame baigiasi seka, kur buvo praeitas
		M[0] = 0;
		int L = 0;
		for(int i=1; i<=n; i++)
			M[i] = -1;
		for(int i=0; i<n; i++)
		{
			int lo = 0, hi = n-1;
			while(lo!=hi)
			{
				int mid = (lo+hi)/2;
				while((M[mid]==-1) && (lo!=hi))
				{
					hi = mid;
					mid = (lo+hi)/2;
				}

				if(X[i]<=X[M[mid]])
					hi = mid;
				else if (X[i]>X[M[mid]])
					lo = mid + 1;
			}
			if(lo==0)
				P[i] = -1;
			else
				P[i] = M[lo-1];
			if(X[M[lo]]>X[i])
				M[lo] = i; 
			L = max(L, lo+1);
		}
		cout << L << endl;
	}
}