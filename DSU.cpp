#include<bits/stdc++.h>
using namespace std;
const int max_n = 100000000;
int DSU[max_n];
void init(int n)
{
	for(int i=0; i<=n; i++)
		DSU[i] = i;
}

int tevas(int id)
{
	if(DSU[id]==id)
		return id;
	else
		return DSU[id] = tevas(DSU[id]);
}

void sujungti(int i, int j)
{
	if(tevas(i)==tevas(j))
		return;
	else
		DSU[tevas(i)] = tevas(j);
}

int main()
{
	int n;
	cin >> n;
	init(n);
	return 0;
}