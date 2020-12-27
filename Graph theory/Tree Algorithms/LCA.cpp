/*Lowest common ansestor
Explanation: using binary lifting algortihm can find lowest common ansestor
between two nodes of tree in O(log(n)) time with O(nlog(n)) precomputation
Source: Competitive Programmer’s Handbook p167
Complexity: O(log(n)) with O(nlog(n)) precomputation
Tested on: lightly tested
*/

#include<bits/stdc++.h>
using namespace std;
const int max_N = 1005;
const int logn = 13;
int parent[max_N][logn];
int depth[max_N];

int findDepth(int id)
{
	if(parent[id][0]==0)
		depth[id] = 0;
	else if (depth[id]==-1)
		depth[id] = findDepth(parent[id][0])+1;
	return depth[id];
}

void precompute(int N)
{
	for(int j=1; j<logn; j++)
	{
		for(int i=1; i<=N; i++)
			parent[i][j] = parent[parent[i][j-1]][j-1];
	}
}

int lca(int v, int w)
{
	if(depth[v]>depth[w])
		swap(v, w);
	for(int i=logn-1; i>=0; i--)
	{
		if(depth[w]-(1<<i)>=depth[v])
			w = parent[w][i];
	}
	if(w==v)
		return w;
	for(int i=logn-1; i>=0; i--)
	{
		if(parent[v][i]!=parent[w][i])
		{
			v = parent[v][i];
			w = parent[w][i];
		}
	}
	return parent[w][0];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for(int i=0; i<=N; i++)
	{
		parent[i][0] = 0;
		depth[i] = -1;
	}
	for(int i=1; i<=N; i++)
	{
		int M;
		cin >> M;
		for(int j=0; j<M; j++)
		{
			int a;
			cin >> a;
			parent[a][0] = i;
		}
	}
	for(int i=1; i<=N; i++)
	{
		if(depth[i]==-1)
			findDepth(i);
	}
	for(int i=1; i<=N; i++)
	{
		if(parent[i][0]==0)
			parent[i][0] = i;
	}
	precompute(N);
	int Q;
	cin >> Q;
	while(Q--)
	{
		int v, w;
		cin >> v >> w;
		cout << lca(v, w) << "\n";
	}
	return 0;
}