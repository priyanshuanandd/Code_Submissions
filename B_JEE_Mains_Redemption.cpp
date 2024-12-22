// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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

// using namespace std;
// #define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
// template <typename Arg1>
// void __f(const char *name, Arg1 &&arg1)
// {
//     cout << name << " : " << arg1 << endl;
// }
// template <typename Arg1, typename... Args>
// void __f(const char *names, Arg1 &&arg1, Args &&...args)
// {
//     const char *comma = strchr(names + 1, ',');
//     cout.write(names, comma - names) << " : " << arg1 << " | ";
//     __f(comma + 1, args...);
// }
// typedef long long ll;
// #define int long long
// typedef long double ld;
// typedef pair<ll, ll> p64;
// typedef vector<ll> v64;
// typedef vector<vector<ll>> vv64;
// typedef vector<p64> vp64;
// typedef set<ll> s64;
// typedef set<p64> sp64;
// typedef map<ll, ll> m64;
// const int MOD = 1000000007;
// const int INF = 2e18;
// double eps = 1e-12;
// #define forn(i, n) for (ll i = 0; i < n; i++)
// #define forsn(i, s, e) for (ll i = s; i < e; i++)
// #define rforn(i, s) for (ll i = s; i >= 0; i--)
// #define rforsn(i, s, e) for (ll i = s; i >= e; i--)

// #define fast_cin()                    \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL)
// #define all(x) (x).begin(), (x).end()
// #define al(arr, n) arr, arr + n
// #define sz(x) ((ll)(x).size())
// using str = string;             // yay python!
// const double pi = 3.1415926536; // 10
// long long power(long double a, long long b)
// {
//     int result = 1;
//     while (b)
//     {
//         if (b & 1)
//             result = (int)(result * a) % MOD;
//         a = (((int)a % MOD) * ((int)a % MOD)) % MOD;
//         b >>= 1;
//     }
//     return result;
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     int c;
//     cin >> c;
//     int x = c + sqrt(c * c - 1);
//     bug(x);
//     ld a = power(x, n);

//     ld f = 1 / a;
//     ld ans = (((int)a % MOD) + ((int)f % MOD)) % MOD;

//     cout << ans << endl;
// }

// int32_t main()
// {
//     fast_cin();
//     clock_t z = clock();
//     ll t = 1;
//     cin >> t;
//     for (int it = 1; it <= t; it++)
//     {
//         solve();
//     }

//     cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

//     return 0;
// }

// // 1. If theres mod(%) think of Pigeon hole .

// // 2. Prefix Sum

// // 3. A^B^A=B

// // 4. DNF-powerset
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long x, long long n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
    {
        long long half_power = power(x, n / 2);
        return (half_power * half_power) % MOD;
    }
    else
    {
        return (x * power(x, n - 1)) % MOD;
    }
}

long long calculate_x_n(long long X, long long N)
{
    return (power(X, N) + power(X, N - 2)) % MOD;
}

long long find_X(long long N, long long C)
{
    long long low = 1, high = C;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (mid + 1 * mid == C)
        {
            return mid;
        }
        else if (mid + 1 * mid < C)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long N, c;
        cin >> N >> c;
        int x = c + (int)sqrt(c * c - 1);
        long long result = calculate_x_n(x, N);
        cout << result << endl;
    }
    return 0;
}
