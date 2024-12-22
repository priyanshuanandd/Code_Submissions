#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define pb push_back

void solve() {
  int n, k;
  cin >> n >> k;

  // Maximum possible pairs
  int max_pairs = (n * (n - 1)) / 2;

  // Case 1: Handle invalid cases
  if (k > max_pairs || (n == 1 && k != 0)) {
    cout << -1 << endl;
    return;
  }

  // Case 2: Handle n = 1
  if (n == 1) {
    cout << 2 << endl;
    return;
  }

  // Case 3: Handle k = 0 (all numbers same)
  if (k == 0) {
    for (int i = 0; i < n; i++) {
      cout << 2 << " ";
    }
    cout << endl;
    return;
  }

  // Case 4: Handle maximum pairs
  if (k == max_pairs) {
    for (int i = 2; i <= n + 1; i++) {
      cout << i << " ";
    }
    cout << endl;
    return;
  }

  // Case 5: General case
  vector<int> result;
  result.pb(2); // First number is always 2

  // Calculate how many numbers should be co-prime with 2
  int needed_coprime = 0;
  int curr_pairs = 0;

  // Find how many odd numbers we need
  for (int i = 1; i < n; i++) {
    if (curr_pairs + i <= k) {
      needed_coprime++;
      curr_pairs += i;
    } else {
      break;
    }
  }

  // Add odd numbers (co-prime with 2)
  for (int i = 0; i < needed_coprime; i++) {
    result.pb(3 + 2 * i);
  }

  // Fill remaining positions
  int remaining = n - result.size();
  if (remaining > 0) {
    if (k > curr_pairs) {
      // Need some additional co-prime pairs
      int extra_pairs_needed = k - curr_pairs;
      int ptr = 4;
      int pairs_created = 0;

      while (result.size() < n && pairs_created < extra_pairs_needed) {
        result.pb(ptr);
        ptr = (ptr == 4) ? 6 : 4;
        pairs_created++;
      }

      // Fill remaining with 4
      while (result.size() < n) {
        result.pb(4);
      }
    } else {
      // No additional pairs needed
      while (result.size() < n) {
        result.pb(4);
      }
    }
  }

  // Print result
  for (int x : result) {
    cout << x << " ";
  }
  cout << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}