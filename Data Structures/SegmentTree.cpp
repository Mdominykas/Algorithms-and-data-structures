/*Segment tree
Explanation: simple segment tree that has array divided in to parts of
2 powers. Answers range queries for function which can be answered given 
results of two parts. Can also support range updates with lazy propagation 
Source: Competitive Programmer’s Handbook p89
Complexity: O(log(n)) update/query
Tested on: Codeforces 1843C Skyline Photo
*/
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int pradzia, pabaiga;
	long long value;
	node *left, *right;
	node() { }
	node(int pr, int pb, int A[])
	{
		pradzia = pr;
		pabaiga = pb;
		if(pradzia==pabaiga)
		{
			left = NULL;
			right = NULL;
			value = A[pradzia];
		}
		else
		{
			left = new node(pr, (pr+pb)/2, A);
			right = new node((pr+pb)/2+1, pb, A);
			value = min(left->value, right->value);
		}
	}
	void update(int id, long long delta)
	{
		if(pradzia==pabaiga)
			value += delta;
		else
		{
			if(left->pabaiga<id)
				right->update(id, delta);
			else
				left->update(id, delta);
			value = min(left->value, right->value);
		}
	}
	long long get(int pr, int pb)
	{
		if((pr<=pradzia) && (pabaiga<=pb))
			return value;
		else if ((pabaiga<pr) || (pb<pradzia))
			return INT_MAX;
		else
			return min(left->get(pr, pb), right->get(pr, pb));
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];
	node medis(0, n-1, a);
	int q;
	cin >> q;
	while(q--)
	{
		char simb;
		cin >> simb;		
		if(simb=='+')
		{
			int id, delta;
			cin >> id >> delta;
			medis.update(id, delta);
		}
		else
		{
			int pr, pb;
			cin >> pr >> pb;
			cout << medis.get(pr, pb) << "\n";
		}
	}
	return 0;	
}