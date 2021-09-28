/*Trie
Explanation: data structures to strore strings. They are stored as
tree, first character is root, and children are subsequent characters.
Source: unknown
Complexity: O(len(S)*n)
Tested on: https://codeforces.com/contest/1574/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

const int numberOfChildren = 12;
struct Trie
{
	struct Node
	{
		int count = 0;
		map<int, Node*> child;
	};
	Node *root;

	Trie()
	{
		root = new Node();
	}


	void add(vector<int> sequence)
	{
		root->count++;
		Node* cur = root;
		for(int i = 0; i < sequence.size(); i++)
		{
			int next = sequence[i];
			if(cur->child[next] == NULL)
			{
				cur->child[next] = new Node();
			}
			cur = cur->child[next];
			cur->count++;
		}
	}

	int numberOfOccurences(vector<int> sequence)
	{
		Node* cur = root;
		for(int i = 0; i < sequence.size(); i++)
		{
			int next = sequence[i];
			if(cur->child[next] == NULL)
				return 0;
			cur = cur->child[next];
		}
		return cur->count;
	}
};

int main()
{
	return 0;
}