#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#define cins(x)       \
    for (auto &i : x) \
    cin >> i
#define cins2(x)      \
    for (auto &i : x) \
    cin >> i.first >> i.second
#define endl "\n"
#define ln "\n"
#define mp make_pair
#define ie insert
#define pb push_back
#define fi first
#define se second
#define F first
#define S second
typedef long long ll;
#define int long long
typedef long double ld;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<string> vs64;
typedef vector<vector<ll>> vv64;
typedef vector<p64> vp64;
typedef set<ll> s64;
typedef set<p64> sp64;
typedef map<ll, ll> m64;
typedef map<ll, v64> mv64;
typedef unordered_map<ll, v64> uv64;
typedef unordered_map<ll, ll> u64;
typedef unordered_map<p64, ll> up64;
typedef unordered_map<ll, vp64> uvp64;
const int MOD = 1000000007;
const int INF = 2e18;
double eps = 1e-12;
#define dbg(a) cout << a << ln;
#define dbg2(a) cout << a << ' ';
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
typedef priority_queue<int, vector<int>, greater<int>> minheap;
typedef priority_queue<int> maxheap;

void solve()
{
    int n;
    cin >> n;

    ld mini = 1e9;
    ld maxi = 0;
    vector<pair<ld, ld>> v;
    int fl = 0;
    forn(i, n)
    {
        ld a, b;
        cin >> a >> b;
        ld curr1, curr2;
        v.push_back({a, b});
        if (a == 0)
        {
            curr1 = 1e9;
        }
        else if (a > 0)
        {
            curr1 = (i + 1) / a;
        }

        curr2 = (i + 1) / b;
        // cout << curr1 << " " << curr2 << endl;

        mini = min(curr1, mini);
        maxi = max(maxi, curr2);
        if (mini < maxi)
        {
            fl = 1;
        }
    }
    if (fl)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << maxi << endl;
    }
}
//! testcase ???????
//? 1.If theres mod(%) think of Pigeon hole .
//? 2.Prefix Sum
//? 3.A^B^A=B ---  rem :  0 1  2  3         xor is broken mod 2
//?           1 to N XOR : n 1 n+1 0
//? 4.DNF-powerset
//? 5.Think 2 poxinter/Think equation/Think Summation
//? 6.Think Circle think Q
//? 7.MAX-MIN SHOWS YOU TO GO FOR EITHER DP OR BINARY SEARCH
//? 8.FOR INTERACTIVE PROBLEMS REMOVE CIN.PTR ALWAYS
//? 9.IF CONSTRAINS ARE LOW (EXCEPT PROBLEM A) GO FOR BRUTE FORCE, DP, BINARY SEARCH ALWAYS
//? 10.FOR BINARY SEARCH, ALWAYS SEE TWICE THE SEARCH SPACE BEFORE MAKING SUBMISSION
//? 11.DON'T IMPLEMENT TOO MUCH FOR PROBLEM A AND B (THEY MIGHT HAVE EASY SOLUTION)

int32_t main()
{
    // clock_t z = clock();

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        cout << "Case #" << it << ": ";
        solve();
    }

    // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
