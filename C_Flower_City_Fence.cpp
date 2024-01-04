#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define bye cout << endl
#define rr return
;
const ll MOD = 1000000007;

void solve()
{
    ll n, k;
    cin >> n >> k;

    // ll temp = k;

    // while (temp / n != 0)
    // {
    //     ll rem = temp % n;
    //     temp /= n;

    //     k += temp;
    //     temp += rem;
    // }
    // cout << k << endl;

    ll lo = 0, hi = 2 * k;

    while (hi >= lo)
    {
        ll mid = (lo + hi) / 2;
        if (mid - (mid / n) >= k)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
}

signed main()
{
    ll t;
    ll g = 1;
    cin >> t;
    while (t--)
    {
        solve();
        g++;
    }
    return 0;
}