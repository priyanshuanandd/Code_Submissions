// Problem: D. Mathematical Problem
// Contest: Codeforces - Codeforces Round 954 (Div. 3)
// URL: https://codeforces.com/contest/1986/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <complex>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
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
#define ln "\n"
#define mp make_pair
#define ie insert
#define pb push_back
#define fi first
#define se second
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
#define dbg(a) cout << a << ln;
#define dbg2(a) cout << a << ' ';
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define minheap priority_queue<int, vector<int>, greater<int>>;
#define maxheap priority_queue<int>;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr, n) arr, arr + n
#define sz(x) ((ll)(x).size())
using str = string;             // yay python!
const double pi = 3.1415926536; // 10

int runs(v64 &kk, int a)
{
    a = kk.size();
    int b = kk[0];
    if (a == 1)
    {
        return b;
    }

    forsn(i, 1, a)
    {
        if ((b * kk[i]) < (b + kk[i]))
        {
            b *= kk[i];
        }
        else
        {
            b += kk[i];
        }
    }
    return b;
}
void solving()
{
    int a;
    cin >> a;
    string s;
    cin >> s;
    int k = 1e9;
    forsn(i1, 1, a)
    {
        v64 kk;
        int b = int32_t(s[i1 - 1]) - '0';
        b *= 10;
        b += (int32_t(s[i1]) - '0');

        forn(i2, a)
        {
            if (i2 == (i1 - 1))
            {
                kk.push_back(b);
                i2++;
            }
            else
            {
                kk.push_back(int32_t(s[i2]) - '0');
            }
        }
        k = min(k, runs(kk, a));
    }
    dbg(k);
}

int32_t main()
{
    fast_cin();
    clock_t z = clock();
    ll t = 1;
    cin >> t;
    // freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    for (int it = 1; it <= t; it++)
    {
        solving();
    }

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

// 1. If theres mod(%) think of Pigeon hole .

// 2. Prefix Sum

// 3. A^B^A=B

// 4. DNF-powerset
