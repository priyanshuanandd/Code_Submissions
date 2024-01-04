#include <bits/stdc++.h>

#define MOD 1000000007
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define loop(i, a, b) for (int i = a; i < b; i++)
#define loopr(i, a, b) for (int i = a; i >= b; i--)
#define loops(i, a, b, step) for (int i = a; i < b; i += step)
#define looprs(i, a, b, step) for (int i = a; i >= b; i -= step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie();
#define FILE_READ_IN freopen("input.txt", "r", stdin);
#define FILE_READ_OUT freopen("output.txt", "w", stdout);
#define all(a) a.begin(), a.end()
using namespace std;
// For ordered_set
// using namespace __gnu_pbds;
// template <typename T>
// using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

void build(ll arr[], ll tree[], ll s, ll e, ll tn)
{
    ll mid = (s + e) / 2;
    if (s == e)
    {
        tree[tn] = arr[s];
        return;
    }
    build(arr, tree, mid + 1, e, (2 * tn) + 1);
    build(arr, tree, s, mid, 2 * tn);
    tree[tn] = max(tree[2 * tn], tree[(2 * tn) + 1]);
}

ll query(ll arr[], ll tree[], ll s, ll e, ll tn, ll l, ll r)
{
    // out
    if (s > r || l > e)
    {
        return 0;
    }
    // in
    if (s >= l && r >= e)
    {
        return tree[tn];
    }
    ll mid = (s + e) / 2;
    return max(query(arr, tree, s, mid, 2 * tn, l, r), query(arr, tree, mid + 1, e, (2 * tn) + 1, l, r));
}

void update(ll arr[], ll tree[], ll s, ll e, ll tn, ll idx, ll val)
{
    ll mid = (s + e) / 2;
    if (s == e)
    {
        arr[idx] = val;
        tree[tn] = val;
        return;
    }
    if (idx > mid)
    {
        update(arr, tree, mid + 1, e, (2 * tn) + 1, idx, val);
    }
    else
    {
        update(arr, tree, s, mid, 2 * tn, idx, val);
    }
    tree[tn] = max(tree[2 * tn], tree[(2 * tn) + 1]);
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    ll idx, val;
    ll arr[n], diff[n], tree[4 * n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        diff[i] = abs(min(arr[i + 1] - arr[i], 0ll));
    }
    build(diff, tree, 0, n - 2, 1);
    for (int i = 0; i < q; i++)
    {
        cin >> idx >> val;
        arr[idx - 1] = val;
        --idx;
        if (idx == 0)
        {
            update(diff, tree, 0, n - 2, 1, idx, abs(min(arr[idx + 1] - arr[idx], 0ll)));
        }
        else if (idx == n - 1)
        {
            update(diff, tree, 0, n - 2, 1, idx - 1, abs(min(arr[idx] - arr[idx - 1], 0ll)));
        }
        else if (idx > 0 && idx < n - 1)
        {
            update(diff, tree, 0, n - 2, 1, idx, abs(min(arr[idx + 1] - arr[idx], 0ll)));
            update(diff, tree, 0, n - 2, 1, idx - 1, abs(min(arr[idx] - arr[idx - 1], 0ll)));
        }
        cout << query(diff, tree, 0, n - 2, 1, 0, n - 2) << endl;
    }
}

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}