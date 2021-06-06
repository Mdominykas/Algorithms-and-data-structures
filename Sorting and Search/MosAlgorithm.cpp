/*Mo's algorithm
Explanation: Mo's algorithm is used to answer offline range queries in static array
It sorts all queries in blocks of sqrt(N) size by which block their begining is and
then by where end is.
Source: Competitive Programmer's handbook p256
Complexity: O(sqrt(N)*(Q+N))
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{

	int N, Q;
	cin >> N >> Q;
	vector<pair<int, int> > queries(Q);

	for(int i=0; i<Q; i++)
		cin >> queries[i].first >> queries[i].second;

	int sqrtN = sqrt(N);

	sort(queries.begin(), queries.end(), [&](pair<int, int> &a, pair<int, int> &b)
	{
		if(a.first/sqrtN != b.first/sqrtN)
			return a.first < b.first;
		else
			return a.second < b.second;
	});

	for(int i=0; i<Q; i++)
		cout << queries[i].first << " " << queries[i].second << "\n";

	return 0;
}