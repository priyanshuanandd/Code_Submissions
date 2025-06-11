class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n);
        vector<int> in(n, 0);
        for (auto i : edges) {
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
            in[i[1]]++;
            in[i[0]]++;
        }
        vector<int> a;
        if(n == 1){
            a.push_back(0);
            return a;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] ==1) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()){
            int curr = q.size();
            ans.clear();
            for(int i = 0 ; i < curr;i++){
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto i : v[node]){
                    if(--in[i] == 1){
                        q.push(i);
                    }
                }
            }
        }
        return ans;
    }
};