/*input
3 
3 5
4 7
2 3
*/
//chinese remainder theorem
//jei visi m_i yra tarpusavyje pirminiai
///randa sistemos x=a_i mod m_i sprendini
#include<bits/stdc++.h>
using namespace std;

int main()
{
	///jei ieskant mod, tai mod = lcm(m_1, m_2...m_n);
	int n;
	cin >> n;
	long long a[n], m[n];
	for(int i=0; i<n; i++)
		cin >> a[i] >> m[i];
	long long sandauga = 1;
	for(int i=0; i<n; i++)
		sandauga *= m[i];
	long long x = 0;
	for(int i=0; i<n; i++)
	{
		sandauga /= m[i];
		x += sandauga*a[i];
		sandauga *= m[i];
	}
	cout << x;
	return 0;
}