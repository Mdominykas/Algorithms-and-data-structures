#include<bits/stdc++.h>
using namespace std;

int dvejetaine_paieska(int ieskomas, int kaire, int desine, int masyvas[])
{
	if(kaire>desine)
		return -1;
	else
	{
		int v = (kaire+desine)/2;
		if(masyvas[v]>ieskomas)
			return dvejetaine_paieska(ieskomas, kaire, v-1, masyvas);
		else if (masyvas[v]<ieskomas)
			return dvejetaine_paieska(ieskomas, v+1, desine, masyvas);
		else
			return v;
	}
}

int main()
{
	int N;
	cin >> N;
	int masyvas[N];
	for(int i=0; i<N; i++)
		cin >> masyvas[i];
	int x;
	cin >> x;
	cout << dvejetaine_paieska(x, 0, N-1, masyvas);
	return 0;
}