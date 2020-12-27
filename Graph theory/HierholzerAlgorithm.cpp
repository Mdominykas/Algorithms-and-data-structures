/*Hierholzer's algorithm
Explanation: algorithm to find Eurelian path or cycle in a graph. It starts at
any vertice and then it builds cycle, until it starting vertice (it can not get
stuck elsewhere). Then one vertice on path with unused edges are chosen and
algorithm continues from it.
Source: https://en.wikipedia.org/wiki/Eulerian_path#Hierholzer's_algorithm
Complexity: O(E)
Tested on: lightly tested
*/

#include<bits/stdc++.h>
using namespace std;
const int max_n = 1000000;
const int max_m = 1000000;
vector<pair<int, int> > briaunos[max_n];
vector<int> gabalai[max_n];

vector<int> EulerCycle;
bool ismesta[max_m];
bool fix(int num)
{
	while(briaunos[num].size()>0)
	{
		if(ismesta[briaunos[num][0].second]==0)
			return true;
		else
		{
			swap(briaunos[num][0], briaunos[num][briaunos[num].size()-1]);
			briaunos[num].pop_back();
		}
	}
	return false;
}

void BuildCycle(int n, int pr)
{
	bool panaudoti[n];
	for(int i=0; i<n; i++)
		panaudoti[i] = 0;
	panaudoti[pr] = 1;
	stack<pair<int, int> > tvarka;
	tvarka.push(make_pair(pr, 0));
	while(!tvarka.empty())
	{
		int num = tvarka.top().first;
		int id = tvarka.top().second;
		int kitas = gabalai[num][id];
		if(panaudoti[kitas]==1)
		{
			EulerCycle.push_back(gabalai[num][id]);
			id++;
			tvarka.pop();
			if(id<gabalai[num].size())
				tvarka.push(make_pair(num, id));
		}
		else
		{
			panaudoti[gabalai[num][id]] = 1;
			if(gabalai[kitas].size()==0)
				continue;
			tvarka.push(make_pair(gabalai[num][id], 0));
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int pr1;
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		briaunos[a].push_back(make_pair(b, i));
		briaunos[b].push_back(make_pair(a, i));
		pr1 = a;
	}
	for(int i=0; i<m; i++)
		ismesta[i] = 0;
	for(int i=0; i<n; i++)
	{
		bool tinkamas = fix(i);
		if(tinkamas)
		{
			int cur = i;
			while(fix(cur))
			{
				gabalai[i].push_back(cur);
				ismesta[briaunos[cur][0].second] = 1;
				cur = briaunos[cur][0].first;
			}
		}
	}
	for(int i=0; i<n; i++)
	{
		if(gabalai[i].size()!=0)
		{
			pr1 = i;
			break;
		}
	}
	BuildCycle(n, pr1);
	for(int i=0; i<EulerCycle.size(); i++)
		cout << EulerCycle[i] << " ";
	return 0;
}