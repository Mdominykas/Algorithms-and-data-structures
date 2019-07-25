#include<bits/stdc++.h>
using namespace std;

const int max_n = 20;
vector<int> kaimynai[max_n];

int padetis[max_n];
int atejo[max_n];

void paieska_gilyn(int virsune)
{
	padetis[virsune] = 1;
	for(int i=0; i<kaimynai[virsune].size(); i++)
	{
		if(padetis[kaimynai[virsune][i]]==0)
		{
			atejo[kaimynai[virsune][i]] = virsune;
			paieska_gilyn(kaimynai[virsune][i]);
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
		kaimynai[a].push_back(b);
		kaimynai[b].push_back(a);
	}
	for(int i=0; i<n; i++)
	{
		padetis[i] = 0;
		atejo[i] = -1;
	}
	for(int i=0; i<n; i++)
	{
		if(padetis[i]==0)
			paieska_gilyn(i);
	}
	for(int i=0; i<n; i++)
		cout << padetis[i] << " " << atejo[i] << endl;
	return 0;
}