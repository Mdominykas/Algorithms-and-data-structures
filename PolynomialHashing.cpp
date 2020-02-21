/*input
aa
*/
#include<bits/stdc++.h>
using namespace std;

long long compute_hash(string &s)
{
	int p =31, mod = 1e9+9;
	long long hash_value = 0, p_pow = 1;
	for(char c : s)
	{
		hash_value = (hash_value + (c-'a'+1) * p_pow) % mod;
		p_pow = (p_pow*p)%mod;
	}
	return hash_value;
}

int main()
{
	string a;
	cin >> a;
	cout << compute_hash(a);
	return 0;
}