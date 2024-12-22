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
bool isvalid(int x, int y, vector<vector<char>> &arr, vv64 &vis)
{
    int n = arr.size();
    if (x >= n or x < 0 or y >= n or y < 0)
        return false;

    if (arr[x][y] == 'T')
        return false;
    if (vis[x][y] == 1)
    {
        return false;
    }
    return true;
}

void bfs(int x, int y, vector<vector<char>> &arr, vv64 &dis, vv64 &vis)
{
    vis[x][y] = 1;
    queue<pair<int, int>> q;
    q.push(mp(x, y));
    vector<int> dx, dy;
    dx = {-1, 1, 0, 0};
    dy = {0, 0, -1, 1};
    while (!q.empty())
    {
        int a = q.front().fi;
        int b = q.front().se;
        q.pop();
        vis[a][b] = 1;
        for (int i = 0; i < 4; i++)
        {
            int aa = a + dx[i];
            int bb = b + dy[i];
            if (isvalid(aa, bb, arr, vis))
            {
                vis[aa][bb] = 1;
                q.push(mp(aa, bb));
                dis[aa][bb] = dis[a][b] + 1;
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));
    vv64 dis(n, vector<int>(n, 0));
    vv64 vis(n, vector<int>(n, 0));
    int sx, sy, ex, ey;
    sx = sy = ex = ey = 0;
    forn(i, n)
    {
        forn(j, n)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'S')
            {

                sx = i;
                sy = j;
            }
            if (arr[i][j] == 'E')
            {
                ex = i;
                ey = j;
            }
        }
    }

    bfs(sx, sy, arr, dis, vis);

    cout << dis[ex][ey] << ln;
}

int32_t main()
{
    fast_cin();
    clock_t z = clock();
    ll t = 1;
    // cin >> t;
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

// 4. DNF-powerset
