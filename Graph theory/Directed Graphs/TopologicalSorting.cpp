/*Topological sorting
Explanation: sort vertice of directed graph array in such way that
there is no way to get to previous vertices or says that it is impossible
Source: Competitive Programmer’s Handbook p152
Complexity: O(E+V)
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

const int max_n = 1000000;
int incoming[max_n];
vector<int> adj[max_n];

vector<int> topologicalSort(int n)
{
	vector<int> ans;
	queue<int> emptyVertices;
	for(int i=0; i<n; i++)
		incoming[i] =0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<adj[i].size(); j++)
			incoming[adj[i][j]]++;
	}
	for(int i=0; i<n; i++)
	{
		if(incoming[i]==0)
		{
			emptyVertices.push(i);
			ans.push_back(i);
		}
	}
	while(!emptyVertices.empty())
	{
		int g = emptyVertices.front();
		for(int i=0; i<adj[g].size(); i++)
		{
			incoming[adj[g][i]]--;
			if(incoming[adj[g][i]]==0)
			{
				ans.push_back(adj[g][i]);
				emptyVertices.push(adj[g][i]);
			}
		}
		emptyVertices.pop();
	}
	return ans;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++)
		incoming[i] = 0;
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		incoming[b]++;
	}
	vector<int> sequence = topologicalSort(n);
	for(int i=0; i<sequence.size(); i++)
		cout << sequence[i] << " ";
	return 0;
}