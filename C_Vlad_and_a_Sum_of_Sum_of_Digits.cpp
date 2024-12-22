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
int sumy(int n)
{
    int ans = 0;
    int k = n;
    while (k != 0)
    {
        int x = k % 10;
        ans += x;
        k /= 10;
    }
    return ans;
}

int maxi = 2e5 + 1;
vector<int> pref(maxi, 0);
void solve()
{
    int n;
    cin >> n;

    // vector<int> v;
    // int k = n;
    // while (k != 0)
    // {
    //     int x = k % 10;
    //     v.push_back(x);
    //     k /= 10;
    // }
    // int sum = 0;
    // int nine1 = 1;
    // int nine2 = 0;
    // int nine3 = 1;
    // forn(i, v.size())
    // {
    //     int curr1 = (((v[i] - 1) * v[i]) * nine1) / 2;

    //     int curr2 = v[i] * nine2;

    //     int curr3 = v[i] * nine3;

    //     sum += curr1 + curr2 + curr3;

    //     nine1 += pow(10, i) * 9;

    //     if (i >= 1)
    //     {
    //         nine2 = 10 * nine2 + 9 * 45;
    //     }
    //     else
    //     {
    //         nine2 = 10 * nine2 + 45;
    //     }

    //     nine3 = (pow(10, i) * v[i] + 1);
    //     // bug(sum, curr1, curr2, curr3, nine1, nine2, nine3);
    // }

    // cout << sum << endl;

    cout << pref[n] << endl;
}

int32_t main()
{
    fast_cin();
    clock_t z = clock();
    ll t = 1;
    cin >> t;

    forsn(i, 1, maxi)
    {
        pref[i] = sumy(i) + pref[i - 1];
    }

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
