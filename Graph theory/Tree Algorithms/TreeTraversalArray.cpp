/*Tree traversal
Explanation: by going through entire tree starting at root and visiting
each children by depth-first search algorithm builds array in which
elements after node is it's children
Source: Competitive Programmer’s Handbook p134
Complexity: O(E+V)
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;
const int max_n = 10000000;
vector<int> adj[max_n];
int subtreeSize[max_n];
int tree_traversal_array[max_n];
int cur = 0;
int dfs(int id)
{
	tree_traversal_array[cur] = id;
	cur++;
	int dydis = 1;
	for(int i=0; i<adj[id].size(); i++)
	{
		dydis += dfs(adj[id][i]);
	}
	subtreeSize[id] = dydis;
	return dydis;
}

int main()
{
	int n;
	cin >> n;
	for(int i=1; i<n; i++)
	{
		int a;
		cin >> a;
		adj[a].push_back(i); 
	}
	dfs(0);
	for(int i=0; i<n; i++)
		cout << tree_traversal_array[i] << " ";
	cout << endl;
	for(int i=0; i<n; i++)
		cout << subtreeSize[tree_traversal_array[i]] << " ";
	return 0;
}