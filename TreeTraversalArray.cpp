/*input
10
0
1
1
1
1
2
4
4
4
*/
#include<bits/stdc++.h>
using namespace std;
const int max_n = 10000000;
vector<int> briaunos[max_n];
int pomedzio_dydis[max_n];
int tree_traversal_array[max_n];
int dab = 0;
int sudaryk(int id)
{
	tree_traversal_array[dab] = id;
	dab++;
	int dydis = 1;
	for(int i=0; i<briaunos[id].size(); i++)
	{
		dydis += sudaryk(briaunos[id][i]);
	}
	pomedzio_dydis[id] = dydis;
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
		briaunos[a].push_back(i); 
	}
	sudaryk(0);
	for(int i=0; i<n; i++)
		cout << tree_traversal_array[i] << " ";
	cout << endl;
	for(int i=0; i<n; i++)
		cout << pomedzio_dydis[tree_traversal_array[i]] << " ";
	return 0;
}