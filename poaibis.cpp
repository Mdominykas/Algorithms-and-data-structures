///perrenka visus imanomus poaibius
#include<iostream>
using namespace std;

const int max_n = 20;
int masyvas[max_n];
bool panaudotas[max_n];
int sk = 0;

void spausdink(int n)
{
    for(int i=0; i<n; i++)
    {
        if(panaudotas[i])
            cout << masyvas[i] << " ";

    }
    cout << endl;
}

void perrink(int m, int n)
{
    if(n==m)
        spausdink(n);
    else
    {
        for(int i=0; i<2; i++)
        {
            panaudotas[m] = i;
            perrink(m+1, n);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i<n; i++)
        cin >> masyvas[i];
    perrink(0, n);
    return 0;
}
