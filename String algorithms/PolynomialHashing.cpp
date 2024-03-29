/*Polynomial string hashing
Explanation: for prime number sum of s_i * p^i is calculated mod other
big number. Then if hashes match, then it is likely that strings are equal
Source: http://web.cs.unlv.edu/larmore/Courses/CSC477/F14/Assignments/horners.pdf
Complexity: O(n)
Tested on: lightly tested
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