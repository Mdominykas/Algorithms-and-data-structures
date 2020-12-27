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

///multiplies matrixes a of size nxk and b of size kxm and stores results in c
vector<vector<int> > multiplyMatrixes( vector<vector<int> > a, vector<vector<int> > b, int n, int m, int k)
{
	vector<vector<int> > c(n, vector<int>(m, 0));
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			for(int k1=0; k1<k; k1++)
				c[i][j] += a[i][k1] * b[k1][j];
		}
	}
	return c;
}


int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int> > a(n, vector<int>(k, 0)), b(k, vector<int>(m, 0));
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
	vector<vector<int> > c = multiplyMatrixes(a, b, n, m, k);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}
	return 0;
}