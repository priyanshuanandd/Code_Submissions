class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        // mark sus nodes
        // run bfs from non sus nodes
        // remove non visited sus nodes

        vector<int> sus(n + 1, 0);
        vector<int> vis(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        vector<vector<int>> adj2(n + 1);

        for (auto i : invocations) {
            adj[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }

        // mark sus

        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            sus[node] = 1;
            for (auto i : adj[node]) {
                if (sus[i] == 0) {
                    q.push(i);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (sus[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            vis[node] = 1;
            for (auto i : adj[node]) {
                if (vis[i] == 0) {
                    q.push(i);
                }
            }
        }
        set<int> ans;
        for (int i = 0; i < n; i++) {
            if(vis[i] == 1 or sus[i] == 0){
                ans.insert(i);
                for(auto j : adj2[i])
                ans.insert(j);
            }
        }
        vector<int> aa;
        for(auto i : ans){
            for(auto j : adj[i]){
                ans.insert(j);
            }
            for(auto j : adj2[i]){
                ans.insert(j);
            }
        }
        for(auto i : ans){
            aa.push_back(i);
        }
        return aa;
    }
};