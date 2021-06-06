/*Euler's tour technique for lowest common ansestor
Explanation: tree is traversed by adding vertice each time it walked
visited. After that lowest common ansestor of two vertices is node with
minimal depth between both of them so it can be answered with sparse table
Source: Competitive Programmer’s Handbook p168
Complexity: O(1) per query after O(nlog(n)) preprocessing 
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;
const int max_n = 1000005;
vector<int> adj[max_n];
int depth[2*max_n-1];
int timeIn[max_n], timeOut[max_n];
int traversalArray[2*max_n-1];


const int logn = 22;
int lookup[2*max_n-1][logn];///saugo indeksus su minimaliu elementu
int loga[2*max_n-1];
void buildsparsetable(int N)
{
	for(int i=0; i<N; i++)
		lookup[i][0] = i;
	for(int j=1; j<logn; j++)
	{
		//cout << "skaiciuoju j = " << j << endl;
		for(int i=0; i+(1<<j)<=N; i++)
		{
			if(depth[lookup[i][j-1]] < depth[lookup[i+(1<<(j-1))][j-1]])
				lookup[i][j] = lookup[i][j-1];
			else
				lookup[i][j] = lookup[i+(1<<(j-1))][j-1];
			//cout << depth[lookup[i][j]] << " ";
			//lookup[i][j] = min(lookup[i][j-1], lookup[i+(1<<(j-1))][j-1]);
		}
		//cout << endl;
	}
	loga[1] = 0;
	for(int i=2; i<=N; i++)
		loga[i] = loga[i/2] + 1;
}

int query(int L, int R)
{
	int sk = loga[R-L+1];
	if(depth[lookup[L][sk]] < depth[lookup[R-(1<<sk)+1][sk]])
		return lookup[L][sk];
	else
		return lookup[R-(1<<sk)+1][sk];
}

int LCA(int A, int B)
{
	if((timeIn[A] <= timeIn[B]) && (timeOut[B] <= timeOut[A]))
		return A;
	// cout << A << " is parent of " << B << endl;
	if((timeIn[B] <= timeIn[A]) && (timeOut[A] <= timeOut[B]))
		return B;
	// cout << B << " is parent of " << B << endl;
	if(timeIn[B]<=timeIn[A])
		swap(A, B);

	// cout << "they are not direct ancestors" << endl;

	return traversalArray[query(timeOut[A], timeIn[B])];
}

int cur = 0, curDep = 0;
void eulerTourTraverse(int id, int par)
{
	timeIn[id] = cur;
	traversalArray[cur] = id;
	depth[cur] = curDep;
	cur++;
	for(int next: adj[id])
	{
		if(next == par)
			continue;
		curDep++;
		eulerTourTraverse(next, id);
		curDep--;
		traversalArray[cur] = id;
		depth[cur] = curDep;
		cur++;
	}
	timeOut[id] = cur;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=1; i<n; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--; 
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// for(int i=0; i<n; i++)
	// {
	// 	cout << i << " jo vaikai: ";
	// 	for(int j=0; j<briaunos[i].size(); j++)
	// 		cout << briaunos[i][j] << " ";
	// 	cout << endl;
	// }
	eulerTourTraverse(0, -1);
	buildsparsetable(2*n-1);
	cout << LCA(2, 3) << endl;
	cout << LCA(3, 2) << endl;


	// for(int i=0; i<n; i++)
	// 	cout << i << " : " << timeIn[i] << " " << timeOut[i] << endl;

	// cout << "traverse array:" << endl;
	// for(int i=0; i<2*n-1; i++)
	// 	cout << traversalArray[i] << " ";
	// cout << endl;

	// cout << "depth array:" << endl;
	// for(int i=0; i<2*n-1; i++)
	// 	cout << depth[i] << " ";
	// cout << endl;

	// cout << "sparse table:" << endl;

	// for(int j=0; j<logn; j++)
	// {
	// 	for(int i=0; i<2*n-1; i++)
	// 		cout << lookup[i][j] << " ";
	// 	cout << endl;
	// }


	return 0;
}