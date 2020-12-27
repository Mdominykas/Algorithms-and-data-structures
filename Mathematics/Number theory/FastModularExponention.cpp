/*input
2 104 103
*/
/*Fast modular exponention
Explanation: return exponent of a to n-th degree to a modulo. It does
it efficiently by splitting number in half and saving the result, when it
is needed
Source: https://www.geeksforgeeks.org/modular-exponentiation-recursive/
Complexity: O(log(n))
Tested on: lightly tested
*/
///a^n%mod randa per O(logn)
#include<bits/stdc++.h>
using namespace std;

long long exponentMod(long long a, long long n, long long mod)
{
	if(n==0)
		return 1;
	else if(n%2==0)
	{
		long long tarp = exponentMod(a, n/2, mod);
		return (tarp*tarp)%mod;
	}
	else
		return (exponentMod(a, n-1, mod)*a)%mod;
}

int main()
{
	int a, n, mod;
	cin >> a >> n >> mod;
	cout << exponentMod(a, n, mod);
	return 0;
}