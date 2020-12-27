/*Binary indexed tree (Fenwick tree)
Explanation: data structures to find interval maximum, minimu or sum that is able
to update each element. Each element is contains the partial result that ends in
it and has length of it's lowest 2 power in binary representation. It can easily be 
updated by adding smallest one in binary represantation.
Source: Competitive Programmer’s Handbook p86
Complexity: O(log(n)) per query 
Tested on: lightly tested
*/

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