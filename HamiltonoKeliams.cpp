///Dirac's theorem: jei kiekvonos virsunes laipsnis bent n/2, tai grafas turi Hamiltono cikla
///Ore's theorem jei bet kuriu negretumu virsuniu laipsniu suma bent n, tai grafas turi Hamiltono cikla
#include<bits/stdc++.h>
using namespace std;

const int max_n = 100;
vector<int> kaimynai[max_n];
int seka[max_n];
bool aplankyta[max_n];

bool ieskok(int dabartine, int liko)
{
	aplankyta[dabartine] = true;
	seka[liko] = dabartine;
	if(liko==0)
	{
		aplankyta[dabartine] = false;
		return true;
	}
	for(int i=0; i<kaimynai[dabartine].size(); i++)
	{
		if(aplankyta[kaimynai[dabartine][i]]==false)
		{
			if(ieskok(kaimynai[dabartine][i], liko-1)==true)
			{
				aplankyta[dabartine] = false;
				return true;
			}

		}
	}
	aplankyta[dabartine] = false;
	return false;
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
		aplankyta[i] = false;
		seka[i] = -1;
	}
	for(int i=0; i<n; i++)
	{
		if(ieskok(i, n-1)==true)
		{
			for(int j=n-1; j>=0; j--)
				cout << seka[j] << " ";
			cout << endl;
		}
	}
	return 0;
}