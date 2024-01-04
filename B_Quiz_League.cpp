#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (auto &i : v)
    {
        cin >> i;
    }

    // cout << k - 1 << endl;
    for (int i = 0; i < n; i++)
    {

        int m = k - 1 + i;
        if (m >= n)
        {
            m = m % n;
        }
        // bug(m);
        if (v[m] == 1)
        {
            cout << m + 1;
            return 0;
        }
    }
}