/*input
5 12
0 1 1
1 2 3
2 3 2
1 3 5
2 4 1
2 3 2
2 1 3
3 2 2
3 1 5
4 2 1
3 2 2
3 4 -7
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;
	vector<tuple<int, int, int> > briaunos;
	for(int i=0; i<M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		briaunos.push_back(make_tuple(a, b, c));
	}
	sort(briaunos.begin(), briaunos.end());
	const int INF = 1000000;
	int atstumai[N];
	for(int i=0; i<N; i++)
		atstumai[i] = INF;
	atstumai[0] = 0;

	for(int i=0; i<N; i++)
	{
		for(auto e : briaunos)
		{
			int a, b, w;
			tie(a, b, w) = e;
			atstumai[b] = min(atstumai[b], atstumai[a]+w);
		}
	}
	bool negative_cycle = 0;
	for(auto e : briaunos)
	{
		int a, b, w;
		tie(a, b, w) = e;
		if(atstumai[b]>atstumai[a]+w)
		{
			negative_cycle = 1;
		}
	}
	if(negative_cycle)
		cout << "neigiamas ciklas" << endl;
	else
	{
		for(int i=0; i<N; i++)
			cout << atstumai[i] << endl;
	}
}