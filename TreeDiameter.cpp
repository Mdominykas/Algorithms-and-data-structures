/*input
7
5 1
1 4
1 0
0 2
0 3
3 6
*/
#include<bits/stdc++.h>
using namespace std;

const int max_n = 20;
vector<int> kaimynai[max_n];

int padetis[max_n];
int gylis[max_n];
int giliausia = 0;

void paieska_gilyn(int virsune)
{
	padetis[virsune] = 1;
	for(int i=0; i<kaimynai[virsune].size(); i++)
	{
		if(padetis[kaimynai[virsune][i]]==0)
		{
			gylis[kaimynai[virsune][i]] = gylis[virsune] + 1;
			if(gylis[kaimynai[virsune][i]]>gylis[giliausia])
				giliausia = kaimynai[virsune][i];

			paieska_gilyn(kaimynai[virsune][i]);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for(int i=1; i<n; i++)
	{
		int a, b;
		cin >> a >> b;
		kaimynai[a].push_back(b);
		kaimynai[b].push_back(a);
	}
	for(int i=0; i<n; i++)
	{
		gylis[i] = 0;
		padetis[i] = 0;
	}
	paieska_gilyn(0);
	for(int i=0; i<n; i++)
	{
		gylis[i] = 0;
		padetis[i] = 0;
	}

	paieska_gilyn(giliausia);
	cout << "medzio diametras: " << gylis[giliausia] << endl;
	return 0;
}