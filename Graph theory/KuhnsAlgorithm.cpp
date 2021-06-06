/*{Algorithm name}
Explanation: algorithm finds maximum matching in bipartite graph. It must be spil
before hand into both sides and adj gives edges from one to the other. While 
there still is augmented path algorithm adds it to all found.
Source: https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html#toc-tgt-4
Complexity: O(EV)
Tested on: BAPC 2017 Programming Tutors
*/

#include<bits/stdc++.h>
using namespace std;
int N;

const int max_n = 102;
vector<int> adj[max_n];

bool visited[max_n];

int parent[max_n];
int child[max_n];

bool dfs(int id)
{
	if(visited[id])
		return false;

	visited[id] = true;
	
	for(int i=0; i<adj[id].size(); i++)
	{
		int next = adj[id][i];
		if((parent[next] == -1) || (dfs(parent[next])))
		{
			parent[next] = id;
			child[id] = next;
			return true;
		}
	}
	return false;
}

int maximumMatching()
{
	int ats = 0;
	bool found = true;
	for(int i=0; i<N; i++)
	{
		parent[i] = -1;
		child[i] = -1;
	}
	while(found)
	{
		found = false;
		for(int i=0; i<N; i++)
			visited[i] = false;

		for(int i=0; i<N; i++)
		{
			if((!visited[i]) && (child[i] == -1))
			{
				if(dfs(i))
				{
					found = true;
					ats++;
					break;
				}
			}
		}
	}
	return ats;
}