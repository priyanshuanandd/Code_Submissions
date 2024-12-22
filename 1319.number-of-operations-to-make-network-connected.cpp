/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
 */

// @lc code=start
class Solution
{
private:
    int dsufind(int v, vector<int> &parent)
    {
        if (-1 == parent[v])
            return v;
        return parent[v] = dsufind(parent[v], parent);
    }

    void dsuunion(int a, int b, vector<int> &parent)
    {
        a = dsufind(a, parent);
        b = dsufind(b, parent);
        if (a != b)
            parent[b] = a;
        parent[a]--;
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int total = connections.size();
        vector<int> par(n + 1, -1);
        for (auto i : connections)
        {
            int a = i.first;
            int b = i.second;

            a = dsufind(a, par);
            b = dsufind(b, par);

            if (a != b)
            {
                total--;
                dsuunion(a,b,par);
            }
        }

        int curr = 0 ;
        for(auto i : par){
            if(i <  - 1){
                curr++;
            }
        }

        if(curr > total){
            return -1;
        }
        return min(curr,total);
    }
};
// @lc code=end
