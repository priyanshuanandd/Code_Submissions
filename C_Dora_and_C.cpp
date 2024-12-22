class Solution {
public:
    vector<vector<int>> grid;
    int n,m;
    // vector<vector<vector<int>>> dp;
    map<pair<int,vector<int>>,int> m;
    int f(int row,vector<int> &vis){
        if(row == n){
            return 0;
        }
        int ans = 0;
        // 0 - 9 vis
        // 10 not picked
        // 11 ->ans
        for(int i = 0; i < m ;i++){
            if(dp[row][i][]== -1){
                vis[grid[row][i]] = 1;
                ans = max(grid[row][i] + f(row+1,vis),ans);
                vis[grid[row][i]] = 0;
            }
        }
        ans = max(f(row+1,vis),ans);
       // cout << row << "->" << ans << endl;
        return ans;
    }
    int maxScore(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        dp.assign(10,vector<vector<int>>(13,vector<int>(101,-1)));
        m = grid[0].size();
        vector<int> vis(101,0);
        return f(0,vis);
    }
};