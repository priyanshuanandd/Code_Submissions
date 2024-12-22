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

    string s;
    cin >> s;

    map<char, int> m;

    for (auto i : s)
    {
        m[i]++;
    }
    p64 cnt1 = {0, 0};
    p64 cnt2 = {0, 0};
    string ans;
    int c1, c2;
    c1 = 0;
    c2 = 0;
    forn(i, n)
    {
        // bug(cnt1.first, cnt2.first, cnt1.second, cnt2.second, ans);
        if (s[i] == 'N' or s[i] == 'S')
        {
            if (cnt1.first == cnt2.first)
            {
                if (c1 >= c2)
                {
                    cnt2.first += (s[i] == 'N') ? 1 : -1;
                    ans.push_back('R');
                    c2++;
                }
                else
                {
                    cnt1.first += (s[i] == 'N') ? 1 : -1;
                    ans.push_back('H');
                    c1++;
                }
                continue;
            }
            if (s[i] == 'S')
            {
                if (cnt1.first > cnt2.first)
                {
                    cnt1.first--;
                    ans.push_back('H');
                    c1++;
                }
                else
                {
                    cnt2.first--;
                    ans.push_back('R');
                    c2++;
                }
            }
            else
            {
                if (cnt1.first > cnt2.first)
                {
                    cnt2.first++;
                    ans.push_back('R');
                    c2++;
                }
                else
                {
                    cnt1.first++;
                    ans.push_back('H');
                    c1++;
                }
            }
        }
        else
        {
            if (cnt1.second == cnt2.second)
            {
                if (c1 > c2)
                {
                    cnt2.second += (s[i] == 'E') ? 1 : -1;
                    ans.push_back('R');
                    c2++;
                }
                else
                {
                    cnt1.second += (s[i] == 'E') ? 1 : -1;
                    ans.push_back('H');
                    c1++;
                }
                continue;
            }
            if (s[i] == 'W')
            {
                if (cnt1.second > cnt2.second)
                {
                    cnt1.second--;
                    ans.push_back('H');
                    c1++;
                }
                else
                {
                    cnt2.second--;
                    ans.push_back('R');
                    c2++;
                }
            }
            else
            {
                if (cnt1.second > cnt2.second)
                {
                    cnt2.second++;
                    ans.push_back('R');
                    c2++;
                }
                else
                {
                    cnt1.second++;
                    ans.push_back('H');
                    c1++;
                }
            }
        }
    }
    // bug(c1, c2, cnt1.first, cnt2.first, cnt1.second, cnt2.second, ans);

    // bug(ans);
    if (cnt1 == cnt2)
    {
        if (c1 == 0 or c2 == 0)
        {
            cout << "NO" << endl;
            return;
        }
        cout << ans << endl;
        return;
    }
    cout << "NO" << endl;
}
// int cntn = 0;
// if (abs(m['E'] - m['S']) % 2 == 1)
// {
//     cout << "NO" << endl;
//     return;
// }

// if (abs(m['E'] - m['W']) % 2 == 1)
// {
//     cout << "NO" << endl;
//     return;
// }
// if ((abs(m['N'] - m['S']) == 0 and m['S'] == 1))
// {
//     if (abs((abs(m['W'] - m['E']) != 0 and m['E'] == 0)))
//     {

//         cout << "NO" << endl;
//         return;
//     }
// }
// if ((abs(m['E'] - m['W']) == 0 and m['E'] == 1))
// {
//     if ((abs(m['N'] - m['S']) == 0 and m['S'] == 0))
//     {

//         cout << "NO" << endl;
//         return;
//     }
// }
// v64 v(4);
// // N S E W
// v[0] = m['N'] / 2;
// v[1] = m['S'] / 2;
// v[2] = m['E'] / 2;
// v[3] = m['W'] / 2;

// string ans;
// for (auto i : s)
// {
//     if (i == 'N')
//     {
//         if (v[0] > 0)
//         {
//             ans.push_back('H');
//             v[0]--;
//         }
//         else
//         {
//             ans.push_back('R');
//         }
//     }

//     if (i == 'S')
//     {

//         if (v[1] > 0)
//         {
//             ans.push_back('H');
//             v[1]--;
//         }
//         else
//         {
//             ans.push_back('R');
//         }
//     }

//     if (i == 'E')
//     {

//         if (v[2] > 0)
//         {
//             ans.push_back('H');
//             v[2]--;
//         }
//         else
//         {
//             ans.push_back('R');
//         }
//     }

//     if (i == 'W')
//     {

//         if (v[3] > 0)
//         {
//             ans.push_back('H');
//             v[3]--;
//         }
//         else
//         {
//             ans.push_back('R');
//         }
//     }
// }
// cout << ans << endl;

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
