#include<bits/stdc++.h>
using namespace std;

struct BIT
{
	int N;
	long long *mas = new long long [100];
	BIT() {}
	BIT(int N1)
	{
		N = 2*N1 + 2;
		mas = new long long[N];
		for(int i=0; i<N; i++)
			mas[i] = 0;
	}
	void update(int id, long long delta)
	{
		while(id<N)
		{
			mas[id] += delta;
			id += (id&-id);
		}
	}
	long long sum(int pr)
	{
		long long ats = 0;
		while(pr)
		{
			ats += mas[pr];
			pr -= (pr&-pr);
		}
		return ats;
	}
	long long get(int pr, int pb)
	{
		if(pr)
			return sum(pb)-sum(pr-1);
		return sum(pb);
	}
};

int main()
{
	return 0;
}