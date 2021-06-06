/*Dijkstra's algorithm on dense graph
Explanation: Algorithm finds shortest paths from one vertice given that graph does not
contain negative weight edges. It is based on the fact that length of shortest path
can not decrease. Thus it does n iterations and choose closest unmarked node and
updates distance to all its neighbours
Source: https://cp-algorithms.com/graph/dijkstra.html
Complexity: O(V^2+E)
Tested on: Codeforces 1483D Useful Edges
*/
#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e5;
const int INF = 1e9;
vector<pair<int, int> > adj[max_n];
int main()
{
	int n, m;
	cin >> n >> m;
	int start, finish;
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	cin >> start >> finish;
	long long d[n];
	for(int j=0; j<n; j++)
		d[j] = INF;


	bool marked[n];
	for(int j=0; j<n; j++)
		marked[j] = false;

	d[start] = 0;

	for(int j=0; j<n; j++)
	{
		int v = -1;
		for(int k=0; k<n; k++)
		{
			if((!marked[k]) && ((v==-1) || (d[k]<d[v])))
				v = k;
		}
		if(d[v] == INF)
			break;

		marked[v] = true;

		for(int j=0; j<adj[v].size(); j++)
		{
			int next = adj[v][j].first;
			if(d[v] + adj[v][j].second < d[next])
				d[next] = d[v] + adj[v][j].second;
		}
	}
	cout << d[finish];
	return 0;
}