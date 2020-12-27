/*Bellman-Ford algortihm
Explanation: algorithm finds shortest path from one vertice to others
and can also detect if graph contain a negative cycle. For N
iterations alogrithm goes through all egdes and updates distance.
if after that it can be updated then there is negative cycle.
Source: Competitive Programmer’s Handbook p125
Complexity: O(EV)
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;
	vector<tuple<int, int, int> > edges;
	for(int i=0; i<M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back(make_tuple(a, b, c));
	}
	sort(edges.begin(), edges.end());
	const int INF = 1000000;
	int dist[N];
	for(int i=0; i<N; i++)
		dist[i] = INF;
	dist[0] = 0;

	for(int i=0; i<N; i++)
	{
		for(auto e : edges)
		{
			int a, b, w;
			tie(a, b, w) = e;
			dist[b] = min(dist[b], dist[a]+w);
		}
	}
	bool negative_cycle = 0;
	for(auto e : edges)
	{
		int a, b, w;
		tie(a, b, w) = e;
		if(dist[b]>dist[a]+w)
		{
			negative_cycle = 1;
		}
	}
	if(negative_cycle)
		cout << "neigiamas ciklas" << endl;
	else
	{
		for(int i=0; i<N; i++)
			cout << dist[i] << endl;
	}
}