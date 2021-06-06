/*Sieve of Eratosthenes
Explanation: algorithm goes through all the numbers and when it finds
prime number it marks all it's multiples as not primes
Source: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Algorithmic_complexity
Complexity: O(nlog(log(n)))
Tested on: Codeforces 1499D - the Number Of Pairs
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int arr[N+1];
	for(int i=0; i<=N; i++)
		arr[i] = 0;
	vector<int> primes;
	for(int i=2; i<=sqrt(N); i++)
	{
		if(arr[i]==0)
		{
			primes.push_back(i);
			for(int j=i; j<=N; j+=i)
				arr[j] = 1;
		}
	}
	for(int i=sqrt(N)+1; i<=N; i++)
	{
		if(arr[i]==0)
			primes.push_back(i);
	}
	for(int i=0; i<primes.size(); i++)
		cout << primes[i] << " ";
	return 0;
}