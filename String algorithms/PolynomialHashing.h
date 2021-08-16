/*Polynomial string hashing (also called rolling hash)
Explanation: for prime number sum of s_i * p^i is calculated mod other
big number. Then if hashes match, then it is likely that strings are equal
Source: http://web.cs.unlv.edu/larmore/Courses/CSC477/F14/Assignments/horners.pdf
Complexity: O(n)
Tested on: untested
*/
#pragma once
#include<bits/stdc++.h>
using namespace std;

struct RollingHash
{
	long long hashValue = 0;
	int base = 31, inverse = 838709685;
	long long removal = 838709685;
	int mod = 1e9 + 9;

	void add(int c)
	{
		hashValue *= base;
		hashValue += c;
		hashValue %= mod;
		removal *= base;
		removal %= mod;
	}
	void remove(int c)
	{
		hashValue -= c*removal;
		hashValue += mod;
		if(hashValue>mod)
			hashValue -= mod;
		removal *= inverse;
		removal %= mod;
	}

	void generateBase()
	{
		hashValue = 0;
		srand(time(NULL));
		bool isPrime = false;
		mod = 1e8 + rand()%(900000000);
		while(!isPrime)
		{
			mod++;
			isPrime = true;
			int modSqrt = sqrt(mod);
			for(int i=2; i<=modSqrt; i++)
			{
				if(mod % i == 0)
				{
					isPrime = false;
					break;
				}
			}
		}
		int base = 1000+(rand()%mod-1000);
		while(!isGenerator(base, mod))
		{
			base++;
		}
		inverse = exponentMod(base, mod-2, mod);
		removal = inverse;
	}

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

	bool isGenerator(int base, int mod)
	{
		int number = mod - 1;
		
		for(int i=2; i*i<number; i++)
		{
			if(number%i == 0)
			{
				if(exponentMod(base, (mod-1)/i, mod) == 1)
					return false;
			}
			while(number % i == 0)
				number /= i;
		}
		if(number != 1)
			return exponentMod(base, (mod-1)/number, mod) == 1;
		return true;	
	}

	void copyValues(RollingHash &other)
	{
		other.hashValue = hashValue;
		other.base = base;
		other.mod = mod;
		other.inverse = inverse;
		other.removal = removal;
	}
};