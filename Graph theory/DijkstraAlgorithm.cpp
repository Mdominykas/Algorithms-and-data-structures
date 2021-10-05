/*Dijkstra's algorithm
Explanation: Algorithm finds shortest paths from one vertice to every other given that
graph does not contain negative weight edges
Source: Competitive Programmer’s Handbook p128
Complexity: O(E*log(E))
Tested on: https://codeforces.com/gym/101933/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e5;
const int INF = 1e9;
vector<pair<int, int> > adjacent[max_n];
int dist[max_n];
bool visited[max_n];


int main()
{
	int n, m;
	cin >> n >> m;
	int start;
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adjacent[a].push_back(make_pair(b, c));
		adjacent[b].push_back(make_pair(a, c));
	}
	cin >> start;
	for(int i = 0; i < n; i++)
	{
		visited[i] = 0;
		dist[i] = INF;
	}
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push(make_pair(0, start));
	while(!q.empty())
	{
		int v = q.top().second;
		q.pop();
		if(visited[v])
			continue;
		visited[v] = 1;
		for(int i = 0; i < adjacent[v].size(); i++)
		{
			int next = adjacent[v][i].first;
			int egdeWeight = adjacent[v][i].second;
			if(dist[next] > egdeWeight + dist[v])
			{
				dist[next] = egdeWeight + dist[v];
				q.push(make_pair(dist[next], next));
			}
		}
	}
	return 0;
}