/*input
5
1 4 2 5 84
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> compress(vector<int> a)
{
	vector<int> b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for(int i=0; i<a.size(); i++)
	{
		a[i] = lower_bound(b.begin(), b.end(), a[i])-b.begin();
	}
	return a;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
	vector<int> b = compress(a);
	for(int i=0; i<n; i++)
		cout << b[i] << " ";
	return 0; 
}