
#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int low = 1;
    int high = 1e6;

    while (high > low)
    {
        int mid = (high + low) / 2;

        cout << mid << endl;
        string s;
        cin >> s;
        if (s == "<")
        {
            high = mid - 1;
        }
        else
        {
            low = mid;
        }
    }
    cout << "! " << low << endl;
    fflush(stdout);
}
