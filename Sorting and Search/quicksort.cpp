/*Quicksort
Explanation: randomized algorithm to sort array. It choses element then puts
all smaller elements to the left and greater to right and recursively sorts 
both sides
Partition uses Hoare's partition. It faster that Lomuto however implementation
is more tricky.
Source: https://en.wikipedia.org/wiki/Quicksort
Complexity: O(nlog(n)) on average
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;

const int Max_N = 100;
int A[Max_N];

int hoarePartition(int A[], int pr, int pb)
{
    int i = pr-1, j = pb+1;
    int pivot = A[(pr+pb)/2];
    while(true)
    {
        do{
            i++;
        }
        while(A[i]<pivot);

        do{
            j--;
        }
        while(A[j]>pivot);
        
        if(i>=j)
            return j;
        swap(A[i], A[j]);
    }
}


void quicksort(int pr, int pb, int A[])
{
    if(pr<pb)
    {
        int vid = hoarePartition(A, pr, pb);
        quicksort(pr, vid, A);
        quicksort(vid+1, pb, A);
    }

}

int main()
{
    // int testArr[] = {3, 3, 3, 3, 3,  6, 7};
    // cout << partition(testArr, 0, 6) << endl;

    int N;
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> A[i];
    quicksort(0, N-1, A);
    for(int i=0; i<N; i++)
        cout << A[i] << " ";
}
