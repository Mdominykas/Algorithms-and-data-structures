/*input
5 6
1 2 2
2 3 7
0 3 9
1 0 5
0 4 1
3 4 2
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;
	int atstumas[N][N];
	const int INF = 1000000;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			atstumas[i][j] = INF;
		atstumas[i][i] = 0;
	}
	for(int i=0; i<M; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		atstumas[a][b] = min(atstumas[a][b], w);
		atstumas[b][a] = min(atstumas[b][a], w);
	}
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			for(int k=0; k<N; k++)
			{
				atstumas[j][k] = min(atstumas[j][k], atstumas[k][i] + atstumas[i][j]);
				atstumas[k][j] = min(atstumas[k][j], atstumas[k][i] + atstumas[i][j]);
			}
		}
	}
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			cout << atstumas[i][j] << " ";
		cout << endl;
	}
	return 0;
}