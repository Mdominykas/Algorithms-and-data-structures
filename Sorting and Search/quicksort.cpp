/*Quicksort
Explanation: randomized algorithm to sort array. It choses element then puts
all smaller elements to the left and greater to right and recursively sorts 
both sides
Source: https://en.wikipedia.org/wiki/Quicksort
Complexity: O(nlog(n)) on average
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

const int Max_N = 100;
int A[Max_N];

int partition(int A[], int pr, int pb)
{
    int i = pr, j = pb;
    int skirt = -1;
    int k = A[pr];
    while(skirt == -1)
    {
        while(A[i]<k)
            i++;
        while(A[j]>k)
            j--;
        if(i<j)
        {
            swap(A[i], A[j]);
            i++;
            j--;
        }
        else
            skirt = j;
    }
    return skirt;
}


void quicksort(int pr, int pb, int A[])
{
    if(pr<pb)
    {
        int vid = partition(A, pr, pb);
        quicksort(pr, vid, A);
        quicksort(vid+1, pb, A);
    }

}

int main()
{
    int N=15;
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> A[i];
    quicksort(0, N-1, A);
    for(int i=0; i<N; i++)
        cout << A[i] << " ";
}
