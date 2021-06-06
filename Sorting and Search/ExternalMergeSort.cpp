/*External merge sort
Explanation: sorts array from one file when it is too large to load in ram.
It does so by reading all data and storing in several files and them
performing merge on all of them
Source: https://en.wikipedia.org/wiki/External_sorting#External_merge_sort
Complexity: O(N/B * log_(N/B) (N/B))
Tested on: lightly tested
*/

#include<bits/stdc++.h>
using namespace std;


void externalMergeSort(ifstream &in, ofstream &out, int limit)
{
	vector<string> intermediate;
	string inter = "intermediate";
	int cur = 0;
	bool endOfData = false;
	while(!endOfData)
	{
		string fileName = inter + to_string(cur);
		ofstream part(fileName);
		intermediate.push_back(fileName);
		vector<int> values;
		for(int i=0; i<limit; i++)
		{
			int value;
			if(in>>value)
			{
				values.push_back(value);
			}
			else
			{
				endOfData = true;
				break;
			}
		}
		sort(values.begin(), values.end());
		for(int i=0; i<values.size(); i++)
			part << values[i] << " ";
		cur++;
	}

	vector<ifstream> partials;
	for(int i=0; i<intermediate.size(); i++)
		partials.push_back(ifstream(intermediate[i]));

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	for(int i=0; i<partials.size(); i++)
	{
		int val;
		if(partials[i] >> val)
			q.push({val, i});
	}

	while(!q.empty())
	{
		pair<int, int> g = q.top();
		q.pop();
		out << g.first << " ";
		int val;
		if(partials[g.second] >> val)
			q.push({val, g.second});
	}

	for(int i=0; i<intermediate.size(); i++)
	{
		char fileName[intermediate[i].size()+1];
		strcpy(fileName, intermediate[i].c_str());
		remove(fileName);
	}

}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	externalMergeSort(in, out, 3);
	return 0;
}