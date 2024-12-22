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
typedef pair<int, int> p64;
typedef vector<int> v64;
typedef vector<vector<int>> vv64;
typedef vector<p64> vp64;
typedef set<int> s64;
typedef set<p64> sp64;
typedef map<int, int> m64;
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
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    v64 v(n + 1, 0), num(n + 1, 0);
    v64 order;
    m64 mapi;
    forn(i, n + 1)
    {
        mapi[i] = -1;
    }
    forn(i, m)
    {
        int x;
        cin >> x;
        order.push_back(x);
        num[x] = 2;
        mapi[order[i]] = i;
    }
    int last = 0;
    forn(i, k)
    {
        int a, b;
        cin >> a >> b;
        v[b] = a;
        if (a == 1)
        {
            dbg(b);
            return;
        }
        num[a] = 1;
        // look from b-1 to place m[a]-1 numbers
        if (mapi[a] >= 0)
        {
            order[mapi[a]] = -1;
            int val = mapi[a] - 1;
            for (int j = b - 1; j > 0; j--)
            {
                if (val < 0 or order[val] == -1)
                {
                    break;
                }
                if (v[j] == 0 and order[val] != -1)
                {
                    v[j] = order[val];
                    num[order[val]] = 1;
                    order[val] = -1;
                    val--;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    printvector(v);
    //  1 is first in order wala case
    if (num[1] == 2 and mapi[1] > 0 and order[0] == -1)
    { // find last placed number before 1 subtract that position mapi[1] - indx in order +1 + indx in v
        int indx = 0;
        int indx2 = 0;

        for (int i = mapi[1] - 1; i >= 0; i--)
        {
            if (order[i] == -1)
            {
                indx = i;
            }
        }
        forsn(i, 1, n)
        {
            if (mapi[v[i]] >= 0)
            {
                indx2 = i;
            }
        }
        // bug(indx2, indx);
        int ans = mapi[1] - indx + indx2;
        cout << ans << endl;
        return;
    }
    else if (num[1] == 2 and mapi[1] > 0)
    {
        int cnt0 = 0;
        forsn(i, 1, n)
        {
            if (v[i] == 0)
            {
                cnt0++;
            }
            if (cnt0 == mapi[1] + 1)
            {
                cnt0 = i;
                break;
            }
        }
        cout << cnt0 << endl;
        return;
    }

    if (num[1] == 1)
    {
        forsn(i, 1, n)
        {
            if (v[i] == 1)
            {
                cout << i << endl;
                return;
            }
        }
    }
    forsn(i, 1, n)
    {
        if (v[i] == 0)
        {
            cout << i << endl;
            return;
        }
    }
    // printvector(v);
}

int32_t main()
{
    fast_cin();
    // clock_t z = clock();
    ll t = 1;
    // cin >> t;
    // freopen("milkorder.in", "r", stdin);
    // freopen("milkorder.out", "w", stdout);
    for (int it = 1; it <= t; it++)
    {
        solve();
    }

    // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
