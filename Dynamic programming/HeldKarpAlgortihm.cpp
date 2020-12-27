/*Held-Karp algorithm
Explanation: algorithm to find answer to travelling salesman's problem
It dynamically iterates all options.
Source: https://en.wikipedia.org/wiki/Held%E2%80%93Karp_algorithm
Complexity: O(2^(n)n^2)
Tested on: untested
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int weight[n];
	for(int i=0; i<n; i++)
		cin >> weight[i];
	pair<int, int> best[1<<n];
	best[0] = {0, 0};
	for(int s=1; s<(1<<n); s++)
	{
		best[s] = {n, 0};
		for(int p=0; p<n; p++)
		{
			if(s&(1<<p))
			{
				auto option = best[s^(1<<p)];
				
				if(option.second + weight[p]>m)
				{
					option.first ++;
					option.second = weight[p];
				}
				else
				{
					option.second += weight[p];
				}
				best[s] = min(best[s], option);
			}
		}
	}
	/*for(int i=0; i<(1<<n); i++)
		cout <<i<< " "<< best[i].first << " " << best[i].second<< endl;*/

	cout << best[(1<<n)-1].first << " " << best[(1<<n)-1].second<< endl;
	return 0;
}