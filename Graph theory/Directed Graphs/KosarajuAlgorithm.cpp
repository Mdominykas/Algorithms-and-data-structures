/*Kosajaru Algorithm
Explanation: algorithm goes through the nodes by depth-first search started at 
each unvisited vertice and stores them by out-time. Then it goes through those
vertice in reverse order and starts dfs with reverse graph at each unvisited. It
works due to the fact that reverse graph has same strongly connected components
Source: Competitive Programmer’s Handbook p158
Complexity: O(E+V)
Tested on: https://codeforces.com/gym/101398 problem I
*/

#include<bits/stdc++.h>
using namespace std;
const int max_n = 1000000;
vector<int> adj[max_n];
vector<int> radj[max_n];
vector<int> order;
int num = 0;
int scc[max_n];
bool used[max_n];


void dfsTopo(int id)
{
	used[id] = true;
	for(int i=0; i<adj[id].size(); i++)
	{
		if(!used[adj[id][i]])
			dfsTopo(adj[id][i]);
	}
	order.push_back(id);
}


void dfsScc(int id, int num)
{
	used[id] = true;
	scc[id] = num;
	for(int i=0; i<radj[id].size(); i++)
	{
		if(!used[radj[id][i]])
			dfsScc(radj[id][i], num);
	}
}

void Kosaraju(int n)
{
	for(int i=0; i<n; i++)
		used[i] = false;
	for(int i=0; i<n; i++)
	{
		if(!used[i])
			dfsTopo(i);
	}
	for(int i=0; i<n; i++)
		used[i] = false;
	reverse(order.begin(), order.end());
	for(int i=0; i<n; i++)
	{
		if(!used[order[i]])
		{
			used[order[i]] = 1;
			dfsScc(order[i], num);
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
	for(int i=0; i<n; i++)
	{
		cout << scc[i] << " ";
	}
	return 0;
}