#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>

using namespace std;

// Function to solve the problem
vector<tuple<int, int, int, int>> solveKevinAndBinaryStrings(int t, vector<string>& testCases) {
    vector<tuple<int, int, int, int>> results;

    for (int testCaseIdx = 0; testCaseIdx < t; ++testCaseIdx) {
        string s = testCases[testCaseIdx];
        int n = s.length();
        vector<int> prefix(n + 1, 0);

        // Compute the prefix XORs
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] ^ (s[i] - '0');
        }

        unordered_map<int, int> xorMap; // Map to store the first occurrence of each XOR
        int maxXor = 0;
        int l1 = 1, r1 = 1, l2 = 1, r2 = 1;

        // Initialize the map with the XOR of an empty prefix
        xorMap[0] = 0;

        // Loop through each possible ending point of the second substring
        for (int i = 1; i <= n; ++i) {
            // For each previous XOR value, compute the current XOR
            for (const auto& entry : xorMap) {
                int xorValue = prefix[i] ^ entry.first;
                if (xorValue > maxXor) {
                    maxXor = xorValue;
                    // The indices of the subarrays that yield the maximum XOR
                    l1 = entry.second + 1; // Start of first substring
                    r1 = i; // End of first substring
                    l2 = entry.second + 1; // Start of second substring
                    r2 = i; // End of second substring
                }
            }

            // Update the map with the current prefix XOR
            xorMap[prefix[i]] = i;
        }

        results.push_back({l1, r1, l2, r2});
    }

    return results;
}

int main() {
    int t;
    cin >> t;
    vector<string> testCases(t);

    for (int i = 0; i < t; ++i) {
        cin >> testCases[i];
    }

    vector<tuple<int, int, int, int>> results = solveKevinAndBinaryStrings(t, testCases);

    for (const auto& result : results) {
        int l1, r1, l2, r2;
        tie(l1, r1, l2, r2) = result;
        cout << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
    }

    return 0;
}
