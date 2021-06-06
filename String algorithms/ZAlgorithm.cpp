/*Z-algorithm
Explanation: algorithm creates Z array. That is array z[k], where z[i]
corresponds to size of longest prefix that is also in string from i. I does
so by keeping longest substring [x, y], that could help and updates using z.
Source: https://e-maxx.ru/algo/z_function
Complexity: O(n)
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> zAlgorithm(string s)
{
	int n = s.size();
	vector<int> z(n);
	z[0] = n;
	int l = 0, r = 0;
	for(int i=1; i<n; i++)
	{
		if(i<=r)
			z[i] = min(r - i + 1, z[i-l]);
		while((i + z[i] < n) && (s[z[i]] == s[i+z[i]]))
			z[i]++;
		if(i + z[i] - 1 > r)
		{
			l = i;
			r = i + z[i] - 1;
		}
		//z[i] = y - x;
	}
	return z;
}

int main()
{
	string s;
	cin >> s;
	vector<int> z = zAlgorithm(s);

	for(int i=0; i<z.size(); i++)
		cout << z[i] << " ";


	return 0;
}