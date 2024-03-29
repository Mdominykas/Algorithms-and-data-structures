/*{Algorithm name}
Explanation: finds area of polygon given its vertices in
clockwise or counter  order.
Source: https://en.wikipedia.org/wiki/Shoelace_formula
Complexity: O(n)
Tested on: lightly tested
*/
#include<bits/stdc++.h>
using namespace std;
///randa plota daugiakampiui, kurio virsunes paeiliui pagal 
///arba pries laikrodzio rodykle
double Shoelace(double X[], double Y[], int N)
{
	double ats = 0;
	for(int i=0; i<N; i++)
	{
		ats += X[i]*Y[(i+1)%N] - X[(i+1)%N]*Y[i];
	}
	ats /= (double) 2;
	return abs(ats);
}

int main()
{
	int N;
	cin >> N;
	double X[N], Y[N];
	for(int i=0; i<N; i++)
		cin >> X[i] >> Y[i];
	double S = Shoelace(X, Y, N);
	cout << S;
	return 0;
}