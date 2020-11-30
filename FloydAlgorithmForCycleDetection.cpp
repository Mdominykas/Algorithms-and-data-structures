/*input
6
1
2
3
4
5
3
0
*/
///per O(n) laiko ir O(1) atminties kryptiniame grafe
///kuriame is kiekvienos virsunes iseina viena briauna
///i kokio ilgio cikla pateksi, jei pradesi nuo x
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int succ[N];
	for(int i=0; i<N; i++)
		cin >> succ[i];
	int x;
	cin >> x;
	int a = succ[x];
	int b = succ[succ[x]];
	while(a!=b)
	{
		a = succ[a];
		b = succ[succ[b]];
	}
	b = succ[a];
	int length = 1;
	while(a!=b)
	{
		b = succ[b];
		length++;
	}
	a = x;
	while(a!=b)
	{
		a = succ[a];
		b = succ[b];
	}
	cout << "pirma is ciklo yra: " << a << endl;
	cout << "ilgis: " <<length;
	return 0;
}