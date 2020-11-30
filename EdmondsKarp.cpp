/*input
4 6
1 2 3
2 3 4
3 1 2
2 2 5
3 4 3
4 3 3
*/
///nevisai Edmonds Karp nes O(V^3) laiko
///dar galima pagreitinti pagal scaling algorithm
///ten ieskai kelio, kuris netrumpesnis uz c,
///o kai tokio nera dalini c is 2
#include<bits/stdc++.h>
using namespace std;


const int max_N = 5002;
int grafas[max_N][max_N];
int praeitas[max_N];
int flow[max_N];
const int INF = 1e9;

int BFS(int pr, int pb, int N)
{
	for(int i=0; i<N; i++)
	{
		praeitas[i] = -1;
		flow[i] = 0;
	}
	flow[pr] = INF;
	queue<int> eile;
	eile.push(pr);
	while(!eile.empty())
	{
		int g = eile.front();
		eile.pop();
		for(int i=0; i<N; i++)
		{
			if((praeitas[i]==-1) && (grafas[g][i]>0))
			{
				flow[i] = min(flow[g], grafas[g][i]);
				praeitas[i] = g;
				eile.push(i);
			}
		}
	}
	return flow[pb];
}

int EdmondsKarp(int source, int sink, int N)
{
	int ats = 0;
	while(BFS(source, sink, N))
	{
		int flowas = flow[sink];
		cout << flowas << endl;
		int dabar = sink;
		ats += flowas;
		while(dabar!=source)
		{
			grafas[dabar][praeitas[dabar]] += flowas;
			grafas[praeitas[dabar]][dabar] -= flowas;
			dabar = praeitas[dabar];
		}
	}
	return ats;
}

int main()
{
	int N, M;
	cin >> N >> M;
	for(int i=0; i<M; i++)
	{
		int a, b, s;
		cin >> a >> b >> s;
		a--;
		b--;
		grafas[a][b] += s;
		//grafas[b][a] += s;
	}
	cout << EdmondsKarp(0, N-1, N);
	return 0;
}