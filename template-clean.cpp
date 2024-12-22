#include <bits/stdc++.h>

using namespace std;

template <typename T>
using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T> using maxheap = std::priority_queue<T>;

#define cins(x)                                                                \
  for (auto &i : x)                                                            \
  cin >> i
#define cins2(x)                                                               \
  for (auto &i : x)                                                            \
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
typedef vector<string> vs64;
typedef vector<vector<ll>> vv64;
typedef vector<p64> vp64;
typedef set<ll> s64;
typedef set<p64> sp64;
typedef map<ll, ll> m64;
typedef map<ll, v64> mv64;
typedef unordered_map<ll, v64> uv64;
typedef unordered_map<ll, ll> u64;
typedef unordered_map<p64, ll> up64;
typedef unordered_map<ll, vp64> uvp64;
const int MOD = 1000000007;
const int INF = 2e18;
double eps = 1e-12;
#define dbg(a) cout << a << ln;
#define dbg2(a) cout << a << ' ';
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr, n) arr, arr + n
#define sz(x) ((int)(x).size())
using str = string;             // yay python!
const double pi = 3.1415926536; // 10
void printvector(v64 &v) {
  for (auto &i : v) {
    cout << i << " ";
  }
  cout << ln;
}
// DSU
int find_set(int v, vector<int> &parent) {
  if (parent[v] <= -1)
    return v;
  return parent[v] = find_set(parent[v], parent);
}

bool union_set(int a, int b, vector<int> &parent) {
  a = find_set(a, parent);
  b = find_set(b, parent);
  if (a != b) {
    parent[a] += parent[b];
    parent[b] = a;
    return true;
  } else {
    return false;
  }
}

// DSU end
int nxt() // takes input
{
  int x;
  cin >> x;
  return x;
}
//  function for prime factorization

vector<pair<int, int>> pf(int n) {
  vector<pair<int, int>> prime;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      int count = 0;
      while (n % i == 0) {
        count++;
        n = n / i;
      }
      prime.pb(mp(i, count));
    }
  }
  if (n > 1) {
    prime.pb(mp(n, 1));
  }
  return prime;
}
// modular exponentiation
int binaryExponentiation(int x, int n) {
  if (n == 0)
    return 1;
  // n is even
  else if (n % 2 == 0)
    return binaryExponentiation(x * x, n / 2);
  // n is odd
  else
    return x * binaryExponentiation(x * x, (n - 1) / 2);
}
int modularExponentiation(int x, int n, int M) {
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
// div = modularExponentiation(div, MOD - 2, MOD);
// return (res * div) % MOD;
// }

void solve() {}

int32_t main() {
  fast_cin();

  // clock_t z = clock();
  ll t = 1;
  // cin >> t;
  // freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
  for (int it = 1; it <= t; it++) {
    // cerr << "TESTCASE : " << it << endl;
    solve();
  }

  // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

  return 0;
}
