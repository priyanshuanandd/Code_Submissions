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
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
//*ordered set start
template <class T>
using ordered_set = tree<T, null_type,
                         less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using multi_ordered_set = tree<T, null_type,
                               less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//?order_of_key - find_by_order
//*ordered set end
#define cins(x)       \
    for (auto &i : x) \
    cin >> i
#define cins2(x)      \
    for (auto &i : x) \
    cin >> i.ff >> i.ss
#define endl "\n"
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
typedef priority_queue<int, vector<int>, greater<int>> minheap;
typedef priority_queue<int> maxheap;
// DSU
int dsufind(int v, vector<int> &parent)
{
    if (-1 == parent[v])
        return v;
    return parent[v] = dsufind(parent[v], parent);
}

void dsuunion(int a, int b, vector<int> &parent)
{
    a = dsufind(a, parent);
    b = dsufind(b, parent);
    if (a != b)
        parent[b] = a;
}

// DSU end
//  function for prime factorization
vector<pair<int, int>> pf(int n)
{
    vector<pair<int, int>> prime;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                count++;
                n = n / i;
            }
            prime.pb(mp(i, count));
        }
    }
    if (n > 1)
    {
        prime.pb(mp(n, 1));
    }
    return prime;
}

struct minmaxstack
{
    v64 s, smin = {INT_MAX}, smax = {INT_MIN};

    void push(int a)
    {
        s.push_back(a);
        smax.push_back(::max(smax.back(), a));
        s.push_back(::min(smin.back(), a));
    }

    int pop()
    {
        smax.pop_back();
        smin.pop_back();
        int x = s.back();
        s.pop_back();
        return x;
    }
    int min()
    {
        return smin.back();
    }
    int max()
    {
        return smax.back();
    }
    bool empty()
    {
        return s.empty();
    }
};
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr, n) arr, arr + n
#define sz(x) ((int)(x).size())
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
// 1. If theres mod(%) think of Pigeon hole .

// 2. Prefix Sum

// 3. A^B^A=B ---  rem :  0 1  2  3
//           1 to N XOR : n 1 n+1 0

// 4. DNF-powerset

// 5. Think 2 pointer/Think equation/Think Summation

// 6. Think Circle think Q
void solve()
{
    int n;
    cin >> n;

    v64 v(n);
    cins(v);

    set<int, greater<int>> maxh;
    set<int> minh;
    forn(i, n)
    {
        minh.insert(i + 1);
        maxh.insert(i + 1);
    }

    int l = 0;
    int r = n - 1;
    int mini, maxi;
    while (l + 1 < r)
    {
        mini = *minh.begin();
        maxi = *maxh.begin();
        // bug(mini, maxi);

        if (v[l] == mini or v[l] == maxi)
        {
            if (v[l] == mini)
            {
                minh.erase(minh.lower_bound(mini));
                maxh.erase(maxh.lower_bound(mini));
                mini = *minh.begin();
                maxi = *maxh.begin();
                l++;
            }
            else
            {
                minh.erase(minh.lower_bound(maxi));
                maxh.erase(maxh.lower_bound(maxi));
                mini = *minh.begin();
                maxi = *maxh.begin();
                l++;
            }
        }

        if (v[r] == mini or v[r] == maxi)
        {
            if (v[r] == mini)
            {
                minh.erase(minh.lower_bound(mini));
                maxh.erase(maxh.lower_bound(mini));
                mini = *minh.begin();
                maxi = *maxh.begin();
                r--;
            }
            else
            {
                minh.erase(minh.lower_bound(maxi));
                maxh.erase(maxh.lower_bound(maxi));
                mini = *minh.begin();
                maxi = *maxh.begin();
                r--;
            }
        }
        // bug(v[l], v[r], mini, maxi);
        if ((v[l] != mini and v[l] != maxi) and (v[r] != mini and v[r] != maxi))
        {
            cout << l + 1 << " " << r + 1 << endl;
            return;
        }
    }
    // for (int r = 0; r < n; r++)
    // {

    //     minh.push(v[r]);
    //     maxh.push(v[r]);
    //     //bug(l, r, minh.top(),maxh.top(),v[l],v[r]);
    //     while ((minh.top() == v[l] or maxh.top() == v[l]) and l+1 < r)
    //     {

    //         if (minh.top() == v[l])
    //         {
    //             minh.pop();
    //             l++;
    //         }
    //         else if (maxh.top() == v[l])
    //         {
    //             maxh.pop();
    //             l++;
    //         }
    //     }
    //     if (maxh.top() != v[r] and minh.top() != v[r] and minh.top() != v[l] and maxh.top() != v[l])
    //     {
    //         cout << l + 1 << " " << r + 1 << endl;
    //         return;
    //     }
    // }
    cout << -1 << endl;
}

int32_t main()
{
    fast_cin();
    // clock_t z = clock();
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
