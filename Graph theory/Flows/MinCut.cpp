/*Min cut algorithm
Explanation: after finding maximum flow minimal cut of graph can be found.
It is only needed to start search from source and reachable egdes which
have been fully filled are minimal cut vertices 
Source: unknown
Complexity: O(E^2V)
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

const int max_n = 103;
const int max_m = 403;

vector<tuple<int, int, int> > edgeList;

vector<pair<int, int> > briaunos[max_n];

vector<int> minCut;

int maxFlow(int n, int source, int sink)
{
	int ans = 0;
	while(true)
	{
		int flow[n], previousEdge[n];
		for(int i=0; i<n; i++)
		{
			flow[i] = 0;
			previousEdge[i] = -1;
		}

		flow[source] = INT_MAX;

		queue<int> eile;
		eile.push(source);

		while(!eile.empty())
		{
			int g = eile.front();
			eile.pop();
			for(int i=0; i<briaunos[g].size(); i++)
			{
				int kita = briaunos[g][i].first;
				int svoris = get<2>(edgeList[briaunos[g][i].second]);
				if((flow[kita]==0) && (flow[kita]<min(flow[g], svoris)))
				{
					flow[kita] = min(flow[g], svoris);
					eile.push(kita);
					previousEdge[kita] = briaunos[g][i].second;
				}
			}
		}

		if(flow[sink]==0)
			break;

		//cout << flow[sink] << endl;

		int v = sink;
		while(v!=source)
		{
			int panaudota = previousEdge[v];
			//cout << v << " (" << panaudota << ")  ";

			get<2>(edgeList[panaudota]) -= flow[sink];
			get<2>(edgeList[1^panaudota]) += flow[sink];

			v = get<0>(edgeList[panaudota]);
		}
		ans += flow[sink];
		//cout << endl;
	}


	bool pasiekiama[n];
	for(int i=0; i<n; i++)
		pasiekiama[i] = false;
	pasiekiama[source] = true;
	queue<int> eile;
	eile.push(source);
	while(!eile.empty())
	{
		int g = eile.front();
		eile.pop();
		for(int i=0; i<briaunos[g].size(); i++)
		{
			if((pasiekiama[briaunos[g][i].first]) || (get<2>(edgeList[briaunos[g][i].second])==0))
				continue;
			pasiekiama[briaunos[g][i].first] = true;
			eile.push(briaunos[g][i].first);
		}
	}
	for(int i=0; 2*i<edgeList.size(); i++)
	{
		if((pasiekiama[get<0>(edgeList[2*i])])^pasiekiama[get<1>(edgeList[2*i])])
		{
			minCut.push_back(i);
		}
	}

	return ans;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for(int i=0; i<m; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		A--;
		B--;
		edgeList.push_back(make_tuple(A, B, C));
		edgeList.push_back(make_tuple(B, A, C));
	
		briaunos[A].push_back({B, 2*i});
		briaunos[B].push_back({A, 2*i+1});
	}

	int ans = maxFlow(n, 0, n-1);
	cout << minCut.size() << " " << ans << "\n";
	for(int i=0; i<minCut.size(); i++)
		cout << minCut[i] + 1 << " ";
	return 0;
}
