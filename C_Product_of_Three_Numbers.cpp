class Solution
{
public:
    vector<bool> findAnswer(int n, vector<vector<int>> &edges)
    {
        vector<bool> ans(edges.size(), 0);

        vector<long long> way(n, 0);
        vector<long long> dist(n, LONG_MAX);
        vector<vector<pair<pair<long long, long long>, long long>>> adj(n);
        long long mod = 1e9 + 7;
        for (int j = 0; j < edges.size(); j++)
        {
            auto i = edges[j];
            adj[i[0]].push_back({{i[1], i[2]}, j});
            adj[i[1]].push_back({{i[0], i[2]}, j});
        }

        priority_queue<pair<pair<long long, long long>, long long>,
                       vector<pair<pair<long long, long long>, long long>>,
                       greater<pair<pair<long long, long long>, long long>>>
            pq;

        pq.push({{0, 0}, 0});
        way[0] = 1;
        while (!pq.empty())
        {

            long long node = pq.top().first.second;
            long long dis = pq.top().first.first;
            pq.pop();
            for (auto j : adj[node])
            {
                auto i = j.first;
                if (dist[i.first] > (dis + i.second))
                {
                    dist[i.first] = (dis + i.second);
                    pq.push({dist[i.first], i.first});
                }
            }
        }
        while (!pq.empty())
        {
            long long node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();
            for (auto j : adj[node])
            {
                auto i = j.first;
                int indx = j.second;
                if (dist[i.first] == (dis + i.second))
                {
                    ans[indx] = 1;
                }
            }
        }
        return ans;
    }
};