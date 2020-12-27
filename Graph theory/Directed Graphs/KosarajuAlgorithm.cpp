/*Kosajaru Algorithm
Explanation: algorithm goes through the nodes by depth-first search
started at each unvisited vertice. Then it goes through those vertice
in reverse order and starts dfs with reverse graph at each unvisited.
Source: Competitive Programmer’s Handbook p158
Complexity: O(E+V)
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;
const int max_n = 1000000;
vector<int> adj[max_n];
vector<int> radj[max_n];
vector<int> sarasas;
vector<vector<int> > ats;
int num = 0;
bool visited[max_n];
void dfs1(int id)
{
	for(int i=0; i<adj[id].size(); i++)
	{
		if(!visited[adj[id][i]])
		{
			visited[adj[id][i]] = 1;
			dfs1(adj[id][i]);
		}
	}
	sarasas.push_back(id);
}

void dfs2(int id, int num)
{
	for(int i=0; i<radj[id].size(); i++)
	{
		int next = radj[id][i];
		if(!visited[next])
		{
			visited[next] = 1;
			dfs2(next, num);
		}
	}
	ats[num].push_back(id);
}

void Kosaraju(int n)
{
	for(int i=0; i<n; i++)
	{
		visited[i] = 0;
	}
	for(int i=0; i<n; i++)
	{
		if(!visited[i])
		{
			visited[i] = 1;
			dfs1(i);
		}
	}
	for(int i=0; i<n; i++)
	{
		visited[i] = 0;
	}
	for(int i=0; i<n/2; i++)
		swap(sarasas[i], sarasas[n-1-i]);
	for(int i=0; i<n; i++)
	{
		if(!visited[sarasas[i]])
		{
			ats.push_back(vector<int>());
			visited[sarasas[i]] = 1;
			dfs2(sarasas[i], num);
			num++;
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
		adj[a].push_back(b);
		radj[b].push_back(a);
	}
	Kosaraju(n);
	for(int i=0; i<num; i++)
	{
		cout << i << " komponente: ";
		for(int j=0; j<ats[i].size(); j++)
			cout << ats[i][j] << " ";
		cout << endl;
	}
	return 0;
}