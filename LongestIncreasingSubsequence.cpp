/*input
2
16
17 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
83
86 177 115 193 135 186 92 49 21 162 27 90 59 163 126 140 26 172 136 11 168 167 29 182 130 62 123 67 135 129 2 22 58 69 167 193 56 11 42 29 173 21 119 184 137 198 124 115 170 13 126 91 180 156 73 62 170 196 81 105 125 84 127 136 105 46 129 113 57 124 95 182 145 14 167 34 164 43 150 87 8 76 178
*/
#include<bits/stdc++.h>///pratestuoti su tam tikru uzdaviniu, kuriame pasitaikys
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