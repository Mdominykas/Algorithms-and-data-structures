#include<bits/stdc++.h>
using namespace std;

const int Max_N = 100;
int A[Max_N];

int perskirk(int A[], int pr, int pb)
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


void rikiuok(int pr, int pb, int A[])
{
    if(pr<pb)
    {
        int vid = perskirk(A, pr, pb);
        rikiuok(pr, vid, A);
        rikiuok(vid+1, pb, A);
    }

}

int main()
{
    int N=15;
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> A[i];
    rikiuok(0, N-1, A);
    for(int i=0; i<N; i++)
        cout << A[i] << " ";
}
