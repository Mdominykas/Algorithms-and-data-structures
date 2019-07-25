///budai issirinkti k elementu is n, kai tvarka svarbi
#include<iostream>
using namespace std;

const int max_n=20;
int masyvas[max_n];
bool panaudotas[max_n];
int ats[max_n];
int kiekis = 0;

void spausdink(int k)
{
    for(int i=0; i<k; i++)
        cout << ats[i] << " ";
    cout << endl;
    kiekis++;
}

void perrink(int n, int k, int m)
{
    if(m==k)
        spausdink(k);
    else
    {
        for(int i=0; i<n; i++)
        {
            if(!panaudotas[i])
            {
                panaudotas[i] = 1;
                ats[m] = masyvas[i];
                perrink(n, k, m+1);
                panaudotas[i] = 0;
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> masyvas[i];
    perrink(n, k, 0);
    cout << kiekis;
    return 0;
}
