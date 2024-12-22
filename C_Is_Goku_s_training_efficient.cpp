#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
int query(int a)
{
    if ((a + 1 > 1e8))
    {
        a = 1e8;
    }
    cout << "? " << a << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main()
{
    int l = 1;
    int r = 1e8;
    while (r - l > 2)
    {
        int mid = (l + r) / 2;
        int q1 = query(mid);
        int q2 = query(mid + 1);
        if (q1 > q2)
        {
            r = mid;
        }
        else if (q2 > q1)
        {
            l = mid;
        }
        else
        {
            l = mid;
            break;
        }
    }

    int qval = query(l);
    int ans = l;
    r = min(r, l + 2);
    for (int i = l + 1; i <= r; i++)
    {
        int curr = query(i);
        if (curr > qval)
        {
            ans = i;
            qval = curr;
        }
    }
    cout << "! " << ans << endl;
    fflush(stdout);
}