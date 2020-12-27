/*Trie
Explanation: data structures to strore strings. They are stored as
tree, first character is root, and children are subsequent characters.
Source: unknown
Complexity: O(len(S)*n)
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

struct Trie
{
	int skaicius = 0;
	Trie* virsune[26];
	Trie()
	{
		for(int i=0; i<26; i++)
			virsune[i] = NULL;
	}
};

Trie pradzia;

void ideti(string zodis)
{
	Trie* dabar = &pradzia;
	for(int i=0; i<zodis.size(); i++)
	{
		int kitas = zodis[i] - 'a';
		if(dabar->virsune[kitas]==NULL)
		{
			dabar->virsune[kitas] = new Trie();
		}
		dabar = dabar->virsune[kitas];
		dabar->skaicius++;
	}
}

int prefix(string uzklausa)
{
	Trie* dabar = &pradzia;
	for(int i=0; i<uzklausa.size(); i++)
	{
		int kitas = uzklausa[i] - 'a';
		if(dabar->virsune[kitas]==NULL)
			return 0;
		dabar = dabar->virsune[kitas];
	}
	return dabar->skaicius;
}

int main()
{
	int N, Q;
	cin >> N;
	string zodziai[N];
	for(int i=0; i<N; i++)
	{
		cin >> zodziai[i];
		ideti(zodziai[i]);
	}
	cin >> Q;
	for(int i=0; i<Q; i++)
	{
		string uzklausa;
		cin >> uzklausa;
		cout << prefix(uzklausa) << endl; 
	}
	return 0;
}