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
const int INF = 2e18;
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

bool dfs(int node, v64 adj[], v64 &vis, v64 &col, int c)
{
    col[node] = c;
    vis[node] = 1;

    for (auto it : adj[node])
    {

        if (vis[it] == 0)
        {
            if (!dfs(it, adj, vis, col, c ^ 1))
            {
                return false;
            }
        }
        else
        {
            if (col[node] == col[it])
            {
                return false;
            }
        }
    }
    return true;
}
bool bfs(int node, v64 adj[], v64 &vis, v64 &col, int c, queue<pair<int, int>> &q)
{
    q.push({node, c});
    while (!q.empty())
    {
        auto k = q.front();
        q.pop();
        vis[k.first] = 1;
        col[k.first] = k.second;
        for (auto i : adj[k.first])
        {
            if (vis[i] == 0)
            {
                col[i] = k.second ^ 1;
            }
            if (vis[i] == 1 and col[i] == col[k.first])
            {
                return false;
            }
        }
    }
    return true;
}
void solve()
{
    int n, e;
    cin >> n >> e;

    vector<int> adj[n + 1];
    vector<int> vis(n + 1);
    vector<int> col(n + 1);

    forn(i, e)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool flag = true;
    queue<pair<int,int>> q;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            bool res = bfs(i, adj, vis, col, 0,q);

            if (res == false)
            {
                flag = false;
            }
        }
    }
    if (flag == true)
    {
        cout << "No suspicious bugs found!\n";
    }
    else
    {
        cout << "Suspicious bugs found!\n";
    }
}

int32_t main()
{
    fast_cin();
    clock_t z = clock();
    ll t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        cout << "Scenario #" << it << ":\n";
        solve();
    }

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

// 1. If theres mod(%) think of Pigeon hole .

// 2. Prefix Sum

// 3. A^B^A=B

// 4. DNF-powerset
