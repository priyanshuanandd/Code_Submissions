#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
#define MAX 200005

vector<int> phi(MAX + 1), g(MAX + 1), prefix(MAX + 1);
vector<vector<int>> divisors(MAX + 1);
vector<int> sumPhi(MAX + 1);

void precompute() {
    // Calculate phi values using sieve
    for(int i = 1; i <= MAX; i++) 
        phi[i] = i;
    
    for(int i = 2; i <= MAX; i++) {
        if(phi[i] == i) {
            for(int j = i; j <= MAX; j += i) {
                phi[j] = phi[j] * (i-1) / i;
            }
        }
    }
    
    // Calculate running sum of phi values that will contribute to each k
    sumPhi[0] = 0;
    for(int i = 1; i < MAX; i++) {
        sumPhi[i] = (sumPhi[i-1] + phi[i]) % mod;
    }
    
    // For each i from 1 to MAX-1:
    // Add contribution to all k > i where k-i forms valid pair with i
    for(int i = 1; i < MAX; i++) {
        for(int k = i+1; k < MAX; k++) {
            g[k] = (g[k] + phi[i] * phi[k-i] % mod) % mod;
        }
    }
    
    // Calculate prefix sums for range queries
    prefix[0] = 0;
    for(int i = 1; i < MAX; i++) {
        prefix[i] = (prefix[i-1] + g[i]) % mod;
    }
}

void solve() {
    int Q;
    cin >> Q;
    while(Q--) {
        int l, r;
        cin >> l >> r;
        int result = (prefix[r] - prefix[l-1] + mod) % mod;
        cout << result << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    precompute();
    int t = 1;
    while(t--) solve();
    return 0;
}