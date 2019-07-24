#include<bits/stdc++.h>
using namespace std;

int dbd(int a, int b)
{
	if(a!=0)
		return dbd(b%a, a);
	else
		return b;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << dbd(a, b);
	return 0;
}