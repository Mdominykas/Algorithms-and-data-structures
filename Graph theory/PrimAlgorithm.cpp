/*Prim's algortihm
Explanation: based on similar ideas as Dijkstra's algorithm. It goes
to the closes univisited vertice and finds minimal spanning tree.
Source: Competitive Programmer’s Handbook p147
Complexity: O(nlog(n))
Tested on: seems incorrect
*/
#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e5;
const int INF = 1e9;
vector<pair<int, int> > adj[max_n];
int dist[max_n];
int parent[max_n];

int main()
{
	int n, m;
	cin >> n >> m;
	int pradine, galine;
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	cin >> pradine >> galine;
	for(int i=0; i<n; i++)
		dist[i] = INF;
	dist[pradine] = 0;
	parent[pradine] = pradine;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > eile;
	eile.push(make_pair(0, pradine));
	while(!eile.empty())
	{
		int v = eile.top().second;
		int ilgis = eile.top().first;
		eile.pop();
		for(int i=0; i<adj[v].size(); i++)
		{
			int kitas = adj[v][i].first;
			int briauna = adj[v][i].second;
			if(dist[kitas]>briauna + dist[v])
			{
				parent[kitas] = v;
				dist[kitas] = briauna + dist[v];
				eile.push(make_pair(dist[kitas], kitas));
			}
		}
	}
	cout << dist[galine];
	return 0;
}