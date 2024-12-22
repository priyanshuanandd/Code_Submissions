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
    int q;
    cin >> q;

    unordered_map<int, int> mcf, mfc;

    set<int> freq;
    while (q--)
    {
        int x;
        cin >> x;

        if (x == 1)
        {
            int k;
            cin >> k;
            // decrease colour associated with freq
            if (mfc[mcf[k]] != 0)
            {
                mfc[mcf[k]]--;
                if (mfc[mcf[k]] == 0)
                {
                    freq.erase(mcf[k]);
                }
            }
            mcf[k]++;
            mfc[mcf[k]]++;
            freq.insert(mcf[k]);
        }
        if (x == 2)
        {
            int k;
            cin >> k;
            // decrease colour associated with fre
            if (mcf[k] == 0)
            {
                continue;
            }
            if (mfc[mcf[k]] != 0)
            {
                mfc[mcf[k]]--;
                if (mfc[mcf[k]] == 0)
                {
                    freq.erase(mcf[k]);
                }
            }
            mcf[k]--;
            if (mcf[k] != 0)
            {
                mfc[mcf[k]]++;
                freq.insert(mcf[k]);
            }
            else
            {
                mcf.erase(k);
            }
        }
        if (x == 3)
        {
            // bug(x, mfc[2]);
            // for (auto &i : freq)
            // {
            //     cout << i << " ";
            // }
            // cout << endl;
            if (freq.empty())
            {
                cout << 0 << endl;
                continue;
            }
            cout << mfc[*(freq.rbegin())] << endl;
        }
        if (x == 4)
        {
            // bug(x);
            // for (auto &i : freq)
            // {
            //     cout << i << " ";
            // }
            // cout << endl;
            if (freq.empty())
            {
                cout << 0 << endl;
                continue;
            }
            cout << mfc[*(freq.begin())] << endl;
        }
    }

    // for (auto &i : freq)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (auto &i : mfc)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }

    // for (auto &i : mcf)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
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

// 1. If theres mod(%) think of Pigeon hole .

// 2. Prefix Sum

// 3. A^B^A=B

// 4. DNF-powerset
