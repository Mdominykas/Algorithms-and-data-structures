#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> pirminiai;
	int N;
	cin >> N;
	pirminiai.push_back(2);
	for(int i=3; i<=N; i+=2)
	{
		bool tinka = 1;
		for(int j=0; j<pirminiai.size() && i>=sqrt(pirminiai[j]); j++)
		{
			if(i%pirminiai[j]==0)
			{
				tinka = 0;
				break;
			}
		}
		if(tinka==1)
			pirminiai.push_back(i);
	}
	for(int i=0; i<pirminiai.size(); i++)
		cout << pirminiai[i] << " ";
	return 0;
}