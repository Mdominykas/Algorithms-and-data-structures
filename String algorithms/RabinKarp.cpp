/*Rabin Karp
Explanation: to search for string s in other string t.
It uses rolling hashes and compares strings only if hashes matdhc
Source: mit ocw 6.006
Complexity: O(|t|+[s]*m), m - number of matches
Tested on: lightly tested
*/
#include<bits/stdc++.h>
#include<unistd.h>
#include "PolynomialHashing.h"
using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;
	RollingHash sHash, tHash;
	sHash.generateBase();
	tHash.copyValues(sHash);
	for(int i = 0; i < s.size(); i++)
	{
		sHash.add(s[i]);
		tHash.add(t[i]);
	}

	int numberOfMatches = 0;
	int i = s.size();
	while(i <= t.size())
	{
		if(tHash.hashValue == sHash.hashValue)
		{
			bool equal = true;
			for(int j = 0; j < s.size(); j++)
			{
				if(s[j] !=  t[i - s.size() + j])
					equal = false;
			}
			if(equal)
				numberOfMatches++;
		}
		if(i < t.size())
		{
			tHash.add(t[i]);
			tHash.remove(t[i-s.size()]);
		}
		i++;
	}
	cout << "numberOfMatches = " << numberOfMatches << endl;
}