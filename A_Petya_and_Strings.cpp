#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string c1, c2;
    cin >> c1 >> c2;

    for (int i = 0; i < c1.size(); i++)
    {
        if (c1[i] >= 65 and c1[i] <= 90)
        {
            c1[i] = c1[i] + 32;
        }
    }
    for (int i = 0; i < c2.size(); i++)
    {
        if (c2[i] >= 65 and c2[i] <= 90)
        {
            c2[i] = c2[i] + 32;
        }
    }

    for (int i = 0; i < c1.size(); i++)
    {
        if (c1[i] > c2[i])
        {
            cout << 1 << endl;
            return;
        }
        else if (c1[i] < c2[i])
        {
            cout << -1 << endl;
            return;
        }
        

    }
    cout << 0 << endl;
}
int main()
{
    int t = 1;

    // cin >> t;

    while (t--)
    {
        solve();
    }
}