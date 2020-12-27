/*Tree diameter
Explanation: finds the diameter of the tree by starting DFS from one vertice
and finding farthest vertice. Then starts dfs from that vertice and the 
farthest it together with farthest vertice form diameter of tree
Source: Competitive Programmer’s Handbook p128
Complexity: O(E)
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

const int max_n = 20;
vector<int> adjacent[max_n];

bool visited[max_n];
int depth[max_n];
int giliausia = 0;

void paieska_gilyn(int virsune)
{
	visited[virsune] = 1;
	for(int i=0; i<adjacent[virsune].size(); i++)
	{
		if(visited[adjacent[virsune][i]]==0)
		{
			depth[adjacent[virsune][i]] = depth[virsune] + 1;
			if(depth[adjacent[virsune][i]]>depth[giliausia])
				giliausia = adjacent[virsune][i];

			paieska_gilyn(adjacent[virsune][i]);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for(int i=1; i<n; i++)
	{
		int a, b;
		cin >> a >> b;
		adjacent[a].push_back(b);
		adjacent[b].push_back(a);
	}
	for(int i=0; i<n; i++)
	{
		depth[i] = 0;
		visited[i] = 0;
	}
	paieska_gilyn(0);
	for(int i=0; i<n; i++)
	{
		depth[i] = 0;
		visited[i] = 0;
	}

	paieska_gilyn(giliausia);
	cout << "medzio diametras: " << depth[giliausia] << endl;
	return 0;
}