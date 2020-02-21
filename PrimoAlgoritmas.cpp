#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e5;
const int INF = 1e9;
vector<pair<int, int> > kaimynai[max_n];
int atstumas[max_n];
int tevas[max_n];

int main()
{
	int n, m;
	cin >> n >> m;
	int pradine, galine;
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		kaimynai[a].push_back(make_pair(b, c));
		kaimynai[b].push_back(make_pair(a, c));
	}
	cin >> pradine >> galine;
	for(int i=0; i<n; i++)
		atstumas[i] = INF;
	atstumas[pradine] = 0;
	tevas[pradine] = pradine;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > eile;
	eile.push(make_pair(0, pradine));
	while(!eile.empty())
	{
		int virsune = eile.top().second;
		int ilgis = eile.top().first;
		eile.pop();
		for(int i=0; i<kaimynai[virsune].size(); i++)
		{
			int kitas = kaimynai[virsune][i].first;
			int briauna = kaimynai[virsune][i].second;
			if(atstumas[kitas]>briauna + atstumas[virsune])
			{
				tevas[kitas] = virsune;
				atstumas[kitas] = briauna + atstumas[virsune];
				eile.push(make_pair(atstumas[kitas], kitas));
			}
		}
	}
	cout << atstumas[galine];
	return 0;
}