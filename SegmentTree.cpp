/*input
4
1 2 3 4
4
? 0 3
+ 3 -1
? 0 1
? 1 2
*/
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int pradzia, pabaiga;
	long long verte;
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
		if((pr<=pradzia) && (pabaiga<=pb))
			return verte;
		else if ((pabaiga<pr) || (pb<pradzia))
			return INT_MAX;
		else
			return min(left->get(pr, pb), right->get(pr, pb));
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