/*input
3
1 4 1
3
1 1
1 2
0 2
*/
#include<bits/stdc++.h>
using namespace std;
const int max_N = 100004;
long long mas[max_N];
long long prefix[max_N];

void precompute(int N)
{
	prefix[0] = 0;
	for(int i=1; i<=N; i++)
	{
		prefix[i] = prefix[i-1] + mas[i-1];
	}
}


long long get(int pr, int pb)
{
	return prefix[pb+1]-prefix[pr];
}

int main()
{
	int N, Q;
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> mas[i];
	precompute(N);
	cin >> Q;
	for(int i=0; i<Q; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << get(a, b) << "\n";
	}
	return 0;
}