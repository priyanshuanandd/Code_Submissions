class Solution {
public:
    int n, m;
    vector<int> v;
    
    long long f(int indx, int currlen, int active, int k, vector<vector<vector<vector<int>>>> &dp) {
        if (indx >= v.size()) {
            if (!active) {
                return (k == 0) ? 0 : INT_MIN;
            } else {
                return (k == 0 && currlen == m) ? 0 : INT_MIN;
            }
        }
        
        auto& x = dp[indx][currlen][active][k];
        if (x != -1)
            return x;
        
        long long ans = INT_MIN;
        
        // Active subarray formation
        if (active) {
            // Can deactivate
            if (currlen == m) {
                ans = max(ans, f(indx, 0, 0, k, dp));
            }
            // Continue adding
            ans = max(ans, v[indx] + f(indx + 1, min(m, currlen + 1), 1, k, dp));
        } else {
            // Activate .. k > 0
            if (k > 0) {
                ans = max(ans, v[indx] + f(indx + 1, 1, 1, k - 1, dp));
            }
            ans = max(ans, f(indx + 1, 0, 0, k, dp));
        }

        return x = ans;
    }
    
    int maxSum(vector<int>& nums, int k, int m) {
        v = nums;
        n = v.size();
        this->m = m;
        
        vector<vector<vector<vector<int>>>> dp(
            n, vector<vector<vector<int>>>(m + 1, vector<vector<int>>(2, vector<int>(k + 1, -1))));
        
        return f(0, 0, 0, k, dp);
    }
};