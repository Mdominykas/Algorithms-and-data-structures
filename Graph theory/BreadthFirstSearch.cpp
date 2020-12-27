/*Breadth-first search
Explanation: algorithm visits all nodes in increasing distance from
starting node.
Source: Competitive Programmer’s Handbook p119
Complexity: O(n+m)
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int main()
{
	int n, m;
	cin >> n >> m;
	queue<int> q;
	int dist[n];
	for(int i=0; i<n; i++)
		dist[i] = INF;
	vector<int> adjacent[n];
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		adjacent[a].push_back(b);
		adjacent[b].push_back(a);
	}
	dist[0] = 0;
	q.push(0);
	while(!q.empty())
	{
		int g = q.front();
		for(int i=0; i<adjacent[g].size(); i++)
		{
			if(dist[adjacent[g][i]]>dist[g]+1)
			{
				dist[adjacent[g][i]] = dist[g] + 1;
				q.push(adjacent[g][i]);
			}
		}
		q.pop();
	}
	for(int i=0; i<n; i++)
		cout << dist[i] << " ";
	return 0;
}