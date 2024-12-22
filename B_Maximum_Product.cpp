#include <bits/stdc++.h>
#include <complex>
#include <queue>
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
#define cins(x)       \
    for (auto &i : x) \
    cin >> i
#define cins2(x)      \
    for (auto &i : x) \
    cin >> i.ff >> i.ss
#define endl "\n"
#define dbg(a) cout << a << ln;
#define dbg2(a) cout << a << ' ';
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define minheap priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>;
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
// 1. If theres mod(%) think of Pigeon hole .

// 2. Prefix Sum

// 3. A^B^A=B

// 4. DNF-powerset

// 5. Think 2 pointer/Think equation/Think Summation
bool comp(int a, int b)
{
    int x = abs(a);
    int y = abs(b);

    return x > y;
}

void solve()
{
    // int n;
    // cin >> n;
    // v64 pos, neg, zero;
    // int cntpos = 0;
    // v64 v(n);
    // forn(i, n)
    // {
    //     int x;
    //     cin >> x;
    //     v[i] = x;
    //     if (x > 0)
    //     {
    //         cntpos++;
    //         pos.push_back(x);
    //     }
    // }

    // sort(all(pos));

    // sort(all(v), comp);

    // int lastneg = 0;
    // int ans = 1;

    // forn(i, 5)
    // {
    //     ans *= v[i];
    //     neg.push_back(i);
    // }
    // // printvector(v);
    // // bug(ans);
    // if (ans < 0 and n > 5)
    // {
    //     for (int i = 5; i < n; i++)
    //     {
    //         for (int j = 0; j < 5; j++)
    //         {

    //             int tmp = v[i];
    //             //bug(tmp);
    //             for (int k = 0; k < 5; k++)
    //             {
    //                 if (k != j)
    //                     tmp *= v[k];
    //             }
    //             ans = max(ans, tmp);
    //         }
    //     }
    // }
    // cout << ans << endl;
    int n;
    cin >> n;
    v64 v(n);
    cins(v);
    sort(all(v));
    int x1 = v[0] * v[1] * v[2] * v[3] * v[n - 1];
    int x2 = v[0] * v[1] * v[n - 3] * v[n - 2] * v[n - 1];
    int x3 = v[n - 5] * v[n - 4] * v[n - 3] * v[n - 2] * v[n - 1];
    cout << max({x1, x2, x3}) << endl;
    // if (!neg.empty())
    // {
    //     for (ll i = 0; i < neg.size() - 2; i += 2)
    //     {
    //         int curr = neg[i] * neg[i + 1];
    //         v.push_back({{curr, 2}, max(neg[i], neg[i + 1])});
    //     }

    //     if (neg.size() % 2)
    //     {
    //         v.push_back({{neg[neg.size() - 1], 1}, neg[neg.size() - 1]});
    //     }
    //     else
    //     {
    //         v.push_back({{neg[neg.size() - 1] * neg[neg.size() - 2], 2}, max(neg[neg.size() - 1], neg[neg.size() - 2])});
    //     }
    // }
    // if (!pos.empty())
    // {
    //     for (ll i = 0; i < pos.size() - 2; i += 2)
    //     {
    //         int curr = pos[i] * pos[i + 1];
    //         v.push_back({{curr, 2}, pos[i]});
    //     }
    //     if (pos.size() % 2)
    //     {
    //         v.push_back({{pos[pos.size() - 1], 1}, pos[pos.size() - 1]});
    //     }
    //     else
    //     {
    //         v.push_back({{pos[pos.size() - 1] * pos[pos.size() - 2], 2}, max(pos[pos.size() - 1], pos[pos.size() - 2])});
    //     }
    // }
    // sort(all(v), comp);
    // int ans = 1;
    // int val = 5;
    // int i = 0;

    // for (auto &i : v)
    // {
    //     bug(i.first.fi, i.first.se);
    //     bug(i.second);
    // }

    // while (i < v.size() and val > 0)
    // {
    //     if (v[i].first.second <= val)
    //     {
    //         val -= v[i].first.second;
    //         ans *= v[i].first.fi;
    //     }
    //     else if (val == 1)
    //     {
    //         val--;
    //         ans *= v[i].second;
    //     }
    //     i++;
    // }
    // cout << ans << endl;
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
