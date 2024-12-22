#include <iostream>
#include <algorithm>
using namespace std;

int longest_common_subsegment(int x, int y) {
    // Find the bitwise AND of x and y
    int common_prefix_length = __builtin_clz(x ^ y); // Count leading zeros in the XOR of x and y
    // Return 2 raised to the power of common_prefix_length minus 1
    return (1 << common_prefix_length) - 1;
}

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int x, y;
        cin >> x >> y; // Parameters of the sequences
        // Output
        cout << longest_common_subsegment(x, y) << endl;
    }
    return 0;
}
