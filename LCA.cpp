/*input
1
7
3 2 3 4
0
3 5 6 7
0
0
0
0
2
5 7
2 7
*/
#include<bits/stdc++.h>
using namespace std;
const int max_N = 1005;
const int logn = 13;
int tevas[max_N][logn];
int gylis[max_N];

int rask_gyli(int id)
{
	if(tevas[id][0]==0)
		gylis[id] = 0;
	else if (gylis[id]==-1)
		gylis[id] = rask_gyli(tevas[id][0])+1;
	return gylis[id];
}

void precompute(int N)
{
	for(int j=1; j<logn; j++)
	{
		for(int i=1; i<=N; i++)
			tevas[i][j] = tevas[tevas[i][j-1]][j-1];
	}
}

int lca(int v, int w)
{
	if(gylis[v]>gylis[w])
		swap(v, w);
	for(int i=logn-1; i>=0; i--)
	{
		if(gylis[w]-(1<<i)>=gylis[v])
			w = tevas[w][i];
	}
	if(w==v)
		return w;
	for(int i=logn-1; i>=0; i--)
	{
		if(tevas[v][i]!=tevas[w][i])
		{
			v = tevas[v][i];
			w = tevas[w][i];
		}
	}
	return tevas[w][0];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for(int i=0; i<=N; i++)
	{
		tevas[i][0] = 0;
		gylis[i] = -1;
	}
	for(int i=1; i<=N; i++)
	{
		int M;
		cin >> M;
		for(int j=0; j<M; j++)
		{
			int a;
			cin >> a;
			tevas[a][0] = i;
		}
	}
	for(int i=1; i<=N; i++)
	{
		if(gylis[i]==-1)
			rask_gyli(i);
	}
	for(int i=1; i<=N; i++)
	{
		if(tevas[i][0]==0)
			tevas[i][0] = i;
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