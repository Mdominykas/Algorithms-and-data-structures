/*Floyd-Warshall algoritm=hm
Explanation: algortihm finds shortest paths between every two vertices.
First of all path using immediate vertices are calculated then they
are improved using intermediate vertices
Source: Competitive Programmer’s Handbook p129
Complexity: O(V^3)
Tested on: lightly tested
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;
	int dist[N][N];
	const int INF = 1000000;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			dist[i][j] = INF;
		dist[i][i] = 0;
	}
	for(int i=0; i<M; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		dist[a][b] = min(dist[a][b], w);
		dist[b][a] = min(dist[b][a], w);
	}
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			for(int k=0; k<N; k++)
			{
				dist[j][k] = min(dist[j][k], dist[k][i] + dist[i][j]);
				dist[k][j] = min(dist[k][j], dist[k][i] + dist[i][j]);
			}
		}
	}
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			cout << dist[i][j] << " ";
		cout << endl;
	}
	return 0;
}