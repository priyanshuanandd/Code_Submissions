#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> highestPeak(vector<vector<int>> &grid)
{
    queue<pair<int, int>> q;
    n = grid.size();
    m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 and xx < n and yy >= 0 and yy < m and grid[xx][yy] == 0 and dist[xx][yy] == INT_MAX)
            {
                // cout << xx << " " << yy << endl;
                dist[xx][yy] = dist[x][y] + 1;
                q.push({xx, yy});
            }
        }
    }

    return dist;
}