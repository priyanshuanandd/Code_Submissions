#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
private:
    std::vector<int> prefix_gcd, suffix_gcd;

public:
    std::vector<int> gcdPairsQueries(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        int n = nums.size();
        prefix_gcd.resize(n);
        suffix_gcd.resize(n);

        // Calculate prefix GCDs
        prefix_gcd[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix_gcd[i] = std::gcd(prefix_gcd[i-1], nums[i]);
        }

        // Calculate suffix GCDs
        suffix_gcd[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; --i) {
            suffix_gcd[i] = std::gcd(suffix_gcd[i+1], nums[i]);
        }

        std::vector<int> result;
        for (const auto& query : queries) {
            int left = query[0], right = query[1], k = query[2];
            int gcd_value;

            if (left == 0) {
                gcd_value = suffix_gcd[right];
            } else if (right == n - 1) {
                gcd_value = prefix_gcd[left - 1];
            } else {
                gcd_value = std::gcd(prefix_gcd[left - 1], suffix_gcd[right]);
            }

            result.push_back(gcd_value);
        }

        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {2, 3, 4};
    std::vector<std::vector<int>> queries = {{0, 2, 2}, {0, 1, 1}, {1, 2, 1}};
    
    std::vector<int> result = sol.gcdPairsQueries(nums, queries);
    
    for (int res : result) {
        std::cout << res << " ";
    }
    std::cout << std::endl;

    return 0;
}