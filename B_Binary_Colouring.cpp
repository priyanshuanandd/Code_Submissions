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

// 3. A^B^A=B

// 4. DNF-powerset

// 5. Think 2 pointer/Think equation/Think Summation

// 6. Think Circle think Q

int soln(int n, int sign, vector<int> &v)
{
    auto a = log2(n);
    int l = floor(a);
    l = max(l, 0ll);
    int r = ceil(a);
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        v[0] = 1 * sign;
        return 0;
    }

    int absl = abs(n - pow(2, l));
    int absr = abs(n - pow(2, r));

    if (absr <= absl)
    {
        v[r] = sign * 1;
        return soln(absr, (-1) * sign, v);
    }
    else
    {
        v[l] = sign * 1;
        return soln(absl, +1 * sign, v);
    }
}
void solve()
{
    int n;
    cin >> n;
    auto a = log2(n);
    int l = floor(a);
    int r = ceil(a);
    // bug(a, r);
    v64 v(32, 0);
    soln(n, 1, v);
    // bug(n);
    int flag = 0, prev = 0;
    forn(i, v.size()- 1)
    {
        if (v[i] == v[i + 1] and v[i] == 1)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        v.assign(32, 0);
        int absl = abs(n - pow(2, l));
        int absr = abs(n - pow(2, r));

        if (absr > absl)
        {
            v[r] = 1 * 1;

            soln(absr, -1, v);
        }

        else
        {
            v[l] = 1 * 1;
            // bug(v[l]);
            soln(absl, 1, v);
        }
    }
    int len = 0;
    
    // his preference-internship -project -letter format - presentation waha

    for (int i = 0; i < 32; i++)
    {
        if (v[i] == 1)
        {
            len = i + 1;
        }
    }
    cout << len << endl;


    // 1 10   2 5     3 7 
    forn(i, len)
    {
        cout << v[i] << " ";
    }
    cout << ln;
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
