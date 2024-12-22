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
#define F first
#define S second
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
        cout << i << " ";
    cout << ln;
}
int n;
v64 v;
v64 cost;
vv64 dp;
int f(int indx, int prev, int state)
{
    if (indx == n)
    {
        return 0;
    }
    auto &x = dp[indx][state];
    if (x != -1)
        return x;
    int ans = 1e18;
    forn(i, 3)
    {
        if (v[indx] + i != prev)
        {
            ans = min(ans, (i * cost[indx]) + f(indx + 1, v[indx] + i, i));
        }
    }
    return x = ans;
}
void solve()
{
    cin >> n;
    v.assign(n, 0);
    cost.assign(n, 0);
    forn(i, n)
    {
        cin >> v[i] >> cost[i];
    }

    //    printvector(v);
    //  printvector(cost);
    int ans = 1e18;
    dp.assign(n + 1, v64(3, -1));
    forn(i, 3)
    {
        ans = min(ans, f(0, -1, i));
    }
    cout << ans << '\n';
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
