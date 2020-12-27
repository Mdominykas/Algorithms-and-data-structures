/*Segment tree with lazy propagation
Explanation: segment tree that has array divided in to parts of 2 powers. 
Answers range queries for function which can be answered given results of two parts. 
Support range updates with lazy propagation. when only it childs has to be updated
it stores information in lazy variable and updates only when needed
Source: Competitive Programmer’s Handbook p89
Complexity: O(log(n)) update/query
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int pradzia, pabaiga;
	long long value, lazy;
	node *left, *right;
	node() { }
	node(int pr, int pb, int A[])
	{
		pradzia = pr;
		pabaiga = pb;
		lazy = 0;
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
	long long get(int pr, int pb)
	{
		fix();
		if((pr<=pradzia) && (pabaiga<=pb))
			return value;
		else if ((pabaiga<pr) || (pb<pradzia))
			return INT_MAX;
		else
			return min(left->get(pr, pb), right->get(pr, pb));
	}
	void fix()
	{
		if(lazy!=0)
		{
			if(left!=NULL)
			{
				left->lazy += lazy;
				left->value += lazy;
				right->lazy += lazy;
				right->value += lazy;
			}
			lazy = 0;
		}
	}
	void update(int pr, int pb, long long delta)
	{
		fix();
		if((pr<=pradzia) && (pabaiga<=pb))
		{
  			lazy += delta;
  			value += delta;
		}
		else if ((pabaiga<pr) || (pb<pradzia))
		{
			return;
		}
		else
		{
			left->update(pr, pb, delta);
			right->update(pr, pb, delta);
			value = min(left->value, right->value);
		}
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
			int pr, pb, delta;
			cin >> pr >> pb >> delta;
			medis.update(pr, pb, delta);
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