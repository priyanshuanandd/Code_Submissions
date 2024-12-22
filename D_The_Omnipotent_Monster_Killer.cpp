#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 3e5 + 5;

long long a[MAX_N];
vector<int> graph[MAX_N];

pair<long long, long long> dfs(int v, int p) {
    long long sum_all = a[v];
    long long sum_even = 0;
    
    for (int u : graph[v]) {
        if (u != p) {
            pair<long long, long long> child = dfs(u, v);
            sum_all += child.first;
            sum_even += child.second;
        }
    }
    
    return make_pair(sum_all, max(sum_even, sum_all - sum_even));
}

long long solve() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        graph[i].clear();
    }
    
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    pair<long long, long long> result = dfs(1, 0);
    return result.first + result.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    
    return 0;
}