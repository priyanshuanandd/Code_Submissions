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
void solve(int it)
{
    string s, t, p;
    cin >> s >> t >> p;
    // if (it == 32)
    // {
    //     bug(s, t, p);
    //     return;
    // }
    map<char, int> ms, mt, mp;
    for (auto &i : t)
    {
        mt[i]++;
    }

    for (auto &i : s)
    {
        ms[i]++;
    }

    for (auto &i : p)
    {
        mp[i]++;
    }

    for (auto &i : mt)
    {
        char a = i.first;
        char b = i.second;
        if (i.second < ms[a])
        {
            cout << "NO" << endl;
            return;
        }

        if (i.second >= ms[a])
        {
            int diff = i.second - ms[a];

            if (diff > mp[a])
            {
                cout << "NO" << endl;
                return;
            }
            else
            {
                ms[a] = diff;
            }
        }
    }
    if (ms.size() != mt.size())
    {
        cout << "NO" << endl;
        return;
    }
    int i = 0;
    int cnt = 0;

    while (i < t.size() or (i - cnt) < s.size())
    {
        char a = t[i];
        // bug(a, s[i - cnt]);
        if (s[i - cnt] != t[i])
        {
            i++;
            cnt++;
            if (ms[a] < 1)
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            i++;
        }
        if (i - cnt >= s.size())
        {
            break;
        }
        if (i == t.size() - 1 and s[i - cnt] != t[i])
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int32_t main()
{
    fast_cin();
    clock_t z = clock();
    ll t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve(it);
    }

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

// 1. If theres mod(%) think of Pigeon hole .
