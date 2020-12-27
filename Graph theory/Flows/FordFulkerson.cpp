/*Ford-Fulkerson algorithm
Explanation: algorihm finds maximum flow between two vertices.
If there is augmented path between source and sink it is added to a flow.
Algorithm is not guaranteed to terminate with not rational numbers. Algorithm
does not provide exact method to find augmented paths 
Source: unknown
Complexity: O(Ef), where f is maximum flow
Tested on: lightly tested
*/

#include<bits/stdc++.h>
using namespace std;

bool bfs(int **rgrpah, int s, int t, int n, int parent[])
{
	bool visited[n];
	for(int i=0; i<n; i++)
		visited[i] = 0;
	queue<int> eile;
	eile.push(s);
	while(!eile.empty())
	{
		int g = eile.front();
		eile.pop();
		for(int i=0; i<n; i++)
		{
			if((rgrpah[g][i]>0) && (visited[i]==0))
			{
				visited[i] = 1;
				parent[i] = g;
				eile.push(i);
			}
		}
	}
	return visited[t];
}

int FordFulkerson(int **grpah, int s, int t, int n)
{
	int **rgrpah;
	rgrpah = new int *[n];
	for(int i=0; i<n; i++)
	{
		rgrpah[i] = new int[n];
		for(int j=0; j<n; j++)
			rgrpah[i][j] = grpah[i][j];
	}
	int parent[n];
	for(int i=0; i<n; i++)
		parent[i] = 0;
	int max_flow = 0;
	while(bfs(rgrpah, s, t, n, parent))
	{
		int flow = INT_MAX;
		int v = t;
		while(v!=s)
		{
			flow = min(flow, rgrpah[parent[v]][v]);
			v = parent[v];
		}
		v = t;
		while(v!=s)
		{
			rgrpah[parent[v]][v] -= flow;
			rgrpah[v][parent[v]] += flow;
			v = parent[v];
		}
		max_flow += flow;
	}
	return max_flow;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int **grpah;
	grpah = new int *[n];
	for(int i=0; i<n; i++)
		grpah[i] = new int[n];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			grpah[i][j] = 0;
	}
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		grpah[a][b] += c;
		//grpah[b][a] += c;
	}
	cout << FordFulkerson(grpah, 0, n-1, n);
}