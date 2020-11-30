/*input
2
1 2 5
2 1 3
*/
//gaussian elimination
//issprendzia n+1 lygciu sistema su
//n nezinomuju per O(n^3)
#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<double> > &matrica, int n)
{
	auto swap_rows = [&](int id1, int id2)
	{
		for(int a=0; a<=n; a++)
			swap(matrica[id1][a], matrica[id2][a]);
	};
	int r = 0, c = 0;
	while((r<n) && (c<=n))
	{
		int parametras = matrica[r][c];
		int numeris = r;
		for(int i=r+1; i<n; i++)
		{
			if(abs(matrica[i][c]>parametras))
			{
				parametras = matrica[i][c];
				numeris = i;
			}
		}
		if(parametras==0)
		{
			c++;
			continue;
		}
		swap_rows(numeris, r);
		for(int i=0; i<r; i++)
		{
			double f = matrica[i][c]/matrica[r][c];
			for(int j=0; j<=n; j++)
				matrica[i][j] -= f*matrica[r][j];
		}
		for(int i=r+1; i<n; i++)
		{
			double f = matrica[i][c]/matrica[r][c];
			for(int j=0; j<=n; j++)
				matrica[i][j] -= f*matrica[r][j];
		}
		r++;
		c++;
	}
	r = 0;
	c = 0;
	while((r<n) && (c<=n))
	{
		if(matrica[r][c]==0)
		{
			c++;
			continue;
		}
		else
		{
			double skaicius = matrica[r][c];
			for(int i=0; i<=n; i++)
				matrica[r][i] /= skaicius;
			r++;
			c++;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	vector<vector<double> > matrica(n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=n; j++)
		{
			double a;
			cin >> a;
			matrica[i].push_back(a);
		}
	}
	solve(matrica, n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=n; j++)
			cout << matrica[i][j] << " ";
		cout << endl;
	}
	return 0;
}