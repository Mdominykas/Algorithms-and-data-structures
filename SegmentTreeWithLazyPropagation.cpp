/*input
4
1 2 3 4
4
? 0 3
+ 0 3 -1
? 0 1
? 1 2
*/
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int pradzia, pabaiga;
	long long verte, lazy;
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
			verte = A[pradzia];
		}
		else
		{
			left = new node(pr, (pr+pb)/2, A);
			right = new node((pr+pb)/2+1, pb, A);
			verte = min(left->verte, right->verte);
		}
	}
	void update(int id, long long delta)
	{
		fix();
		if(pradzia==pabaiga)
			verte += delta;
		else
		{
			if(left->pabaiga<id)
				right->update(id, delta);
			else
				left->update(id, delta);
			verte = min(left->verte, right->verte);
		}
	}
	long long get(int pr, int pb)
	{
		fix();
		if((pr<=pradzia) && (pabaiga<=pb))
			return verte;
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
				left->verte += lazy;
				right->lazy += lazy;
				right->verte += lazy;
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
  			verte += delta;
		}
		else if ((pabaiga<pr) || (pb<pradzia))
		{
			return;
		}
		else
		{
			left->update(pr, pb, delta);
			right->update(pr, pb, delta);
			verte = min(left->verte, right->verte);
		}
	}
	void spausdinti()
	{
		if(left==NULL)
			cout << verte << " ";
		else
		{
			left->spausdinti();
			right->spausdinti();
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