/*Depth-first search
Explanation: algorithm traverse all vertices from starting one
in recursive order
Source: Competitive Programmer’s Handbook p117
Complexity: O(n+m)
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

const int max_n = 20;
vector<int> adjacent[max_n];

int padetis[max_n];
int parent[max_n];

void dfs(int virsune)
{
	padetis[virsune] = 1;
	for(int i=0; i<adjacent[virsune].size(); i++)
	{
		if(padetis[adjacent[virsune][i]]==0)
		{
			parent[adjacent[virsune][i]] = virsune;
			dfs(adjacent[virsune][i]);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		adjacent[a].push_back(b);
		adjacent[b].push_back(a);
	}
	for(int i=0; i<n; i++)
	{
		padetis[i] = 0;
		parent[i] = -1;
	}
	for(int i=0; i<n; i++)
	{
		if(padetis[i]==0)
			dfs(i);
	}
	for(int i=0; i<n; i++)
		cout << padetis[i] << " " << parent[i] << endl;
	return 0;
}