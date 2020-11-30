/*input
2 104 103
*/
///a^n%mod randa per O(logn)
#include<bits/stdc++.h>
using namespace std;

long long laipsnis(long long a, long long n, long long mod)
{
	if(n==0)
		return 1;
	else if(n%2==0)
	{
		long long tarp = laipsnis(a, n/2, mod);
		return (tarp*tarp)%mod;
	}
	else
		return (laipsnis(a, n-1, mod)*a)%mod;
}

int main()
{
	int a, n, mod;
	cin >> a >> n >> mod;
	cout << laipsnis(a, n, mod);
	return 0;
}