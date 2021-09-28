/*Knuth-Morris-Pratt algorithm
Explanation: algorithm finds number of occurencies of one string in another.
It does so by precomputing LPS array that shows for each index the length of 
longest suffix that is also a prefix. Then it goes by each character and if it
can not add more to current it changes to LPS value.
Source: https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
Complexity: O(n+m)
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

void computeLPSArray(char* pat, int M, int* lps)
{
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while(i < M)
	{
		if(pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else///pat[len]!=pat[i]
		{
			if(len == 0)
			{
				lps[i] = 0;
				i++;
			}
			else
			{
				len = lps[len - 1];
			}
		}
	}
}

void KMPSearch(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	int lps[M];/// longest proper prefix that is also a suffix

	computeLPSArray(pat, M, lps);

	int i = 0;///kurioje txt vietoje yra
	int j = 0;/// kiek sutapo paeiliui raidziu
	while(i < N)
	{
		if(pat[i] == txt[j])
		{
			i++;
			j++;
		}

		if(j == M)
		{
			printf("Found pattern at index %d", i-M);
			j = lps[j - 1];
		}
		else if ((i < N) && (pat[j] != txt[i]))
		{
			if(j != 0)
				j = lps[j - 1];
			else
				i++;
		}

	}
}

int main()
{
	char txt[] = "ABABDABACDABABCABAB"; 
    char pat[] = "ABABCABAB"; 
    KMPSearch(pat, txt); 
}