/*Binary search
Explanation: search for first element occurence in sorted array. compares with middle
element after that changes ranges of search
Source: https://en.wikipedia.org/wiki/Binary_search_algorithm
Complexity: O(log(n))
Tested on: lightly tested
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    int x;
    cin >> x;

    int low = 0, high = N-1;
    int best = high;

    auto can = [&](int id)
    {
        return arr[id] <= x;
    };
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (can(mid))
        {
            best = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return 0;
}