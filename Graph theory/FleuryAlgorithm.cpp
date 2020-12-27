/*Fleury's algorithm
Explanation: algorithm to find Euler's path or Euler's cycle. 
Algorithm goes thorugh graph and check if egde is a bridge.
If edge is not or all edges from that vertice are bridges 
then it is added to the path
Source: unknown
Complexity: O((V+E)^2)
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

const int max_n = 10000;
int briaunos[max_n][max_n];
int briaunu_skaicius[max_n];
int bridges[max_n][max_n];
vector<int> kelias;
int aplankyta[max_n];

void paieska_platyn(int x)
{
	aplankyta[x] = 1;
	for(int i=0; i<max_n; i++)
	{
		if((briaunos[x][i]>0) && (aplankyta[i]==0))
			paieska_platyn(i);
	}
}

int tiltas(int x, int y)
{
	if(briaunos[x][y]>1)
		return false;
	else if(bridges[x][y]==1)
		return true;
	else
	{
		briaunos[x][y]--;
		briaunos[y][x]--;
		for(int i=0; i<max_n; i++)
			aplankyta[i] = 0;
		paieska_platyn(x);
		briaunos[x][y]++;
		briaunos[y][x]++;
		bridges[x][y] = 1-aplankyta[y];
		return bridges[x][y];
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	int nelyg = 0;
	int virsune = 0;
	for(int i=0; i<n; i++)
	{
		briaunu_skaicius[i] = 0;
		for(int j=0; j<n; j++)
		{
			briaunos[i][j] = 0;
			bridges[i][j] = 0;
		}
	}
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		briaunos[a][b]++;
		briaunos[b][a]++;
		briaunu_skaicius[a]++;
		briaunu_skaicius[b]++;
		virsune = a;
	}
	for(int i=0; i<n; i++)
	{
		if(briaunu_skaicius[i]%2!=0)
		{
			nelyg++;
			virsune = i;
		}
	}
	int dalykas = 0 ;
	kelias.push_back(virsune);
	if((nelyg==0) || (nelyg==2))
	{
		while(briaunu_skaicius[virsune]!=0)
		{
			dalykas++;
			int suma = 0;
			for(int i=0; i<n; i++)
			{
				suma += briaunos[virsune][i];
				if(briaunos[i][virsune]>0)
				{
					if((tiltas(virsune, i)==0) || (suma==briaunu_skaicius[virsune]))
					{
						kelias.push_back(i);
						briaunos[virsune][i]--;
						briaunos[i][virsune]--;
						briaunu_skaicius[virsune]--;
						briaunu_skaicius[i]--;
						virsune = i;
						break;
					}
				}
			}
		}
	}
	if(kelias.size()==m+1)
	{
		cout << "kelias: "; 
		for(int i=0; i<kelias.size(); i++)
			cout << kelias[i] << " ";
	}
	else
		cout << "kelias neegzistuoja";
	return 0;
}