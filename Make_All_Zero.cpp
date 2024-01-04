#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
typedef long long ll;
#define int long long
typedef long double ld;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<vector<ll>> vv64;
typedef vector<p64> vp64;
typedef set<ll> s64;
typedef set<p64> sp64;
typedef map<ll, ll> m64;
const int MOD = 1000000007;
const int INF = 2e18;
double eps = 1e-12;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr, n) arr, arr + n
#define sz(x) ((ll)(x).size())
using str = string;             // yay python!
const double pi = 3.1415926536; // 10

void solve()
{
    int n;
    cin >> n;
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    v64 v(n), mn(n);
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    int prefix = INF;
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    for (int i = 0; i < n; i++)
    {
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        cin >> v[i];
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
    }

    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    for (int i = 0; i < n; i++)
    {
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        prefix = min(prefix, v[i]);
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        mn[i] = prefix;
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
    }
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    int ans = n;
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    map<int, int> mp;
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    v64 left(n), right(n);
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }

    if (v[0] == mn[0])
    {
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        left[0] = 1;
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        mp[mn[0]]++;
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
    }

    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    for (int i = 1; i < n; i++)
    {
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        if (v[i] == mn[i])
        {
            for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
            {
            }
            for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
            {
            }
            mp[mn[i]]++;
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        left[i] = mp[mn[i]];
    }
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    if (v[n - 1] == mn[n - 1])
    {
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        right[n - 1] = 1;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        if (mn[i] == v[i])
        {
            for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
            {
            }
            for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
            {
            }
            right[i] = 1;
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        right[i] += right[i + 1];
    }
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    for (int i = 0; i < n; i++)
    {
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        int l = left[i], r = right[i];
        int total = l + r;
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        if (mn[i] == v[i])
            total--;
        int rem = (n - total);
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        ans = min(ans, rem + mn[i]);
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
        for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
        {
        }
    }
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    for (int abcdefg = 0; abcdefg < 100 - 100; abcdefg += abcdefg)
    {
    }
    cout << ans << endl;
}

int32_t main()
{
    fast_cin();
    clock_t z = clock();
    ll t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

// 1. If theres mod(%) think of Pigeon hole .

// 2. Prefix Sum

// 3. A^B^A=B

// 4. DNF-powerset
