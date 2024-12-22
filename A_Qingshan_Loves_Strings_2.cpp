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
pair<int, string> deleter(string s, int count)
{
    pair<int, string> p1;
    if (s.empty())
    {
        p1 = {count, s};
        return p1;
    }

    if (s[0] != s[s.size() - 1])
    {
        count++;
        s.pop_back();
        s.erase(s.begin());
        return deleter(s, count);
    }
    else
    {
        p1 = {count, s};
        return p1;
    }
}
void solve()
{
    // 010101
    //
    // 010011
    int n;
    cin >> n;
    string s;
    cin >> s;
    n = s.size();
    if (n % 2 == 1)
    {
        cout << -1 << endl;
        return;
    }
    int ktt = 300;
    int i = 0;
    auto k = deleter(s, 0);
    // bug(k.first, k.second, i);
    if (k.second.empty())
    {
        cout << 0 << endl;
        cout << endl;
        return;
    }

    i += k.first;
    int count0 = 0;
    int count1 = 0;
    int jj = -1;
    vector<int> ans;
    bool flag = false;
    while (ktt--)
    {
        // bug(i);
        auto k = deleter(s, 0);
        flag = false;
        if (jj != -1)
        {
            i += k.first;
        }
        if (flag)
        {
            i--;
        }

        jj = 0;
        s = k.second;
        if (s.empty())
        {
            break;
        }
        int count0 = 0;
        int count1 = 0;
        for (auto &i : s)
        {
            if (i == '0')
            {
                count0++;
            }
            else
            {
                count1++;
            }
        }

        if (count0 == 0 or count1 == 0)
        {
            cout << -1 << endl;
            return;
        }
        int j = 0;
        if (s[j] == s[s.size() - 1 - j])
        {

            if (s[j] == '0')
            {
                ans.push_back(i + s.size());
                s += "01";
            }
            else
            {
                s = "01" + s;
                flag = true;
                ans.push_back(i);
            }
        }
    }
    cout << ans.size() << endl;

    for (auto &i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
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