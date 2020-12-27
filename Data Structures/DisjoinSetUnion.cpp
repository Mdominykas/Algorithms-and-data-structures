/*Disjoin set union
Explanation: data structure to store which component element belongs to
it stores parent of each component and can get up to a root while updating it
Can optimized by comparing size of graph
Source: https://cp-algorithms.com/data_structures/disjoint_set_union.html
Complexity: O(alpha(n)) per query (alpha(n) is inverse Ackerman function)
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;
const int max_n = 100000000;

struct DSU
{
	int *parent;
	DSU(int n)
	{
		parent = new int [n+1];
		for(int i=0; i<=n; i++)
			parent[i] = i;
	}

	int findSet(int id)
	{
		if(parent[id]==id)
			return id;
		else
			return parent[id] = findSet(parent[id]);
	}

	void unionSets(int i, int j)
	{
		if(findSet(i)==findSet(j))
			return;
		else
			parent[findSet(i)] = findSet(j);
	}
};


int main()
{
	int n;
	cin >> n;
	DSU naujas(n);
	return 0;
}