/*Prefix sum array
Explanation: can answer sums querys in constant time after linear time
precomputation. It stores intermediante values to every state and computes
final result from that
Source: Competitive Programmer’s Handbook p84
Complexity: O(1) after O(n) precomputation
Tested on: lightly tested
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
	return 0;
}