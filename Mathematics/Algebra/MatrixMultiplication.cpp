/*input
2 3 4 
1 2 3 4
8 4 2 7
1 2 2
2 7 4
3 6 8
4 2 7
*/
/*Matrix multiplication
Explanation: straight forward algorithm to multiply two matrixes
Source: https://www8.cs.umu.se/kurser/TDBA77/VT06/algorithms/BOOK/BOOK3/NODE138.HTM
Complexity: O(n^3)
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<double> > multiplyMatrixes(vector<vector<double> > a, vector<vector<double> > b)
{
	assert(b.size() > 0);
	assert(a.size() > 0);
	assert(a[0].size() == b.size());
	vector<vector<double> > c(a.size(), vector<double>(b[0].size(), 0));
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = 0; j < b[0].size(); j++)
		{
			for(int k1 = 0; k1 < b.size(); k1++)
				c[i][j] += a[i][k1] * b[k1][j];
		}
	}
	return c;
}


int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<double> > a(n, vector<double>(k, 0)), b(k, vector<double>(m, 0));
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<k; j++)
			cin >> a[i][j];
	}
	for(int i=0; i<k; i++)
	{
		for(int j=0; j<m; j++)
			cin >> b[i][j];
	}
	vector<vector<double> > c = multiplyMatrixes(a, b);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}
	return 0;
}