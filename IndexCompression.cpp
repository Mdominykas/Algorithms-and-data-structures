/*input
7
1 9 5 3 5 2 2
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> compress(vector<int> mas)
{
	vector<int> b = mas;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for(int i=0; i<mas.size(); i++)
		mas[i] = int(lower_bound(b.begin(), b.end(), mas[i])-b.begin());
	return mas;
}

int main()
{
	int n;
	cin >> n;
	vector<int> mas(n);
	for(int i=0; i<n; i++)
		cin >> mas[i];
	mas = compress(mas);
	for(int i=0; i<n; i++)
		cout << mas[i] << " ";
	return 0;
}