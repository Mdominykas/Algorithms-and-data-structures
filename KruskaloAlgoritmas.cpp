#include<bits/stdc++.h>
using namespace std;
const int max_n = 100000000;
int DSU[max_n];
void init(int n)
{
	for(int i=0; i<=n; i++)
		DSU[i] = i;
}

int tevas(int id)
{
	if(DSU[id]==id)
		return id;
	else
		return DSU[id] = tevas(DSU[id]);
}

bool sujungti(int i, int j)
{
	if(tevas(i)==tevas(j))
		return false;
	else
	{
		DSU[tevas(i)] = tevas(j);
		return true;
	}
}

struct briauna
{
	int pirma, antra;
	int ilgis;
	briauna() {}
	briauna(int pirma1, int antra1, int ilgis1)
	{
		pirma = pirma1;
		antra = antra1;
		ilgis = ilgis1;
	}
	bool operator < (const briauna &kita) const
	{
		return ilgis<kita.ilgis;
	}
};

int main()
{

	int n, m;
	cin >> n >> m;
	vector<briauna> briaunos;
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		briauna nauja(a, b, c);
		briaunos.push_back(nauja);
	}
	sort()
	init(n);
	vector<briauna> medis;
	for(int i=0; i<briaunos.size(); i++)
	{
		if(sujungti(briaunos[i].pirma, briaunos[i].antra)==true)
			medis.push_back(briaunos[i]);
	}
}