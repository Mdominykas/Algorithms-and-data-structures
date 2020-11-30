/*input
9
0
1
1
1
2
2
4
6
5
2 4
8 2
5 0
5 7
6 8
*/
///neveikia
///turetu rasti LCA
///pagal suomiu programavimo knyga 168(178) puslapi
#include<bits/stdc++.h>
using namespace std;
const int max_n = 10000000;
vector<int> briaunos[max_n];
int gylis[2*max_n-1];
int pirmas[max_n];
int tree_traversal_array[2*max_n-1];
int dab = 0;
const int logn = 22;
int lookup[max_n][logn];
int loga[max_n];
void buildsparsetable(int N)
{
	for(int i=0; i<N; i++)
		lookup[i][0] = tree_traversal_array[i];
	for(int j=1; j<logn; j++)
	{
		cout << "skaiciuoju j = " << j << endl;
		for(int i=0; i+(1<<j)<=N; i++)
		{
			if(gylis[lookup[i][j-1]]<gylis[lookup[i+(1<<(j-1))][j-1]])
				lookup[i][j] = lookup[i][j-1];
			else
				lookup[i][j] = lookup[i+(1<<(j-1))][j-1];
			cout << gylis[lookup[i][j]] << " ";
			//lookup[i][j] = min(lookup[i][j-1], lookup[i+(1<<(j-1))][j-1]);
		}
		cout << endl;
	}
	loga[1] = 0;
	for(int i=2; i<=N; i++)
		loga[i] = loga[i/2] + 1;
}

int query(int L, int R)
{
	int sk = loga[R-L+1];
	if(gylis[lookup[L][sk]] < gylis[lookup[R-(1<<sk)+1][sk]])
		return lookup[L][sk];
	else
		return lookup[R-(1<<sk)+1][sk];
}

void sudaryk(int id, int gyl)
{

	pirmas[id] = dab;
	tree_traversal_array[dab] = id;
	gylis[dab] = gyl;
	dab++;
	for(int i=0; i<briaunos[id].size(); i++)
	{
		sudaryk(briaunos[id][i], gyl+1);
		tree_traversal_array[dab] = id;
		dab++;
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=1; i<n; i++)
	{
		int a;
		cin >> a;
		briaunos[a].push_back(i); 
	}
	for(int i=0; i<n; i++)
	{
		cout << i << " jo vaikai: ";
		for(int j=0; j<briaunos[i].size(); j++)
			cout << briaunos[i][j] << " ";
		cout << endl;
	}
	sudaryk(0, 0);
	buildsparsetable(2*n-1);
	int Q;
	cin >> Q;
	for(int i=0; i<2*n-1; i++)
		cout << tree_traversal_array[i] << " ";
	cout << endl;
	for(int i=0; i<Q; i++)
	{
		int A, B;
		cin >> A >> B;
		cout << "klausiu: " << A << " " << B << endl;
		A = pirmas[A];
		B = pirmas[B];
		if(A>B)
			swap(A, B);
		cout << "masyve tai: " << A << " " << B << endl;

		cout << query(A, B) << "\n";
	}
	return 0;
}