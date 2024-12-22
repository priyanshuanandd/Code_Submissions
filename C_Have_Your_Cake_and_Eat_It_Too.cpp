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
    cin >> i.first >> i.second
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
int nxt() // takes input
{
    int x;
    cin >> x;
    return x;
}
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
// modular exponentiation
int binaryExponentiation(int x, int n)
{
    if (n == 0)
        return 1;
    // n is even
    else if (n % 2 == 0)
        return binaryExponentiation(x * x, n / 2);
    // n is odd
    else
        return x * binaryExponentiation(x * x, (n - 1) / 2);
}
int modularExponentiation(int x, int n, int M)
{
    if (n == 0)
        return 1;
    // n is even
    else if (n % 2 == 0)
        return modularExponentiation((x * x) % M, n / 2, M);
    // n is odd
    else
        return (x * modularExponentiation((x * x) % M, (n - 1) / 2, M)) % M;
}

// const int N = 1e6 + 100;
// long long fact[N];
// ! initialise the factorial
// void initfact(){
// fact[0] = 1;
// for (int i = 1; i < N; i++)
//{
// fact[i] = (fact[i - 1] * i);
// fact[i] %= MOD;
// }}
//! Less and Equal to
// int lowerbound(int num,vector<int> v){
//     int l = 0 ; int r = v.size();
//     while(l+1 < r){
//         int mid = (l+r)/2;

//         if(v[mid] <= num){
//             l = mid;
//         }
//         else{
//             r = mid;
//         }
//     }
//     return l;
// }
//! formula for c
// ll C(ll n, ll i)
//{
// ll res = fact[n];
// ll div = fact[n - i] * fact[i];
// div %= MOD;
// div = modpow(div, MOD - 2, MOD);
// return (res * div) % MOD;
// }

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
int la, ra, lb, rb, lc, rc;
bool f(int n, vector<int> &a, vector<int> &b, vector<int> &c, int total)
{
    int target = total / 3;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    int i = 0, j = 0, k = 0;

    // Find first subarray
    while (i < n && sum1 < target)
    {
        sum1 += a[i++];
    }
    if (sum1 < target)
        return false;
    la = 0;
    ra = i - 1;

    // Find second subarray
    while (j < n && sum2 < target)
    {
        sum2 += b[j++];
    }
    if (sum2 < target)
        return false;
    lb = 0;
    rb = j - 1;

    // Find third subarray
    while (k < n && sum3 < target)
    {
        sum3 += c[k++];
    }
    if (sum3 < target)
        return false;
    lc = 0;
    rc = k - 1;

    // Check if we used all elements
    return (i + j + k == n);
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);

    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;
    for (int &x : c)
        cin >> x;

    int total = accumulate(a.begin(), a.end(), 0) +
                accumulate(b.begin(), b.end(), 0) +
                accumulate(c.begin(), c.end(), 0);

    if (f(n, a, b, c, total))
    {
        cout << la + 1 << " " << ra + 1 << " " << lb + 1 << " " << rb + 1 << " " << lc + 1 << " " << rc + 1 << endl;
    }
    else if (f(n, a, c, b, total))
    {
        cout << la + 1 << " " << ra + 1 << " " << lc + 1 << " " << rc + 1 << " " << lb + 1 << " " << rb + 1 << endl;
    }
    else if (f(n, b, a, c, total))
    {
        cout << lb + 1 << " " << rb + 1 << " " << la + 1 << " " << ra + 1 << " " << lc + 1 << " " << rc + 1 << endl;
    }
    else if (f(n, b, c, a, total))
    {
        cout << lb + 1 << " " << rb + 1 << " " << lc + 1 << " " << rc + 1 << " " << la + 1 << " " << ra + 1 << endl;
    }
    else if (f(n, c, a, b, total))
    {
        cout << lc + 1 << " " << rc + 1 << " " << la + 1 << " " << ra + 1 << " " << lb + 1 << " " << rb + 1 << endl;
    }
    else if (f(n, c, b, a, total))
    {
        cout << lc + 1 << " " << rc + 1 << " " << lb + 1 << " " << rb + 1 << " " << la + 1 << " " << ra + 1 << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}