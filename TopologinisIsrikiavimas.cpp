/*input
7 6
1 2
2 4
1 3
5 3
3 6
6 0
*/
#include<bits/stdc++.h>
using namespace std;

const int max_n = 1000000;
int ateinantys[max_n];
vector<int> kaimynai[max_n];

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++)
		ateinantys[i] = 0;
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		kaimynai[a].push_back(b);
		ateinantys[b]++;
	}
	queue<int> tuscios;
	int seka[n], numeris = 0;
	for(int i=0; i<n; i++)
	{
		if(ateinantys[i]==0)
		{
			tuscios.push(i);
			seka[numeris] = i;
			numeris++;
		}
	}
	while(!tuscios.empty())
	{
		int g = tuscios.front();
		for(int i=0; i<kaimynai[g].size(); i++)
		{
			ateinantys[kaimynai[g][i]]--;
			if(ateinantys[kaimynai[g][i]]==0)
			{
				seka[numeris] = kaimynai[g][i];
				numeris++;
				tuscios.push(kaimynai[g][i]);
			}
		}
		tuscios.pop();
	}
	for(int i=0; i<n; i++)
		cout << seka[i] << " ";
	return 0;
}