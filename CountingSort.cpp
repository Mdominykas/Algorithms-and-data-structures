#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int masyvas[N];
	for(int i=0; i<N; i++)
		cin >> masyvas[i];
	int maxi = masyvas[0];
	for(int i=1; i<N; i++)
		maxi = max(maxi, masyvas[i]);
	int aibe[maxi+1];
	for(int i=0; i<=maxi; i++)
		aibe[i] = 0;
	for(int i=0; i<N; i++)
		aibe[masyvas[i]]++;
	int numeris = 0;
	for(int i=0; i<=maxi; i++)
	{
		for(int j=0; j<aibe[i]; j++)
		{
			masyvas[numeris] = i;
			numeris++;
		}
	}
	for(int i=0; i<N; i++)
		cout << masyvas[i] << " ";
	return 0;
}