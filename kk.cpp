#include <bits/stdc++.h>
using namespace std;

vector<int> decode(vector<int> encoded, int first)
{
    vector<int> v;
    int x = 0;
    v.push_back(first);
    for (int i = 0; i < encoded.size(); i++)
    {
        x = first^encoded[0];
        v.push_back(x);
        first = x;
    }
    
}
void solve()
{
    ll n;
    cin >> n;
    deque<ll> arr(n), brr;
    forn(i, n)
    {
        cin >> arr[i];
    }
    sort(all(arr));
    ll v = arr.back() + arr[n - 2];
    forn(i, n)
    {
        if (i % 2 == 0)
        {
            brr.pb(arr.back());
            arr.pop_back();
        }
        else
        {
            brr.pb(arr.front());
            arr.pop_front();
        }
    }
    forn(i, n - 1)
    {
        if (brr[i] + brr[i + 1] >= v)
        {
            dbg("NO");
            return;
        }
    }
    dbg("YES");
}
int main()
{
    
}