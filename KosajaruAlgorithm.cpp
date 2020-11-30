/*input
7 10
0 1
0 3
1 0
1 4
2 1
2 6
4 3
5 4
5 2
6 5
*/
#include<bits/stdc++.h>
using namespace std;
const int max_n = 1000000;
vector<int> briaunos[max_n];
vector<int> rbriaunos[max_n];
vector<int> sarasas;
vector<vector<int> > ats;
int num = 0;
bool aplankyta[max_n];
void dfs1(int id)
{
	for(int i=0; i<briaunos[id].size(); i++)
	{
		if(!aplankyta[briaunos[id][i]])
		{
			aplankyta[briaunos[id][i]] = 1;
			dfs1(briaunos[id][i]);
		}
	}
	sarasas.push_back(id);
}

void dfs2(int id, int num)
{
	for(int i=0; i<rbriaunos[id].size(); i++)
	{
		int kitas = rbriaunos[id][i];
		if(!aplankyta[kitas])
		{
			aplankyta[kitas] = 1;
			dfs2(kitas, num);
		}
	}
	ats[num].push_back(id);
}

void Kosaraju(int n)
{
	for(int i=0; i<n; i++)
	{
		aplankyta[i] = 0;
	}
	for(int i=0; i<n; i++)
	{
		if(!aplankyta[i])
		{
			aplankyta[i] = 1;
			dfs1(i);
		}
	}
	for(int i=0; i<n; i++)
	{
		aplankyta[i] = 0;
	}
	for(int i=0; i<n/2; i++)
		swap(sarasas[i], sarasas[n-1-i]);
	for(int i=0; i<n; i++)
	{
		if(!aplankyta[sarasas[i]])
		{
			ats.push_back(vector<int>());
			aplankyta[sarasas[i]] = 1;
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
		briaunos[a].push_back(b);
		rbriaunos[b].push_back(a);
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