/*input
4 6
1 2 3
2 3 4
3 1 2
2 2 5
3 4 3
4 3 3
*/
#include<bits/stdc++.h>
using namespace std;

bool bfs(int **rgrafas, int s, int t, int n, int tevas[])
{
	bool aplankyti[n];
	for(int i=0; i<n; i++)
		aplankyti[i] = 0;
	queue<int> eile;
	eile.push(s);
	while(!eile.empty())
	{
		int g = eile.front();
		eile.pop();
		for(int i=0; i<n; i++)
		{
			if((rgrafas[g][i]>0) && (aplankyti[i]==0))
			{
				aplankyti[i] = 1;
				tevas[i] = g;
				eile.push(i);
			}
		}
	}
	return aplankyti[t];
}

int FordFulkerson(int **grafas, int s, int t, int n)
{
	int **rgrafas;
	rgrafas = new int *[n];
	for(int i=0; i<n; i++)
	{
		rgrafas[i] = new int[n];
		for(int j=0; j<n; j++)
			rgrafas[i][j] = grafas[i][j];
	}
	int tevas[n];
	for(int i=0; i<n; i++)
		tevas[i] = 0;
	int max_flow = 0;
	while(bfs(rgrafas, s, t, n, tevas))
	{
		int flow = INT_MAX;
		int v = t;
		while(v!=s)
		{
			flow = min(flow, rgrafas[tevas[v]][v]);
			v = tevas[v];
		}
		v = t;
		while(v!=s)
		{
			rgrafas[tevas[v]][v] -= flow;
			rgrafas[v][tevas[v]] += flow;
			v = tevas[v];
		}
		max_flow += flow;
	}
	return max_flow;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int **grafas;
	grafas = new int *[n];
	for(int i=0; i<n; i++)
		grafas[i] = new int[n];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			grafas[i][j] = 0;
	}
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		grafas[a][b] += c;
	}
	cout << FordFulkerson(grafas, 0, n-1, n);
}