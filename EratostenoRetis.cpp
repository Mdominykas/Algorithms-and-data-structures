#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int masyvas[N+1];
	for(int i=0; i<=N; i++)
		masyvas[i] = 0;
	vector<int> pirminiai;
	for(int i=2; i<=sqrt(N); i++)
	{
		if(masyvas[i]==0)
		{
			pirminiai.push_back(i);
			for(int j=2; j<=N/i; j++)
				masyvas[i*j] = 1;
		}
	}
	for(int i=sqrt(N)+1; i<=N; i++)
	{
		if(masyvas[i]==0)
			pirminiai.push_back(i);
	}
	for(int i=0; i<pirminiai.size(); i++)
		cout << pirminiai[i] << " ";
	return 0;
}