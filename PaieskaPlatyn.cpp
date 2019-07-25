#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int main()
{
	int n, m;
	cin >> n >> m;
	queue<int> eile;
	int atstumas[n];
	for(int i=0; i<n; i++)
		atstumas[i] = INF;
	vector<int> kaimynai[n];
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		kaimynai[a].push_back(b);
		kaimynai[b].push_back(a);
	}
	atstumas[0] = 0;
	eile.push(0);
	while(!eile.empty())
	{
		int g = eile.front();
		for(int i=0; i<kaimynai[g].size(); i++)
		{
			if(atstumas[kaimynai[g][i]]>atstumas[g]+1)
			{
				atstumas[kaimynai[g][i]] = atstumas[g] + 1;
				eile.push(kaimynai[g][i]);
			}
		}
		eile.pop();
	}
	for(int i=0; i<n; i++)
		cout << atstumas[i] << " ";
	return 0;
}