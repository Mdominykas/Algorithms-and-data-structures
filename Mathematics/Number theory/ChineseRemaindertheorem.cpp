/*input
3 
3 5
4 7
2 3
*/
/*Chinese remainder theorem
Explanation: alogrithm finds number that gives given remainder modulo every
given coprime number 
Source: https://rosettacode.org/wiki/Chinese_remainder_theorem#C.2B.2B
Complexity: O(N)
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long a[n], modulo[n];
	for(int i=0; i<n; i++)
		cin >> a[i] >> modulo[i];
	long long multiplicand = 1;
	for(int i=0; i<n; i++)
		multiplicand *= modulo[i];
	long long x = 0;
	for(int i=0; i<n; i++)
	{
		multiplicand /= modulo[i];
		x += multiplicand*a[i];
		multiplicand *= modulo[i];
	}
	cout << x;
	return 0;
}