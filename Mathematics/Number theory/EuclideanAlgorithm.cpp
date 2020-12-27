/*Euclidean algorihm
Explanation: algorihm returns largest common divisor. It does so by taking 
one number modulo other and repeating it until one becomes 0.
Source: https://en.wikipedia.org/wiki/Euclidean_algorithm#Algorithmic_efficiency
Complexity: O(log(a+b))
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if(a!=0)
		return gcd(b%a, a);
	else
		return b;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b);
	return 0;
}