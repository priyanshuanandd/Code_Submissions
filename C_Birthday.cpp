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

    vector<int> v(n);

    for (auto &i : v)
    {
        cin >> i;
    }

    sort(all(v));

    v64 v2(n);
    int i = 0;
    while (!v.empty())
    {
        v2[i] = v[0];
        v.erase(v.begin());
        if (v.empty())
        {
            break;
        }
        v2[n - i - 1] = v[0];
        v.erase(v.begin());
        i++;
    }

    for (auto i : v2)
    {
        cout << i << " ";
    }
}

int32_t main()
{
    fast_cin();
    clock_t z = clock();
    ll t = 1;
    // cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}