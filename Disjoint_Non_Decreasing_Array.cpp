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
void printvector(v64 &v)
{
    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << ln;
}
pair<int, int> findIntersection(vector<pair<int, int>> &ranges)
{
    if (ranges.empty())
        return {-1, -1};

    int intersectionStart = ranges[0].first;
    int intersectionEnd = ranges[0].second;

    for (size_t i = 1; i < ranges.size(); ++i)
    {
        intersectionStart = max(intersectionStart, ranges[i].first);
        intersectionEnd = min(intersectionEnd, ranges[i].second);
        if (intersectionStart > intersectionEnd)
            return {-1, -1};
    }
    return {intersectionStart, intersectionEnd};
}
void solve()
{
    int n;
    cin >> n;
    vp64 vp;
    v64 v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    int prev = 0;
    m64 m;
    forn(i, n - 1)
    {

        prev = v[i + 1] - v[i];

        if (prev < 0)
        {
            m[i + 1] = 1;
            if (i + 2 == n)
            {
                vp.push_back({abs(prev), 1e9});
            }
            else
            {
                int right = v[i + 2] - v[i + 1];

                if (right + prev >= 0)
                {
                    vp.push_back({abs(prev), right});
                }
                else
                {
                    dbg("No");
                    return;
                }
            }
        }
    }

    auto ans = findIntersection(vp);
    if ((ans.first != -1 and ans.second != -1) or vp.empty())
    {
        dbg("Yes");
    }
    else
    {
        dbg("No");
    }
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
        solve();
    }

    // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

// 1. If theres mod(%) think of Pigeon hole .

// 2. Prefix Sum

// 3. A^B^A=B

// 4. DNF-powerset
